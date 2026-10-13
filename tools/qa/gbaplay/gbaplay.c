/*
 * gbaplay - headless, scriptable GBA player for QA (built on libmgba).
 *
 * Usage: gbaplay [options] ROM [SCRIPT]
 *   see usage() below and docs/hack/QA_TOOLING.md
 *
 * Exit codes:
 *   0 ok, 1 usage/load error, 2 script syntax error,
 *   3 at least one expect* failed, 4 hang detected (with --hang-fatal),
 *   5 CPU crash (jump to invalid address), 6 game FATAL log (with --fatal-is-fail)
 */
#include <mgba/core/config.h>
#include <mgba/core/core.h>
#include <mgba/core/log.h>
#include <mgba/core/serialize.h>
#include <mgba/internal/arm/arm.h>
#include <mgba/internal/gba/gba.h>
#ifndef USE_PNG
#define USE_PNG
#endif
#include <mgba-util/png-io.h>
#include <mgba-util/vfs.h>

#include <ctype.h>
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_SYMS_INIT 4096
#define SCREEN_W 240
#define SCREEN_H 160

/* ---------- global state ---------- */
static struct mCore* core;
static color_t* videoBuffer;
static unsigned vw = SCREEN_W, vh = SCREEN_H;
static const char* outDir = NULL;
static const char* savPath = NULL;
static const char* savOutPath = NULL;
static int verbose = 0;
static int logMask = mLOG_FATAL | mLOG_ERROR;
static int quiet = 0;

static long hangFrames = 0;      /* 0 = disabled */
static int hangFatal = 0;
static int fatalIsFail = 0;
static uint32_t lastHash = 0;
static long sameFrames = 0;
static int hangReported = 0;
static int hangDetected = 0;
static int crashed = 0;
static int gameFatal = 0;
static int expectFailures = 0;
static unsigned long totalFrames = 0;
static uint32_t heldKeys = 0;
static int releaseGap = 2;
static int gbaDebugCategory = -1;
static int gbaMemCategory = -1;

/* ---------- symbols / defines ---------- */
struct Sym { char* name; uint32_t value; };
static struct Sym* syms = NULL;
static size_t nsyms = 0, capsyms = 0;

static void symAdd(const char* name, uint32_t value) {
	for (size_t i = 0; i < nsyms; ++i) {
		if (strcmp(syms[i].name, name) == 0) { syms[i].value = value; return; }
	}
	if (nsyms == capsyms) {
		capsyms = capsyms ? capsyms * 2 : MAX_SYMS_INIT;
		syms = realloc(syms, capsyms * sizeof(*syms));
	}
	syms[nsyms].name = strdup(name);
	syms[nsyms].value = value;
	++nsyms;
}

static int symFind(const char* name, uint32_t* out) {
	for (size_t i = 0; i < nsyms; ++i) {
		if (strcmp(syms[i].name, name) == 0) { *out = syms[i].value; return 1; }
	}
	return 0;
}

static int isIdent(const char* s) {
	if (!(isalpha((unsigned char) *s) || *s == '_')) return 0;
	for (++s; *s; ++s) if (!(isalnum((unsigned char) *s) || *s == '_')) return 0;
	return 1;
}

static int parseHexWord(const char* s, uint32_t* out) {
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) s += 2;
	size_t n = strlen(s);
	if (n != 8) return 0;
	for (size_t i = 0; i < n; ++i) if (!isxdigit((unsigned char) s[i])) return 0;
	*out = (uint32_t) strtoul(s, NULL, 16);
	return 1;
}

/* Accepts: `make syms` output (addr type size name), `nm` output (addr type name)
 * and GNU ld .map lines (0xADDR name). Only symbols in EWRAM/IWRAM/ROM are kept. */
static int loadSymbols(const char* path) {
	FILE* f = fopen(path, "r");
	if (!f) { fprintf(stderr, "gbaplay: cannot open symbol file %s\n", path); return 0; }
	char line[1024];
	size_t before = nsyms;
	while (fgets(line, sizeof(line), f)) {
		char* tok[8]; int nt = 0;
		for (char* t = strtok(line, " \t\r\n"); t && nt < 8; t = strtok(NULL, " \t\r\n")) tok[nt++] = t;
		if (nt < 2 || nt > 4) continue;
		uint32_t addr;
		if (!parseHexWord(tok[0], &addr)) continue;
		const char* name = tok[nt - 1];
		if (!isIdent(name)) continue;
		if (nt == 2 && tok[0][0] != '0') continue;
		uint32_t region = addr >> 24;
		if (region != 2 && region != 3 && region != 8 && region != 9) continue;
		uint32_t dummy;
		if (symFind(name, &dummy)) continue; /* keep first definition */
		symAdd(name, addr);
	}
	fclose(f);
	if (!quiet) fprintf(stderr, "gbaplay: loaded %zu symbols from %s\n", nsyms - before, path);
	return 1;
}

/* ---------- expressions ----------
 * expr := term (('+'|'-') term)*
 * term := '*' term          (32-bit read at address)
 *       | '(' expr ')' | number | symbol
 * No spaces inside an expression. */
static const char* exprErr;
static uint32_t parseExpr(const char** p);

static uint32_t parseTerm(const char** p) {
	const char* s = *p;
	if (*s == '*') {
		*p = s + 1;
		uint32_t a = parseTerm(p);
		return core->busRead32(core, a);
	}
	if (*s == '(') {
		*p = s + 1;
		uint32_t v = parseExpr(p);
		if (**p != ')') { exprErr = "missing ')'"; return 0; }
		++*p;
		return v;
	}
	if (isdigit((unsigned char) *s)) {
		char* end;
		uint32_t v = (uint32_t) strtoul(s, &end, 0);
		*p = end;
		return v;
	}
	if (isalpha((unsigned char) *s) || *s == '_') {
		char name[256]; size_t n = 0;
		while ((isalnum((unsigned char) *s) || *s == '_') && n < sizeof(name) - 1) name[n++] = *s++;
		name[n] = 0;
		*p = s;
		uint32_t v;
		if (!symFind(name, &v)) { static char buf[300]; snprintf(buf, sizeof(buf), "unknown symbol '%s'", name); exprErr = buf; return 0; }
		return v;
	}
	exprErr = "syntax error";
	return 0;
}

static uint32_t parseExpr(const char** p) {
	uint32_t v = parseTerm(p);
	while (!exprErr && (**p == '+' || **p == '-')) {
		char op = **p; ++*p;
		uint32_t r = parseTerm(p);
		v = op == '+' ? v + r : v - r;
	}
	return v;
}

static int evalExpr(const char* s, uint32_t* out) {
	exprErr = NULL;
	const char* p = s;
	uint32_t v = parseExpr(&p);
	if (!exprErr && *p) exprErr = "trailing characters";
	if (exprErr) { fprintf(stderr, "gbaplay: bad expression '%s': %s\n", s, exprErr); return 0; }
	*out = v;
	return 1;
}

/* ---------- logging ---------- */
static void logCb(struct mLogger* logger, int category, enum mLogLevel level, const char* format, va_list args) {
	(void) logger;
	char msg[1024];
	vsnprintf(msg, sizeof(msg), format, args);
	if (category == gbaDebugCategory) {
		/* mGBA debug print (AGBPrint/MgbaPrintf from the game) */
		const char* lv = level == mLOG_FATAL ? "FATAL" : level == mLOG_ERROR ? "ERROR" : level == mLOG_WARN ? "WARN" : level == mLOG_INFO ? "INFO" : "DEBUG";
		printf("[game %s] %s\n", lv, msg);
		if (level == mLOG_FATAL) gameFatal = 1;
		return;
	}
	if (category == gbaMemCategory && strstr(msg, "Jumped to invalid address")) {
		printf("[CRASH] frame %lu: %s\n", totalFrames, msg);
		crashed = 1;
		return;
	}
	if ((level & logMask) || verbose >= 2) {
		printf("[mgba %s] %s\n", mLogCategoryName(category), msg);
	}
}

static struct mLogger logger = { .log = logCb, .filter = NULL };

static void crashCb(void* ctx) {
	(void) ctx;
	crashed = 1;
}

/* ---------- emulation helpers ---------- */
static uint32_t frameHash(void) {
	uint32_t h = 2166136261u;
	const uint8_t* b = (const uint8_t*) videoBuffer;
	size_t n = (size_t) vw * vh * sizeof(color_t);
	for (size_t i = 0; i < n; i += 4) { h ^= b[i] | (b[i + 1] << 8) | (b[i + 2] << 16); h *= 16777619u; }
	return h;
}

static uint32_t cpuPC(void) {
	return ((struct ARMCore*) core->cpu)->gprs[ARM_PC];
}

static void runFrames(long n) {
	for (long i = 0; i < n; ++i) {
		core->setKeys(core, heldKeys);
		core->runFrame(core);
		++totalFrames;
		if (crashed) return;
		if (hangFrames > 0) {
			uint32_t h = frameHash();
			if (h == lastHash) {
				++sameFrames;
				if (sameFrames >= hangFrames && !hangReported) {
					printf("[HANG?] frame %lu: screen unchanged for %ld frames (PC=%08X)\n", totalFrames, sameFrames, cpuPC());
					hangReported = 1;
					hangDetected = 1;
					if (hangFatal) return;
				}
			} else {
				sameFrames = 0;
				hangReported = 0;
				lastHash = h;
			}
		}
	}
}

static char* resolveOut(const char* path, char* buf, size_t bufsz) {
	if (outDir && path[0] != '/') snprintf(buf, bufsz, "%s/%s", outDir, path);
	else snprintf(buf, bufsz, "%s", path);
	return buf;
}

static int writePNG(const char* path) {
	struct VFile* vf = VFileOpen(path, O_CREAT | O_TRUNC | O_WRONLY);
	if (!vf) { fprintf(stderr, "gbaplay: cannot write %s\n", path); return 0; }
	png_structp png = PNGWriteOpen(vf);
	png_infop info = PNGWriteHeader(png, vw, vh);
	int ok = PNGWritePixels(png, vw, vh, vw, videoBuffer);
	PNGWriteClose(png, info);
	vf->close(vf);
	return ok;
}

static int writeSave(const char* path) {
	void* sram = NULL;
	size_t size = core->savedataClone(core, &sram);
	if (!size || !sram) { fprintf(stderr, "gbaplay: no battery save data to write\n"); return 0; }
	char tmp[4096];
	snprintf(tmp, sizeof(tmp), "%s.tmp", path);
	FILE* f = fopen(tmp, "wb");
	if (!f) { free(sram); fprintf(stderr, "gbaplay: cannot write %s\n", tmp); return 0; }
	size_t w = fwrite(sram, 1, size, f);
	fclose(f);
	free(sram);
	if (w != size || rename(tmp, path) != 0) { fprintf(stderr, "gbaplay: failed writing %s\n", path); return 0; }
	if (!quiet) fprintf(stderr, "gbaplay: wrote battery save %s (%zu bytes)\n", path, size);
	return 1;
}

static int loadSaveFile(const char* path) {
	FILE* f = fopen(path, "rb");
	void* data = NULL;
	size_t size = 0;
	if (f) {
		fseek(f, 0, SEEK_END);
		long sz = ftell(f);
		fseek(f, 0, SEEK_SET);
		if (sz > 0) {
			data = malloc(sz);
			size = fread(data, 1, sz, f);
		}
		fclose(f);
		if (!quiet) fprintf(stderr, "gbaplay: loaded battery save %s (%zu bytes)\n", path, size);
	} else if (!quiet) {
		fprintf(stderr, "gbaplay: battery save %s does not exist yet, starting blank\n", path);
	}
	/* The save lives in memory while running; it is written back explicitly
	 * (atomically) at exit or with the `writesave` command. */
	struct VFile* vf = VFileMemChunk(data, size);
	free(data);
	return vf && core->loadSave(core, vf);
}

/* ---------- keys ---------- */
static const char* keyNames[] = { "A", "B", "SELECT", "START", "RIGHT", "LEFT", "UP", "DOWN", "R", "L" };

static int parseKeys(const char* s, uint32_t* out) {
	uint32_t k = 0;
	char buf[128];
	snprintf(buf, sizeof(buf), "%s", s);
	for (char* t = strtok(buf, "+,"); t; t = strtok(NULL, "+,")) {
		int found = 0;
		for (int i = 0; i < 10; ++i) {
			if (strcasecmp(t, keyNames[i]) == 0) { k |= 1u << i; found = 1; break; }
		}
		if (!found) { fprintf(stderr, "gbaplay: unknown key '%s'\n", t); return 0; }
	}
	*out = k;
	return 1;
}

/* ---------- script ---------- */
static int scriptError(const char* file, int line, const char* msg) {
	fprintf(stderr, "gbaplay: %s:%d: %s\n", file, line, msg);
	return 0;
}

static long toLong(const char* s, long def) {
	if (!s) return def;
	char* end;
	long v = strtol(s, &end, 0);
	return *end ? def : v;
}

static void hexdump(uint32_t addr, uint32_t len) {
	for (uint32_t off = 0; off < len; off += 16) {
		printf("%08X:", addr + off);
		for (uint32_t i = 0; i < 16 && off + i < len; ++i) printf(" %02X", core->busRead8(core, addr + off + i) & 0xFF);
		printf("\n");
	}
}

static uint32_t readN(int width, uint32_t addr) {
	switch (width) {
	case 8: return core->busRead8(core, addr) & 0xFF;
	case 16: return core->busRead16(core, addr) & 0xFFFF;
	default: return core->busRead32(core, addr);
	}
}

static int flagGet(uint32_t id, int* out) {
	uint32_t base, off;
	if (!symFind("gSaveBlock1Ptr", &base)) { fprintf(stderr, "gbaplay: flag needs symbol gSaveBlock1Ptr (use --syms)\n"); return 0; }
	if (!symFind("SB1_FLAGS_OFFSET", &off)) { fprintf(stderr, "gbaplay: flag needs SB1_FLAGS_OFFSET (use --defs or `define`)\n"); return 0; }
	uint32_t sb1 = core->busRead32(core, base);
	uint8_t byte = core->busRead8(core, sb1 + off + id / 8);
	*out = (byte >> (id % 8)) & 1;
	return 1;
}

static int varGet(uint32_t id, uint32_t* out) {
	uint32_t base, off;
	if (id < 0x4000 || id >= 0x8000) { fprintf(stderr, "gbaplay: var 0x%X: only saved vars 0x4000-0x7FFF are supported\n", id); return 0; }
	if (!symFind("gSaveBlock1Ptr", &base)) { fprintf(stderr, "gbaplay: var needs symbol gSaveBlock1Ptr (use --syms)\n"); return 0; }
	if (!symFind("SB1_VARS_OFFSET", &off)) { fprintf(stderr, "gbaplay: var needs SB1_VARS_OFFSET (use --defs or `define`)\n"); return 0; }
	uint32_t sb1 = core->busRead32(core, base);
	*out = core->busRead16(core, sb1 + off + (id - 0x4000) * 2) & 0xFFFF;
	return 1;
}

static int stopRequested = 0;

static int shouldAbort(void) {
	return crashed || (hangFatal && hangDetected) || (fatalIsFail && gameFatal) || stopRequested;
}

static int execCommand(char** tok, int nt, const char* file, int lineNo);

static int execLine(char* line, const char* file, int lineNo) {
	char* hash = strchr(line, '#');
	if (hash) *hash = 0;
	char* tok[32]; int nt = 0;
	char* save;
	/* `echo` keeps the rest of the line */
	char* p = line;
	while (isspace((unsigned char) *p)) ++p;
	if (strncmp(p, "echo", 4) == 0 && (p[4] == 0 || isspace((unsigned char) p[4]))) {
		char* msg = p + 4;
		while (isspace((unsigned char) *msg)) ++msg;
		size_t n = strlen(msg);
		while (n && isspace((unsigned char) msg[n - 1])) msg[--n] = 0;
		printf("[echo] frame %lu: %s\n", totalFrames, msg);
		return 1;
	}
	for (char* t = strtok_r(line, " \t\r\n", &save); t && nt < 32; t = strtok_r(NULL, " \t\r\n", &save)) tok[nt++] = t;
	if (!nt) return 1;
	return execCommand(tok, nt, file, lineNo);
}

static int execCommand(char** tok, int nt, const char* file, int lineNo) {
	const char* cmd = tok[0];
	char pathbuf[4096];
	if (verbose) fprintf(stderr, "gbaplay: [%lu] %s:%d: %s\n", totalFrames, file, lineNo, cmd);

	if (!strcmp(cmd, "wait")) {
		heldKeys = 0;
		runFrames(toLong(nt > 1 ? tok[1] : NULL, 1));
	} else if (!strcmp(cmd, "waitsec")) {
		heldKeys = 0;
		runFrames((long) (atof(nt > 1 ? tok[1] : "1") * 60.0));
	} else if (!strcmp(cmd, "press") || !strcmp(cmd, "hold")) {
		if (nt < 2) return scriptError(file, lineNo, "usage: press KEY[+KEY] [frames]");
		uint32_t k;
		if (!parseKeys(tok[1], &k)) return scriptError(file, lineNo, "bad key");
		long frames = toLong(nt > 2 ? tok[2] : NULL, !strcmp(cmd, "press") ? 2 : 30);
		heldKeys = k;
		runFrames(frames);
		heldKeys = 0;
		if (!strcmp(cmd, "press") && !shouldAbort()) runFrames(releaseGap);
	} else if (!strcmp(cmd, "release")) {
		heldKeys = 0;
	} else if (!strcmp(cmd, "gap")) {
		releaseGap = (int) toLong(nt > 1 ? tok[1] : NULL, 2);
	} else if (!strcmp(cmd, "screenshot")) {
		if (nt < 2) return scriptError(file, lineNo, "usage: screenshot FILE.png");
		resolveOut(tok[1], pathbuf, sizeof(pathbuf));
		if (!writePNG(pathbuf)) return scriptError(file, lineNo, "screenshot failed");
		printf("[screenshot] frame %lu -> %s\n", totalFrames, pathbuf);
	} else if (!strcmp(cmd, "savestate") || !strcmp(cmd, "loadstate")) {
		if (nt < 2) return scriptError(file, lineNo, "usage: savestate|loadstate FILE");
		resolveOut(tok[1], pathbuf, sizeof(pathbuf));
		int saving = !strcmp(cmd, "savestate");
		struct VFile* vf = VFileOpen(pathbuf, saving ? (O_CREAT | O_TRUNC | O_RDWR) : O_RDONLY);
		if (!vf) return scriptError(file, lineNo, "cannot open state file");
		int flags = SAVESTATE_SAVEDATA | SAVESTATE_RTC;
		bool ok = saving ? mCoreSaveStateNamed(core, vf, flags) : mCoreLoadStateNamed(core, vf, flags);
		vf->close(vf);
		if (!ok) return scriptError(file, lineNo, "savestate operation failed");
		printf("[%s] frame %lu %s\n", cmd, totalFrames, pathbuf);
	} else if (!strcmp(cmd, "writesave")) {
		const char* dst = nt > 1 ? resolveOut(tok[1], pathbuf, sizeof(pathbuf)) : (savOutPath ? savOutPath : savPath);
		if (!dst) return scriptError(file, lineNo, "writesave: no path (give one or use --sav)");
		if (!writeSave(dst)) return scriptError(file, lineNo, "writesave failed");
	} else if (!strcmp(cmd, "reset")) {
		core->reset(core);
		printf("[reset] frame %lu (soft reset, battery save kept in memory)\n", totalFrames);
	} else if (!strcmp(cmd, "turbo") || !strcmp(cmd, "realtime")) {
		/* gbaplay always runs unthrottled; accepted for compatibility */
	} else if (!strcmp(cmd, "readmem") || !strcmp(cmd, "dumpmem")) {
		int dump = !strcmp(cmd, "dumpmem");
		if (nt < 3 || (dump && nt < 4)) return scriptError(file, lineNo, dump ? "usage: dumpmem EXPR LEN FILE" : "usage: readmem EXPR LEN");
		uint32_t a, len;
		if (!evalExpr(tok[1], &a) || !evalExpr(tok[2], &len)) return scriptError(file, lineNo, "bad expression");
		if (dump) {
			resolveOut(tok[3], pathbuf, sizeof(pathbuf));
			FILE* f = fopen(pathbuf, "wb");
			if (!f) return scriptError(file, lineNo, "cannot open dump file");
			for (uint32_t i = 0; i < len; ++i) fputc(core->busRead8(core, a + i) & 0xFF, f);
			fclose(f);
			printf("[dumpmem] %08X+%u -> %s\n", a, len, pathbuf);
		} else {
			printf("[readmem] %s = %08X, %u bytes:\n", tok[1], a, len);
			hexdump(a, len);
		}
	} else if (!strncmp(cmd, "read", 4) && (!strcmp(cmd + 4, "8") || !strcmp(cmd + 4, "16") || !strcmp(cmd + 4, "32"))) {
		if (nt < 2) return scriptError(file, lineNo, "usage: read8|read16|read32 EXPR");
		uint32_t a;
		if (!evalExpr(tok[1], &a)) return scriptError(file, lineNo, "bad expression");
		uint32_t v = readN(atoi(cmd + 4), a);
		printf("[%s] %s (%08X) = 0x%X (%u)\n", cmd, tok[1], a, v, v);
	} else if (!strncmp(cmd, "write", 5) && (!strcmp(cmd + 5, "8") || !strcmp(cmd + 5, "16") || !strcmp(cmd + 5, "32"))) {
		if (nt < 3) return scriptError(file, lineNo, "usage: write8|write16|write32 EXPR VALUE");
		uint32_t a, v;
		if (!evalExpr(tok[1], &a) || !evalExpr(tok[2], &v)) return scriptError(file, lineNo, "bad expression");
		int w = atoi(cmd + 5);
		if (w == 8) core->busWrite8(core, a, v); else if (w == 16) core->busWrite16(core, a, v); else core->busWrite32(core, a, v);
		printf("[%s] %08X <- 0x%X\n", cmd, a, v);
	} else if (!strncmp(cmd, "expect", 6) && (!strcmp(cmd + 6, "8") || !strcmp(cmd + 6, "16") || !strcmp(cmd + 6, "32"))) {
		if (nt < 3) return scriptError(file, lineNo, "usage: expect8|16|32 EXPR VALUE");
		uint32_t a, v;
		if (!evalExpr(tok[1], &a) || !evalExpr(tok[2], &v)) return scriptError(file, lineNo, "bad expression");
		uint32_t got = readN(atoi(cmd + 6), a);
		int ok = got == v;
		if (!ok) ++expectFailures;
		printf("[%s] %s:%d %s (%08X) == 0x%X ? got 0x%X\n", ok ? "PASS" : "FAIL", file, lineNo, tok[1], a, v, got);
	} else if (!strcmp(cmd, "waitfor8") || !strcmp(cmd, "waitfor16") || !strcmp(cmd, "waitfor32")) {
		if (nt < 4) return scriptError(file, lineNo, "usage: waitforN EXPR VALUE MAXFRAMES [KEY [PERIOD]]");
		uint32_t a, v, mashKeys = 0;
		if (!evalExpr(tok[2], &v)) return scriptError(file, lineNo, "bad expression");
		long maxf = toLong(tok[3], 600);
		if (nt > 4 && !parseKeys(tok[4], &mashKeys)) return scriptError(file, lineNo, "bad key");
		long period = toLong(nt > 5 ? tok[5] : NULL, 8);
		if (period < 2) period = 2;
		int w = atoi(cmd + 7);
		long f = 0;
		heldKeys = 0;
		for (; f < maxf && !shouldAbort(); ++f) {
			if (!evalExpr(tok[1], &a)) return scriptError(file, lineNo, "bad expression");
			if (readN(w, a) == v) break;
			/* optional mashing: KEY held for 2 frames every PERIOD frames */
			heldKeys = (mashKeys && (f % period) < 2) ? mashKeys : 0;
			runFrames(1);
		}
		heldKeys = 0;
		int ok = f < maxf && !shouldAbort();
		if (!ok) ++expectFailures;
		printf("[%s] %s:%d waitfor %s == 0x%X after %ld frames\n", ok ? "PASS" : "FAIL", file, lineNo, tok[1], v, f);
	} else if (!strcmp(cmd, "flag") || !strcmp(cmd, "expectflag")) {
		if (nt < 2) return scriptError(file, lineNo, "usage: flag ID | expectflag ID 0|1");
		uint32_t id; int v;
		if (!evalExpr(tok[1], &id) || !flagGet(id, &v)) return scriptError(file, lineNo, "flag read failed");
		if (!strcmp(cmd, "flag")) {
			printf("[flag] %s (0x%X) = %d\n", tok[1], id, v);
		} else {
			if (nt < 3) return scriptError(file, lineNo, "usage: expectflag ID 0|1");
			int want = (int) toLong(tok[2], 1);
			if (v != want) ++expectFailures;
			printf("[%s] %s:%d flag %s (0x%X) == %d ? got %d\n", v == want ? "PASS" : "FAIL", file, lineNo, tok[1], id, want, v);
		}
	} else if (!strcmp(cmd, "var") || !strcmp(cmd, "expectvar")) {
		if (nt < 2) return scriptError(file, lineNo, "usage: var ID | expectvar ID VALUE");
		uint32_t id, v;
		if (!evalExpr(tok[1], &id) || !varGet(id, &v)) return scriptError(file, lineNo, "var read failed");
		if (!strcmp(cmd, "var")) {
			printf("[var] %s (0x%X) = %u\n", tok[1], id, v);
		} else {
			uint32_t want;
			if (nt < 3 || !evalExpr(tok[2], &want)) return scriptError(file, lineNo, "usage: expectvar ID VALUE");
			if (v != want) ++expectFailures;
			printf("[%s] %s:%d var %s (0x%X) == %u ? got %u\n", v == want ? "PASS" : "FAIL", file, lineNo, tok[1], id, want, v);
		}
	} else if (!strcmp(cmd, "define")) {
		if (nt < 3 || !isIdent(tok[1])) return scriptError(file, lineNo, "usage: define NAME EXPR");
		uint32_t v;
		if (!evalExpr(tok[2], &v)) return scriptError(file, lineNo, "bad expression");
		symAdd(tok[1], v);
	} else if (!strcmp(cmd, "pc")) {
		printf("[pc] frame %lu PC=%08X\n", totalFrames, cpuPC());
	} else if (!strcmp(cmd, "hangcheck")) {
		hangFrames = toLong(nt > 1 ? tok[1] : NULL, 600);
		sameFrames = 0; hangReported = 0;
	} else if (!strcmp(cmd, "repeat")) {
		if (nt < 3) return scriptError(file, lineNo, "usage: repeat N COMMAND ARGS...");
		long n = toLong(tok[1], -1);
		if (n < 0) return scriptError(file, lineNo, "repeat: bad count");
		for (long i = 0; i < n && !shouldAbort(); ++i) {
			if (!execCommand(tok + 2, nt - 2, file, lineNo)) return 0;
		}
	} else if (!strcmp(cmd, "quit") || !strcmp(cmd, "exit")) {
		stopRequested = 1;
	} else {
		return scriptError(file, lineNo, "unknown command");
	}
	return 1;
}

static int runScript(const char* path) {
	FILE* f = strcmp(path, "-") ? fopen(path, "r") : stdin;
	if (!f) { fprintf(stderr, "gbaplay: cannot open script %s\n", path); return 0; }
	char line[4096];
	int lineNo = 0;
	int ok = 1;
	while (fgets(line, sizeof(line), f)) {
		++lineNo;
		char* p = line;
		while (isspace((unsigned char) *p)) ++p;
		if (!strncmp(p, "include", 7) && isspace((unsigned char) p[7])) {
			char* inc = p + 8;
			while (isspace((unsigned char) *inc)) ++inc;
			inc[strcspn(inc, " \t\r\n")] = 0;
			char incPath[4096];
			if (inc[0] != '/' && strchr(path, '/')) {
				snprintf(incPath, sizeof(incPath), "%.*s/%s", (int) (strrchr(path, '/') - path), path, inc);
			} else {
				snprintf(incPath, sizeof(incPath), "%s", inc);
			}
			if (!runScript(incPath)) { ok = 0; break; }
			continue;
		}
		if (!execLine(line, path, lineNo)) { ok = 0; break; }
		if (shouldAbort()) break;
	}
	if (f != stdin) fclose(f);
	return ok;
}

static void usage(const char* argv0) {
	fprintf(stderr,
		"usage: %s [options] ROM [SCRIPT|-]\n"
		"  -f, --frames N        run N frames (after the script, if any)\n"
		"  -s, --sav FILE        battery save: loaded at boot if present, written back at exit\n"
		"      --sav-out FILE    write the battery save here instead of --sav\n"
		"      --no-sav-write    never write the battery save at exit\n"
		"  -t, --state FILE      load a savestate before running\n"
		"  -o, --outdir DIR      base dir for relative screenshot/state/dump paths\n"
		"      --syms FILE       symbol file (.sym from `make syms`, nm output or .map); may repeat\n"
		"      --defs FILE       extra NAME VALUE definitions (e.g. struct offsets); may repeat\n"
		"  -D NAME=VALUE         define a constant usable in expressions\n"
		"      --screenshot FILE screenshot at exit\n"
		"      --hang N          warn when the screen is unchanged for N frames\n"
		"      --hang-fatal      stop with exit code 4 when a hang is detected\n"
		"      --fatal-is-fail   stop with exit code 6 on a game FATAL log (assert)\n"
		"      --rtc EPOCH       RTC start time (unix seconds, default 1767268800 = 2026-01-01 12:00 UTC);\n"
		"                        the clock advances with emulated time (deterministic). 'wall' = host clock\n"
		"      --bios FILE       use a real GBA BIOS (default: mGBA HLE BIOS)\n"
		"  -l, --log MASK        mGBA log levels to print (default 3 = FATAL|ERROR; 127 = all)\n"
		"  -v, --verbose         trace script commands (-v -v: all mGBA logs)\n"
		"  -q, --quiet           less chatter on stderr\n"
		"Exit: 0 ok, 1 load error, 2 script error, 3 expect failed, 4 hang, 5 crash, 6 game fatal\n",
		argv0);
}

static int loadDefs(const char* path) {
	FILE* f = fopen(path, "r");
	if (!f) { fprintf(stderr, "gbaplay: cannot open defs %s\n", path); return 0; }
	char line[512];
	while (fgets(line, sizeof(line), f)) {
		char name[256], val[256];
		if (line[0] == '#') continue;
		if (sscanf(line, "%255s %255s", name, val) == 2 && isIdent(name)) symAdd(name, (uint32_t) strtoul(val, NULL, 0));
	}
	fclose(f);
	return 1;
}

int main(int argc, char** argv) {
	setvbuf(stdout, NULL, _IOLBF, 0);
	const char* romPath = NULL;
	const char* scriptPath = NULL;
	const char* statePath = NULL;
	const char* finalShot = NULL;
	const char* biosPath = NULL;
	long extraFrames = 0;
	int noSavWrite = 0;
	int64_t rtcEpoch = 1767268800LL;
	int rtcWall = 0;
	const char* symFiles[16]; int nSymFiles = 0;
	const char* defFiles[16]; int nDefFiles = 0;
	const char* cliDefs[64]; int nCliDefs = 0;

	for (int i = 1; i < argc; ++i) {
		const char* a = argv[i];
#define NEXT() (i + 1 < argc ? argv[++i] : (usage(argv[0]), exit(1), (char*) NULL))
		if (!strcmp(a, "-f") || !strcmp(a, "--frames")) extraFrames = atol(NEXT());
		else if (!strcmp(a, "-s") || !strcmp(a, "--sav")) savPath = NEXT();
		else if (!strcmp(a, "--sav-out")) savOutPath = NEXT();
		else if (!strcmp(a, "--no-sav-write")) noSavWrite = 1;
		else if (!strcmp(a, "-t") || !strcmp(a, "--state")) statePath = NEXT();
		else if (!strcmp(a, "-o") || !strcmp(a, "--outdir")) outDir = NEXT();
		else if (!strcmp(a, "--syms")) { if (nSymFiles < 16) symFiles[nSymFiles++] = NEXT(); }
		else if (!strcmp(a, "--defs")) { if (nDefFiles < 16) defFiles[nDefFiles++] = NEXT(); }
		else if (!strcmp(a, "-D")) { if (nCliDefs < 64) cliDefs[nCliDefs++] = NEXT(); }
		else if (!strcmp(a, "--screenshot")) finalShot = NEXT();
		else if (!strcmp(a, "--hang")) hangFrames = atol(NEXT());
		else if (!strcmp(a, "--hang-fatal")) hangFatal = 1;
		else if (!strcmp(a, "--fatal-is-fail")) fatalIsFail = 1;
		else if (!strcmp(a, "--rtc")) { const char* v = NEXT(); if (!strcmp(v, "wall")) rtcWall = 1; else rtcEpoch = atoll(v); }
		else if (!strcmp(a, "--bios")) biosPath = NEXT();
		else if (!strcmp(a, "-l") || !strcmp(a, "--log")) logMask = (int) strtol(NEXT(), NULL, 0);
		else if (!strcmp(a, "-v") || !strcmp(a, "--verbose")) ++verbose;
		else if (!strcmp(a, "-q") || !strcmp(a, "--quiet")) quiet = 1;
		else if (!strcmp(a, "-h") || !strcmp(a, "--help")) { usage(argv[0]); return 0; }
		else if (a[0] == '-' && a[1]) { fprintf(stderr, "gbaplay: unknown option %s\n", a); usage(argv[0]); return 1; }
		else if (!romPath) romPath = a;
		else if (!scriptPath) scriptPath = a;
		else { usage(argv[0]); return 1; }
	}
	if (!romPath) { usage(argv[0]); return 1; }
	if (hangFatal && !hangFrames) hangFrames = 600;
	if (outDir) mkdir(outDir, 0755);

	mLogSetDefaultLogger(&logger);
	gbaDebugCategory = mLogCategoryById("gba.debug");
	gbaMemCategory = mLogCategoryById("gba.memory");

	core = mCoreFind(romPath);
	if (!core) { fprintf(stderr, "gbaplay: unsupported ROM %s\n", romPath); return 1; }
	core->init(core);
	mCoreInitConfig(core, NULL);
	mCoreConfigSetDefaultValue(&core->config, "idleOptimization", "detect");
	mCoreLoadForeignConfig(core, &core->config);

	core->desiredVideoDimensions(core, &vw, &vh);
	videoBuffer = calloc((size_t) vw * vh, sizeof(color_t));
	core->setVideoBuffer(core, videoBuffer, vw);
	core->setAudioBufferSize(core, 2048);

	struct VFile* romVf = VFileOpen(romPath, O_RDONLY);
	if (!romVf || !core->loadROM(core, romVf)) { fprintf(stderr, "gbaplay: cannot load ROM %s\n", romPath); return 1; }
	if (biosPath) {
		struct VFile* bvf = VFileOpen(biosPath, O_RDONLY);
		if (!bvf || !core->loadBIOS(core, bvf, 0)) { fprintf(stderr, "gbaplay: cannot load BIOS %s\n", biosPath); return 1; }
		mCoreConfigSetValue(&core->config, "useBios", "1");
		mCoreLoadForeignConfig(core, &core->config);
	}
	if (savPath) {
		if (!loadSaveFile(savPath)) { fprintf(stderr, "gbaplay: cannot attach save %s\n", savPath); return 1; }
	}

	if (!rtcWall) {
		core->rtc.override = RTC_FAKE_EPOCH;
		core->rtc.value = rtcEpoch * 1000LL;
	}

	struct mCoreCallbacks cbs = { 0 };
	cbs.coreCrashed = crashCb;
	core->addCoreCallbacks(core, &cbs);
	if (core->platform(core) == mPLATFORM_GBA) ((struct GBA*) core->board)->hardCrash = false;

	core->reset(core);

	for (int i = 0; i < nSymFiles; ++i) if (!loadSymbols(symFiles[i])) return 1;
	for (int i = 0; i < nDefFiles; ++i) if (!loadDefs(defFiles[i])) return 1;
	for (int i = 0; i < nCliDefs; ++i) {
		char buf[256];
		snprintf(buf, sizeof(buf), "%s", cliDefs[i]);
		char* eq = strchr(buf, '=');
		if (!eq) { fprintf(stderr, "gbaplay: -D expects NAME=VALUE\n"); return 1; }
		*eq = 0;
		symAdd(buf, (uint32_t) strtoul(eq + 1, NULL, 0));
	}

	if (statePath) {
		struct VFile* svf = VFileOpen(statePath, O_RDONLY);
		if (!svf || !mCoreLoadStateNamed(core, svf, SAVESTATE_SAVEDATA | SAVESTATE_RTC)) { fprintf(stderr, "gbaplay: cannot load state %s\n", statePath); return 1; }
		svf->close(svf);
	}

	int rc = 0;
	if (scriptPath && !runScript(scriptPath)) rc = 2;
	if (!rc && !shouldAbort() && extraFrames > 0) runFrames(extraFrames);

	if (finalShot) {
		char pathbuf[4096];
		resolveOut(finalShot, pathbuf, sizeof(pathbuf));
		if (writePNG(pathbuf)) printf("[screenshot] frame %lu -> %s\n", totalFrames, pathbuf);
	}
	if (savPath && !noSavWrite) writeSave(savOutPath ? savOutPath : savPath);
	else if (savOutPath && !noSavWrite) writeSave(savOutPath);

	if (!rc) {
		if (crashed) rc = 5;
		else if (fatalIsFail && gameFatal) rc = 6;
		else if (hangFatal && hangDetected) rc = 4;
		else if (expectFailures) rc = 3;
	}
	printf("[gbaplay] done: %lu frames (%.1f s emulated), expect failures: %d, crash: %s, hang: %s, exit %d\n",
		totalFrames, totalFrames / 59.7275, expectFailures, crashed ? "yes" : "no", hangDetected ? "yes" : "no", rc);

	core->unloadROM(core);
	mCoreConfigDeinit(&core->config);
	core->deinit(core);
	free(videoBuffer);
	return rc;
}

#!/usr/bin/env python3
"""
validate_trainers.py -- validation statique des équipes de dresseurs (.party)
pour pokeemeraude-expansion 1.16.x.

Python 3 stdlib uniquement. Lecture seule : ne modifie aucun fichier, ne lance pas make.

Ce qui est vérifié (OBLIGATOIRE, niveau ERREUR) :
  * existence des constantes générées par trainerproc à partir du texte :
      SPECIES_*, ITEM_* (objets tenus + objets du dresseur), MOVE_*, ABILITY_*,
      NATURE_*, BALL_*, TYPE_* (Tera Type), AI_FLAG_*, TRAINER_CLASS_*,
      TRAINER_PIC_*, TRAINER_ENCOUNTER_MUSIC_*, MUGSHOT_COLOR_*
  * talent présent dans .abilities de l'espèce (sinon assertf() au runtime dans
    CreateNPCTrainerPartyFromTrainer -> src/battle_main.c)
  * niveau 1..100, au plus 4 capacités, au plus 6 Pokémon (hors pools / Party Size),
    au plus 4 objets de dresseur (MAX_TRAINER_ITEMS)

AVERTISSEMENTS :
  * capacité en double, EV > 252 sur une stat ou total > 510, IV > 31
  * (option --learnsets) capacité absente des learnsets connus de l'espèce et de
    ses pré-évolutions : level-up + oeufs + all_learnables.json + universalMoves
  * (option --strict-levels) capacité uniquement apprise par level-up à un niveau
    supérieur au niveau du Pokémon (et non disponible par CT/tuteur/oeuf)

Usage :
  python3 tools/qa/validate_trainers.py                       # src/data/trainers.party
  python3 tools/qa/validate_trainers.py --learnsets
  python3 tools/qa/validate_trainers.py --learnsets --strict-levels
  python3 tools/qa/validate_trainers.py -f src/data/trainers_frlg.party --summary
  python3 tools/qa/validate_trainers.py --trainer TRAINER_ROXANNE_1 --learnsets

Code de sortie : 0 si aucune erreur, 1 sinon (les avertissements ne font pas échouer,
sauf avec --werror).
"""

import argparse
import json
import os
import re
import sys
from collections import defaultdict

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))


def rp(*parts):
    return os.path.join(ROOT, *parts)


def read(path):
    with open(path, encoding="utf-8", errors="replace") as fh:
        return fh.read()


def strip_c_comments(text):
    text = re.sub(r"/\*.*?\*/", lambda m: "\n" * m.group(0).count("\n"), text, flags=re.S)
    return re.sub(r"//[^\n]*", "", text)


# --------------------------------------------------------------------------- #
# Collecte des constantes
# --------------------------------------------------------------------------- #

def collect_constants(paths, prefix):
    """Identifiants PREFIX_* définis comme membre d'enum ou #define."""
    pat_enum = re.compile(r"^\s*(" + prefix + r"_\w+)\s*(?:=|,|$)", re.M)
    pat_def = re.compile(r"^\s*#\s*define\s+(" + prefix + r"_\w+)\b", re.M)
    out = set()
    for p in paths:
        if not os.path.exists(p):
            continue
        t = strip_c_comments(read(p))
        out.update(pat_enum.findall(t))
        out.update(pat_def.findall(t))
    return out


def load_constants():
    c = {}
    c["SPECIES"] = collect_constants([rp("include/constants/species.h")], "SPECIES")
    c["ITEM"] = collect_constants([rp("include/constants/items.h")], "ITEM")
    c["MOVE"] = collect_constants([rp("include/constants/moves.h")], "MOVE")
    c["ABILITY"] = collect_constants([rp("include/constants/abilities.h")], "ABILITY")
    c["NATURE"] = collect_constants([rp("include/constants/pokemon.h")], "NATURE")
    c["TYPE"] = collect_constants([rp("include/constants/pokemon.h")], "TYPE")
    c["BALL"] = collect_constants([rp("include/constants/pokeball.h")], "BALL")
    c["AI_FLAG"] = collect_constants([rp("include/constants/battle_ai.h")], "AI_FLAG")
    tr = [rp("include/constants/trainers.h")]
    c["TRAINER_CLASS"] = collect_constants(tr, "TRAINER_CLASS")
    c["TRAINER_PIC"] = collect_constants(tr, "TRAINER_PIC")
    c["TRAINER_BACK_PIC"] = collect_constants(tr, "TRAINER_BACK_PIC")
    c["TRAINER_ENCOUNTER_MUSIC"] = collect_constants(tr, "TRAINER_ENCOUNTER_MUSIC")
    c["MUGSHOT_COLOR"] = collect_constants([rp("include/battle_transition.h")], "MUGSHOT_COLOR")
    return c


# --------------------------------------------------------------------------- #
# Conversions texte -> constante (copie fidèle de tools/trainerproc/main.c)
# --------------------------------------------------------------------------- #

def is_constant(s, prefix):
    return s.startswith(prefix + "_")


def to_constant(prefix, s):
    """fprint_constant(): chaque caractère non alphanumérique -> '_', apostrophe supprimée."""
    if s == "":
        return prefix + "_NONE"
    out = [] if is_constant(s, prefix) else [prefix + "_"]
    for ch in s:
        if "A" <= ch <= "Z" or "0" <= ch <= "9":
            out.append(ch)
        elif "a" <= ch <= "z":
            out.append(ch.upper())
        elif ch == "'":
            pass
        else:
            out.append("_")
    return "".join(out)


def to_species(s):
    """fprint_species(): les séparateurs consécutifs fusionnent en un seul '_'."""
    if s == "":
        return "SPECIES_NONE"
    out = [] if is_constant(s, "SPECIES") else ["SPECIES_"]
    underscore = False
    for ch in s:
        if ("A" <= ch <= "Z") or ("0" <= ch <= "9") or ("a" <= ch <= "z"):
            if underscore:
                out.append("_")
            underscore = False
            out.append(ch.upper())
        elif ch in ("'", "%", "’"):
            pass
        elif ch == "♂":
            underscore = False
            out.append("_M")
        elif ch == "♀":
            underscore = False
            out.append("_F")
        elif ch == "é":
            if underscore:
                out.append("_")
            underscore = False
            out.append("E")
        else:
            underscore = True
    return "".join(out)


# --------------------------------------------------------------------------- #
# Données d'espèces / learnsets
# --------------------------------------------------------------------------- #

def balanced_after(text, start):
    """text[start] == '(' ; renvoie le contenu jusqu'à la parenthèse fermante."""
    depth = 0
    for i in range(start, len(text)):
        if text[i] == "(":
            depth += 1
        elif text[i] == ")":
            depth -= 1
            if depth == 0:
                return text[start + 1:i]
    return text[start + 1:]


class SpeciesDB:
    def __init__(self):
        self.abilities = {}        # SPECIES -> set(ABILITY) | None si non résolu
        self.levelup_sym = {}
        self.teach_sym = {}
        self.egg_sym = {}
        self.preevo = defaultdict(set)
        self.levelup = {}          # sym -> list[(lvl, MOVE)]
        self.egg = {}              # sym -> set(MOVE)
        self.learnables = {}
        self.universal = set()
        self._load()

    def _load(self):
        files = []
        d = rp("src/data/pokemon/species_info")
        for f in sorted(os.listdir(d)):
            if f.endswith(".h"):
                files.append(os.path.join(d, f))
        files.append(rp("src/data/pokemon/species_info.h"))
        texts = {f: strip_c_comments(read(f)) for f in files if os.path.exists(f)}
        alltext = "\n".join(texts.values())

        # macros (ex: MEOWTH_ABILITIES, UNOWN_MISC_INFO(...))
        macros = {}
        for m in re.finditer(r"^\s*#\s*define\s+(\w+)(\([^)]*\))?[ \t]*((?:[^\n]*\\\n)*[^\n]*)", alltext, re.M):
            macros[m.group(1)] = m.group(3).replace("\\\n", "\n")

        entry_pat = re.compile(r"^\s*\[(SPECIES_\w+)\]\s*=", re.M)
        for text in texts.values():
            starts = [(m.group(1), m.end()) for m in entry_pat.finditer(text)]
            for idx, (sp, pos) in enumerate(starts):
                end = starts[idx + 1][1] if idx + 1 < len(starts) else len(text)
                block = text[pos:end]
                # expansion (2 niveaux) des macros référencées dans le bloc
                for _ in range(2):
                    used = set(re.findall(r"\b([A-Z][A-Z0-9_]+)\b", block)) & macros.keys()
                    if not used:
                        break
                    block = block + "\n" + "\n".join(macros[u] for u in sorted(used))
                self._parse_block(sp, block, macros)

        # learnsets level-up
        lu_files = [os.path.join(rp("src/data/pokemon/level_up_learnsets"), f)
                    for f in os.listdir(rp("src/data/pokemon/level_up_learnsets")) if f.endswith(".h")]
        lu_files.append(rp("src/data/pokemon/species_info.h"))
        for f in lu_files:
            if not os.path.exists(f):
                continue
            t = strip_c_comments(read(f))
            for m in re.finditer(r"struct\s+LevelUpMove\s+(\w+)\s*\[\]\s*=\s*\{(.*?)\};", t, re.S):
                self.levelup.setdefault(m.group(1), []).extend(
                    (int(a), b) for a, b in re.findall(r"LEVEL_UP_MOVE\(\s*(\d+)\s*,\s*(MOVE_\w+)\s*\)", m.group(2)))
        # oeufs
        for f in (rp("src/data/pokemon/egg_moves.h"), rp("src/data/pokemon/species_info.h")):
            if os.path.exists(f):
                t = strip_c_comments(read(f))
                for m in re.finditer(r"u16\s+(\w+EggMoveLearnset)\s*\[\]\s*=\s*\{(.*?)\};", t, re.S):
                    self.egg.setdefault(m.group(1), set()).update(re.findall(r"MOVE_\w+", m.group(2)))
        # CT / tuteurs potentiels
        p = rp("src/data/pokemon/all_learnables.json")
        if os.path.exists(p):
            self.learnables = {k: set(v) for k, v in json.load(open(p, encoding="utf-8")).items()}
        p = rp("src/data/pokemon/special_movesets.json")
        if os.path.exists(p):
            self.universal = set(json.load(open(p, encoding="utf-8")).get("universalMoves", []))

    def _parse_block(self, sp, block, macros):
        ab = None
        m = re.search(r"\.abilities\s*=\s*(\{[^}]*\}|\w+)", block)
        if m:
            val = m.group(1)
            if not val.startswith("{") and val in macros:
                val = macros[val]
            toks = set(re.findall(r"ABILITY_\w+", val)) - {"ABILITY_NONE"}
            # union des branches #if éventuelles
            for m2 in re.finditer(r"\.abilities\s*=\s*\{([^}]*)\}", block):
                toks |= set(re.findall(r"ABILITY_\w+", m2.group(1))) - {"ABILITY_NONE"}
            ab = toks or None
        if sp not in self.abilities or self.abilities[sp] is None:
            self.abilities[sp] = ab
        elif ab:
            self.abilities[sp] |= ab
        for field, store in ((r"levelUpLearnset", self.levelup_sym),
                             (r"teachableLearnset", self.teach_sym),
                             (r"eggMoveLearnset", self.egg_sym)):
            mm = re.search(r"\." + field + r"\s*=\s*(\w+)", block)
            if mm and sp not in store:
                store[sp] = mm.group(1)
        i = block.find(".evolutions")
        if i >= 0:
            j = block.find("(", i)
            if j >= 0:
                body = balanced_after(block, j)
                for tgt in re.findall(r"SPECIES_\w+", body):
                    if tgt != sp:
                        self.preevo[tgt].add(sp)

    @staticmethod
    def _teach_key(sym):
        m = re.match(r"s(\w+?)TeachableLearnset$", sym or "")
        if not m:
            return None
        return re.sub(r"(?!^)([A-Z]+)", r"_\1", m.group(1)).upper()

    def lineage(self, sp):
        seen, todo = [], [sp]
        while todo:
            s = todo.pop()
            if s in seen:
                continue
            seen.append(s)
            todo.extend(self.preevo.get(s, ()))
            # formes (SPECIES_X_MEGA, _ALOLA...) : se rabattre sur l'espèce de base si inconnue
        return seen

    def move_sources(self, sp, move):
        """Renvoie (connu, sources:set, levels:list) pour sp et ses pré-évolutions."""
        known = False
        sources, levels = set(), []
        for s in self.lineage(sp):
            lu = self.levelup.get(self.levelup_sym.get(s, ""), None)
            if lu is not None:
                known = True
                for lvl, mv in lu:
                    if mv == move:
                        sources.add("levelup")
                        levels.append(lvl)
            eg = self.egg.get(self.egg_sym.get(s, ""), None)
            if eg is not None:
                known = True
                if move in eg:
                    sources.add("egg")
            key = self._teach_key(self.teach_sym.get(s))
            if key and key in self.learnables:
                known = True
                if move in self.learnables[key]:
                    sources.add("teachable")
        if move in self.universal:
            sources.add("universal")
        if sp == "SPECIES_SMEARGLE" and move not in SKETCH_BANNED:
            sources.add("sketch")
        if FORM_SIGNATURE_MOVES.get(sp) == move:
            sources.add("form")
        return known, sources, levels


# --------------------------------------------------------------------------- #
# Parsing du fichier .party
# --------------------------------------------------------------------------- #

class Mon:
    def __init__(self, line_no):
        self.line = line_no
        self.raw_species = ""
        self.nickname = None
        self.item = None
        self.fields = {}
        self.moves = []
        self.unknown = []


class Trainer:
    def __init__(self, tid, line_no):
        self.id = tid
        self.line = line_no
        self.fields = {}
        self.mons = []


def parse_party(path):
    text = read(path)
    # retire les commentaires /* */ en conservant les numéros de ligne
    text = re.sub(r"/\*.*?\*/", lambda m: "\n" * m.group(0).count("\n"), text, flags=re.S)
    lines = text.split("\n")
    trainers = []
    cur = None
    block = []  # (line_no, text)

    def flush():
        if cur is None or not block:
            return
        first = block[0][1]
        if not cur.fields and not cur.mons and ":" in first and not first.lstrip().startswith("-") \
                and re.match(r"^[A-Za-z][A-Za-z ]*:", first):
            # bloc d'en-tête du dresseur
            for ln, t in block:
                k, _, v = t.partition(":")
                cur.fields[k.strip()] = (v.strip(), ln)
            return
        mon = Mon(block[0][0])
        head = first.strip()
        if " @ " in head:
            head, item = head.split(" @ ", 1)
            mon.item = item.strip()
        elif head.endswith("@"):
            head = head[:-1].strip()
        head = head.strip()
        head = re.sub(r"\s*\((M|F)\)\s*$", "", head)
        m = re.match(r"^(.*?)\s*\(([^()]+)\)\s*$", head)
        if m and m.group(1):
            mon.nickname, mon.raw_species = m.group(1).strip(), m.group(2).strip()
        else:
            mon.raw_species = head
        for ln, t in block[1:]:
            s = t.strip()
            if s.startswith("- "):
                mon.moves.append((s[2:].strip(), ln))
            elif re.match(r"^\S+ Nature$", s):  # syntaxe Showdown "Adamant Nature"
                mon.fields["Nature"] = (s[:-len(" Nature")].strip(), ln)
            elif ":" in s:
                k, _, v = s.partition(":")
                mon.fields[k.strip()] = (v.strip(), ln)
            else:
                mon.unknown.append((s, ln))
        cur.mons.append(mon)

    for i, raw in enumerate(lines, 1):
        line = raw.rstrip()
        m = re.match(r"^===\s*(\S+)\s*===\s*$", line)
        if m:
            flush()
            block = []
            cur = Trainer(m.group(1), i)
            trainers.append(cur)
            continue
        if cur is None:
            continue
        if line.strip() == "":
            flush()
            block = []
        else:
            block.append((i, line))
    flush()
    return trainers


# --------------------------------------------------------------------------- #
# Validation
# --------------------------------------------------------------------------- #

# Capacités données par changement de forme (non présentes dans les learnsets)
FORM_SIGNATURE_MOVES = {
    "SPECIES_ROTOM_HEAT": "MOVE_OVERHEAT", "SPECIES_ROTOM_WASH": "MOVE_HYDRO_PUMP",
    "SPECIES_ROTOM_FROST": "MOVE_BLIZZARD", "SPECIES_ROTOM_FAN": "MOVE_AIR_SLASH",
    "SPECIES_ROTOM_MOW": "MOVE_LEAF_STORM",
}

SKETCH_BANNED = {"MOVE_STRUGGLE", "MOVE_CHATTER", "MOVE_SKETCH"}

KNOWN_MON_KEYS = {"EVs", "IVs", "Ability", "Level", "Ball", "Happiness", "Nature", "Shiny",
                  "Dynamax Level", "Gigantamax", "Tera Type", "Tags"}

STAT_RE = re.compile(r"(\d+)\s*(HP|Atk|Def|SpA|SpD|Spe)", re.I)


class Report:
    def __init__(self):
        self.errors = []
        self.warnings = []

    def err(self, path, ln, tid, msg):
        self.errors.append((path, ln, tid, msg))

    def warn(self, path, ln, tid, msg):
        self.warnings.append((path, ln, tid, msg))


def check_const(rep, consts, kind, value, path, ln, tid, label, species=False):
    c = to_species(value) if species else to_constant(kind, value)
    if c not in consts[kind]:
        rep.err(path, ln, tid, "%s inconnu : '%s' -> %s" % (label, value, c))
        return None
    return c


def validate(path, trainers, consts, sdb, args, rep):
    rel = os.path.relpath(path, ROOT)
    for tr in trainers:
        if args.trainer and tr.id not in args.trainer:
            continue
        tid = tr.id
        f = tr.fields
        uses_pool = any(k in f for k in ("Party Size", "Pool Rules", "Pool Pick Functions", "Pool Prune", "Copy Pool"))
        if "Class" in f:
            check_const(rep, consts, "TRAINER_CLASS", f["Class"][0], rel, f["Class"][1], tid, "Classe")
        if "Pic" in f and f["Pic"][0]:
            check_const(rep, consts, "TRAINER_PIC", f["Pic"][0], rel, f["Pic"][1], tid, "Pic")
        if "Back Pic" in f and f["Back Pic"][0]:
            check_const(rep, consts, "TRAINER_BACK_PIC", f["Back Pic"][0], rel, f["Back Pic"][1], tid, "Back Pic")
        if "Music" in f and f["Music"][0]:
            check_const(rep, consts, "TRAINER_ENCOUNTER_MUSIC", f["Music"][0], rel, f["Music"][1], tid, "Musique")
        if "Mugshot" in f and f["Mugshot"][0]:
            check_const(rep, consts, "MUGSHOT_COLOR", f["Mugshot"][0], rel, f["Mugshot"][1], tid, "Mugshot")
        if "Items" in f and f["Items"][0]:
            items = [x.strip() for x in f["Items"][0].split("/") if x.strip()]
            if len(items) > 4:
                rep.err(rel, f["Items"][1], tid, "plus de 4 objets de dresseur (MAX_TRAINER_ITEMS=4)")
            for it in items:
                check_const(rep, consts, "ITEM", it, rel, f["Items"][1], tid, "Objet dresseur")
        if "AI" in f and f["AI"][0]:
            for fl in [x.strip() for x in f["AI"][0].split("/") if x.strip()]:
                check_const(rep, consts, "AI_FLAG", fl, rel, f["AI"][1], tid, "Flag IA")
        if not uses_pool and len(tr.mons) > 6:
            rep.err(rel, tr.line, tid, "%d Pokémon (> 6) sans 'Party Size'/pool" % len(tr.mons))
        if len(tr.mons) == 0 and tid != "TRAINER_NONE":
            rep.warn(rel, tr.line, tid, "dresseur sans Pokémon")

        for mon in tr.mons:
            ln = mon.line
            sp = check_const(rep, consts, "SPECIES", mon.raw_species, rel, ln, tid, "Espèce", species=True)
            if mon.nickname and len(mon.nickname) > 12:
                rep.warn(rel, ln, tid, "surnom > 12 caractères (tronqué) : %s" % mon.nickname)
            if mon.item:
                check_const(rep, consts, "ITEM", mon.item, rel, ln, tid, "Objet tenu")
            mf = mon.fields
            for s, uln in mon.unknown:
                rep.err(rel, uln, tid, "ligne non reconnue dans le bloc Pokémon : '%s'" % s)
            for k in mf:
                if k not in KNOWN_MON_KEYS:
                    rep.err(rel, mf[k][1], tid, "champ Pokémon inconnu de trainerproc : '%s'" % k)
            level = 100
            if "Level" in mf:
                try:
                    level = int(mf["Level"][0])
                    if not 1 <= level <= 100:
                        rep.err(rel, mf["Level"][1], tid, "niveau hors bornes : %d" % level)
                except ValueError:
                    rep.err(rel, mf["Level"][1], tid, "niveau non numérique : %s" % mf["Level"][0])
            if "Nature" in mf:
                check_const(rep, consts, "NATURE", mf["Nature"][0], rel, mf["Nature"][1], tid, "Nature")
            if "Ball" in mf:
                check_const(rep, consts, "BALL", mf["Ball"][0], rel, mf["Ball"][1], tid, "Ball")
            if "Tera Type" in mf:
                check_const(rep, consts, "TYPE", mf["Tera Type"][0], rel, mf["Tera Type"][1], tid, "Tera Type")
            if "EVs" in mf:
                evs = [int(a) for a, _ in STAT_RE.findall(mf["EVs"][0])]
                if any(e > 252 for e in evs) or sum(evs) > 510:
                    rep.warn(rel, mf["EVs"][1], tid, "EV hors normes (max 252/stat, 510 total) : %s" % mf["EVs"][0])
            if "IVs" in mf:
                if any(int(a) > 31 for a, _ in STAT_RE.findall(mf["IVs"][0])):
                    rep.err(rel, mf["IVs"][1], tid, "IV > 31 : %s" % mf["IVs"][0])
            if "Ability" in mf:
                ab = check_const(rep, consts, "ABILITY", mf["Ability"][0], rel, mf["Ability"][1], tid, "Talent")
                if ab and sp:
                    allowed = sdb.abilities.get(sp)
                    if allowed is None:
                        rep.warn(rel, mf["Ability"][1], tid, "talents de %s non résolus (macro) : vérifier %s à la main" % (sp, ab))
                    elif ab not in allowed:
                        rep.err(rel, mf["Ability"][1], tid, "%s n'a pas le talent %s (autorisés : %s) -> assertf au runtime"
                                % (sp, ab, ", ".join(sorted(allowed))))
            if len(mon.moves) > 4:
                rep.err(rel, ln, tid, "%d capacités (> 4)" % len(mon.moves))
            seen = set()
            for mv_raw, mln in mon.moves:
                mv = check_const(rep, consts, "MOVE", mv_raw, rel, mln, tid, "Capacité")
                if not mv:
                    continue
                if mv in seen:
                    rep.warn(rel, mln, tid, "capacité en double : %s" % mv)
                seen.add(mv)
                if args.learnsets and sp:
                    known, sources, levels = sdb.move_sources(sp, mv)
                    if not known:
                        continue
                    if not sources:
                        rep.warn(rel, mln, tid, "[learnset] %s ne peut pas apprendre %s (ni level-up, oeuf, CT/tuteur, universel)" % (sp, mv))
                    elif args.strict_levels and sources == {"levelup"} and min(levels) > level:
                        rep.warn(rel, mln, tid, "[niveau] %s apprend %s au N.%d (Pokémon N.%d)" % (sp, mv, min(levels), level))


def main():
    ap = argparse.ArgumentParser(description="Validation statique des fichiers .party (expansion 1.16.x)")
    ap.add_argument("-f", "--file", action="append",
                    help="fichier .party (défaut : src/data/trainers.party ; répétable)")
    ap.add_argument("--learnsets", action="store_true", help="vérifier la légalité des capacités (avertissements)")
    ap.add_argument("--strict-levels", action="store_true", help="avec --learnsets : signaler les capacités level-up au-dessus du niveau")
    ap.add_argument("--trainer", action="append", help="limiter à un ou plusieurs TRAINER_*")
    ap.add_argument("--summary", action="store_true", help="n'afficher que le résumé")
    ap.add_argument("--werror", action="store_true", help="les avertissements font échouer")
    ap.add_argument("--json", help="écrire le rapport au format JSON dans ce fichier")
    args = ap.parse_args()

    files = args.file or [rp("src/data/trainers.party")]
    consts = load_constants()
    sdb = SpeciesDB()
    rep = Report()
    n_tr = n_mon = 0
    for fp in files:
        path = fp if os.path.isabs(fp) else os.path.join(os.getcwd(), fp)
        if not os.path.exists(path):
            path = rp(fp)
        trainers = parse_party(path)
        n_tr += len(trainers)
        n_mon += sum(len(t.mons) for t in trainers)
        validate(path, trainers, consts, sdb, args, rep)

    if not args.summary:
        for kind, lst in (("ERREUR", rep.errors), ("AVERT.", rep.warnings)):
            for p, ln, tid, msg in lst:
                print("%s:%d: %s [%s] %s" % (p, ln, kind, tid, msg))
    print("---")
    print("Fichiers : %d | dresseurs : %d | Pokémon : %d | erreurs : %d | avertissements : %d"
          % (len(files), n_tr, n_mon, len(rep.errors), len(rep.warnings)))
    if args.json:
        with open(args.json, "w", encoding="utf-8") as fh:
            json.dump({"errors": rep.errors, "warnings": rep.warnings}, fh, ensure_ascii=False, indent=1)
    if rep.errors or (args.werror and rep.warnings):
        sys.exit(1)


if __name__ == "__main__":
    main()

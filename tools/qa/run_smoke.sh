#!/bin/sh
# Smoke test: new game -> truck -> in-game save -> power cycle -> continue.
# Usage: tools/qa/run_smoke.sh [PROJECT_DIR] [OUTDIR]
#   PROJECT_DIR: built tree containing pokeemeraude.gba / .elf (default: this repo)
#   OUTDIR:      default qa_artifacts/smoke-<date> in this repo
set -e
QA=$(cd "$(dirname "$0")" && pwd)
REPO=$(cd "$QA/../.." && pwd)
PROJ=$(cd "${1:-$REPO}" && pwd)
OUT=${2:-$REPO/qa_artifacts/smoke-$(date +%Y%m%d-%H%M%S)}
GBAPLAY=${GBAPLAY:-$(command -v gbaplay || echo /opt/mgba-tools/bin/gbaplay)}
ROM=${ROM:-$PROJ/pokeemeraude.gba}
ELF=${ELF:-${ROM%.gba}.elf}
mkdir -p "$OUT"
arm-none-eabi-nm "$ELF" > "$OUT/rom.syms"
"$QA/sb_offsets.sh" "$PROJ" > "$OUT/offsets.defs"
rm -f "$OUT/game.sav"
echo "== run 1: new game + save ==" | tee "$OUT/log.txt"
"$GBAPLAY" -q --hang 1800 --syms "$OUT/rom.syms" --defs "$OUT/offsets.defs" -o "$OUT/run1_new_game" -s "$OUT/game.sav" \
    "$ROM" "$QA/scripts/new_game_and_save.txt" > "$OUT/run1.log" 2>&1 && rc1=0 || rc1=$?
cat "$OUT/run1.log" | tee -a "$OUT/log.txt"
echo "== run 2: power cycle + continue ==" | tee -a "$OUT/log.txt"
"$GBAPLAY" -q --hang 1800 --syms "$OUT/rom.syms" --defs "$OUT/offsets.defs" -o "$OUT/run2_continue" -s "$OUT/game.sav" --no-sav-write \
    "$ROM" "$QA/scripts/continue_from_save.txt" > "$OUT/run2.log" 2>&1 && rc2=0 || rc2=$?
cat "$OUT/run2.log" | tee -a "$OUT/log.txt"
echo "artifacts: $OUT"
if [ "$rc1" -eq 0 ] && [ "$rc2" -eq 0 ]; then echo "SMOKE: PASS"; exit 0; fi
echo "SMOKE: FAIL (run1 exit $rc1, run2 exit $rc2)"; exit 1

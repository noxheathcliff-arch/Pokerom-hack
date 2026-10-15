#!/bin/sh
# Compute struct offsets / constants from the project's headers (with the project's
# own compiler flags) and print them as "NAME VALUE" lines usable by gbaplay --defs.
# Usage: tools/qa/sb_offsets.sh [PROJECT_DIR] > qa_artifacts/offsets.defs
# Requires a project where the build was run at least once (generated headers).
set -e
PROJ=${1:-$(cd "$(dirname "$0")/../.." && pwd)}
CC=${ARM_CC:-arm-none-eabi-gcc}
TMP=$(mktemp -d)
trap 'rm -rf "$TMP"' EXIT
cat > "$TMP/off.c" <<'CEOF'
#include "global.h"
#include "main.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "constants/map_groups.h"
#define D(name, val) __asm__ volatile("\n@@DEF " #name " %c0" :: "i"((int)(val)))
void qa_offsets(void)
{
    D(SB1_POS_OFFSET, offsetof(struct SaveBlock1, pos));
    D(SB1_LOCATION_OFFSET, offsetof(struct SaveBlock1, location));
    D(SB1_FLAGS_OFFSET, offsetof(struct SaveBlock1, flags));
    D(SB1_VARS_OFFSET, offsetof(struct SaveBlock1, vars));
    D(SB1_MONEY_OFFSET, offsetof(struct SaveBlock1, money));
    D(SB1_PARTYCOUNT_OFFSET, offsetof(struct SaveBlock1, playerPartyCount));
    D(SB1_PARTY_OFFSET, offsetof(struct SaveBlock1, playerParty));
    D(SB1_SIZE, sizeof(struct SaveBlock1));
    D(SB2_PLAYERNAME_OFFSET, offsetof(struct SaveBlock2, playerName));
    D(SB2_GENDER_OFFSET, offsetof(struct SaveBlock2, playerGender));
    D(SB2_PLAYTIME_HOURS_OFFSET, offsetof(struct SaveBlock2, playTimeHours));
    D(SB2_SIZE, sizeof(struct SaveBlock2));
    D(MAIN_CALLBACK2_OFFSET, offsetof(struct Main, callback2));
    D(MAP_INSIDE_OF_TRUCK_GROUP, MAP_GROUP(MAP_INSIDE_OF_TRUCK));
    D(MAP_INSIDE_OF_TRUCK_NUM, MAP_NUM(MAP_INSIDE_OF_TRUCK));
    D(MAP_ROUTE104_GROUP, MAP_GROUP(MAP_ROUTE104));
    D(MAP_ROUTE104_NUM, MAP_NUM(MAP_ROUTE104));
    D(MAP_LITTLEROOT_TOWN_GROUP, MAP_GROUP(MAP_LITTLEROOT_TOWN));
    D(MAP_LITTLEROOT_TOWN_NUM, MAP_NUM(MAP_LITTLEROOT_TOWN));
    D(FLAG_SYS_POKEMON_GET, FLAG_SYS_POKEMON_GET);
    D(FLAG_BADGE01_GET, FLAG_BADGE01_GET);
    D(VAR_LITTLEROOT_INTRO_STATE, VAR_LITTLEROOT_INTRO_STATE);
}
CEOF
cd "$PROJ"
$CC -S -o "$TMP/off.s" -iquote include -iquote "$PROJ/include" -DMODERN=1 -DTESTING=0 -D${GAME_VERSION:-EMERALD} \
    -std=gnu17 -mthumb -mthumb-interwork -mabi=apcs-gnu -mcpu=arm7tdmi -O1 "$TMP/off.c"
grep -o '@@DEF [A-Za-z0-9_]* -*[0-9]*' "$TMP/off.s" | sed 's/^@@DEF //'

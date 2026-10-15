// Hack: unit tests for the Pokemon Confluence engine helpers (src/confluence.c).
// See docs/hack/ENGINE_CHANGES.md §CF and docs/hack/FLAGS_VARS_REGISTRY.md.
#include "global.h"
#include "caps.h"
#include "confluence.h"
#include "event_data.h"
#include "pokemon.h"
#include "wild_encounter.h"
#include "test/overworld_script.h"
#include "test/test.h"
#include "constants/confluence.h"
#include "constants/maps.h"
#include "constants/map_groups.h"

// setdecision_once refers to VAR_RESULT by name inside the assembler macro.
asm(".set VAR_RESULT, " STR(VAR_RESULT) "\n");

bool8 DoMassOutbreakEncounterTest(void); // wild_encounter.c (no header prototype upstream)

static const u16 sCfVars[] =
{
    VAR_CF_BR, VAR_CF_BL, VAR_CF_FL, VAR_CF_PR, VAR_CF_PE, VAR_CF_AM, VAR_CF_TI, VAR_CF_GI, VAR_CF_HO,
    VAR_CF_REP_L, VAR_CF_REP_C, VAR_CF_REP_M, VAR_CF_REP_A, VAR_CF_REP_I, VAR_CF_REP_G, VAR_CF_REP_P,
    VAR_CF_PA, VAR_CF_RK, VAR_CF_CHAPTER, VAR_CF_ECO, VAR_CF_WORLD, VAR_CF_BVCOUNT, VAR_CF_SUMMIT,
    VAR_CF_CLIMAX, VAR_CF_FIN, VAR_CF_STANCE,
    VAR_CF_D00, VAR_CF_D01, VAR_CF_D02, VAR_CF_D03, VAR_CF_D04, VAR_CF_D05, VAR_CF_D06, VAR_CF_D07,
    VAR_CF_D08, VAR_CF_D09, VAR_CF_D10, VAR_CF_D11, VAR_CF_D12, VAR_CF_D13, VAR_CF_D14, VAR_CF_D15, VAR_CF_D16,
    VAR_CF_CAP,
};

static void SetPlayerMap(u32 map)
{
    gSaveBlock1Ptr->location.mapGroup = MAP_GROUP(map);
    gSaveBlock1Ptr->location.mapNum = MAP_NUM(map);
}

static void ClearCfVars(void)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sCfVars); i++)
        VarSet(sCfVars[i], 0);
}

// ---------------------------------------------------------------------------
// Allocation
// ---------------------------------------------------------------------------

TEST("Confluence allocation: 44 distinct saved vars, none aliased by FRLG code compiled in Emerald")
{
    u32 i, j;
    EXPECT_EQ(ARRAY_COUNT(sCfVars), 44);
    for (i = 0; i < ARRAY_COUNT(sCfVars); i++)
    {
        EXPECT_GT(sCfVars[i], TEMP_VARS_END);
        EXPECT_LE(sCfVars[i], VARS_END);
        EXPECT_NE(sCfVars[i], VAR_DIFFICULTY);
        // Written by shared code through vars_frlg.h aliases (overworld.c, trainer_fan_club.c, hall_of_fame_frlg.inc).
        EXPECT_NE(sCfVars[i], 0x406E);
        EXPECT_NE(sCfVars[i], 0x4073);
        EXPECT_NE(sCfVars[i], 0x4068);
        for (j = i + 1; j < ARRAY_COUNT(sCfVars); j++)
            EXPECT_NE(sCfVars[i], sCfVars[j]);
    }
}

TEST("Confluence allocation: flags are saved, wired to the engine configs, visibility block is 93")
{
    EXPECT_GT(FLAG_CF_EXP_SHARE, TEMP_FLAGS_END);
    EXPECT_EQ(I_EXP_SHARE_FLAG, FLAG_CF_EXP_SHARE);
    EXPECT_EQ(B_FLAG_NO_WHITEOUT, FLAG_CF_NO_WHITEOUT);
    EXPECT_EQ(B_LEVEL_CAP_VARIABLE, VAR_CF_CAP);
    EXPECT_EQ(FLAG_CF_VIS_END - FLAG_CF_VIS_START + 1, 93);
    EXPECT_EQ(FLAG_CF_PLANQUE_RESOLUE, FLAG_CF_M_PLANQUE);
    EXPECT_EQ(FLAG_CF_FONDMER_DONE, FLAG_CF_M_FONDMER);
    EXPECT_LT(FLAG_CF_VIS_END, DAILY_FLAGS_START);
    EXPECT_NE(FLAG_CF_REFUS_BLUE2, FLAG_CF_M_PLANQUE);
    EXPECT_NE(FLAG_CF_DOS_GARDIENNE, FLAG_CF_ALDO_RESPECT);
}

TEST("Confluence new game: starting values (relations 50, Hoopa 20, reps 50, PA/RK 20, cap 14)")
{
    ClearCfVars();
    CF_InitNewGameVars();
    EXPECT_EQ(VarGet(VAR_CF_BR), 50);
    EXPECT_EQ(VarGet(VAR_CF_GI), 50);
    EXPECT_EQ(VarGet(VAR_CF_HO), 20);
    EXPECT_EQ(VarGet(VAR_CF_REP_L), 50);
    EXPECT_EQ(VarGet(VAR_CF_REP_P), 50);
    EXPECT_EQ(VarGet(VAR_CF_PA), 20);
    EXPECT_EQ(VarGet(VAR_CF_RK), 20);
    EXPECT_EQ(VarGet(VAR_CF_CAP), 14);
    EXPECT_EQ(VarGet(VAR_CF_ECO), 0);
    EXPECT_EQ(VarGet(VAR_CF_D16), 0);
    ClearCfVars();
}

// ---------------------------------------------------------------------------
// E-CAP
// ---------------------------------------------------------------------------

TEST("E-CAP: the cap is VAR_CF_CAP, raisecap is monotonic, unset var means no cap")
{
    VarSet(VAR_CF_CAP, 14);
    EXPECT_EQ(GetCurrentLevelCap(), 14);
    RUN_OVERWORLD_SCRIPT(raisecap 18;);
    EXPECT_EQ(VarGet(VAR_CF_CAP), 18);
    EXPECT_EQ(gSpecialVar_Result, 18);
    EXPECT_EQ(GetCurrentLevelCap(), 18);
    RUN_OVERWORLD_SCRIPT(raisecap 10;); // never lowers
    EXPECT_EQ(VarGet(VAR_CF_CAP), 18);
    VarSet(VAR_TEMP_1, 25);
    RUN_OVERWORLD_SCRIPT(raisecap VAR_TEMP_1;); // var argument
    EXPECT_EQ(VarGet(VAR_CF_CAP), 25);
    gSpecialVar_0x8004 = 200; // special form, clamped
    CF_RaiseCap();
    EXPECT_EQ(VarGet(VAR_CF_CAP), MAX_LEVEL);
    VarSet(VAR_CF_CAP, 0);
    EXPECT_EQ(GetCurrentLevelCap(), MAX_LEVEL);
}

// ---------------------------------------------------------------------------
// E-BITS and decisions
// ---------------------------------------------------------------------------

TEST("E-BITS: setbits writes only its field, getbits reads it (macros and specials)")
{
    VarSet(VAR_CF_WORLD, 0xFFFF);
    RUN_OVERWORLD_SCRIPT(setbits VAR_CF_WORLD, 4, 2, 1;);
    EXPECT_EQ(VarGet(VAR_CF_WORLD), 0xFFDF);
    RUN_OVERWORLD_SCRIPT(getbits VAR_CF_WORLD, 4, 2;);
    EXPECT_EQ(gSpecialVar_Result, 1);
    RUN_OVERWORLD_SCRIPT(setbits VAR_CF_WORLD, 10, 4, 0x1F;); // value wider than the field is masked
    EXPECT_EQ(VarGet(VAR_CF_WORLD), 0xFFDF);
    VarSet(VAR_CF_WORLD, 0);
    VarSet(VAR_TEMP_1, 3);
    RUN_OVERWORLD_SCRIPT(setbits VAR_CF_WORLD, 14, 2, VAR_TEMP_1;);
    EXPECT_EQ(VarGet(VAR_CF_WORLD), 0xC000);
    gSpecialVar_0x8004 = VAR_CF_WORLD;
    gSpecialVar_0x8005 = 14;
    gSpecialVar_0x8006 = 2;
    CF_GetBits();
    EXPECT_EQ(gSpecialVar_Result, 3);
    gSpecialVar_0x8005 = 0;
    gSpecialVar_0x8006 = 16;
    gSpecialVar_0x8007 = 0x1234;
    CF_SetBits();
    EXPECT_EQ(VarGet(VAR_CF_WORLD), 0x1234);
    VarSet(VAR_CF_WORLD, 0);
}

TEST("Decisions: D001..D131 map to distinct 2-bit slots, write-once, D001 = D00 b0-1, D131 = D16 b4-5")
{
    u32 n;
    ClearCfVars();
    RUN_OVERWORLD_SCRIPT(setdecision 1, DEC_B;);
    EXPECT_EQ(gSpecialVar_Result, TRUE);
    EXPECT_EQ(VarGet(VAR_CF_D00), 2);
    RUN_OVERWORLD_SCRIPT(setdecision 1, DEC_C;); // already taken: refused, unchanged
    EXPECT_EQ(gSpecialVar_Result, FALSE);
    RUN_OVERWORLD_SCRIPT(checkdecision 1;);
    EXPECT_EQ(gSpecialVar_Result, DEC_B);
    RUN_OVERWORLD_SCRIPT(setdecision 131, DEC_C;);
    EXPECT_EQ(VarGet(VAR_CF_D16), 3 << 4);
    EXPECT_EQ(CF_SetDecision(0, DEC_A), FALSE);
    EXPECT_EQ(CF_SetDecision(132, DEC_A), FALSE);
    EXPECT_EQ(CF_SetDecision(5, 4), FALSE);
    EXPECT_EQ(CF_SetDecision(5, DEC_NONE), FALSE);

    ClearCfVars();
    for (n = 1; n <= CF_DECISION_COUNT; n++)
        EXPECT_EQ(CF_SetDecision(n, (n % 3) + 1), TRUE);
    for (n = 1; n <= CF_DECISION_COUNT; n++)
        EXPECT_EQ(CF_GetDecision(n), (n % 3) + 1);
    ClearCfVars();
}

TEST("Decisions: setdecision_once jumps away when the decision was already taken")
{
    ClearCfVars();
    VarSet(VAR_TEMP_2, 0);
    RUN_OVERWORLD_SCRIPT(
        setdecision_once 27, DEC_A, 2f;
        setvar VAR_TEMP_2, 1;
        end;
    2:
        setvar VAR_TEMP_2, 2;
    );
    EXPECT_EQ(VarGet(VAR_TEMP_2), 1);
    RUN_OVERWORLD_SCRIPT(
        setdecision_once 27, DEC_B, 2f;
        setvar VAR_TEMP_2, 1;
        end;
    2:
        setvar VAR_TEMP_2, 2;
    );
    EXPECT_EQ(VarGet(VAR_TEMP_2), 2);
    EXPECT_EQ(CF_GetDecision(27), DEC_A);
    ClearCfVars();
}

// ---------------------------------------------------------------------------
// E-REPREL
// ---------------------------------------------------------------------------

TEST("E-REPREL: standing = rep - mean(7) + 100; standings sum to ~0")
{
    ClearCfVars();
    CF_InitNewGameVars();
    RUN_OVERWORLD_SCRIPT(repstanding VAR_CF_REP_G;);
    EXPECT_EQ(gSpecialVar_Result, 100);
    VarSet(VAR_CF_REP_G, 64); // sum = 364, mean = 52
    RUN_OVERWORLD_SCRIPT(repstanding VAR_CF_REP_G;);
    EXPECT_EQ(gSpecialVar_Result, 112);
    gSpecialVar_0x8004 = VAR_CF_REP_C;
    CF_RepStanding();
    EXPECT_EQ(gSpecialVar_Result, 98);
    // "Pleasing everyone" does not move standings.
    VarSet(VAR_CF_REP_L, 60); VarSet(VAR_CF_REP_C, 60); VarSet(VAR_CF_REP_M, 60); VarSet(VAR_CF_REP_A, 60);
    VarSet(VAR_CF_REP_I, 60); VarSet(VAR_CF_REP_G, 60); VarSet(VAR_CF_REP_P, 60);
    EXPECT_EQ(CF_GetRepStanding(VAR_CF_REP_G), 0);
    VarSet(VAR_CF_REP_P, 25); // sum = 385, mean = 55
    EXPECT_EQ(CF_GetRepStanding(VAR_CF_REP_P), -30);
    EXPECT_EQ(CF_GetRepStanding(VAR_CF_REP_L), 5);
    ClearCfVars();
}

// ---------------------------------------------------------------------------
// E-REMOVE, E-NATIVE, E-ADAPT
// ---------------------------------------------------------------------------

TEST("E-REMOVE: removepartymon removes a slot and compacts; never removes the last Pokemon")
{
    ZeroPlayerPartyMons();
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_TREECKO, 5;
        givemon SPECIES_PIKACHU, 5;
        givemon SPECIES_WINGULL, 5;
    );
    EXPECT_EQ(CalculatePlayerPartyCount(), 3);
    RUN_OVERWORLD_SCRIPT(removepartymon 1;);
    EXPECT_EQ(gSpecialVar_Result, TRUE);
    EXPECT_EQ(gPlayerPartyCount, 2);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), SPECIES_TREECKO);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][1], MON_DATA_SPECIES), SPECIES_WINGULL);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][2], MON_DATA_SPECIES), SPECIES_NONE);
    RUN_OVERWORLD_SCRIPT(removepartymon 4;); // empty slot
    EXPECT_EQ(gSpecialVar_Result, FALSE);
    EXPECT_EQ(CF_RemovePartyMon(0), TRUE);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), SPECIES_WINGULL);
    EXPECT_EQ(CF_RemovePartyMon(0), FALSE); // last one
    EXPECT_EQ(gPlayerPartyCount, 1);
    ZeroPlayerPartyMons();
}

TEST("E-CLEARPARTY: clearparty empties the whole party")
{
    ZeroPlayerPartyMons();
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_TREECKO, 60;
        givemon SPECIES_PIKACHU, 60;
    );
    EXPECT_EQ(CalculatePlayerPartyCount(), 2);
    RUN_OVERWORLD_SCRIPT(clearparty;);
    EXPECT_EQ(gPlayerPartyCount, 0);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), SPECIES_NONE);
    EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][1], MON_DATA_SPECIES), SPECIES_NONE);
}

TEST("E-NATIVE: Hoenn dex species are native, other regions and foreign regional forms are not")
{
    RUN_OVERWORLD_SCRIPT(ishoennnative SPECIES_SKITTY;);
    EXPECT_EQ(gSpecialVar_Result, TRUE);
    RUN_OVERWORLD_SCRIPT(ishoennnative SPECIES_BULBASAUR;);
    EXPECT_EQ(gSpecialVar_Result, FALSE);
    EXPECT_EQ(CF_IsHoennNative(SPECIES_ZIGZAGOON), TRUE);
    EXPECT_EQ(CF_IsHoennNative(SPECIES_ZIGZAGOON_GALAR), FALSE);
    EXPECT_EQ(CF_IsHoennNative(SPECIES_PIKACHU), TRUE); // in the Hoenn dex
    EXPECT_EQ(CF_IsHoennNative(SPECIES_SKWOVET), FALSE);
    EXPECT_EQ(CF_IsHoennNative(SPECIES_NONE), FALSE);
}

TEST("E-ADAPT: +2 type 1, +1 type 2 per usable Pokemon; tie goes to the lead's type 1")
{
    ZeroPlayerPartyMons();
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_CHARMANDER, 10;
        givemon SPECIES_BULBASAUR, 10;
    );
    // Fire 2, Grass 2, Poison 1: tie -> lead (Charmander) -> Fire, package B.
    RUN_OVERWORLD_SCRIPT(getdominanttype;);
    EXPECT_EQ(gSpecialVar_Result, TYPE_FIRE);
    EXPECT_EQ(gSpecialVar_0x8000, 2);
    RUN_OVERWORLD_SCRIPT(givemon SPECIES_ODDISH, 10;);
    // Grass 4 wins; package A.
    EXPECT_EQ(CF_GetDominantPartyType(), TYPE_GRASS);
    EXPECT_EQ(CF_GetAdaptPackage(TYPE_GRASS), 1);
    // Fainted Pokemon do not count.
    SetMonData(&gParties[B_TRAINER_PLAYER][1], MON_DATA_HP, &(u16){0});
    SetMonData(&gParties[B_TRAINER_PLAYER][2], MON_DATA_HP, &(u16){0});
    EXPECT_EQ(CF_GetDominantPartyType(), TYPE_FIRE);
    EXPECT_EQ(CF_GetAdaptPackage(TYPE_WATER), 3);
    ZeroPlayerPartyMons();
    EXPECT_EQ(CF_GetDominantPartyType(), TYPE_NONE);
}

// ---------------------------------------------------------------------------
// E-ECO, E-TOD
// ---------------------------------------------------------------------------

TEST("E-ECO: Route 116 (Z-02) picks its _Mixte header with zone state MIXTE; others unaffected")
{
    u16 base;
    VarSet(VAR_CF_ECO, 0);
    SetPlayerMap(MAP_ROUTE116);
    base = GetCurrentMapWildMonHeaderId();
    EXPECT_NE(base, HEADER_NONE);
    EXPECT_EQ(CF_GetEcoZone(MAP_GROUP(MAP_ROUTE116), MAP_NUM(MAP_ROUTE116)), ECO_Z02);

    RUN_OVERWORLD_SCRIPT(setbits VAR_CF_ECO, 2, 2, ECO_MIXTE;); // Z-02 = bits 2-3
    EXPECT_EQ(GetCurrentMapWildMonHeaderId(), base + 1);
    EXPECT_EQ(gWildMonHeaders[base + 1].mapGroup, MAP_GROUP(MAP_ROUTE116));
    EXPECT_EQ(gWildMonHeaders[base + 1].mapNum, MAP_NUM(MAP_ROUTE116));
    EXPECT_NE(gWildMonHeaders[base + 1].encounterTypes[OW_TIME_OF_DAY_FALLBACK].landMonsInfo,
              gWildMonHeaders[base].encounterTypes[OW_TIME_OF_DAY_FALLBACK].landMonsInfo);

    CF_WriteBits(VAR_CF_ECO, 2, 2, ECO_ABATTU); // 4th table (_Abattu)
    EXPECT_EQ(GetCurrentMapWildMonHeaderId(), base + 3);

    CF_WriteBits(VAR_CF_ECO, 2, 2, ECO_ENVAHI);
    CF_WriteBits(VAR_CF_ECO, 0, 2, ECO_MIXTE); // another zone (Z-01) does not change Route 116
    EXPECT_EQ(GetCurrentMapWildMonHeaderId(), base);

    SetPlayerMap(MAP_ROUTE101); // single-header zone map ignores the state
    base = GetCurrentMapWildMonHeaderId();
    EXPECT_EQ(gWildMonHeaders[base].mapNum, MAP_NUM(MAP_ROUTE101));
    VarSet(VAR_CF_ECO, 0);
    EXPECT_EQ(GetCurrentMapWildMonHeaderId(), base);
}

TEST("E-ECO: no map has more than 4 consecutive headers (Altering Cave excepted)")
{
    u32 i, count = 1;
    for (i = 1; gWildMonHeaders[i - 1].mapGroup != MAP_GROUP(MAP_UNDEFINED); i++)
    {
        if (gWildMonHeaders[i].mapGroup == gWildMonHeaders[i - 1].mapGroup
         && gWildMonHeaders[i].mapNum == gWildMonHeaders[i - 1].mapNum)
        {
            count++;
            if (!(gWildMonHeaders[i].mapGroup == MAP_GROUP(MAP_ALTERING_CAVE) && gWildMonHeaders[i].mapNum == MAP_NUM(MAP_ALTERING_CAVE)))
                EXPECT_LE(count, 4);
        }
        else
        {
            count = 1;
        }
    }
}

TEST("E-TOD: time-of-day encounters are enabled (night tables are optional per map)")
{
    EXPECT_EQ(OW_TIME_OF_DAY_ENCOUNTERS, TRUE);
    EXPECT_EQ(OW_TIME_OF_DAY_DISABLE_FALLBACK, FALSE);
}

// ---------------------------------------------------------------------------
// E-OUT
// ---------------------------------------------------------------------------

TEST("E-OUT: setringoutbreak sets a persistent outbreak with level-up moves; clear ends it")
{
    u32 i;
    EXPECT_EQ(OW_RANDOM_TV_OUTBREAKS, FALSE);
    SetPlayerMap(MAP_ROUTE116);
    RUN_OVERWORLD_SCRIPT(setringoutbreak SPECIES_SKITTY, MAP_ROUTE116, 12, 100;);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonSpecies, SPECIES_SKITTY);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonLevel, 12);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakDaysLeft, CF_OUTBREAK_UNTIL_CLEARED);
    EXPECT_NE(gSaveBlock1Ptr->outbreakPokemonMoves[0], MOVE_NONE);
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        u32 j;
        const struct LevelUpMove *learnset = GetSpeciesLevelUpLearnset(SPECIES_SKITTY);
        bool32 found = (gSaveBlock1Ptr->outbreakPokemonMoves[i] == MOVE_NONE);
        for (j = 0; !found && learnset[j].move != LEVEL_UP_MOVE_END && learnset[j].level <= 12; j++)
            found = (learnset[j].move == gSaveBlock1Ptr->outbreakPokemonMoves[i]);
        EXPECT(found);
    }
    EXPECT_EQ(DoMassOutbreakEncounterTest(), TRUE);
    SetPlayerMap(MAP_ROUTE101);
    EXPECT_EQ(DoMassOutbreakEncounterTest(), FALSE);

    RUN_OVERWORLD_SCRIPT(setringoutbreak SPECIES_ZIGZAGOON, MAP_ROUTE101, 5, 40, 3, MOVE_TACKLE, MOVE_GROWL;);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonMoves[0], MOVE_TACKLE);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonMoves[1], MOVE_GROWL);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonMoves[2], MOVE_NONE);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakDaysLeft, 3);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonProbability, 40);

    RUN_OVERWORLD_SCRIPT(clearringoutbreak;);
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonSpecies, SPECIES_NONE);
    EXPECT_EQ(DoMassOutbreakEncounterTest(), FALSE);

    gSpecialVar_0x8004 = SPECIES_WINGULL; // special form
    gSpecialVar_0x8005 = MAP_ROUTE101;
    gSpecialVar_0x8006 = 7;
    gSpecialVar_0x8007 = 30;
    SetRingOutbreak();
    EXPECT_EQ(gSaveBlock1Ptr->outbreakLocationMapNum, MAP_NUM(MAP_ROUTE101));
    EXPECT_EQ(gSaveBlock1Ptr->outbreakLocationMapGroup, MAP_GROUP(MAP_ROUTE101));
    ClearRingOutbreak();
    EXPECT_EQ(gSaveBlock1Ptr->outbreakPokemonSpecies, SPECIES_NONE);
}

// ---------------------------------------------------------------------------
// E-LEDGER
// ---------------------------------------------------------------------------

TEST("SPAWN: the demo new game starts on Route 104")
{
    EXPECT_EQ(CF_SPAWN_X, 15);
    EXPECT_EQ(CF_SPAWN_Y, 57);
}

TEST("E-LEDGER: 128 static-encounter bits in SaveBlock3")
{
    u32 i;
    EXPECT_EQ(sizeof(gSaveBlock3Ptr->cfStaticLedger), CF_LEDGER_BYTES);
    for (i = 0; i < CF_LEDGER_BITS; i++)
        CF_LedgerSet(i, FALSE);
    RUN_OVERWORLD_SCRIPT(setledger 0; setledger 127;);
    EXPECT_EQ(CF_LedgerGet(0), TRUE);
    EXPECT_EQ(CF_LedgerGet(1), FALSE);
    EXPECT_EQ(CF_LedgerGet(127), TRUE);
    RUN_OVERWORLD_SCRIPT(checkledger 127;);
    EXPECT_EQ(gSpecialVar_Result, TRUE);
    RUN_OVERWORLD_SCRIPT(setledger 127, FALSE;);
    EXPECT_EQ(CF_LedgerGet(127), FALSE);
    CF_LedgerSet(128, TRUE); // out of range: ignored
    EXPECT_EQ(CF_LedgerGet(128), FALSE);
    gSpecialVar_0x8004 = 42;
    LedgerSet();
    LedgerGet();
    EXPECT_EQ(gSpecialVar_Result, TRUE);
    EXPECT_EQ(gSaveBlock3Ptr->cfStaticLedger[5], 1 << 2);
    for (i = 0; i < CF_LEDGER_BITS; i++)
        CF_LedgerSet(i, FALSE);
}

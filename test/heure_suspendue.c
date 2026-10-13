// Heure Suspendue: engine hooks specific to the hack (see docs/hack/ENGINE_CHANGES.md).
#include "global.h"
#include "caps.h"
#include "data.h"
#include "event_data.h"
#include "international_string_util.h"
#include "string_util.h"
#include "wild_encounter.h"
#include "constants/maps.h"
#include "constants/map_groups.h"
#include "constants/metatile_behaviors.h"
#include "test/test.h"

static void SetPlayerMap(u32 map)
{
    gSaveBlock1Ptr->location.mapGroup = MAP_GROUP(map);
    gSaveBlock1Ptr->location.mapNum = MAP_NUM(map);
}

// ---------------------------------------------------------------------------
// N1 - Figement: no wild encounters while FLAG_FIGEMENT_ACTIF is set
// ---------------------------------------------------------------------------

TEST("Figement: FLAG_FIGEMENT_ACTIF is a saved story flag")
{
    EXPECT_EQ(FLAG_FIGEMENT_ACTIF, 0x20);
    EXPECT_GT(FLAG_FIGEMENT_ACTIF, TEMP_FLAGS_END);
}

TEST("Figement: fishing finds no Pokemon while the flag is set (positive control without it)")
{
    SetPlayerMap(MAP_ROUTE114); // has land, water, rock smash and fishing tables
    FlagClear(FLAG_FIGEMENT_ACTIF);
    EXPECT_NE(GetCurrentMapWildMonHeaderId(), HEADER_NONE);
    EXPECT_EQ(DoesCurrentMapHaveFishingMons(), TRUE);
    EXPECT_EQ(AreWildEncountersFrozenByFigement(), FALSE);

    FlagSet(FLAG_FIGEMENT_ACTIF);
    EXPECT_EQ(AreWildEncountersFrozenByFigement(), TRUE);
    EXPECT_EQ(DoesCurrentMapHaveFishingMons(), FALSE);
    FlagClear(FLAG_FIGEMENT_ACTIF);
}

TEST("Figement: no grass or surf encounter while the flag is set")
{
    u32 i;
    SetPlayerMap(MAP_ROUTE114);
    FlagSet(FLAG_FIGEMENT_ACTIF);
    for (i = 0; i < 2000; i++)
    {
        EXPECT_EQ(StandardWildEncounter(MB_TALL_GRASS, MB_TALL_GRASS), FALSE);
        EXPECT_EQ(StandardWildEncounter(MB_DEEP_WATER, MB_DEEP_WATER), FALSE);
        EXPECT_EQ(StandardWildEncounter(MB_TALL_GRASS, MB_NORMAL), FALSE);
    }
    FlagClear(FLAG_FIGEMENT_ACTIF);
}

TEST("Figement: Rock Smash and Sweet Scent / Honey find nothing while the flag is set")
{
    u32 i;
    SetPlayerMap(MAP_ROUTE114);
    FlagSet(FLAG_FIGEMENT_ACTIF);
    for (i = 0; i < 500; i++)
    {
        gSpecialVar_Result = 0xFFFF;
        RockSmashWildEncounter();
        EXPECT_EQ(gSpecialVar_Result, FALSE);
        EXPECT_EQ(SweetScentWildEncounter(), FALSE); // Honey uses the same Sweet Scent effect
    }
    FlagClear(FLAG_FIGEMENT_ACTIF);
}

TEST("Figement: the flag is cleared on every map load (ClearTempFieldEventData)")
{
    FlagSet(FLAG_FIGEMENT_ACTIF);
    ClearTempFieldEventData();
    EXPECT_EQ(FlagGet(FLAG_FIGEMENT_ACTIF), FALSE);
    EXPECT_EQ(AreWildEncountersFrozenByFigement(), FALSE);
}

// ---------------------------------------------------------------------------
// H1 - soft level caps keyed on badges
// ---------------------------------------------------------------------------

TEST("Level cap: badge table 15/19/24/29/33/38/44/50/58 then 100 after the champion")
{
    static const u16 badges[] = {
        FLAG_BADGE01_GET, FLAG_BADGE02_GET, FLAG_BADGE03_GET, FLAG_BADGE04_GET,
        FLAG_BADGE05_GET, FLAG_BADGE06_GET, FLAG_BADGE07_GET, FLAG_BADGE08_GET,
        FLAG_IS_CHAMPION,
    };
    static const u8 caps[] = {15, 19, 24, 29, 33, 38, 44, 50, 58, MAX_LEVEL};
    u32 i;

    ASSUME(B_EXP_CAP_TYPE == EXP_CAP_SOFT);
    ASSUME(B_LEVEL_CAP_TYPE == LEVEL_CAP_FLAG_LIST);

    for (i = 0; i < ARRAY_COUNT(badges); i++)
        FlagClear(badges[i]);
    for (i = 0; i < ARRAY_COUNT(badges); i++)
    {
        EXPECT_EQ(GetCurrentLevelCap(), caps[i]);
        FlagSet(badges[i]);
    }
    EXPECT_EQ(GetCurrentLevelCap(), caps[ARRAY_COUNT(badges)]);
    for (i = 0; i < ARRAY_COUNT(badges); i++)
        FlagClear(badges[i]);
}

TEST("Level cap: soft cap reduces exp above the cap and boosts it below")
{
    u32 i;
    for (i = 0; i < 8; i++)
        FlagClear(FLAG_BADGE01_GET + i);
    FlagClear(FLAG_IS_CHAMPION);
    // Cap = 15 with no badge.
    EXPECT_EQ(GetSoftLevelCapExpValue(15, 640), 640 / 4);
    EXPECT_EQ(GetSoftLevelCapExpValue(16, 640), 640 / 8);
    EXPECT_EQ(GetSoftLevelCapExpValue(30, 640), 640 / 64);
    EXPECT_GT(GetSoftLevelCapExpValue(10, 640), 640); // B_LEVEL_CAP_EXP_UP
}

// ---------------------------------------------------------------------------
// N2 - repurposed trainer classes
// ---------------------------------------------------------------------------

TEST("Trainer classes: repurposed Aqua/Magma classes have the Heure Suspendue names")
{
    EXPECT_EQ(StringCompare(gTrainerClasses[TRAINER_CLASS_CARILLONNEUR].name, COMPOUND_STRING("CARILLONNEUR")), 0);
    EXPECT_EQ(StringCompare(gTrainerClasses[TRAINER_CLASS_VEILLEUR].name, COMPOUND_STRING("VEILLEUR")), 0);
    EXPECT_EQ(StringCompare(gTrainerClasses[TRAINER_CLASS_SONNEUR].name, COMPOUND_STRING("SONNEUR")), 0);
    EXPECT_EQ(StringCompare(gTrainerClasses[TRAINER_CLASS_SONNEUSE].name, COMPOUND_STRING("SONNEUSE")), 0);
    EXPECT_EQ(StringLength(gTrainerClasses[TRAINER_CLASS_CARILLONNEUR].name), 12);
}

TEST("Trainer classes: feminine forms")
{
    EXPECT_EQ(StringCompare(GetTrainerClassNameGenderSpecific(TRAINER_CLASS_CARILLONNEUR, 1, NULL), COMPOUND_STRING("CARILLONNEUSE")), 0);
    EXPECT_EQ(StringCompare(GetTrainerClassNameGenderSpecific(TRAINER_CLASS_CARILLONNEUR, 0, NULL), COMPOUND_STRING("CARILLONNEUR")), 0);
    EXPECT_EQ(StringCompare(GetTrainerClassNameGenderSpecific(TRAINER_CLASS_SONNEUR, 1, NULL), COMPOUND_STRING("SONNEUSE")), 0);
    EXPECT_EQ(StringCompare(GetTrainerClassNameGenderSpecific(TRAINER_CLASS_VEILLEUR, 1, NULL), COMPOUND_STRING("VEILLEUSE")), 0);
    EXPECT_EQ(StringCompare(GetTrainerClassNameGenderSpecific(TRAINER_CLASS_VEILLEUR, 0, NULL), COMPOUND_STRING("VEILLEUR")), 0);
}

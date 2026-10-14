// Project engine hooks (see docs/hack/ENGINE_CHANGES.md).
#include "global.h"
#include "battle_setup.h"
#include "caps.h"
#include "trainer_see.h"
#include "constants/battle_setup.h"
#include "constants/party_menu.h"
#include "data.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "pokemon.h"
#include "trainer.h"
#include "constants/event_objects.h"
#include "string_util.h"
#include "script_affinity.h"
#include "wild_encounter.h"
#include "test/overworld_script.h"
#include "constants/maps.h"
#include "constants/map_groups.h"
#include "test/test.h"

void RockSmashWildEncounter(void); // special, no header prototype upstream

static void SetPlayerMap(u32 map)
{
    gSaveBlock1Ptr->location.mapGroup = MAP_GROUP(map);
    gSaveBlock1Ptr->location.mapNum = MAP_NUM(map);
}

// ---------------------------------------------------------------------------
// No wild encounters while FLAG_NO_WILD_ENCOUNTERS (= WE_FLAG_NO_ENCOUNTER) is set
// ---------------------------------------------------------------------------

TEST("No-encounter flag: WE_FLAG_NO_ENCOUNTER is the saved flag FLAG_NO_WILD_ENCOUNTERS")
{
    // Grass/water step encounters are blocked upstream in field_control_avatar.c
    // (ShouldDisableRandomEncounters, static) and overworld encounters in
    // wild_encounter_ow.c, both via FlagGet(WE_FLAG_NO_ENCOUNTER).
    EXPECT_EQ(WE_FLAG_NO_ENCOUNTER, FLAG_NO_WILD_ENCOUNTERS);
    EXPECT_GT(FLAG_NO_WILD_ENCOUNTERS, TEMP_FLAGS_END);
}

TEST("No-encounter flag: fishing finds nothing while set (positive control without it)")
{
    SetPlayerMap(MAP_ROUTE114); // has land, water, rock smash and fishing tables
    FlagClear(FLAG_NO_WILD_ENCOUNTERS);
    EXPECT_NE(GetCurrentMapWildMonHeaderId(), HEADER_NONE);
    EXPECT_EQ(DoesCurrentMapHaveFishingMons(), TRUE);
    EXPECT_EQ(IsWildEncounterFlagSet(), FALSE);

    FlagSet(FLAG_NO_WILD_ENCOUNTERS);
    EXPECT_EQ(IsWildEncounterFlagSet(), TRUE);
    EXPECT_EQ(DoesCurrentMapHaveFishingMons(), FALSE);
    FlagClear(FLAG_NO_WILD_ENCOUNTERS);
}

TEST("No-encounter flag: Rock Smash and Sweet Scent / Honey find nothing while set")
{
    u32 i;
    SetPlayerMap(MAP_ROUTE114);
    FlagSet(FLAG_NO_WILD_ENCOUNTERS);
    for (i = 0; i < 500; i++)
    {
        gSpecialVar_Result = 0xFFFF;
        RockSmashWildEncounter();
        EXPECT_EQ(gSpecialVar_Result, FALSE);
        EXPECT_EQ(SweetScentWildEncounter(), FALSE); // Honey uses the same Sweet Scent effect
    }
    FlagClear(FLAG_NO_WILD_ENCOUNTERS);
}

// ---------------------------------------------------------------------------
// Soft level caps (values are placeholders: only the structure is tested)
// ---------------------------------------------------------------------------

TEST("Level cap: non-decreasing along the badge flags, MAX_LEVEL after the champion")
{
    static const u16 milestones[] = {
        FLAG_BADGE01_GET, FLAG_BADGE02_GET, FLAG_BADGE03_GET, FLAG_BADGE04_GET,
        FLAG_BADGE05_GET, FLAG_BADGE06_GET, FLAG_BADGE07_GET, FLAG_BADGE08_GET,
        FLAG_IS_CHAMPION,
    };
    u32 i, prev;

    ASSUME(B_LEVEL_CAP_TYPE == LEVEL_CAP_FLAG_LIST);

    for (i = 0; i < ARRAY_COUNT(milestones); i++)
        FlagClear(milestones[i]);
    prev = GetCurrentLevelCap();
    EXPECT_LT(prev, MAX_LEVEL);
    for (i = 0; i < ARRAY_COUNT(milestones); i++)
    {
        FlagSet(milestones[i]);
        EXPECT_GE(GetCurrentLevelCap(), prev);
        prev = GetCurrentLevelCap();
    }
    EXPECT_EQ(prev, MAX_LEVEL);
    for (i = 0; i < ARRAY_COUNT(milestones); i++)
        FlagClear(milestones[i]);
}

TEST("Level cap: soft cap reduces exp at/above the cap and boosts it below")
{
    u32 i, cap;
    ASSUME(B_EXP_CAP_TYPE == EXP_CAP_SOFT); // forced to EXP_CAP_NONE in config/test.h: skipped by make check
    for (i = 0; i < 8; i++)
        FlagClear(FLAG_BADGE01_GET + i);
    FlagClear(FLAG_IS_CHAMPION);
    cap = GetCurrentLevelCap();
    EXPECT_EQ(GetSoftLevelCapExpValue(cap, 640), 640 / 4);
    EXPECT_EQ(GetSoftLevelCapExpValue(cap + 1, 640), 640 / 8);
    EXPECT_EQ(GetSoftLevelCapExpValue(cap + 10, 640), 640 / 64);
    EXPECT_GT(GetSoftLevelCapExpValue(cap - 1, 640), 640); // B_LEVEL_CAP_EXP_UP
}

// ---------------------------------------------------------------------------
// Trainer class names: buffer is 12 characters + EOS
// ---------------------------------------------------------------------------

TEST("Trainer classes: every class name fits in 12 characters")
{
    u32 i;
    EXPECT_EQ(sizeof(gTrainerClasses[0].name), 13);
    for (i = 0; i < TRAINER_CLASS_COUNT; i++)
        EXPECT_LE(StringLength(gTrainerClasses[i].name), 12);
}

// ---------------------------------------------------------------------------
// Kanto player avatar (OW_KANTO_PLAYER_AVATAR) and Kanto NPC sprites in Emerald
// ---------------------------------------------------------------------------

TEST("Kanto avatar: the player uses Red / Green overworld sprites and Red / Leaf trainer pics")
{
    ASSUME(OW_KANTO_PLAYER_AVATAR == TRUE);
    EXPECT_EQ(GetPlayerAvatarGraphicsIdByStateIdAndGender(PLAYER_AVATAR_STATE_NORMAL, MALE), OBJ_EVENT_GFX_RED_NORMAL);
    EXPECT_EQ(GetPlayerAvatarGraphicsIdByStateIdAndGender(PLAYER_AVATAR_STATE_SURFING, MALE), OBJ_EVENT_GFX_RED_SURF);
    EXPECT_EQ(GetPlayerAvatarGraphicsIdByStateIdAndGender(PLAYER_AVATAR_STATE_MACH_BIKE, MALE), OBJ_EVENT_GFX_RED_BIKE);
    EXPECT_EQ(GetPlayerAvatarGraphicsIdByStateIdAndGender(PLAYER_AVATAR_STATE_NORMAL, FEMALE), OBJ_EVENT_GFX_GREEN_NORMAL);
    EXPECT_EQ(GetPlayerTrainerPic(MALE, VERSION_EMERALD), TRAINER_PIC_RED);
    EXPECT_EQ(GetPlayerTrainerPic(FEMALE, VERSION_EMERALD), TRAINER_PIC_LEAF);
    EXPECT_EQ(PlayerGenderToFrontTrainerPicId(MALE), TRAINER_PIC_RED);
}

TEST("Kanto NPCs: overworld graphics are built in Emerald")
{
    static const u16 gfx[] = {
        OBJ_EVENT_GFX_RED_NORMAL, OBJ_EVENT_GFX_RED_BIKE, OBJ_EVENT_GFX_RED_SURF, OBJ_EVENT_GFX_RED_FIELD_MOVE,
        OBJ_EVENT_GFX_RED_FISH, OBJ_EVENT_GFX_RED_VS_SEEKER, OBJ_EVENT_GFX_GREEN_NORMAL,
        OBJ_EVENT_GFX_BLUE, OBJ_EVENT_GFX_GIOVANNI, OBJ_EVENT_GFX_PROF_OAK, OBJ_EVENT_GFX_BROCK,
        OBJ_EVENT_GFX_MISTY, OBJ_EVENT_GFX_LT_SURGE, OBJ_EVENT_GFX_ERIKA, OBJ_EVENT_GFX_KOGA,
        OBJ_EVENT_GFX_SABRINA, OBJ_EVENT_GFX_BLAINE, OBJ_EVENT_GFX_LORELEI, OBJ_EVENT_GFX_BRUNO,
        OBJ_EVENT_GFX_AGATHA, OBJ_EVENT_GFX_LANCE, OBJ_EVENT_GFX_ROCKET_M, OBJ_EVENT_GFX_ROCKET_F,
        OBJ_EVENT_GFX_BILL, OBJ_EVENT_GFX_MR_FUJI, OBJ_EVENT_GFX_CELIO, OBJ_EVENT_GFX_DAISY,
    };
    u32 i;
    for (i = 0; i < ARRAY_COUNT(gfx); i++)
    {
        const struct ObjectEventGraphicsInfo *info = GetObjectEventGraphicsInfo(gfx[i]);
        EXPECT(info != NULL);
        EXPECT(info->images != NULL);
    }
}

// ---------------------------------------------------------------------------
// Declinable trainer battles (trainerbattle_single_declinable)
// ---------------------------------------------------------------------------

TEST("Declinable battles: only trainers flagged TRAINER_BATTLE_DECLINABLE can be refused")
{
    ASSUME(B_DECLINABLE_TRAINER_BATTLES == TRUE);
    InitTrainerBattleParameter();
    gNoOfApproachingTrainers = 1;
    TRAINER_BATTLE_PARAM.mode = TRAINER_BATTLE_SINGLE;
    EXPECT_EQ(IsTrainerBattleDeclinable(), FALSE);
    TRAINER_BATTLE_PARAM.rivalBattleFlags = TRAINER_BATTLE_DECLINABLE;
    EXPECT_EQ(IsTrainerBattleDeclinable(), TRUE);
    gNoOfApproachingTrainers = 2; // two trainers at once: mandatory
    EXPECT_EQ(IsTrainerBattleDeclinable(), FALSE);
    gNoOfApproachingTrainers = 0;
    InitTrainerBattleParameter();
}

TEST("Declinable battles: a refused trainer is remembered until the next map load")
{
    ClearDeclinedTrainerBattles();
    gSpecialVar_LastTalked = 5;
    RecordDeclinedTrainerBattle();
    EXPECT_EQ(HasTrainerBattleBeenDeclined(5), TRUE);
    EXPECT_EQ(HasTrainerBattleBeenDeclined(6), FALSE);
    gSpecialVar_LastTalked = 40;
    RecordDeclinedTrainerBattle();
    EXPECT_EQ(HasTrainerBattleBeenDeclined(40), TRUE);
    ClearTempFieldEventData();
    EXPECT_EQ(HasTrainerBattleBeenDeclined(5), FALSE);
    EXPECT_EQ(HasTrainerBattleBeenDeclined(40), FALSE);
}

// ---------------------------------------------------------------------------
// Affinity / reputation helpers (addaffinity / subaffinity)
// ---------------------------------------------------------------------------

TEST("Affinity: addaffinity / subaffinity clamp to the range")
{
    VarSet(VAR_TEMP_0, 95);
    RUN_OVERWORLD_SCRIPT(addaffinity VAR_TEMP_0, 10;);
    EXPECT_EQ(VarGet(VAR_TEMP_0), 100);
    EXPECT_EQ(gSpecialVar_Result, 100);
    RUN_OVERWORLD_SCRIPT(subaffinity VAR_TEMP_0, 30;);
    EXPECT_EQ(VarGet(VAR_TEMP_0), 70);
    RUN_OVERWORLD_SCRIPT(subaffinity VAR_TEMP_0, 200;);
    EXPECT_EQ(VarGet(VAR_TEMP_0), 0);
    RUN_OVERWORLD_SCRIPT(addaffinity VAR_TEMP_0, 7, 0, 5;);
    EXPECT_EQ(VarGet(VAR_TEMP_0), 5);
    EXPECT_EQ(AddAffinityClamped(VAR_TEMP_0, -1, 0, 100), 4);
}


// ---------------------------------------------------------------------------
// Choose the lead Pokemon (B_FLAG_CHOOSE_BATTLE_LEAD)
// ---------------------------------------------------------------------------

TEST("Choose lead: the selection is offered only with the flag and 2+ usable Pokemon, and used once")
{
    ZeroPlayerPartyMons();
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_WOBBUFFET, 10;
        givemon SPECIES_WYNAUT, 10;
    );
    FlagClear(FLAG_CHOOSE_BATTLE_LEAD);
    EXPECT_EQ(ShouldChooseBattleLead(), FALSE);
    FlagSet(FLAG_CHOOSE_BATTLE_LEAD);
    EXPECT_EQ(ShouldChooseBattleLead(), TRUE);

    gSpecialVar_0x8004 = 1;
    SetBattleLeadFromSelection();
    EXPECT_EQ(ConsumeChosenBattleLead(), 1);
    EXPECT_EQ(ConsumeChosenBattleLead(), PARTY_SIZE); // consumed

    gSpecialVar_0x8004 = PARTY_NOTHING_CHOSEN; // B pressed
    SetBattleLeadFromSelection();
    EXPECT_EQ(ConsumeChosenBattleLead(), PARTY_SIZE);
    FlagClear(FLAG_CHOOSE_BATTLE_LEAD);
}

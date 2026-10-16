// Project engine hooks (see docs/hack/ENGINE_CHANGES.md).
#include "global.h"
#include "battle_setup.h"
#include "caps.h"
#include "trainer_see.h"
#include "constants/battle_setup.h"
#include "constants/party_menu.h"
#include "battle_main.h"
#include "confluence.h"
#include "constants/battle_ai.h"
#include "data.h"
#include "malloc.h"
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

TEST("Level cap: Confluence uses the variable cap VAR_CF_CAP (E-CAP)")
{
    // Milestone caps are raised by script (raisecap); see test/hack_confluence.c.
    EXPECT_EQ(B_LEVEL_CAP_TYPE, LEVEL_CAP_VARIABLE);
    EXPECT_EQ(B_LEVEL_CAP_VARIABLE, VAR_CF_CAP);
}

TEST("Level cap: soft cap reduces exp at/above the cap and boosts it below")
{
    u32 cap;
    ASSUME(B_EXP_CAP_TYPE == EXP_CAP_SOFT); // forced to EXP_CAP_NONE in config/test.h: skipped by make check
    VarSet(VAR_CF_CAP, 14);
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

TEST("Declinable battles: the declined flag makes the refusal final (no sight, no re-ask)")
{
    u8 script[1 + sizeof(TrainerBattleParameter)];
    TrainerBattleParameter *param = (TrainerBattleParameter *)&script[1];

    memset(script, 0, sizeof(script));
    param->params.mode = TRAINER_BATTLE_SINGLE;
    param->params.rivalBattleFlags = TRAINER_BATTLE_DECLINABLE;
    param->params.defeatTextB = (u8 *)FLAG_TEMP_1; // declined_flag argument
    FlagClear(FLAG_TEMP_1);
    EXPECT_EQ(IsTrainerBattleDeclinedFromScriptPointer(script), FALSE);
    FlagSet(FLAG_TEMP_1);
    EXPECT_EQ(IsTrainerBattleDeclinedFromScriptPointer(script), TRUE);

    TrainerBattleLoadArgs(&script[1]);
    gNoOfApproachingTrainers = 0;
    EXPECT_EQ(IsTrainerBattleAlreadyDeclined(), TRUE);
    FlagClear(FLAG_TEMP_1);
    EXPECT_EQ(IsTrainerBattleAlreadyDeclined(), FALSE);

    param->params.rivalBattleFlags = 0; // ordinary (mandatory) battle: flag argument ignored
    FlagSet(FLAG_TEMP_1);
    EXPECT_EQ(IsTrainerBattleDeclinedFromScriptPointer(script), FALSE);
    FlagClear(FLAG_TEMP_1);
    InitTrainerBattleParameter();
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

// ---------------------------------------------------------------------------
// CF-14: wild Pokemon genders follow the species ratio
// ---------------------------------------------------------------------------

TEST("Wild genders: Route 104 grass gives both genders with a non-Cute Charm lead")
{
    u32 i, males = 0, females = 0;
    ZeroPlayerPartyMons();
    RUN_OVERWORLD_SCRIPT(
        givemon SPECIES_TREECKO, 5;
        givemon SPECIES_ZIGZAGOON_GALAR, 5;
    );
    SetPlayerMap(MAP_ROUTE104);
    u16 headerId = GetCurrentMapWildMonHeaderId();
    const struct WildPokemonInfo *info = gWildMonHeaders[headerId].encounterTypes[OW_TIME_OF_DAY_FALLBACK].landMonsInfo;
    EXPECT_NE(info, NULL);
    for (i = 0; i < 200; i++)
    {
        TryGenerateWildMon(info, WILD_AREA_LAND, 0);
        u32 g = GetMonGender(&gParties[B_TRAINER_OPPONENT_A][0]);
        if (g == MON_MALE) males++;
        else if (g == MON_FEMALE) females++;
    }
    DebugPrintf("males=%d females=%d", males, females);
    EXPECT_GT(males, 40);
    EXPECT_GT(females, 40);
}

// ---------------------------------------------------------------------------
// CF-17: wild levels follow the player's top level
// ---------------------------------------------------------------------------

static void GivePlayerTopLevel(u32 level)
{
    ZeroPlayerPartyMons();
    CreateMon(&gParties[B_TRAINER_PLAYER][0], SPECIES_TREECKO, level, 0, OTID_STRUCT_PLAYER_ID);
    CreateMon(&gParties[B_TRAINER_PLAYER][1], SPECIES_ZIGZAGOON, level - 4, 0, OTID_STRUCT_PLAYER_ID);
    CalculatePlayerPartyCount();
}

TEST("Wild levels: 1-3 below the top level, the top level is rare, never above it")
{
    u32 i, atTop = 0;
    GivePlayerTopLevel(11);
    FlagSet(CF_FLAG_LEVEL_SCALING);
    VarSet(VAR_CF_CHAPTER, 1);
    EXPECT_EQ(CF_GetPlayerTopLevel(), 11);
    for (i = 0; i < 1000; i++)
    {
        u32 lvl = CF_ScaleWildMonLevel(5, 2);
        EXPECT_GE(lvl, 8);
        EXPECT_LE(lvl, 11);
        if (lvl == 11)
            atTop++;
    }
    DebugPrintf("top level hits=%d/1000", atTop);
    EXPECT_GE(atTop, 10);
    EXPECT_LE(atTop, 60);
    FlagClear(CF_FLAG_LEVEL_SCALING);
    VarSet(VAR_CF_CHAPTER, 0);
}

TEST("Wild levels: never below the map's vanilla minimum")
{
    u32 i;
    GivePlayerTopLevel(11);
    FlagSet(CF_FLAG_LEVEL_SCALING);
    VarSet(VAR_CF_CHAPTER, 1);
    for (i = 0; i < 200; i++)
    {
        u32 lvl = CF_ScaleWildMonLevel(10, 10);
        EXPECT_GE(lvl, 10);
        EXPECT_LE(lvl, 11);
        EXPECT_EQ(CF_ScaleWildMonLevel(16, 15), 15);
    }
    FlagClear(CF_FLAG_LEVEL_SCALING);
    VarSet(VAR_CF_CHAPTER, 0);
}

TEST("Wild levels: vanilla level in the prologue (chapter 0) and without scaling")
{
    GivePlayerTopLevel(11);
    FlagSet(CF_FLAG_LEVEL_SCALING);
    VarSet(VAR_CF_CHAPTER, 0);
    EXPECT_EQ(CF_ScaleWildMonLevel(5, 2), 5);
    FlagClear(CF_FLAG_LEVEL_SCALING);
    VarSet(VAR_CF_CHAPTER, 1);
    EXPECT_EQ(CF_ScaleWildMonLevel(5, 2), 5);
    VarSet(VAR_CF_CHAPTER, 0);
}

// ---------------------------------------------------------------------------
// CF-18: trainer levels are shifted down below the player's top level
// Test builds use the test trainer table, so the trainers are defined here
// (same shape as the game's Petalburg Woods grunt and rival Flora fights).
// ---------------------------------------------------------------------------

static const struct TrainerMon sCfGruntMons[] =
{
    { .species = SPECIES_KOFFING, .lvl = 15 },
    { .species = SPECIES_ZUBAT, .lvl = 15 },
};

static const struct TrainerMon sCfRivalMons[] =
{
    { .species = SPECIES_ZIGZAGOON, .lvl = 11 },
    { .species = SPECIES_POOCHYENA, .lvl = 12 },
    { .species = SPECIES_TAILLOW, .lvl = 14 },
};

static const struct Trainer sCfGrunt =
{
    .trainerClass = TRAINER_CLASS_TEAM_ROCKET_FRLG,
    .aiFlags = AI_FLAG_CHECK_BAD_MOVE,
    .party = TRAINER_PARTY(sCfGruntMons),
};

static const struct Trainer sCfRival =
{
    .trainerClass = TRAINER_CLASS_RIVAL,
    .aiFlags = AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_ACE_POKEMON,
    .party = TRAINER_PARTY(sCfRivalMons),
};

static const struct Trainer sCfAceOnly =
{
    .trainerClass = TRAINER_CLASS_HIKER,
    .aiFlags = AI_FLAG_ACE_POKEMON,
    .party = TRAINER_PARTY(sCfGruntMons),
};

TEST("Trainer levels: boss = Ace Pokemon flag or a leader/rival/E4/champion/admin class")
{
    EXPECT(!CF_IsBossTrainer(&sCfGrunt));
    EXPECT(CF_IsBossTrainer(&sCfRival));
    EXPECT(CF_IsBossTrainer(&sCfAceOnly));
}

TEST("Trainer levels: a normal trainer ends 1-3 below the top level (rarely equal), spacing kept")
{
    u32 i, j, atTop = 0, highest = 0;
    const struct Trainer *trainer = &sCfGrunt;
    struct Pokemon *party = Alloc(PARTY_SIZE * sizeof(struct Pokemon));
    EXPECT(!CF_IsBossTrainer(trainer));
    for (j = 0; j < trainer->partySize; j++)
        highest = max(highest, trainer->party[j].lvl);
    GivePlayerTopLevel(11);
    FlagSet(CF_FLAG_LEVEL_SCALING);
    VarSet(VAR_CF_CHAPTER, 1);
    for (i = 0; i < 100; i++)
    {
        u32 n = CreateNPCTrainerPartyFromTrainer(party, trainer, TRUE, BATTLE_TYPE_TRAINER);
        u32 top = 0, shift;
        for (j = 0; j < n; j++)
            top = max(top, GetMonData(&party[j], MON_DATA_LEVEL));
        EXPECT_GE(top, 8);
        EXPECT_LE(top, 11);
        if (top == 11)
            atTop++;
        shift = highest - top;
        for (j = 0; j < n; j++)
            EXPECT_EQ(GetMonData(&party[j], MON_DATA_LEVEL), trainer->party[j].lvl - shift);
    }
    DebugPrintf("trainer at top=%d/100", atTop);
    EXPECT_LE(atTop, 20);
    FlagClear(CF_FLAG_LEVEL_SCALING);
    VarSet(VAR_CF_CHAPTER, 0);
    Free(party);
}

TEST("Trainer levels: a boss (rival) ace is capped at the top level, never raised")
{
    u32 j, n, highest = 0;
    const struct Trainer *trainer = &sCfRival;
    struct Pokemon *party = Alloc(PARTY_SIZE * sizeof(struct Pokemon));
    EXPECT(CF_IsBossTrainer(trainer));
    for (j = 0; j < trainer->partySize; j++)
        highest = max(highest, trainer->party[j].lvl);
    FlagSet(CF_FLAG_LEVEL_SCALING);
    VarSet(VAR_CF_CHAPTER, 1);

    // Player below the authored levels: shifted down so the ace equals the top level.
    GivePlayerTopLevel(highest - 3);
    n = CreateNPCTrainerPartyFromTrainer(party, trainer, TRUE, BATTLE_TYPE_TRAINER);
    for (j = 0; j < n; j++)
        EXPECT_EQ(GetMonData(&party[j], MON_DATA_LEVEL), trainer->party[j].lvl - 3);

    // Player above the authored levels: unchanged (no upward scaling).
    GivePlayerTopLevel(highest + 6);
    n = CreateNPCTrainerPartyFromTrainer(party, trainer, TRUE, BATTLE_TYPE_TRAINER);
    for (j = 0; j < n; j++)
        EXPECT_EQ(GetMonData(&party[j], MON_DATA_LEVEL), trainer->party[j].lvl);

    // Scaling off: authored levels.
    FlagClear(CF_FLAG_LEVEL_SCALING);
    GivePlayerTopLevel(highest - 3);
    n = CreateNPCTrainerPartyFromTrainer(party, trainer, TRUE, BATTLE_TYPE_TRAINER);
    for (j = 0; j < n; j++)
        EXPECT_EQ(GetMonData(&party[j], MON_DATA_LEVEL), trainer->party[j].lvl);
    VarSet(VAR_CF_CHAPTER, 0);
    Free(party);
}

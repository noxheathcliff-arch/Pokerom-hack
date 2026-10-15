// Hack: Pokemon Confluence engine helpers (docs/hack/ENGINE_CHANGES.md §CF, GAME_SYSTEMS §17).
// E-BITS, decisions, E-REPREL, E-CAP, E-REMOVE, E-NATIVE, E-ADAPT, E-ECO, E-OUT, E-LEDGER.
// Script macros live in asm/macros/event.inc; specials in data/specials.inc.
// Everything here is ROM code; the only save data added is the 16-byte ledger in SaveBlock3.
#include "global.h"
#include "confluence.h"
#include "event_data.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "script.h"
#include "tv.h"

void EndMassOutbreak(void); // src/tv.c (no header prototype upstream)
#include "constants/confluence.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "constants/maps.h"
#include "constants/map_groups.h"

// ---------------------------------------------------------------------------
// Storage tables
// ---------------------------------------------------------------------------

// The decision vars are not contiguous IDs (see FLAGS_VARS_REGISTRY.md): always go through this table.
static const u16 sDecisionVars[] =
{
    VAR_CF_D00, VAR_CF_D01, VAR_CF_D02, VAR_CF_D03, VAR_CF_D04, VAR_CF_D05,
    VAR_CF_D06, VAR_CF_D07, VAR_CF_D08, VAR_CF_D09, VAR_CF_D10, VAR_CF_D11,
    VAR_CF_D12, VAR_CF_D13, VAR_CF_D14, VAR_CF_D15, VAR_CF_D16,
};
STATIC_ASSERT(ARRAY_COUNT(sDecisionVars) * 8 >= CF_DECISION_COUNT, NotEnoughDecisionVars);

static const u16 sReputationVars[CF_REP_COUNT] =
{
    VAR_CF_REP_L, VAR_CF_REP_C, VAR_CF_REP_M, VAR_CF_REP_A, VAR_CF_REP_I, VAR_CF_REP_G, VAR_CF_REP_P,
};

static const u16 sRelationVars[] =
{
    VAR_CF_BR, VAR_CF_BL, VAR_CF_FL, VAR_CF_PR, VAR_CF_PE, VAR_CF_AM, VAR_CF_TI, VAR_CF_GI,
};

// E-ECO: map -> ecosystem zone (ENCOUNTERS_PLAN §3.1). Only maps whose wild-encounter JSON lists
// consecutive variant entries (base, _Mixte, _Restaure, _Abattu) actually change; a map with a
// single header ignores the zone state. Keep this list in sync with ENCOUNTERS_PLAN §3.1.
struct EcoZoneMap
{
    u8 mapGroup;
    u8 mapNum;
    u8 zone;
};

#define ECO_MAP(map, z) { MAP_GROUP(map), MAP_NUM(map), z }
static const struct EcoZoneMap sEcoZoneMaps[] =
{
    // Z-01 Littoral sud
    ECO_MAP(MAP_ROUTE101, ECO_Z01), ECO_MAP(MAP_ROUTE102, ECO_Z01), ECO_MAP(MAP_ROUTE103, ECO_Z01),
    ECO_MAP(MAP_ROUTE104, ECO_Z01), ECO_MAP(MAP_ROUTE105, ECO_Z01), ECO_MAP(MAP_ROUTE106, ECO_Z01),
    ECO_MAP(MAP_ROUTE107, ECO_Z01), ECO_MAP(MAP_ROUTE108, ECO_Z01), ECO_MAP(MAP_ROUTE109, ECO_Z01),
    ECO_MAP(MAP_ROUTE134, ECO_Z01), ECO_MAP(MAP_DEWFORD_TOWN, ECO_Z01), ECO_MAP(MAP_SLATEPORT_CITY, ECO_Z01),
    ECO_MAP(MAP_PETALBURG_CITY, ECO_Z01), ECO_MAP(MAP_ABANDONED_SHIP_ROOMS_B1F, ECO_Z01),
    ECO_MAP(MAP_ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS, ECO_Z01),
    // Z-02 Merouville et mines
    ECO_MAP(MAP_PETALBURG_WOODS, ECO_Z02), ECO_MAP(MAP_ROUTE115, ECO_Z02), ECO_MAP(MAP_ROUTE116, ECO_Z02),
    ECO_MAP(MAP_RUSTURF_TUNNEL, ECO_Z02), ECO_MAP(MAP_GRANITE_CAVE_1F, ECO_Z02), ECO_MAP(MAP_GRANITE_CAVE_B1F, ECO_Z02),
    ECO_MAP(MAP_GRANITE_CAVE_B2F, ECO_Z02), ECO_MAP(MAP_GRANITE_CAVE_STEVENS_ROOM, ECO_Z02),
    // Z-03 Lavandia, centrale et desert
    ECO_MAP(MAP_ROUTE110, ECO_Z03), ECO_MAP(MAP_NEW_MAUVILLE_ENTRANCE, ECO_Z03), ECO_MAP(MAP_NEW_MAUVILLE_INSIDE, ECO_Z03),
    ECO_MAP(MAP_ROUTE117, ECO_Z03), ECO_MAP(MAP_ROUTE118, ECO_Z03), ECO_MAP(MAP_ROUTE111, ECO_Z03),
    ECO_MAP(MAP_MIRAGE_TOWER_1F, ECO_Z03), ECO_MAP(MAP_MIRAGE_TOWER_2F, ECO_Z03), ECO_MAP(MAP_MIRAGE_TOWER_3F, ECO_Z03),
    ECO_MAP(MAP_MIRAGE_TOWER_4F, ECO_Z03),
    // Z-04 Forets du nord et Nenucrique
    ECO_MAP(MAP_ROUTE119, ECO_Z04), ECO_MAP(MAP_ROUTE120, ECO_Z04), ECO_MAP(MAP_ROUTE121, ECO_Z04),
    ECO_MAP(MAP_ROUTE122, ECO_Z04), ECO_MAP(MAP_ROUTE123, ECO_Z04), ECO_MAP(MAP_LILYCOVE_CITY, ECO_Z04),
    ECO_MAP(MAP_MT_PYRE_1F, ECO_Z04), ECO_MAP(MAP_MT_PYRE_2F, ECO_Z04), ECO_MAP(MAP_MT_PYRE_3F, ECO_Z04),
    ECO_MAP(MAP_MT_PYRE_4F, ECO_Z04), ECO_MAP(MAP_MT_PYRE_5F, ECO_Z04), ECO_MAP(MAP_MT_PYRE_6F, ECO_Z04),
    ECO_MAP(MAP_MT_PYRE_EXTERIOR, ECO_Z04), ECO_MAP(MAP_MT_PYRE_SUMMIT, ECO_Z04),
    // Z-05 Mers de l'est
    ECO_MAP(MAP_ROUTE124, ECO_Z05), ECO_MAP(MAP_ROUTE125, ECO_Z05), ECO_MAP(MAP_ROUTE126, ECO_Z05),
    ECO_MAP(MAP_ROUTE127, ECO_Z05), ECO_MAP(MAP_ROUTE128, ECO_Z05), ECO_MAP(MAP_ROUTE129, ECO_Z05),
    ECO_MAP(MAP_ROUTE130, ECO_Z05), ECO_MAP(MAP_ROUTE131, ECO_Z05), ECO_MAP(MAP_ROUTE132, ECO_Z05),
    ECO_MAP(MAP_ROUTE133, ECO_Z05), ECO_MAP(MAP_MOSSDEEP_CITY, ECO_Z05), ECO_MAP(MAP_SOOTOPOLIS_CITY, ECO_Z05),
    ECO_MAP(MAP_PACIFIDLOG_TOWN, ECO_Z05), ECO_MAP(MAP_EVER_GRANDE_CITY, ECO_Z05),
    ECO_MAP(MAP_UNDERWATER_ROUTE124, ECO_Z05), ECO_MAP(MAP_UNDERWATER_ROUTE126, ECO_Z05),
    ECO_MAP(MAP_SHOAL_CAVE_LOW_TIDE_ENTRANCE_ROOM, ECO_Z05), ECO_MAP(MAP_SHOAL_CAVE_LOW_TIDE_INNER_ROOM, ECO_Z05),
    ECO_MAP(MAP_SHOAL_CAVE_LOW_TIDE_STAIRS_ROOM, ECO_Z05), ECO_MAP(MAP_SHOAL_CAVE_LOW_TIDE_LOWER_ROOM, ECO_Z05),
    ECO_MAP(MAP_SHOAL_CAVE_LOW_TIDE_ICE_ROOM, ECO_Z05),
    ECO_MAP(MAP_SEAFLOOR_CAVERN_ENTRANCE, ECO_Z05), ECO_MAP(MAP_SEAFLOOR_CAVERN_ROOM1, ECO_Z05),
    ECO_MAP(MAP_SEAFLOOR_CAVERN_ROOM2, ECO_Z05), ECO_MAP(MAP_SEAFLOOR_CAVERN_ROOM3, ECO_Z05),
    ECO_MAP(MAP_SEAFLOOR_CAVERN_ROOM4, ECO_Z05), ECO_MAP(MAP_SEAFLOOR_CAVERN_ROOM5, ECO_Z05),
    ECO_MAP(MAP_SEAFLOOR_CAVERN_ROOM6, ECO_Z05), ECO_MAP(MAP_SEAFLOOR_CAVERN_ROOM7, ECO_Z05),
    ECO_MAP(MAP_SEAFLOOR_CAVERN_ROOM8, ECO_Z05),
    ECO_MAP(MAP_CAVE_OF_ORIGIN_ENTRANCE, ECO_Z05), ECO_MAP(MAP_CAVE_OF_ORIGIN_1F, ECO_Z05),
    ECO_MAP(MAP_VICTORY_ROAD_1F, ECO_Z05), ECO_MAP(MAP_VICTORY_ROAD_B1F, ECO_Z05), ECO_MAP(MAP_VICTORY_ROAD_B2F, ECO_Z05),
    // Z-06 Cendres et volcan
    ECO_MAP(MAP_ROUTE112, ECO_Z06), ECO_MAP(MAP_FIERY_PATH, ECO_Z06), ECO_MAP(MAP_JAGGED_PASS, ECO_Z06),
    ECO_MAP(MAP_ROUTE113, ECO_Z06), ECO_MAP(MAP_ROUTE114, ECO_Z06),
    ECO_MAP(MAP_METEOR_FALLS_1F_1R, ECO_Z06), ECO_MAP(MAP_METEOR_FALLS_1F_2R, ECO_Z06),
    ECO_MAP(MAP_METEOR_FALLS_B1F_1R, ECO_Z06), ECO_MAP(MAP_METEOR_FALLS_B1F_2R, ECO_Z06),
    ECO_MAP(MAP_METEOR_FALLS_STEVENS_CAVE, ECO_Z06),
    ECO_MAP(MAP_MAGMA_HIDEOUT_1F, ECO_Z06), ECO_MAP(MAP_MAGMA_HIDEOUT_2F_1R, ECO_Z06),
    ECO_MAP(MAP_MAGMA_HIDEOUT_2F_2R, ECO_Z06), ECO_MAP(MAP_MAGMA_HIDEOUT_2F_3R, ECO_Z06),
    ECO_MAP(MAP_MAGMA_HIDEOUT_3F_1R, ECO_Z06), ECO_MAP(MAP_MAGMA_HIDEOUT_3F_2R, ECO_Z06),
    ECO_MAP(MAP_MAGMA_HIDEOUT_3F_3R, ECO_Z06), ECO_MAP(MAP_MAGMA_HIDEOUT_4F, ECO_Z06),
};
#undef ECO_MAP

// ---------------------------------------------------------------------------
// New game
// ---------------------------------------------------------------------------

static void CF_DemoNewGameInit(void);

void CF_InitNewGameVars(void)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sRelationVars); i++)
        VarSet(sRelationVars[i], CF_START_RELATION);
    VarSet(VAR_CF_HO, CF_START_HOOPA);
    for (i = 0; i < CF_REP_COUNT; i++)
        VarSet(sReputationVars[i], CF_START_REPUTATION);
    VarSet(VAR_CF_PA, CF_START_PA);
    VarSet(VAR_CF_RK, CF_START_RK);
    VarSet(VAR_CF_CAP, CF_START_LEVEL_CAP);
    // Everything else (CHAPTER, ECO = all ENVAHI, WORLD, decisions...) starts at 0 (vars are cleared).
    CF_DemoNewGameInit();
}

// SLICE_DEMO_CH0-1 s2 / s6 / s8: demo new-game flags and neutral vanilla states.
// The prologue itself (party, P1) is played by scripts: Route104_OnFrame, VAR_ROUTE104_STATE = 0.
static void CF_DemoNewGameInit(void)
{
    u32 i;

    FlagSet(FLAG_NO_WILD_ENCOUNTERS); // cleared at the end of P4
    // Object visibility: flag set = hidden. VIS_00/01 (beach) and VIS_10/11/12/14/15 (walls) stay visible.
    // VIS_39 = Routes 102-104 trainers (until chapter 1); VIS_40/41 = Petalburg mini-scene (D006 b).
    for (i = 2; i <= 41; i++)
    {
        if (i == 10 || i == 11 || i == 12 || i == 14 || i == 15)
            continue;
        FlagSet(FLAG_CF_VIS_00 + i);
    }
    // Mr. Briney (s6): at home, no crossing, no Peeko, no boat on Route 104.
    FlagClear(FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY);
    FlagSet(FLAG_HIDE_BRINEYS_HOUSE_PEEKO);
    FlagSet(FLAG_HIDE_ROUTE_104_MR_BRINEY);
    FlagSet(FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT);
    // Vanilla scripts neutralized (s8): final values.
    FlagSet(FLAG_RESCUED_BIRCH);
    FlagSet(FLAG_HIDE_ROUTE_101_ZIGZAGOON); // vanilla Route 101 chase objects (visible by default in vanilla)
    FlagSet(FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG);
    VarSet(VAR_LITTLEROOT_INTRO_STATE, 7); // 6 = Brendan house "gym report" scene; 7 = past it
    VarSet(VAR_LITTLEROOT_TOWN_STATE, 4);
    VarSet(VAR_LITTLEROOT_RIVAL_STATE, 4);
    VarSet(VAR_ROUTE101_STATE, 2); // P4 triggers (10,18) / (11,18)
    VarSet(VAR_PETALBURG_CITY_STATE, 1);
    VarSet(VAR_SCOTT_PETALBURG_ENCOUNTER, 1);
    VarSet(VAR_BRINEY_HOUSE_STATE, 0); // 0 = P2 pending, 9 = "at home" afterwards
    // Brendan's house: only Mrs. Seko (rival mom) remains.
    FlagSet(FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM);
    FlagSet(FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_1);
    FlagSet(FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_2);
    FlagSet(FLAG_HIDE_PLAYERS_HOUSE_DAD);
    FlagSet(FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING);
    FlagSet(FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN);
    FlagClear(FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM);
}

// ---------------------------------------------------------------------------
// E-BITS
// ---------------------------------------------------------------------------

static u16 BitMask(u32 width)
{
    if (width == 0)
        return 0;
    if (width >= 16)
        return 0xFFFF;
    return (1u << width) - 1;
}

u16 CF_ReadBits(u16 varId, u32 shift, u32 width)
{
    if (shift >= 16)
        return 0;
    return (VarGet(varId) >> shift) & BitMask(width);
}

void CF_WriteBits(u16 varId, u32 shift, u32 width, u16 value)
{
    u16 mask, old;
    if (shift >= 16)
        return;
    mask = BitMask(width) << shift;
    old = VarGet(varId);
    VarSet(varId, (old & ~mask) | ((value << shift) & mask));
}

// Decision n (1..131) -> var + shift. Returns FALSE for an out-of-range decision.
static bool32 DecisionSlot(u32 n, u16 *varId, u32 *shift)
{
    if (n == 0 || n > CF_DECISION_COUNT)
        return FALSE;
    *varId = sDecisionVars[(n - 1) / 8];
    *shift = 2 * ((n - 1) % 8);
    return TRUE;
}

u16 CF_GetDecision(u32 n)
{
    u16 varId;
    u32 shift;
    if (!DecisionSlot(n, &varId, &shift))
        return DEC_NONE;
    return CF_ReadBits(varId, shift, 2);
}

// Write-once: returns TRUE if the option was recorded, FALSE if the decision was already taken
// (or the arguments are invalid). This is the single-use guard of every decision delta.
bool32 CF_SetDecision(u32 n, u32 option)
{
    u16 varId;
    u32 shift;
    if (option == DEC_NONE || option > DEC_C || !DecisionSlot(n, &varId, &shift))
        return FALSE;
    if (CF_ReadBits(varId, shift, 2) != DEC_NONE)
        return FALSE;
    CF_WriteBits(varId, shift, 2, option);
    return TRUE;
}

// ---------------------------------------------------------------------------
// E-REPREL: S(X) = rX - mean(7 reputations), truncated toward zero.
// ---------------------------------------------------------------------------

s32 CF_GetRepStanding(u16 repVar)
{
    s32 sum = 0;
    u32 i;
    for (i = 0; i < CF_REP_COUNT; i++)
        sum += VarGet(sReputationVars[i]);
    return (7 * (s32)VarGet(repVar) - sum) / 7;
}

// ---------------------------------------------------------------------------
// E-CAP: monotonic level cap
// ---------------------------------------------------------------------------

u16 CF_RaiseLevelCap(u16 cap)
{
    if (cap > MAX_LEVEL)
        cap = MAX_LEVEL;
    if (cap > VarGet(VAR_CF_CAP))
        VarSet(VAR_CF_CAP, cap);
    return VarGet(VAR_CF_CAP);
}

// ---------------------------------------------------------------------------
// E-REMOVE: remove a party slot and compact the party
// ---------------------------------------------------------------------------

bool32 CF_RemovePartyMon(u32 slot)
{
    u32 i, othersUsable = 0;

    if (slot >= PARTY_SIZE || GetMonData(&gParties[B_TRAINER_PLAYER][slot], MON_DATA_SPECIES) == SPECIES_NONE)
        return FALSE;
    // Never leave the player without a non-egg Pokemon.
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (i != slot
         && GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES) != SPECIES_NONE
         && !GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_IS_EGG))
            othersUsable++;
    }
    if (othersUsable == 0)
        return FALSE;

    ZeroMonData(&gParties[B_TRAINER_PLAYER][slot]);
    CompactPartySlots();
    CalculatePlayerPartyCount();
    return TRUE;
}

// ---------------------------------------------------------------------------
// E-NATIVE: species belongs to the Hoenn dex (regional forms from other regions excluded)
// ---------------------------------------------------------------------------

bool32 CF_IsHoennNative(u32 species)
{
    const struct SpeciesInfo *info;
    if (species == SPECIES_NONE || species >= NUM_SPECIES)
        return FALSE;
    info = &gSpeciesInfo[species];
    if (info->isAlolanForm || info->isGalarianForm || info->isHisuianForm || info->isPaldeanForm)
        return FALSE;
    return SpeciesToHoennPokedexNum(species) != 0;
}

// ---------------------------------------------------------------------------
// E-ADAPT (COMBAT_DESIGN §5.3): for each usable party Pokemon, +2 to its type 1 and +1 to its
// type 2 (a single-type Pokemon only gives +2). Highest score wins; tie -> type 1 of the lead
// (first usable Pokemon) if it is among the tied types, else the tied type met first in party order.
// ---------------------------------------------------------------------------

static bool32 IsUsablePartyMon(struct Pokemon *mon)
{
    return GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE
        && !GetMonData(mon, MON_DATA_IS_EGG)
        && GetMonData(mon, MON_DATA_HP) != 0;
}

u32 CF_GetDominantPartyType(void)
{
    u8 score[NUMBER_OF_MON_TYPES] = {0};
    u8 order[NUMBER_OF_MON_TYPES];
    u32 nOrder = 0, i, j, best = 0, leadType = TYPE_NONE, result = TYPE_NONE;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][i];
        u32 species, t1, t2;
        if (!IsUsablePartyMon(mon))
            continue;
        species = GetMonData(mon, MON_DATA_SPECIES);
        t1 = GetSpeciesType(species, 0);
        t2 = GetSpeciesType(species, 1);
        if (leadType == TYPE_NONE)
            leadType = t1;
        score[t1] += 2;
        if (t2 != t1)
            score[t2] += 1;
        for (j = 0; j < nOrder && order[j] != t1; j++)
            ;
        if (j == nOrder)
            order[nOrder++] = t1;
        for (j = 0; j < nOrder && order[j] != t2; j++)
            ;
        if (j == nOrder)
            order[nOrder++] = t2;
    }
    for (i = 0; i < NUMBER_OF_MON_TYPES; i++)
        if (score[i] > best)
            best = score[i];
    if (best == 0)
        return TYPE_NONE;
    if (score[leadType] == best)
        return leadType;
    for (j = 0; j < nOrder; j++)
    {
        if (score[order[j]] == best)
        {
            result = order[j];
            break;
        }
    }
    return result;
}

// COMBAT_DESIGN §5.3 packages: 1 = A, 2 = B, 3 = C.
u32 CF_GetAdaptPackage(u32 type)
{
    switch (type)
    {
    case TYPE_GRASS: case TYPE_BUG: case TYPE_ICE: case TYPE_FAIRY:
    case TYPE_PSYCHIC: case TYPE_GHOST: case TYPE_DRAGON:
        return 1;
    case TYPE_WATER: case TYPE_GROUND: case TYPE_FLYING: case TYPE_POISON: case TYPE_FIGHTING:
        return 3;
    default: // Fire, Rock, Steel, Electric, Normal, Dark (and anything unexpected)
        return 2;
    }
}

// ---------------------------------------------------------------------------
// E-ECO: alternate wild headers by zone state
// ---------------------------------------------------------------------------

u32 CF_GetEcoZone(u32 mapGroup, u32 mapNum)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sEcoZoneMaps); i++)
    {
        if (sEcoZoneMaps[i].mapGroup == mapGroup && sEcoZoneMaps[i].mapNum == mapNum)
            return sEcoZoneMaps[i].zone;
    }
    return ECO_ZONE_NONE;
}

u32 CF_GetEcoState(u32 zone)
{
    if (zone == ECO_ZONE_NONE || zone > ECO_ZONE_COUNT)
        return ECO_ENVAHI;
    return CF_ReadBits(VAR_CF_ECO, 2 * (zone - 1), 2);
}

// numHeaders = number of consecutive headers the map has. A state without its own header
// (e.g. a map with only 2 tables in state ABATTU) falls back to the base header (offset 0).
u32 CF_GetEcoHeaderOffset(u32 mapGroup, u32 mapNum, u32 numHeaders)
{
    u32 state;
    if (numHeaders <= 1)
        return 0;
    state = CF_GetEcoState(CF_GetEcoZone(mapGroup, mapNum));
    return state < numHeaders ? state : 0;
}

// ---------------------------------------------------------------------------
// E-OUT: scripted ("ring") outbreaks, using the vanilla SaveBlock1 outbreak fields.
// The vanilla TV random outbreak is disabled in tv.c (TryStartRandomMassOutbreak).
// ---------------------------------------------------------------------------

static void FillLevelUpMoves(u32 species, u32 level, u16 *moves)
{
    const struct LevelUpMove *learnset = GetSpeciesLevelUpLearnset(species);
    u32 i, j, n = 0;

    for (i = 0; i < MAX_MON_MOVES; i++)
        moves[i] = MOVE_NONE;
    for (i = 0; learnset[i].move != LEVEL_UP_MOVE_END; i++)
    {
        bool32 known = FALSE;
        if (learnset[i].level > level)
            break;
        for (j = 0; j < MAX_MON_MOVES; j++)
            if (moves[j] == learnset[i].move)
                known = TRUE;
        if (known)
            continue;
        if (n < MAX_MON_MOVES)
        {
            moves[n++] = learnset[i].move;
        }
        else
        {
            for (j = 0; j < MAX_MON_MOVES - 1; j++)
                moves[j] = moves[j + 1];
            moves[MAX_MON_MOVES - 1] = learnset[i].move;
        }
    }
}

void CF_StartRingOutbreak(u32 species, u32 mapGroup, u32 mapNum, u32 level, u32 probability, const u16 *moves, u32 days)
{
    u32 i;
    if (level == 0 || level > MAX_LEVEL)
        level = 5;
    if (probability > 100)
        probability = 100;
    gSaveBlock1Ptr->outbreakPokemonSpecies = species;
    gSaveBlock1Ptr->outbreakLocationMapGroup = mapGroup;
    gSaveBlock1Ptr->outbreakLocationMapNum = mapNum;
    gSaveBlock1Ptr->outbreakPokemonLevel = level;
    gSaveBlock1Ptr->outbreakPokemonProbability = probability;
    gSaveBlock1Ptr->outbreakDaysLeft = days == 0 ? CF_OUTBREAK_UNTIL_CLEARED : days;
    if (moves != NULL && moves[0] != MOVE_NONE)
    {
        for (i = 0; i < MAX_MON_MOVES; i++)
            gSaveBlock1Ptr->outbreakPokemonMoves[i] = moves[i];
    }
    else
    {
        FillLevelUpMoves(species, level, gSaveBlock1Ptr->outbreakPokemonMoves);
    }
}

void CF_ClearRingOutbreak(void)
{
    EndMassOutbreak();
}

// ---------------------------------------------------------------------------
// E-LEDGER: 128 static-encounter bits in SaveBlock3
// ---------------------------------------------------------------------------

bool32 CF_LedgerGet(u32 index)
{
    if (index >= CF_LEDGER_BITS)
        return FALSE;
    return (gSaveBlock3Ptr->cfStaticLedger[index / 8] >> (index % 8)) & 1;
}

void CF_LedgerSet(u32 index, bool32 value)
{
    if (index >= CF_LEDGER_BITS)
        return;
    if (value)
        gSaveBlock3Ptr->cfStaticLedger[index / 8] |= 1 << (index % 8);
    else
        gSaveBlock3Ptr->cfStaticLedger[index / 8] &= ~(1 << (index % 8));
}

// ---------------------------------------------------------------------------
// Script natives (callnative, requests_effects=1) used by the macros in asm/macros/event.inc.
// Arguments read with VarGet accept either a var or an immediate value.
// ---------------------------------------------------------------------------

void Script_CF_GetBits(struct ScriptContext *ctx)
{
    u16 varId = ScriptReadHalfword(ctx);
    u32 shift = VarGet(ScriptReadHalfword(ctx));
    u32 width = VarGet(ScriptReadHalfword(ctx));
    Script_RequestEffects(SCREFF_V1);
    gSpecialVar_Result = CF_ReadBits(varId, shift, width);
}

void Script_CF_SetBits(struct ScriptContext *ctx)
{
    u16 varId = ScriptReadHalfword(ctx);
    u32 shift = VarGet(ScriptReadHalfword(ctx));
    u32 width = VarGet(ScriptReadHalfword(ctx));
    u16 value = VarGet(ScriptReadHalfword(ctx));
    Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE);
    Script_RequestWriteVar(varId);
    CF_WriteBits(varId, shift, width, value);
}

void Script_CF_SetDecision(struct ScriptContext *ctx)
{
    u32 n = VarGet(ScriptReadHalfword(ctx));
    u32 option = VarGet(ScriptReadHalfword(ctx));
    Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE);
    gSpecialVar_Result = CF_SetDecision(n, option);
}

void Script_CF_CheckDecision(struct ScriptContext *ctx)
{
    u32 n = VarGet(ScriptReadHalfword(ctx));
    Script_RequestEffects(SCREFF_V1);
    gSpecialVar_Result = CF_GetDecision(n);
}

void Script_CF_RepStanding(struct ScriptContext *ctx)
{
    u16 repVar = ScriptReadHalfword(ctx);
    Script_RequestEffects(SCREFF_V1);
    gSpecialVar_Result = CF_GetRepStanding(repVar) + 100;
}

void Script_CF_RaiseCap(struct ScriptContext *ctx)
{
    u16 cap = VarGet(ScriptReadHalfword(ctx));
    Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE);
    gSpecialVar_Result = CF_RaiseLevelCap(cap);
}

void Script_CF_RemovePartyMon(struct ScriptContext *ctx)
{
    u32 slot = VarGet(ScriptReadHalfword(ctx));
    Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE);
    gSpecialVar_Result = CF_RemovePartyMon(slot);
}

// E-CLEARPARTY: empties the whole party (no "last Pokemon" guard; prologue, SLICE_DEMO_CH0-1).
void CF_ClearParty(void)
{
    ZeroPlayerPartyMons();
    CalculatePlayerPartyCount();
}

void Script_CF_ClearParty(struct ScriptContext *ctx)
{
    Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE);
    CF_ClearParty();
}

void Script_CF_IsHoennNative(struct ScriptContext *ctx)
{
    u32 species = VarGet(ScriptReadHalfword(ctx));
    Script_RequestEffects(SCREFF_V1);
    gSpecialVar_Result = CF_IsHoennNative(species);
}

void Script_CF_DominantType(struct ScriptContext *ctx)
{
    Script_RequestEffects(SCREFF_V1);
    gSpecialVar_Result = CF_GetDominantPartyType();
    gSpecialVar_0x8000 = CF_GetAdaptPackage(gSpecialVar_Result);
}

void Script_CF_SetRingOutbreak(struct ScriptContext *ctx)
{
    u32 species = VarGet(ScriptReadHalfword(ctx));
    u32 map = ScriptReadHalfword(ctx); // MAP_* constant: (num | group << 8)
    u32 level = VarGet(ScriptReadHalfword(ctx));
    u32 probability = VarGet(ScriptReadHalfword(ctx));
    u32 days = VarGet(ScriptReadHalfword(ctx));
    u16 moves[MAX_MON_MOVES];
    u32 i;
    for (i = 0; i < MAX_MON_MOVES; i++)
        moves[i] = ScriptReadHalfword(ctx);
    Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE);
    CF_StartRingOutbreak(species, MAP_GROUP(map), MAP_NUM(map), level, probability, moves, days);
}

void Script_CF_ClearRingOutbreak(struct ScriptContext *ctx)
{
    Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE);
    CF_ClearRingOutbreak();
}

void Script_CF_LedgerGet(struct ScriptContext *ctx)
{
    u32 index = VarGet(ScriptReadHalfword(ctx));
    Script_RequestEffects(SCREFF_V1);
    gSpecialVar_Result = CF_LedgerGet(index);
}

void Script_CF_LedgerSet(struct ScriptContext *ctx)
{
    u32 index = VarGet(ScriptReadHalfword(ctx));
    u32 value = VarGet(ScriptReadHalfword(ctx));
    Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE);
    CF_LedgerSet(index, value);
}

// ---------------------------------------------------------------------------
// Specials (arguments in VAR_0x8004.., result in VAR_RESULT), for scripts that prefer `special`.
// ---------------------------------------------------------------------------

void CF_GetBits(void)
{
    gSpecialVar_Result = CF_ReadBits(gSpecialVar_0x8004, gSpecialVar_0x8005, gSpecialVar_0x8006);
}

void CF_SetBits(void)
{
    CF_WriteBits(gSpecialVar_0x8004, gSpecialVar_0x8005, gSpecialVar_0x8006, gSpecialVar_0x8007);
}

void CF_RepStanding(void)
{
    gSpecialVar_Result = CF_GetRepStanding(gSpecialVar_0x8004) + 100;
}

void CF_RaiseCap(void)
{
    gSpecialVar_Result = CF_RaiseLevelCap(gSpecialVar_0x8004);
}

void SetRingOutbreak(void)
{
    CF_StartRingOutbreak(gSpecialVar_0x8004, gSpecialVar_0x8005 >> 8, gSpecialVar_0x8005 & 0xFF,
                         gSpecialVar_0x8006, gSpecialVar_0x8007, NULL, CF_OUTBREAK_UNTIL_CLEARED);
}

void ClearRingOutbreak(void)
{
    CF_ClearRingOutbreak();
}

void LedgerGet(void)
{
    gSpecialVar_Result = CF_LedgerGet(gSpecialVar_0x8004);
}

void LedgerSet(void)
{
    CF_LedgerSet(gSpecialVar_0x8004, TRUE);
}

#ifndef GUARD_CONFLUENCE_H
#define GUARD_CONFLUENCE_H

// Hack: Pokemon Confluence engine helpers (src/confluence.c).

// CF-15: every Pokemon obeys, whatever its level, OT or the badges (Red is a champion).
#define CF_ALWAYS_OBEY TRUE

// CF-16: full party EXP. Every non-fainted party member gets the same, unsplit EXP as the battler.
// Always on in the game; the test build drives it through CF_FLAG_FULL_PARTY_EXP so the upstream
// EXP tests keep their vanilla behavior.
#if TESTING
#define CF_FLAG_FULL_PARTY_EXP TESTING_FLAG_UNUSED_3
#endif
bool32 CF_IsFullPartyExpEnabled(void);

// CF-14: seeds the RNG (and the TID lower half) when a main menu action is picked.
void CF_SeedRngFromMainMenu(void);

// CF-17 / CF-18: wild and trainer levels follow the player's top level (off in the prologue).
// The test build drives them through CF_FLAG_LEVEL_SCALING.
#if TESTING
#define CF_FLAG_LEVEL_SCALING TESTING_FLAG_UNUSED_4
#endif
#define CF_WILD_TOP_LEVEL_CHANCE    3 // % of wild Pokemon at the player's top level
#define CF_TRAINER_TOP_LEVEL_CHANCE 5 // % of normal trainers whose highest mon is at it
struct Trainer;
u32 CF_GetPlayerTopLevel(void);
u32 CF_ScaleWildMonLevel(u32 vanillaLevel, u32 mapMinLevel);
bool32 CF_IsBossTrainer(const struct Trainer *trainer);
u32 CF_GetTrainerLevelShift(const struct Trainer *trainer, const u32 *monIndices, u32 monsCount, u32 battleTypeFlags);
u32 CF_ApplyTrainerLevelShift(u32 level, u32 shift);

void CF_InitNewGameVars(void);
u16 CF_ReadBits(u16 varId, u32 shift, u32 width);
void CF_WriteBits(u16 varId, u32 shift, u32 width, u16 value);
u16 CF_GetDecision(u32 n);
bool32 CF_SetDecision(u32 n, u32 option);
s32 CF_GetRepStanding(u16 repVar);
u16 CF_RaiseLevelCap(u16 cap);
bool32 CF_RemovePartyMon(u32 slot);
void CF_ClearParty(void);
bool32 CF_IsHoennNative(u32 species);
u32 CF_GetDominantPartyType(void);
u32 CF_GetAdaptPackage(u32 type);
u32 CF_GetEcoZone(u32 mapGroup, u32 mapNum);
u32 CF_GetEcoState(u32 zone);
u32 CF_GetEcoHeaderOffset(u32 mapGroup, u32 mapNum, u32 numHeaders);
void CF_StartRingOutbreak(u32 species, u32 mapGroup, u32 mapNum, u32 level, u32 probability, const u16 *moves, u32 days);
void CF_ClearRingOutbreak(void);
bool32 CF_LedgerGet(u32 index);
void CF_LedgerSet(u32 index, bool32 value);

// Specials
void CF_GetBits(void);
void CF_SetBits(void);
void CF_RepStanding(void);
void CF_RaiseCap(void);
void SetRingOutbreak(void);
void ClearRingOutbreak(void);
void LedgerGet(void);
void LedgerSet(void);
void CF_ShowFollowerNPC(void);
void CF_PlaceFollowerNPC(void);
void CF_StepAwayDir(void);
void CF_RevealFollowerNPC(void);
void CF_FaceEachOther(void);
void CF_FollowerSideDir(void);

#endif // GUARD_CONFLUENCE_H

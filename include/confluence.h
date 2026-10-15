#ifndef GUARD_CONFLUENCE_H
#define GUARD_CONFLUENCE_H

// Hack: Pokemon Confluence engine helpers (src/confluence.c).

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

#endif // GUARD_CONFLUENCE_H

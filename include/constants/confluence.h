#ifndef GUARD_CONSTANTS_CONFLUENCE_H
#define GUARD_CONSTANTS_CONFLUENCE_H

// Hack: Pokemon Confluence engine helpers (src/confluence.c, docs/hack/ENGINE_CHANGES.md).

// Decisions D001..D131: 2-bit slots in VAR_CF_D00..VAR_CF_D16 (0 = not taken yet).
#define CF_DECISION_COUNT   131
#define DEC_NONE            0
#define DEC_A               1
#define DEC_B               2
#define DEC_C               3   // also "refused" for declinable story battles (DECISION_LEDGER rule 7)

// Ecosystem zones Z-01..Z-06 (VAR_CF_ECO, 2 bits each; zone n uses bits 2*(n-1)).
#define ECO_ZONE_NONE       0
#define ECO_Z01             1
#define ECO_Z02             2
#define ECO_Z03             3
#define ECO_Z04             4
#define ECO_Z05             5
#define ECO_Z06             6
#define ECO_ZONE_COUNT      6

#define ECO_ENVAHI          0
#define ECO_MIXTE           1
#define ECO_RESTAURE        2
#define ECO_ABATTU          3

// Reputation indices (VAR_CF_REP_*), for documentation; CF_RepStanding takes the var itself.
#define CF_REP_COUNT        7

// New-game starting values (GAME_SYSTEMS §2).
#define CF_START_RELATION   50
#define CF_START_HOOPA      20
#define CF_START_REPUTATION 50
#define CF_START_PA         20
#define CF_START_RK         20
#define CF_START_LEVEL_CAP  14

// Static encounter ledger (SaveBlock3, E-LEDGER): 128 bits.
#define CF_LEDGER_BITS      128
#define CF_LEDGER_BYTES     (CF_LEDGER_BITS / 8)

// Scripted ("ring") outbreak: duration meaning "until ClearRingOutbreak".
#define CF_OUTBREAK_UNTIL_CLEARED 0xFFFF

#endif // GUARD_CONSTANTS_CONFLUENCE_H

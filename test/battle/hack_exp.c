#include "global.h"
#include "confluence.h"
#include "event_data.h"
#include "test/battle.h"

// ---------------------------------------------------------------------------
// CF-16: full party EXP (Cmd_getexp, CF_IsFullPartyExpEnabled)
// The game always has it on; tests drive it through CF_FLAG_FULL_PARTY_EXP.
// ---------------------------------------------------------------------------

WILD_BATTLE_TEST("Full party EXP: every non-fainted party member gets the same full EXP as the battler")
{
    GIVEN {
        FLAG_SET(CF_FLAG_FULL_PARTY_EXP);
        PLAYER(SPECIES_WOBBUFFET) { Level(20); }
        PLAYER(SPECIES_WOBBUFFET) { Level(20); }
        PLAYER(SPECIES_WOBBUFFET) { Level(20); HP(0); }
        PLAYER(SPECIES_WOBBUFFET) { Level(20); }
        OPPONENT(SPECIES_CATERPIE) { Level(10); HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Chenipan sauvage est K.O.!\p");
        EXPERIENCE_BAR(player);
        MESSAGE("Le reste de l'équipe gagne aussi des Points d'Expérience!\p");
        NOT MESSAGE("Le reste de l'équipe gagne aussi des Points d'Expérience!\p");
    } THEN {
        // Same species and level everywhere, so the unevolved-EXP bonus cannot skew the comparison.
        u32 wobbBase = gExperienceTables[gSpeciesInfo[SPECIES_WOBBUFFET].growthRate][20];
        // The test body runs again for THEN, so the lead's gain is read back from its EXP.
        u32 leadGain = GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_EXP) - wobbBase;
        EXPECT_GT(leadGain, 0);
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][1], MON_DATA_EXP), wobbBase + leadGain);
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][2], MON_DATA_EXP), wobbBase); // fainted: nothing
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][3], MON_DATA_EXP), wobbBase + leadGain);
    }
}

WILD_BATTLE_TEST("Full party EXP: without it (test control) the bench gets nothing")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Level(20); }
        PLAYER(SPECIES_WYNAUT) { Level(20); }
        OPPONENT(SPECIES_CATERPIE) { Level(10); HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Chenipan sauvage est K.O.!\p");
        NOT MESSAGE("Le reste de l'équipe gagne aussi des Points d'Expérience!\p");
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][1], MON_DATA_EXP), gExperienceTables[gSpeciesInfo[SPECIES_WYNAUT].growthRate][20]);
    }
}

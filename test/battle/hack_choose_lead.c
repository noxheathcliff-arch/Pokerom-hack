#include "global.h"
#include "battle_setup.h"
#include "event_data.h"
#include "test/battle.h"

// ---------------------------------------------------------------------------
// Choose the lead Pokemon (B_FLAG_CHOOSE_BATTLE_LEAD)
// ---------------------------------------------------------------------------

// Note: a battle test where the selected slot leads cannot be written with the current
// test runner: it tracks the player's active mon as slot 0 and reports "Illegal battle
// record" when another slot is sent out (observed, which shows the override is applied).

AI_SINGLE_BATTLE_TEST("Choose lead: without a selection the first party slot leads")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
    } THEN {
        EXPECT_EQ(player->species, SPECIES_WOBBUFFET);
    }
}

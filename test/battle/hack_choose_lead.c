#include "global.h"
#include "battle_setup.h"
#include "event_data.h"
#include "test/battle.h"

// ---------------------------------------------------------------------------
// Choose the lead Pokemon (B_FLAG_CHOOSE_BATTLE_LEAD)
// ---------------------------------------------------------------------------

SINGLE_BATTLE_TEST("Choose lead: the selected party slot is sent out first")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        gSpecialVar_0x8004 = 1;
        SetBattleLeadFromSelection();
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(player->species, SPECIES_WYNAUT);
    }
}

SINGLE_BATTLE_TEST("Choose lead: without a selection the first party slot leads")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
        EXPECT_EQ(player->species, SPECIES_WOBBUFFET);
    }
}

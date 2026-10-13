#include "global.h"
#include "test/battle.h"
#include "battle_ai_util.h"

AI_MULTI_BATTLE_TEST("12v12: AI can use all 6 party slots in a 12v12 (battler 1)")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);

        PLAYER(SPECIES_WOBBUFFET);

        PARTNER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        PARTNER(SPECIES_ABRA) { Moves(MOVE_CELEBRATE); }
        PARTNER(SPECIES_KADABRA) { Moves(MOVE_CELEBRATE); }
        PARTNER(SPECIES_ALAKAZAM) { Moves(MOVE_CELEBRATE); }
        PARTNER(SPECIES_WYNAUT) { Moves(MOVE_CELEBRATE); }
        PARTNER(SPECIES_HYPNO) { Moves(MOVE_CELEBRATE); }

        OPPONENT_A(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); HP(1); Status1(STATUS1_POISON); }
        OPPONENT_A(SPECIES_ABRA) { Moves(MOVE_CELEBRATE); HP(1); Status1(STATUS1_POISON); }
        OPPONENT_A(SPECIES_KADABRA) { Moves(MOVE_CELEBRATE); HP(1); Status1(STATUS1_POISON); }
        OPPONENT_A(SPECIES_ALAKAZAM) { Moves(MOVE_CELEBRATE); HP(1); Status1(STATUS1_POISON); }
        OPPONENT_A(SPECIES_WYNAUT) { Moves(MOVE_CELEBRATE); HP(1); Status1(STATUS1_POISON); }
        OPPONENT_A(SPECIES_HYPNO) { Moves(MOVE_CELEBRATE); HP(1); Status1(STATUS1_POISON); }

        OPPONENT_B(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT_B(SPECIES_ABRA) { Moves(MOVE_CELEBRATE); }
        OPPONENT_B(SPECIES_KADABRA) { Moves(MOVE_CELEBRATE); }
        OPPONENT_B(SPECIES_ALAKAZAM) { Moves(MOVE_CELEBRATE); }
        OPPONENT_B(SPECIES_WYNAUT) { Moves(MOVE_CELEBRATE); }
        OPPONENT_B(SPECIES_HYPNO) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { EXPECT_MOVE(playerRight, MOVE_CELEBRATE); } // Set controller to AI rather than recorded
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        MESSAGE("Un Hypnomade est envoyé\npar " AI_TRAINER_NAME  "!");
        MESSAGE("Un Okéoké est envoyé\npar " AI_TRAINER_NAME  "!");
        MESSAGE("Un Alakazam est envoyé\npar " AI_TRAINER_NAME  "!");
        MESSAGE("Un Kadabra est envoyé\npar " AI_TRAINER_NAME  "!");
        MESSAGE("Un Abra est envoyé\npar " AI_TRAINER_NAME  "!");
    }
}

AI_MULTI_BATTLE_TEST("12v12: AI can use all 6 party slots in a 12v12 (battler 2)")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);

        PLAYER(SPECIES_WOBBUFFET);

        PARTNER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); HP(1); Status1(STATUS1_POISON); }
        PARTNER(SPECIES_ABRA) { Moves(MOVE_CELEBRATE); HP(1); Status1(STATUS1_POISON); }
        PARTNER(SPECIES_KADABRA) { Moves(MOVE_CELEBRATE); HP(1); Status1(STATUS1_POISON); }
        PARTNER(SPECIES_ALAKAZAM) { Moves(MOVE_CELEBRATE); HP(1); Status1(STATUS1_POISON); }
        PARTNER(SPECIES_WYNAUT) { Moves(MOVE_CELEBRATE); HP(1); Status1(STATUS1_POISON); }
        PARTNER(SPECIES_HYPNO) { Moves(MOVE_CELEBRATE); HP(1); Status1(STATUS1_POISON); }

        OPPONENT_A(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT_A(SPECIES_ABRA) { Moves(MOVE_CELEBRATE); }
        OPPONENT_A(SPECIES_KADABRA) { Moves(MOVE_CELEBRATE); }
        OPPONENT_A(SPECIES_ALAKAZAM) { Moves(MOVE_CELEBRATE); }
        OPPONENT_A(SPECIES_WYNAUT) { Moves(MOVE_CELEBRATE); }
        OPPONENT_A(SPECIES_HYPNO) { Moves(MOVE_CELEBRATE); }

        OPPONENT_B(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT_B(SPECIES_ABRA) { Moves(MOVE_CELEBRATE); }
        OPPONENT_B(SPECIES_KADABRA) { Moves(MOVE_CELEBRATE); }
        OPPONENT_B(SPECIES_ALAKAZAM) { Moves(MOVE_CELEBRATE); }
        OPPONENT_B(SPECIES_WYNAUT) { Moves(MOVE_CELEBRATE); }
        OPPONENT_B(SPECIES_HYPNO) { Moves(MOVE_CELEBRATE); }
    } WHEN {
        TURN { EXPECT_MOVE(playerRight, MOVE_CELEBRATE); } // Set controller to AI rather than recorded
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        MESSAGE("Hypnomade est envoyé par\n" AI_PARTNER_NAME  "!");
        MESSAGE("Okéoké est envoyé par\n" AI_PARTNER_NAME  "!");
        MESSAGE("Alakazam est envoyé par\n" AI_PARTNER_NAME  "!");
        MESSAGE("Kadabra est envoyé par\n" AI_PARTNER_NAME  "!");
        MESSAGE("Abra est envoyé par\n" AI_PARTNER_NAME  "!");
    }
}

AI_MULTI_BATTLE_TEST("12v12: AI can use all 6 party slots in a 12v12 (battler 3)")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);

        PLAYER(SPECIES_WOBBUFFET);

        PARTNER(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        PARTNER(SPECIES_ABRA) { Moves(MOVE_CELEBRATE); }
        PARTNER(SPECIES_KADABRA) { Moves(MOVE_CELEBRATE); }
        PARTNER(SPECIES_ALAKAZAM) { Moves(MOVE_CELEBRATE); }
        PARTNER(SPECIES_WYNAUT) { Moves(MOVE_CELEBRATE); }
        PARTNER(SPECIES_HYPNO) { Moves(MOVE_CELEBRATE); }

        OPPONENT_A(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); }
        OPPONENT_A(SPECIES_ABRA) { Moves(MOVE_CELEBRATE); }
        OPPONENT_A(SPECIES_KADABRA) { Moves(MOVE_CELEBRATE); }
        OPPONENT_A(SPECIES_ALAKAZAM) { Moves(MOVE_CELEBRATE); }
        OPPONENT_A(SPECIES_WYNAUT) { Moves(MOVE_CELEBRATE); }
        OPPONENT_A(SPECIES_HYPNO) { Moves(MOVE_CELEBRATE); }

        OPPONENT_B(SPECIES_WOBBUFFET) { Moves(MOVE_CELEBRATE); HP(1); Status1(STATUS1_POISON); }
        OPPONENT_B(SPECIES_ABRA) { Moves(MOVE_CELEBRATE); HP(1); Status1(STATUS1_POISON); }
        OPPONENT_B(SPECIES_KADABRA) { Moves(MOVE_CELEBRATE); HP(1); Status1(STATUS1_POISON); }
        OPPONENT_B(SPECIES_ALAKAZAM) { Moves(MOVE_CELEBRATE); HP(1); Status1(STATUS1_POISON); }
        OPPONENT_B(SPECIES_WYNAUT) { Moves(MOVE_CELEBRATE); HP(1); Status1(STATUS1_POISON); }
        OPPONENT_B(SPECIES_HYPNO) { Moves(MOVE_CELEBRATE); HP(1); Status1(STATUS1_POISON); }
    } WHEN {
        TURN { EXPECT_MOVE(playerRight, MOVE_CELEBRATE); } // Set controller to AI rather than recorded
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        MESSAGE("Un Hypnomade est envoyé\npar " AI_TRAINER_2_NAME  "!");
        MESSAGE("Un Okéoké est envoyé\npar " AI_TRAINER_2_NAME  "!");
        MESSAGE("Un Alakazam est envoyé\npar " AI_TRAINER_2_NAME  "!");
        MESSAGE("Un Kadabra est envoyé\npar " AI_TRAINER_2_NAME  "!");
        MESSAGE("Un Abra est envoyé\npar " AI_TRAINER_2_NAME  "!");
    }
}

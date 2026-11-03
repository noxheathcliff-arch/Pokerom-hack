#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Rapid Spin activates after Toxic Debris")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_RAPID_SPIN) == EFFECT_RAPID_SPIN);
        PLAYER(SPECIES_GLIMMORA) { Ability(ABILITY_TOXIC_DEBRIS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_RAPID_SPIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAPID_SPIN, opponent);
        ABILITY_POPUP(player, ABILITY_TOXIC_DEBRIS);
        MESSAGE("Il n'y a plus de pics toxiques autour de l'équipe ennemie!");
    }
}

SINGLE_BATTLE_TEST("Rapid Spin blows away Wrap, hazards and raises Speed (Gen 8+)")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_RAPID_SPIN) == EFFECT_RAPID_SPIN);
        #if B_SPEED_BUFFING_RAPID_SPIN >= GEN_8
        ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_RAPID_SPIN, self: TRUE, speed: 1);
        #endif
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_WRAP); }
        TURN { MOVE(opponent, MOVE_STEALTH_ROCK); MOVE(player, MOVE_RAPID_SPIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAPID_SPIN, player);
    #if B_SPEED_BUFFING_RAPID_SPIN >= GEN_8
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Ah, Vitesse du Qulbutoké augmente!");
    #endif
        MESSAGE("Qulbutoké se libère de Ligotage!");
        MESSAGE("Les pierres pointues autour de votre équipe ont disparu!");
    }
}

SINGLE_BATTLE_TEST("Rapid Spin: Mortal Spin blows away Wrap, hazards and poisons foe")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_MORTAL_SPIN) == EFFECT_RAPID_SPIN);
        ASSUME(MoveHasAdditionalEffect(MOVE_MORTAL_SPIN, MOVE_EFFECT_POISON) == TRUE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_WRAP); }
        TURN { MOVE(opponent, MOVE_STEALTH_ROCK); MOVE(player, MOVE_MORTAL_SPIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MORTAL_SPIN, player);
        MESSAGE("Qulbutoké ennemi est empoisonné!");
        STATUS_ICON(opponent, poison: TRUE);
        MESSAGE("Qulbutoké se libère de Ligotage!");
        MESSAGE("Les pierres pointues autour de votre équipe ont disparu!");
    }
}

SINGLE_BATTLE_TEST("Rapid Spin blows away all hazards")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_RAPID_SPIN) == EFFECT_RAPID_SPIN);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_STEALTH_ROCK); }
        TURN { MOVE(opponent, MOVE_STICKY_WEB); }
        TURN { MOVE(opponent, MOVE_TOXIC_SPIKES); }
        TURN { MOVE(opponent, MOVE_SPIKES); MOVE(player, MOVE_RAPID_SPIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAPID_SPIN, player);

        MESSAGE("Il n'y a plus de picots autour de votre équipe!");
        MESSAGE("La toile gluante du côté de votre équipe a disparu!");
        MESSAGE("Il n'y a plus de pics toxiques autour de votre équipe!");
        MESSAGE("Les pierres pointues autour de votre équipe ont disparu!");
    } THEN {
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][0], HAZARDS_NONE);
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][1], HAZARDS_NONE);
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][2], HAZARDS_NONE);
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][3], HAZARDS_NONE);
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][4], HAZARDS_NONE);
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][5], HAZARDS_NONE);
    }
}

TO_DO_BATTLE_TEST("Rapid Spin blows away Wrap, hazards, but doesn't raise Speed when Sheer Force boosted (Gen 8)");

SINGLE_BATTLE_TEST("Rapid Spin doesn't blow away Wrap, hazards or raise Speed when Sheer Force boosted (Gen 9+)")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_RAPID_SPIN) == EFFECT_RAPID_SPIN);
        #if B_SPEED_BUFFING_RAPID_SPIN >= GEN_8
        ASSUME_MOVE_EFFECT_STAT_CHANGE(MOVE_RAPID_SPIN, self: TRUE, speed: 1);
        #endif
        PLAYER(SPECIES_TAUROS) { Ability(ABILITY_SHEER_FORCE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_WRAP); }
        TURN { MOVE(opponent, MOVE_STEALTH_ROCK); MOVE(player, MOVE_RAPID_SPIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAPID_SPIN, player);
        NONE_OF {
        #if B_SPEED_BUFFING_RAPID_SPIN >= GEN_8
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
            MESSAGE("Ah, Vitesse du Tauros augmente!");
        #endif
            MESSAGE("Tauros est libéré de Ligotage!");
            MESSAGE("Les pierres pointues autour de votre équipe ont disparu!");
        }
    }
}

SINGLE_BATTLE_TEST("Rapid Spin and Mortal Spin will remove hazards if the target is behind a Substitute")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_RAPID_SPIN; }
    PARAMETRIZE { move = MOVE_MORTAL_SPIN; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_STEALTH_ROCK); }
        TURN { MOVE(player, MOVE_SUBSTITUTE); MOVE(opponent, move); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, player);
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        SUB_HIT(player);
        NOT HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Rapid Spin and Mortal Spin remove Leech Seed")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_RAPID_SPIN; }
    PARAMETRIZE { move = MOVE_MORTAL_SPIN; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_LEECH_SEED); MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LEECH_SEED, opponent);
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        MESSAGE("Qulbutoké s'est débarrassé de Vampigraine!");
    }
}

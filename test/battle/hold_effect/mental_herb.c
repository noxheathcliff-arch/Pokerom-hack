#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_MENTAL_HERB].holdEffect == HOLD_EFFECT_MENTAL_HERB);
}

SINGLE_BATTLE_TEST("Mental Herb cures infatuation")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_ATTRACT) == EFFECT_ATTRACT);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_MENTAL_HERB); Gender(MON_MALE); }
        OPPONENT(SPECIES_WOBBUFFET) { Gender(MON_FEMALE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ATTRACT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ATTRACT, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Herbe Mental de Qulbutoké fait faner son amour!");
    } THEN {
        EXPECT(player->volatiles.infatuation == 0);
    }
}

SINGLE_BATTLE_TEST("Mental Herb cures Torment volatile status (Gen 5+)")
{
    GIVEN {
        WITH_CONFIG(B_MENTAL_HERB, GEN_5);
        ASSUME(GetMoveEffect(MOVE_TORMENT) == EFFECT_TORMENT);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_MENTAL_HERB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TORMENT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TORMENT, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Les tourments de Qulbutoké sont apaisés!");
    } THEN {
        EXPECT(player->volatiles.torment == FALSE);
    }
}

SINGLE_BATTLE_TEST("Mental Herb clears the Torment timer set by G-Max Meltdown (Gen 5+)")
{
    GIVEN {
        WITH_CONFIG(B_MENTAL_HERB, GEN_5);
        ASSUME(MoveHasAdditionalEffect(MOVE_G_MAX_MELTDOWN, MOVE_EFFECT_TORMENT_SIDE));
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_MENTAL_HERB); }
        OPPONENT(SPECIES_MELMETAL) { GigantamaxFactor(TRUE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_IRON_HEAD, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_G_MAX_MELTDOWN, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Les tourments de Qulbutoké sont apaisés!");
    } THEN {
        EXPECT(player->volatiles.torment == FALSE);
        EXPECT(player->volatiles.tormentTimer == 0);
    }
}

SINGLE_BATTLE_TEST("Mental Herb cures Disable volatile status (Gen 5+)")
{
    GIVEN {
        WITH_CONFIG(B_MENTAL_HERB, GEN_5);
        ASSUME(GetMoveEffect(MOVE_DISABLE) == EFFECT_DISABLE);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_MENTAL_HERB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(opponent, MOVE_DISABLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DISABLE, opponent);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("La capacité de Qulbutoké n'est plus sous entrave!");
    } THEN {
        EXPECT(player->volatiles.disabledMove == MOVE_NONE);
        EXPECT(player->volatiles.disableTimer == 0);
    }
}

SINGLE_BATTLE_TEST("Mental Herb cures Heal Block volatile status (Gen 5+)")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_HEAL_BLOCK; }
    PARAMETRIZE { move = MOVE_PSYCHIC_NOISE; }

    GIVEN {
        WITH_CONFIG(B_MENTAL_HERB, GEN_5);
        ASSUME(GetMoveEffect(MOVE_HEAL_BLOCK) == EFFECT_HEAL_BLOCK);
        ASSUME(MoveHasAdditionalEffect(MOVE_PSYCHIC_NOISE, MOVE_EFFECT_PSYCHIC_NOISE));
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_MENTAL_HERB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        MESSAGE("Qulbutoké ne peut pas guérir!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Le blocage de soins qui affectait Qulbutoké s'est dissipé!");
    } THEN {
        EXPECT(player->volatiles.healBlock == FALSE);
        EXPECT(player->volatiles.healBlockTimer == 0);
    }
}

SINGLE_BATTLE_TEST("Mental Herb cures Encore volatile status (Gen 5+)")
{
    GIVEN {
        WITH_CONFIG(B_MENTAL_HERB, GEN_5);
        ASSUME(GetMoveEffect(MOVE_ENCORE) == EFFECT_ENCORE);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_MENTAL_HERB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_ENCORE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ENCORE, opponent);
        MESSAGE("Qulbutoké! Encore une fois!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Qulbutoké n'est plus obligé d'utiliser la même capacité!");
    } THEN {
        EXPECT(player->volatiles.encoredMove == MOVE_NONE);
        EXPECT(player->volatiles.encoreTimer == 0);
    }
}

SINGLE_BATTLE_TEST("Mental Herb cures Taunt volatile status (Gen 5+)")
{
    GIVEN {
        WITH_CONFIG(B_MENTAL_HERB, GEN_5);
        ASSUME(GetMoveEffect(MOVE_TAUNT) == EFFECT_TAUNT);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_MENTAL_HERB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TAUNT); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAUNT, opponent);
        MESSAGE("Qulbutoké répond à la Provoc!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Qulbutoké s'est remis de la Provoc!");
    } THEN {
        EXPECT(player->volatiles.tauntTimer == 0);
    }
}

DOUBLE_BATTLE_TEST("Mental Herb cures volatile statuses in the following order - Infatuation, Torment, Disable, Heal Block, Encore, Taunt (Gen 5+)")
{
    GIVEN {
        WITH_CONFIG(B_MENTAL_HERB, GEN_5);
        PLAYER(SPECIES_WOBBUFFET) { Gender(MON_MALE); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Gender(MON_FEMALE); }
        OPPONENT(SPECIES_WYNAUT) { Item(ITEM_MENTAL_HERB); };
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_CELEBRATE);
               MOVE(opponentLeft, MOVE_HEAL_BLOCK, target: playerLeft);
               MOVE(playerRight, MOVE_DISABLE, target: playerLeft);
               MOVE(opponentRight, MOVE_TORMENT, target: playerLeft); }
        TURN { MOVE(playerLeft, MOVE_SPLASH);
               MOVE(opponentLeft, MOVE_CELEBRATE);
               MOVE(playerRight, MOVE_CELEBRATE);
               MOVE(opponentRight, MOVE_TAUNT, target: playerLeft); }
        TURN { MOVE(playerLeft, MOVE_POUND, target: opponentRight);
               MOVE(opponentLeft, MOVE_ATTRACT, target: playerLeft);
               MOVE(playerRight, MOVE_ENCORE, target: playerLeft);
               MOVE(opponentRight, MOVE_TRICK, target: playerLeft); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, playerLeft);
        MESSAGE("Herbe Mental de Qulbutoké fait faner son amour!");
        MESSAGE("Les tourments de Qulbutoké sont apaisés!");
        MESSAGE("La capacité de Qulbutoké n'est plus sous entrave!");
        MESSAGE("Le blocage de soins qui affectait Qulbutoké s'est dissipé!");
        MESSAGE("Qulbutoké n'est plus obligé d'utiliser la même capacité!");
        MESSAGE("Qulbutoké s'est remis de la Provoc!");
    } THEN {
        EXPECT(playerLeft->volatiles.infatuation == 0);
        EXPECT(playerLeft->volatiles.torment == FALSE);
        EXPECT(playerLeft->volatiles.disabledMove == MOVE_NONE);
        EXPECT(playerLeft->volatiles.disableTimer == 0);
        EXPECT(playerLeft->volatiles.healBlock == FALSE);
        EXPECT(playerLeft->volatiles.healBlockTimer == 0);
        EXPECT(playerLeft->volatiles.encoredMove == MOVE_NONE);
        EXPECT(playerLeft->volatiles.encoreTimer == 0);
        EXPECT(playerLeft->volatiles.tauntTimer == 0);
    }
}

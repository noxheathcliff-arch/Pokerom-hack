#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_METRONOME) == EFFECT_METRONOME);
}

SINGLE_BATTLE_TEST("Metronome picks a random move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_METRONOME, WITH_RNG(RNG_METRONOME, MOVE_SCRATCH)); }
    } SCENE {
        MESSAGE("Qulbutoké utilise\nMétronome!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_METRONOME, player);
        MESSAGE("Métronome lance la capacité Griffe!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Metronome's called powder move fails against Grass Types")
{
    GIVEN {
        WITH_CONFIG(B_POWDER_GRASS, GEN_6);
        ASSUME(IsPowderMove(MOVE_POISON_POWDER));
        ASSUME(GetSpeciesType(SPECIES_TANGELA, 0) == TYPE_GRASS);
        ASSUME(GetMoveEffect(MOVE_POISON_POWDER) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_POISON_POWDER) == MOVE_EFFECT_POISON);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_TANGELA);
    } WHEN {
        TURN { MOVE(player, MOVE_METRONOME, WITH_RNG(RNG_METRONOME, MOVE_POISON_POWDER)); }
    } SCENE {
        MESSAGE("Qulbutoké utilise\nMétronome!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_METRONOME, player);
        MESSAGE("Métronome lance la capacité Poudre Toxik!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_POISON_POWDER, player);
        MESSAGE("Ça n'affecte pas Saquedeneu ennemi…");
        NOT STATUS_ICON(opponent, poison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Metronome's called multi-hit move hits multiple times")
{
    GIVEN {
        ASSUME(IsMultiHitMove(MOVE_ROCK_BLAST));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_METRONOME, WITH_RNG(RNG_METRONOME, MOVE_ROCK_BLAST)); }
    } SCENE {
        MESSAGE("Qulbutoké utilise\nMétronome!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_METRONOME, player);
        MESSAGE("Métronome lance la capacité Boule Roc!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_BLAST, player);
        HP_BAR(opponent);
        MESSAGE("Touché 5 fois!");
    }
}

DOUBLE_BATTLE_TEST("Metronome's called spread move does not hit the user's partner")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_SWIFT) == TARGET_BOTH);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_METRONOME, WITH_RNG(RNG_METRONOME, MOVE_SWIFT)); }
    } SCENE {
        MESSAGE("Qulbutoké utilise\nMétronome!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_METRONOME, playerLeft);
        MESSAGE("Métronome lance la capacité Météores!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SWIFT, playerLeft);
        HP_BAR(opponentLeft);
        NOT HP_BAR(playerRight);
        HP_BAR(opponentRight);
    } THEN {
        EXPECT_EQ(playerRight->hp, playerRight->maxHP);
        EXPECT_LT(opponentLeft->hp, opponentLeft->maxHP);
        EXPECT_LT(opponentRight->hp, opponentRight->maxHP);
    }
}

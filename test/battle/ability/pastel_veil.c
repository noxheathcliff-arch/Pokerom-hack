#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_TOXIC) == EFFECT_NON_VOLATILE_STATUS);
    ASSUME(GetMoveNonVolatileStatus(MOVE_TOXIC) == MOVE_EFFECT_TOXIC);
}

SINGLE_BATTLE_TEST("Pastel Veil prevents Poison Sting poison")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_POISON_STING, MOVE_EFFECT_POISON) == TRUE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PONYTA_GALAR) { Ability(ABILITY_PASTEL_VEIL); }
    } WHEN {
        TURN { MOVE(player, MOVE_POISON_STING); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POISON_STING, player);
        NOT STATUS_ICON(opponent, poison: TRUE);
    }
}

DOUBLE_BATTLE_TEST("Pastel Veil prevents Poison Sting poison on partner")
{
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_POISON_STING, MOVE_EFFECT_POISON) == TRUE);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_PONYTA_GALAR) { Ability(ABILITY_PASTEL_VEIL); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_POISON_STING, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_POISON_STING, playerLeft);
        NOT STATUS_ICON(opponentRight, poison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Pastel Veil immediately cures Mold Breaker poison")
{
    GIVEN {
        PLAYER(SPECIES_PINSIR) { Ability(ABILITY_MOLD_BREAKER); }
        OPPONENT(SPECIES_PONYTA_GALAR) { Ability(ABILITY_PASTEL_VEIL); }
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, player);
        STATUS_ICON(opponent, badPoison: TRUE);
        ABILITY_POPUP(opponent, ABILITY_PASTEL_VEIL);
        MESSAGE("Ponyta ennemi n'est plus empoisonné!");
        STATUS_ICON(opponent, none: TRUE);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
    }
}

DOUBLE_BATTLE_TEST("Pastel Veil does not cure Mold Breaker poison on partner")
{
    GIVEN {
        PLAYER(SPECIES_PINSIR) { Ability(ABILITY_MOLD_BREAKER); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_PONYTA_GALAR) { Ability(ABILITY_PASTEL_VEIL); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TOXIC, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, playerLeft, target: opponentRight);
        STATUS_ICON(opponentRight, badPoison: TRUE);
        NOT STATUS_ICON(opponentRight, none: TRUE);
    }
}

SINGLE_BATTLE_TEST("Pastel Veil prevents Toxic bad poison")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PONYTA_GALAR) { Ability(ABILITY_PASTEL_VEIL); }
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC); }
    } SCENE {
        MESSAGE("Qulbutoké utilise\nToxik!");
        ABILITY_POPUP(opponent, ABILITY_PASTEL_VEIL);
        MESSAGE("Ça n'affecte pas Ponyta ennemi…");
        NOT STATUS_ICON(opponent, badPoison: TRUE);
    }
}

DOUBLE_BATTLE_TEST("Pastel Veil prevents Toxic bad poison on partner - right target")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_PONYTA_GALAR) { Ability(ABILITY_PASTEL_VEIL); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TOXIC, target: opponentRight); }
    } SCENE {
        MESSAGE("Qulbutoké utilise\nToxik!");
        ABILITY_POPUP(opponentLeft, ABILITY_PASTEL_VEIL);
        MESSAGE("Ça n'affecte pas Okéoké ennemi…");
        NOT STATUS_ICON(opponentRight, badPoison: TRUE);
    }
}

DOUBLE_BATTLE_TEST("Pastel Veil prevents Toxic bad poison on partner - left target")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_PONYTA_GALAR) { Ability(ABILITY_PASTEL_VEIL); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TOXIC, target: opponentLeft); }
    } SCENE {
        MESSAGE("Qulbutoké utilise\nToxik!");
        ABILITY_POPUP(opponentRight, ABILITY_PASTEL_VEIL);
        MESSAGE("Ça n'affecte pas Okéoké ennemi…");
        NOT STATUS_ICON(opponentLeft, badPoison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Pastel Veil prevents Toxic Spikes poison")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TOXIC_SPIKES) == EFFECT_TOXIC_SPIKES);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PONYTA_GALAR) { Ability(ABILITY_PASTEL_VEIL); }
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC_SPIKES); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        MESSAGE("2 envoie\nun Ponyta!");
        NOT STATUS_ICON(opponent, poison: TRUE);
    }
}

DOUBLE_BATTLE_TEST("Pastel Veil prevents Toxic Spikes poison on partner")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_TOXIC_SPIKES) == EFFECT_TOXIC_SPIKES);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_PONYTA_GALAR) { Ability(ABILITY_PASTEL_VEIL); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TOXIC_SPIKES); }
        TURN { SWITCH(opponentRight, 2); }
    } SCENE {
        MESSAGE("2 envoie\nun Okéoké!");
        NOT STATUS_ICON(opponentRight, poison: TRUE);
    }
}

DOUBLE_BATTLE_TEST("Pastel Veil cures partner's poison on initial switch in")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_PONYTA_GALAR) { Ability(ABILITY_PASTEL_VEIL); }
    } WHEN {
        TURN {}
    } SCENE {
        MESSAGE("2 envoie\nun Qulbutoké et un Ponyta!");
        ABILITY_POPUP(opponentRight, ABILITY_PASTEL_VEIL);
        MESSAGE("Qulbutoké ennemi n'est plus empoisonné!");
        STATUS_ICON(opponentLeft, none: TRUE);
    }
}

DOUBLE_BATTLE_TEST("Pastel Veil cures partner's poison on switch in")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_POISON); }
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_PONYTA_GALAR) { Ability(ABILITY_PASTEL_VEIL); }
    } WHEN {
        TURN { SWITCH(opponentRight, 2); }
    } SCENE {
        MESSAGE("2 envoie\nun Ponyta!");
        ABILITY_POPUP(opponentRight, ABILITY_PASTEL_VEIL);
        MESSAGE("Qulbutoké ennemi n'est plus empoisonné!");
        STATUS_ICON(opponentLeft, none: TRUE);
    }
}

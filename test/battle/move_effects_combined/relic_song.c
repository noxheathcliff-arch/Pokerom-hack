#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_RELIC_SONG, MOVE_EFFECT_SLEEP) == TRUE);
}

SINGLE_BATTLE_TEST("Relic Song has a 10% chance to put the target to sleep")
{
    PASSES_RANDOMLY(10, 100, RNG_SECONDARY_EFFECT);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_RELIC_SONG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RELIC_SONG, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        STATUS_ICON(opponent, sleep: TRUE);
    }
}

SINGLE_BATTLE_TEST("Relic Song is prevented by Soundproof")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_VOLTORB) { Ability(ABILITY_SOUNDPROOF); }
    } WHEN {
        TURN { MOVE(player, MOVE_RELIC_SONG); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_SOUNDPROOF);
        MESSAGE("Ça n'affecte pas Voltorbe ennemi…");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_RELIC_SONG, player);
            HP_BAR(opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Relic Song will become a Water-type move when used by a Pokémon with the Ability Liquid Voice")
{
    GIVEN {
        PLAYER(SPECIES_VULPIX);
        OPPONENT(SPECIES_POPPLIO) { Ability(ABILITY_LIQUID_VOICE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_RELIC_SONG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RELIC_SONG, opponent);
        HP_BAR(player);
        MESSAGE("C'est super efficace!");
    }
}

SINGLE_BATTLE_TEST("Relic Song is blocked by Throat Chop")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_THROAT_CHOP); MOVE(player, MOVE_RELIC_SONG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THROAT_CHOP, opponent);
        HP_BAR(player);
        MESSAGE("Exécu-Son empêche Qulbutoké d'utiliser cette capacité!\p");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_RELIC_SONG, player);
    }
}

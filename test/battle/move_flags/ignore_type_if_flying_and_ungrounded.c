#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Thousand Arrows does neutral damage to non-grounded Flying types regardless of other typings")
{
    u32 pokemon;
    PARAMETRIZE { pokemon = SPECIES_SKARMORY; }
    PARAMETRIZE { pokemon = SPECIES_SCYTHER; }
    GIVEN {
        ASSUME(MoveIgnoresTypeIfFlyingAndUngrounded(MOVE_THOUSAND_ARROWS) == TRUE);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(pokemon);
    } WHEN {
        TURN { MOVE(player, MOVE_THOUSAND_ARROWS); }
        TURN { MOVE(player, MOVE_THOUSAND_ARROWS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THOUSAND_ARROWS, player);
        if (pokemon == SPECIES_SKARMORY) {
            MESSAGE("Airmure ennemi s'écrase au sol!");
            MESSAGE("Airmure ennemi utilise\nCélébration!");
        } else {
            MESSAGE("Insécateur ennemi s'écrase au sol!");
            MESSAGE("Insécateur ennemi utilise\nCélébration!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponent);
        MESSAGE("Félicitations, 1!");
        MESSAGE("Qulbutoké utilise\nMyria-Flèches!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THOUSAND_ARROWS, player);
        if (pokemon == SPECIES_SKARMORY)
        {
            MESSAGE("C'est super efficace!");
        }
        else
        {
            MESSAGE("Ce n'est pas très efficace…");
        }
    }
}

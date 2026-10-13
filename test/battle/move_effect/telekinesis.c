#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_TELEKINESIS) == EFFECT_TELEKINESIS);
}

SINGLE_BATTLE_TEST("Telekinesis makes the target unable to avoid any attacks made against it")
{
    GIVEN {
        #if B_MINIMIZE_EVASION >= GEN_5
        ASSUME_STAT_CHANGE(MOVE_MINIMIZE, evasion: +2);
        #else
        ASSUME_STAT_CHANGE(MOVE_MINIMIZE, evasion: +1);
        #endif
        ASSUME(GetMoveAccuracy(MOVE_SCREECH) < 100);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_TELEKINESIS); MOVE(opponent, MOVE_MINIMIZE); }
        TURN { MOVE(player, MOVE_SCREECH, hit:FALSE); }
    } SCENE {
        MESSAGE("Qulbutoké utilise\nLévikinésie!");
        MESSAGE("Okéoké ennemi est emporté haut dans le ciel!");
        MESSAGE("Okéoké ennemi utilise\nLilliput!");
        MESSAGE("Qulbutoké utilise\nGrincement!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCREECH, player);
        NOT MESSAGE("Okéoké ennemi évite l'attaque!");
    }
}

SINGLE_BATTLE_TEST("Telekinesis ends after 3 turns")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_TELEKINESIS); }
        TURN {}
        TURN {}
    } SCENE {
        MESSAGE("Qulbutoké utilise\nLévikinésie!");
        MESSAGE("Okéoké ennemi est emporté haut dans le ciel!");
        MESSAGE("Qulbutoké utilise\nCélébration!");
        MESSAGE("Qulbutoké utilise\nCélébration!");
        MESSAGE("Okéoké ennemi est libéré de la capacité Lévikinésie!");
    }
}

SINGLE_BATTLE_TEST("Telekinesis makes the target immune to Ground-type attacks")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_BULLDOZE) == TYPE_GROUND);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_BULLDOZE); }
        TURN { MOVE(player, MOVE_TELEKINESIS); }
        TURN { MOVE(player, MOVE_BULLDOZE); }
    } SCENE {
        MESSAGE("Qulbutoké utilise\nPiétisol!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLDOZE, player);
        HP_BAR(opponent);
        MESSAGE("Qulbutoké utilise\nLévikinésie!");
        MESSAGE("Okéoké ennemi est emporté haut dans le ciel!");
        MESSAGE("Qulbutoké utilise\nPiétisol!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_BULLDOZE, player);
            HP_BAR(opponent);
        }
        MESSAGE("Ça n'affecte pas Okéoké ennemi…");
    }
}

TO_DO_BATTLE_TEST("Baton Pass passes Telekinesis' effect");
//Bulbapedia doesn't confirm what happens with Diglett, Dugtrio, Sandygast and Palossand, so it needs to be tested in-game.
TO_DO_BATTLE_TEST("Baton Pass removes Telekinesis' effect disappears if the switching-in mon is Mega Gengar");

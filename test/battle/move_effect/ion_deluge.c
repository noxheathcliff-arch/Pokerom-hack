#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_ION_DELUGE) == EFFECT_ION_DELUGE);
}

// For some reason SINGLE_BATTLE_TEST didn't catch these two issues.
WILD_BATTLE_TEST("Ion Deluge works the same way as always when used by a mon with Volt Absorb")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_LANTURN) { Ability(ABILITY_VOLT_ABSORB); HP(1); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ION_DELUGE); }
    } SCENE {
        MESSAGE("Lanturn sauvage utilise\nDéluge Plasmique!");
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_VOLT_ABSORB);
            HP_BAR(opponent);
            MESSAGE("Wild Lanturn restored PV using its Vole-Viee-Volt!");
        }
        MESSAGE("Un déluge de plasma s'abat sur le terrain!");
    }
}

WILD_BATTLE_TEST("Ion Deluge works the same way as always when used by a mon with Lightning Rod / Motor Drive")
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_LIGHTNING_ROD; }
    PARAMETRIZE { ability = ABILITY_MOTOR_DRIVE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ZEBSTRIKA) { Ability(ability); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ION_DELUGE); }
    } SCENE {
        MESSAGE("Zéblitz sauvage utilise\nDéluge Plasmique!");
        NONE_OF {
            ABILITY_POPUP(opponent, ability);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("Ah, Attaque Spéciale du Wild Zéblitz augmente!");
            MESSAGE("Ah, Vitesse du Wild Zéblitz augmente!");
        }
        MESSAGE("Un déluge de plasma s'abat sur le terrain!");
    }
}

SINGLE_BATTLE_TEST("Ion Deluge makes Normal type moves Electric type")
{
    GIVEN {
        ASSUME(GetMoveType(MOVE_SCRATCH) == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GOLBAT);
    } WHEN {
        TURN { MOVE(opponent, MOVE_ION_DELUGE); MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Nosferalto ennemi utilise\nDéluge Plasmique!");
        MESSAGE("Un déluge de plasma s'abat sur le terrain!");
        MESSAGE("Qulbutoké utilise\nGriffe!");
        MESSAGE("C'est super efficace!"); // Because Scratch is now electric type.
    }
}

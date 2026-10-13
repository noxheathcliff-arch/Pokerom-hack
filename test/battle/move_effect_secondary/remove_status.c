#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Smelling Salts does not cure paralyzed pokemons behind substitutes or get increased power")
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { ability = ABILITY_INFILTRATOR; }
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_SMELLING_SALTS, MOVE_EFFECT_REMOVE_STATUS) == TRUE);
        ASSUME(GetMoveEffectArg_Status(MOVE_SMELLING_SALTS) == STATUS1_PARALYSIS);
        PLAYER(SPECIES_CROBAT) { Ability(ability); }
        OPPONENT(SPECIES_SEISMITOAD) { Status1(STATUS1_PARALYSIS); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_CELEBRATE); }
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_SMELLING_SALTS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SMELLING_SALTS, player);
        if (ability == ABILITY_INNER_FOCUS)
        {
            MESSAGE("Le clone subit les dégâts à la place de Crapustule ennemi!\p");
            NONE_OF {
                MESSAGE("Le clone de Crapustule ennemi disparaît…\p"); // Smelling Salts does 86 damage, the sub has 122 HP, if hitting a sub it shouldn't get boosted damage.
                MESSAGE("Crapustule ennemi n'est plus paralysé!");
                STATUS_ICON(opponent, none: TRUE);
            }
        }
        else
        {
            MESSAGE("Crapustule ennemi n'est plus paralysé!");
            STATUS_ICON(opponent, none: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Smelling Salts get incread power vs. paralyzed targets")
{
    u32 status1;
    PARAMETRIZE { status1 = STATUS1_PARALYSIS; }
    PARAMETRIZE { status1 = STATUS1_NONE; }
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_SMELLING_SALTS, MOVE_EFFECT_REMOVE_STATUS) == TRUE);
        ASSUME(GetMoveEffectArg_Status(MOVE_SMELLING_SALTS) == STATUS1_PARALYSIS);
        PLAYER(SPECIES_CROBAT);
        OPPONENT(SPECIES_LOTAD) { Status1(status1); }
    } WHEN {
        TURN { MOVE(player, MOVE_SMELLING_SALTS); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SMELLING_SALTS, player);
        if (status1 == STATUS1_PARALYSIS)
        {
            MESSAGE("Nénupiot ennemi est K.O.!\p");
        }
        else
        {
            NOT MESSAGE("Nénupiot ennemi est K.O.!\p");
            MESSAGE("Nénupiot ennemi utilise\nCélébration!");
        }
    }
}

SINGLE_BATTLE_TEST("Wake-Up Slap does not cure paralyzed pokemons behind substitutes or get increased power")
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_INNER_FOCUS; }
    PARAMETRIZE { ability = ABILITY_INFILTRATOR; }
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_WAKE_UP_SLAP, MOVE_EFFECT_REMOVE_STATUS) == TRUE);
        ASSUME(GetMoveEffectArg_Status(MOVE_WAKE_UP_SLAP) == STATUS1_SLEEP);
        PLAYER(SPECIES_CROBAT) { Ability(ability); }
        OPPONENT(SPECIES_SEISMITOAD);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_SING); }
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_WAKE_UP_SLAP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WAKE_UP_SLAP, player);
        if (ability == ABILITY_INNER_FOCUS)
        {
            MESSAGE("Le clone subit les dégâts à la place de Crapustule ennemi!\p");
            NONE_OF {
                MESSAGE("Le clone de Crapustule ennemi disparaît…\p"); // Smelling Salts does 86 damage, the sub has 122 HP, if hitting a sub it shouldn't get boosted damage.
                MESSAGE("Crapustule ennemi se réveille!");
                STATUS_ICON(opponent, none: TRUE);
            }
        }
        else
        {
            MESSAGE("Crapustule ennemi se réveille!");
            STATUS_ICON(opponent, none: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Wake-Up Slap gets increased power against sleeping targets")
{
    u32 status1;
    PARAMETRIZE { status1 = STATUS1_SLEEP; }
    PARAMETRIZE { status1 = STATUS1_NONE; }
    GIVEN {
        ASSUME(MoveHasAdditionalEffect(MOVE_WAKE_UP_SLAP, MOVE_EFFECT_REMOVE_STATUS) == TRUE);
        ASSUME(GetMoveEffectArg_Status(MOVE_WAKE_UP_SLAP) == STATUS1_SLEEP);
        PLAYER(SPECIES_CROBAT);
        OPPONENT(SPECIES_LOTAD) { Status1(status1); }
    } WHEN {
        TURN { MOVE(player, MOVE_WAKE_UP_SLAP); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WAKE_UP_SLAP, player);
        if (status1 == STATUS1_SLEEP)
        {
            MESSAGE("Nénupiot ennemi est K.O.!\p");
        }
        else
        {
            NOT MESSAGE("Nénupiot ennemi est K.O.!\p");
            MESSAGE("Nénupiot ennemi utilise\nCélébration!");
        }
    }
}

TO_DO_BATTLE_TEST("Wake-Up Slap gets increased power against Pokémon with Comatose")

DOUBLE_BATTLE_TEST("Sparkling Aria cures burns from all Pokemon on the field and behind substitutes")
{
    GIVEN {
        ASSUME(MoveIgnoresSubstitute(MOVE_SPARKLING_ARIA));
        ASSUME(MoveHasAdditionalEffect(MOVE_SPARKLING_ARIA, MOVE_EFFECT_REMOVE_STATUS) == TRUE);
        ASSUME(GetMoveEffectArg_Status(MOVE_SPARKLING_ARIA) == STATUS1_BURN);
        PLAYER(SPECIES_PRIMARINA);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WOBBUFFET) { Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_WYNAUT) { Status1(STATUS1_BURN); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SUBSTITUTE); MOVE(opponentRight, MOVE_CELEBRATE); MOVE(playerRight, MOVE_CELEBRATE); MOVE(playerLeft, MOVE_SPARKLING_ARIA); }
    } SCENE {
        MESSAGE("Qulbutoké ennemi n'est plus brûlé!");
        MESSAGE("Qulbutoké n'est plus brûlé!");
        MESSAGE("Okéoké ennemi n'est plus brûlé!");
    }
}

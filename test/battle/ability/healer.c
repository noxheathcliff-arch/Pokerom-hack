#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Healer cures adjacent ally's status condition 30% of the time")
{
    u16 status;
    PARAMETRIZE { status = STATUS1_SLEEP; }
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_BURN; }
    // PARAMETRIZE { status = STATUS1_FREEZE; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { status = STATUS1_FROSTBITE; }
    PASSES_RANDOMLY(30, 100, RNG_HEALER);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Status1(status); }
        OPPONENT(SPECIES_CHANSEY) { Ability(ABILITY_HEALER); }
    } WHEN {
        TURN {}
    } SCENE {
        switch (status)
        {
            case STATUS1_BURN:
                MESSAGE("Qulbutoké ennemi n'est plus brûlé!");
                break;
            case STATUS1_PARALYSIS:
                MESSAGE("Qulbutoké ennemi n'est plus paralysé!");
                break;
            case STATUS1_FROSTBITE:
                MESSAGE("Qulbutoké ennemi s'est remis de sa gelure!");
                break;
            case STATUS1_POISON:
                MESSAGE("Qulbutoké ennemi n'est plus empoisonné!");
                break;
            case STATUS1_TOXIC_POISON:
                MESSAGE("Qulbutoké ennemi n'est plus empoisonné!");
                break;
            case STATUS1_SLEEP:
                MESSAGE("Qulbutoké ennemi se réveille!");
                break;
        }
    }
}

DOUBLE_BATTLE_TEST("Healer cures status condition before burn or poison damage is dealt")
{
    u16 status;
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_BURN; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { status = STATUS1_FROSTBITE; }
    PASSES_RANDOMLY(30, 100, RNG_HEALER);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); Status1(status); }
        OPPONENT(SPECIES_CHANSEY) { Ability(ABILITY_HEALER); }
    } WHEN {
        TURN {}
    } SCENE {
        NOT MESSAGE("Qulbutoké ennemi est K.O.!\p");
        switch (status)
        {
            case STATUS1_POISON:
                MESSAGE("Qulbutoké ennemi n'est plus empoisonné!");
                break;
            case STATUS1_BURN:
                MESSAGE("Qulbutoké ennemi n'est plus brûlé!");
                break;
            case STATUS1_TOXIC_POISON:
                MESSAGE("Qulbutoké ennemi n'est plus empoisonné!");
                break;
            case STATUS1_FROSTBITE:
                MESSAGE("Qulbutoké ennemi s'est remis de sa gelure!");
                break;
        }
    }
}

// Triple battles
TO_DO_BATTLE_TEST("Healer has a 30% chance of curing each of its ally's status conditions independently");

#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Hydration cures non-volatile Status conditions if it is raining")
{
    u32 status;
    enum Move move;
    PARAMETRIZE { status = STATUS1_BURN; }
    PARAMETRIZE { status = STATUS1_NONE; move = MOVE_POWDER_SNOW; } // Freeze
    PARAMETRIZE { status = STATUS1_PARALYSIS; }
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { status = STATUS1_NONE; move = MOVE_SPORE; } // Sleep
    PARAMETRIZE { status = STATUS1_FROSTBITE; }

    GIVEN {
        PLAYER(SPECIES_VAPOREON) { Ability(ABILITY_HYDRATION); Status1(status); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            if (status == STATUS1_NONE)
            {
                MOVE(player, MOVE_RAIN_DANCE); MOVE(opponent, move);
            }
            else
            {
                MOVE(player, MOVE_RAIN_DANCE);
            }
        }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_HYDRATION);
        switch (status)
        {
            case STATUS1_BURN:
                MESSAGE("Aquali n'est plus brûlé!");
                break;
            case STATUS1_PARALYSIS:
                MESSAGE("Aquali n'est plus paralysé!");
                break;
            case STATUS1_POISON:
            case STATUS1_TOXIC_POISON:
                MESSAGE("Aquali n'est plus empoisonné!");
                break;
            case STATUS1_FROSTBITE:
                MESSAGE("Aquali s'est remis de sa gelure!");
                break;
        }
        STATUS_ICON(player, none: TRUE);
    }
}

SINGLE_BATTLE_TEST("Hydration doesn't cure status conditions if Cloud Nine/Air Lock is on the field")
{
    GIVEN {
        PLAYER(SPECIES_VAPOREON) { Ability(ABILITY_HYDRATION); Status1(STATUS1_BURN); }
        OPPONENT(SPECIES_GOLDUCK) { Ability(ABILITY_CLOUD_NINE); }
    } WHEN {
        TURN { MOVE(player, MOVE_RAIN_DANCE); }
    } SCENE {
        NOT ABILITY_POPUP(player, ABILITY_HYDRATION);
        MESSAGE("Aquali souffre de sa brûlure!");
    }
}

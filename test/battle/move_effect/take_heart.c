#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_TAKE_HEART) == EFFECT_TAKE_HEART);
}

SINGLE_BATTLE_TEST("Take Heart increases Sp. Atk and Sp. Def by one stage")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TAKE_HEART); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
    }
}

SINGLE_BATTLE_TEST("Take Heart cures the user of all status conditions")
{
    u32 status1;
    PARAMETRIZE { status1 = STATUS1_SLEEP; }
    PARAMETRIZE { status1 = STATUS1_POISON; }
    PARAMETRIZE { status1 = STATUS1_FREEZE; }
    PARAMETRIZE { status1 = STATUS1_BURN; }
    PARAMETRIZE { status1 = STATUS1_PARALYSIS; }
    PARAMETRIZE { status1 = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { status1 = STATUS1_FROSTBITE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(status1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TAKE_HEART); }
    } SCENE {
        if (status1 == STATUS1_SLEEP) {
            MESSAGE("Qulbutoké dort profondément.");
        } else if (status1 == STATUS1_FREEZE) {
            PASSES_RANDOMLY(20, 100, RNG_FROZEN);
            STATUS_ICON(player, none: TRUE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        } else {
            STATUS_ICON(player, none: TRUE);
            switch (status1)
            {
                case STATUS1_POISON:
                    MESSAGE("Qulbutoké n'est plus empoisonné!");
                    break;
                case STATUS1_BURN:
                    MESSAGE("Qulbutoké n'est plus brûlé!");
                    break;
                case STATUS1_PARALYSIS:
                    MESSAGE("Qulbutoké n'est plus paralysé!");
                    break;
                case STATUS1_TOXIC_POISON:
                    MESSAGE("Qulbutoké n'est plus empoisonné!");
                    break;
                case STATUS1_FROSTBITE:
                    MESSAGE("Qulbutoké s'est remis de sa gelure!");
                    break;
            }
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        }
    }
}

SINGLE_BATTLE_TEST("Take Heart cures sleep when used by Sleep Talk")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SPORE) == EFFECT_NON_VOLATILE_STATUS);
        ASSUME(GetMoveNonVolatileStatus(MOVE_SPORE) == MOVE_EFFECT_SLEEP);
        ASSUME(GetMoveEffect(MOVE_SLEEP_TALK) == EFFECT_SLEEP_TALK);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_SLEEP_TALK, MOVE_TAKE_HEART); }
    } WHEN {
        TURN { MOVE(player, MOVE_SPORE); MOVE(opponent, MOVE_SLEEP_TALK); }
    } SCENE {
        MESSAGE("Qulbutoké utilise\nSpore!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPORE, player);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_SLP, opponent);
        MESSAGE("Qulbutoké ennemi s'est endormi!");
        MESSAGE("Qulbutoké ennemi utilise\nBlabla Dodo!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SLEEP_TALK, opponent);
        MESSAGE("Qulbutoké ennemi utilise\nExtravaillance!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TAKE_HEART, opponent);
        STATUS_ICON(opponent, none: TRUE);
        MESSAGE("Qulbutoké ennemi se réveille!");
    }
}

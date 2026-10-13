#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_FLY) == EFFECT_SEMI_INVULNERABLE);
    ASSUME(GetMoveTwoTurnAttackStatus(MOVE_FLY) == STATE_ON_AIR);
    ASSUME(GetMoveEffect(MOVE_DIG) == EFFECT_SEMI_INVULNERABLE);
    ASSUME(GetMoveTwoTurnAttackStatus(MOVE_DIG) == STATE_UNDERGROUND);
    ASSUME(GetMoveEffect(MOVE_BOUNCE) == EFFECT_SEMI_INVULNERABLE);
    ASSUME(GetMoveTwoTurnAttackStatus(MOVE_BOUNCE) == STATE_ON_AIR);
    ASSUME(GetMoveEffect(MOVE_DIVE) == EFFECT_SEMI_INVULNERABLE);
    ASSUME(GetMoveTwoTurnAttackStatus(MOVE_DIVE) == STATE_UNDERWATER);
    ASSUME(GetMoveEffect(MOVE_PHANTOM_FORCE) == EFFECT_SEMI_INVULNERABLE);
    ASSUME(GetMoveTwoTurnAttackStatus(MOVE_PHANTOM_FORCE) == STATE_PHANTOM_FORCE);
    ASSUME(GetMoveEffect(MOVE_SHADOW_FORCE) == EFFECT_SEMI_INVULNERABLE);
    ASSUME(GetMoveTwoTurnAttackStatus(MOVE_SHADOW_FORCE) == STATE_PHANTOM_FORCE);
}

SINGLE_BATTLE_TEST("Semi-invulnerable moves make the user semi-invulnerable turn 1, then strike turn 2")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_FLY; }
    PARAMETRIZE { move = MOVE_DIG; }
    PARAMETRIZE { move = MOVE_BOUNCE; }
    PARAMETRIZE { move = MOVE_DIVE; }
    PARAMETRIZE { move = MOVE_PHANTOM_FORCE; }
    PARAMETRIZE { move = MOVE_SHADOW_FORCE; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); MOVE(opponent, MOVE_AERIAL_ACE); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        // Charging turn
        if (B_UPDATED_MOVE_DATA >= GEN_5)
        {
            switch (move)
            {
                case MOVE_FLY:
                    NOT MESSAGE("Qulbutoké s'envole!");
                    MESSAGE("Qulbutoké utilise\nVol!");
                    break;
                case MOVE_DIG:
                    NOT MESSAGE("Qulbutoké dug a hole!");
                    MESSAGE("Qulbutoké utilise\nTunnel!");
                    break;
                case MOVE_BOUNCE:
                    NOT MESSAGE("Qulbutoké se propulse dans les airs!");
                    MESSAGE("Qulbutoké utilise\nRebond!");
                    break;
                case MOVE_DIVE:
                    NOT MESSAGE("Qulbutoké se cache sous l'eau!");
                    MESSAGE("Qulbutoké utilise\nPlongée!");
                    break;
                case MOVE_PHANTOM_FORCE:
                    NOT MESSAGE("Qulbutoké disparaît instantanément!");
                    MESSAGE("Qulbutoké utilise\nHantise!");
                    break;
                case MOVE_SHADOW_FORCE:
                    NOT MESSAGE("Qulbutoké disparaît instantanément!");
                    MESSAGE("Qulbutoké utilise\nRevenant!");
                    break;
                default:
                    break;
            }
        } else {
            ANIMATION(ANIM_TYPE_MOVE, move, player);
        }
        if (B_UPDATED_MOVE_DATA < GEN_5)
        {
            switch (move)
            {
                case MOVE_FLY:
                    MESSAGE("Qulbutoké s'envole!");
                    break;
                case MOVE_DIG:
                    MESSAGE("Qulbutoké dug a hole!");
                    break;
                case MOVE_BOUNCE:
                    MESSAGE("Qulbutoké se propulse dans les airs!");
                    break;
                case MOVE_DIVE:
                    MESSAGE("Qulbutoké se cache sous l'eau!");
                    break;
                case MOVE_PHANTOM_FORCE:
                case MOVE_SHADOW_FORCE:
                    MESSAGE("Qulbutoké disparaît instantanément!");
                    break;
                default:
                    break;
            }
        }
        else
            ANIMATION(ANIM_TYPE_MOVE, move, player);

        // Aerial Ace cannot miss unless the target is semi-invulnerable
        MESSAGE("Qulbutoké ennemi utilise\nAéropique!");
        MESSAGE("Qulbutoké évite l'attaque!");
        // Attack turn
        switch (move)
        {
            case MOVE_FLY:
                MESSAGE("Qulbutoké utilise\nVol!");
                break;
            case MOVE_DIG:
                MESSAGE("Qulbutoké utilise\nTunnel!");
                break;
            case MOVE_BOUNCE:
                MESSAGE("Qulbutoké utilise\nRebond!");
                break;
            case MOVE_DIVE:
                MESSAGE("Qulbutoké utilise\nPlongée!");
                break;
            case MOVE_PHANTOM_FORCE:
                MESSAGE("Qulbutoké utilise\nHantise!");
                break;
            case MOVE_SHADOW_FORCE:
                MESSAGE("Qulbutoké utilise\nRevenant!");
                break;
            default:
                break;
        }
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Semi-invulnerable moves don't need to charge with Power Herb")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_FLY; }
    PARAMETRIZE { move = MOVE_DIG; }
    PARAMETRIZE { move = MOVE_BOUNCE; }
    PARAMETRIZE { move = MOVE_DIVE; }
    PARAMETRIZE { move = MOVE_PHANTOM_FORCE; }
    PARAMETRIZE { move = MOVE_SHADOW_FORCE; }

    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_POWER_HERB) == HOLD_EFFECT_POWER_HERB);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_POWER_HERB); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        // Charging turn
        if (B_UPDATED_MOVE_DATA >= GEN_5)
        {
            switch (move)
            {
                case MOVE_FLY:
                    NOT MESSAGE("Qulbutoké s'envole!");
                    MESSAGE("Qulbutoké utilise\nVol!");
                    break;
                case MOVE_DIG:
                    NOT MESSAGE("Qulbutoké dug a hole!");
                    MESSAGE("Qulbutoké utilise\nTunnel!");
                    break;
                case MOVE_BOUNCE:
                    NOT MESSAGE("Qulbutoké se propulse dans les airs!");
                    MESSAGE("Qulbutoké utilise\nRebond!");
                    break;
                case MOVE_DIVE:
                    NOT MESSAGE("Qulbutoké se cache sous l'eau!");
                    MESSAGE("Qulbutoké utilise\nPlongée!");
                    break;
                case MOVE_PHANTOM_FORCE:
                    NOT MESSAGE("Qulbutoké disparaît instantanément!");
                    MESSAGE("Qulbutoké utilise\nHantise!");
                    break;
                case MOVE_SHADOW_FORCE:
                    NOT MESSAGE("Qulbutoké disparaît instantanément!");
                    MESSAGE("Qulbutoké utilise\nRevenant!");
                    break;
                default:
                    break;
            }
        } else {
            ANIMATION(ANIM_TYPE_MOVE, move, player);
        }
        if (B_UPDATED_MOVE_DATA < GEN_5)
        {
            switch (move)
            {
                case MOVE_FLY:
                    MESSAGE("Qulbutoké s'envole!");
                    break;
                case MOVE_DIG:
                    MESSAGE("Qulbutoké dug a hole!");
                    break;
                case MOVE_BOUNCE:
                    MESSAGE("Qulbutoké se propulse dans les airs!");
                    break;
                case MOVE_DIVE:
                    MESSAGE("Qulbutoké se cache sous l'eau!");
                    break;
                case MOVE_PHANTOM_FORCE:
                case MOVE_SHADOW_FORCE:
                    MESSAGE("Qulbutoké disparaît instantanément!");
                    break;
                default:
                    break;
            }
        }
        else
            ANIMATION(ANIM_TYPE_MOVE, move, player);
        MESSAGE("Qulbutoké est complètement chargé grâce à Herbe Pouvoir!");
        if (B_UPDATED_MOVE_DATA < GEN_5)
        {
            switch (move)
            {
                case MOVE_FLY:
                    MESSAGE("Qulbutoké utilise\nVol!");
                    break;
                case MOVE_DIG:
                    MESSAGE("Qulbutoké utilise\nTunnel!");
                    break;
                case MOVE_BOUNCE:
                    MESSAGE("Qulbutoké utilise\nRebond!");
                    break;
                case MOVE_DIVE:
                    MESSAGE("Qulbutoké utilise\nPlongée!");
                    break;
                case MOVE_PHANTOM_FORCE:
                    MESSAGE("Qulbutoké utilise\nHantise!");
                    break;
                case MOVE_SHADOW_FORCE:
                    MESSAGE("Qulbutoké utilise\nRevenant!");
                    break;
                default:
                    break;
            }
        }
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
    }
}

SINGLE_BATTLE_TEST("Power Herb semi-invulnerable moves do not keep the user untargetable that turn")
{
    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_POWER_HERB) == HOLD_EFFECT_POWER_HERB);
        PLAYER(SPECIES_BASCULEGION) { Item(ITEM_POWER_HERB); Speed(20); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(10); }
    } WHEN {
        TURN { MOVE(player, MOVE_PHANTOM_FORCE); MOVE(opponent, MOVE_WATER_GUN); }
    } SCENE {
        NOT MESSAGE("Paragruel disparaît instantanément!");
        MESSAGE("Paragruel utilise\nHantise!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PHANTOM_FORCE, player);
        MESSAGE("Paragruel est complètement chargé grâce à Herbe Pouvoir!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PHANTOM_FORCE, player);
        HP_BAR(opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WATER_GUN, opponent);
        HP_BAR(player);
    }
}

// No way to apply this test with Shadow Force/Phantom Force
SINGLE_BATTLE_TEST("Semi-invulnerable moves apply a status that won't block certain moves")
{
    enum Move move, opMove;

    PARAMETRIZE { move = MOVE_FLY; opMove = MOVE_SKY_UPPERCUT; }
    PARAMETRIZE { move = MOVE_DIG; opMove = MOVE_EARTHQUAKE; }
    PARAMETRIZE { move = MOVE_BOUNCE; opMove = MOVE_THUNDER; }
    PARAMETRIZE { move = MOVE_DIVE; opMove = MOVE_SURF; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); MOVE(opponent, opMove); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        ANIMATION(ANIM_TYPE_MOVE, opMove, opponent);
        HP_BAR(player);
    }
}

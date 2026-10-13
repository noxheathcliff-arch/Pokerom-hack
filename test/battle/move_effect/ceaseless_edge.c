#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_CEASELESS_EDGE) == EFFECT_CEASELESS_EDGE);
}

SINGLE_BATTLE_TEST("Ceaseless Edge sets up hazards after hitting the target")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CEASELESS_EDGE); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        s32 maxHP = GetMonData(&OPPONENT_PARTY[1], MON_DATA_MAX_HP);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CEASELESS_EDGE, player);
        HP_BAR(opponent);
        MESSAGE("Des picots s'éparpillent autour de l'équipe ennemie!");
        MESSAGE("2 envoie\nun Qulbutoké!");
        HP_BAR(opponent, damage: maxHP / 8);
        MESSAGE("Qulbutoké ennemi est blessé par les picots!");
    }
}

SINGLE_BATTLE_TEST("Ceaseless Edge can set up to 3 layers of Spikes")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_CEASELESS_EDGE); }
        TURN { MOVE(player, MOVE_CEASELESS_EDGE); }
        TURN { MOVE(player, MOVE_CEASELESS_EDGE); }
        TURN { MOVE(player, MOVE_CEASELESS_EDGE); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        s32 maxHP = GetMonData(&OPPONENT_PARTY[1], MON_DATA_MAX_HP);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_CEASELESS_EDGE, player);
        HP_BAR(opponent);
        MESSAGE("Des picots s'éparpillent autour de l'équipe ennemie!");

        ANIMATION(ANIM_TYPE_MOVE, MOVE_CEASELESS_EDGE, player);
        HP_BAR(opponent);
        MESSAGE("Des picots s'éparpillent autour de l'équipe ennemie!");

        ANIMATION(ANIM_TYPE_MOVE, MOVE_CEASELESS_EDGE, player);
        HP_BAR(opponent);
        MESSAGE("Des picots s'éparpillent autour de l'équipe ennemie!");

        ANIMATION(ANIM_TYPE_MOVE, MOVE_CEASELESS_EDGE, player);
        HP_BAR(opponent);
        NOT MESSAGE("Des picots s'éparpillent autour de l'équipe ennemie!");

        MESSAGE("2 envoie\nun Okéoké!");
        HP_BAR(opponent, damage: maxHP / 4);
        MESSAGE("Okéoké ennemi est blessé par les picots!");
    }
}

SINGLE_BATTLE_TEST("Ceaseless Edge fails to set up hazards if user faints")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ROCKY_HELMET); }
    } WHEN {
        TURN { MOVE(player, MOVE_CEASELESS_EDGE); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CEASELESS_EDGE, player);
        HP_BAR(player);
        MESSAGE("Qulbutoké est blessé par Casque Brut de Qulbutoké ennemi!");
        NOT MESSAGE("Des picots s'éparpillent autour de l'équipe ennemie!");
    }
}

SINGLE_BATTLE_TEST("Ceaseless Edge does not set up hazards if target was not hit")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT);  MOVE(player, MOVE_CEASELESS_EDGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_CEASELESS_EDGE, player);
            MESSAGE("Des picots s'éparpillent autour de l'équipe ennemie!");
        }
    }
}

SINGLE_BATTLE_TEST("Ceaseless Edge will set up rocks if the target is behind a Substitute")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); MOVE(opponent, MOVE_CEASELESS_EDGE); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CEASELESS_EDGE, opponent);
        SUB_HIT(player);
        HP_BAR(player);
    }
}

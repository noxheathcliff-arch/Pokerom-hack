#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_STONE_AXE) == EFFECT_STONE_AXE);
}

SINGLE_BATTLE_TEST("Stone Axe sets up hazards after hitting the target")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_STONE_AXE); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        s32 maxHP = GetMonData(&OPPONENT_PARTY[1], MON_DATA_MAX_HP);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STONE_AXE, player);
        HP_BAR(opponent);
        MESSAGE("Des pierres pointues lévitent autour de l'équipe ennemie!");
        MESSAGE("2 envoie\nun Qulbutoké!");
        HP_BAR(opponent, damage: maxHP / 8);
        MESSAGE("Des pierres pointues transpercent Qulbutoké ennemi!");
    }
}

SINGLE_BATTLE_TEST("Stone Axe can set up pointed stones only once")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(player, MOVE_STONE_AXE); }
        TURN { MOVE(player, MOVE_STONE_AXE); }
        TURN { MOVE(player, MOVE_STONE_AXE); }
        TURN { MOVE(player, MOVE_STONE_AXE); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        s32 maxHP = GetMonData(&OPPONENT_PARTY[1], MON_DATA_MAX_HP);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_STONE_AXE, player);
        HP_BAR(opponent);
        MESSAGE("Des pierres pointues lévitent autour de l'équipe ennemie!");

        ANIMATION(ANIM_TYPE_MOVE, MOVE_STONE_AXE, player);
        HP_BAR(opponent);
        NOT MESSAGE("Des pierres pointues lévitent autour de l'équipe ennemie!");

        ANIMATION(ANIM_TYPE_MOVE, MOVE_STONE_AXE, player);
        HP_BAR(opponent);
        NOT MESSAGE("Des pierres pointues lévitent autour de l'équipe ennemie!");

        ANIMATION(ANIM_TYPE_MOVE, MOVE_STONE_AXE, player);
        HP_BAR(opponent);
        NOT MESSAGE("Des pierres pointues lévitent autour de l'équipe ennemie!");

        MESSAGE("2 envoie\nun Okéoké!");
        HP_BAR(opponent, damage: maxHP / 8);
        MESSAGE("Des pierres pointues transpercent Okéoké ennemi!");
    }
}

SINGLE_BATTLE_TEST("Stone Axe sets up hazards after any ability activation")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_SKARMORY) { Ability(ABILITY_WEAK_ARMOR); }
    } WHEN {
        TURN { MOVE(player, MOVE_STONE_AXE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STONE_AXE, player);
        ABILITY_POPUP(opponent, ABILITY_WEAK_ARMOR);
        MESSAGE("Des pierres pointues lévitent autour de l'équipe ennemie!");
    }
}

SINGLE_BATTLE_TEST("Stone Axe fails to set up hazards if user faints")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_ROCKY_HELMET); }
    } WHEN {
        TURN { MOVE(player, MOVE_STONE_AXE); SEND_OUT(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STONE_AXE, player);
        HP_BAR(player);
        MESSAGE("Qulbutoké est blessé par Casque Brut de Qulbutoké ennemi!");
        NOT MESSAGE("Des pierres pointues lévitent autour de l'équipe ennemie!");
    }
}

SINGLE_BATTLE_TEST("Stone Axe will set up rocks if the target is behind a Substitute")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SUBSTITUTE); MOVE(opponent, MOVE_STONE_AXE); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STONE_AXE, opponent);
        SUB_HIT(player);
        HP_BAR(player);
    }
}

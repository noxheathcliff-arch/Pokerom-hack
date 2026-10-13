#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Venusaur can Mega Evolve holding Venusaurite")
{
    GIVEN {
        PLAYER(SPECIES_VENUSAUR) { Item(ITEM_VENUSAURITE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
    } SCENE {
        MESSAGE("Florizarrite de Florizarre réagit au Méga-Anneau de 1!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, player);
        MESSAGE("Florizarre méga-évolue en Méga-Florizarre!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_VENUSAUR_MEGA);
    }
}

DOUBLE_BATTLE_TEST("Mega Evolution's order is determined by Speed - opponent faster")
{
    GIVEN {
        PLAYER(SPECIES_VENUSAUR) { Item(ITEM_VENUSAURITE); Speed(1); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_GARDEVOIR) { Item(ITEM_GARDEVOIRITE); Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(4); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); MOVE(playerLeft, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
    } SCENE {
        MESSAGE("Gardevoirite de Gardevoir ennemi réagit au Méga-Anneau de 2!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponentLeft);
        MESSAGE("Gardevoir ennemi méga-évolue en Méga-Gardevoir!");
        MESSAGE("Florizarrite de Florizarre réagit au Méga-Anneau de 1!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, playerLeft);
        MESSAGE("Florizarre méga-évolue en Méga-Florizarre!");
    }
}

DOUBLE_BATTLE_TEST("Mega Evolution's order is determined by Speed - player faster")
{
    GIVEN {
        PLAYER(SPECIES_VENUSAUR) { Item(ITEM_VENUSAURITE); Speed(5); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_GARDEVOIR) { Item(ITEM_GARDEVOIRITE); Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(4); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); MOVE(playerLeft, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
    } SCENE {
        MESSAGE("Florizarrite de Florizarre réagit au Méga-Anneau de 1!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, playerLeft);
        MESSAGE("Florizarre méga-évolue en Méga-Florizarre!");
        MESSAGE("Gardevoirite de Gardevoir ennemi réagit au Méga-Anneau de 2!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponentLeft);
        MESSAGE("Gardevoir ennemi méga-évolue en Méga-Gardevoir!");
    }
}

SINGLE_BATTLE_TEST("Rayquaza can Mega Evolve knowing Dragon Ascent")
{
    GIVEN {
        PLAYER(SPECIES_RAYQUAZA) { Moves(MOVE_DRAGON_ASCENT, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
    } SCENE {
        MESSAGE("L'esprit de 1 entre en résonance avec la volonté de Rayquaza!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, player);
        MESSAGE("Rayquaza méga-évolue en Méga-Rayquaza!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_RAYQUAZA_MEGA);
    }
}

SINGLE_BATTLE_TEST("Mega Evolution doesn't affect turn order (Gen6)")
{
    GIVEN {
        WITH_CONFIG(B_MEGA_EVO_TURN_ORDER, GEN_6);
        PLAYER(SPECIES_GARDEVOIR) { Item(ITEM_GARDEVOIRITE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
    } SCENE {
        MESSAGE("Qulbutoké ennemi utilise\nCélébration!");
        MESSAGE("Gardevoir utilise\nCélébration!");
    } THEN {
        EXPECT_EQ(player->speed, 205);
    }
}

SINGLE_BATTLE_TEST("Mega Evolution affects turn order (Gen7+)")
{
    GIVEN {
        WITH_CONFIG(B_MEGA_EVO_TURN_ORDER, GEN_7);
        PLAYER(SPECIES_GARDEVOIR) { Item(ITEM_GARDEVOIRITE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
    } SCENE {
        MESSAGE("Gardevoir utilise\nCélébration!");
        MESSAGE("Qulbutoké ennemi utilise\nCélébration!");
    } THEN {
        EXPECT_EQ(player->speed, 205);
    }
}

SINGLE_BATTLE_TEST("Abilities replaced by Mega Evolution do not affect turn order")
{
    GIVEN {
        WITH_CONFIG(B_MEGA_EVO_TURN_ORDER, GEN_7);
        ASSUME(GetSpeciesAbility(SPECIES_SABLEYE_MEGA, 0) != ABILITY_STALL
            && GetSpeciesAbility(SPECIES_SABLEYE_MEGA, 1) != ABILITY_STALL);
        PLAYER(SPECIES_SABLEYE) { Item(ITEM_SABLENITE); Ability(ABILITY_STALL); Speed(105); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(44); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
    } SCENE {
        MESSAGE("Ténéfix utilise\nCélébration!");
        MESSAGE("Qulbutoké ennemi utilise\nCélébration!");
    } THEN {
        EXPECT_EQ(player->speed, 105);
    }
}

DOUBLE_BATTLE_TEST("Mega Evolution happens after switching, but before Focus Punch-like Moves")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_FOCUS_PUNCH) == EFFECT_FOCUS_PUNCH);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_VENUSAUR) { Item(ITEM_VENUSAURITE); }
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(opponentRight, 2); MOVE(playerRight, MOVE_FOCUS_PUNCH, gimmick: GIMMICK_MEGA, target: opponentLeft); MOVE(playerLeft, MOVE_FOCUS_PUNCH, target: opponentLeft); }
        TURN {}
    } SCENE {
        MESSAGE("2 retire Qulbutoké!");
        MESSAGE("2 envoie\nun Qulbutoké!");

        MESSAGE("Florizarrite de Florizarre réagit au Méga-Anneau de 1!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, playerRight);
        MESSAGE("Florizarre méga-évolue en Méga-Florizarre!");

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FOCUS_PUNCH_SETUP, playerRight);
        MESSAGE("Florizarre se concentre au maximum!");

        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FOCUS_PUNCH_SETUP, playerLeft);
        MESSAGE("Qulbutoké se concentre au maximum!");
    }
}

SINGLE_BATTLE_TEST("Regular Mega Evolution and Fervent Wish Mega Evolution can happen on the same turn")
{
    GIVEN {
        PLAYER(SPECIES_RAYQUAZA) { Moves(MOVE_DRAGON_ASCENT, MOVE_CELEBRATE); Speed(3); }
        OPPONENT(SPECIES_GARDEVOIR) { Item(ITEM_GARDEVOIRITE); Speed(2); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); MOVE(opponent, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
    } SCENE {
        MESSAGE("L'esprit de 1 entre en résonance avec la volonté de Rayquaza!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, player);
        MESSAGE("Rayquaza méga-évolue en Méga-Rayquaza!");

        MESSAGE("Gardevoirite de Gardevoir ennemi réagit au Méga-Anneau de 2!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponent);
        MESSAGE("Gardevoir ennemi méga-évolue en Méga-Gardevoir!");
    } THEN {
        EXPECT_EQ(player->species, SPECIES_RAYQUAZA_MEGA);
        EXPECT_EQ(opponent->species, SPECIES_GARDEVOIR_MEGA);
    }
}

SINGLE_BATTLE_TEST("Mega Evolved Pokemon do not change abilities after fainting")
{
    GIVEN {
        ASSUME(MoveMakesContact(MOVE_CRUNCH) == TRUE);
        ASSUME(GetSpeciesAbility(SPECIES_GARCHOMP_MEGA, 0) != ABILITY_ROUGH_SKIN);
        ASSUME(GetSpeciesAbility(SPECIES_GARCHOMP_MEGA, 1) != ABILITY_ROUGH_SKIN);
        ASSUME(GetSpeciesAbility(SPECIES_GARCHOMP_MEGA, 2) != ABILITY_ROUGH_SKIN);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GARCHOMP) { Ability(ABILITY_ROUGH_SKIN); Item(ITEM_GARCHOMPITE); HP(1); }
    } WHEN {
        TURN { MOVE(player, MOVE_CRUNCH); MOVE(opponent, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_MEGA_EVOLUTION, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CRUNCH, player);
        MESSAGE("Carchacrok ennemi est K.O.!\p");
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_ROUGH_SKIN);
            MESSAGE("Qulbutoké est blessé par Peau Dure de Carchacrok!");
            HP_BAR(player);
        }
    }
}

SINGLE_BATTLE_TEST("Venusaur returns its base Form upon battle end after Mega Evolving")
{
    GIVEN {
        PLAYER(SPECIES_VENUSAUR) { Item(ITEM_VENUSAURITE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), SPECIES_VENUSAUR);
    }
}

SINGLE_BATTLE_TEST("Rayquaza returns its base Form upon battle end after Mega Evolving")
{
    GIVEN {
        PLAYER(SPECIES_RAYQUAZA) { Moves(MOVE_DRAGON_ASCENT, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); }
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][0], MON_DATA_SPECIES), SPECIES_RAYQUAZA);
    }
}

SINGLE_BATTLE_TEST("Venusaur returns its base Form upon fainting end after Mega Evolving")
{
    GIVEN {
        PLAYER(SPECIES_VENUSAUR) { HP(1); Item(ITEM_VENUSAURITE); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA);
            MOVE(opponent, MOVE_SCRATCH);
            SEND_OUT(player, 1);
        }
        TURN { USE_ITEM(player, ITEM_REVIVE, 0); }
        TURN { SWITCH(player, 0); }
    } THEN {
        EXPECT_EQ(player->species, SPECIES_VENUSAUR);
    }
}

SINGLE_BATTLE_TEST("Rayquaza returns its base Form upon fainting end after Mega Evolving")
{
    GIVEN {
        PLAYER(SPECIES_RAYQUAZA) { HP(1); Moves(MOVE_DRAGON_ASCENT, MOVE_CELEBRATE); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(player, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA);
            MOVE(opponent, MOVE_SCRATCH);
            SEND_OUT(player, 1);
        }
        TURN { USE_ITEM(player, ITEM_REVIVE, 0); }
        TURN { SWITCH(player, 0); }
    } THEN {
        EXPECT_EQ(player->species, SPECIES_RAYQUAZA);
    }
}

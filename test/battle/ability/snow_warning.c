#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Snow Warning sets up hail for 5 turns (Gen6-8)")
{
    GIVEN {
        WITH_CONFIG(B_SNOW_WARNING, GEN_8);
        WITH_CONFIG(B_ABILITY_WEATHER, GEN_6);
        PLAYER(SPECIES_ABOMASNOW) { Ability(ABILITY_SNOW_WARNING); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_SNOW_WARNING);
        MESSAGE("La grêle s'abat violemment.");
        MESSAGE("La grêle s'abat violemment.");
        MESSAGE("La grêle s'abat violemment.");
        MESSAGE("La grêle s'abat violemment.");
        MESSAGE("La grêle s'est arrêtée.");
    }
}

SINGLE_BATTLE_TEST("Snow Warning sets up hail for 8 turns with Icy Rock (Gen6-8)")
{
    GIVEN {
        WITH_CONFIG(B_SNOW_WARNING, GEN_8);
        WITH_CONFIG(B_ABILITY_WEATHER, GEN_6);
        ASSUME(gItemsInfo[ITEM_ICY_ROCK].holdEffect == HOLD_EFFECT_ICY_ROCK);
        PLAYER(SPECIES_ABOMASNOW) { Ability(ABILITY_SNOW_WARNING); Item(ITEM_ICY_ROCK); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_SNOW_WARNING);
        MESSAGE("La grêle s'abat violemment.");
        MESSAGE("La grêle s'abat violemment.");
        MESSAGE("La grêle s'abat violemment.");
        MESSAGE("La grêle s'abat violemment.");
        MESSAGE("La grêle s'abat violemment.");
        MESSAGE("La grêle s'abat violemment.");
        MESSAGE("La grêle s'abat violemment.");
        MESSAGE("La grêle s'est arrêtée.");
    }
}

SINGLE_BATTLE_TEST("Snow Warning sets up permanent hail (Gen4-5)")
{
    GIVEN {
        WITH_CONFIG(B_SNOW_WARNING, GEN_8);
        WITH_CONFIG(B_ABILITY_WEATHER, GEN_5);
        PLAYER(SPECIES_ABOMASNOW) { Ability(ABILITY_SNOW_WARNING); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_SNOW_WARNING);
        MESSAGE("La grêle s'abat violemment.");
        MESSAGE("La grêle s'abat violemment.");
        MESSAGE("La grêle s'abat violemment.");
        MESSAGE("La grêle s'abat violemment.");
        MESSAGE("La grêle s'abat violemment.");
        MESSAGE("La grêle s'abat violemment.");
        MESSAGE("La grêle s'abat violemment.");
        MESSAGE("La grêle s'abat violemment.");
        MESSAGE("La grêle s'abat violemment.");
        NOT MESSAGE("La grêle s'est arrêtée.");
    }
}

SINGLE_BATTLE_TEST("Snow Warning sets up snow for 5 turns (Gen9+)")
{
    GIVEN {
        WITH_CONFIG(B_SNOW_WARNING, GEN_9);
        WITH_CONFIG(B_ABILITY_WEATHER, GEN_9);
        PLAYER(SPECIES_ABOMASNOW) { Ability(ABILITY_SNOW_WARNING); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_SNOW_WARNING);
        MESSAGE("La neige continue de tomber.");
        MESSAGE("La neige continue de tomber.");
        MESSAGE("La neige continue de tomber.");
        MESSAGE("La neige continue de tomber.");
        MESSAGE("La neige s'est arrêtée.");
    }
}

SINGLE_BATTLE_TEST("Snow Warning sets up snow for 8 turns with Icy Rock (Gen9+)")
{
    GIVEN {
        WITH_CONFIG(B_SNOW_WARNING, GEN_9);
        WITH_CONFIG(B_ABILITY_WEATHER, GEN_9);
        ASSUME(gItemsInfo[ITEM_ICY_ROCK].holdEffect == HOLD_EFFECT_ICY_ROCK);
        PLAYER(SPECIES_ABOMASNOW) { Ability(ABILITY_SNOW_WARNING); Item(ITEM_ICY_ROCK); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ABILITY_POPUP(player, ABILITY_SNOW_WARNING);
        MESSAGE("La neige continue de tomber.");
        MESSAGE("La neige continue de tomber.");
        MESSAGE("La neige continue de tomber.");
        MESSAGE("La neige continue de tomber.");
        MESSAGE("La neige continue de tomber.");
        MESSAGE("La neige continue de tomber.");
        MESSAGE("La neige continue de tomber.");
        MESSAGE("La neige s'est arrêtée.");
    }
}

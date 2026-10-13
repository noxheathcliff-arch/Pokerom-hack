#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_CHILLY_RECEPTION) == EFFECT_WEATHER_AND_SWITCH);
}
#if B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_HAIL
SINGLE_BATTLE_TEST("Chilly Reception sets up hail and switches the user out")
#else
SINGLE_BATTLE_TEST("Chilly Reception sets up snow and switches the user out")
#endif
{
    GIVEN {
        PLAYER(SPECIES_SLOWKING_GALAR);
        PLAYER(SPECIES_SLOWPOKE_GALAR);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CHILLY_RECEPTION); SEND_OUT(player, 1); }
    } SCENE {
        MESSAGE("Roigada s'apprête à faire un mauvais jeu de mots…");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHILLY_RECEPTION, player);
#if B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_HAIL
        MESSAGE("Il commence à grêler!");
#else
        MESSAGE("Il commence à neiger!");
#endif
        MESSAGE("Roigada revient vers 1!");
        SEND_IN_MESSAGE("Ramoloss");
#if B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_HAIL
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HAIL_CONTINUES);
#else
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SNOW_CONTINUES);
#endif
    }
}



SINGLE_BATTLE_TEST("Chilly Reception switches the user out, even if the weather does not change")
{
    GIVEN {
        PLAYER(SPECIES_SLOWKING_GALAR);
        PLAYER(SPECIES_SLOWPOKE_GALAR);
        OPPONENT(SPECIES_KYOGRE)  { Item(ITEM_BLUE_ORB); }
    } WHEN {
        TURN { MOVE(player, MOVE_CHILLY_RECEPTION); SEND_OUT(player, 1); }
    } SCENE {
        MESSAGE("Roigada s'apprête à faire un mauvais jeu de mots…");
        MESSAGE("Impossible de dissiper une telle pluie!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHILLY_RECEPTION, player);
        MESSAGE("Roigada revient vers 1!");
        SEND_IN_MESSAGE("Ramoloss");
        MESSAGE("La pluie continue de tomber.");
    }
}

SINGLE_BATTLE_TEST("Chilly Reception does not switch the user out if no replacements")
{
    GIVEN {
        PLAYER(SPECIES_SLOWKING_GALAR);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CHILLY_RECEPTION); }
    } SCENE {
        MESSAGE("Roigada s'apprête à faire un mauvais jeu de mots…");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHILLY_RECEPTION, player);
        MESSAGE("Il commence à neiger!");
        NOT MESSAGE("Roigada revient vers 1!");
    }
}

SINGLE_BATTLE_TEST("Chilly Reception does not switch the user out if replacements fainted")
{
    GIVEN {
        PLAYER(SPECIES_SLOWKING_GALAR);
        PLAYER(SPECIES_SLOWPOKE_GALAR) { HP(0); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CHILLY_RECEPTION); }
    } SCENE {
        MESSAGE("Roigada s'apprête à faire un mauvais jeu de mots…");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHILLY_RECEPTION, player);
        MESSAGE("Il commence à neiger!");
        NOT MESSAGE("Roigada revient vers 1!");
    }
}

SINGLE_BATTLE_TEST("Chilly Reception changes the weather, even if the user cannot switch out")
{
    GIVEN {
        PLAYER(SPECIES_SLOWKING_GALAR);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CHILLY_RECEPTION); }
    } SCENE {
        MESSAGE("Roigada s'apprête à faire un mauvais jeu de mots…");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHILLY_RECEPTION, player);
#if B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_HAIL
        MESSAGE("Il commence à grêler!");
#else
        MESSAGE("Il commence à neiger!");
#endif
        NOT MESSAGE("Roigada revient vers 1!");
    }
}

SINGLE_BATTLE_TEST("Chilly Reception switches the user out even if it can't change the weather")
{
    GIVEN {
        PLAYER(SPECIES_SLOWKING_GALAR);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_NINETALES_ALOLA) { Ability(ABILITY_SNOW_WARNING); }
    } WHEN {
        TURN { MOVE(player, MOVE_CHILLY_RECEPTION); SEND_OUT(player, 1); }
    } SCENE {
        MESSAGE("Roigada s'apprête à faire un mauvais jeu de mots…");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHILLY_RECEPTION, player);
        MESSAGE("Mais cela échoue!"); // According to jpwiki, this is the correct message
        MESSAGE("Roigada revient vers 1!");
        SEND_IN_MESSAGE("Qulbutoké");
    }
}

SINGLE_BATTLE_TEST("Chilly Reception fails if it can't switch the user out or change the weather")
{
    GIVEN {
        PLAYER(SPECIES_SLOWKING_GALAR);
        OPPONENT(SPECIES_NINETALES_ALOLA) { Ability(ABILITY_SNOW_WARNING); }
    } WHEN {
        TURN { MOVE(player, MOVE_CHILLY_RECEPTION); }
    } SCENE {
        MESSAGE("Roigada s'apprête à faire un mauvais jeu de mots…");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_CHILLY_RECEPTION, player);
        MESSAGE("Mais cela échoue!");
    }
}

SINGLE_BATTLE_TEST("Chilly Reception doesn't announce its move if it's called by a different move")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SLEEP_TALK) == EFFECT_SLEEP_TALK);
        PLAYER(SPECIES_SLOWKING_GALAR) { Status1(STATUS1_SLEEP); Moves(MOVE_SLEEP_TALK, MOVE_CHILLY_RECEPTION); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SLEEP_TALK); SEND_OUT(player, 1); }
    } SCENE {
        NOT MESSAGE("Roigada s'apprête à faire un mauvais jeu de mots…");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CHILLY_RECEPTION, player);
#if B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_HAIL
        MESSAGE("Il commence à grêler!");
#else
        MESSAGE("Il commence à neiger!");
#endif
        MESSAGE("Roigada revient vers 1!");
        SEND_IN_MESSAGE("Qulbutoké");
    }
}

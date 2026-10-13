#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_THUNDER_WAVE) == EFFECT_NON_VOLATILE_STATUS);
    ASSUME(GetMoveNonVolatileStatus(MOVE_THUNDER_WAVE) == MOVE_EFFECT_PARALYSIS);
}

SINGLE_BATTLE_TEST("Paralysis reduces Speed by 50% (Gen 7+) or 75% (Gen 1-6)")
{
    u32 playerSpeed, genConfig;
    bool32 playerFirst;
    PARAMETRIZE { playerSpeed = 196; playerFirst = FALSE; genConfig = GEN_6; }
    PARAMETRIZE { playerSpeed = 204; playerFirst = TRUE;  genConfig = GEN_6; }
    PARAMETRIZE { playerSpeed = 98;  playerFirst = FALSE; genConfig = GEN_7; }
    PARAMETRIZE { playerSpeed = 102; playerFirst = TRUE;  genConfig = GEN_7; }
    GIVEN {
        WITH_CONFIG(B_PARALYSIS_SPEED, genConfig);
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_PARALYSIS); Speed(playerSpeed); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        if (playerFirst) {
            ONE_OF {
                MESSAGE("Qulbutoké utilise\nCélébration!");
                MESSAGE("Qulbutoké est paralysé! Il aura du mal à attaquer!");
            }
            MESSAGE("Qulbutoké ennemi utilise\nCélébration!");
        } else {
            MESSAGE("Qulbutoké ennemi utilise\nCélébration!");
            ONE_OF {
                MESSAGE("Qulbutoké utilise\nCélébration!");
                MESSAGE("Qulbutoké est paralysé! Il aura du mal à attaquer!");
            }
        }
    }
}

SINGLE_BATTLE_TEST("Paralysis has a 25% chance of skipping the turn")
{
    PASSES_RANDOMLY(25, 100, RNG_PARALYSIS);
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(STATUS1_PARALYSIS); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Qulbutoké est paralysé! Il n'a pas pu attaquer!");
    }
}

SINGLE_BATTLE_TEST("Thunder Wave doesn't affect Electric types (Gen6+)")
{
    u32 gen = 0;
    PARAMETRIZE { gen = GEN_5; }
    PARAMETRIZE { gen = GEN_6; }
    GIVEN {
        WITH_CONFIG(B_PARALYZE_ELECTRIC, gen);
        ASSUME(GetSpeciesType(SPECIES_PIKACHU, 0) == TYPE_ELECTRIC);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIKACHU);
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDER_WAVE); }
    } SCENE {
        MESSAGE("Qulbutoké utilise\nCage Éclair!");
        if (gen == GEN_6) {
            NONE_OF {
                ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponent);
                STATUS_ICON(opponent, paralysis: TRUE);
            }
            MESSAGE("Ça n'affecte pas Pikachu ennemi…");
        } else {
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PRZ, opponent);
            STATUS_ICON(opponent, paralysis: TRUE);
        }
    }
}

SINGLE_BATTLE_TEST("Thunder Wave doesn't print an effectiveness message")
{
    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_PIDGEY].types[1] == TYPE_FLYING);
        PLAYER(SPECIES_PIDGEY);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_THUNDER_WAVE); }
    } SCENE {
        MESSAGE("Qulbutoké ennemi utilise\nCage Éclair!");
        NOT MESSAGE("C'est super efficace!");
    }
}

SINGLE_BATTLE_TEST("Thunder Wave prints an avoided attack message when it misses")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDER_WAVE, hit: FALSE); }
    } SCENE {
        MESSAGE("Qulbutoké utilise\nCage Éclair!");
        MESSAGE("Qulbutoké ennemi évite l'attaque!");
        NOT MESSAGE("Mais cela échoue!");
    }
}

SINGLE_BATTLE_TEST("Thunder Wave prints failure when the target already has a different non-volatile status")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ZIGZAGOON) { Status1(STATUS1_POISON); }
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDER_WAVE); }
    } SCENE {
        MESSAGE("Qulbutoké utilise\nCage Éclair!");
        MESSAGE("Mais cela échoue!");
    }
}

SINGLE_BATTLE_TEST("Thunder Wave prints already paralyzed message with the right target")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ZIGZAGOON) { Status1(STATUS1_PARALYSIS); }
    } WHEN {
        TURN { MOVE(player, MOVE_THUNDER_WAVE); }
    } SCENE {
        MESSAGE("Qulbutoké utilise\nCage Éclair!");
        MESSAGE("Zigzaton ennemi est déjà paralysé.");
        NOT MESSAGE("Qulbutoké est déjà paralysé.");
    }
}

#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Octolock decreases Defense and Sp. Def by at the end of the turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_OCTOLOCK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OCTOLOCK, player);
        MESSAGE("Qulbutoké ennemi ne peut plus fuir à cause d'Octoprise!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Ah, Défense du Qulbutoké ennemi baisse!");
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Ah, Défense Spéciale du Qulbutoké ennemi baisse!");
    }
}

SINGLE_BATTLE_TEST("Octolock reduction is prevented by Clear Body, White Smoke and Full Metal Body")
{
    u32 species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_BELDUM; ability = ABILITY_CLEAR_BODY; }
    PARAMETRIZE { species = SPECIES_TORKOAL; ability = ABILITY_WHITE_SMOKE; }
    PARAMETRIZE { species = SPECIES_SOLGALEO; ability = ABILITY_FULL_METAL_BODY; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN { MOVE(player, MOVE_OCTOLOCK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OCTOLOCK, player);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        if (species == SPECIES_BELDUM)
        {
            MESSAGE("Terhal ennemi ne peut plus fuir à cause d'Octoprise!");
            ABILITY_POPUP(opponent, ABILITY_CLEAR_BODY);
            MESSAGE("Les stats de Terhal ennemi ne baissent pas!");
            NONE_OF {
                MESSAGE("Ah, Défense du Terhal ennemi baisse!");
                MESSAGE("Ah, Défense Spéciale du Terhal ennemi baisse!");
            }
        }
        else if (species == SPECIES_TORKOAL)
        {
            MESSAGE("Chartor ennemi ne peut plus fuir à cause d'Octoprise!");
            ABILITY_POPUP(opponent, ABILITY_WHITE_SMOKE);
            MESSAGE("Les stats de Chartor ennemi ne baissent pas!");
            NONE_OF {
                MESSAGE("Ah, Défense du Chartor ennemi baisse!");
                MESSAGE("Ah, Défense Spéciale du Chartor ennemi baisse!");
            }
        }
        else if (species == SPECIES_SOLGALEO)
        {
            MESSAGE("Solgaleo ennemi ne peut plus fuir à cause d'Octoprise!");
            ABILITY_POPUP(opponent, ABILITY_FULL_METAL_BODY);
            MESSAGE("Les stats de Solgaleo ennemi ne baissent pas!");
            NONE_OF {
                MESSAGE("Ah, Défense du Solgaleo ennemi baisse!");
                MESSAGE("Ah, Défense Spéciale du Solgaleo ennemi baisse!");
            }
        }
    }
}

SINGLE_BATTLE_TEST("Octolock Defense reduction is prevented by Big Pecks")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIDGEY) { Ability(ABILITY_BIG_PECKS); }
    } WHEN {
        TURN { MOVE(player, MOVE_OCTOLOCK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OCTOLOCK, player);
        MESSAGE("Roucool ennemi ne peut plus fuir à cause d'Octoprise!");
        NOT MESSAGE("Ah, Défense du Roucool ennemi baisse!");
        ABILITY_POPUP(opponent, ABILITY_BIG_PECKS);
        MESSAGE("Défense de Roucool ennemi ne baisse pas!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Ah, Défense Spéciale du Roucool ennemi baisse!");
    }
}

SINGLE_BATTLE_TEST("Octolock reduction is prevented by Clear Amulet")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_CLEAR_AMULET); }
    } WHEN {
        TURN { MOVE(player, MOVE_OCTOLOCK); }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OCTOLOCK, player);
        MESSAGE("Qulbutoké ennemi ne peut plus fuir à cause d'Octoprise!");
        MESSAGE("L'effet de Talisman Sain tenu par Qulbutoké ennemi empêche ses stats de baisser!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("Ah, Défense du Qulbutoké ennemi baisse!");
            MESSAGE("Ah, Défense Spéciale du Qulbutoké ennemi baisse!");
        }
    }
}

SINGLE_BATTLE_TEST("Octolock will not decrease Defense and Sp. Def further then minus six")
{
    u8 j;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_OCTOLOCK); }
        for (j = 0; j < 6; j++)
            TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OCTOLOCK, player);
        for (j = 0; j < 5; j++) {
            MESSAGE("Ah, Défense du Qulbutoké ennemi baisse!");
            MESSAGE("Ah, Défense Spéciale du Qulbutoké ennemi baisse!");
        }
        MESSAGE("Défense de Qulbutoké ennemi ne peut plus baisser!");
        MESSAGE("Défense Spéciale de Qulbutoké ennemi ne peut plus baisser!");
        NONE_OF {
            MESSAGE("Ah, Défense du Qulbutoké ennemi baisse!");
            MESSAGE("Ah, Défense Spéciale du Qulbutoké ennemi baisse!");
        }
    }
}

SINGLE_BATTLE_TEST("Octolock ends after user that set the lock switches out")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_OCTOLOCK); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OCTOLOCK, player);
        MESSAGE("Qulbutoké ennemi ne peut plus fuir à cause d'Octoprise!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Ah, Défense du Qulbutoké ennemi baisse!");
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Ah, Défense Spéciale du Qulbutoké ennemi baisse!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("Ah, Défense du Qulbutoké ennemi baisse!");
            MESSAGE("Ah, Défense Spéciale du Qulbutoké ennemi baisse!");
        }

    }
}

SINGLE_BATTLE_TEST("Octolock stat drops are not reflected by Mirror Armor")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CORVIKNIGHT) { Ability(ABILITY_MIRROR_ARMOR); }
    } WHEN {
        TURN { MOVE(player, MOVE_OCTOLOCK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OCTOLOCK, player);
        MESSAGE("Corvaillus ennemi ne peut plus fuir à cause d'Octoprise!");
        NOT ABILITY_POPUP(opponent, ABILITY_MIRROR_ARMOR);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Ah, Défense du Corvaillus ennemi baisse!");
    } THEN {
        EXPECT_EQ(player->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(player->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE - 1);
        EXPECT_EQ(opponent->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Octolock stat drop is prevented by Mist")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_MIST); }
        TURN { MOVE(player, MOVE_OCTOLOCK); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIST, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OCTOLOCK, player);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE);
    }
}

DOUBLE_BATTLE_TEST("Octolock stat drop is prevented by Flower Veil")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_CHIKORITA, 0) == TYPE_GRASS || GetSpeciesType(SPECIES_CHIKORITA, 1) == TYPE_GRASS);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_COMFEY) { Ability(ABILITY_FLOWER_VEIL); }
        OPPONENT(SPECIES_CHIKORITA);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_OCTOLOCK, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_OCTOLOCK, playerLeft);
        ABILITY_POPUP(opponentLeft, ABILITY_FLOWER_VEIL);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
    } THEN {
        EXPECT_EQ(opponentRight->statStages[STAT_DEF], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponentRight->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE);
    }
}

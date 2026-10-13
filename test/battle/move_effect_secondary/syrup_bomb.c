#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(MoveHasAdditionalEffect(MOVE_SYRUP_BOMB, MOVE_EFFECT_SYRUP_BOMB) == TRUE);
}

SINGLE_BATTLE_TEST("Syrup Bomb covers the foe in sticky syrup for 3 turns")
{
    u8 j;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SYRUP_BOMB); }
        for (j = 0; j < 4; j++)
            TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SYRUP_BOMB, player);
        HP_BAR(opponent);
        MESSAGE("Qulbutoké ennemi est recouvert de sirop!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, opponent);
        MESSAGE("Ah, Vitesse du Qulbutoké ennemi baisse!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, opponent);
        MESSAGE("Ah, Vitesse du Qulbutoké ennemi baisse!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, opponent);
        MESSAGE("Ah, Vitesse du Qulbutoké ennemi baisse!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, opponent);
            MESSAGE("Ah, Vitesse du Qulbutoké ennemi baisse!");
        }
    }
}

SINGLE_BATTLE_TEST("Sticky Syrup isn't applied again if the target is already covered")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SYRUP_BOMB); }
        TURN { MOVE(player, MOVE_SYRUP_BOMB); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SYRUP_BOMB, player);
        HP_BAR(opponent);
        MESSAGE("Qulbutoké ennemi est recouvert de sirop!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, opponent);
        MESSAGE("Ah, Vitesse du Qulbutoké ennemi baisse!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SYRUP_BOMB, player);
        HP_BAR(opponent);
        NOT MESSAGE("Qulbutoké ennemi est recouvert de sirop!");
    }
}

SINGLE_BATTLE_TEST("Syrup Bomb is prevented by Bulletproof")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CHESPIN) { Ability(ABILITY_BULLETPROOF); }
    } WHEN {
        TURN { MOVE(player, MOVE_SYRUP_BOMB); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_BULLETPROOF);
        MESSAGE("Ça n'affecte pas Marisson ennemi…");
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SYRUP_BOMB, player);
            HP_BAR(opponent);
        }
    }
}

SINGLE_BATTLE_TEST("Sticky Syrup speed reduction is prevented by Clear Body, White Smoke or Full Metal Body")
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
        TURN { MOVE(player, MOVE_SYRUP_BOMB); }
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SYRUP_BOMB, player);
        HP_BAR(opponent);
        if (species == SPECIES_BELDUM)
        {
            MESSAGE("Terhal ennemi est recouvert de sirop!");
            ABILITY_POPUP(opponent, ABILITY_CLEAR_BODY);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, opponent);
            MESSAGE("Les stats de Terhal ennemi ne baissent pas!");
            NONE_OF {
                MESSAGE("Ah, Vitesse du Terhal ennemi baisse!");
            }
        }
        else if (species == SPECIES_TORKOAL)
        {
            MESSAGE("Chartor ennemi est recouvert de sirop!");
            ABILITY_POPUP(opponent, ABILITY_WHITE_SMOKE);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, opponent);
            MESSAGE("Les stats de Chartor ennemi ne baissent pas!");
            NONE_OF {
                MESSAGE("Ah, Vitesse du Chartor ennemi baisse!");
            }
        }
        else if (species == SPECIES_SOLGALEO)
        {
            MESSAGE("Solgaleo ennemi est recouvert de sirop!");
            ABILITY_POPUP(opponent, ABILITY_FULL_METAL_BODY);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, opponent);
            MESSAGE("Les stats de Solgaleo ennemi ne baissent pas!");
            NONE_OF {
                MESSAGE("Ah, Vitesse du Solgaleo ennemi baisse!");
            }
        }
    }
}

SINGLE_BATTLE_TEST("Sticky Syrup speed reduction is prevented by Clear Amulet")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_CLEAR_AMULET); }
    } WHEN {
        TURN { MOVE(player, MOVE_SYRUP_BOMB); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SYRUP_BOMB, player);
        HP_BAR(opponent);
        MESSAGE("Qulbutoké ennemi est recouvert de sirop!");
        MESSAGE("L'effet de Talisman Sain tenu par Qulbutoké ennemi empêche ses stats de baisser!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, opponent);
            MESSAGE("Ah, Vitesse du Qulbutoké ennemi baisse!");
        }
    }
}

SINGLE_BATTLE_TEST("Sticky syrup will not decrease speed further then minus six")
{
    u8 j;

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        for (j = 0; j < 3; j++)
            TURN { MOVE(player, MOVE_SCARY_FACE); }
        TURN { MOVE(player, MOVE_SYRUP_BOMB); }
        TURN {}
    } SCENE {
        for (j = 0; j < 3; j++) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCARY_FACE, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SYRUP_BOMB, player);
        HP_BAR(opponent);
        MESSAGE("Qulbutoké ennemi est recouvert de sirop!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, opponent);
        MESSAGE("Vitesse de Qulbutoké ennemi ne peut plus baisser!");
        NONE_OF {
            MESSAGE("Ah, Vitesse du Qulbutoké ennemi baisse!");
        }
    }
}

SINGLE_BATTLE_TEST("Sticky Syrup is removed when the user switches out")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SYRUP_BOMB); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SYRUP_BOMB, player);
        HP_BAR(opponent);
        MESSAGE("Qulbutoké ennemi est recouvert de sirop!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, opponent);
        MESSAGE("Ah, Vitesse du Qulbutoké ennemi baisse!");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, opponent);
            MESSAGE("Ah, Vitesse du Qulbutoké ennemi baisse!");
        }
    }
}

SINGLE_BATTLE_TEST("Sticky Syrup is removed when the user faints")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SYRUP_BOMB);
               MOVE(opponent, MOVE_SCRATCH);
               SEND_OUT(player, 1);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SYRUP_BOMB, player);
        HP_BAR(opponent);
        MESSAGE("Qulbutoké ennemi est recouvert de sirop!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        HP_BAR(player);
        MESSAGE("Qulbutoké est K.O.!\p");
        SEND_IN_MESSAGE("Okéoké");
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, opponent);
            MESSAGE("Ah, Vitesse du Qulbutoké ennemi baisse!");
        }
    }
}

SINGLE_BATTLE_TEST("Sticky Syrup is not reflected by Mirror Armor")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CORVIKNIGHT) { Ability(ABILITY_MIRROR_ARMOR); }
    } WHEN {
        TURN { MOVE(player, MOVE_SYRUP_BOMB); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SYRUP_BOMB, player);
        HP_BAR(opponent);
        MESSAGE("Corvaillus ennemi est recouvert de sirop!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, opponent);
        NONE_OF {
            ABILITY_POPUP(opponent, ABILITY_MIRROR_ARMOR);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        }
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
        EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Sticky Syrup stat drop is prevented by Mist")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_MIST); }
        TURN { MOVE(player, MOVE_SYRUP_BOMB); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIST, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SYRUP_BOMB, player);
        HP_BAR(opponent);
        MESSAGE("Qulbutoké ennemi est recouvert de sirop!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, opponent);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
    }
}

DOUBLE_BATTLE_TEST("Sticky Syrup stat drop is prevented by Flower Veil")
{
    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_CHIKORITA, 0) == TYPE_GRASS || GetSpeciesType(SPECIES_CHIKORITA, 1) == TYPE_GRASS);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_COMFEY) { Ability(ABILITY_FLOWER_VEIL); }
        OPPONENT(SPECIES_CHIKORITA);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SYRUP_BOMB, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SYRUP_BOMB, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_SYRUP_BOMB_SPEED_DROP, opponentRight);
        ABILITY_POPUP(opponentLeft, ABILITY_FLOWER_VEIL);
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentRight);
    } THEN {
        EXPECT_EQ(opponentRight->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
    }
}


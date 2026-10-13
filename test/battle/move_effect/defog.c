#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_DEFOG) == EFFECT_DEFOG);
    ASSUME(GetMoveEffect(MOVE_REFLECT) == EFFECT_REFLECT);
    ASSUME(GetMoveEffect(MOVE_LIGHT_SCREEN) == EFFECT_LIGHT_SCREEN);
    ASSUME(GetMoveEffect(MOVE_MIST) == EFFECT_MIST);
    ASSUME(GetMoveEffect(MOVE_SAFEGUARD) == EFFECT_SAFEGUARD);
    ASSUME(GetMoveEffect(MOVE_AURORA_VEIL) == EFFECT_AURORA_VEIL);
    ASSUME(GetMoveEffect(MOVE_STEALTH_ROCK) == EFFECT_STEALTH_ROCK);
    ASSUME(GetMoveEffect(MOVE_SPIKES) == EFFECT_SPIKES);
    ASSUME(GetMoveEffect(MOVE_TOXIC_SPIKES) == EFFECT_TOXIC_SPIKES);
    ASSUME(GetMoveEffect(MOVE_STICKY_WEB) == EFFECT_STICKY_WEB);
    ASSUME(GetMoveEffect(MOVE_TOXIC) == EFFECT_NON_VOLATILE_STATUS);
    ASSUME(GetMoveNonVolatileStatus(MOVE_TOXIC) == MOVE_EFFECT_TOXIC);
    ASSUME_STAT_CHANGE(MOVE_SCREECH, defense: -2);
    ASSUME(GetMoveCategory(MOVE_SCRATCH) == DAMAGE_CATEGORY_PHYSICAL);
    ASSUME(GetMoveCategory(MOVE_GUST) == DAMAGE_CATEGORY_SPECIAL);
}

SINGLE_BATTLE_TEST("Defog lowers evasiveness by 1 stage")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_DEFOG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DEFOG, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Ah, esquive du Qulbutoké ennemi baisse!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_EVASION], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Defog fails if target has minimum evasion stat change")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_NUMEL) { Ability(ABILITY_SIMPLE); }
    } WHEN {
        TURN { MOVE(player, MOVE_DEFOG); }
        TURN { MOVE(player, MOVE_DEFOG); }
        TURN { MOVE(player, MOVE_DEFOG); }
        TURN { MOVE(player, MOVE_DEFOG); }
    } SCENE {
        for (u32 i = 0; i < 3; i++)
        {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_DEFOG, player);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
            MESSAGE("Ah, esquive du Chamallot ennemi baisse beaucoup!");
        }
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_DEFOG, player);
        MESSAGE("esquive de Chamallot ennemi ne peut plus baisser!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_EVASION], DEFAULT_STAT_STAGE - 6);
    }
}

SINGLE_BATTLE_TEST("Defog lowers evasiveness of target behind Substitute (Gen4)")
{
    KNOWN_FAILING;
    GIVEN {
        WITH_CONFIG(B_DEFOG_EFFECT_CLEARING, GEN_4);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_DEFOG); }
    } SCENE {
        MESSAGE("Qulbutoké ennemi utilise\nClonage!");
        NOT MESSAGE("Mais cela échoue!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DEFOG, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Ah, esquive du Qulbutoké ennemi baisse!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_EVASION], DEFAULT_STAT_STAGE - 1);
    }
}

SINGLE_BATTLE_TEST("Defog fails if target has minimum evasion stat change behind Substitute (Gen4)")
{
    KNOWN_FAILING;
    GIVEN {
        WITH_CONFIG(B_DEFOG_EFFECT_CLEARING, GEN_4);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); Ability(ABILITY_SIMPLE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_DEFOG); }
        TURN { MOVE(player, MOVE_DEFOG); }
        TURN { MOVE(player, MOVE_DEFOG); }
        TURN { MOVE(player, MOVE_DEFOG); }
    } SCENE {
        MESSAGE("Qulbutoké ennemi utilise\nClonage!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DEFOG, player);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Ah, esquive du Qulbutoké ennemi baisse beaucoup!");
        MESSAGE("Mais cela échoue!");
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_EVASION], DEFAULT_STAT_STAGE - 6);
    }
}

SINGLE_BATTLE_TEST("Defog does not lower evasiveness if target behind Substitute (Gen5+)")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_LIGHT_SCREEN; }
    PARAMETRIZE { move = MOVE_CELEBRATE; }

    GIVEN {
        WITH_CONFIG(B_DEFOG_EFFECT_CLEARING, GEN_5);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
    } WHEN {
        TURN { MOVE(opponent, move); }
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_DEFOG); }
    } SCENE {
        MESSAGE("Qulbutoké ennemi utilise\nClonage!");
        if (move == MOVE_CELEBRATE)
        {
            MESSAGE("Mais cela échoue!");
            NONE_OF {
                ANIMATION(ANIM_TYPE_MOVE, MOVE_DEFOG, player);
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
                MESSAGE("Ah, esquive du Qulbutoké ennemi baisse!");
            }
        }
        else
        {
            NONE_OF {
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
                MESSAGE("Ah, esquive du Qulbutoké ennemi baisse!");
            }
        }
    } THEN {
        EXPECT_EQ(opponent->statStages[STAT_EVASION], DEFAULT_STAT_STAGE);
    }
}

DOUBLE_BATTLE_TEST("Defog doesn't remove Reflect or Light Screen from the user's side", s16 damagePhysical, s16 damageSpecial)
{
    enum Move move;

    PARAMETRIZE { move = MOVE_DEFOG; }
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_REFLECT); MOVE(playerRight, MOVE_LIGHT_SCREEN); }
        TURN { MOVE(playerLeft, move, target: opponentLeft); }
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); MOVE(opponentRight, MOVE_GUST, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REFLECT, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LIGHT_SCREEN, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, move, playerLeft);
        NONE_OF {
            MESSAGE("Protection de votre équipe s'est dissipé!");
            MESSAGE("Mur Lumière de votre équipe s'est dissipé!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        HP_BAR(playerLeft, captureDamage: &results[i].damagePhysical);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GUST, opponentRight);
        HP_BAR(playerRight, captureDamage: &results[i].damageSpecial);
    } FINALLY {
        EXPECT_EQ(results[1].damagePhysical, results[0].damagePhysical);
        EXPECT_EQ(results[1].damageSpecial, results[0].damageSpecial);
    }
}

DOUBLE_BATTLE_TEST("Defog removes Reflect and Light Screen from target's side", s16 damagePhysical, s16 damageSpecial)
{
    enum Move move;

    PARAMETRIZE { move = MOVE_DEFOG; }
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_REFLECT); MOVE(opponentRight, MOVE_LIGHT_SCREEN); }
        TURN { MOVE(playerLeft, move, target: opponentLeft); }
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentLeft); MOVE(playerRight, MOVE_GUST, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REFLECT, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LIGHT_SCREEN, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, move, playerLeft);
        if (move == MOVE_DEFOG) {
            MESSAGE("Protection de l'équipe ennemie s'est dissipé!");
            MESSAGE("Mur Lumière de l'équipe ennemie s'est dissipé!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &results[i].damagePhysical);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GUST, playerRight);
        HP_BAR(opponentRight, captureDamage: &results[i].damageSpecial);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damagePhysical, Q_4_12(1.5), results[0].damagePhysical);
        EXPECT_MUL_EQ(results[1].damageSpecial, Q_4_12(1.5), results[0].damageSpecial);
    }
}

DOUBLE_BATTLE_TEST("Defog doesn't remove Mist or Safeguard from the user's side")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_DEFOG; }
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_MIST); MOVE(playerRight, MOVE_SAFEGUARD); }
        TURN { MOVE(playerLeft, move, target: opponentLeft); }
        TURN { MOVE(opponentLeft, MOVE_SCREECH, target: playerLeft); MOVE(opponentRight, MOVE_TOXIC, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIST, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SAFEGUARD, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, move, playerLeft);
        NONE_OF {
            MESSAGE("Brume de votre équipe s'est dissipé!");
            MESSAGE("Rune Protect de votre équipe s'est dissipé!");
        }
        MESSAGE("Qulbutoké ennemi utilise\nGrincement!");
        MESSAGE("Qulbutoké est protégé par la brume!");
        NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
        MESSAGE("Qulbutoké ennemi utilise\nToxik!");
        MESSAGE("Qulbutoké est protégé par la brume!");
        NOT STATUS_ICON(playerRight, badPoison: TRUE);
    }
}

DOUBLE_BATTLE_TEST("Defog removes Mist and Safeguard from target's side")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_DEFOG; }
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_MIST); MOVE(opponentRight, MOVE_SAFEGUARD); }
        TURN { MOVE(playerLeft, move, target: opponentLeft); }
        TURN { MOVE(playerLeft, MOVE_SCREECH, target: opponentLeft); MOVE(playerRight, MOVE_TOXIC, target: opponentRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MIST, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SAFEGUARD, opponentRight);
        if (move == MOVE_DEFOG) {
            ANIMATION(ANIM_TYPE_MOVE, move, playerLeft);
            MESSAGE("Brume de l'équipe ennemie s'est dissipé!");
            MESSAGE("Rune Protect de l'équipe ennemie s'est dissipé!");
        }
        MESSAGE("Qulbutoké utilise\nGrincement!");
        if (move == MOVE_DEFOG) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_SCREECH, playerLeft);
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        } else {
            MESSAGE("Qulbutoké ennemi est protégé par la brume!");
            NOT ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
        }
        MESSAGE("Qulbutoké utilise\nToxik!");
        if (move == MOVE_DEFOG) {
            ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, playerRight);
            STATUS_ICON(opponentRight, badPoison: TRUE);
        } else {
            MESSAGE("Qulbutoké ennemi est protégé par la brume!");
            NOT STATUS_ICON(opponentRight, badPoison: TRUE);
        }
    }
}

DOUBLE_BATTLE_TEST("Defog removes Stealth Rock and Sticky Web from target's side")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_DEFOG; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_STEALTH_ROCK); MOVE(opponentRight, MOVE_STICKY_WEB); }
        TURN { MOVE(opponentLeft, move, target: playerLeft); }
        TURN { SWITCH(playerLeft, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STICKY_WEB, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, move, opponentLeft);
        if (move == MOVE_DEFOG) {
            MESSAGE("La toile gluante du côté de votre équipe a disparu!");
            MESSAGE("Les pierres pointues autour de votre équipe ont disparu!");
        }
        // Switch happens
        SWITCH_OUT_MESSAGE("Qulbutoké");
        SEND_IN_MESSAGE("Qulbutoké");
        if (move != MOVE_DEFOG) {
            HP_BAR(playerLeft);
            MESSAGE("Des pierres pointues transpercent Qulbutoké!");
            MESSAGE("Qulbutoké est pris dans une toile gluante!");
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
            MESSAGE("Ah, Vitesse du Qulbutoké baisse!");
        } else {
            NONE_OF {
                HP_BAR(playerLeft);
                MESSAGE("Des pierres pointues transpercent Qulbutoké!");
                MESSAGE("Qulbutoké est pris dans une toile gluante!");
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
                MESSAGE("Ah, Vitesse du Qulbutoké baisse!");
            }
        }
    } THEN {
        if (move != MOVE_DEFOG) {
            EXPECT_EQ(playerLeft->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
        } else {
            EXPECT_EQ(playerLeft->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
        }
    }
}

DOUBLE_BATTLE_TEST("Defog removes Stealth Rock and Sticky Web from user's side (Gen 6+)")
{
    enum Move move;
    u32 config;

    PARAMETRIZE { move = MOVE_CELEBRATE; config = GEN_5; }
    PARAMETRIZE { move = MOVE_DEFOG;     config = GEN_5; }
    PARAMETRIZE { move = MOVE_DEFOG;     config = GEN_6; }
    GIVEN {
        WITH_CONFIG(B_DEFOG_EFFECT_CLEARING, config);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_STEALTH_ROCK); MOVE(opponentRight, MOVE_STICKY_WEB); }
        TURN { MOVE(playerLeft, move, target: opponentLeft); }
        TURN { SWITCH(playerLeft, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STEALTH_ROCK, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_STICKY_WEB, opponentRight);
        ANIMATION(ANIM_TYPE_MOVE, move, playerLeft);
        if (move == MOVE_DEFOG && config >= GEN_6) {
            MESSAGE("La toile gluante du côté de votre équipe a disparu!");
            MESSAGE("Les pierres pointues autour de votre équipe ont disparu!");
        }
        // Switch happens
        SWITCH_OUT_MESSAGE("Qulbutoké");
        SEND_IN_MESSAGE("Qulbutoké");
        if (move != MOVE_DEFOG || config <= GEN_5) {
            HP_BAR(playerLeft);
            MESSAGE("Des pierres pointues transpercent Qulbutoké!");
            MESSAGE("Qulbutoké est pris dans une toile gluante!");
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
            MESSAGE("Ah, Vitesse du Qulbutoké baisse!");
        } else {
            NONE_OF {
                HP_BAR(playerLeft);
                MESSAGE("Des pierres pointues transpercent Qulbutoké!");
                MESSAGE("Qulbutoké est pris dans une toile gluante!");
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
                MESSAGE("Ah, Vitesse du Qulbutoké baisse!");
            }
        }
    } THEN {
        if (move != MOVE_DEFOG || config <= GEN_5) {
            EXPECT_EQ(playerLeft->statStages[STAT_SPEED], DEFAULT_STAT_STAGE - 1);
        } else {
            EXPECT_EQ(playerLeft->statStages[STAT_SPEED], DEFAULT_STAT_STAGE);
        }
    }
}

SINGLE_BATTLE_TEST("Defog removes Spikes from target's side")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_DEFOG;     }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
    } WHEN {
        TURN { MOVE(player, MOVE_SPIKES); }
        TURN { MOVE(player, move); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPIKES, player);
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        if (move == MOVE_DEFOG) {
            MESSAGE("Il n'y a plus de picots autour de l'équipe ennemie!");
            NONE_OF {
                HP_BAR(opponent);
                MESSAGE("Qulbutoké ennemi est blessé par les picots!");
            }
        } else {
            NOT MESSAGE("Il n'y a plus de picots autour de l'équipe ennemie!");
            HP_BAR(opponent);
            MESSAGE("Qulbutoké ennemi est blessé par les picots!");
        }
    }
}

SINGLE_BATTLE_TEST("Defog removes Spikes from user's side (Gen 6+)")
{
    enum Move move;
    u32 config;

    PARAMETRIZE { move = MOVE_CELEBRATE; config = GEN_5; }
    PARAMETRIZE { move = MOVE_DEFOG;     config = GEN_5; }
    PARAMETRIZE { move = MOVE_DEFOG;     config = GEN_6; }
    GIVEN {
        WITH_CONFIG(B_DEFOG_EFFECT_CLEARING, config);
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SPIKES); MOVE(player, move); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPIKES, opponent);
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        if (move == MOVE_DEFOG && config >= GEN_6)
            MESSAGE("Il n'y a plus de picots autour de votre équipe!");
        // Switch happens
        SWITCH_OUT_MESSAGE("Qulbutoké");
        SEND_IN_MESSAGE("Qulbutoké");
        if (move != MOVE_DEFOG || config <= GEN_5) {
            HP_BAR(player);
            MESSAGE("Qulbutoké est blessé par les picots!");
        } else {
            NONE_OF {
                HP_BAR(player);
                MESSAGE("Qulbutoké est blessé par les picots!");
            }
        }
    }
}

SINGLE_BATTLE_TEST("Defog removes terrain (Gen 8+)")
{
    enum Move move;
    u32 config;

    PARAMETRIZE { move = MOVE_PSYCHIC_TERRAIN;  config = GEN_7; }
    PARAMETRIZE { move = MOVE_ELECTRIC_TERRAIN; config = GEN_7; }
    PARAMETRIZE { move = MOVE_MISTY_TERRAIN;    config = GEN_7; }
    PARAMETRIZE { move = MOVE_GRASSY_TERRAIN;   config = GEN_7; }
    PARAMETRIZE { move = MOVE_PSYCHIC_TERRAIN;  config = GEN_8; }
    PARAMETRIZE { move = MOVE_ELECTRIC_TERRAIN; config = GEN_8; }
    PARAMETRIZE { move = MOVE_MISTY_TERRAIN;    config = GEN_8; }
    PARAMETRIZE { move = MOVE_GRASSY_TERRAIN;   config = GEN_8; }
    GIVEN {
        WITH_CONFIG(B_DEFOG_EFFECT_CLEARING, config);
        PLAYER(SPECIES_WOBBUFFET) { Speed(50); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(5); }
    } WHEN {
        TURN { MOVE(player, move); MOVE(opponent, MOVE_DEFOG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DEFOG, opponent);
        if (config >= GEN_8) {
            if (move == MOVE_PSYCHIC_TERRAIN) {
                MESSAGE("Le sol redevient normal.");
            }
            else if (move == MOVE_ELECTRIC_TERRAIN) {
                MESSAGE("L'électricité parcourant le terrain s'est dissipée.");
            }
            else if (move == MOVE_MISTY_TERRAIN) {
                MESSAGE("La brume qui recouvrait le terrain se dissipe.");
            }
            else if (move == MOVE_GRASSY_TERRAIN) {
                MESSAGE("Le gazon disparaît.");
            }
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_RESTORE_BG, player);
        } else {
            NONE_OF {
                MESSAGE("Le sol redevient normal.");
                MESSAGE("L'électricité parcourant le terrain s'est dissipée.");
                MESSAGE("La brume qui recouvrait le terrain se dissipe.");
                MESSAGE("Le gazon disparaît.");
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_RESTORE_BG, player);
            }
        }
    }
}

SINGLE_BATTLE_TEST("Defog removes Toxic Spikes from target's side")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_CELEBRATE; }
    PARAMETRIZE { move = MOVE_DEFOG; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC_SPIKES); }
        TURN { MOVE(player, move); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_SPIKES, player);
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        if (move == MOVE_DEFOG)
            MESSAGE("Il n'y a plus de pics toxiques autour de l'équipe ennemie!");
        // Switch happens
        MESSAGE("2 envoie\nun Qulbutoké!");
        if (move != MOVE_DEFOG) {
            MESSAGE("Qulbutoké ennemi est empoisonné!");
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
            STATUS_ICON(opponent, poison: TRUE);
        } else {
            NONE_OF {
                MESSAGE("Qulbutoké ennemi est empoisonné!");
                ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
                STATUS_ICON(opponent, poison: TRUE);
            }
        }
    }
}

SINGLE_BATTLE_TEST("Defog removes Toxic Spikes from user's side (Gen 6+)")
{
    enum Move move;
    u32 config;

    PARAMETRIZE { move = MOVE_CELEBRATE; config = GEN_5; }
    PARAMETRIZE { move = MOVE_DEFOG;     config = GEN_5; }
    PARAMETRIZE { move = MOVE_DEFOG;     config = GEN_6; }
    GIVEN {
        WITH_CONFIG(B_DEFOG_EFFECT_CLEARING, config);
        PLAYER(SPECIES_WOBBUFFET) { Speed(5); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC_SPIKES); MOVE(opponent, move); }
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC_SPIKES, player);
        ANIMATION(ANIM_TYPE_MOVE, move, opponent);
        if (move == MOVE_DEFOG && config >= GEN_6)
            MESSAGE("Il n'y a plus de pics toxiques autour de l'équipe ennemie!");
        // Switch happens
        MESSAGE("2 envoie\nun Qulbutoké!");
        if (move != MOVE_DEFOG || config <= GEN_5) {
            MESSAGE("Qulbutoké ennemi est empoisonné!");
            ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
            STATUS_ICON(opponent, poison: TRUE);
        } else {
            NONE_OF {
                MESSAGE("Qulbutoké ennemi est empoisonné!");
                ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_PSN, opponent);
                STATUS_ICON(opponent, poison: TRUE);
            }
        }
    }
}

DOUBLE_BATTLE_TEST("Defog doesn't remove Aurora Veil from the user's side", s16 damagePhysical, s16 damageSpecial)
{
    enum Move move;

    PARAMETRIZE { move = MOVE_DEFOG; }
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_HAIL) == EFFECT_WEATHER);
        ASSUME(GetMoveWeatherType(MOVE_HAIL) == BATTLE_WEATHER_HAIL);
        ASSUME(GetSpeciesType(SPECIES_GLALIE, 0) == TYPE_ICE);
        PLAYER(SPECIES_GLALIE) { Speed(4); }
        PLAYER(SPECIES_GLALIE) { Speed(3); }
        OPPONENT(SPECIES_GLALIE) { Speed(2); }
        OPPONENT(SPECIES_GLALIE) { Speed(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_HAIL); MOVE(playerRight, MOVE_AURORA_VEIL); }
        TURN { MOVE(playerLeft, move, target: opponentLeft); }
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); MOVE(opponentRight, MOVE_GUST, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HAIL, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AURORA_VEIL, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, move, playerLeft);
        if (move == MOVE_DEFOG) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponentLeft);
            MESSAGE("Ah, esquive du Oniglali ennemi baisse!");
        }
        NOT MESSAGE("Voile Aurore de votre équipe s'est dissipé!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        HP_BAR(playerLeft, captureDamage: &results[i].damagePhysical);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GUST, opponentRight);
        HP_BAR(playerRight, captureDamage: &results[i].damageSpecial);
    } THEN {
        if (move == MOVE_DEFOG)
            EXPECT_EQ(opponentLeft->statStages[STAT_EVASION], DEFAULT_STAT_STAGE - 1);
        else
            EXPECT_EQ(opponentLeft->statStages[STAT_EVASION], DEFAULT_STAT_STAGE);
    } FINALLY {
        EXPECT_EQ(results[1].damagePhysical, results[0].damagePhysical);
        EXPECT_EQ(results[1].damageSpecial, results[0].damageSpecial);
    }
}

DOUBLE_BATTLE_TEST("Defog removes Aurora Veil from target's side", s16 damagePhysical, s16 damageSpecial)
{
    enum Move move;

    PARAMETRIZE { move = MOVE_DEFOG; }
    PARAMETRIZE { move = MOVE_CELEBRATE; }
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_HAIL) == EFFECT_WEATHER);
        ASSUME(GetMoveWeatherType(MOVE_HAIL) == BATTLE_WEATHER_HAIL);
        ASSUME(GetSpeciesType(SPECIES_GLALIE, 0) == TYPE_ICE);
        PLAYER(SPECIES_GLALIE) { Speed(4); }
        PLAYER(SPECIES_GLALIE) { Speed(3); }
        OPPONENT(SPECIES_GLALIE) { Speed(2); }
        OPPONENT(SPECIES_GLALIE) { Speed(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_HAIL); MOVE(playerRight, MOVE_AURORA_VEIL); }
        TURN { MOVE(opponentLeft, move, target: playerLeft); }
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerLeft); MOVE(opponentRight, MOVE_GUST, target: playerRight); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HAIL, playerLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AURORA_VEIL, playerRight);
        ANIMATION(ANIM_TYPE_MOVE, move, opponentLeft);
        if (move == MOVE_DEFOG) {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, playerLeft);
            MESSAGE("Ah, esquive du Oniglali baisse!");
            MESSAGE("Voile Aurore de votre équipe s'est dissipé!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponentLeft);
        HP_BAR(playerLeft, captureDamage: &results[i].damagePhysical);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GUST, opponentRight);
        HP_BAR(playerRight, captureDamage: &results[i].damageSpecial);
    } THEN {
        if (move == MOVE_DEFOG)
            EXPECT_EQ(playerLeft->statStages[STAT_EVASION], DEFAULT_STAT_STAGE - 1);
        else
            EXPECT_EQ(playerLeft->statStages[STAT_EVASION], DEFAULT_STAT_STAGE);
    } FINALLY {
        EXPECT_MUL_EQ(results[1].damagePhysical, Q_4_12(1.5), results[0].damagePhysical);
        EXPECT_MUL_EQ(results[1].damageSpecial, Q_4_12(1.5), results[0].damageSpecial);
    }
}

DOUBLE_BATTLE_TEST("Defog removes everything it can")
{
    u32 config;
    PARAMETRIZE { config = GEN_5; }
    PARAMETRIZE { config = GEN_6; }
    GIVEN {
        WITH_CONFIG(B_DEFOG_EFFECT_CLEARING, config);
        ASSUME(GetMoveEffect(MOVE_HAIL) == EFFECT_WEATHER);
        ASSUME(GetMoveWeatherType(MOVE_HAIL) == BATTLE_WEATHER_HAIL);
        ASSUME(GetSpeciesType(SPECIES_GLALIE, 0) == TYPE_ICE);
        PLAYER(SPECIES_GLALIE) { Speed(4); }
        PLAYER(SPECIES_GLALIE) { Speed(3); }
        PLAYER(SPECIES_GLALIE) { Speed(12); }
        PLAYER(SPECIES_GLALIE) { Speed(3); }
        OPPONENT(SPECIES_GLALIE) { Speed(2); }
        OPPONENT(SPECIES_GLALIE) { Speed(1); }
        OPPONENT(SPECIES_GLALIE) { Speed(1); }
        OPPONENT(SPECIES_GLALIE) { Speed(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_STICKY_WEB); MOVE(playerRight, MOVE_SPIKES); MOVE(opponentLeft, MOVE_STICKY_WEB); MOVE(opponentRight, MOVE_SPIKES); }
        TURN { SWITCH(playerLeft, 2); SWITCH(playerRight, 3); SWITCH(opponentLeft, 2); SWITCH(opponentRight, 3); }
        TURN { MOVE(playerLeft, MOVE_TOXIC_SPIKES); MOVE(playerRight, MOVE_STEALTH_ROCK); MOVE(opponentLeft, MOVE_TOXIC_SPIKES); MOVE(opponentRight, MOVE_STEALTH_ROCK); }
        TURN { MOVE(playerLeft, MOVE_HAIL); MOVE(playerRight, MOVE_AURORA_VEIL); MOVE(opponentLeft, MOVE_AURORA_VEIL); MOVE(opponentRight, MOVE_LIGHT_SCREEN); }
        TURN { MOVE(playerLeft, MOVE_REFLECT); MOVE(playerRight, MOVE_LIGHT_SCREEN); MOVE(opponentLeft, MOVE_REFLECT); MOVE(opponentRight, MOVE_SAFEGUARD); }
        TURN { MOVE(playerLeft, MOVE_MIST); MOVE(playerRight, MOVE_SAFEGUARD); MOVE(opponentLeft, MOVE_MIST); MOVE(opponentRight, MOVE_DEFOG, target: playerLeft); }
    } SCENE {
        MESSAGE("Oniglali ennemi utilise\nAnti-Brume!");
        MESSAGE("Oniglali est protégé par la brume!");

        // No, idea. Either I'm blind or the anim is played on the correct mon
        // ANIMATION(ANIM_TYPE_MOVE, MOVE_DEFOG, opponentRight);

        // Player side
        MESSAGE("Protection de votre équipe s'est dissipé!");
        MESSAGE("Mur Lumière de votre équipe s'est dissipé!");
        MESSAGE("Brume de votre équipe s'est dissipé!");
        MESSAGE("Voile Aurore de votre équipe s'est dissipé!");
        MESSAGE("Rune Protect de votre équipe s'est dissipé!");

        if (config == GEN_6) {
            MESSAGE("Il n'y a plus de picots autour de votre équipe!");
            MESSAGE("La toile gluante du côté de votre équipe a disparu!");
            MESSAGE("Il n'y a plus de pics toxiques autour de votre équipe!");
            MESSAGE("Les pierres pointues autour de votre équipe ont disparu!");

            // Opponent side
            MESSAGE("Il n'y a plus de picots autour de l'équipe ennemie!");
            MESSAGE("La toile gluante du côté de l'équipe ennemie a disparu!");
            MESSAGE("Il n'y a plus de pics toxiques autour de l'équipe ennemie!");
            MESSAGE("Les pierres pointues autour de l'équipe ennemie ont disparu!");
        }
    } THEN {
        if (config == GEN_6) {
            EXPECT_EQ(gBattleStruct->hazardsQueue[0][0], HAZARDS_NONE);
            EXPECT_EQ(gBattleStruct->hazardsQueue[0][1], HAZARDS_NONE);
            EXPECT_EQ(gBattleStruct->hazardsQueue[0][2], HAZARDS_NONE);
            EXPECT_EQ(gBattleStruct->hazardsQueue[0][3], HAZARDS_NONE);
        } else {
            EXPECT_EQ(gBattleStruct->hazardsQueue[0][0], HAZARDS_STICKY_WEB);
            EXPECT_EQ(gBattleStruct->hazardsQueue[0][1], HAZARDS_SPIKES);
            EXPECT_EQ(gBattleStruct->hazardsQueue[0][2], HAZARDS_STEALTH_ROCK);
            EXPECT_EQ(gBattleStruct->hazardsQueue[0][3], HAZARDS_TOXIC_SPIKES);
        }
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][4], HAZARDS_NONE);
        EXPECT_EQ(gBattleStruct->hazardsQueue[0][5], HAZARDS_NONE);

        if (config == GEN_6) {
            EXPECT_EQ(gBattleStruct->hazardsQueue[1][0], HAZARDS_NONE);
            EXPECT_EQ(gBattleStruct->hazardsQueue[1][1], HAZARDS_NONE);
            EXPECT_EQ(gBattleStruct->hazardsQueue[1][2], HAZARDS_NONE);
            EXPECT_EQ(gBattleStruct->hazardsQueue[1][3], HAZARDS_NONE);
        } else {
            EXPECT_EQ(gBattleStruct->hazardsQueue[1][0], HAZARDS_STICKY_WEB);
            EXPECT_EQ(gBattleStruct->hazardsQueue[1][1], HAZARDS_SPIKES);
            EXPECT_EQ(gBattleStruct->hazardsQueue[1][2], HAZARDS_TOXIC_SPIKES);
            EXPECT_EQ(gBattleStruct->hazardsQueue[1][3], HAZARDS_STEALTH_ROCK);
        }
        EXPECT_EQ(gBattleStruct->hazardsQueue[1][4], HAZARDS_NONE);
        EXPECT_EQ(gBattleStruct->hazardsQueue[1][5], HAZARDS_NONE);
    }
}

SINGLE_BATTLE_TEST("Defog is used on the correct side if opposing mon is behind a Substitute with Screen up")
{
    u32 config;
    // PARAMETRIZE { config = GEN_4; }
    PARAMETRIZE { config = GEN_5; }
    GIVEN {
        WITH_CONFIG(B_DEFOG_EFFECT_CLEARING, config);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_LIGHT_SCREEN); }
        TURN { MOVE(opponent, MOVE_SUBSTITUTE); MOVE(player, MOVE_DEFOG); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_LIGHT_SCREEN, opponent);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, opponent);
        MESSAGE("Qulbutoké utilise\nAnti-Brume!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DEFOG, player);
        MESSAGE("Mur Lumière de l'équipe ennemie s'est dissipé!");
    } THEN {
        if (config >= GEN_5)
            EXPECT_EQ(opponent->statStages[STAT_EVASION], DEFAULT_STAT_STAGE);
        else
            EXPECT_EQ(opponent->statStages[STAT_EVASION], DEFAULT_STAT_STAGE - 1);
    }
}

#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_COURT_CHANGE) == EFFECT_COURT_CHANGE);
}

SINGLE_BATTLE_TEST("Court Change swaps entry hazard counts together with the hazard queues")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TOXIC_SPIKES); }
        TURN { MOVE(opponent, MOVE_COURT_CHANGE); }
    } THEN {
        EXPECT_EQ(gBattleStruct->hazardsQueue[B_SIDE_PLAYER][0], HAZARDS_TOXIC_SPIKES);
        EXPECT_EQ(gBattleStruct->hazardsQueue[B_SIDE_OPPONENT][0], HAZARDS_NONE);
        EXPECT_EQ(gBattleStruct->numHazards[B_SIDE_PLAYER], 1);
        EXPECT_EQ(gBattleStruct->numHazards[B_SIDE_OPPONENT], 0);
    }
}

DOUBLE_BATTLE_TEST("Court Change swaps entry hazards used by the opponent")
{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_STICKY_WEB); MOVE(opponentRight, MOVE_STEALTH_ROCK); }
        TURN { MOVE(opponentLeft, MOVE_SPIKES); MOVE(opponentRight, MOVE_TOXIC_SPIKES); }
        TURN { MOVE(playerLeft, MOVE_COURT_CHANGE); }
        TURN { SWITCH(playerLeft, 2); SWITCH(opponentLeft, 2); }
    } SCENE {
        MESSAGE("Qulbutoké ennemi utilise\nToile Gluante!");
        MESSAGE("Qulbutoké ennemi utilise\nPiège de Roc!");
        MESSAGE("Qulbutoké ennemi utilise\nPicots!");
        MESSAGE("Qulbutoké ennemi utilise\nPics Toxik!");
        MESSAGE("Okéoké utilise\nChange-Côté!");
        MESSAGE("Les effets affectant chaque côté du terrain ont été échangés par Okéoké!");
        SEND_IN_MESSAGE("Okéoké");
        NONE_OF {
            MESSAGE("Okéoké est pris dans une toile gluante!");
            MESSAGE("Des pierres pointues transpercent Okéoké!");
            MESSAGE("Okéoké est blessé par les picots!");
            MESSAGE("Okéoké est empoisonné!");
        }
        MESSAGE("2 envoie\nun Qulbutoké!");
        MESSAGE("Qulbutoké ennemi est pris dans une toile gluante!");
        MESSAGE("Des pierres pointues transpercent Qulbutoké ennemi!");
        MESSAGE("Qulbutoké ennemi est blessé par les picots!");
        MESSAGE("Qulbutoké ennemi est empoisonné!");
    }
}

DOUBLE_BATTLE_TEST("Court Change swaps entry hazards used by the player")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_STICKY_WEB); MOVE(playerRight, MOVE_STEALTH_ROCK); }
        TURN { MOVE(playerLeft, MOVE_SPIKES); MOVE(playerRight, MOVE_TOXIC_SPIKES); }
        TURN { MOVE(opponentLeft, MOVE_COURT_CHANGE); }
        TURN { SWITCH(opponentLeft, 2); SWITCH(playerLeft, 2); }
    } SCENE {
        MESSAGE("Qulbutoké utilise\nToile Gluante!");
        MESSAGE("Qulbutoké utilise\nPiège de Roc!");
        MESSAGE("Qulbutoké utilise\nPicots!");
        MESSAGE("Qulbutoké utilise\nPics Toxik!");
        MESSAGE("Okéoké ennemi utilise\nChange-Côté!");
        MESSAGE("Les effets affectant chaque côté du terrain ont été échangés par Okéoké ennemi!");
        SEND_IN_MESSAGE("Qulbutoké");
        MESSAGE("Qulbutoké est pris dans une toile gluante!");
        MESSAGE("Des pierres pointues transpercent Qulbutoké!");
        MESSAGE("Qulbutoké est blessé par les picots!");
        MESSAGE("Qulbutoké est empoisonné!");
        MESSAGE("2 envoie\nun Okéoké!");
        NONE_OF {
            MESSAGE("Okéoké ennemi est pris dans une toile gluante!");
            MESSAGE("Des pierres pointues transpercent Okéoké ennemi!");
            MESSAGE("Okéoké ennemi est blessé par les picots!");
            MESSAGE("Okéoké ennemi est empoisonné!");
        }
    }
}

DOUBLE_BATTLE_TEST("Court Change used by the player swaps Mist, Safeguard, Aurora Veil, Reflect, Light Screen, Tailwind")
{
    GIVEN {
        WITH_CONFIG(B_TAILWIND_TURNS, GEN_5);
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SNOWSCAPE); MOVE(opponentLeft, MOVE_MIST); MOVE(opponentRight, MOVE_SAFEGUARD); }
        TURN { MOVE(opponentLeft, MOVE_AURORA_VEIL); MOVE(opponentRight, MOVE_REFLECT); }
        TURN { MOVE(opponentLeft, MOVE_LIGHT_SCREEN); MOVE(opponentRight, MOVE_TAILWIND); }
        TURN { MOVE(playerLeft, MOVE_COURT_CHANGE); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        MESSAGE("Okéoké utilise\nChute de Neige!");
        MESSAGE("Qulbutoké ennemi utilise\nBrume!");
        MESSAGE("Qulbutoké ennemi utilise\nRune Protect!");
        MESSAGE("Qulbutoké ennemi utilise\nVoile Aurore!");
        MESSAGE("Qulbutoké ennemi utilise\nProtection!");
        MESSAGE("Qulbutoké ennemi utilise\nMur Lumière!");
        MESSAGE("Qulbutoké ennemi utilise\nVent Arrière!");
        MESSAGE("Okéoké utilise\nChange-Côté!");
        MESSAGE("Les effets affectant chaque côté du terrain ont été échangés par Okéoké!");
        // The effects now end for the player side.
        MESSAGE("La brume autour de votre équipe s'est dissipée!");
        MESSAGE("Brume de votre équipe s'est dissipé!");
        MESSAGE("Protection de votre équipe s'est dissipé!");
        MESSAGE("Le vent arrière soufflant sur votre équipe s'arrête!");
        MESSAGE("Voile Aurore de votre équipe s'est dissipé!");
        MESSAGE("Mur Lumière de votre équipe s'est dissipé!");
    }
}

DOUBLE_BATTLE_TEST("Court Change used by the opponent swaps Mist, Safeguard, Aurora Veil, Reflect, Light Screen, Tailwind")
{
    GIVEN {
        WITH_CONFIG(B_TAILWIND_TURNS, GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SNOWSCAPE); MOVE(playerLeft, MOVE_MIST); MOVE(playerRight, MOVE_SAFEGUARD); }
        TURN { MOVE(playerLeft, MOVE_AURORA_VEIL); MOVE(playerRight, MOVE_REFLECT); }
        TURN { MOVE(playerLeft, MOVE_LIGHT_SCREEN); MOVE(playerRight, MOVE_TAILWIND); }
        TURN { MOVE(opponentLeft, MOVE_COURT_CHANGE); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        MESSAGE("Qulbutoké utilise\nBrume!");
        MESSAGE("Qulbutoké utilise\nRune Protect!");
        MESSAGE("Qulbutoké utilise\nVoile Aurore!");
        MESSAGE("Qulbutoké utilise\nProtection!");
        MESSAGE("Qulbutoké utilise\nMur Lumière!");
        MESSAGE("Qulbutoké utilise\nVent Arrière!");
        MESSAGE("Okéoké ennemi utilise\nChange-Côté!");
        MESSAGE("Les effets affectant chaque côté du terrain ont été échangés par Okéoké ennemi!");
        // The effects now end for the player side.
        MESSAGE("La neige s'est arrêtée.");
        MESSAGE("La brume autour de l'équipe ennemie s'est dissipée!");
        MESSAGE("Brume de l'équipe ennemie s'est dissipé!");
        MESSAGE("Protection de l'équipe ennemie s'est dissipé!");
        MESSAGE("Le vent arrière soufflant sur l'équipe ennemie s'arrête!");
        MESSAGE("Voile Aurore de l'équipe ennemie s'est dissipé!");
        MESSAGE("Mur Lumière de l'équipe ennemie s'est dissipé!");
    }
}

DOUBLE_BATTLE_TEST("Court Change used by the player swaps G-Max Steelsurge")
{
    GIVEN {
        PLAYER(SPECIES_COPPERAJAH) { GigantamaxFactor(TRUE); }
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT) { HP(999); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_IRON_HEAD, target: opponentRight, gimmick: GIMMICK_DYNAMAX); }
        TURN { MOVE(opponentLeft, MOVE_COURT_CHANGE); }
        TURN { SWITCH(opponentLeft, 2); SWITCH(playerLeft, 2); }
    } SCENE {
        MESSAGE("Pachyradjah utilise\nPercée G-Max!");
        SEND_IN_MESSAGE("Qulbutoké");
        MESSAGE("L'acier pointu transperce Qulbutoké!");
        NOT MESSAGE("L'acier pointu transperce Okéoké ennemi!");
    }
}

DOUBLE_BATTLE_TEST("Court Change used by the player swaps G-Max Vine Lash, G-Max Wildfire, G-Max Cannonade")
{
    u32 species, move;
    PARAMETRIZE { species = SPECIES_VENUSAUR;  move = MOVE_VINE_WHIP; }
    PARAMETRIZE { species = SPECIES_CHARIZARD; move = MOVE_EMBER; }
    PARAMETRIZE { species = SPECIES_BLASTOISE; move = MOVE_WATER_GUN; }
    GIVEN {
        PLAYER(species) { GigantamaxFactor(TRUE); }
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN {
            MOVE(playerLeft, move, target: opponentRight, gimmick: GIMMICK_DYNAMAX);
            MOVE(opponentLeft, MOVE_COURT_CHANGE);
        }
    } SCENE {
        switch (species) {
            case SPECIES_VENUSAUR:
                MESSAGE("Florizarre utilise\nFouet G-Max!");
                MESSAGE("Qulbutoké subit des coups de Fouet G-Max!");
                break;
            case SPECIES_CHARIZARD:
                MESSAGE("Dracaufeu utilise\nFournaise G-Max!");
                MESSAGE("Qulbutoké est brûlé par les flammes de Fournaise G-Max!");
                break;
            case SPECIES_BLASTOISE:
                MESSAGE("Tortank utilise\nCanonnade G-Max!");
                MESSAGE("Qulbutoké subit la violence du tourbillon provoqué par Canonnade G-Max!");
                break;
        }
        NONE_OF {
            MESSAGE("Okéoké ennemi subit des coups de Fouet G-Max!");
            MESSAGE("Okéoké ennemi est brûlé par les flammes de Fournaise G-Max!");
            MESSAGE("Okéoké ennemi subit la violence du tourbillon provoqué par Canonnade G-Max!");
        }
    }
}

AI_SINGLE_BATTLE_TEST("AI uses Court Change")
{
    enum Move move;

    PARAMETRIZE { move = MOVE_HEADBUTT; }
    PARAMETRIZE { move = MOVE_REFLECT; }
    PARAMETRIZE { move = MOVE_LIGHT_SCREEN; }
    PARAMETRIZE { move = MOVE_SAFEGUARD; }
    PARAMETRIZE { move = MOVE_SPIKES; }
    PARAMETRIZE { move = MOVE_STEALTH_ROCK; }
    PARAMETRIZE { move = MOVE_TOXIC_SPIKES; }
    PARAMETRIZE { move = MOVE_TAILWIND; }
    PARAMETRIZE { move = MOVE_STICKY_WEB; }
    PARAMETRIZE { move = MOVE_MIST; }
    PARAMETRIZE { move = MOVE_LUCKY_CHANT; }

    GIVEN {
        AI_FLAGS(AI_FLAG_CHECK_BAD_MOVE | AI_FLAG_CHECK_VIABILITY | AI_FLAG_TRY_TO_FAINT);
        PLAYER(SPECIES_ZIGZAGOON) { Moves(move, MOVE_CELEBRATE); }
        PLAYER(SPECIES_ZIGZAGOON) { Moves(move, MOVE_CELEBRATE); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_COURT_CHANGE, MOVE_HEADBUTT); }
        OPPONENT(SPECIES_ZIGZAGOON) { Moves(MOVE_COURT_CHANGE, MOVE_HEADBUTT); }
    } WHEN {
        TURN { MOVE(player, move); EXPECT_MOVE(opponent, MOVE_HEADBUTT); }
        if (move == MOVE_HEADBUTT)
            TURN { MOVE(player, MOVE_CELEBRATE); NOT_EXPECT_MOVE(opponent, MOVE_COURT_CHANGE); }
        else
            TURN { MOVE(player, MOVE_CELEBRATE); EXPECT_MOVE(opponent, MOVE_COURT_CHANGE); }
    }
}

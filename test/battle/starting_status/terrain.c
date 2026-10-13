#include "global.h"
#include "event_data.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("SetStartingStatus starts a chosen terrain at the beginning of battle and lasts infinitely long if it's defined as such")
{
    u16 terrain;

    PARAMETRIZE { terrain = STARTING_STATUS_GRASSY_TERRAIN; }
    PARAMETRIZE { terrain = STARTING_STATUS_PSYCHIC_TERRAIN; }
    PARAMETRIZE { terrain = STARTING_STATUS_MISTY_TERRAIN; }
    PARAMETRIZE { terrain = STARTING_STATUS_ELECTRIC_TERRAIN; }
    PARAMETRIZE { terrain = STARTING_STATUS_ELECTRIC_TERRAIN_TEMPORARY; }

    SetStartingStatus(terrain);

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        // More than 5 turns
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        switch (terrain)
        {
        case STARTING_STATUS_GRASSY_TERRAIN:
            MESSAGE("Un beau gazon recouvre le terrain!");
            break;
        case STARTING_STATUS_PSYCHIC_TERRAIN:
            MESSAGE("Le sol réagit de façon étrange…");
            break;
        case STARTING_STATUS_MISTY_TERRAIN:
            MESSAGE("Le terrain est couvert de brume!");
            break;
        case STARTING_STATUS_ELECTRIC_TERRAIN:
            MESSAGE("De l'électricité parcourt le terrain!");
            break;
        }
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_RESTORE_BG);
        if (terrain != STARTING_STATUS_ELECTRIC_TERRAIN_TEMPORARY) {
            NONE_OF {
                ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_RESTORE_BG);
                MESSAGE("Le sol redevient normal.");
                MESSAGE("L'électricité parcourant le terrain s'est dissipée.");
                MESSAGE("La brume qui recouvrait le terrain se dissipe.");
                MESSAGE("Le gazon disparaît.");
            }
        } else {
            MESSAGE("L'électricité parcourant le terrain s'est dissipée.");
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_RESTORE_BG);
        }
    } THEN {
        ResetStartingStatuses();
    }
}

SINGLE_BATTLE_TEST("Terrain started after the one which started the battle lasts only 5 turns")
{
    bool32 viaMove;

    PARAMETRIZE { viaMove = TRUE; }
    PARAMETRIZE { viaMove = FALSE; }

    SetStartingStatus(STARTING_STATUS_ELECTRIC_TERRAIN);

    GIVEN {
        PLAYER(SPECIES_TAPU_BULU) { Ability(viaMove == TRUE ? ABILITY_TELEPATHY : ABILITY_GRASSY_SURGE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        // More than 5 turns
        TURN { MOVE(player, viaMove == TRUE ? MOVE_GRASSY_TERRAIN : MOVE_CELEBRATE); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        // Electric Terrain at battle's start
        MESSAGE("De l'électricité parcourt le terrain!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_RESTORE_BG);
        // Player uses Grassy Terrain
        if (viaMove) {
            MESSAGE("Tokotoro utilise\nChamp Herbu!");
            ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASSY_TERRAIN, player);
            MESSAGE("Un beau gazon pousse sur le terrain!");
        } else {
            ABILITY_POPUP(player, ABILITY_GRASSY_SURGE);
            MESSAGE("Un beau gazon pousse sur le terrain!");
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_RESTORE_BG);
        }

        // 5 turns
        MESSAGE("Tokotoro utilise\nCélébration!");
        MESSAGE("Qulbutoké ennemi utilise\nCélébration!");

        MESSAGE("Tokotoro utilise\nCélébration!");
        MESSAGE("Qulbutoké ennemi utilise\nCélébration!");

        MESSAGE("Tokotoro utilise\nCélébration!");
        MESSAGE("Qulbutoké ennemi utilise\nCélébration!");

        MESSAGE("Le gazon disparaît.");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_RESTORE_BG);
    } THEN {
        ResetStartingStatuses();
    }
}

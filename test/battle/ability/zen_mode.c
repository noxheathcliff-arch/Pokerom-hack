#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Zen Mode switches Darmanitan's form when HP is half or less at the end of the turn")
{
    u16 standardSpecies, zenSpecies;
    PARAMETRIZE { standardSpecies = SPECIES_DARMANITAN_STANDARD;          zenSpecies = SPECIES_DARMANITAN_ZEN; }
    PARAMETRIZE { standardSpecies = SPECIES_DARMANITAN_GALAR_STANDARD; zenSpecies = SPECIES_DARMANITAN_GALAR_ZEN; }

    GIVEN {
        ASSUME(GetSpeciesBaseHP(standardSpecies) == 105);
        ASSUME(GetSpeciesBaseHP(zenSpecies) == 105);
        PLAYER(standardSpecies)
        {
            Ability(ABILITY_ZEN_MODE);
            HP((GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP) / 2) + 1);
        }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
            TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Darumacho utilise\nCélébration!");
        MESSAGE("Qulbutoké ennemi utilise\nGriffe!");
        HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_ZEN_MODE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Le talent Mode Transe s'active!");
    } THEN {
        EXPECT_LT(player->hp, player->maxHP / 2);
        EXPECT_EQ(player->species, zenSpecies);
    }
}

SINGLE_BATTLE_TEST("Zen Mode switches Darmanitan's form to Standard when swapped out")
{
    u16 standardSpecies, zenSpecies;
    PARAMETRIZE { standardSpecies = SPECIES_DARMANITAN_STANDARD;          zenSpecies = SPECIES_DARMANITAN_ZEN; }
    PARAMETRIZE { standardSpecies = SPECIES_DARMANITAN_GALAR_STANDARD;    zenSpecies = SPECIES_DARMANITAN_GALAR_ZEN; }

    GIVEN {
        ASSUME(GetSpeciesBaseHP(standardSpecies) == 105);
        ASSUME(GetSpeciesBaseHP(zenSpecies) == 105);
        PLAYER(standardSpecies)
        {
            Ability(ABILITY_ZEN_MODE);
            HP(GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP) / 2);
        }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { SWITCH(player, 1); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { SWITCH(player, 0); MOVE(opponent, MOVE_CELEBRATE); }
    } SCENE {
        MESSAGE("Darumacho utilise\nCélébration!");
        MESSAGE("Qulbutoké ennemi utilise\nCélébration!");
        ABILITY_POPUP(player, ABILITY_ZEN_MODE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Le talent Mode Transe s'active!");
        MESSAGE("Qulbutoké! Go!");
        MESSAGE("Qulbutoké ennemi utilise\nCélébration!");
        MESSAGE("Darumacho! Go!");
        MESSAGE("Qulbutoké ennemi utilise\nCélébration!");
        ABILITY_POPUP(player, ABILITY_ZEN_MODE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Le talent Mode Transe s'active!");
    } THEN {
        EXPECT_LE(player->hp, player->maxHP / 2);
        EXPECT_EQ(player->species, zenSpecies);
    }
}

SINGLE_BATTLE_TEST("Zen Mode switches Darmanitan's form when HP is healed above half")
{
    u16 standardSpecies, zenSpecies;
    PARAMETRIZE { standardSpecies = SPECIES_DARMANITAN_STANDARD;          zenSpecies = SPECIES_DARMANITAN_ZEN; }
    PARAMETRIZE { standardSpecies = SPECIES_DARMANITAN_GALAR_STANDARD;    zenSpecies = SPECIES_DARMANITAN_GALAR_ZEN; }

    GIVEN {
        ASSUME(GetSpeciesBaseHP(standardSpecies) == 105);
        ASSUME(GetSpeciesBaseHP(zenSpecies) == 105);
        PLAYER(standardSpecies)
        {
            Ability(ABILITY_ZEN_MODE);
            HP(GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP) / 2);
        }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_CELEBRATE); }
        TURN { MOVE(player, MOVE_CELEBRATE); MOVE(opponent, MOVE_HEAL_PULSE); }
    } SCENE {
        MESSAGE("Darumacho utilise\nCélébration!");
        MESSAGE("Qulbutoké ennemi utilise\nCélébration!");
        ABILITY_POPUP(player, ABILITY_ZEN_MODE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Le talent Mode Transe s'active!");
        MESSAGE("Darumacho utilise\nCélébration!");
        MESSAGE("Qulbutoké ennemi utilise\nVibra Soin!");
        HP_BAR(player);
        ABILITY_POPUP(player, ABILITY_ZEN_MODE);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_FORM_CHANGE, player);
        MESSAGE("Le talent Mode Transe n'est plus actif!");
    } THEN {
        EXPECT_GT(player->hp, player->maxHP / 2);
        EXPECT_EQ(player->species, standardSpecies);
    }
}

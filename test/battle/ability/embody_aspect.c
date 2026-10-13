#include "global.h"
#include "test/battle.h"


SINGLE_BATTLE_TEST("Embody Aspect raises a stat depending on the users form by one stage")
{
    u16 species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_OGERPON_TEAL_TERA; ability = ABILITY_EMBODY_ASPECT_TEAL_MASK; }
    PARAMETRIZE { species = SPECIES_OGERPON_HEARTHFLAME_TERA; ability = ABILITY_EMBODY_ASPECT_HEARTHFLAME_MASK; }
    PARAMETRIZE { species = SPECIES_OGERPON_WELLSPRING_TERA; ability = ABILITY_EMBODY_ASPECT_WELLSPRING_MASK; }
    PARAMETRIZE { species = SPECIES_OGERPON_CORNERSTONE_TERA; ability = ABILITY_EMBODY_ASPECT_CORNERSTONE_MASK; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(species) { Ability(ability); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponent, ability);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        if (ability == ABILITY_EMBODY_ASPECT_TEAL_MASK)
            MESSAGE("Ah, Vitesse du Ogerpon ennemi augmente!");
        else if (ability == ABILITY_EMBODY_ASPECT_HEARTHFLAME_MASK)
            MESSAGE("Ah, Attaque du Ogerpon ennemi augmente!");
        else if (ability == ABILITY_EMBODY_ASPECT_WELLSPRING_MASK)
            MESSAGE("Ah, Défense Spéciale du Ogerpon ennemi augmente!");
        else if (ability == ABILITY_EMBODY_ASPECT_CORNERSTONE_MASK)
            MESSAGE("Ah, Défense du Ogerpon ennemi augmente!");
    } THEN {
        if (ability == ABILITY_EMBODY_ASPECT_TEAL_MASK)
            EXPECT_EQ(opponent->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
        else if (ability == ABILITY_EMBODY_ASPECT_HEARTHFLAME_MASK)
            EXPECT_EQ(opponent->statStages[STAT_ATK], DEFAULT_STAT_STAGE + 1);
        else if (ability == ABILITY_EMBODY_ASPECT_WELLSPRING_MASK)
            EXPECT_EQ(opponent->statStages[STAT_SPDEF], DEFAULT_STAT_STAGE + 1);
        else if (ability == ABILITY_EMBODY_ASPECT_CORNERSTONE_MASK)
            EXPECT_EQ(opponent->statStages[STAT_DEF], DEFAULT_STAT_STAGE + 1);
    }
}

SINGLE_BATTLE_TEST("Embody Aspect activates when it's no longer effected by Neutralizing Gas")
{
    GIVEN {
        PLAYER(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_OGERPON_TEAL_TERA) { Ability(ABILITY_EMBODY_ASPECT_TEAL_MASK); }
    } WHEN {
        TURN { SWITCH(player, 1); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Un gaz inhibiteur envahit les lieux!");
        SWITCH_OUT_MESSAGE("Smogogo");
        MESSAGE("Les effets du gaz inhibiteur se sont dissipés.");
        ABILITY_POPUP(opponent, ABILITY_EMBODY_ASPECT_TEAL_MASK);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, opponent);
        MESSAGE("Ah, Vitesse du Ogerpon ennemi augmente!");
    }
}

SINGLE_BATTLE_TEST("Embody Aspect does not reactivate after Neutralizing Gas ends if it already activated this switch-in")
{
    GIVEN {
        PLAYER(SPECIES_OGERPON_TEAL_TERA) { Ability(ABILITY_EMBODY_ASPECT_TEAL_MASK); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WEEZING) { Ability(ABILITY_NEUTRALIZING_GAS); }
    } WHEN {
        TURN { SWITCH(opponent, 1); }
        TURN { SWITCH(opponent, 0); }
    } SCENE {
        ABILITY_POPUP(player, ABILITY_EMBODY_ASPECT_TEAL_MASK);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_STATS_CHANGE, player);
        MESSAGE("Ah, Vitesse du Ogerpon augmente!");

        ABILITY_POPUP(opponent, ABILITY_NEUTRALIZING_GAS);
        MESSAGE("Un gaz inhibiteur envahit les lieux!");

        MESSAGE("Les effets du gaz inhibiteur se sont dissipés.");
        NOT ABILITY_POPUP(player, ABILITY_EMBODY_ASPECT_TEAL_MASK);
    } THEN {
        EXPECT_EQ(player->statStages[STAT_SPEED], DEFAULT_STAT_STAGE + 1);
    }
}

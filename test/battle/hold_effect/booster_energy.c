#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_BOOSTER_ENERGY].holdEffect == HOLD_EFFECT_BOOSTER_ENERGY);
}

SINGLE_BATTLE_TEST("Booster Energy will activate Quark Drive after Electric Terrain ends")
{
    GIVEN {
        PLAYER(SPECIES_IRON_MOTH) { Attack(100); Defense(100); Speed(100); SpAttack(110); SpDefense(100); Ability(ABILITY_QUARK_DRIVE); Item(ITEM_BOOSTER_ENERGY); }
        OPPONENT(SPECIES_TAPU_KOKO) { Speed(100); Ability(ABILITY_ELECTRIC_SURGE); }
    } WHEN {
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_ELECTRIC_SURGE);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Mite-de-Fer a activé Charge Quantique grâce à son Énergie Booster!");
            MESSAGE("Attaque Spéciale de Mite-de-Fer est renforcé!");
        }
        ABILITY_POPUP(player, ABILITY_QUARK_DRIVE);
        MESSAGE("Mite-de-Fer a activé Charge Quantique grâce au champ électrifié!");
        MESSAGE("Attaque Spéciale de Mite-de-Fer est renforcé!");
        MESSAGE("L'électricité parcourant le terrain s'est dissipée.");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        ABILITY_POPUP(player, ABILITY_QUARK_DRIVE);
        MESSAGE("Mite-de-Fer a activé Charge Quantique grâce à son Énergie Booster!");
        MESSAGE("Attaque Spéciale de Mite-de-Fer est renforcé!");
    }
}

SINGLE_BATTLE_TEST("Booster Energy will activate Protosynthesis after harsh sunlight ends")
{
    GIVEN {
        WITH_CONFIG(B_ABILITY_WEATHER, GEN_6);
        PLAYER(SPECIES_RAGING_BOLT) { Attack(100); Defense(100); Speed(100); SpAttack(110); SpDefense(100); Ability(ABILITY_PROTOSYNTHESIS); Item(ITEM_BOOSTER_ENERGY); }
        OPPONENT(SPECIES_TORKOAL) { Speed(100); Ability(ABILITY_DROUGHT); }
    } WHEN {
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_DROUGHT);
        NONE_OF {
            ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
            MESSAGE("Ire-Foudre a activé Paléosynthèse grâce à son Énergie Booster!");
            MESSAGE("Attaque Spéciale de Ire-Foudre est renforcé!");
        }
        ABILITY_POPUP(player, ABILITY_PROTOSYNTHESIS);
        MESSAGE("Le soleil brille, ce qui a permis à Ire-Foudre d'activer Paléosynthèse!");
        MESSAGE("Attaque Spéciale de Ire-Foudre est renforcé!");
        MESSAGE("Les rayons du soleil s'affaiblissent.");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        ABILITY_POPUP(player, ABILITY_PROTOSYNTHESIS);
        MESSAGE("Ire-Foudre a activé Paléosynthèse grâce à son Énergie Booster!");
        MESSAGE("Attaque Spéciale de Ire-Foudre est renforcé!");
    }
}

SINGLE_BATTLE_TEST("Booster Energy's Protosynthesis boost is preserved when weather changes")
{
    GIVEN {
        PLAYER(SPECIES_RAGING_BOLT) { Attack(110); Defense(100); Speed(100); SpAttack(100); SpDefense(100); Ability(ABILITY_PROTOSYNTHESIS); Item(ITEM_BOOSTER_ENERGY); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); Moves(MOVE_SUNNY_DAY, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SUNNY_DAY); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Ire-Foudre a activé Paléosynthèse grâce à son Énergie Booster!");
        MESSAGE("Attaque de Ire-Foudre est renforcé!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUNNY_DAY, opponent);
        MESSAGE("Les rayons du soleil s'affaiblissent.");
    } THEN {
        EXPECT(gBattleMons[B_POSITION_PLAYER_LEFT].volatiles.paradoxBoostedStat == STAT_ATK);
    }
}

SINGLE_BATTLE_TEST("Booster Energy activates Protosynthesis and increases highest stat")
{
    u32 attack, defense, speed, spAttack, spDefense;

    PARAMETRIZE { attack = 110; defense = 100; speed = 100; spAttack = 100; spDefense = 100; }
    PARAMETRIZE { attack = 100; defense = 110; speed = 100; spAttack = 100; spDefense = 100; }
    PARAMETRIZE { attack = 100; defense = 100; speed = 110; spAttack = 100; spDefense = 100; }
    PARAMETRIZE { attack = 100; defense = 100; speed = 100; spAttack = 110; spDefense = 100; }
    PARAMETRIZE { attack = 100; defense = 100; speed = 100; spAttack = 100; spDefense = 110; }

    GIVEN {
        PLAYER(SPECIES_RAGING_BOLT) { Attack(attack); Defense(defense); Speed(speed); SpAttack(spAttack); SpDefense(spDefense); Ability(ABILITY_PROTOSYNTHESIS); Item(ITEM_BOOSTER_ENERGY); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); }
    } WHEN {
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        ABILITY_POPUP(player, ABILITY_PROTOSYNTHESIS);
        MESSAGE("Ire-Foudre a activé Paléosynthèse grâce à son Énergie Booster!");
        if (attack == 110)
            MESSAGE("Attaque de Ire-Foudre est renforcé!");
        else if (defense == 110)
            MESSAGE("Défense de Ire-Foudre est renforcé!");
        else if (speed == 110)
            MESSAGE("Vitesse de Ire-Foudre est renforcé!");
        else if (spAttack == 110)
            MESSAGE("Attaque Spéciale de Ire-Foudre est renforcé!");
        else if (spDefense == 110)
            MESSAGE("Défense Spéciale de Ire-Foudre est renforcé!");
    } THEN {
        EXPECT(player->item == ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Booster Energy activates Quark Drive and increases highest stat")
{
    u32 attack, defense, speed, spAttack, spDefense;

    PARAMETRIZE { attack = 110; defense = 100; speed = 100; spAttack = 100; spDefense = 100; }
    PARAMETRIZE { attack = 100; defense = 110; speed = 100; spAttack = 100; spDefense = 100; }
    PARAMETRIZE { attack = 100; defense = 100; speed = 110; spAttack = 100; spDefense = 100; }
    PARAMETRIZE { attack = 100; defense = 100; speed = 100; spAttack = 110; spDefense = 100; }
    PARAMETRIZE { attack = 100; defense = 100; speed = 100; spAttack = 100; spDefense = 110; }

    GIVEN {
        PLAYER(SPECIES_IRON_MOTH) { Attack(attack); Defense(defense); Speed(speed); SpAttack(spAttack); SpDefense(spDefense); Ability(ABILITY_QUARK_DRIVE); Item(ITEM_BOOSTER_ENERGY); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); }
    } WHEN {
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        if (attack == 110)
            MESSAGE("Attaque de Mite-de-Fer est renforcé!");
        else if (defense == 110)
            MESSAGE("Défense de Mite-de-Fer est renforcé!");
        else if (speed == 110)
            MESSAGE("Vitesse de Mite-de-Fer est renforcé!");
        else if (spAttack == 110)
            MESSAGE("Attaque Spéciale de Mite-de-Fer est renforcé!");
        else if (spDefense == 110)
            MESSAGE("Défense Spéciale de Mite-de-Fer est renforcé!");
    } THEN {
        EXPECT(player->item == ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Booster Energy's Quark Drive boost is preserved when terrain changes")
{
    GIVEN {
        PLAYER(SPECIES_IRON_MOTH) { Attack(110); Defense(100); Speed(100); SpAttack(100); SpDefense(100); Ability(ABILITY_QUARK_DRIVE); Item(ITEM_BOOSTER_ENERGY); Moves(MOVE_CELEBRATE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(50); Moves(MOVE_GRASSY_TERRAIN, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_GRASSY_TERRAIN); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, player);
        MESSAGE("Mite-de-Fer a activé Charge Quantique grâce à son Énergie Booster!");
        MESSAGE("Attaque de Mite-de-Fer est renforcé!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASSY_TERRAIN, opponent);
        MESSAGE("Le gazon disparaît.");
    } THEN {
        EXPECT(gBattleMons[B_POSITION_PLAYER_LEFT].volatiles.paradoxBoostedStat == STAT_ATK);
    }
}

SINGLE_BATTLE_TEST("Booster Energy increases special attack by 30% if it is the highest stat", s16 damage)
{
    u32 species;
    enum Ability ability;
    enum Item item;

    PARAMETRIZE { species = SPECIES_RAGING_BOLT; ability = ABILITY_PROTOSYNTHESIS; item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_RAGING_BOLT; ability = ABILITY_PROTOSYNTHESIS; item = ITEM_BOOSTER_ENERGY; }

    PARAMETRIZE { species = SPECIES_IRON_MOTH; ability = ABILITY_QUARK_DRIVE; item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_IRON_MOTH; ability = ABILITY_QUARK_DRIVE; item = ITEM_BOOSTER_ENERGY; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_ROUND) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(species) { Attack(100); Defense(100); Speed(100); SpAttack(110); SpDefense(100); Ability(ability); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(player, MOVE_ROUND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.3), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Booster Energy increases special defense by 30% if it is the highest stat", s16 damage)
{
    u32 species;
    enum Ability ability;
    enum Item item;

    PARAMETRIZE { species = SPECIES_RAGING_BOLT; ability = ABILITY_PROTOSYNTHESIS; item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_RAGING_BOLT; ability = ABILITY_PROTOSYNTHESIS; item = ITEM_BOOSTER_ENERGY; }

    PARAMETRIZE { species = SPECIES_IRON_MOTH; ability = ABILITY_QUARK_DRIVE; item = ITEM_NONE; }
    PARAMETRIZE { species = SPECIES_IRON_MOTH; ability = ABILITY_QUARK_DRIVE; item = ITEM_BOOSTER_ENERGY; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_ROUND) == DAMAGE_CATEGORY_SPECIAL);
        PLAYER(species) { Attack(100); Defense(100); Speed(100); SpAttack(100); SpDefense(110); Ability(ability); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_ROUND); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROUND, opponent);
        HP_BAR(player, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.77), results[1].damage);
        EXPECT_MUL_EQ(results[2].damage, Q_4_12(0.77), results[3].damage);
    }
}

SINGLE_BATTLE_TEST("Booster Energy can't be tricked if a Paradox species is involved")
{
    GIVEN {
        ASSUME(gSpeciesInfo[SPECIES_IRON_MOTH].isParadox == TRUE);
        PLAYER(SPECIES_IRON_MOTH) { Item(ITEM_BERRY_JUICE); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_BOOSTER_ENERGY); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_TRICK); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_TRICK, opponent);
        MESSAGE("Mais cela échoue!");
    }
}

DOUBLE_BATTLE_TEST("Booster Energy triggers correctly for all battlers if multiple fainted the previous turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_CATERPIE) { HP(1); }
        PLAYER(SPECIES_GOUGING_FIRE) { Item(ITEM_BOOSTER_ENERGY); }
        PLAYER(SPECIES_IRON_MOTH) { Item(ITEM_BOOSTER_ENERGY); }
        OPPONENT(SPECIES_CATERPIE) { HP(1); }
        OPPONENT(SPECIES_CATERPIE) { HP(1); }
        OPPONENT(SPECIES_FLUTTER_MANE) { Item(ITEM_BOOSTER_ENERGY); }
        OPPONENT(SPECIES_CATERPIE);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_EXPLOSION);
               SEND_OUT(opponentRight, 3);
               SEND_OUT(opponentLeft, 2);
               SEND_OUT(playerRight, 3);
               SEND_OUT(playerLeft, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPLOSION, playerLeft);
        ABILITY_POPUP(playerLeft, ABILITY_PROTOSYNTHESIS);
        ABILITY_POPUP(playerRight, ABILITY_QUARK_DRIVE);
        ABILITY_POPUP(opponentLeft, ABILITY_PROTOSYNTHESIS);
    }
}

DOUBLE_BATTLE_TEST("Booster Energy activates on any terrain")
{
    GIVEN {
        PLAYER(SPECIES_IRON_MOTH) { Speed(110); Ability(ABILITY_QUARK_DRIVE); Item(ITEM_BOOSTER_ENERGY); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(80); }
        OPPONENT(SPECIES_TAPU_BULU) { Speed(100); Ability(ABILITY_GRASSY_SURGE); }
        OPPONENT(SPECIES_TAPU_KOKO) { Speed(10); Ability(ABILITY_ELECTRIC_SURGE); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_GRASSY_SURGE);
        ABILITY_POPUP(playerLeft, ABILITY_QUARK_DRIVE);
        ABILITY_POPUP(opponentRight, ABILITY_ELECTRIC_SURGE);
    }
}

DOUBLE_BATTLE_TEST("Booster Energy activates on air locked sun")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_RAGING_BOLT) { Ability(ABILITY_PROTOSYNTHESIS); Item(ITEM_BOOSTER_ENERGY); }
        OPPONENT(SPECIES_PSYDUCK) { Ability(ABILITY_CLOUD_NINE); }
        OPPONENT(SPECIES_TORKOAL) { Ability(ABILITY_DROUGHT); }
    } WHEN {
        TURN { SWITCH(playerLeft, 2); }
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_CLOUD_NINE);
        ABILITY_POPUP(opponentRight, ABILITY_DROUGHT);
        ABILITY_POPUP(playerLeft, ABILITY_PROTOSYNTHESIS);
    }
}

DOUBLE_BATTLE_TEST("Booster Energy will not activate on terrain if user has Protosynthesis instead of Quark Drive")
{
    GIVEN {
        PLAYER(SPECIES_RAGING_BOLT) { Speed(110); Ability(ABILITY_PROTOSYNTHESIS); Item(ITEM_BOOSTER_ENERGY); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(80); }
        OPPONENT(SPECIES_TAPU_BULU) { Speed(100); Ability(ABILITY_GRASSY_SURGE); }
        OPPONENT(SPECIES_TAPU_KOKO) { Speed(10); Ability(ABILITY_ELECTRIC_SURGE); }
    } WHEN {
        TURN {}
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_GRASSY_SURGE);
        NOT ABILITY_POPUP(playerLeft, ABILITY_PROTOSYNTHESIS);
        ABILITY_POPUP(opponentRight, ABILITY_ELECTRIC_SURGE);
        ABILITY_POPUP(playerLeft, ABILITY_PROTOSYNTHESIS); // Activation after all terrains
    }
}

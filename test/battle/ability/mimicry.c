#include "global.h"
#include "test/battle.h"

static const u16 terrainData[][2] =
{
    { MOVE_ELECTRIC_TERRAIN, TYPE_ELECTRIC, },
    { MOVE_PSYCHIC_TERRAIN,  TYPE_PSYCHIC, },
    { MOVE_GRASSY_TERRAIN,   TYPE_GRASS, },
    { MOVE_MISTY_TERRAIN,    TYPE_FAIRY, },
};

SINGLE_BATTLE_TEST("Mimicry changes the battler's type based on Terrain")
{
    u32 j;
    enum Move terrainMove = MOVE_NONE;
    enum Type terrainType = TYPE_NONE;

    for (j = 0; j < ARRAY_COUNT(terrainData); j++)
        PARAMETRIZE { terrainMove = terrainData[j][0]; terrainType = terrainData[j][1]; }

    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_STUNFISK_GALAR) { Ability(ABILITY_MIMICRY); }
    } WHEN {
        TURN { MOVE(player, terrainMove); }
    } SCENE {
        ABILITY_POPUP(opponent);
        switch (terrainMove)
        {
        case MOVE_ELECTRIC_TERRAIN: MESSAGE("Limonde ennemi prend le type Electrik!"); break;
        case MOVE_PSYCHIC_TERRAIN:  MESSAGE("Limonde ennemi prend le type Psy!"); break;
        case MOVE_GRASSY_TERRAIN:   MESSAGE("Limonde ennemi prend le type Plante!"); break;
        case MOVE_MISTY_TERRAIN:    MESSAGE("Limonde ennemi prend le type Fée!"); break;
        default: break;
        }
    } THEN {
        EXPECT_EQ(gBattleMons[B_POSITION_OPPONENT_LEFT].types[0], terrainType);
        EXPECT_EQ(gBattleMons[B_POSITION_OPPONENT_LEFT].types[1], terrainType);
    }
}

SINGLE_BATTLE_TEST("Mimicry restores the battler's types when terrain is removed by Steel Roller and Ice Spinner")
{
    u32 j;
    enum Move terrainMove = MOVE_NONE;
    enum Move removeTerrainMove = MOVE_NONE;

    for (j = 0; j < ARRAY_COUNT(terrainData); j++)
    {
        PARAMETRIZE { removeTerrainMove = MOVE_STEEL_ROLLER; terrainMove = terrainData[j][0]; }
        PARAMETRIZE { removeTerrainMove = MOVE_ICE_SPINNER; terrainMove =  terrainData[j][0]; }
    }

    GIVEN {
        ASSUME(GetSpeciesType(SPECIES_STUNFISK_GALAR, 0) == TYPE_GROUND);
        ASSUME(GetSpeciesType(SPECIES_STUNFISK_GALAR, 1) == TYPE_STEEL);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_STUNFISK_GALAR) { Ability(ABILITY_MIMICRY); }
    } WHEN {
        TURN { MOVE(opponent, terrainMove); MOVE(player, removeTerrainMove); }
    } SCENE {
        switch (terrainMove)
        {
        case MOVE_ELECTRIC_TERRAIN: MESSAGE("L'électricité parcourant le terrain s'est dissipée."); break;
        case MOVE_PSYCHIC_TERRAIN:  MESSAGE("Le sol redevient normal."); break;
        case MOVE_GRASSY_TERRAIN:   MESSAGE("Le gazon disparaît."); break;
        case MOVE_MISTY_TERRAIN:    MESSAGE("La brume qui recouvrait le terrain se dissipe."); break;
        default: break;
        }
    } THEN {
        EXPECT_EQ(gBattleMons[B_POSITION_OPPONENT_LEFT].types[0], TYPE_GROUND);
        EXPECT_EQ(gBattleMons[B_POSITION_OPPONENT_LEFT].types[1], TYPE_STEEL);
    }
}

DOUBLE_BATTLE_TEST("Mimicry can trigger multiple times in a turn")
{
    GIVEN {
        PLAYER(SPECIES_STUNFISK_GALAR) { Speed(50); Ability(ABILITY_MIMICRY); }
        PLAYER(SPECIES_MORELULL) { Speed(40); }
        OPPONENT(SPECIES_IGGLYBUFF) { Speed(60); }
        OPPONENT(SPECIES_BAGON) { Speed(70); }
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_ELECTRIC_TERRAIN); MOVE(opponentLeft, MOVE_MISTY_TERRAIN); }
    } SCENE {
        MESSAGE("Draby ennemi utilise\nChamp Électrifié!");
        ABILITY_POPUP(playerLeft, ABILITY_MIMICRY);
        MESSAGE("Limonde prend le type Electrik!");
        // igglybuff
        MESSAGE("Toudoudou ennemi utilise\nChamp Brumeux!");
        ABILITY_POPUP(playerLeft, ABILITY_MIMICRY);
        MESSAGE("Limonde prend le type Fée!");
    } THEN {
        EXPECT_EQ(gBattleMons[0].types[0], TYPE_FAIRY);
        EXPECT_EQ(gBattleMons[0].types[1], TYPE_FAIRY);
        EXPECT_EQ(gBattleMons[0].types[2], TYPE_MYSTERY);
    }
}

DOUBLE_BATTLE_TEST("Mimicry triggers after Skill Swap")
{
    GIVEN {
        PLAYER(SPECIES_STUNFISK_GALAR) { Speed(40); Ability(ABILITY_MIMICRY); }
        PLAYER(SPECIES_SHIFTRY)        { Speed(50); Ability(ABILITY_CHLOROPHYLL); }
        OPPONENT(SPECIES_SHUCKLE)      { Speed(30); }
        OPPONENT(SPECIES_CHANSEY)      { Speed(20); }
    } WHEN {
        TURN { MOVE(playerRight, MOVE_GRASSY_TERRAIN); }
        TURN { MOVE(playerRight, MOVE_SKILL_SWAP, target: playerLeft);
               MOVE(playerLeft,  MOVE_SPLASH);
             }
    } SCENE {
        // turn 1
        MESSAGE("Tengalice utilise\nChamp Herbu!");
        ABILITY_POPUP(playerLeft, ABILITY_MIMICRY);
        MESSAGE("Limonde prend le type Plante!");
        // turn 2
        MESSAGE("Tengalice utilise\nÉchange!");
        ABILITY_POPUP(playerRight, ABILITY_MIMICRY);
        MESSAGE("Tengalice prend le type Plante!");
        MESSAGE("Limonde utilise\nTrempette!"); // make sure popup occurs before the subsequent move
    } THEN {
        EXPECT_EQ(playerLeft->types[0], TYPE_GRASS);
        EXPECT_EQ(playerLeft->types[1], TYPE_GRASS);
        EXPECT_EQ(playerRight->types[0], TYPE_GRASS);
        EXPECT_EQ(playerRight->types[1], TYPE_GRASS);
    }
}

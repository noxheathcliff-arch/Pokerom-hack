#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_AIR_BALLOON].holdEffect == HOLD_EFFECT_AIR_BALLOON);
    ASSUME(GetMoveType(MOVE_EARTHQUAKE) == TYPE_GROUND);
    ASSUME(GetMoveType(MOVE_SCRATCH) != TYPE_GROUND);
}

SINGLE_BATTLE_TEST("Air Balloon prevents the holder from taking damage from ground type moves")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_EARTHQUAKE); }
    } SCENE {
        MESSAGE("Qulbutoké flotte grâce à son Ballon!");
        MESSAGE("Qulbutoké ennemi utilise\nSéisme!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponent);
        MESSAGE("Ça n'affecte pas Qulbutoké…");
    }
}

SINGLE_BATTLE_TEST("Air Balloon only displays entry message when user switches in")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); };
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        MESSAGE("Qulbutoké flotte grâce à son Ballon!");
        NOT MESSAGE("Qulbutoké flotte grâce à son Ballon!");
    }
}

SINGLE_BATTLE_TEST("Air Balloon pops when the holder is hit by a move that is not ground type")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Qulbutoké flotte grâce à son Ballon!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        MESSAGE("Le Ballon de Qulbutoké a éclaté!");
    }
}

SINGLE_BATTLE_TEST("Air Balloon no longer prevents the holder from taking damage from ground type moves once it has been popped")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
        TURN { MOVE(opponent, MOVE_EARTHQUAKE); }
    } SCENE {
        MESSAGE("Qulbutoké flotte grâce à son Ballon!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        MESSAGE("Le Ballon de Qulbutoké a éclaté!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, opponent);
        NOT MESSAGE("Ça n'affecte pas Qulbutoké…");
    }
}

SINGLE_BATTLE_TEST("Air Balloon can not be restored with Recycle after it has been popped")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_RECYCLE) == EFFECT_RECYCLE);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN {
            MOVE(opponent, MOVE_SCRATCH);
            MOVE(player, MOVE_RECYCLE);
        }
    } SCENE {
        MESSAGE("Qulbutoké flotte grâce à son Ballon!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        MESSAGE("Le Ballon de Qulbutoké a éclaté!");
        MESSAGE("Qulbutoké utilise\nRecyclage!");
        MESSAGE("Mais cela échoue!");
    }
}

SINGLE_BATTLE_TEST("Air Balloon prevents the user from being healed by Grassy Terrain")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_GRASSY_TERRAIN) == EFFECT_GRASSY_TERRAIN);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); MaxHP(100); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_GRASSY_TERRAIN); }
    } SCENE {
        MESSAGE("Qulbutoké flotte grâce à son Ballon!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GRASSY_TERRAIN, player);
        NOT MESSAGE("Qulbutoké is healed by the Champ Herbu!");
    }
}

SINGLE_BATTLE_TEST("Air Balloon pops before it can be stolen with Magician")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); }
        OPPONENT(SPECIES_DELPHOX) { Ability(ABILITY_MAGICIAN); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Qulbutoké flotte grâce à son Ballon!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        MESSAGE("Le Ballon de Qulbutoké a éclaté!");
        NOT ABILITY_POPUP(opponent, ABILITY_MAGICIAN);
    }
}

SINGLE_BATTLE_TEST("Air Balloon pops before it can be stolen by Thief")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_THIEF) == EFFECT_STEAL_ITEM);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_THIEF); }
    } SCENE {
        MESSAGE("Qulbutoké flotte grâce à son Ballon!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_THIEF, opponent);
        MESSAGE("Le Ballon de Qulbutoké a éclaté!");
        NOT MESSAGE("Qulbutoké ennemi vole Ballon de Qulbutoké!");
    }
}

SINGLE_BATTLE_TEST("Air Balloon pops if a damaging move hits the holder's Substitute")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SUBSTITUTE) == EFFECT_SUBSTITUTE);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); Speed(2); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(1); }
    } WHEN {
        TURN {MOVE(player, MOVE_SUBSTITUTE); MOVE(opponent, MOVE_EMBER);}
    } SCENE {
        MESSAGE("Qulbutoké flotte grâce à son Ballon!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SUBSTITUTE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EMBER, opponent);
        MESSAGE("Le Ballon de Qulbutoké a éclaté!");
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

SINGLE_BATTLE_TEST("Air Balloon pops when Disguise is broken")
{
    u32 species, newSpecies;
    PARAMETRIZE { species = SPECIES_MIMIKYU_DISGUISED;       newSpecies = SPECIES_MIMIKYU_BUSTED; }
    PARAMETRIZE { species = SPECIES_MIMIKYU_TOTEM_DISGUISED; newSpecies = SPECIES_MIMIKYU_BUSTED_TOTEM; }
    
    GIVEN {
        PLAYER(species) { Ability(ABILITY_DISGUISE); Item(ITEM_AIR_BALLOON); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_AERIAL_ACE); }
    } SCENE {
        MESSAGE("Mimiqui flotte grâce à son Ballon!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_AERIAL_ACE, opponent);
        ABILITY_POPUP(player, ABILITY_DISGUISE);
        HP_BAR(player);
        MESSAGE("Le Ballon de Mimiqui a éclaté!");
    } THEN {
        EXPECT_EQ(player->species, newSpecies);
    }
}

SINGLE_BATTLE_TEST("Air Balloon pops when the holder faints from a damaging move")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_AIR_BALLOON); HP(1); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Qulbutoké flotte grâce à son Ballon!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, opponent);
        MESSAGE("Le Ballon de Qulbutoké a éclaté!");
        MESSAGE("Qulbutoké est K.O.!\p");
    } THEN {
        EXPECT_EQ(player->item, ITEM_NONE);
    }
}

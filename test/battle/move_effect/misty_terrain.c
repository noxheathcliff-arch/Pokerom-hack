#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Misty Terrain protects grounded battlers from non-volatile status conditions")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CLAYDOL) { Ability(ABILITY_LEVITATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_MISTY_TERRAIN); MOVE(opponent, MOVE_TOXIC); }
        TURN { MOVE(player, MOVE_TOXIC); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MISTY_TERRAIN, player);
        MESSAGE("Kaorine ennemi utilise\nToxik!");
        MESSAGE("Qulbutoké est protégé par un champ brumeux!");
        NOT { STATUS_ICON(opponent, badPoison: TRUE); }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TOXIC, player);
        STATUS_ICON(opponent, badPoison: TRUE);
    }
}

SINGLE_BATTLE_TEST("Misty Terrain does not increase the power of Fairy-type moves", s16 damage)
{
    bool32 terrain;
    PARAMETRIZE { terrain = FALSE; }
    PARAMETRIZE { terrain = TRUE; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_MOONBLAST) == TYPE_FAIRY);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (terrain)
            TURN { MOVE(player, MOVE_MISTY_TERRAIN); }
        TURN { MOVE(player, MOVE_MOONBLAST); }
    } SCENE {
        if (terrain)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_MISTY_TERRAIN, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MOONBLAST, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Misty Terrain decreases power of Dragon-type moves by 50 percent", s16 damage)
{
    bool32 terrain;
    PARAMETRIZE { terrain = FALSE; }
    PARAMETRIZE { terrain = TRUE; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_DRAGON_CLAW) == TYPE_DRAGON);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (terrain)
            TURN { MOVE(player, MOVE_MISTY_TERRAIN); }
        TURN { MOVE(player, MOVE_DRAGON_CLAW); }
    } SCENE {
        if (terrain)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_MISTY_TERRAIN, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_CLAW, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Misty Terrain uses the defender's ability when checking if it is grounded", s16 damage)
{
    bool32 terrain;
    PARAMETRIZE { terrain = FALSE; }
    PARAMETRIZE { terrain = TRUE; }

    GIVEN {
        ASSUME(GetMoveType(MOVE_DRAGON_CLAW) == TYPE_DRAGON);
        PLAYER(SPECIES_ROTOM) { Ability(ABILITY_LEVITATE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (terrain)
            TURN { MOVE(player, MOVE_MISTY_TERRAIN); }
        TURN { MOVE(player, MOVE_DRAGON_CLAW); }
    } SCENE {
        if (terrain)
            ANIMATION(ANIM_TYPE_MOVE, MOVE_MISTY_TERRAIN, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DRAGON_CLAW, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(0.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Misty Terrain lasts for 5 turns")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_MISTY_TERRAIN); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        MESSAGE("Qulbutoké ennemi utilise\nCélébration!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MISTY_TERRAIN, player);
        MESSAGE("La brume recouvre le terrain!");

        MESSAGE("Qulbutoké utilise\nCélébration!");
        MESSAGE("Qulbutoké ennemi utilise\nCélébration!");

        MESSAGE("Qulbutoké utilise\nCélébration!");
        MESSAGE("Qulbutoké ennemi utilise\nCélébration!");

        MESSAGE("Qulbutoké utilise\nCélébration!");
        MESSAGE("Qulbutoké ennemi utilise\nCélébration!");

        MESSAGE("La brume qui recouvrait le terrain se dissipe.");
    }
}

SINGLE_BATTLE_TEST("Misty Terrain will fail if there is one already on the field")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_MISTY_TERRAIN); MOVE(opponent, MOVE_MISTY_TERRAIN); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MISTY_TERRAIN, player);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_MISTY_TERRAIN, opponent);
    }
}

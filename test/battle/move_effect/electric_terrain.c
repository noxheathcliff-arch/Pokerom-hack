#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Electric Terrain protects grounded battlers from falling asleep")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_CLAYDOL) { Ability(ABILITY_LEVITATE); }
    } WHEN {
        TURN { MOVE(player, MOVE_ELECTRIC_TERRAIN); MOVE(opponent, MOVE_SPORE); }
        TURN { MOVE(player, MOVE_SPORE); }
    } SCENE {
        MESSAGE("Qulbutoké utilise\nChamp Électrifié!");
        MESSAGE("Kaorine ennemi utilise\nSpore!");
        MESSAGE("Qulbutoké est protégé par un champ électrifié!");
        MESSAGE("Qulbutoké utilise\nSpore!");
        MESSAGE("Kaorine ennemi s'est endormi!");
        STATUS_ICON(opponent, sleep: TRUE);
    }
}

SINGLE_BATTLE_TEST("Electric Terrain increases power of Electric-type moves by 30/50 percent", s16 damage)
{
    bool32 terrain;
    PARAMETRIZE { terrain = FALSE; }
    PARAMETRIZE { terrain = TRUE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (terrain)
            TURN { MOVE(player, MOVE_ELECTRIC_TERRAIN); }
        TURN { MOVE(player, MOVE_THUNDER_SHOCK); }
    } SCENE {
        MESSAGE("Qulbutoké utilise\nÉclair!");
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        if (B_TERRAIN_TYPE_BOOST >= GEN_8)
            EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.3), results[1].damage);
        else
            EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
    }
}

SINGLE_BATTLE_TEST("Electric Terrain lasts for 5 turns")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CELEBRATE); MOVE(player, MOVE_ELECTRIC_TERRAIN); }
        TURN {}
        TURN {}
        TURN {}
        TURN {}
    } SCENE {
        MESSAGE("Qulbutoké ennemi utilise\nCélébration!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ELECTRIC_TERRAIN, player);
        MESSAGE("De l'électricité parcourt le terrain!");

        MESSAGE("Qulbutoké utilise\nCélébration!");
        MESSAGE("Qulbutoké ennemi utilise\nCélébration!");

        MESSAGE("Qulbutoké utilise\nCélébration!");
        MESSAGE("Qulbutoké ennemi utilise\nCélébration!");

        MESSAGE("Qulbutoké utilise\nCélébration!");
        MESSAGE("Qulbutoké ennemi utilise\nCélébration!");

        MESSAGE("L'électricité parcourant le terrain s'est dissipée.");
    }
}

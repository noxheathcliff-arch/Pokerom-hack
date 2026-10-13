#include "global.h"
#include "test/battle.h"

TO_DO_BATTLE_TEST("Conversion 2's type change considers Inverse Battles");

SINGLE_BATTLE_TEST("Conversion 2 randomly changes the type of the user to a type that resists the last move that hit the user (Gen 1-4)")
{
    GIVEN {
        WITH_CONFIG(B_UPDATED_CONVERSION_2, GEN_4);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_OMINOUS_WIND); MOVE(opponent, MOVE_CONVERSION_2); }
    } SCENE {
        // turn 1
        MESSAGE("Qulbutoké utilise\nVent Mauvais!");
        // turn 1
        ONE_OF {
            MESSAGE("Qulbutoké ennemi prend le type Normal!");
            MESSAGE("Qulbutoké ennemi prend le type Ténèbres!");
        }
    }
}

SINGLE_BATTLE_TEST("Conversion 2's type change considers Struggle to be Normal type (Gen 1-4)")
{
    GIVEN {
        WITH_CONFIG(B_UPDATED_CONVERSION_2, GEN_4);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_STRUGGLE); }
        TURN { MOVE(player, MOVE_CONVERSION_2); }
    } SCENE {
        // turn 1
        MESSAGE("Qulbutoké ennemi utilise\nLutte!");
        // turn 2
        ONE_OF {
            MESSAGE("Qulbutoké prend le type Acier!");
            MESSAGE("Qulbutoké prend le type Roche!");
            MESSAGE("Qulbutoké prend le type Spectre!");
        }
    }
}

SINGLE_BATTLE_TEST("Conversion 2 randomly changes the type of the user to a type that resists the last used target's move (Gen 5+)")
{
    GIVEN {
        WITH_CONFIG(B_UPDATED_CONVERSION_2, GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_OMINOUS_WIND); MOVE(opponent, MOVE_CONVERSION_2); }
    } SCENE {
        // turn 1
        MESSAGE("Qulbutoké utilise\nVent Mauvais!");
        // turn 1
        ONE_OF {
            MESSAGE("Qulbutoké ennemi prend le type Normal!");
            MESSAGE("Qulbutoké ennemi prend le type Ténèbres!");
        }
    }
}

SINGLE_BATTLE_TEST("Conversion 2's type change considers status moves (Gen 5+)")
{
    GIVEN {
        WITH_CONFIG(B_UPDATED_CONVERSION_2, GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CURSE); }
        TURN { MOVE(player, MOVE_CONVERSION_2); }
    } SCENE {
        // turn 1
        MESSAGE("Qulbutoké ennemi utilise\nMalédiction!");
        // turn 2
        ONE_OF {
            MESSAGE("Qulbutoké prend le type Normal!");
            MESSAGE("Qulbutoké prend le type Ténèbres!");
        }
    }
}

SINGLE_BATTLE_TEST("Conversion 2's type change considers the type of moves called by other moves")
{
    GIVEN {
        WITH_CONFIG(B_UPDATED_CONVERSION_2, GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_OMINOUS_WIND); MOVE(opponent, MOVE_MIRROR_MOVE); }
        TURN { MOVE(player, MOVE_CONVERSION_2); }
    } SCENE {
        // turn 1
        MESSAGE("Qulbutoké ennemi utilise\nMimique!");
        // turn 2
        ONE_OF {
            MESSAGE("Qulbutoké prend le type Normal!");
            MESSAGE("Qulbutoké prend le type Ténèbres!");
        }
    }
}

SINGLE_BATTLE_TEST("Conversion 2's type change considers dynamic type moves")
{
    GIVEN {
        WITH_CONFIG(B_UPDATED_CONVERSION_2, GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_HAIL); MOVE(opponent, MOVE_WEATHER_BALL); }
        TURN { MOVE(player, MOVE_CONVERSION_2); }
    } SCENE {
        // turn 1
        MESSAGE("Qulbutoké ennemi utilise\nBall'Météo!");
        // turn 2
        ONE_OF {
            MESSAGE("Qulbutoké prend le type Acier!");
            MESSAGE("Qulbutoké prend le type Feu!");
            MESSAGE("Qulbutoké prend le type Eau!");
            MESSAGE("Qulbutoké prend le type Glace!");
        }
    }
}

SINGLE_BATTLE_TEST("Conversion 2's type change considers move types changed by Normalize and Electrify")
{
    GIVEN {
        WITH_CONFIG(B_UPDATED_CONVERSION_2, GEN_5);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_NORMALIZE); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_ELECTRIFY); MOVE(opponent, MOVE_POUND); }
        TURN { MOVE(player, MOVE_CONVERSION_2); }
        TURN { MOVE(player, MOVE_WATER_GUN); MOVE(opponent, MOVE_CONVERSION_2); }
    } SCENE {
        // turn 1
        MESSAGE("Qulbutoké utilise\nÉlectrisation!");
        MESSAGE("Qulbutoké ennemi utilise\nÉcras'Face!");
        // turn 2
        ONE_OF {
            MESSAGE("Qulbutoké prend le type Sol!");
            MESSAGE("Qulbutoké prend le type Dragon!");
            MESSAGE("Qulbutoké prend le type Plante!");
            MESSAGE("Qulbutoké prend le type Electrik!");
        }
        // turn 3
        MESSAGE("Qulbutoké utilise\nPistolet à O!");
        ONE_OF {
            MESSAGE("Qulbutoké ennemi prend le type Acier!");
            MESSAGE("Qulbutoké ennemi prend le type Roche!");
            MESSAGE("Qulbutoké ennemi prend le type Spectre!");
        }
    }
}

SINGLE_BATTLE_TEST("Conversion 2's type change fails targeting Struggle (Gen 5+)")
{
    GIVEN {
        WITH_CONFIG(B_UPDATED_CONVERSION_2, GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_STRUGGLE); }
        TURN { MOVE(player, MOVE_CONVERSION_2); }
    } SCENE {
        // turn 1
        MESSAGE("Qulbutoké ennemi utilise\nLutte!");
        // turn 2
        MESSAGE("Qulbutoké utilise\nConversion 2!");
        MESSAGE("Mais cela échoue!");
    }
}

SINGLE_BATTLE_TEST("Conversion 2 fails if the move used is of typeless damage (Gen 5+)")
{
    GIVEN {
        WITH_CONFIG(B_UPDATED_CONVERSION_2, GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ENTEI);
    } WHEN {
        TURN { MOVE(opponent, MOVE_BURN_UP); }
        TURN { MOVE(opponent, MOVE_REVELATION_DANCE); }
        TURN { MOVE(player, MOVE_CONVERSION_2); }
    } SCENE {
        // turn 1
        MESSAGE("Entei ennemi utilise\nFlamme Ultime!");
        // turn 2
        MESSAGE("Entei ennemi utilise\nDanse Éveil!");
        // turn 3
        MESSAGE("Qulbutoké utilise\nConversion 2!");
        MESSAGE("Mais cela échoue!");
    }
}

SINGLE_BATTLE_TEST("Conversion 2 fails if the targeted move is Stellar Type")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_STELLAR); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TERA_BLAST, gimmick: GIMMICK_TERA); MOVE(opponent, MOVE_CONVERSION_2); }
    } SCENE {
        // turn 1
        MESSAGE("Qulbutoké utilise\nTéra Explosion!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TERA_BLAST, player);
        // turn 1
        MESSAGE("Qulbutoké ennemi utilise\nConversion 2!");
        MESSAGE("Mais cela échoue!");
    }
}

SINGLE_BATTLE_TEST("Conversion 2 fails if used by a Terastallized Pokemon")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_PSYCHIC); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TACKLE); }
        TURN { MOVE(player, MOVE_CONVERSION_2, gimmick: GIMMICK_TERA); }
    } SCENE {
        MESSAGE("Qulbutoké utilise\nConversion 2!");
        MESSAGE("Mais cela échoue!");
    }
}

SINGLE_BATTLE_TEST("Conversion 2 fails if last hit by a Stellar-type move (Gen 1-4)")
{
    GIVEN {
        WITH_CONFIG(B_UPDATED_CONVERSION_2, GEN_4);
        PLAYER(SPECIES_WOBBUFFET) { TeraType(TYPE_STELLAR); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_TERA_BLAST, gimmick: GIMMICK_TERA); MOVE(opponent, MOVE_CONVERSION_2); }
    } SCENE {
        // turn 1
        MESSAGE("Qulbutoké utilise\nTéra Explosion!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TERA_BLAST, player);
        // turn 2
        MESSAGE("Qulbutoké ennemi utilise\nConversion 2!");
        MESSAGE("Mais cela échoue!");
    }
}

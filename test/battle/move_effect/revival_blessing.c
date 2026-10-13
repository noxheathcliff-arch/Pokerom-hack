#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_REVIVAL_BLESSING) == EFFECT_REVIVAL_BLESSING);
}

SINGLE_BATTLE_TEST("Revival Blessing revives a chosen fainted party member for the player")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET) { HP(0); }
        PLAYER(SPECIES_WYNAUT) { HP(0); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_REVIVAL_BLESSING, partyIndex:2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REVIVAL_BLESSING, player);
        MESSAGE("Okéoké a repris connaissance et est prêt à se battre de nouveau!");
    }
}

SINGLE_BATTLE_TEST("Revival Blessing revives a fainted party member for an opponent")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_RAICHU);
        OPPONENT(SPECIES_PICHU) { HP(0); }
        OPPONENT(SPECIES_PIKACHU) { HP(0); }
    } WHEN {
        TURN { MOVE(opponent, MOVE_REVIVAL_BLESSING, partyIndex:1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REVIVAL_BLESSING, opponent);
        MESSAGE("Pichu a repris connaissance et est prêt à se battre de nouveau!");
    }
}

SINGLE_BATTLE_TEST("Revival Blessing fails if no party members are fainted")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_REVIVAL_BLESSING); }
    } SCENE {
        MESSAGE("Qulbutoké utilise\nSecond Souffle!");
        MESSAGE("Mais cela échoue!");
    }
}

DOUBLE_BATTLE_TEST("Revival Blessing doesn't prevent revived battlers from losing their turn")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT) { HP(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_SCRATCH, target: opponentRight);
               MOVE(opponentLeft, MOVE_REVIVAL_BLESSING, partyIndex: 1); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, playerLeft);
        MESSAGE("Okéoké ennemi est K.O.!\p");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REVIVAL_BLESSING, opponentLeft);
        MESSAGE("Okéoké a repris connaissance et est prêt à se battre de nouveau!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_CELEBRATE, opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Revival Blessing correctly updates battler absent flags")
{
    GIVEN {
        PLAYER(SPECIES_SALAMENCE) { Level(40); }
        PLAYER(SPECIES_PIDGEOT) { Level(40); }
        OPPONENT(SPECIES_GEODUDE) { Level(5); Ability(ABILITY_ROCK_HEAD); }
        OPPONENT(SPECIES_STARLY) { Level(5); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_EARTHQUAKE);
               MOVE(opponentRight, MOVE_REVIVAL_BLESSING, partyIndex: 0); }
        TURN { MOVE(playerLeft, MOVE_EARTHQUAKE); }
    } SCENE {
        // Turn 1
        MESSAGE("Drattak utilise\nSéisme!");
        MESSAGE("Ça n'affecte pas Roucarnage…");
        MESSAGE("Ça n'affecte pas Étourmi ennemi…");
        HP_BAR(opponentLeft);
        MESSAGE("Racaillou ennemi est K.O.!\p");
        MESSAGE("Étourmi ennemi utilise\nSecond Souffle!");
        MESSAGE("Racaillou a repris connaissance et est prêt à se battre de nouveau!"); // Should have prefix but it doesn't currently.
        // Turn 2
        MESSAGE("Drattak utilise\nSéisme!");
        MESSAGE("Ça n'affecte pas Roucarnage…");
        MESSAGE("Ça n'affecte pas Étourmi ennemi…");
        HP_BAR(opponentLeft);
        MESSAGE("Racaillou ennemi est K.O.!\p");
    }
}

SINGLE_BATTLE_TEST("Revival Blessing keeps Mimikyu Busted forms and Eiscue Noice in their current forms")
{
    enum Species species;
    enum Ability ability;

    PARAMETRIZE { species = SPECIES_MIMIKYU_BUSTED;       ability = ABILITY_DISGUISE; }
    PARAMETRIZE { species = SPECIES_MIMIKYU_BUSTED_TOTEM; ability = ABILITY_DISGUISE; }
    PARAMETRIZE { species = SPECIES_EISCUE_NOICE;         ability = ABILITY_ICE_FACE; }

    GIVEN {
        ASSUME(GetMoveCategory(MOVE_CRUNCH) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(species) { HP(1); Ability(ability); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CRUNCH); SEND_OUT(player, 1); }
        TURN { MOVE(player, MOVE_REVIVAL_BLESSING, partyIndex: 0); }
        TURN { SWITCH(player, 0); MOVE(opponent, MOVE_CRUNCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CRUNCH, opponent);
        HP_BAR(player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_REVIVAL_BLESSING, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_CRUNCH, opponent);
        NOT ABILITY_POPUP(player, ability);
        HP_BAR(player);
    }
}

#include "global.h"
#include "test/battle.h"

DOUBLE_BATTLE_TEST("Spread Moves: Ability and Item effects activate correctly after a multi target move")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_LUM_BERRY].holdEffect == HOLD_EFFECT_CURE_STATUS);
        ASSUME(gItemsInfo[ITEM_COVERT_CLOAK].holdEffect == HOLD_EFFECT_COVERT_CLOAK);
        ASSUME(gItemsInfo[ITEM_EJECT_BUTTON].holdEffect == HOLD_EFFECT_EJECT_BUTTON);
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_LUM_BERRY); }
        PLAYER(SPECIES_WOBBUFFET) { Item(ITEM_COVERT_CLOAK); }
        OPPONENT(SPECIES_GOLISOPOD) { Ability(ABILITY_EMERGENCY_EXIT); MaxHP(260); HP(131); }
        OPPONENT(SPECIES_WOBBUFFET) { Item(ITEM_EJECT_BUTTON); }
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_PIKACHU);
    } WHEN {
        TURN {
            MOVE(opponentRight, MOVE_HEAT_WAVE);
            MOVE(playerLeft, MOVE_HYPER_VOICE);
            SEND_OUT(opponentRight, 3);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, playerLeft);
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_EFFECT, opponentRight);
        MESSAGE("Qulbutoké ennemi se retire grâce au Bouton Fuite!");
        MESSAGE("2 envoie\nun Pikachu!");
        NONE_OF {
            ABILITY_POPUP(opponentLeft, ABILITY_EMERGENCY_EXIT);
            MESSAGE("2 envoie\nun Okéoké!");
        }
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: No damage will be dealt to a mon in an invulnerable position")
{
    u32 attackingMove = 0, invulMove = 0;
    PARAMETRIZE { attackingMove = MOVE_HYPER_VOICE; invulMove = MOVE_FLY; }
    PARAMETRIZE { attackingMove = MOVE_LAVA_PLUME;  invulMove = MOVE_FLY; }
    PARAMETRIZE { attackingMove = MOVE_HYPER_VOICE; invulMove = MOVE_DIVE; }
    PARAMETRIZE { attackingMove = MOVE_LAVA_PLUME;  invulMove = MOVE_DIVE; }
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_HYPER_VOICE) == TARGET_BOTH);
        ASSUME(GetMoveTarget(MOVE_LAVA_PLUME) == TARGET_FOES_AND_ALLY);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_ZAPDOS);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, invulMove, target: playerLeft); MOVE(playerLeft, attackingMove); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, attackingMove, playerLeft);
        NOT HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: A spread move attack will activate both resist berries")
{
    s16 opponentLeftDmg[2];
    s16 opponentRightDmg[2];

    GIVEN {
        ASSUME(gItemsInfo[ITEM_CHILAN_BERRY].holdEffect == HOLD_EFFECT_RESIST_BERRY);
        ASSUME(gItemsInfo[ITEM_CHILAN_BERRY].holdEffectParam == TYPE_NORMAL);
        PLAYER(SPECIES_GARDEVOIR);
        PLAYER(SPECIES_RALTS);
        OPPONENT(SPECIES_RAICHU) { Item(ITEM_CHILAN_BERRY); }
        OPPONENT(SPECIES_SANDSLASH) { Item(ITEM_CHILAN_BERRY); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_HYPER_VOICE); }
        TURN { MOVE(playerLeft, MOVE_HYPER_VOICE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponentLeft);
        MESSAGE("Baie Zalis réduit les dégâts infligés à Raichu ennemi!");
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponentRight);
        MESSAGE("Baie Zalis réduit les dégâts infligés à Sablaireau ennemi!");

        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, playerLeft);
        EFFECTIVENESS_SE(opponentLeft, SE_EFFECTIVE); // effective against both
        HP_BAR(opponentLeft, captureDamage: &opponentLeftDmg[0]);
        HP_BAR(opponentRight, captureDamage: &opponentRightDmg[0]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, playerLeft);
        EFFECTIVENESS_SE(opponentLeft, SE_EFFECTIVE); // effective against both
        HP_BAR(opponentLeft, captureDamage: &opponentLeftDmg[1]);
        HP_BAR(opponentRight, captureDamage: &opponentRightDmg[1]);
    } THEN {
        EXPECT_MUL_EQ(opponentLeftDmg[1], Q_4_12(0.5), opponentLeftDmg[0]);
        EXPECT_MUL_EQ(opponentRightDmg[1], Q_4_12(0.5), opponentRightDmg[0]);
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: If a spread move attack will activate a resist berries on one Pokémon, only the damage for that mon will be reduced")
{
    s16 opponentLeftDmg[2];
    s16 opponentRightDmg[2];

    GIVEN {
        ASSUME(gItemsInfo[ITEM_CHILAN_BERRY].holdEffect == HOLD_EFFECT_RESIST_BERRY);
        ASSUME(gItemsInfo[ITEM_CHILAN_BERRY].holdEffectParam == TYPE_NORMAL);
        PLAYER(SPECIES_GARDEVOIR);
        PLAYER(SPECIES_RALTS);
        OPPONENT(SPECIES_RAICHU)
        OPPONENT(SPECIES_SANDSLASH) { Item(ITEM_CHILAN_BERRY); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_HYPER_VOICE); }
        TURN { MOVE(playerLeft, MOVE_HYPER_VOICE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_GENERAL, B_ANIM_HELD_ITEM_BERRY, opponentRight);
        MESSAGE("Baie Zalis réduit les dégâts infligés à Sablaireau ennemi!");

        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &opponentLeftDmg[0]);
        HP_BAR(opponentRight, captureDamage: &opponentRightDmg[0]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &opponentLeftDmg[1]);
        HP_BAR(opponentRight, captureDamage: &opponentRightDmg[1]);
    } THEN {
        EXPECT_EQ(opponentLeftDmg[1], opponentLeftDmg[0]);
        EXPECT_MUL_EQ(opponentRightDmg[1], Q_4_12(0.5), opponentRightDmg[0]);
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: A spread move attack will be weakened by strong winds on both targets")
{
    s16 opponentLeftDmg[2];
    s16 opponentRightDmg[2];

    GIVEN {
        PLAYER(SPECIES_GARDEVOIR);
        PLAYER(SPECIES_RAYQUAZA) { Ability(ABILITY_AIR_LOCK); }
        PLAYER(SPECIES_RALTS);
        OPPONENT(SPECIES_ZAPDOS);
        OPPONENT(SPECIES_RAYQUAZA) { Moves(MOVE_DRAGON_ASCENT, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); MOVE(playerLeft, MOVE_ROCK_SLIDE); }
        TURN { SWITCH(playerRight, 2); MOVE(opponentRight, MOVE_CELEBRATE); MOVE(playerLeft, MOVE_ROCK_SLIDE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_SLIDE, playerLeft);
        EFFECTIVENESS_SE(opponentLeft, SE_SUPER_EFFECTIVE); // SE on rayquaza
        HP_BAR(opponentLeft, captureDamage: &opponentLeftDmg[0]);
        HP_BAR(opponentRight, captureDamage: &opponentRightDmg[0]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_SLIDE, playerLeft);
        EFFECTIVENESS_SE(opponentLeft, SE_EFFECTIVE);
        HP_BAR(opponentLeft, captureDamage: &opponentLeftDmg[1]);
        HP_BAR(opponentRight, captureDamage: &opponentRightDmg[1]);
    } THEN {
        EXPECT_MUL_EQ(opponentLeftDmg[0], Q_4_12(0.5), opponentLeftDmg[1]);
        EXPECT_MUL_EQ(opponentRightDmg[0], Q_4_12(0.5), opponentRightDmg[1]);
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: A spread move attack will be weakened by strong winds on one of the targets")
{
    s16 opponentLeftDmg[2];
    s16 opponentRightDmg[2];

    GIVEN {
        PLAYER(SPECIES_GARDEVOIR);
        PLAYER(SPECIES_RAYQUAZA) { Ability(ABILITY_AIR_LOCK); }
        PLAYER(SPECIES_RALTS);
        OPPONENT(SPECIES_DONPHAN)
        OPPONENT(SPECIES_RAYQUAZA) { Moves(MOVE_DRAGON_ASCENT, MOVE_CELEBRATE); }
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_CELEBRATE, gimmick: GIMMICK_MEGA); MOVE(playerLeft, MOVE_ROCK_SLIDE); }
        TURN { SWITCH(playerRight, 2); MOVE(opponentRight, MOVE_CELEBRATE); MOVE(playerLeft, MOVE_ROCK_SLIDE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_SLIDE, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &opponentLeftDmg[0]);
        HP_BAR(opponentRight, captureDamage: &opponentRightDmg[0]);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_SLIDE, playerLeft);
        HP_BAR(opponentLeft, captureDamage: &opponentLeftDmg[1]);
        HP_BAR(opponentRight, captureDamage: &opponentRightDmg[1]);
    } THEN {
        EXPECT_EQ(opponentLeftDmg[1], opponentLeftDmg[0]);
        EXPECT_MUL_EQ(opponentRightDmg[0], Q_4_12(0.5), opponentRightDmg[1]);
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: AOE move vs Disguise, Volt Absorb (right) and Lightning Rod (left)")
{
    GIVEN {
        WITH_CONFIG(B_REDIRECT_ABILITY_IMMUNITY, GEN_5);
        ASSUME(GetMoveTarget(MOVE_DISCHARGE) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveType(MOVE_DISCHARGE) == TYPE_ELECTRIC);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_MIMIKYU) { Ability(ABILITY_DISGUISE); }
        OPPONENT(SPECIES_RAICHU) { Ability(ABILITY_LIGHTNING_ROD); }
        OPPONENT(SPECIES_LANTURN) { Ability(ABILITY_VOLT_ABSORB); HP(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DISCHARGE); }
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_LIGHTNING_ROD);
        ABILITY_POPUP(opponentRight, ABILITY_VOLT_ABSORB);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DISCHARGE, playerLeft);
        ABILITY_POPUP(playerRight, ABILITY_DISGUISE);
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: AOE move vs Disguise, Volt Absorb (left) and Lightning Rod (right)")
{
    GIVEN {
        WITH_CONFIG(B_REDIRECT_ABILITY_IMMUNITY, GEN_5);
        ASSUME(GetMoveTarget(MOVE_DISCHARGE) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveType(MOVE_DISCHARGE) == TYPE_ELECTRIC);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_MIMIKYU) { Ability(ABILITY_DISGUISE); }
        OPPONENT(SPECIES_LANTURN) { Ability(ABILITY_VOLT_ABSORB); HP(1); }
        OPPONENT(SPECIES_RAICHU) { Ability(ABILITY_LIGHTNING_ROD); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_DISCHARGE); }
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_VOLT_ABSORB);
        ABILITY_POPUP(opponentRight, ABILITY_LIGHTNING_ROD);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_DISCHARGE, playerLeft);
        ABILITY_POPUP(playerRight, ABILITY_DISGUISE);
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: AOE move vs Eiscue and Mimikyu (Based on vanilla games)")
{
    s16 disguiseDamage;

    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveCategory(MOVE_EARTHQUAKE) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_EISCUE) { Ability(ABILITY_ICE_FACE); }
        OPPONENT(SPECIES_MIMIKYU) { Ability(ABILITY_DISGUISE); }
        OPPONENT(SPECIES_EISCUE) { Ability(ABILITY_ICE_FACE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_EARTHQUAKE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, playerLeft);
        ABILITY_POPUP(opponentLeft, ABILITY_DISGUISE);
        HP_BAR(opponentLeft, captureDamage: &disguiseDamage);
        ABILITY_POPUP(playerRight, ABILITY_ICE_FACE);
        ABILITY_POPUP(opponentRight, ABILITY_ICE_FACE);
        NONE_OF {
            HP_BAR(playerRight);
            HP_BAR(opponentRight);
        }
    } THEN {
        EXPECT_EQ(disguiseDamage, opponentLeft->maxHP / 8);
        EXPECT_EQ(opponentLeft->species, SPECIES_MIMIKYU_BUSTED);
        EXPECT_EQ(playerRight->species, SPECIES_EISCUE_NOICE);
        EXPECT_EQ(opponentRight->species, SPECIES_EISCUE_NOICE);
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: Spread move, Gem Boosted, vs Resist Berries")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_HYPER_VOICE) == TARGET_BOTH);
        ASSUME(gItemsInfo[ITEM_NORMAL_GEM].holdEffect == HOLD_EFFECT_GEMS);
        ASSUME(gItemsInfo[ITEM_CHILAN_BERRY].holdEffect == HOLD_EFFECT_RESIST_BERRY);
        ASSUME(gItemsInfo[ITEM_CHILAN_BERRY].holdEffectParam == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET) { Speed(40); Item(ITEM_NORMAL_GEM); }
        PLAYER(SPECIES_WYNAUT) { Speed(30); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(20); Item(ITEM_CHILAN_BERRY); }
        OPPONENT(SPECIES_WYNAUT) { Speed(10); Item(ITEM_CHILAN_BERRY); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_HYPER_VOICE); }
    } SCENE {
        MESSAGE("Joyau Normal renforce la capacité de Qulbutoké!");
        MESSAGE("Baie Zalis réduit les dégâts infligés à Qulbutoké ennemi!");
        MESSAGE("Baie Zalis réduit les dégâts infligés à Okéoké ennemi!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, playerLeft);
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: Explosion, Gem Boosted, vs Resist Berries")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EXPLOSION) == TARGET_FOES_AND_ALLY);
        ASSUME(gItemsInfo[ITEM_NORMAL_GEM].holdEffect == HOLD_EFFECT_GEMS);
        ASSUME(gItemsInfo[ITEM_CHILAN_BERRY].holdEffect == HOLD_EFFECT_RESIST_BERRY);
        ASSUME(gItemsInfo[ITEM_CHILAN_BERRY].holdEffectParam == TYPE_NORMAL);
        PLAYER(SPECIES_WOBBUFFET) { Speed(40); Item(ITEM_NORMAL_GEM); }
        PLAYER(SPECIES_MISDREAVUS) { Speed(30); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(20); Item(ITEM_CHILAN_BERRY); }
        OPPONENT(SPECIES_WYNAUT) { Speed(10); Item(ITEM_CHILAN_BERRY); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_EXPLOSION); }
    } SCENE {
        MESSAGE("Ça n'affecte pas Feuforêve…");
        MESSAGE("Joyau Normal renforce la capacité de Qulbutoké!");
        MESSAGE("Baie Zalis réduit les dégâts infligés à Qulbutoké ennemi!");
        MESSAGE("Baie Zalis réduit les dégâts infligés à Okéoké ennemi!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPLOSION, playerLeft);
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: Spread move vs Eiscue and Mimikyu with 1 Eject Button")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_RAZOR_LEAF) == TARGET_BOTH);
        ASSUME(GetMoveCategory(MOVE_RAZOR_LEAF) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(gItemsInfo[ITEM_EJECT_BUTTON].holdEffect == HOLD_EFFECT_EJECT_BUTTON);
        PLAYER(SPECIES_WOBBUFFET) { Speed(40); }
        PLAYER(SPECIES_WYNAUT) { Speed(30); }
        OPPONENT(SPECIES_MIMIKYU) { Speed(20); Ability(ABILITY_DISGUISE); Item(ITEM_EJECT_BUTTON); }
        OPPONENT(SPECIES_EISCUE) { Speed(10); Ability(ABILITY_ICE_FACE); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(100); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_RAZOR_LEAF); SEND_OUT(opponentLeft, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_RAZOR_LEAF, playerLeft);
        ABILITY_POPUP(opponentLeft, ABILITY_DISGUISE);
        ABILITY_POPUP(opponentRight, ABILITY_ICE_FACE);
        MESSAGE("Mimiqui ennemi se retire grâce au Bouton Fuite!");
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: Spread move vs Wide Guard")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_HYPER_VOICE) == TARGET_BOTH);
        PLAYER(SPECIES_WOBBUFFET) { Speed(40); }
        PLAYER(SPECIES_WYNAUT) { Speed(20); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(30); }
        OPPONENT(SPECIES_WYNAUT) { Speed(10); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_WIDE_GUARD); MOVE(opponentLeft, MOVE_HYPER_VOICE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_WIDE_GUARD, playerLeft);
        MESSAGE("Garde Large protège votre équipe!");
        MESSAGE("Qulbutoké ennemi utilise\nMégaphone!");
        MESSAGE("Qulbutoké se protège!");
        MESSAGE("Okéoké se protège!");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, playerLeft);
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: Spread move vs one protecting mon")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_HYPER_VOICE) == TARGET_BOTH);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_PROTECT); MOVE(playerLeft, MOVE_HYPER_VOICE); }
    } SCENE {
        MESSAGE("Qulbutoké ennemi utilise\nAbri!");
        MESSAGE("Qulbutoké utilise\nMégaphone!");
        MESSAGE("Qulbutoké ennemi se protège!");
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: Super Effective Message on both opposing mons")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_PRECIPICE_BLADES) == TARGET_BOTH);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_GOLEM);
        OPPONENT(SPECIES_ONIX);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_PRECIPICE_BLADES); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PRECIPICE_BLADES, playerLeft);
        EFFECTIVENESS_SE(opponentLeft, SE_SUPER_EFFECTIVE);
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
        MESSAGE("C'est super efficace sur Grolem ennemi et Onix!");
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: Super Effective Message on both player mons")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_PRECIPICE_BLADES) == TARGET_BOTH);
        PLAYER(SPECIES_GOLEM);
        PLAYER(SPECIES_ONIX);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_PRECIPICE_BLADES); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PRECIPICE_BLADES, opponentLeft);
        HP_BAR(playerLeft);
        HP_BAR(playerRight);
        MESSAGE("C'est super efficace sur Grolem et Onix!");
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: Not very effective Message on both opposing mons")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_PRECIPICE_BLADES) == TARGET_BOTH);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_CHIKORITA);
        OPPONENT(SPECIES_TREECKO);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_PRECIPICE_BLADES); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PRECIPICE_BLADES, playerLeft);
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
        MESSAGE("Ce n'est pas très efficace sur Germignon ennemi et Arcko…");
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: Not very effective message on both player mons")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_PRECIPICE_BLADES) == TARGET_BOTH);
        PLAYER(SPECIES_CHIKORITA);
        PLAYER(SPECIES_TREECKO);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_PRECIPICE_BLADES); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PRECIPICE_BLADES, opponentLeft);
        HP_BAR(playerLeft);
        HP_BAR(playerRight);
        MESSAGE("Ce n'est pas très efficace sur Germignon et Arcko…");
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: Doesn't affect any target")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_PIDGEY);
        OPPONENT(SPECIES_PIDGEY);
        OPPONENT(SPECIES_HOOTHOOT);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_EARTHQUAKE); }
    } SCENE {
        MESSAGE("Ça n'affecte pas Roucool…");
        MESSAGE("Ça n'affecte pas Roucool ennemi…");
        MESSAGE("Ça n'affecte pas Hoothoot ennemi…");
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, playerLeft);
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: Unless move hits every target user will not include partner in the target count")
{
    GIVEN {
        PLAYER(SPECIES_SANDSLASH);
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PLAYER(SPECIES_RALTS);
        OPPONENT(SPECIES_TORKOAL);
        OPPONENT(SPECIES_TORKOAL);
    } WHEN {
        TURN { MOVE(opponentRight, MOVE_ICY_WIND); MOVE(playerLeft, MOVE_ROCK_SLIDE); SEND_OUT(playerRight, 2); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_ICY_WIND, opponentRight);
        EFFECTIVENESS_SE(playerRight, SE_SUPER_EFFECTIVE); // SE against sandslash
        HP_BAR(playerLeft);
        HP_BAR(playerRight);

        ANIMATION(ANIM_TYPE_MOVE, MOVE_ROCK_SLIDE, playerLeft);
        EFFECTIVENESS_SE(opponentLeft, SE_SUPER_EFFECTIVE); // se against torkoal
        HP_BAR(opponentLeft);
        HP_BAR(opponentRight);
        MESSAGE("C'est super efficace sur Chartor ennemi et Chartor!");
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: Focus Sash activates correctly")
{
    GIVEN {
        ASSUME(gItemsInfo[ITEM_FOCUS_SASH].holdEffect == HOLD_EFFECT_FOCUS_SASH);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT) { HP(2); MaxHP(2); Item(ITEM_FOCUS_SASH); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(2); MaxHP(2); Item(ITEM_FOCUS_SASH); }
        OPPONENT(SPECIES_WYNAUT) { HP(2); MaxHP(2); Item(ITEM_FOCUS_SASH); }
    } WHEN {
        TURN { MOVE(playerRight, MOVE_HYPER_VOICE); MOVE(playerLeft, MOVE_EXPLOSION); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HYPER_VOICE, playerRight);
        MESSAGE("Okéoké ennemi tient bon grâce à Ceinture Force!");
        MESSAGE("Qulbutoké ennemi tient bon grâce à Ceinture Force!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EXPLOSION, playerLeft);
        MESSAGE("Qulbutoké ennemi est K.O.!\p");
        MESSAGE("Okéoké tient bon grâce à Ceinture Force!");
        MESSAGE("Okéoké ennemi est K.O.!\p");
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: AOE ground type move vs Levitate and Air Balloon")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveCategory(MOVE_EARTHQUAKE) == DAMAGE_CATEGORY_PHYSICAL);
        ASSUME(gItemsInfo[ITEM_AIR_BALLOON].holdEffect == HOLD_EFFECT_AIR_BALLOON);
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_FLYGON) { Ability(ABILITY_LEVITATE); }
        OPPONENT(SPECIES_WYNAUT) { Item(ITEM_AIR_BALLOON); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_EARTHQUAKE); }
    } SCENE {
        ABILITY_POPUP(opponentLeft, ABILITY_LEVITATE);
        MESSAGE("Ça n'affecte pas Okéoké ennemi…");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, playerLeft);
        HP_BAR(playerRight);
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: Earthquake fails in order of ally, left foe, right foe")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveCategory(MOVE_EARTHQUAKE) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_FLYGON) { Speed(1); Ability(ABILITY_LEVITATE); }
        OPPONENT(SPECIES_FLYGON) { Speed(2); Ability(ABILITY_LEVITATE); }
        OPPONENT(SPECIES_FLYGON) { Speed(3); Ability(ABILITY_LEVITATE); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_EARTHQUAKE); }
    } SCENE {
        ABILITY_POPUP(playerRight, ABILITY_LEVITATE);
        ABILITY_POPUP(opponentLeft, ABILITY_LEVITATE);
        ABILITY_POPUP(opponentRight, ABILITY_LEVITATE);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, playerLeft);
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: Earthquake fails due to accuracy in order of ally, left foe, right foe")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_EARTHQUAKE) == TARGET_FOES_AND_ALLY);
        ASSUME(GetMoveCategory(MOVE_EARTHQUAKE) == DAMAGE_CATEGORY_PHYSICAL);
        PLAYER(SPECIES_WOBBUFFET) { Speed(4); }
        PLAYER(SPECIES_WYNAUT) { Speed(1); Item(ITEM_BRIGHTPOWDER); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); Item(ITEM_BRIGHTPOWDER); }
        OPPONENT(SPECIES_WYNAUT) { Speed(3); Item(ITEM_BRIGHTPOWDER); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_EARTHQUAKE, hit: FALSE); }
    } SCENE {
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_EARTHQUAKE, playerLeft);
        MESSAGE("Okéoké évite l'attaque!");
        MESSAGE("Qulbutoké ennemi évite l'attaque!");
        MESSAGE("Okéoké ennemi évite l'attaque!");
    }
}

DOUBLE_BATTLE_TEST("Spread Moves: A missed multi-target stat move names the missed battler")
{
    GIVEN {
        ASSUME(GetMoveTarget(MOVE_STRING_SHOT) == TARGET_BOTH);
        PLAYER(SPECIES_CATERPIE);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_BELDUM) { Ability(ABILITY_CLEAR_BODY); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_STRING_SHOT, hit: FALSE); }
    } SCENE {
        MESSAGE("Qulbutoké ennemi évite l'attaque!");
    }
}

#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(GetMoveEffect(MOVE_JUMP_KICK) == EFFECT_RECOIL_IF_MISS);
}

SINGLE_BATTLE_TEST("Recoil if miss: Jump Kick has 50% recoil on miss")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_JUMP_KICK, hit: FALSE); }
    } SCENE {
        s32 maxHP = GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP);
        MESSAGE("Qulbutoké utilise\nPied Sauté!");
        MESSAGE("Qulbutoké ennemi évite l'attaque!");
        MESSAGE("Qulbutoké s'est blessé en attaquant!");
        HP_BAR(player, damage: maxHP / 2);
    }
}

SINGLE_BATTLE_TEST("Recoil if miss: Jump Kick has 50% recoil on protect")
{
    GIVEN {
        ASSUME(!MoveIgnoresProtect(MOVE_JUMP_KICK));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, MOVE_JUMP_KICK, hit: FALSE); }
    } SCENE {
        s32 maxHP = GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_PROTECT, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_JUMP_KICK, player);
        HP_BAR(player, damage: maxHP / 2);
    }
}

SINGLE_BATTLE_TEST("Recoil if miss: Jump Kick has no recoil if no target")
{
    GIVEN {
        WITH_CONFIG(B_HEALING_WISH_SWITCH, GEN_5);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { MOVE(opponent, MOVE_HEALING_WISH); MOVE(player, MOVE_JUMP_KICK, hit: FALSE); SEND_OUT(opponent, 1); }
    } SCENE {
        s32 maxHP = GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_HEALING_WISH, opponent);
        NOT HP_BAR(player, damage: maxHP / 2);
    }
}

SINGLE_BATTLE_TEST("Recoil if miss: Jump Kick's recoil happens after Spiky Shield damage and Pokemon can faint from either of these")
{
    s16 hp, maxHp = 256;
    bool32 faintOnSpiky = FALSE, faintOnJumpKick = FALSE;

    PARAMETRIZE { hp = maxHp; }
    PARAMETRIZE { hp = maxHp / 2; faintOnJumpKick = TRUE; } // Faints after Jump Kick's recoil
    PARAMETRIZE { hp = maxHp / 8; faintOnSpiky = TRUE; } // Faints after Spiky Shield's recoil

    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SPIKY_SHIELD) == EFFECT_PROTECT);
        PLAYER(SPECIES_WOBBUFFET) { HP(hp); MaxHP(maxHp); }
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (!faintOnJumpKick && !faintOnSpiky) {
            TURN { MOVE(opponent, MOVE_SPIKY_SHIELD); MOVE(player, MOVE_JUMP_KICK, hit: FALSE); }
        } else {
            TURN { MOVE(opponent, MOVE_SPIKY_SHIELD); MOVE(player, MOVE_JUMP_KICK, hit: FALSE); SEND_OUT(player, 1); }
        }
        TURN {}
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPIKY_SHIELD, opponent);
        MESSAGE("Qulbutoké utilise\nPied Sauté!");
        MESSAGE("Qulbutoké ennemi se protège!");
        HP_BAR(player, damage: maxHp / 8);
        MESSAGE("Qulbutoké est blessé!");
        if (faintOnSpiky){
            MESSAGE("Qulbutoké est K.O.!\p");
            SEND_IN_MESSAGE("Okéoké");
            NONE_OF {
                MESSAGE("Qulbutoké s'est blessé en attaquant!");
                HP_BAR(player);
            }
        } else {
            MESSAGE("Qulbutoké s'est blessé en attaquant!");
            HP_BAR(player);
            if (faintOnJumpKick) {
                MESSAGE("Qulbutoké est K.O.!\p");
                SEND_IN_MESSAGE("Okéoké");
            }
        }
    }
}

SINGLE_BATTLE_TEST("Recoil if miss: Jump Kick recoil happens after Spiky Shield damage")
{
    GIVEN {
        ASSUME(!MoveIgnoresProtect(MOVE_JUMP_KICK));
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SPIKY_SHIELD); MOVE(player, MOVE_JUMP_KICK); }
    } SCENE {
        s32 maxHP = GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPIKY_SHIELD, opponent);
        NOT ANIMATION(ANIM_TYPE_MOVE, MOVE_JUMP_KICK, player);
        MESSAGE("Qulbutoké est blessé!");
        MESSAGE("Qulbutoké s'est blessé en attaquant!");
        HP_BAR(player, damage: maxHP / 2);
    }
}

SINGLE_BATTLE_TEST("Recoil if miss: Supercell Slam causes recoil if it is absorbed")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_PIKACHU) { Ability(ABILITY_LIGHTNING_ROD); }
    } WHEN {
        TURN { MOVE(player, MOVE_SUPERCELL_SLAM); }
    } SCENE {
        s32 maxHP = GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP);
        ABILITY_POPUP(opponent, ABILITY_LIGHTNING_ROD);
        MESSAGE("Qulbutoké s'est blessé en attaquant!");
        HP_BAR(player, damage: maxHP / 2);
    }
}

SINGLE_BATTLE_TEST("Recoil if miss: Disguise doesn't prevent crash damage from Jump Kick into ghost types")
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_EARLY_BIRD; }
    PARAMETRIZE { ability = ABILITY_SCRAPPY; }

    GIVEN {
        PLAYER(SPECIES_KANGASKHAN) { Ability(ability); }
        OPPONENT(SPECIES_MIMIKYU_DISGUISED) { Ability(ABILITY_DISGUISE); }
    } WHEN {
        TURN { MOVE(player, MOVE_JUMP_KICK); }
    } SCENE {
        s32 maxHP = GetMonData(&PLAYER_PARTY[0], MON_DATA_MAX_HP);
        MESSAGE("Kangourex utilise\nPied Sauté!");
        if (ability == ABILITY_SCRAPPY) {
            NONE_OF {
                MESSAGE("Kangourex  s'est blessé en attaquant!");
                HP_BAR(player, damage: maxHP / 2);
            }
        }
    }
}

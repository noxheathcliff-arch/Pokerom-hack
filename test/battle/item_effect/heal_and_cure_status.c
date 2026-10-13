#include "global.h"
#include "test/battle.h"

ASSUMPTIONS
{
    ASSUME(gItemsInfo[ITEM_FULL_RESTORE].battleUsage == EFFECT_ITEM_HEAL_AND_CURE_STATUS);
}

SINGLE_BATTLE_TEST("Full Restore restores a battler's HP and cures any primary status")
{
    u16 status;
    PARAMETRIZE { status = STATUS1_BURN; }
    PARAMETRIZE { status = STATUS1_FREEZE; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; }
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { status = STATUS1_SLEEP; }
    PARAMETRIZE { status = STATUS1_FROSTBITE; }
    PARAMETRIZE { status = STATUS1_NONE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); MaxHP(300); Status1(status); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_FULL_RESTORE, partyIndex: 0); }
    } SCENE {
        MESSAGE("Qulbutoké récupère des PV.");
        if (status != STATUS1_NONE) {
            switch (status)
            {
                case STATUS1_BURN:
                    MESSAGE("Qulbutoké n'est plus brûlé!");
                    break;
                case STATUS1_FREEZE:
                    MESSAGE("Qulbutoké n'est plus gelé!");
                    break;
                case STATUS1_PARALYSIS:
                    MESSAGE("Qulbutoké n'est plus paralysé!");
                    break;
                case STATUS1_POISON:
                case STATUS1_TOXIC_POISON:
                    MESSAGE("Qulbutoké n'est plus empoisonné!");
                    break;
                case STATUS1_SLEEP:
                    MESSAGE("Qulbutoké se réveille!");
                    break;
                case STATUS1_FROSTBITE:
                    MESSAGE("Qulbutoké s'est remis de sa gelure!");
                    break;
            } // The message is not printed if status wasn't healed.
        }
    } THEN {
        EXPECT_EQ(player->hp, player->maxHP);
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Full Restore restores a party members HP and cures any primary status")
{
    u16 status;
    PARAMETRIZE { status = STATUS1_BURN; }
    PARAMETRIZE { status = STATUS1_FREEZE; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; }
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { status = STATUS1_SLEEP; }
    PARAMETRIZE { status = STATUS1_FROSTBITE; }
    PARAMETRIZE { status = STATUS1_NONE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(100); MaxHP(300); Status1(status); }
        PLAYER(SPECIES_WYNAUT) { HP(100); MaxHP(300); Status1(status); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_FULL_RESTORE, partyIndex: 1); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        MESSAGE("Okéoké récupère des PV.");
        if (status != STATUS1_NONE) {
            switch (status)
            {
                case STATUS1_BURN:
                    MESSAGE("Okéoké n'est plus brûlé!");
                    break;
                case STATUS1_FREEZE:
                    MESSAGE("Okéoké n'est plus gelé!");
                    break;
                case STATUS1_PARALYSIS:
                    MESSAGE("Okéoké n'est plus paralysé!");
                    break;
                case STATUS1_POISON:
                case STATUS1_TOXIC_POISON:
                    MESSAGE("Okéoké n'est plus empoisonné!");
                    break;
                case STATUS1_SLEEP:
                    MESSAGE("Okéoké se réveille!");
                    break;
                case STATUS1_FROSTBITE:
                    MESSAGE("Okéoké s'est remis de sa gelure!");
                    break;
            } // The message is not printed if status wasn't healed.
        }
    } THEN {
        EXPECT_EQ(player->hp, player->maxHP);
        EXPECT_EQ(player->species, SPECIES_WYNAUT);
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Full Restore heals a battler from any primary status")
{
    u16 status;
    PARAMETRIZE { status = STATUS1_BURN; }
    PARAMETRIZE { status = STATUS1_FREEZE; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; }
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { status = STATUS1_SLEEP; }
    PARAMETRIZE { status = STATUS1_FROSTBITE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Status1(status); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_FULL_RESTORE, partyIndex: 0); }
    } SCENE {
        NOT MESSAGE("Qulbutoké récupère des PV!"); // The message is not printed if mon has max HP.
        switch (status)
        {
            case STATUS1_BURN:
                MESSAGE("Qulbutoké n'est plus brûlé!");
                break;
            case STATUS1_FREEZE:
                MESSAGE("Qulbutoké n'est plus gelé!");
                break;
            case STATUS1_PARALYSIS:
                MESSAGE("Qulbutoké n'est plus paralysé!");
                break;
            case STATUS1_POISON:
            case STATUS1_TOXIC_POISON:
                MESSAGE("Qulbutoké n'est plus empoisonné!");
                break;
            case STATUS1_SLEEP:
                MESSAGE("Qulbutoké se réveille!");
                break;
            case STATUS1_FROSTBITE:
                MESSAGE("Qulbutoké s'est remis de sa gelure!");
                break;
        }
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Full Restore heals a party member from any primary status")
{
    u16 status;
    PARAMETRIZE { status = STATUS1_BURN; }
    PARAMETRIZE { status = STATUS1_FREEZE; }
    PARAMETRIZE { status = STATUS1_PARALYSIS; }
    PARAMETRIZE { status = STATUS1_POISON; }
    PARAMETRIZE { status = STATUS1_TOXIC_POISON; }
    PARAMETRIZE { status = STATUS1_SLEEP; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT) { Status1(status); }
        OPPONENT(SPECIES_WYNAUT);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_FULL_RESTORE, partyIndex: 1); }
        TURN { SWITCH(player, 1); }
    } SCENE {
        NOT MESSAGE("Okéoké récupère des PV!"); // The message is not printed if mon has max HP.
        switch (status)
        {
            case STATUS1_BURN:
                MESSAGE("Okéoké n'est plus brûlé!");
                break;
            case STATUS1_FREEZE:
                MESSAGE("Okéoké n'est plus gelé!");
                break;
            case STATUS1_PARALYSIS:
                MESSAGE("Okéoké n'est plus paralysé!");
                break;
            case STATUS1_POISON:
            case STATUS1_TOXIC_POISON:
                MESSAGE("Okéoké n'est plus empoisonné!");
                break;
            case STATUS1_SLEEP:
                MESSAGE("Okéoké se réveille!");
                break;
        }
    } THEN {
        EXPECT_EQ(player->species, SPECIES_WYNAUT);
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

SINGLE_BATTLE_TEST("Full Restore restores a battler's HP and cures confusion")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { HP(1); MaxHP(300); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_CONFUSE_RAY); }
        TURN { USE_ITEM(player, ITEM_FULL_RESTORE, partyIndex: 0); }
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("Qulbutoké récupère des PV.");
        NONE_OF { MESSAGE("Qulbutoké est confus!"); }
    } THEN {
        EXPECT_EQ(player->hp, player->maxHP);
    }
}

SINGLE_BATTLE_TEST("Full Restore resets Toxic Counter")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_TOXIC); }
        TURN {}
        TURN { USE_ITEM(player, ITEM_FULL_RESTORE, partyIndex: 0); }
    } SCENE {
        MESSAGE("Qulbutoké ennemi utilise\nToxik!");
        MESSAGE("Qulbutoké récupère des PV.");
        MESSAGE("Qulbutoké n'est plus empoisonné!");
    } THEN {
        EXPECT_EQ(player->status1, STATUS1_NONE);
    }
}

.equ REQUIRED_CAUGHT_MONS, 40

Route16_NorthEntrance_2F_Frlg_MapScripts::
	.byte 0

Route16_NorthEntrance_2F_EventScript_LittleBoy::
	msgbox Route16_NorthEntrance_2F_Text_OnBikeRideWithGirlfriend, MSGBOX_NPC
	end

Route16_NorthEntrance_2F_EventScript_LittleGirl::
	msgbox Route16_NorthEntrance_2F_Text_RidingTogetherOnNewBikes, MSGBOX_NPC
	end

Route16_NorthEntrance_2F_EventScript_LeftBinoculars::
	msgbox Route16_NorthEntrance_2F_Text_ItsCeladonDeptStore, MSGBOX_SIGN
	end

Route16_NorthEntrance_2F_EventScript_RightBinoculars::
	msgbox Route16_NorthEntrance_2F_Text_LongPathOverWater, MSGBOX_SIGN
	end

Route16_NorthEntrance_2F_EventScript_Aide::
	lock
	faceplayer
	call Route16_NorthEntrance_2F_EventScript_GetAideRequestInfo
	goto_if_set FLAG_GOT_AMULET_COIN_FROM_OAKS_AIDE, Route16_NorthEntrance_2F_EventScript_AlreadyGotAmuletCoin
	msgbox Route16_NorthEntrance_2F_Text_GiveAmuletCoinIfCaught40, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Aide_EventScript_DeclineCheckMons
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetFrlgPokedexCount
	buffernumberstring STR_VAR_3, VAR_0x8006
	call Route16_NorthEntrance_2F_EventScript_GetAideRequestInfo
	goto_if_lt VAR_0x8006, REQUIRED_CAUGHT_MONS, Aide_EventScript_HaventCaughtEnough
	msgbox Route16_NorthEntrance_2F_Text_GreatHereYouGo
	checkitemspace ITEM_AMULET_COIN
	goto_if_eq VAR_RESULT, FALSE, Aide_EventScript_NoRoomForItem
	giveitem_msg Route16_NorthEntrance_2F_Text_ReceivedAmuletCoinFromAide, ITEM_AMULET_COIN
	setflag FLAG_GOT_AMULET_COIN_FROM_OAKS_AIDE
	msgbox Route16_NorthEntrance_2F_Text_ExplainAmuletCoin
	release
	end

Route16_NorthEntrance_2F_EventScript_AlreadyGotAmuletCoin::
	msgbox Route16_NorthEntrance_2F_Text_ExplainAmuletCoin
	release
	end

Route16_NorthEntrance_2F_EventScript_GetAideRequestInfo::
	buffernumberstring STR_VAR_1, REQUIRED_CAUGHT_MONS
	bufferitemname STR_VAR_2, ITEM_AMULET_COIN
	return

Route16_NorthEntrance_2F_Text_OnBikeRideWithGirlfriend::
	.string "Je vais me faire une virée avec ma\n"
	.string "p'tite copine!$"

Route16_NorthEntrance_2F_Text_RidingTogetherOnNewBikes::
	.string "On va pédaler ensemble!$"

Route16_NorthEntrance_2F_Text_ItsCeladonDeptStore::
	.string "Vous regardez dans les jumelles…\p"
	.string "Vous voyez le CENTRE COMMERCIAL\n"
	.string "de CELADOPOLE!$"

Route16_NorthEntrance_2F_Text_LongPathOverWater::
	.string "Vous regardez dans les jumelles…\p"
	.string "Vous voyez un grand ponton!$"

Route16_NorthEntrance_2F_Text_GiveAmuletCoinIfCaught40::
	.string "Salut! Tu te rappelles?\n"
	.string "Je suis un assistant du PROF. CHEN!\p"
	.string "Si tu attrapes 40 POKéMON\n"
	.string "différents, je suis censé\l"
	.string "t'offrir cette PIECE RUNE!\p"
	.string "Alors {PLAYER}, as-tu attrapé au\n"
	.string "moins 40 POKéMON différents?$"

Route16_NorthEntrance_2F_Text_GreatHereYouGo::
	.string "Super! Tu as {STR_VAR_3} POKéMON\n"
	.string "différents!\p"
	.string "Félicitations!\n"
	.string "Voici ta récompense!$"

Route16_NorthEntrance_2F_Text_ReceivedAmuletCoinFromAide::
	.string "{PLAYER} obtient une\n"
	.string "PIECE RUNE!$"

Route16_NorthEntrance_2F_Text_ExplainAmuletCoin::
	.string "Une PIECE RUNE doit être tenue\n"
	.string "par un POKéMON.\p"
	.string "Si ce POKéMON apparaît dans une\n"
	.string "victoire, tu reçois plus d'argent.$"


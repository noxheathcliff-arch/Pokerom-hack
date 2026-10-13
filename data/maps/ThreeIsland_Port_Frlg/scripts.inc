ThreeIsland_Port_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ThreeIsland_Port_OnTransition
	.byte 0

ThreeIsland_Port_OnTransition::
	clearflag FLAG_SYS_PC_STORAGE_DISABLED
	setflag FLAG_SEVII_DETOUR_FINISHED
	end

ThreeIsland_Port_EventScript_Woman::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 2, ThreeIsland_Port_EventScript_WomanLostelleFound
	goto_if_ge VAR_MAP_SCENE_THREE_ISLAND, 4, ThreeIsland_Port_EventScript_WomanBikersGone
	msgbox ThreeIsland_Port_Text_IllCallThePolice
	release
	end

ThreeIsland_Port_EventScript_WomanLostelleFound::
	msgbox ThreeIsland_Port_Text_EverythingTurnedOutForBest
	release
	end

ThreeIsland_Port_EventScript_WomanBikersGone::
	msgbox ThreeIsland_Port_Text_ThankGoodnessBikersGone
	release
	end

ThreeIsland_Port_EventScript_Biker1::
	msgbox ThreeIsland_Port_Text_WereKantoRiderFederation, MSGBOX_NPC
	end

ThreeIsland_Port_EventScript_Biker2::
	lock
	msgbox ThreeIsland_Port_Text_ForkOverMoney
	release
	end

ThreeIsland_Port_Text_WereKantoRiderFederation::
	.string "On est les KANTO ANGELS!\n"
	.string "Vroom! Vavavavooom! Vroom!\p"
	.string "La honte, je dois faire le bruit de\n"
	.string "ma bécane tout seul.$"

ThreeIsland_Port_Text_ForkOverMoney::
	.string "Hey! Madame,\n"
	.string "t'aurais pas du liquide sur toi?$"

ThreeIsland_Port_Text_IllCallThePolice::
	.string "Aaaah.\p"
	.string "Qu-qui êtes-vous? Je vais appeler\n"
	.string "la police moi, voyous!$"

ThreeIsland_Port_Text_ThankGoodnessBikersGone::
	.string "Ces MOTARDS…\n"
	.string "Ils sont vraiment partis?\p"
	.string "Oh, merci mon dieu!\n"
	.string "Ils m'ont fait une peur bleue.$"

ThreeIsland_Port_Text_EverythingTurnedOutForBest::
	.string "Ces MOTARDS sont partis et\n"
	.string "LOSTELLE est saine et sauve.\p"
	.string "Tout est bien qui finit bien.$"


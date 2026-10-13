.equ REQUIRED_SEEN_MONS, 10

Route2_EastBuilding_Frlg_MapScripts::
	.byte 0

Route2_EastBuilding_EventScript_Aide::
	lock
	faceplayer
	call Route2_EastBuilding_EventScript_GetAideRequestInfo
	goto_if_set FLAG_GOT_HM05, Route2_EastBuilding_EventScript_AlreadyGotHM05
	msgbox Route2_EastBuilding_Text_GiveHM05IfSeen10Mons, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Aide_EventScript_DeclineCheckMons
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetFrlgPokedexCount
	buffernumberstring STR_VAR_3, VAR_0x8006
	call Route2_EastBuilding_EventScript_GetAideRequestInfo
	goto_if_lt VAR_0x8006, REQUIRED_SEEN_MONS, Aide_EventScript_HaventCaughtEnough
	msgbox Route2_EastBuilding_Text_GreatHereYouGo
	checkitemspace ITEM_HM05
	goto_if_eq VAR_RESULT, FALSE, Aide_EventScript_NoRoomForItem
	giveitem_msg Route2_EastBuilding_Text_ReceivedHM05FromAide, ITEM_HM05
	setflag FLAG_GOT_HM05
	msgbox Route2_EastBuilding_Text_ExplainHM05
	release
	end

Route2_EastBuilding_EventScript_AlreadyGotHM05::
	msgbox Route2_EastBuilding_Text_ExplainHM05
	release
	end

Route2_EastBuilding_EventScript_GetAideRequestInfo::
	buffernumberstring STR_VAR_1, REQUIRED_SEEN_MONS
	bufferitemname STR_VAR_2, ITEM_HM05
	return

Route2_EastBuilding_EventScript_Rocker::
	msgbox Route2_EastBuilding_Text_CanGetThroughRockTunnel, MSGBOX_NPC
	end

Route2_EastBuilding_Text_GiveHM05IfSeen10Mons::
	.string "Salut! Tu te rappelles de moi?\n"
	.string "Je suis un assistant du PROF. CHEN!\p"
	.string "Si tu attrapes dix POKéMON\n"
	.string "différents, je suis censé t'offrir…\p"
	.string "cette CS05!\p"
	.string "Alors {PLAYER}, as-tu attrapé au\n"
	.string "moins dix POKéMON différents?$"

Route2_EastBuilding_Text_GreatHereYouGo::
	.string "Super! Tu as {STR_VAR_3} POKéMON\n"
	.string "différents!\p"
	.string "Félicitations!\n"
	.string "Voici ta récompense!$"

Route2_EastBuilding_Text_ReceivedHM05FromAide::
	.string "{PLAYER} obtient\n"
	.string "CS05!$"

Route2_EastBuilding_Text_ExplainHM05::
	.string "La CS FLASH peut éclairer les\n"
	.string "endroits sombres.$"

Route2_EastBuilding_Text_CanGetThroughRockTunnel::
	.string "Si un POKéMON a appris FLASH,\n"
	.string "tu pourras traverser la GROTTE.$"


.equ REQUIRED_CAUGHT_MONS, 50

Route15_WestEntrance_2F_Frlg_MapScripts::
	.byte 0

Route15_WestEntrance_2F_EventScript_LeftBinoculars::
	lockall
	msgbox Route15_WestEntrance_2F_Text_LargeShiningBird
	showmonpic SPECIES_ARTICUNO, 10, 3
	delay 20
	waitbuttonpress
	hidemonpic
	setvar VAR_0x8004, SPECIES_ARTICUNO
	special SetSeenMon
	releaseall
	end

Route15_WestEntrance_2F_EventScript_RightBinoculars::
	msgbox Route15_WestEntrance_2F_Text_SmallIslandOnHorizon, MSGBOX_SIGN
	end

Route15_WestEntrance_2F_EventScript_Aide::
	lock
	faceplayer
	call Route15_WestEntrance_2F_EventScript_GetAideRequestInfo
	goto_if_set FLAG_GOT_EXP_SHARE_FROM_OAKS_AIDE, Route15_WestEntrance_2F_EventScript_AlreadyGotExpShare
	msgbox Route15_WestEntrance_2F_Text_GiveItemIfCaughtEnough, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Aide_EventScript_DeclineCheckMons
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetFrlgPokedexCount
	buffernumberstring STR_VAR_3, VAR_0x8006
	call Route15_WestEntrance_2F_EventScript_GetAideRequestInfo
	goto_if_lt VAR_0x8006, REQUIRED_CAUGHT_MONS, Aide_EventScript_HaventCaughtEnough
	msgbox Route15_WestEntrance_2F_Text_GreatHereYouGo
	checkitemspace ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Aide_EventScript_NoRoomForItem
	giveitem_msg Route15_WestEntrance_2F_Text_ReceivedItemFromAide, ITEM_EXP_SHARE
	setflag FLAG_GOT_EXP_SHARE_FROM_OAKS_AIDE
	msgbox Route15_WestEntrance_2F_Text_ExplainExpShare
	release
	end

Route15_WestEntrance_2F_EventScript_AlreadyGotExpShare::
	msgbox Route15_WestEntrance_2F_Text_ExplainExpShare
	release
	end

Route15_WestEntrance_2F_EventScript_GetAideRequestInfo::
	buffernumberstring STR_VAR_1, REQUIRED_CAUGHT_MONS
	bufferitemname STR_VAR_2, ITEM_EXP_SHARE
	return

Route15_WestEntrance_2F_Text_GiveItemIfCaughtEnough::
	.string "Salut! Tu te rappelles?\n"
	.string "Je suis un assistant du PROF. CHEN!\p"
	.string "Si tu attrapes {STR_VAR_1} POKéMON\n"
	.string "différents, je suis censé t'offrir…\l"
	.string "{STR_VAR_2}!\p"
	.string "Alors {PLAYER}, as-tu attrapé au\n"
	.string "moins {STR_VAR_1} POKéMON différents?$"

Route15_WestEntrance_2F_Text_GreatHereYouGo::
	.string "Super! Tu as {STR_VAR_3} POKéMON\n"
	.string "différents!\p"
	.string "Félicitations!\n"
	.string "Voici ta récompense!$"

Route15_WestEntrance_2F_Text_ReceivedItemFromAide::
	.string "{PLAYER} obtient\n"
	.string "{STR_VAR_2}!$"

Route15_WestEntrance_2F_Text_ExplainExpShare::
	.string "MULTI EXP est un objet qui\n"
	.string "doit être porté par un POKéMON.\p"
	.string "Les POKéMON de ton équipe se\n"
	.string "partageront les points d'EXP.\p"
	.string "après un combat. Même ceux\n"
	.string "qui n'ont pas combattu.$"

Route15_WestEntrance_2F_Text_LargeShiningBird::
	.string "Vous regardez dans les jumelles…\p"
	.string "Un grand et bel oiseau vole vers\n"
	.string "la mer.$"

Route15_WestEntrance_2F_Text_SmallIslandOnHorizon::
	.string "Vous regardez dans les jumelles…\p"
	.string "Vous voyez une petite île!$"


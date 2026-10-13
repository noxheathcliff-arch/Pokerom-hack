PewterCity_House1_Frlg_MapScripts::
	.byte 0

PewterCity_House1_EventScript_BaldingMan::
	msgbox PewterCity_House1_Text_TradeMonsAreFinicky, MSGBOX_NPC
	end

PewterCity_House1_EventScript_LittleBoy::
	lock
	msgbox PewterCity_House1_Text_NidoranSit
	call PewterCity_House1_EventScript_DoNidoranCry
	release
	end

PewterCity_House1_EventScript_Nidoran::
	lock
	faceplayer
	call PewterCity_House1_EventScript_DoNidoranCry
	applymovement LOCALID_PEWTER_HOUSE_NIDORAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PewterCity_House1_EventScript_DoNidoranCry::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	waitse
	playmoncry SPECIES_NIDORAN_M, CRY_MODE_NORMAL
	msgbox PewterCity_House1_Text_Nidoran
	waitmoncry
	call EventScript_RestorePrevTextColor
	return

PewterCity_House1_Text_Nidoran::
	.string "NIDORAN♂: Nidoni!$"

PewterCity_House1_Text_NidoranSit::
	.string "NIDORAN, assis!$"

PewterCity_House1_Text_TradeMonsAreFinicky::
	.string "Notre POKéMON est un échangé, il\n"
	.string "est difficile à maîtriser.\p"
	.string "Un échangé est un POKéMON échangé\n"
	.string "avec un autre joueur.\p"
	.string "Il grandit vite, mais il n'en fait\n"
	.string "qu'à sa tête pendant les combats!\p"
	.string "Si seulement nous avions des\n"
	.string "BADGES…$"


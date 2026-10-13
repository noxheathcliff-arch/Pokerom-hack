FuchsiaCity_House1_Frlg_MapScripts::
	.byte 0

FuchsiaCity_House1_EventScript_Woman::
	msgbox FuchsiaCity_House1_Text_WardenIsOldHasFalseTeeth, MSGBOX_NPC
	end

FuchsiaCity_House1_EventScript_OldMan::
	lock
	faceplayer
	famechecker FAMECHECKER_BILL, 2
	msgbox FuchsiaCity_House1_Text_BillIsMyGrandson
	release
	end

FuchsiaCity_House1_EventScript_LittleBoy::
	msgbox FuchsiaCity_House1_Text_BillFilesHisOwnMonData, MSGBOX_NPC
	end

FuchsiaCity_House1_Text_WardenIsOldHasFalseTeeth::
	.string "Le GARDIEN du PARC SAFARI est\n"
	.string "vieux mais trop cool!\p"
	.string "Ses dents sont fausses par contre.$"

FuchsiaCity_House1_Text_BillIsMyGrandson::
	.string "Hmm?\n"
	.string "Tu connais LEO?\p"
	.string "C'est mon petit-fils!\p"
	.string "Il souffre de collectionnite\n"
	.string "depuis tout petit!$"

FuchsiaCity_House1_Text_BillFilesHisOwnMonData::
	.string "LEO enregistre ses données sur les\n"
	.string "POKéMON sur son PC!\p"
	.string "Il t'a déjà montré tout ça?$"


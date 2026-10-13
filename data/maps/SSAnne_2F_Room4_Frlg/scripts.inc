SSAnne_2F_Room4_Frlg_MapScripts::
	.byte 0

SSAnne_2F_Room4_EventScript_Lamar::
	trainerbattle_single TRAINER_GENTLEMAN_LAMAR, SSAnne_2F_Room4_Text_LamarIntro, SSAnne_2F_Room4_Text_LamarDefeat
	msgbox SSAnne_2F_Room4_Text_LamarPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_2F_Room4_EventScript_Dawn::
	trainerbattle_single TRAINER_LASS_DAWN, SSAnne_2F_Room4_Text_DawnIntro, SSAnne_2F_Room4_Text_DawnDefeat
	msgbox SSAnne_2F_Room4_Text_DawnPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_2F_Room4_Text_LamarIntro::
	.string "Qu'est-ce que tu préfères?\n"
	.string "Un POKéMON costaud ou rare?$"

SSAnne_2F_Room4_Text_LamarDefeat::
	.string "Bravo!\n"
	.string "Tu es plutôt balèze!$"

SSAnne_2F_Room4_Text_LamarPostBattle::
	.string "Je préfère les POKéMON rares\n"
	.string "et costauds!$"

SSAnne_2F_Room4_Text_DawnIntro::
	.string "Je ne crois pas que tu étais \n"
	.string "à la fête.$"

SSAnne_2F_Room4_Text_DawnDefeat::
	.string "Relax!\n"
	.string "T'énerve pas!!!$"

SSAnne_2F_Room4_Text_DawnPostBattle::
	.string "Woah! Tes POKéMON sont super\n"
	.string "forts! Je les adore!$"


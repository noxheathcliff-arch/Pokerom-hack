SSAnne_1F_Room7_Frlg_MapScripts::
	.byte 0

SSAnne_1F_Room7_EventScript_Thomas::
	trainerbattle_single TRAINER_GENTLEMAN_THOMAS, SSAnne_1F_Room7_Text_ThomasIntro, SSAnne_1F_Room7_Text_ThomasDefeat
	msgbox SSAnne_1F_Room7_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room7_Text_ThomasIntro::
	.string "Je voyage toujours en solitaire!\p"
	.string "Mes POKéMON sont mes amis!$"

SSAnne_1F_Room7_Text_ThomasDefeat::
	.string "Non!\n"
	.string "Mes p'tits amis!$"

SSAnne_1F_Room7_Text_ThomasPostBattle::
	.string "Il faut être gentil avec ses\n"
	.string "POKéMON!$"


SSAnne_1F_Room5_Frlg_MapScripts::
	.byte 0

SSAnne_1F_Room5_EventScript_Arthur::
	trainerbattle_single TRAINER_GENTLEMAN_ARTHUR, SSAnne_1F_Room5_Text_ArthurIntro, SSAnne_1F_Room5_Text_ArthurDefeat
	msgbox SSAnne_1F_Room5_Text_ArthurPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room5_Text_ArthurIntro::
	.string "Toi, t'as du culot!\n"
	.string "Tu oses entrer ici!?$"

SSAnne_1F_Room5_Text_ArthurDefeat::
	.string "Huf!\n"
	.string "Aucun sens de la courtoisie!!$"

SSAnne_1F_Room5_Text_ArthurPostBattle::
	.string "J'aimerais être seul!\n"
	.string "Va-t-en!$"


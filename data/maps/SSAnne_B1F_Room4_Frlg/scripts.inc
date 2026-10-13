SSAnne_B1F_Room4_Frlg_MapScripts::
	.byte 0

SSAnne_B1F_Room4_EventScript_Leonard::
	trainerbattle_single TRAINER_SAILOR_LEONARD, SSAnne_B1F_Room4_Text_LeonardIntro, SSAnne_B1F_Room4_Text_LeonardDefeat
	msgbox SSAnne_B1F_Room4_Text_LeonardPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room4_EventScript_Duncan::
	trainerbattle_single TRAINER_SAILOR_DUNCAN, SSAnne_B1F_Room4_Text_DuncanIntro, SSAnne_B1F_Room4_Text_DuncanDefeat
	msgbox SSAnne_B1F_Room4_Text_DuncanPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room4_Text_LeonardIntro::
	.string "Tu sais ce qu'on raconte sur les\n"
	.string "marins et les duels!$"

SSAnne_B1F_Room4_Text_LeonardDefeat::
	.string "Ouaip!\n"
	.string "Beau combat!$"

SSAnne_B1F_Room4_Text_LeonardPostBattle::
	.string "Alors, mousse, tu veux devenir\n"
	.string "marin?$"

SSAnne_B1F_Room4_Text_DuncanIntro::
	.string "Ma réputation de marin est en jeu!$"

SSAnne_B1F_Room4_Text_DuncanDefeat::
	.string "Ha!\n"
	.string "Je sombre!$"

SSAnne_B1F_Room4_Text_DuncanPostBattle::
	.string "As-tu rencontré le MAITRE PECHEUR\n"
	.string "à CARMIN SUR MER?$"


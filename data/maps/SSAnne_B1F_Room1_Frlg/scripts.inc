SSAnne_B1F_Room1_Frlg_MapScripts::
	.byte 0

SSAnne_B1F_Room1_EventScript_Barny::
	trainerbattle_single TRAINER_FISHERMAN_BARNY, SSAnne_B1F_Room1_Text_BarnyIntro, SSAnne_B1F_Room1_Text_BarnyDefeat
	msgbox SSAnne_B1F_Room1_Text_BarnyPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room1_EventScript_Phillip::
	trainerbattle_single TRAINER_SAILOR_PHILLIP, SSAnne_B1F_Room1_Text_PhillipIntro, SSAnne_B1F_Room1_Text_PhillipDefeat
	msgbox SSAnne_B1F_Room1_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room1_Text_PhillipIntro::
	.string "Si tu perds, on te balance aux\n"
	.string "requins!$"

SSAnne_B1F_Room1_Text_PhillipDefeat::
	.string "Hein?\n"
	.string "Battu par toi?$"

SSAnne_B1F_Room1_Text_PhillipPostBattle::
	.string "Quelques POKéMON sont souvent\n"
	.string "entraînés dans le sillage du\l"
	.string "bateau…$"

SSAnne_B1F_Room1_Text_BarnyIntro::
	.string "Salut étranger!\n"
	.string "Parlons un peu!\p"
	.string "Tous mes POKéMON viennent\n"
	.string "de la mer!$"

SSAnne_B1F_Room1_Text_BarnyDefeat::
	.string "Zut!\n"
	.string "Celui-là s'est échappé!$"

SSAnne_B1F_Room1_Text_BarnyPostBattle::
	.string "Je cherche un assistant. Tu aurais\n"
	.string "pu faire l'affaire.$"


SSAnne_2F_Room2_Frlg_MapScripts::
	.byte 0

SSAnne_2F_Room2_EventScript_Dale::
	trainerbattle_single TRAINER_FISHERMAN_DALE, SSAnne_2F_Room2_Text_DaleIntro, SSAnne_2F_Room2_Text_DaleDefeat
	msgbox SSAnne_2F_Room2_Text_DalePostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_2F_Room2_EventScript_Brooks::
	trainerbattle_single TRAINER_GENTLEMAN_BROOKS, SSAnne_2F_Room2_Text_BrooksIntro, SSAnne_2F_Room2_Text_BrooksDefeat
	msgbox SSAnne_2F_Room2_Text_BrooksPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_2F_Room2_Text_BrooksIntro::
	.string "Les duels contre les jeunes me\n"
	.string "maintiennent en forme!$"

SSAnne_2F_Room2_Text_BrooksDefeat::
	.string "Woah!\n"
	.string "Ha! Je me sens en pleine forme!$"

SSAnne_2F_Room2_Text_BrooksPostBattle::
	.string "Hmm!\n"
	.string "Il y a 15 ans, j'aurais gagné…$"

SSAnne_2F_Room2_Text_DaleIntro::
	.string "Hé!\n"
	.string "Regarde ce que j'ai pêché!$"

SSAnne_2F_Room2_Text_DaleDefeat::
	.string "OK!\n"
	.string "J'suis fait!!$"

SSAnne_2F_Room2_Text_DalePostBattle::
	.string "Une fête?\p"
	.string "Elle doit être finie maintenant.$"


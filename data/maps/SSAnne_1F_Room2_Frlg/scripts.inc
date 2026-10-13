SSAnne_1F_Room2_Frlg_MapScripts::
	.byte 0

SSAnne_1F_Room2_EventScript_Woman::
	msgbox SSAnne_1F_Room2_Text_CruisingAroundWorld, MSGBOX_NPC
	end

SSAnne_1F_Room2_EventScript_Ann::
	trainerbattle_single TRAINER_LASS_ANN, SSAnne_1F_Room2_Text_AnnIntro, SSAnne_1F_Room2_Text_AnnDefeat
	msgbox SSAnne_1F_Room2_Text_AnnPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room2_EventScript_Tyler::
	trainerbattle_single TRAINER_YOUNGSTER_TYLER, SSAnne_1F_Room2_Text_TylerIntro, SSAnne_1F_Room2_Text_TylerDefeat
	msgbox SSAnne_1F_Room2_Text_TylerPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_1F_Room2_Text_TylerIntro::
	.string "J'aime les POKéMON! Et toi?$"

SSAnne_1F_Room2_Text_TylerDefeat::
	.string "Woo!\n"
	.string "T'es cool, toi!$"

SSAnne_1F_Room2_Text_TylerPostBattle::
	.string "Soyons amis, OK?\p"
	.string "Comme ça, on pourra\n"
	.string "échanger nos POKéMON!$"

SSAnne_1F_Room2_Text_AnnIntro::
	.string "J'ai déniché ces POKéMON un peu\n"
	.string "partout dans le monde!$"

SSAnne_1F_Room2_Text_AnnDefeat::
	.string "Quoi! Un tour du monde pour ce\n"
	.string "résultat! C'est nul!$"

SSAnne_1F_Room2_Text_AnnPostBattle::
	.string "Tu as fait mal à mes POKéMON!\p"
	.string "Il faut que tu les soignes dans un\n"
	.string "CENTRE POKéMON!!!$"

SSAnne_1F_Room2_Text_CruisingAroundWorld::
	.string "Nous parcourons les mers du\n"
	.string "monde entier!$"


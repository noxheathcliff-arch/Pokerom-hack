SSAnne_B1F_Room2_Frlg_MapScripts::
	.byte 0

SSAnne_B1F_Room2_EventScript_Huey::
	trainerbattle_single TRAINER_SAILOR_HUEY, SSAnne_B1F_Room2_Text_HueyIntro, SSAnne_B1F_Room2_Text_HueyDefeat
	msgbox SSAnne_B1F_Room2_Text_HueyPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room2_Text_HueyIntro::
	.string "Nous, les marins, on a aussi des\n"
	.string "POKéMON!$"

SSAnne_B1F_Room2_Text_HueyDefeat::
	.string "OK!\n"
	.string "Tu te bats pas trop mal!$"

SSAnne_B1F_Room2_Text_HueyPostBattle::
	.string "Tous nos POKéMON viennent des\n"
	.string "hautes mers!$"


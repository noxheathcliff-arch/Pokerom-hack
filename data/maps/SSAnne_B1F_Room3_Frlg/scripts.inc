SSAnne_B1F_Room3_Frlg_MapScripts::
	.byte 0

SSAnne_B1F_Room3_EventScript_Dylan::
	trainerbattle_single TRAINER_SAILOR_DYLAN, SSAnne_B1F_Room3_Text_DylanIntro, SSAnne_B1F_Room3_Text_DylanDefeat
	msgbox SSAnne_B1F_Room3_Text_DylanPostBattle, MSGBOX_AUTOCLOSE
	end

SSAnne_B1F_Room3_Text_DylanIntro::
	.string "J'aime les enfants joyeux\n"
	.string "comme toi!$"

SSAnne_B1F_Room3_Text_DylanDefeat::
	.string "Hein?\n"
	.string "J'ai perdu? Argh!$"

SSAnne_B1F_Room3_Text_DylanPostBattle::
	.string "Les POKéMON EAU vivent dans les\n"
	.string "grands fonds! J'ai besoin d'une\l"
	.string "CANNE!$"


RocketHideout_B2F_Frlg_MapScripts::
	.byte 0

RocketHideout_B2F_EventScript_Grunt::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_13, RocketHideout_B2F_Text_GruntIntro, RocketHideout_B2F_Text_GruntDefeat
	msgbox RocketHideout_B2F_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B2F_Text_GruntIntro::
	.string "Le chef dit qu'on peut voir les\n"
	.string "fantômes avec un SCOPE SYLPHE!$"

RocketHideout_B2F_Text_GruntDefeat::
	.string "STOP!\n"
	.string "J'me rends!$"

RocketHideout_B2F_Text_GruntPostBattle::
	.string "Le repaire de la TEAM ROCKET a\n"
	.string "4 niveaux souterrains.\p"
	.string "Pourras-tu arriver jusqu'au chef?$"


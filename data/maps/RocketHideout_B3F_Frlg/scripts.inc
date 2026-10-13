RocketHideout_B3F_Frlg_MapScripts::
	.byte 0

RocketHideout_B3F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_14, RocketHideout_B3F_Text_Grunt1Intro, RocketHideout_B3F_Text_Grunt1Defeat
	msgbox RocketHideout_B3F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B3F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_15, RocketHideout_B3F_Text_Grunt2Intro, RocketHideout_B3F_Text_Grunt2Defeat
	msgbox RocketHideout_B3F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B3F_Text_Grunt1Intro::
	.string "Ne te mêle plus des affaires de la\n"
	.string "TEAM ROCKET!$"

RocketHideout_B3F_Text_Grunt1Defeat::
	.string "Paf!\n"
	.string "J'suis au tapis!$"

RocketHideout_B3F_Text_Grunt1PostBattle::
	.string "Le SCOPE SYLPHE?\n"
	.string "Le bidule que le chef a volé?\p"
	.string "Il est là, quelque part…$"

RocketHideout_B3F_Text_Grunt2Intro::
	.string "On nous a prévenus de ton arrivée!$"

RocketHideout_B3F_Text_Grunt2Defeat::
	.string "Quoi?\n"
	.string "J'ai perdu? NON!$"

RocketHideout_B3F_Text_Grunt2PostBattle::
	.string "Allez, continue!\p"
	.string "Mais il te faut la CLE ASC. pour\n"
	.string "l'ascenseur!$"


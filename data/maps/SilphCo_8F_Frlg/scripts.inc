SilphCo_8F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_8F_OnLoad
	.byte 0

SilphCo_8F_OnLoad::
	call_if_unset FLAG_SILPH_8F_DOOR, EventScript_Close8FDoor
	end

SilphCo_8F_EventScript_WorkerM::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_8F_EventScript_WorkerMRocketsGone
	msgbox SilphCo_8F_Text_WonderIfSilphIsFinished
	release
	end

SilphCo_8F_EventScript_WorkerMRocketsGone::
	msgbox SilphCo_8F_Text_ThanksForSavingUs
	release
	end

SilphCo_8F_EventScript_FloorSign::
	msgbox SilphCo_8F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_8F_EventScript_Parker::
	trainerbattle_single TRAINER_SCIENTIST_PARKER, SilphCo_8F_Text_ParkerIntro, SilphCo_8F_Text_ParkerDefeat
	msgbox SilphCo_8F_Text_ParkerPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_8F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_32, SilphCo_8F_Text_Grunt1Intro, SilphCo_8F_Text_Grunt1Defeat
	msgbox SilphCo_8F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_8F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_36, SilphCo_8F_Text_Grunt2Intro, SilphCo_8F_Text_Grunt2Defeat
	msgbox SilphCo_8F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_8F_Text_WonderIfSilphIsFinished::
	.string "Mmm… La SYLPHE va-t-elle faire\n"
	.string "faillite?$"

SilphCo_8F_Text_ThanksForSavingUs::
	.string "Merci de nous avoir sauvés!$"

SilphCo_8F_Text_Grunt1Intro::
	.string "Hop hop hop!\n"
	.string "On ne bouge plus!$"

SilphCo_8F_Text_Grunt1Defeat::
	.string "Je suis faible!$"

SilphCo_8F_Text_Grunt1PostBattle::
	.string "Va-t-en ou j'appelle du renfort!$"

SilphCo_8F_Text_ParkerIntro::
	.string "Tu nous casses les pieds!$"

SilphCo_8F_Text_ParkerDefeat::
	.string "Heu?\n"
	.string "J'ai perdu?$"

SilphCo_8F_Text_ParkerPostBattle::
	.string "La SYLPHE est un vrai labyrinthe,\n"
	.string "hein?$"

SilphCo_8F_Text_Grunt2Intro::
	.string "Je suis l'un des 4 FRERES ROCKET!$"

SilphCo_8F_Text_Grunt2Defeat::
	.string "Whoo!\n"
	.string "Frèèèères!$"

SilphCo_8F_Text_Grunt2PostBattle::
	.string "Mes frères te dégommeront!$"

SilphCo_8F_Text_FloorSign::
	.string "SYLPHE SARL.\n"
	.string "7ème étage.$"

SilphCo_8F_Text_ToRocketBossMonsAreTools::
	.string "Le chef de la TEAM ROCKET est\n"
	.string "incroyablement cruel.\p"
	.string "Pour lui, les POKéMON ne sont que\n"
	.string "des outils.\p"
	.string "Qu'arrivera-t-il s'il arrive à\n"
	.string "s'emparer de notre compagnie?$"

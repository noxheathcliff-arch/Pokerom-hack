SilphCo_10F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_10F_OnLoad
	.byte 0

SilphCo_10F_OnLoad::
	call_if_unset FLAG_SILPH_10F_DOOR, EventScript_Close10FDoor
	end

SilphCo_10F_EventScript_WorkerF::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_10F_EventScript_WorkerFRocketsGone
	msgbox SilphCo_10F_Text_WaaaImScared
	release
	end

SilphCo_10F_EventScript_WorkerFRocketsGone::
	msgbox SilphCo_10F_Text_KeepMeCryingASecret
	release
	end

SilphCo_10F_EventScript_FloorSign::
	msgbox SilphCo_10F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_10F_EventScript_Travis::
	trainerbattle_single TRAINER_SCIENTIST_TRAVIS, SilphCo_10F_Text_TravisIntro, SilphCo_10F_Text_TravisDefeat
	msgbox SilphCo_10F_Text_TravisPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_10F_EventScript_Grunt::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_39, SilphCo_10F_Text_GruntIntro, SilphCo_10F_Text_GruntDefeat
	msgbox SilphCo_10F_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_10F_Text_GruntIntro::
	.string "Bienvenue au 9ème étage!\n"
	.string "C'est sympa de passer!$"

SilphCo_10F_Text_GruntDefeat::
	.string "Aïe!\n"
	.string "Bobo!$"

SilphCo_10F_Text_GruntPostBattle::
	.string "Bien joué, mais la salle du\n"
	.string "conseil est au-dessus!$"

SilphCo_10F_Text_TravisIntro::
	.string "Maintenant…\n"
	.string "Fini de jouer!$"

SilphCo_10F_Text_TravisDefeat::
	.string "Oh!\n"
	.string "Game Over!$"

SilphCo_10F_Text_TravisPostBattle::
	.string "T'as gagné!\n"
	.string "Alors retourne chez toi!$"

SilphCo_10F_Text_WaaaImScared::
	.string "Waaaaa!\n"
	.string "Mamaaaan!$"

SilphCo_10F_Text_KeepMeCryingASecret::
	.string "Ne raconte à personne que j'ai\n"
	.string "pleuré!$"

SilphCo_10F_Text_FloorSign::
	.string "SYLPHE SARL.\n"
	.string "9ème étage.$"


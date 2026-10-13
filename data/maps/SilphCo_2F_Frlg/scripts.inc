SilphCo_2F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_2F_OnLoad
	.byte 0

SilphCo_2F_OnLoad::
	call_if_unset FLAG_SILPH_2F_DOOR_1, EventScript_Close2FDoor1
	call_if_unset FLAG_SILPH_2F_DOOR_2, EventScript_Close2FDoor2
	end

SilphCo_2F_EventScript_ThunderWaveTutor::
	goto EventScript_ThunderWaveTutor
	end

SilphCo_2F_EventScript_FloorSign::
	msgbox SilphCo_2F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_2F_EventScript_Connor::
	trainerbattle_single TRAINER_SCIENTIST_CONNOR, SilphCo_2F_Text_ConnorIntro, SilphCo_2F_Text_ConnorDefeat
	msgbox SilphCo_2F_Text_ConnorPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_EventScript_Jerry::
	trainerbattle_single TRAINER_SCIENTIST_JERRY, SilphCo_2F_Text_JerryIntro, SilphCo_2F_Text_JerryDefeat
	msgbox SilphCo_2F_Text_JerryPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_23, SilphCo_2F_Text_Grunt1Intro, SilphCo_2F_Text_Grunt1Defeat
	msgbox SilphCo_2F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_24, SilphCo_2F_Text_Grunt2Intro, SilphCo_2F_Text_Grunt2Defeat
	msgbox SilphCo_2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_2F_Text_ConnorIntro::
	.string "A l'aide! Je suis un employé de la\n"
	.string "SYLPHE SARL!$"

SilphCo_2F_Text_ConnorDefeat::
	.string "???\n"
	.string "Comment t'as su que j'étais de\l"
	.string "la TEAM ROCKET?$"

SilphCo_2F_Text_ConnorPostBattle::
	.string "Je travaille pour la SYLPHE SARL\n"
	.string "et la TEAM ROCKET!$"

SilphCo_2F_Text_JerryIntro::
	.string "Hop hop!\n"
	.string "Zone privée, dégage!$"

SilphCo_2F_Text_JerryDefeat::
	.string "OK.\n"
	.string "J'suis battu!$"

SilphCo_2F_Text_JerryPostBattle::
	.string "Trouve la sortie du labyrinthe!$"

SilphCo_2F_Text_Grunt1Intro::
	.string "Hé! Pas de mioches ici!$"

SilphCo_2F_Text_Grunt1Defeat::
	.string "La vache! T'es balèze.$"

SilphCo_2F_Text_Grunt1PostBattle::
	.string "Les dalles en forme de diamant sont\n"
	.string "des téléporteurs!\p"
	.string "C'est de la super technologie!$"

SilphCo_2F_Text_Grunt2Intro::
	.string "Hé, p'tite tête!\n"
	.string "Qu'est-ce tu fais là?$"

SilphCo_2F_Text_Grunt2Defeat::
	.string "Oups, j'ai perdu!$"

SilphCo_2F_Text_Grunt2PostBattle::
	.string "La SYLPHE SARL et la TEAM ROCKET\n"
	.string "vont fusionner!$"

Text_ThunderWaveTeach::
	.string "Au secours!\n"
	.string "A l'aide!\p"
	.string "Quoi?\n"
	.string "Tu n'es pas de la TEAM?\p"
	.string "Tant mieux!\n"
	.string "Tiens, prends ça!$"

Text_ThunderWaveDeclined::
	.string "Oh…\n"
	.string "Mais CAGE-ECLAIR est utile…$"

Text_ThunderWaveWhichMon::
	.string "A quel POKéMON enseigner\n"
	.string "CAGE-ECLAIR?$"

Text_ThunderWaveTaught::
	.string "CAGE-ECLAIR paralyse le\n"
	.string "POKéMON attaqué.\p"
	.string "Un POKéMON paralysé peut être\n"
	.string "incapable d'attaquer en combat.\p"
	.string "C'est une capacité de type\n"
	.string "ELECTRIK, ça ne marchera pas\l"
	.string "sur tous les POKéMON.$"

SilphCo_2F_Text_FloorSign::
	.string "SYLPHE SARL.\n"
	.string "1er étage.$"


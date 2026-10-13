SilphCo_3F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_3F_OnLoad
	.byte 0

SilphCo_3F_OnLoad::
	call_if_unset FLAG_SILPH_3F_DOOR_1, EventScript_Close3FDoor1
	call_if_unset FLAG_SILPH_3F_DOOR_2, EventScript_Close3FDoor2
	end

SilphCo_3F_EventScript_WorkerM::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_3F_EventScript_WorkerMRocketsGone
	msgbox SilphCo_3F_Text_WhatAmIToDo
	release
	end

SilphCo_3F_EventScript_WorkerMRocketsGone::
	msgbox SilphCo_3F_Text_YouAndYourMonsSavedUs
	release
	end

SilphCo_3F_EventScript_FloorSign::
	msgbox SilphCo_3F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_3F_EventScript_Jose::
	trainerbattle_single TRAINER_SCIENTIST_JOSE, SilphCo_3F_Text_JoseIntro, SilphCo_3F_Text_JoseDefeat
	msgbox SilphCo_3F_Text_JosePostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_3F_EventScript_Grunt::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_25, SilphCo_3F_Text_GruntIntro, SilphCo_3F_Text_GruntDefeat
	msgbox SilphCo_3F_Text_GruntPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_3F_Text_WhatAmIToDo::
	.string "Je travaille pour la SYLPHE SARL.\n"
	.string "Que faire d'autre?$"

SilphCo_3F_Text_YouAndYourMonsSavedUs::
	.string "{PLAYER}!\p"
	.string "Toi et tes POKéMON, vous nous\n"
	.string "avez sauvés!$"

SilphCo_3F_Text_GruntIntro::
	.string "T'occupe pas de nos affaires!$"

SilphCo_3F_Text_GruntDefeat::
	.string "Yaha!\n"
	.string "T'es trop fort!$"

SilphCo_3F_Text_GruntPostBattle::
	.string "Tu peux ouvrir les portes avec\n"
	.string "la CARTE MAGN.!$"

SilphCo_3F_Text_JoseIntro::
	.string "Je préfère la TEAM ROCKET à\n"
	.string "la SYLPHE SARL!!!$"

SilphCo_3F_Text_JoseDefeat::
	.string "!!!\n"
	.string "Tu m'as eu!$"

SilphCo_3F_Text_JosePostBattle::
	.string "Hmmm…\p"
	.string "J'aide la TEAM ROCKET et ils me\n"
	.string "laissent étudier les POKéMON!$"

SilphCo_3F_Text_FloorSign::
	.string "SYLPHE SARL.\n"
	.string "2ème étage.$"


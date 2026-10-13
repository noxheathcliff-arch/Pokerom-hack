SilphCo_9F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_9F_OnLoad
	.byte 0

SilphCo_9F_OnLoad::
	call_if_unset FLAG_SILPH_9F_DOOR_1, EventScript_Close9FDoor1
	call_if_unset FLAG_SILPH_9F_DOOR_2, EventScript_Close9FDoor2
	call_if_unset FLAG_SILPH_9F_DOOR_3, EventScript_Close9FDoor3
	call_if_unset FLAG_SILPH_9F_DOOR_4, EventScript_Close9FDoor4
	end

SilphCo_9F_EventScript_HealWoman::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_9F_EventScript_HealWomanRocketsGone
	msgbox SilphCo_9F_Text_YouShouldTakeQuickNap
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox SilphCo_9F_Text_DontGiveUp
	release
	end

SilphCo_9F_EventScript_HealWomanRocketsGone::
	msgbox SilphCo_9F_Text_ThankYouSoMuch
	release
	end

SilphCo_9F_EventScript_FloorSign::
	msgbox SilphCo_9F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_9F_EventScript_Ed::
	trainerbattle_single TRAINER_SCIENTIST_ED, SilphCo_9F_Text_EdIntro, SilphCo_9F_Text_EdDefeat
	msgbox SilphCo_9F_Text_EdPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_9F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_37, SilphCo_9F_Text_Grunt1Intro, SilphCo_9F_Text_Grunt1Defeat
	msgbox SilphCo_9F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_9F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_38, SilphCo_9F_Text_Grunt2Intro, SilphCo_9F_Text_Grunt2Defeat
	msgbox SilphCo_9F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_9F_Text_YouShouldTakeQuickNap::
	.string "Après tant d'efforts, tu\n"
	.string "devrais faire une sieste!$"

SilphCo_9F_Text_DontGiveUp::
	.string "Courage!$"

SilphCo_9F_Text_ThankYouSoMuch::
	.string "Merci mille fois!$"

SilphCo_9F_Text_Grunt1Intro::
	.string "Tes POKéMON ont l'air de t'aimer!$"

SilphCo_9F_Text_Grunt1Defeat::
	.string "Ghaaah!$"

SilphCo_9F_Text_Grunt1PostBattle::
	.string "Si j'avais commencé avec les\n"
	.string "POKéMON à ton âge…$"

SilphCo_9F_Text_EdIntro::
	.string "Tes POKéMON ont des points faibles!\n"
	.string "Ah-ah!$"

SilphCo_9F_Text_EdDefeat::
	.string "Non!\n"
	.string "J'ai perdu!$"

SilphCo_9F_Text_EdPostBattle::
	.string "Jouer sur les points faibles est\n"
	.string "la clé! Pense aux différents types!$"

SilphCo_9F_Text_Grunt2Intro::
	.string "Je suis l'un des 4 FRERES ROCKET!$"

SilphCo_9F_Text_Grunt2Defeat::
	.string "Frères!\n"
	.string "J'suis nul!$"

SilphCo_9F_Text_Grunt2PostBattle::
	.string "Mes frères me vengeront!$"

SilphCo_9F_Text_FloorSign::
	.string "SYLPHE SARL.\n"
	.string "8ème étage.$"


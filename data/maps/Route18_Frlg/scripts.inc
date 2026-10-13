Route18_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route18_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route18_OnWarp
	.byte 0

Route18_OnTransition::
	call_if_eq VAR_MAP_SCENE_ROUTE16, 1, Route18_OnTransitionCyclingRoad
	end

Route18_OnTransitionCyclingRoad::
	setflag FLAG_SYS_ON_CYCLING_ROAD
	return

Route18_OnWarp::
	map_script_2 VAR_MAP_SCENE_ROUTE16, 1, Route18_OnWarpCyclingRoad
	.2byte 0

Route18_OnWarpCyclingRoad::
	special ForcePlayerOntoBike
	end

Route18_EventScript_RouteSign::
	msgbox Route18_Text_RouteSign, MSGBOX_SIGN
	end

Route18_EventScript_CyclingRoadSign::
	msgbox Route18_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route18_Text_WiltonIntro::
	.string "Je fouille les hautes herbes pour\n"
	.string "y trouver des POKéMON.$"

Route18_Text_WiltonDefeat::
	.string "Oh!$"

Route18_Text_WiltonPostBattle::
	.string "Ah, si j'avais un VELO!$"

Route18_Text_RamiroIntro::
	.string "Cui cui cui!\n"
	.string "J'fais l'oiseau, ça ressemble?$"

Route18_Text_RamiroDefeat::
	.string "…\n"
	.string "J'suis cuit!$"

Route18_Text_RamiroPostBattle::
	.string "Le week-end, je collectionne les\n"
	.string "POKéMON EAU!$"

Route18_Text_JacobIntro::
	.string "T'es sur mon gazon, dégage!$"

Route18_Text_JacobDefeat::
	.string "Ah?$"

Route18_Text_JacobPostBattle::
	.string "C'est mon endroit préféré pour\n"
	.string "chasser les POKéMON!$"

Route18_Text_RouteSign::
	.string "ROUTE 18\n"
	.string "CELADOPOLE - PARMANIE$"

Route18_Text_CyclingRoadSign::
	.string "PISTE CYCLABLE\n"
	.string "Interdite aux piétons!$"


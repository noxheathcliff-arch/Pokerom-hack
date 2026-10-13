VictoryRoad_3F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VictoryRoad_3F_OnLoad
	.byte 0

VictoryRoad_3F_OnLoad::
	call_if_ne VAR_MAP_SCENE_VICTORY_ROAD_3F, 100, VictoryRoad_3F_EventScript_SetRockBarrier
	end

VictoryRoad_3F_EventScript_SetRockBarrier::
	setmetatile 12, 12, METATILE_Cave_RockBarrier_Top, 1
	setmetatile 12, 13, METATILE_Cave_RockBarrier_Bottom, 1
	return

VictoryRoad_3F_EventScript_FloorSwitch::
	lockall
	goto_if_eq VAR_MAP_SCENE_VICTORY_ROAD_3F, 100, VictoryRoad_3F_EventScript_FloorSwitchAlreadyPressed
	setmetatile 12, 12, METATILE_Cave_Floor_Ledge_Top, 0
	setmetatile 12, 13, METATILE_Cave_Floor_Ledge_Bottom, 0
	playse SE_ICE_BREAK
	special DrawWholeMapView
	waitse
	copyobjectxytoperm LOCALID_VICTORY_ROAD_3F_BOULDER1
	copyobjectxytoperm LOCALID_VICTORY_ROAD_3F_BOULDER2
	setvar VAR_MAP_SCENE_VICTORY_ROAD_3F, 100
	releaseall
	end

VictoryRoad_3F_EventScript_FloorSwitchAlreadyPressed::
	releaseall
	end

VictoryRoad_3F_EventScript_George::
	trainerbattle_single TRAINER_COOLTRAINER_GEORGE, VictoryRoad_3F_Text_GeorgeIntro, VictoryRoad_3F_Text_GeorgeDefeat
	msgbox VictoryRoad_3F_Text_GeorgePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Colby::
	trainerbattle_single TRAINER_COOLTRAINER_COLBY, VictoryRoad_3F_Text_ColbyIntro, VictoryRoad_3F_Text_ColbyDefeat
	msgbox VictoryRoad_3F_Text_ColbyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Caroline::
	trainerbattle_single TRAINER_COOLTRAINER_CAROLINE, VictoryRoad_3F_Text_CarolineIntro, VictoryRoad_3F_Text_CarolineDefeat
	msgbox VictoryRoad_3F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Alexa::
	trainerbattle_single TRAINER_COOLTRAINER_ALEXA, VictoryRoad_3F_Text_AlexaIntro, VictoryRoad_3F_Text_AlexaDefeat
	msgbox VictoryRoad_3F_Text_AlexaPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Ray::
	trainerbattle_double TRAINER_COOL_COUPLE_RAY_TYRA, VictoryRoad_3F_Text_RayIntro, VictoryRoad_3F_Text_RayDefeat, VictoryRoad_3F_Text_RayNotEnoughMons
	msgbox VictoryRoad_3F_Text_RayPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_3F_EventScript_Tyra::
	trainerbattle_double TRAINER_COOL_COUPLE_RAY_TYRA, VictoryRoad_3F_Text_TyraIntro, VictoryRoad_3F_Text_TyraDefeat, VictoryRoad_3F_Text_TyraNotEnoughMons
	msgbox VictoryRoad_3F_Text_TyraPostBattle, MSGBOX_AUTOCLOSE
	end

Text_DoubleEdgeTeach::
	.string "Je suis impressionné, tu as\n"
	.string "réussi à arriver jusque-là si\l"
	.string "courageusement.\p"
	.string "Pour la peine, je veux bien\n"
	.string "t'apprendre DAMOCLES.\p"
	.string "Veux-tu que j'enseigne cette\n"
	.string "technique à un de tes POKéMON?$"

Text_DoubleEdgeDeclined::
	.string "Très bien. N'hésite pas à revenir\n"
	.string "si tu changes d'avis.$"

Text_DoubleEdgeWhichMon::
	.string "A quel POKéMON enseigner\n"
	.string "DAMOCLES?$"

Text_DoubleEdgeTaught::
	.string "Continue comme ça jusqu'à la\n"
	.string "LIGUE POKéMON!\p"
	.string "Je sais que tu peux tous les\n"
	.string "battre facilement.$"

VictoryRoad_3F_Text_GeorgeIntro::
	.string "J'ai entendu parler de quelqu'un\n"
	.string "de très doué!$"

VictoryRoad_3F_Text_GeorgeDefeat::
	.string "…\n"
	.string "C'était vrai!$"

VictoryRoad_3F_Text_GeorgePostBattle::
	.string "Alors c'était vrai?\p"
	.string "Tu as bien battu GIOVANNI de la\n"
	.string "TEAM ROCKET?$"

VictoryRoad_3F_Text_AlexaIntro::
	.string "Un DRESSEUR est toujours en quête\n"
	.string "d'adversaires plus puissants!$"

VictoryRoad_3F_Text_AlexaDefeat::
	.string "Oh!\n"
	.string "Tu plaisantes pas toi!$"

VictoryRoad_3F_Text_AlexaPostBattle::
	.string "Il faut se battre souvent pour\n"
	.string "progresser.$"

VictoryRoad_3F_Text_CarolineIntro::
	.string "Je vais te montrer ma puissance!$"

VictoryRoad_3F_Text_CarolineDefeat::
	.string "Non!\n"
	.string "Je suis furieuse!$"

VictoryRoad_3F_Text_CarolinePostBattle::
	.string "Ben, j'suis pas si forte que ça!$"

VictoryRoad_3F_Text_ColbyIntro::
	.string "Seuls les élus peuvent passer!$"

VictoryRoad_3F_Text_ColbyDefeat::
	.string "Oh!\n"
	.string "J'y crois pas!$"

VictoryRoad_3F_Text_ColbyPostBattle::
	.string "Ces DRESSEURS sont de la\n"
	.string "LIGUE POKéMON!\p"
	.string "Fais attention!$"

VictoryRoad_3F_Text_RayIntro::
	.string "ROMEO: Nous sommes destinés\n"
	.string "à de grandes choses.$"

VictoryRoad_3F_Text_RayDefeat::
	.string "ROMEO: Ridicule!\n"
	.string "C'est pas possible.$"

VictoryRoad_3F_Text_RayPostBattle::
	.string "ROMEO: Tu nous a battus.\n"
	.string "J'étais pourtant sûr de moi.$"

VictoryRoad_3F_Text_RayNotEnoughMons::
	.string "ROMEO: Tous les deux, nous\n"
	.string "atteindrons les sommets.\p"
	.string "Mais tu dois avoir un deuxième\n"
	.string "POKéMON pour te battre avec nous.$"

VictoryRoad_3F_Text_TyraIntro::
	.string "TYRA: Nous allons devenir champions\n"
	.string "ensemble.$"

VictoryRoad_3F_Text_TyraDefeat::
	.string "TYRA: Oh, mais…$"

VictoryRoad_3F_Text_TyraPostBattle::
	.string "TYRA: Grâce à toi, j'ai enfin\n"
	.string "compris que la puissance seule\l"
	.string "ne suffit pas.$"

VictoryRoad_3F_Text_TyraNotEnoughMons::
	.string "TYRA: Tu ne peux pas te battre\n"
	.string "contre nous avec un seul POKéMON.$"


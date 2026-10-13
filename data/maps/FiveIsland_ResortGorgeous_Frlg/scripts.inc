FiveIsland_ResortGorgeous_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FiveIsland_ResortGorgeous_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FiveIsland_ResortGorgeous_OnFrame
	.byte 0

FiveIsland_ResortGorgeous_OnWarp::
	map_script_2 VAR_MAP_SCENE_FIVE_ISLAND_RESORT_GORGEOUS, 1, FiveIsland_ResortGorgeous_EventScript_TurnPlayerNorth
	.2byte 0

FiveIsland_ResortGorgeous_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

FiveIsland_ResortGorgeous_OnFrame::
	map_script_2 VAR_MAP_SCENE_FIVE_ISLAND_RESORT_GORGEOUS, 1, FiveIsland_ResortGorgeous_EventScript_SelphyReturnHomeScene
	.2byte 0

FiveIsland_ResortGorgeous_EventScript_SelphyReturnHomeScene::
	lockall
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox FiveIsland_ResortGorgeous_Text_SelphyThanksYouMayGoNow
	closemessage
	applymovement LOCALID_RESORT_GORGEOUS_SELPHY, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 39, 8
	waitdooranim
	applymovement LOCALID_RESORT_GORGEOUS_SELPHY, FiveIsland_ResortGorgeous_Movement_SelphyEnterHome
	waitmovement 0
	closedoor 39, 8
	waitdooranim
	removeobject LOCALID_RESORT_GORGEOUS_SELPHY
	clearflag FLAG_HIDE_RESORT_GORGEOUS_INSIDE_SELPHY
	setvar VAR_MAP_SCENE_FIVE_ISLAND_RESORT_GORGEOUS, 2
	releaseall
	end

FiveIsland_ResortGorgeous_Movement_SelphyEnterHome::
	walk_up
	set_invisible
	step_end

FiveIsland_ResortGorgeous_EventScript_SelphysHouseSign::
	msgbox FiveIsland_ResortGorgeous_Text_SelphysHouse, MSGBOX_SIGN
	end

FiveIsland_ResortGorgeous_Text_DaisyIntro::
	.string "Grâce à ces mains d'artiste,\n"
	.string "la victoire sera à moi.$"

FiveIsland_ResortGorgeous_Text_DaisyDefeat::
	.string "C'est pas possible…\n"
	.string "Je suis rouge de honte…$"

FiveIsland_ResortGorgeous_Text_DaisyPostBattle::
	.string "Noooon, mes tubes de peinture\n"
	.string "se sont répandus partout!$"

FiveIsland_ResortGorgeous_Text_CelinaIntro::
	.string "Excuse-moi! Tu ne vois pas que\n"
	.string "j'essaie de peindre, là.$"

FiveIsland_ResortGorgeous_Text_CelinaDefeat::
	.string "C'est complètement loupé!\n"
	.string "J'ai plus qu'à recommencer.$"

FiveIsland_ResortGorgeous_Text_CelinaPostBattle::
	.string "Voilà, regarde un peu par là…\n"
	.string "Parfait, ne bouge plus!$"

FiveIsland_ResortGorgeous_Text_RaynaIntro::
	.string "Hmm…\n"
	.string "La perspective est ratée…$"

FiveIsland_ResortGorgeous_Text_RaynaDefeat::
	.string "Oh, tu m'en as fait voir de toutes\n"
	.string "les couleurs.$"

FiveIsland_ResortGorgeous_Text_RaynaPostBattle::
	.string "Le ciel et la mer. Ils changent\n"
	.string "sans arrêt de couleur.\p"
	.string "Je crois que je vais me mettre à\n"
	.string "la photo, c'est plus simple.$"

FiveIsland_ResortGorgeous_Text_JackiIntro::
	.string "Je suis venue rendre visite à\n"
	.string "un ami, si ça t'intéresse.$"

FiveIsland_ResortGorgeous_Text_JackiDefeat::
	.string "Oh, pas mal.$"

FiveIsland_ResortGorgeous_Text_JackiPostBattle::
	.string "J'adore les combats de POKéMON\n"
	.string "sous une brise légère.$"

FiveIsland_ResortGorgeous_Text_GillianIntro::
	.string "J'aimerais faire construire une\n"
	.string "piscine juste pour mes POKéMON.$"

FiveIsland_ResortGorgeous_Text_GillianDefeat::
	.string "Eh ben mon cochon!$"

FiveIsland_ResortGorgeous_Text_GillianPostBattle::
	.string "Plutôt qu'une piscine, un solarium\n"
	.string "serait formidable.$"

FiveIsland_ResortGorgeous_Text_DestinIntro::
	.string "Je suis un bon sprinter. Personne\n"
	.string "ne peut me rattraper.$"

FiveIsland_ResortGorgeous_Text_DestinDefeat::
	.string "Oups, j'ai dû trop me précipiter.$"

FiveIsland_ResortGorgeous_Text_DestinPostBattle::
	.string "Quand je cours avec le vent, j'ai\n"
	.string "l'impression de voler.$"

FiveIsland_ResortGorgeous_Text_TobyIntro::
	.string "Vivre ici, avec ces embruns,\n"
	.string "me remplit d'énergie.$"

FiveIsland_ResortGorgeous_Text_TobyDefeat::
	.string "Pas sympa ça!$"

FiveIsland_ResortGorgeous_Text_TobyPostBattle::
	.string "Faut pas le prendre comme ça.\n"
	.string "C'est débile!$"

FiveIsland_ResortGorgeous_Text_SelphyThanksYouMayGoNow::
	.string "THEMIS: Merci.\p"
	.string "Tu peux y aller maintenant.$"

FiveIsland_ResortGorgeous_Text_SelphysHouse::
	.string "MAISON DE THEMIS$"


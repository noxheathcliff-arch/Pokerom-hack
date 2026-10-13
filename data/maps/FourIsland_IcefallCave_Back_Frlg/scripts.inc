FourIsland_IcefallCave_Back_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FourIsland_IcefallCave_Back_OnTransition
	.byte 0

FourIsland_IcefallCave_Back_OnTransition::
	call_if_eq VAR_MAP_SCENE_ICEFALL_CAVE_BACK, 1, FourIsland_IcefallCave_Back_EventScript_HideLorelei
	end

FourIsland_IcefallCave_Back_EventScript_HideLorelei::
	setflag FLAG_HIDE_ICEFALL_CAVE_LORELEI
	return

FourIsland_IcefallCave_Back_EventScript_LoreleiRocketsScene::
	lockall
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox FourIsland_IcefallCave_Back_Text_LoreleiKeepHandsOffMons
	applymovement LOCALID_ICEFALL_ROCKET1, FourIsland_IcefallCave_Back_Movement_WalkInPlaceDown
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox FourIsland_IcefallCave_Back_Text_ShutItLadyLeaveUsBe
	closemessage
	playse SE_PIN
	applymovement LOCALID_ICEFALL_LORELEI, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ICEFALL_LORELEI, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_ICEFALL_LORELEI, Common_Movement_Delay48
	waitmovement 0
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox FourIsland_IcefallCave_Back_Text_LoreleiPlayerHelpMeKickPoachersOut
	closemessage
	applymovement LOCALID_ICEFALL_LORELEI, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 18
	applymovement LOCALID_ICEFALL_LORELEI, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 35
	applymovement LOCALID_ICEFALL_ROCKET3, FourIsland_IcefallCave_Back_Movement_Rocket3FaceLorelei
	applymovement LOCALID_ICEFALL_LORELEI, FourIsland_IcefallCave_Back_Movement_LoreleiToRockets
	applymovement LOCALID_PLAYER, FourIsland_IcefallCave_Back_Movement_PlayerToRockets
	waitmovement 0
	applymovement LOCALID_ICEFALL_ROCKET2, FourIsland_IcefallCave_Back_Movement_WalkInPlaceDown
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox FourIsland_IcefallCave_Back_Text_GruntIntro
	setvar VAR_LAST_TALKED, LOCALID_ICEFALL_ROCKET3
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_45, FourIsland_IcefallCave_Back_Text_GruntDefeat
	applymovement LOCALID_ICEFALL_LORELEI, FourIsland_IcefallCave_Back_Movement_WalkInPlaceUp
	waitmovement 0
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox FourIsland_IcefallCave_Back_Text_LoreleiWhereHaveYouTakenMons
	textcolor NPC_TEXT_COLOR_MALE
	msgbox FourIsland_IcefallCave_Back_Text_NotTellingYouThat
	textcolor NPC_TEXT_COLOR_FEMALE
	message FourIsland_IcefallCave_Back_Text_LoreleiWellDeepFreezeYou
	waitmessage
	waitse
	playmoncry SPECIES_LAPRAS, CRY_MODE_ENCOUNTER
	waitbuttonpress
	waitmoncry
	applymovement LOCALID_ICEFALL_ROCKET1, FourIsland_IcefallCave_Back_Movement_Rocket1ReactToThreat
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox FourIsland_IcefallCave_Back_Text_OkayRocketWareHouseFiveIsland
	closemessage
	applymovement LOCALID_ICEFALL_LORELEI, FourIsland_IcefallCave_Back_Movement_LoreleiWatchRocketsExit
	applymovement LOCALID_PLAYER, FourIsland_IcefallCave_Back_Movement_PlayerWatchRocketsExit
	applymovement LOCALID_ICEFALL_ROCKET1, FourIsland_IcefallCave_Back_Movement_Rocket1Exit
	applymovement LOCALID_ICEFALL_ROCKET2, FourIsland_IcefallCave_Back_Movement_Rocket2Exit
	applymovement LOCALID_ICEFALL_ROCKET3, FourIsland_IcefallCave_Back_Movement_Rocket3Exit
	waitmovement 0
	removeobject LOCALID_ICEFALL_ROCKET1
	removeobject LOCALID_ICEFALL_ROCKET2
	removeobject LOCALID_ICEFALL_ROCKET3
	delay 50
	applymovement LOCALID_ICEFALL_LORELEI, FourIsland_IcefallCave_Back_Movement_LoreleiWalkToPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox FourIsland_IcefallCave_Back_Text_ThankYouThisIsAwful
	setflag FLAG_HIDE_RUIN_VALLEY_SCIENTIST
	clearflag FLAG_HIDE_LORELEI_IN_HER_HOUSE
	setvar VAR_MAP_SCENE_ICEFALL_CAVE_BACK, 1
	releaseall
	end

FourIsland_IcefallCave_Back_Movement_PlayerToRockets::
	walk_up
	walk_up
	walk_right
	walk_up
	step_end

FourIsland_IcefallCave_Back_Movement_PlayerWatchRocketsExit::
	delay_16
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

FourIsland_IcefallCave_Back_Movement_WalkInPlaceDown::
	walk_in_place_down
	step_end

FourIsland_IcefallCave_Back_Movement_UnusedPushRight::
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

FourIsland_IcefallCave_Back_Movement_Rocket1ReactToThreat::
	walk_in_place_fast_down
	step_end

FourIsland_IcefallCave_Back_Movement_Rocket1Exit::
	walk_right
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

FourIsland_IcefallCave_Back_Movement_Rocket2Exit::
	delay_16
	walk_left
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

FourIsland_IcefallCave_Back_Movement_Rocket3Exit::
	delay_16
	walk_down
	delay_16
	walk_down
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

FourIsland_IcefallCave_Back_Movement_Rocket3FaceLorelei::
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

FourIsland_IcefallCave_Back_Movement_UnusedWalkLeft::
	walk_left
	walk_left
	step_end

FourIsland_IcefallCave_Back_Movement_LoreleiToRockets::
	walk_left
	walk_up
	step_end

FourIsland_IcefallCave_Back_Movement_WalkInPlaceUp::
	walk_in_place_up
	step_end

FourIsland_IcefallCave_Back_Movement_LoreleiWatchRocketsExit::
	delay_8
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

FourIsland_IcefallCave_Back_Movement_LoreleiWalkToPlayer::
	walk_right
	step_end

FourIsland_IcefallCave_Back_EventScript_Lorelei::
	msgbox FourIsland_IcefallCave_Back_Text_ThankYouThisIsAwful, MSGBOX_NPC
	end

FourIsland_IcefallCave_Back_Text_LoreleiKeepHandsOffMons::
	.string "OLGA: Ne pozez pas vos mains zur\n"
	.string "les POKéMON de zette grotte.\p"
	.string "Faites ze que ze dis, ou vous\n"
	.string "zallez avoir affaire à moi!$"

FourIsland_IcefallCave_Back_Text_ShutItLadyLeaveUsBe::
	.string "Pour qui tu te prends?\p"
	.string "Laisse-nous tranquilles et\n"
	.string "occupe-toi de tes affaires.$"

FourIsland_IcefallCave_Back_Text_LoreleiPlayerHelpMeKickPoachersOut::
	.string "OLGA: {PLAYER}?!\n"
	.string "Qu'est-ze que tu fais là?\p"
	.string "Non, on verra za plus tard.\n"
	.string "J'ai bezoin de toi maintenant.\p"
	.string "Aide-moi à me débarazzer de\n"
	.string "zes voleurs.\p"
	.string "Ils zattrapent les POKéMON\n"
	.string "et les revendent après!\p"
	.string "A mon zignal!\n"
	.string "Tu prends zelui-là, ya?$"

FourIsland_IcefallCave_Back_Text_GruntIntro::
	.string "Qu-Quoi??\p"
	.string "Qui vous êtes pour nous dire ce\n"
	.string "qu'on doit faire avec nos POKéMON?$"

FourIsland_IcefallCave_Back_Text_GruntDefeat::
	.string "On avait pas prévu ça!$"

FourIsland_IcefallCave_Back_Text_LoreleiWhereHaveYouTakenMons::
	.string "OLGA: Humph.\n"
	.string "Espèze de mizérable.\p"
	.string "Toi!\n"
	.string "Dis-moi!\p"
	.string "Où avez-vous zemporté les\n"
	.string "POKéMON capturés?\p"
	.string "Dites-moi tout zou bien…$"

FourIsland_IcefallCave_Back_Text_NotTellingYouThat::
	.string "Ja-jamais!\n"
	.string "Je ne dirai rien!$"

FourIsland_IcefallCave_Back_Text_LoreleiWellDeepFreezeYou::
	.string "OLGA: Zi vous ne parlez pas,\n"
	.string "nous zallons vous congeler.\p"
	.string "Mon LOKHLASS est furieux de\n"
	.string "ze que vous zavez fait.\p"
	.string "Go, LOKHLASS!\n"
	.string "LAZER GLACE…$"

FourIsland_IcefallCave_Back_Text_OkayRocketWareHouseFiveIsland::
	.string "OK, OK, je vais parler!\p"
	.string "Les POKéMON sont dans l'ENTREPOT\n"
	.string "ROCKET sur l'ILE 5.\p"
	.string "Voilà, je l'ai dit!\n"
	.string "Laissez-nous maintenant!\p"
	.string "… Mais je suis sûr que vous\n"
	.string "arriverez jamais à l'ENTREPOT!\p"
	.string "Hehehehehe!$"

FourIsland_IcefallCave_Back_Text_ThankYouThisIsAwful::
	.string "{PLAYER}, merzi beaucoup.\n"
	.string "Mais z'est vraiment affreux…\p"
	.string "Je zuis née et j'ai grandi sur\n"
	.string "zes ILES.\p"
	.string "Je ne me doutais pas que zes\n"
	.string "bandits étaient izi…$"


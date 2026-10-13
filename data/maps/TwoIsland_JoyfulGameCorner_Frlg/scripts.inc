TwoIsland_JoyfulGameCorner_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TwoIsland_JoyfulGameCorner_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, TwoIsland_JoyfulGameCorner_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TwoIsland_JoyfulGameCorner_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad_Frlg
	.byte 0

TwoIsland_JoyfulGameCorner_OnTransition::
	call_if_set FLAG_GOT_MOON_STONE_FROM_JOYFUL_GAME_CORNER, TwoIsland_JoyfulGameCorner_EventScript_SetLostelleReturnedPos
	end

TwoIsland_JoyfulGameCorner_EventScript_SetLostelleReturnedPos::
	setobjectxyperm LOCALID_JOYFUL_GAME_CORNER_DADDY, 6, 2
	setobjectmovementtype LOCALID_JOYFUL_GAME_CORNER_DADDY, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_JOYFUL_GAME_CORNER_LOSTELLE, MOVEMENT_TYPE_LOOK_AROUND
	setvar VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 4
	return

TwoIsland_JoyfulGameCorner_OnWarp::
	map_script_2 VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 2, TwoIsland_JoyfulGameCorner_EventScript_TurnPlayerNorth
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, EventScript_CheckTurnAttendant_Frlg
	.2byte 0

TwoIsland_JoyfulGameCorner_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

TwoIsland_JoyfulGameCorner_OnFrame::
	map_script_2 VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 0, TwoIsland_JoyfulGameCorner_EventScript_HelpFindLostelleScene
	map_script_2 VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 2, TwoIsland_JoyfulGameCorner_EventScript_FoundLostelleScene
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
	.2byte 0

TwoIsland_JoyfulGameCorner_EventScript_FoundLostelleScene::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	msgbox TwoIsland_JoyfulGameCorner_Text_YouRescuedLostelle
	textcolor NPC_TEXT_COLOR_FEMALE
	special GetPlayerBigGuyGirlString
	msgbox TwoIsland_JoyfulGameCorner_Text_LostelleItsOkayDaddy
	closemessage
	applymovement LOCALID_JOYFUL_GAME_CORNER_LOSTELLE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setvar VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 3
	releaseall
	end

TwoIsland_JoyfulGameCorner_EventScript_HelpFindLostelleScene::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_JOYFUL_GAME_CORNER_DADDY, TwoIsland_JoyfulGameCorner_Movement_DaddyPacing
	waitmovement 0
	msgbox TwoIsland_JoyfulGameCorner_Text_WhereHasLostelleGottenTo
	closemessage
	applymovement LOCALID_JOYFUL_GAME_CORNER_DADDY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_JOYFUL_GAME_CORNER_DADDY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_JOYFUL_GAME_CORNER_DADDY, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_JOYFUL_GAME_CORNER_DADDY, TwoIsland_JoyfulGameCorner_Movement_DaddyApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox TwoIsland_JoyfulGameCorner_Text_PleaseHelpFindLostelle
	closemessage
	playse SE_DOOR
	waitse
	applymovement LOCALID_PLAYER, TwoIsland_JoyfulGameCorner_Movement_PlayerFaceDaddy
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_BOY, 0
	addobject LOCALID_JOYFUL_GAME_CORNER_BIKER
	applymovement LOCALID_JOYFUL_GAME_CORNER_BIKER, TwoIsland_JoyfulGameCorner_Movement_BikerLookAround
	waitmovement 0
	msgbox TwoIsland_JoyfulGameCorner_Text_IsThisOnlyThreeIsland
	applymovement LOCALID_JOYFUL_GAME_CORNER_BIKER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox TwoIsland_JoyfulGameCorner_Text_ThisIsTwoIslandMoveIt
	msgbox TwoIsland_JoyfulGameCorner_Text_TheseIslandsAreConfusing
	closemessage
	applymovement LOCALID_JOYFUL_GAME_CORNER_BIKER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_JOYFUL_GAME_CORNER_BIKER
	fadedefaultbgm
	delay 60
	msgbox TwoIsland_JoyfulGameCorner_Text_PunkScuffedUpMyFloor
	clearflag FLAG_HIDE_THREE_ISLAND_LONE_BIKER
	setvar VAR_MAP_SCENE_THREE_ISLAND, 2
	setvar VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 1
	releaseall
	end

TwoIsland_JoyfulGameCorner_Movement_DaddyPacing::
	walk_left
	walk_right
	walk_right
	delay_8
	walk_in_place_faster_up
	delay_16
	step_end

TwoIsland_JoyfulGameCorner_Movement_DaddyApproachPlayer::
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

TwoIsland_JoyfulGameCorner_Movement_PlayerFaceDaddy::
	walk_left
	walk_in_place_faster_right
	step_end

TwoIsland_JoyfulGameCorner_Movement_BikerLookAround::
	walk_in_place_faster_left
	delay_8
	walk_in_place_faster_right
	delay_8
	walk_in_place_faster_up
	step_end

TwoIsland_JoyfulGameCorner_EventScript_InfoMan::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 4, JoyfulGameCorner_EventScript_InfoMan2_Frlg
	goto_if_set FLAG_RESCUED_LOSTELLE, TwoIsland_JoyfulGameCorner_EventScript_GetGamesGoingSoon
	msgbox TwoIsland_JoyfulGameCorner_Text_NotRunningAnyGamesToday
	release
	end

TwoIsland_JoyfulGameCorner_EventScript_GetGamesGoingSoon::
	msgbox TwoIsland_JoyfulGameCorner_Text_GetGamesGoingSoon
	release
	end

@ Only referred to as Lostelles Daddy in text
TwoIsland_JoyfulGameCorner_EventScript_LostellesDaddy::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 4, JoyfulGameCorner_EventScript_MinigameAttendant_Frlg
	goto_if_set FLAG_GOT_MOON_STONE_FROM_JOYFUL_GAME_CORNER, TwoIsland_JoyfulGameCorner_EventScript_GetGameCornerRunning
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 3, TwoIsland_JoyfulGameCorner_EventScript_GiveDaddyMeteorite
	msgbox TwoIsland_JoyfulGameCorner_Text_PleaseGoToThreeIsland
	release
	end

TwoIsland_JoyfulGameCorner_EventScript_GiveDaddyMeteorite::
	goto_if_set FLAG_NO_ROOM_FOR_JOYFUL_GAME_CORNER_MOON_STONE, TwoIsland_JoyfulGameCorner_EventScript_ReceiveMoonStone
	msgbox TwoIsland_JoyfulGameCorner_Text_ThisIsForMe
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 2
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_OBTAIN_TMHM
	message TwoIsland_JoyfulGameCorner_Text_HandedMeteoriteToLostellesDaddy
	waitmessage
	waitfanfare
	call EventScript_RestorePrevTextColor
	removeitem ITEM_METEORITE
	msgbox TwoIsland_JoyfulGameCorner_Text_OhThisIsFromBill
	goto TwoIsland_JoyfulGameCorner_EventScript_ReceiveMoonStone
	end

TwoIsland_JoyfulGameCorner_EventScript_ReceiveMoonStone::
	checkitemspace ITEM_MOON_STONE
	goto_if_eq VAR_RESULT, FALSE, TwoIsland_JoyfulGameCorner_EventScript_NoRoomForMoonStone
	additem ITEM_MOON_STONE
	setflag FLAG_GOT_MOON_STONE_FROM_JOYFUL_GAME_CORNER
	msgreceiveditem TwoIsland_JoyfulGameCorner_Text_ReceivedMoonStoneFromLostellesDaddy, ITEM_MOON_STONE
	release
	end

TwoIsland_JoyfulGameCorner_EventScript_GetGameCornerRunning::
	msgbox TwoIsland_JoyfulGameCorner_Text_IllGetGameCornerRunning
	release
	end

TwoIsland_JoyfulGameCorner_EventScript_NoRoomForMoonStone::
	setflag FLAG_NO_ROOM_FOR_JOYFUL_GAME_CORNER_MOON_STONE
	msgbox TwoIsland_JoyfulGameCorner_Text_NotGoingToFitInBag
	release
	end

TwoIsland_JoyfulGameCorner_EventScript_Lostelle::
	lock
	faceplayer
	msgbox TwoIsland_JoyfulGameCorner_Text_PleaseShowMeYouBeingCool
	release
	end

TwoIsland_JoyfulGameCorner_Text_WhereHasLostelleGottenTo::
	.string "Bon, où est-ce que LOSTELLE\n"
	.string "est encore passée?\p"
	.string "Elle devrait déjà être là\n"
	.string "avec mon repas…$"

TwoIsland_JoyfulGameCorner_Text_PleaseHelpFindLostelle::
	.string "Hm? Bonjour!\n"
	.string "Tu connais LOSTELLE?\p"
	.string "Est-ce que tu l'as vue? Elle\n"
	.string "devrait déjà être là.\p"
	.string "Elle est si mignonne…\n"
	.string "J'espère que…\p"
	.string "J'espère qu'il ne lui est rien\n"
	.string "arrivé… …\p"
	.string "LOSTELLE!\p"
	.string "Je t'en prie, aide-moi à la\n"
	.string "chercher, va voir sur l'ILE 3!$"

TwoIsland_JoyfulGameCorner_Text_IsThisOnlyThreeIsland::
	.string "Hein? C'est quoi cette SALLE DE\n"
	.string "JEU? Ça craint vraiment ici!\p"
	.string "Les imbéciles, ils disaient qu'ils\n"
	.string "m'attendraient sur l'île…\p"
	.string "Et où est-ce qu'ils sont?\p"
	.string "Eh, toi! C'est bien la seule ILE 3\n"
	.string "ici, non?$"

TwoIsland_JoyfulGameCorner_Text_ThisIsTwoIslandMoveIt::
	.string "Ouvre les yeux avant de sortir\n"
	.string "du lit, crétin!\p"
	.string "Tu es sur l'ILE 2!\p"
	.string "Allez, pars d'ici et emmène ta\n"
	.string "fichue moto avec toi!$"

TwoIsland_JoyfulGameCorner_Text_TheseIslandsAreConfusing::
	.string "Hein? …\n"
	.string "Oh, j'ai compris…\p"
	.string "Tss…\n"
	.string "Quelle idée d'appeler ces îles\l"
	.string "comme ça aussi…$"

TwoIsland_JoyfulGameCorner_Text_PunkScuffedUpMyFloor::
	.string "Regarde ça!\n"
	.string "Ce voyou a rayé tout le sol.$"

TwoIsland_JoyfulGameCorner_Text_PleaseGoToThreeIsland::
	.string "Mais écoute, je t'en conjure, tu\n"
	.string "dois aller sur l'ILE 3.\p"
	.string "Si quelque chose devait arriver\n"
	.string "à LOSTELLE…\p"
	.string "J'habite la maison au toit rouge\n"
	.string "sur l'ILE 3.\p"
	.string "Elle est peut-être juste en retard,\n"
	.string "alors je dois encore rester ici.\p"
	.string "C'est pour ça que j'ai besoin que\n"
	.string "tu ailles là-bas.$"

TwoIsland_JoyfulGameCorner_Text_NotRunningAnyGamesToday::
	.string "Désolé. Les jeux ne fonctionnent\n"
	.string "pas aujourd'hui.$"

TwoIsland_JoyfulGameCorner_Text_GetGamesGoingSoon::
	.string "Promis, les jeux fonctionneront\n"
	.string "bientôt pour toi!$"

TwoIsland_JoyfulGameCorner_Text_YouRescuedLostelle::
	.string "Alors c'est vrai, LOSTELLE a été\n"
	.string "sauvée grâce à toi?\p"
	.string "Comment te remercier?\p"
	.string "LOSTELLE ma chérie, pardonne-moi!\p"
	.string "Papa ne savait pas que tu étais\n"
	.string "en danger!$"

TwoIsland_JoyfulGameCorner_Text_LostelleItsOkayDaddy::
	.string "LOSTELLE: Tout va bien, papa!\n"
	.string "Grâce à {PLAYER}!$"

TwoIsland_JoyfulGameCorner_Text_ThisIsForMe::
	.string "Oh, qu'est-ce que c'est?\n"
	.string "Tu dis que c'est pour moi?\p"
	.string "Comment sais-tu que j'aime\n"
	.string "les pierres rares?\p"
	.string "On peut dire que tu sais comment\n"
	.string "rendre les gens heureux!$"

TwoIsland_JoyfulGameCorner_Text_HandedMeteoriteToLostellesDaddy::
	.string "{PLAYER} tend le METEORITE au père\n"
	.string "de LOSTELLE.$"

TwoIsland_JoyfulGameCorner_Text_OhThisIsFromBill::
	.string "Oh, je vois, ça vient de LEO!\n"
	.string "Remercie-le de ma part!\p"
	.string "Au fait, j'ai moi aussi quelque\n"
	.string "chose pour toi, pour te remercier.$"

TwoIsland_JoyfulGameCorner_Text_ReceivedMoonStoneFromLostellesDaddy::
	.string "{PLAYER} reçoit la PIERRE LUNE\n"
	.string "du père de LOSTELLE.$"

TwoIsland_JoyfulGameCorner_Text_NotGoingToFitInBag::
	.string "Il n'y a plus de place dans\n"
	.string "ton sac.$"

TwoIsland_JoyfulGameCorner_Text_IllGetGameCornerRunning::
	.string "Très bien, je vais ouvrir la SALLE\n"
	.string "DE JEU tout de suite.\p"
	.string "Viens me voir avec des amis.$"

TwoIsland_JoyfulGameCorner_Text_PleaseShowMeYouBeingCool::
	.string "J'suis sûre qu'on se reverra!$"


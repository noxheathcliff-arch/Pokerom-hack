FourIsland_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FourIsland_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FourIsland_OnFrame
	.byte 0

FourIsland_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_FOUR_ISLAND
	call_if_eq VAR_MAP_SCENE_FOUR_ISLAND, 0, FourIsland_EventScript_ShowRival
	call FourIsland_EventScript_TrySetDayCareManPos
	end

FourIsland_EventScript_ShowRival::
	clearflag FLAG_HIDE_FOUR_ISLAND_RIVAL
	return

FourIsland_EventScript_TrySetDayCareManPos::
	goto_if_unset FLAG_PENDING_DAYCARE_EGG, FourIsland_EventScript_EndSetDayCareManPos
	setobjectxyperm LOCALID_FOUR_ISLAND_DAYCARE_MAN, 16, 14
FourIsland_EventScript_EndSetDayCareManPos::
	return

FourIsland_OnFrame::
	map_script_2 VAR_MAP_SCENE_FOUR_ISLAND, 0, FourIsland_EventScript_RivalScene
	.2byte 0

FourIsland_EventScript_RivalScene::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_FOUR_ISLAND_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	applymovement LOCALID_FOUR_ISLAND_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FOUR_ISLAND_RIVAL, Common_Movement_Delay48
	waitmovement 0
	delay 25
	applymovement LOCALID_FOUR_ISLAND_RIVAL, FourIsland_Movement_RivalApproach
	waitmovement 0
	msgbox FourIsland_Text_RivalAlreadyGotEggBeSmellingYa
	closemessage
	applymovement LOCALID_PLAYER, FourIsland_Movement_PlayerWatchRivalExit
	applymovement LOCALID_FOUR_ISLAND_RIVAL, FourIsland_Movement_RivalExit
	waitmovement 0
	fadedefaultbgm
	playse SE_EXIT
	delay 35
	removeobject LOCALID_FOUR_ISLAND_RIVAL
	setvar VAR_MAP_SCENE_FOUR_ISLAND, 1
	releaseall
	end

FourIsland_Movement_RivalApproach::
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

FourIsland_Movement_RivalExit::
	delay_16
	delay_4
	walk_down
	step_end

FourIsland_Movement_PlayerWatchRivalExit::
	walk_left
	walk_in_place_faster_right
	step_end

FourIsland_EventScript_DaycareMan::
	lock
	faceplayer
	special GetDaycareMonNicknames
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, FourIsland_EventScript_DaycareEggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, FourIsland_EventScript_CheckOnOneMon
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, FourIsland_EventScript_CheckOnTwoMons
	msgbox DayCare_Text_ImDaycareManSpeakToMyWife
	release
	end

FourIsland_EventScript_DaycareEggWaiting::
	msgbox DayCare_Text_DoYouWantEgg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FourIsland_EventScript_DaycareAcceptEgg
	msgbox DayCare_Text_IWillKeepDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FourIsland_EventScript_DaycareAcceptEgg
	msgbox DayCare_Text_IllKeepIt
	clearflag FLAG_PENDING_DAYCARE_EGG
	special RejectEggFromDayCare
	release
	end

FourIsland_EventScript_DaycareAcceptEgg::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_ne VAR_RESULT, PARTY_SIZE, FourIsland_EventScript_DaycareReceivedEgg
	msgbox DayCare_Text_YouHaveNoRoomForIt
	release
	end

FourIsland_EventScript_DaycareReceivedEgg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	message DayCare_Text_ReceivedEgg
	call EventScript_RestorePrevTextColor
	playfanfare MUS_LEVEL_UP
	waitfanfare
	waitbuttonpress
	msgbox DayCare_Text_TakeGoodCareOfIt
	special GiveEggFromDaycare
	clearflag FLAG_PENDING_DAYCARE_EGG
	release
	end

FourIsland_EventScript_CheckOnOneMon::
	special GetDaycareMonNicknames
	msgbox DayCare_Text_YourMonIsDoingFine
	release
	end

FourIsland_EventScript_CheckOnTwoMons::
	special GetDaycareMonNicknames
	msgbox DayCare_Text_YourMonsAreDoingFine
	special SetDaycareCompatibilityString
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	release
	end

FourIsland_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_IS_CHAMPION, FourIsland_EventScript_OldWomanLoreleiLeft
	msgbox FourIsland_Text_LoreleiHasReturned
	release
	end

FourIsland_EventScript_OldWomanLoreleiLeft::
	famechecker FAMECHECKER_LORELEI, 5
	msgbox FourIsland_Text_LoreleiMetLaprasAsChild
	release
	end

FourIsland_EventScript_LittleGirl::
	lock
	faceplayer
	famechecker FAMECHECKER_LORELEI, 4
	msgbox FourIsland_Text_LoreleiHasLotsOfStuffedDolls
	release
	end

FourIsland_EventScript_FatMan::
	msgbox FourIsland_Text_MadeSlushieUsingIcefallCaveIce, MSGBOX_NPC
	end

FourIsland_EventScript_IslandSign::
	msgbox FourIsland_Text_IslandSign, MSGBOX_SIGN
	end

FourIsland_EventScript_LoreleisHouseSign::
	msgbox FourIsland_Text_LoreleisHouse, MSGBOX_SIGN
	end

FourIsland_Text_IslandSign::
	.string "ILE 4\n"
	.string "La chaleureuse île glacée$"

FourIsland_Text_LoreleiHasReturned::
	.string "OLGA est de retour.\p"
	.string "Elle a dû trouver la vie en ville\n"
	.string "trop stressante.$"

FourIsland_Text_LoreleiMetLaprasAsChild::
	.string "OLGA est revenue.\p"
	.string "Son LOKHLASS, ça doit être\n"
	.string "celui qu'elle a depuis son enfance.\p"
	.string "Je crois qu'elle l'avait attrapé\n"
	.string "dans la GROTTE DE GLACE.\p"
	.string "Ce POKéMON a dû passer des\n"
	.string "années avec elle.$"

FourIsland_Text_RivalAlreadyGotEggBeSmellingYa::
	.string "{RIVAL}: Hey!\n"
	.string "{PLAYER}!\p"
	.string "Qu'est-ce que tu fais aux\n"
	.string "ILES SEVII?\p"
	.string "Tu devrais arrêter de me suivre,\n"
	.string "tu crois pas?\p"
	.string "De toute façon, j'ai plus rien à\n"
	.string "faire ici, depuis que\p"
	.string "j'ai reçu mon OEUF POKéMON.\p"
	.string "Pff, je suis sûr que tu sais\n"
	.string "rien sur les OEUFS POKéMON.\p"
	.string "C'est pas comme ça que tu vas\n"
	.string "remplir ton POKéDEX NATIONAL.\p"
	.string "Au fait, j'ai ramené une vieille\n"
	.string "connaissance avec moi.\p"
	.string "Va chercher un peu si tu veux\n"
	.string "savoir qui c'est.\p"
	.string "Moi, j'ai pas de temps à perdre\n"
	.string "avec toi.\p"
	.string "Allez, tchao!$"

FourIsland_Text_LoreleiHasLotsOfStuffedDolls::
	.string "Oh, tu m'as trouvée!\n"
	.string "Mais ne dis rien à OLGA!\p"
	.string "Tu savais qu'elle a une collection\n"
	.string "de poupées?\p"
	.string "Sa collection grandit à chaque fois\n"
	.string "qu'elle revient sur l'ILE 4.$"

FourIsland_Text_MadeSlushieUsingIcefallCaveIce::
	.string "Oooh, c'est frais!\p"
	.string "J'me suis fait un cornet avec ce\n"
	.string "que j'ai ramassé dans la GROTTE\l"
	.string "DE GLACE.$"

FourIsland_Text_LoreleisHouse::
	.string "MAISON D'OLGA$"


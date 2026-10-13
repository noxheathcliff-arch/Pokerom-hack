TrainerTower_Lobby_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, TrainerTower_Lobby_OnResume
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, TrainerTower_Lobby_OnReturnToField
	map_script MAP_SCRIPT_ON_TRANSITION, TrainerTower_Lobby_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, TrainerTower_Lobby_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerTower_Lobby_OnFrame
	.byte 0

TrainerTower_Lobby_OnResume::
	setvar VAR_TEMP_2, 0
	ttower_resumetimer
	ttower_shouldexit
	goto_if_eq VAR_RESULT, FALSE, TrainerTower_Lobby_OnResumeEnd
	@ Never reached, above always FALSE
	setvar VAR_TEMP_0, 0
	setobjectxy LOCALID_PLAYER, 9, 7
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_FaceReceptionist
TrainerTower_Lobby_OnResumeEnd::
	end

TrainerTower_Lobby_OnReturnToField::
	addobject LOCALID_TOWER_NURSE
	addobject LOCALID_TOWER_MART_CLERK
	addobject LOCALID_TOWER_RECEPTIONIST
	addobject LOCALID_TOWER_COOLTRAINER_F
	addobject LOCALID_TOWER_BALDING_MAN
	end

TrainerTower_Lobby_OnLoad::
	call_if_eq VAR_TEMP_D, 17, TrainerTower_Lobby_OpenCounterBarrier
	end

TrainerTower_Lobby_OpenCounterBarrier::
	setmetatile 17, 10, METATILE_TrainerTower_Floor_ShadeBottomLeft, 0
	return

TrainerTower_Lobby_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_TRAINER_TOWER_LOBBY
	getplayerxy VAR_TEMP_D, VAR_RESULT
	end

TrainerTower_Lobby_OnFrame::
	map_script_2 VAR_TEMP_0, 0, TrainerTower_Lobby_EventScript_Enter
	map_script_2 VAR_TEMP_D, 17, TrainerTower_Lobby_EventScript_ExitElevator
	.2byte 0

TrainerTower_Lobby_EventScript_ExitElevator::
	lockall
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_ExitElevator
	waitmovement 0
	setmetatile 17, 10, METATILE_TrainerTower_CounterBarrier, 1
	special DrawWholeMapView
	playse SE_CLICK
	waitse
	setvar VAR_TEMP_D, 0
	releaseall
	end

TrainerTower_Lobby_Movement_ExitElevator::
	walk_down
	walk_down
	step_end

TrainerTower_Lobby_EventScript_Enter::
	setvar VAR_TEMP_0, 1
	ttower_getchallengestatus
	switch VAR_RESULT
	case TT_CHALLENGE_STATUS_LOST, TrainerTower_Lobby_EventScript_LostChallenge
	case TT_CHALLENGE_STATUS_UNK, TrainerTower_Lobby_EventScript_ExitChallengeSpeakToReceptionist
	case TT_CHALLENGE_STATUS_NORMAL, TrainerTower_Lobby_EventScript_EnterEnd

TrainerTower_Lobby_EventScript_LostChallenge::
	lock
	faceplayer
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_FaceReceptionist
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox TrainerTower_Lobby_Text_TooBadComeBackTryAgain
	goto TrainerTower_Lobby_EventScript_ExitChallenge

@ Presumably E-Reader related
TrainerTower_Lobby_EventScript_ExitChallengeSpeakToReceptionist::
	lock
	faceplayer
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_FaceReceptionist
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox TrainerTower_Lobby_Text_MoveCounterHereWhenTrainersSwitch
TrainerTower_Lobby_EventScript_ExitChallenge::
	closemessage
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_WalkDown
	waitmovement 0
	setvar VAR_MAP_SCENE_TRAINER_TOWER, 0
	release
TrainerTower_Lobby_EventScript_EnterEnd::
	end

TrainerTower_Lobby_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

TrainerTower_Lobby_EventScript_Receptionist::
	lock
	faceplayer
	ttower_getbeatchallenge
	goto_if_eq VAR_RESULT, TRUE, TrainerTower_Lobby_EventScript_ThanksForCompeting
	msgbox TrainerTower_Lobby_Text_GiveItYourBest
	goto TrainerTower_Lobby_EventScript_ReceptionistEnd

TrainerTower_Lobby_EventScript_ThanksForCompeting::
	msgbox TrainerTower_Lobby_Text_ThanksForCompeting
TrainerTower_Lobby_EventScript_ReceptionistEnd::
	release
	end

TrainerTower_Lobby_EventScript_MartClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart TrainerTower_Lobby_Mart_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
TrainerTower_Lobby_Mart_Items::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

TrainerTower_Lobby_EventScript_EntryTrigger::
	lockall
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_FaceReceptionist
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox TrainerTower_Lobby_Text_WelcomeToTrainerTower
	ttower_getnumfloors
	goto_if_eq VAR_RESULT, FALSE, TrainerTower_Lobby_EventScript_AllFloorsUsed
	msgbox TrainerTower_Lobby_Text_TrainersUpToFloorNum
	goto TrainerTower_Lobby_EventScript_AskEnterChallenge

TrainerTower_Lobby_EventScript_AllFloorsUsed::
	msgbox TrainerTower_Lobby_Text_TrainersUpEighthFloor
TrainerTower_Lobby_EventScript_AskEnterChallenge::
	message TrainerTower_Lobby_Text_LikeToChallengeTrainers
	waitmessage
	multichoice 18, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, TrainerTower_Lobby_EventScript_ChooseChallenge
	case 1, TrainerTower_Lobby_EventScript_DeclineChallenge
	case 2, TrainerTower_Lobby_EventScript_ChallengeInfo
	case MULTI_B_PRESSED, TrainerTower_Lobby_EventScript_DeclineChallenge
	end

TrainerTower_Lobby_EventScript_ChallengeInfo::
	msgbox TrainerTower_Lobby_Text_ExplainTrainerTower
	goto TrainerTower_Lobby_EventScript_AskEnterChallenge
	end

TrainerTower_Lobby_EventScript_ChooseChallenge::
	multichoice 13, 3, MULTI_TRAINER_TOWER_MODE, FALSE
	switch VAR_RESULT
	case 0, TrainerTower_Lobby_EventScript_BeginChallenge
	case 1, TrainerTower_Lobby_EventScript_BeginChallenge
	case 2, TrainerTower_Lobby_EventScript_BeginChallenge
	case 3, TrainerTower_Lobby_EventScript_BeginChallenge
	case 4, TrainerTower_Lobby_EventScript_DeclineChallenge
	case MULTI_B_PRESSED, TrainerTower_Lobby_EventScript_DeclineChallenge
	end

TrainerTower_Lobby_EventScript_BeginChallenge::
	copyvar VAR_0x8005, VAR_RESULT
	setvar VAR_MAP_SCENE_TRAINER_TOWER, 1
	special HealPlayerParty
	msgbox TrainerTower_Lobby_Text_StartClockGetSetGo
	ttower_startchallenge
	releaseall
	end

TrainerTower_Lobby_EventScript_DeclineChallenge::
	msgbox TrainerTower_Lobby_Text_PleaseVisitUsAgain
	closemessage
	applymovement LOCALID_PLAYER, TrainerTower_Lobby_Movement_WalkDown
	waitmovement 0
	releaseall
	end

TrainerTower_Lobby_Movement_FaceReceptionist::
	face_right
	step_end

TrainerTower_Lobby_Movement_WalkDown::
	walk_down
	step_end

TrainerTower_Lobby_EventScript_ShowRecords::
	lockall
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, 1
	special ShowTrainerHillRecords
	releaseall
	end

TrainerTower_Lobby_EventScript_CooltrainerF::
	msgbox TrainerTower_Lobby_Text_WonderWhatKindsOfTrainers, MSGBOX_NPC
	end

TrainerTower_Lobby_EventScript_BaldingMan::
	msgbox TrainerTower_Lobby_Text_StairsTougherThanAnyBattle, MSGBOX_NPC
	end

@ All Trainer Tower text (Lobby and Roof) is interleaved here

TrainerTower_Lobby_Text_WelcomeToTrainerTower::
	.string "Bonjour.\p"
	.string "Bienvenue à la TOUR DRESSEURS\p"
	.string "où les DRESSEURS viennent\n"
	.string "du monde entier.$"

TrainerTower_Lobby_Text_TrainersUpToFloorNum::
	.string "Les DRESSEURS du monde entier\n"
	.string "viennent ici pour combattre.\p"
	.string "Un instant…\p"
	.string "En ce moment, il n'y a\n"
	.string "des DRESSEURS que\p"
	.string "jusqu'au niveau {STR_VAR_1}.$"

TrainerTower_Lobby_Text_TrainersUpEighthFloor::
	.string "Les DRESSEURS attendent pour vous\n"
	.string "défier jusqu'au 8ème niveau.$"

TrainerTower_Lobby_Text_LikeToChallengeTrainers::
	.string "Voulez-vous affronter les\n"
	.string "DRESSEURS qui patientent?$"

TrainerTower_Lobby_Text_StartClockGetSetGo::
	.string "OK, je compte sur vous pour\n"
	.string "avoir un beau spectacle.\p"
	.string "Je mets le chrono en marche.\p"
	.string "A vos marques…\p"
	.string "Prêts…\p"
	.string "Partez!$"

TrainerTower_Lobby_Text_PleaseVisitUsAgain::
	.string "Revenez nous voir.$"

TrainerTower_Lobby_Text_TooBadComeBackTryAgain::
	.string "Quel dommage.\p"
	.string "Vous avez pourtant fait de\n"
	.string "votre mieux.\p"
	.string "Mais n'hésitez pas à revenir\n"
	.string "nous voir.$"

TrainerTower_Lobby_Text_GiveItYourBest::
	.string "Vous avez fait de votre mieux.$"

TrainerTower_Lobby_Text_MoveCounterHereWhenTrainersSwitch::
	.string "Ça peut être assez mouvementé\n"
	.string "quand les DRESSEURS changent\p"
	.string "de place. C'est pour ça qu'on est\n"
	.string "installés ici.\p"
	.string "Désolé pour ça.$"

TrainerTower_Roof_Text_ImOwnerBattledPerfectly::
	.string "Bonjour…\p"
	.string "Je suis le propriétaire de cette\n"
	.string "TOUR.\p"
	.string "La vue qu'on a depuis le toit\n"
	.string "frise la perfection…\p"
	.string "Ta façon de combattre aussi,\n"
	.string "c'était formidable…$"

TrainerTower_Roof_Text_ThisIsForYou::
	.string "C'est pour toi…$"

TrainerTower_Roof_Text_DoneItInRecordTime::
	.string "Oh!\n"
	.string "Incroyable!\p"
	.string "C'est incroyable de te voir arriver\n"
	.string "ici aussi vite!\p"
	.string "C'est même un temps record…\p"
	.string "Je vais l'afficher à la réception.$"

TrainerTower_Roof_Text_TookSweetTimeGettingHere::
	.string "On dirait que tu as pris ton\n"
	.string "temps pour venir…$"

TrainerTower_Roof_Text_IdLikeToSeeBetterTime::
	.string "Je sais que tu peux faire un\n"
	.string "meilleur temps…\p"
	.string "Je compte sur toi.\p"
	.string "A la prochaine alors…$"

TrainerTower_Text_XMinYZSec::
	.string "{STR_VAR_1} min. {STR_VAR_2},{STR_VAR_3} sec.$"

TrainerTower_Lobby_Text_HereAreTheResults::
	.string "せいせきひょうです$"

TrainerTower_Lobby_Text_NeedTwoMonsForDouble::
	.string "C'est un combat deux contre deux.\p"
	.string "Vous ne pouvez pas combattre\n"
	.string "avec un seul POKéMON.$"

TrainerTower_Lobby_Text_ExplainTrainerTower::
	.string "A la TOUR DRESSEURS, il y a\n"
	.string "une épreuve de CONTRE-LA-MONTRE.\p"
	.string "Le chronomètre partira à partir\n"
	.string "d'ici et jusqu'au PROPRIETAIRE qui\p"
	.string "se trouve sur le toit. Les\n"
	.string "meilleurs temps sont affichés ici.\p"
	.string "Essayez d'affronter des amis pour\n"
	.string "voir qui est le plus rapide.\p"
	.string "Vous ne gagnerez pas de points\n"
	.string "EXP. ni d'argent en battant\p"
	.string "ces DRESSEURS.$"

TrainerTower_Lobby_Text_ThanksForCompeting::
	.string "Merci de participer!$"

TrainerTower_Lobby_Text_WonderWhatKindsOfTrainers::
	.string "Je suis ici pour voir à quel point\n"
	.string "je suis douée.\p"
	.string "Je me demande quel type de\n"
	.string "DRESSEUR peut bien m'attendre.\p"
	.string "C'est stressant.$"

TrainerTower_Lobby_Text_StairsTougherThanAnyBattle::
	.string "… … …\p"
	.string "Ces escaliers… …\p"
	.string "Je suis épuisé avant d'avoir\n"
	.string "combattu…$"


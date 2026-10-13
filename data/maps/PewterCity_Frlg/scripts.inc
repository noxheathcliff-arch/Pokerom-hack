PewterCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_OnTransition
	.byte 0

PewterCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_PEWTER_CITY
	setvar VAR_MAP_SCENE_PEWTER_CITY_MUSEUM_1F, 0
	end

@ Impossible to speak to this NPC from a facing dir != DIR_EAST normally, so they arent checked
@ Additionally, no movement script exists for facing DIR_SOUTH, which would necessitate walking out of bounds
PewterCity_EventScript_GymGuide::
	lock
	faceplayer
	msgbox PewterCity_Text_BrocksLookingForChallengersFollowMe
	closemessage
	playbgm MUS_FOLLOW_ME, 0
	call_if_eq VAR_FACING, DIR_EAST, PewterCity_EventScript_WalkToGymEast
	msgbox PewterCity_Text_GoTakeOnBrock
	closemessage
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GymGuideExit
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_PEWTER_GYM_GUIDE
	clearflag FLAG_HIDE_PEWTER_CITY_GYM_GUIDE
	release
	end

PewterCity_EventScript_WalkToGymEast::
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWaitForGuideEast
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadEast
	waitmovement 0
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymEast
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymEast
	waitmovement 0
	return

@ Unused
PewterCity_EventScript_WalkToGymWest::
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWaitForGuideWest
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadWest
	waitmovement 0
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymWest
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymWest
	waitmovement 0
	return

@ Unused
PewterCity_EventScript_WalkToGymNorth::
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWaitForGuideNorth
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadNorth
	waitmovement 0
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymNorth
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymNorth
	waitmovement 0
	return

.macro walk_to_gym
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
.endm

.macro walk_to_gym_alt
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
.endm

PewterCity_Movement_PlayerWaitForGuideEast::
	delay_16
	delay_16
	delay_4
	walk_in_place_faster_down
	step_end

PewterCity_Movement_PlayerWalkToGymEast::
	walk_down
	walk_to_gym
	step_end

PewterCity_Movement_PlayerWaitForGuideWest::
	delay_16
	step_end

PewterCity_Movement_PlayerWalkToGymWest::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_to_gym_alt
	step_end

PewterCity_Movement_PlayerWaitForGuideNorth::
	delay_16
	step_end

PewterCity_Movement_PlayerWalkToGymNorth::
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_to_gym_alt
	step_end

PewterCity_Movement_GuideMoveToLeadEast::
	walk_down
	walk_left
	walk_in_place_faster_up
	walk_in_place_up
	step_end

PewterCity_Movement_GuideWalkToGymEast::
	walk_to_gym
	walk_right
	walk_in_place_faster_left
	step_end

PewterCity_Movement_GuideMoveToLeadWest::
	walk_in_place_right
	step_end

PewterCity_Movement_GuideWalkToGymWest::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_to_gym_alt
	walk_right
	walk_in_place_faster_left
	step_end

PewterCity_Movement_GuideMoveToLeadNorth::
	walk_in_place_down
	step_end

PewterCity_Movement_GuideWalkToGymNorth::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_to_gym_alt
	walk_right
	walk_in_place_faster_left
	step_end

PewterCity_Movement_GymGuideExit::
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PewterCity_EventScript_GymGuideTriggerTop::
	lockall
	setvar VAR_TEMP_1, 0
	goto PewterCity_EventScript_GymGuideTrigger
	end

PewterCity_EventScript_GymGuideTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	goto PewterCity_EventScript_GymGuideTrigger
	end

PewterCity_EventScript_GymGuideTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 2
	goto PewterCity_EventScript_GymGuideTrigger
	end

@ This trigger is inaccessible and its corresponding movement script isnt linked
PewterCity_EventScript_GymGuideTriggerRight::
	lockall
	setvar VAR_TEMP_1, 3
	goto PewterCity_EventScript_GymGuideTrigger
	end

PewterCity_EventScript_GymGuideTrigger::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox PewterCity_Text_BrocksLookingForChallengersFollowMe
	closemessage
	playbgm MUS_FOLLOW_ME, 0
	call_if_eq VAR_TEMP_1, 0, PewterCity_EventScript_WalkToGymTop
	call_if_eq VAR_TEMP_1, 1, PewterCity_EventScript_WalkToGymMid
	call_if_eq VAR_TEMP_1, 2, PewterCity_EventScript_WalkToGymBottom
	msgbox PewterCity_Text_GoTakeOnBrock
	closemessage
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GymGuideExit
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_PEWTER_GYM_GUIDE
	clearflag FLAG_HIDE_PEWTER_CITY_GYM_GUIDE
	releaseall
	end

PewterCity_EventScript_WalkToGymTop::
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadTop
	waitmovement 0
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymTop
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymTop
	waitmovement 0
	return

PewterCity_EventScript_WalkToGymMid::
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadMid
	waitmovement 0
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymMid
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymMid
	waitmovement 0
	return

PewterCity_EventScript_WalkToGymBottom::
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadBottom
	waitmovement 0
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymBottom
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymBottom
	waitmovement 0
	return

@ Unused
PewterCity_EventScript_WalkToGymRight::
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideApproachPlayerRight
	waitmovement 0
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymRight
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymRight
	waitmovement 0
	return

PewterCity_Movement_PlayerWalkToGymTop::
	walk_left
	walk_to_gym
	step_end

PewterCity_Movement_PlayerWalkToGymMid::
	walk_up
	walk_left
	walk_to_gym
	step_end

PewterCity_Movement_PlayerWalkToGymBottom::
	walk_up
	walk_up
	walk_left
	walk_to_gym
	step_end

PewterCity_Movement_PlayerWalkToGymRight::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_to_gym_alt
	step_end

PewterCity_Movement_GuideMoveToLeadTop::
	walk_left
	walk_down
	walk_in_place_faster_right
	walk_in_place_right
	step_end

PewterCity_Movement_GuideMoveToLeadMid::
	walk_down
	walk_in_place_down
	step_end

PewterCity_Movement_GuideMoveToLeadBottom::
	walk_down
	walk_down
	walk_in_place_down
	step_end

PewterCity_Movement_GuideApproachPlayerRight::
	walk_down
	walk_down
	walk_right
	walk_down
	walk_right
	walk_in_place_right
	step_end

PewterCity_Movement_GuideWalkToGymTop::
	walk_to_gym
	walk_right
	walk_in_place_faster_left
	step_end

PewterCity_Movement_GuideWalkToGymMid::
	walk_left
	walk_to_gym
	walk_right
	walk_in_place_faster_left
	step_end

PewterCity_Movement_GuideWalkToGymBottom::
	walk_up
	walk_left
	walk_to_gym
	walk_right
	walk_in_place_faster_left
	step_end

PewterCity_Movement_GuideWalkToGymRight::
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_to_gym_alt
	walk_right
	walk_in_place_faster_left
	step_end

PewterCity_EventScript_Lass::
	msgbox PewterCity_Text_ClefairyCameFromMoon, MSGBOX_NPC
	end

PewterCity_EventScript_MuseumGuide::
	lock
	faceplayer
	msgbox PewterCity_Text_DidYouCheckOutMuseum, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_EventScript_CheckedOutMuseum
	msgbox PewterCity_Text_ReallyYouHaveToGo
	closemessage
	delay 10
	playbgm MUS_FOLLOW_ME, 0
	call_if_eq VAR_FACING, DIR_NORTH, PewterCity_EventScript_LeadToMuseumNorth
	call_if_eq VAR_FACING, DIR_SOUTH, PewterCity_EventScript_LeadToMuseumSouth
	call_if_eq VAR_FACING, DIR_WEST, PewterCity_EventScript_LeadToMuseumWest
	call_if_eq VAR_FACING, DIR_EAST, PewterCity_EventScript_LeadToMuseumEast
	msgbox PewterCity_Text_ThisIsTheMuseum
	closemessage
	delay 10
	applymovement LOCALID_PEWTER_MUSEUM_GUIDE, PewterCity_Movement_MuseumGuideExit
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_PEWTER_MUSEUM_GUIDE
	clearflag FLAG_HIDE_PEWTER_MUSEUM_GUIDE
	release
	end

PewterCity_EventScript_LeadToMuseumNorth::
	applymovement LOCALID_PEWTER_MUSEUM_GUIDE, PewterCity_Movement_GuideWalkToMuseumNorth
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToMuseumNorth
	waitmovement 0
	return

PewterCity_EventScript_LeadToMuseumSouth::
	applymovement LOCALID_PEWTER_MUSEUM_GUIDE, PewterCity_Movement_GuideWalkToMuseumSouth
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToMuseumSouth
	waitmovement 0
	return

PewterCity_EventScript_LeadToMuseumWest::
	applymovement LOCALID_PEWTER_MUSEUM_GUIDE, PewterCity_Movement_GuideWalkToMuseumWest
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToMuseumWest
	waitmovement 0
	return

PewterCity_EventScript_LeadToMuseumEast::
	applymovement LOCALID_PEWTER_MUSEUM_GUIDE, PewterCity_Movement_GuideWalkToMuseumEast
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToMuseumEast
	waitmovement 0
	return

PewterCity_EventScript_CheckedOutMuseum::
	msgbox PewterCity_Text_WerentThoseFossilsAmazing
	release
	end

.macro walk_to_museum
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
.endm

.macro walk_to_museum_south
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
.endm

PewterCity_Movement_PlayerWalkToMuseumNorth::
	walk_up
	walk_to_museum
	delay_8
	walk_in_place_faster_up
	step_end

PewterCity_Movement_GuideWalkToMuseumNorth::
	walk_to_museum
	walk_left
	walk_in_place_faster_up
	step_end

PewterCity_Movement_PlayerWalkToMuseumSouth::
	delay_16
	delay_16
	walk_left
	walk_to_museum_south
	delay_8
	walk_in_place_faster_up
	step_end

PewterCity_Movement_GuideWalkToMuseumSouth::
	walk_left
	walk_up
	walk_to_museum_south
	walk_left
	walk_in_place_faster_up
	step_end

PewterCity_Movement_PlayerWalkToMuseumWest::
	walk_left
	walk_to_museum
	delay_8
	walk_in_place_faster_up
	step_end

PewterCity_Movement_GuideWalkToMuseumWest::
	walk_to_museum
	walk_left
	walk_in_place_faster_up
	step_end

PewterCity_Movement_PlayerWalkToMuseumEast::
	walk_right
	walk_to_museum
	delay_8
	walk_in_place_faster_up
	step_end

PewterCity_Movement_GuideWalkToMuseumEast::
	walk_to_museum
	walk_left
	walk_in_place_faster_up
	step_end

PewterCity_Movement_MuseumGuideExit::
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

PewterCity_EventScript_FatMan::
	lock
	faceplayer
	famechecker FAMECHECKER_BROCK, 2
	msgbox PewterCity_Text_BrockOnlySeriousTrainerHere
	release
	end

PewterCity_EventScript_BugCatcher::
	lock
	faceplayer
	msgbox PewterCity_Text_DoYouKnowWhatImDoing, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_EventScript_KnowWhatTheyreDoing
	msgbox PewterCity_Text_SprayingRepelToKeepWildMonsOut
	release
	end

PewterCity_EventScript_KnowWhatTheyreDoing::
	msgbox PewterCity_Text_ThatsRightItsHardWork
	release
	end

PewterCity_EventScript_TrainerTips::
	msgbox PewterCity_Text_TrainerTipsEarningEXP, MSGBOX_SIGN
	end

PewterCity_EventScript_PoliceNotice::
	msgbox PewterCity_Text_CallPoliceIfInfoOnThieves, MSGBOX_SIGN
	end

PewterCity_EventScript_MuseumSign::
	msgbox PewterCity_Text_MuseumOfScience, MSGBOX_SIGN
	end

PewterCity_EventScript_GymSign::
	lockall
	famechecker FAMECHECKER_BROCK, 0
	msgbox PewterCity_Text_GymSign
	releaseall
	end

PewterCity_EventScript_CitySign::
	msgbox PewterCity_Text_CitySign, MSGBOX_SIGN
	end

PewterCity_EventScript_RunningShoesAide::
	lock
	faceplayer
	setvar VAR_TEMP_1, 0
	call PewterCity_EventScript_AideGiveRunningShoes
	release
	end

PewterCity_EventScript_RunningShoesAideTriggerTop::
	lockall
	setvar VAR_TEMP_1, 1
	call PewterCity_EventScript_AideGiveRunningShoes
	releaseall
	end

PewterCity_EventScript_RunningShoesAideTriggerMid::
	lockall
	setvar VAR_TEMP_1, 2
	call PewterCity_EventScript_AideGiveRunningShoes
	releaseall
	end

PewterCity_EventScript_RunningShoesAideTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 3
	call PewterCity_EventScript_AideGiveRunningShoes
	releaseall
	end

PewterCity_EventScript_AideGiveRunningShoes::
	textcolor NPC_TEXT_COLOR_MALE
	call_if_eq VAR_TEMP_1, 1, PewterCity_EventScript_AideNoticePlayer
	call_if_eq VAR_TEMP_1, 2, PewterCity_EventScript_AideNoticePlayer
	call_if_eq VAR_TEMP_1, 3, PewterCity_EventScript_AideNoticePlayer
	waitse
	playse SE_PIN
	applymovement LOCALID_PEWTER_AIDE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PEWTER_AIDE, Common_Movement_Delay48
	waitmovement 0
	msgbox PewterCity_Text_OhPlayer
	call_if_eq VAR_TEMP_1, 0, PewterCity_EventScript_AideApproachPlayer0
	call_if_eq VAR_TEMP_1, 1, PewterCity_EventScript_AideApproachPlayer1
	call_if_eq VAR_TEMP_1, 2, PewterCity_EventScript_AideApproachPlayer2
	call_if_eq VAR_TEMP_1, 3, PewterCity_EventScript_AideApproachPlayer3
	msgbox PewterCity_Text_AskedToDeliverThis
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message PewterCity_Text_ReceivedRunningShoesFromAide
	waitmessage
	waitfanfare
	msgbox PewterCity_Text_SwitchedShoesWithRunningShoes
	special DisableMsgBoxWalkaway
	signmsg
	msgbox PewterCity_Text_ExplainRunningShoes
	normalmsg
	call EventScript_RestorePrevTextColor
	msgbox PewterCity_Text_MustBeGoingBackToLab
	closemessage
	call_if_eq VAR_TEMP_1, 0, PewterCity_EventScript_AideExit0
	call_if_eq VAR_TEMP_1, 1, PewterCity_EventScript_AideExit1
	call_if_eq VAR_TEMP_1, 2, PewterCity_EventScript_AideExit2
	call_if_eq VAR_TEMP_1, 3, PewterCity_EventScript_AideExit3
	delay 30
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox PewterCity_Text_RunningShoesLetterFromMom
	closemessage
	removeobject LOCALID_PEWTER_AIDE
	setflag FLAG_SYS_B_DASH
	setvar VAR_MAP_SCENE_PEWTER_CITY, 2
	return

PewterCity_EventScript_AideNoticePlayer::
	applymovement LOCALID_PEWTER_AIDE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

@ Aide already at player
PewterCity_EventScript_AideApproachPlayer0::
	closemessage
	delay 20
	return

PewterCity_EventScript_AideApproachPlayer1::
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

PewterCity_EventScript_AideApproachPlayer2::
	closemessage
	applymovement LOCALID_PEWTER_AIDE, PewterCity_Movement_AideApproachPlayerMid
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

PewterCity_EventScript_AideApproachPlayer3::
	closemessage
	applymovement LOCALID_PEWTER_AIDE, PewterCity_Movement_AideApproachPlayerBottom
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

PewterCity_EventScript_AideExit0::
	applymovement LOCALID_PEWTER_AIDE, PewterCity_Movement_AideExit0
	waitmovement 0
	return

PewterCity_EventScript_AideExit1::
	applymovement LOCALID_PEWTER_AIDE, PewterCity_Movement_AideExit1
	waitmovement 0
	return

PewterCity_EventScript_AideExit2::
	applymovement LOCALID_PEWTER_AIDE, PewterCity_Movement_AideExit2
	waitmovement 0
	return

PewterCity_EventScript_AideExit3::
	applymovement LOCALID_PEWTER_AIDE, PewterCity_Movement_AideExit3
	waitmovement 0
	return

PewterCity_Movement_AideApproachPlayerMid::
	delay_4
	walk_down
	step_end

PewterCity_Movement_AideApproachPlayerBottom::
	delay_4
	walk_down
	walk_down
	step_end

PewterCity_Movement_AideExit0::
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PewterCity_Movement_AideExit1::
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PewterCity_Movement_AideExit2::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PewterCity_Movement_AideExit3::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@ Unused
PewterCity_Movement_WalkInPlaceLeft::
	walk_in_place_left
	step_end

Text_DreamEaterTeach::
	.string "(Bâiiiille)\n"
	.string "J'ai dû m'endormir au soleil.\p"
	.string "J'ai rêvé qu'un SOPORIFIK\n"
	.string "dévorait mes rêves…\p"
	.string "Et j'ai appris comment\n"
	.string "dévorer les rêves…\p"
	.string "C'est dingue ça!\p"
	.string "Laisse-moi l'apprendre aussi\n"
	.string "à un POKéMON.$"

Text_DreamEaterDeclined::
	.string "… Ronfl…$"

Text_DreamEaterWhichMon::
	.string "A quel POKéMON enseigner\n"
	.string "DEVOREVE?$"

Text_DreamEaterTaught::
	.string "… Zzz… Peux…\n"
	.string "plus… rien… manger…$"

PewterCity_Text_ClefairyCameFromMoon::
	.string "On raconte que les MELOFEE sont\n"
	.string "des habitants de la lune!\p"
	.string "Ils sont apparus après la chute\n"
	.string "de la PIERRE LUNE sur le MONT\l"
	.string "SELENITE.$"

PewterCity_Text_BrockOnlySeriousTrainerHere::
	.string "Il n'y a pas vraiment de\n"
	.string "DRESSEURS sérieux par ici.\p"
	.string "Ils s'intéressent surtout aux\n"
	.string "INSECTES, rien de passionnant.\p"
	.string "Mais PIERRE d'ARGENTA n'est\n"
	.string "pas comme ça, pas du tout.$"

PewterCity_Text_DidYouCheckOutMuseum::
	.string "T'as déjà visité le MUSEE?$"

PewterCity_Text_WerentThoseFossilsAmazing::
	.string "Les fossiles du MONT SELENITE sont\n"
	.string "intéressants, hein?$"

PewterCity_Text_ReallyYouHaveToGo::
	.string "Non?\n"
	.string "Mais il faut y aller, voyons!$"

PewterCity_Text_ThisIsTheMuseum::
	.string "C'est par là! L'entrée est\n"
	.string "payante mais ça vaut l'coup!$"

PewterCity_Text_DoYouKnowWhatImDoing::
	.string "Psssst!\n"
	.string "Tu sais c'que j'fais?$"

PewterCity_Text_ThatsRightItsHardWork::
	.string "Ah bon?\n"
	.string "OK.$"

PewterCity_Text_SprayingRepelToKeepWildMonsOut::
	.string "Je vaporise du REPOUSSE\n"
	.string "pour éloigner les POKéMON\p"
	.string "de mon jardin!$"

PewterCity_Text_BrocksLookingForChallengersFollowMe::
	.string "T'es DRESSEUR?\p"
	.string "PIERRE cherche un adversaire!\n"
	.string "Suis-moi!$"

PewterCity_Text_GoTakeOnBrock::
	.string "Si tu t'en sens capable, tu devrais\n"
	.string "aller affronter PIERRE!$"

PewterCity_Text_TrainerTipsEarningEXP::
	.string "ASTUCE\p"
	.string "Chaque POKéMON prenant part au\n"
	.string "combat, même pendant une seconde,\p"
	.string "gagne des points EXP.$"

PewterCity_Text_CallPoliceIfInfoOnThieves::
	.string "AVIS!\p"
	.string "On nous signale des voleurs de\n"
	.string "fossiles de POKéMON au\p"
	.string "MONT SELENITE.\p"
	.string "N'hésitez pas à contacter la\n"
	.string "POLICE d'ARGENTA!$"

PewterCity_Text_MuseumOfScience::
	.string "MUSEE DES SCIENCES d'ARGENTA$"

PewterCity_Text_GymSign::
	.string "ARENE POKéMON d'ARGENTA\n"
	.string "CHAMPION: PIERRE\l"
	.string "Le DRESSEUR dur comme la pierre!$"

PewterCity_Text_CitySign::
	.string "ARGENTA\n"
	.string "Le mat et le gris de la roche$"

PewterCity_Text_OhPlayer::
	.string "Oh, {PLAYER}{KUN}!$"

PewterCity_Text_AskedToDeliverThis::
	.string "Content de te voir. Je suis\n"
	.string "l'ASSISTANT du PROF. CHEN.\p"
	.string "On m'a demandé de te donner\n"
	.string "ça, alors voilà…$"

PewterCity_Text_ReceivedRunningShoesFromAide::
	.string "{PLAYER} reçoit les CHAUSSURES DE\n"
	.string "SPORT de l'ASSISTANT.$"

PewterCity_Text_SwitchedShoesWithRunningShoes::
	.string "{PLAYER} enlève ses chaussures pour\n"
	.string "mettre les CHAUSSURES DE SPORT.$"

PewterCity_Text_ExplainRunningShoes::
	.string "Appuie sur le bouton B\n"
	.string "pour courir.\p"
	.string "Mais seulement où tu as la place\n"
	.string "pour ça!$"

PewterCity_Text_MustBeGoingBackToLab::
	.string "Bon, je dois retourner au LABO.\p"
	.string "Au revoir.$"

PewterCity_Text_RunningShoesLetterFromMom::
	.string "Il y a un mot avec:\p"
	.string "{PLAYER},\p"
	.string "Voilà une paire de CHAUSSURES\n"
	.string "DE SPORT mon petit bouchon.\p"
	.string "Bon courage, \n"
	.string "ta maman.$"


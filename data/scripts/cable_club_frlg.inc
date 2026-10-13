CableClub_OnTransition_Frlg::
	call CableClub_EventScript_HideOrShowMysteryGiftMan_Frlg
	end

CableClub_EventScript_HideOrShowMysteryGiftMan_Frlg::
	specialvar VAR_RESULT, ValidateSavedWonderCard
	goto_if_eq VAR_RESULT, FALSE, EventScript_HideMysteryGiftMan_Frlg
	clearflag FLAG_HIDE_MG_DELIVERYMEN
	return

EventScript_HideMysteryGiftMan_Frlg::
	setflag FLAG_HIDE_MG_DELIVERYMEN
	return

CableClub_EventScript_MysteryGiftMan_Frlg::
	trywondercardscript

@ Unused
EventScript_MysteryGiftThankYou_Frlg::
	msgbox gText_ThankYouForAccessingMysteryGift, MSGBOX_NPC
	end

CableClub_OnWarp_Frlg::
	map_script_2 VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, EventScript_CheckTurnAttendant_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, EventScript_CheckTurnAttendant_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MULTI_BATTLE, EventScript_CheckTurnAttendant_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER, EventScript_CheckTurnAttendant_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_UNION_ROOM, EventScript_CheckTurnAttendant_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_BERRY_CRUSH, EventScript_CheckTurnAttendant_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, EventScript_CheckTurnAttendant_Frlg
	.2byte 0

EventScript_CheckTurnAttendant_Frlg::
	goto_if_eq VAR_0x8007, 0, EventScript_CheckTurnAttendantEnd
	turnobject VAR_0x8007, DIR_WEST
EventScript_CheckTurnAttendantEnd:
	end

CableClub_OnLoad_Frlg::
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, EventScript_OnLoadFromColosseum_Frlg
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, EventScript_OnLoadFromColosseum_Frlg
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_MULTI_BATTLE, EventScript_OnLoadFromColosseum_Frlg
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER, EventScript_OnLoadFromTradeCenter_Frlg
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_UNION_ROOM, EventScript_OnLoadFromUnionRoom_Frlg
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_BERRY_CRUSH, EventScript_OnLoadFromBerryCrush_Frlg
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_MINIGAME, EventScript_OnLoadFromGameCorner_Frlg
	end

EventScript_OnLoadFromColosseum_Frlg::
	call CableClub_EventScript_OpenDirectCornerBarrier_Frlg
	end

EventScript_OnLoadFromTradeCenter_Frlg::
	call CableClub_EventScript_OpenDirectCornerBarrier_Frlg
	end

EventScript_OnLoadFromUnionRoom_Frlg::
	call CableClub_EventScript_OpenUnionRoomBarrier_Frlg
	end

EventScript_OnLoadFromBerryCrush_Frlg::
	call CableClub_EventScript_OpenDirectCornerBarrier_Frlg
	end

EventScript_OnLoadFromGameCorner_Frlg::
	call CableClub_EventScript_OpenGameCornerBarrier_Frlg
	end

CableClub_OnFrame_Frlg::
	map_script_2 VAR_MAP_SCENE_POKEMON_CENTER_TEALA, 1, CableClub_EventScript_Tutorial_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, CableClub_EventScript_ExitLinkRoom_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, CableClub_EventScript_ExitLinkRoom_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MULTI_BATTLE, CableClub_EventScript_ExitLinkRoom_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER, CableClub_EventScript_ExitTradeCenter_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_UNION_ROOM, CableClub_EventScript_ExitUnionRoom_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_BERRY_CRUSH, CableClub_EventScript_ExitLinkRoom_Frlg
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom_Frlg
	.2byte 0

CableClub_EventScript_ExitLinkRoom_Frlg::
	lockall
	call CableClub_EventScript_CloseLinkAndExitLinkRoom_Frlg
	call CableClub_EventScript_CloseDirectCornerBarrier_Frlg
	special DrawWholeMapView
	playse SE_CLICK
	erasebox 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_ExitMinigameRoom_Frlg::
	lockall
	call CableClub_EventScript_CloseLinkAndExitLinkRoom_Frlg
	call CableClub_EventScript_CloseGameCornerBarrier_Frlg
	special DrawWholeMapView
	playse SE_CLICK
	erasebox 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_CloseLinkAndExitLinkRoom_Frlg::
	setvar VAR_CABLE_CLUB_STATE, 0
	textcolor NPC_TEXT_COLOR_FEMALE
	goto_if_eq VAR_0x8007, 0, CableClub_EventScript_PlayerExitLinkRoom_Frlg
	applymovement VAR_0x8007, Movement_AttendantFaceLeft
	waitmovement 0
	applymovement LOCALID_PLAYER, Movement_PlayerExitLinkRoom
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceDown
	waitmovement 0
	return

CableClub_EventScript_ExitTradeCenter_Frlg::
	lockall
	call CableClub_EventScript_PlayerExitTradeCenter_Frlg
	call CableClub_EventScript_CloseDirectCornerBarrier_Frlg
	special DrawWholeMapView
	playse SE_CLICK
	erasebox 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_PlayerExitTradeCenter_Frlg::
	special CloseLink
	setvar VAR_CABLE_CLUB_STATE, 0
	textcolor NPC_TEXT_COLOR_FEMALE
	goto_if_eq VAR_0x8007, 0, CableClub_EventScript_PlayerExitLinkRoom_Frlg
	applymovement LOCALID_PLAYER, Movement_PlayerFaceAttendantRight
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceLeft
	waitmovement 0
	call CableClub_EventScript_TrainerCardDataOverwritten_Frlg
	return

CableClub_EventScript_ExitUnionRoom_Frlg::
	lockall
	call CableClub_EventScript_PlayerExitUnionRoom_Frlg
	call CableClub_EventScript_CloseUnionRoomBarrier_Frlg
	special DrawWholeMapView
	playse SE_CLICK
	erasebox 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_PlayerExitUnionRoom_Frlg::
	setvar VAR_CABLE_CLUB_STATE, 0
	textcolor NPC_TEXT_COLOR_FEMALE
	goto_if_eq VAR_0x8007, 0, CableClub_EventScript_PlayerExitLinkRoom_Frlg
	applymovement LOCALID_PLAYER, Movement_PlayerFaceAttendantRight
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceLeft
	waitmovement 0
	call CableClub_EventScript_TrainerCardDataOverwritten_Frlg
	return

CableClub_EventScript_TrainerCardDataOverwritten_Frlg::
	message CableClub_Text_TrainerCardDataOverwritten_Frlg
	waitmessage
	playse SE_PIN
	message CableClub_Text_HopeToSeeYouAgain_Frlg
	waitmessage
	applymovement LOCALID_PLAYER, Movement_PlayerExitLinkRoom
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceDown
	waitmovement 0
	return

CableClub_EventScript_PlayerExitLinkRoom_Frlg::
	applymovement LOCALID_PLAYER, Movement_PlayerExitLinkRoom
	waitmovement 0
	return

CableClub_EventScript_Tutorial_Frlg::
	lockall
	textcolor NPC_TEXT_COLOR_FEMALE
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox CableClub_Text_FirstTimeRightThisWay_Frlg
	closemessage
	applymovement LOCALID_PLAYER, Movement_PlayerApproachCounter
	waitmovement 0
	delay 30
	msgbox CableClub_Text_ExplainWirelessClubFirstTime_Frlg
	setvar VAR_MAP_SCENE_POKEMON_CENTER_TEALA, 2
	releaseall
	end

Movement_PlayerApproachCounter:
	walk_up
	walk_up
	step_end

CableClub_EventScript_WelcomeToCableClub_Frlg::
	message CableClub_Text_WelcomeWhichCableClubService_Frlg
	waitmessage
	delay 15
	goto CableClub_EventScript_SelectCableClubRoom_Frlg
	end

CableClub_EventScript_UnusedWelcomeToCableClub_Frlg::
	msgbox CableClub_Text_WhichService_Frlg
	goto CableClub_EventScript_SelectCableClubRoom_Frlg
	end

CableClub_EventScript_SelectCableClubRoom_Frlg::
	setvar VAR_0x8004, 0
	multichoice 0, 0, MULTI_CABLE_CLUB_NO_RECORD_MIX, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_TradeCenter_Frlg
	case 1, CableClub_EventScript_Colosseum_Frlg
	case 2, CableClub_EventScript_AbortLink_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink_Frlg
	end

CableClub_EventScript_Colosseum_Frlg::
	copyvar VAR_0x8007, VAR_LAST_TALKED
	goto CableClub_EventScript_SelectBattleMode_Frlg
	end

CableClub_EventScript_SelectBattleMode_Frlg::
	message CableClub_Text_PlayWhichBattleMode_Frlg
	waitmessage
	multichoice 0, 0, MULTI_BATTLE_MODE, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_SingleBattleMode_Frlg
	case 1, CableClub_EventScript_DoubleBattleMode_Frlg
	case 2, CableClub_EventScript_MultiBattleMode_Frlg
	case 3, CableClub_EventScript_BattleModeInfo_Frlg
	case 4, CableClub_EventScript_AbortLink_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink_Frlg
	end

CableClub_EventScript_BattleModeInfo_Frlg::
	msgbox CableClub_Text_ExplainBattleModes_Frlg
	goto CableClub_EventScript_SelectBattleMode_Frlg
	end

CableClub_EventScript_SingleBattleMode_Frlg::
	setvar VAR_0x8004, USING_SINGLE_BATTLE
	goto CableClub_EventScript_TryEnterColosseum_Frlg
	end

CableClub_EventScript_DoubleBattleMode_Frlg::
	special HasEnoughMonsForDoubleBattle
	goto_if_ne VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS, CableClub_EventScript_NeedTwoMonsForDoubleBattle_Frlg
	setvar VAR_0x8004, USING_DOUBLE_BATTLE
	goto CableClub_EventScript_TryEnterColosseum_Frlg
	end

CableClub_EventScript_NeedTwoMonsForDoubleBattle_Frlg::
	msgbox CableClub_Text_NeedTwoMonsForDoubleBattle_Frlg
	goto CableClub_EventScript_SelectBattleMode_Frlg
	end

CableClub_EventScript_MultiBattleMode_Frlg::
	setvar VAR_0x8004, USING_MULTI_BATTLE
	goto CableClub_EventScript_TryEnterColosseum_Frlg
	end

CableClub_EventScript_TryEnterColosseum_Frlg::
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink_Frlg
	message CableClub_Text_PleaseWaitBCancel_Frlg
	waitmessage
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special TryBattleLinkup
	call EventScript_RestorePrevTextColor
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterColosseum_Frlg
	goto_if_eq VAR_RESULT, LINKUP_SOMEONE_NOT_READY, CableClub_EventScript_AbortLinkSomeoneNotReady_Frlg
	goto_if_eq VAR_RESULT, LINKUP_DIFF_SELECTIONS, CableClub_EventScript_AbortLinkDifferentSelections_Frlg
	goto_if_eq VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS, CableClub_EventScript_AbortLinkIncorrectNumberOfBattlers_Frlg
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_AbortLink_Frlg
	goto_if_eq VAR_RESULT, LINKUP_CONNECTION_ERROR, CableClub_EventScript_AbortLinkConnectionError_Frlg
	end

CableClub_EventScript_EnterColosseum_Frlg::
	special HealPlayerParty
	special SavePlayerParty
	special LoadPlayerBag
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	messageautoscroll CableClub_Text_PleaseEnter_Frlg
	waitmessage
	call CableClub_EventScript_OpenDirectCornerBarrier_Frlg
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement LOCALID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement LOCALID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideplayer
	closedoor 9, 1
	waitdooranim
	release
	goto_if_eq VAR_0x8004, USING_MULTI_BATTLE, CableClub_EventScript_WarpTo4PColosseum_Frlg
	special SetCableClubWarp
	warp MAP_BATTLE_COLOSSEUM_2P_FRLG, 6, 8
	special DoCableClubWarp
	end

@ Unused
CableClub_EventScript_PlayerApproachLinkRoomRight_Frlg::
	applymovement LOCALID_PLAYER, Movement_PlayerApproachLinkRoomRight
	waitmovement 0
	return

CableClub_EventScript_WarpTo4PColosseum_Frlg::
	special SetCableClubWarp
	warp MAP_BATTLE_COLOSSEUM_4P_FRLG, 5, 8
	special DoCableClubWarp
	end

CableClub_EventScript_AbortLinkIncorrectNumberOfBattlers_Frlg::
	switch VAR_0x8004
	case USING_SINGLE_BATTLE, CableClub_EventScript_AbortLinkWrongNumberForSingleBattle_Frlg
	case USING_DOUBLE_BATTLE, CableClub_EventScript_AbortLinkWrongNumberForDoubleBattle_Frlg
	case USING_MULTI_BATTLE, CableClub_EventScript_AbortLinkNeedFourPlayers_Frlg
	goto CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants_Frlg
	end

CableClub_EventScript_AbortLinkNeedFourPlayers_Frlg::
	special CloseLink
	msgbox CableClub_Text_NeedFourPlayers_Frlg
	goto CableClub_EventScript_ConfirmNumberAndRestart_Frlg
	end

CableClub_EventScript_AbortLinkWrongNumberForDoubleBattle_Frlg::
	special CloseLink
	msgbox CableClub_Text_CantDoubleBattleWithXPlayers_Frlg
	goto CableClub_EventScript_ConfirmNumberAndRestart_Frlg
	end

CableClub_EventScript_AbortLinkWrongNumberForSingleBattle_Frlg::
	special CloseLink
	msgbox CableClub_Text_CantSingleBattleWithXPlayers_Frlg
	goto CableClub_EventScript_ConfirmNumberAndRestart_Frlg
	end

CableClub_EventScript_ConfirmNumberAndRestart_Frlg::
	special CloseLink  @ Redundant
	msgbox CableClub_Text_PleaseConfirmNumberAndRestart_Frlg
	release
	end

CableClub_EventScript_TradeCenter_Frlg::
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call CableClub_EventScript_CheckPartyTradeRequirements_Frlg
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink_Frlg
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink_Frlg
	message CableClub_Text_PleaseWaitBCancel_Frlg
	waitmessage
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special TryTradeLinkup
	call EventScript_RestorePrevTextColor
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterTradeCenter_Frlg
	goto_if_eq VAR_RESULT, LINKUP_SOMEONE_NOT_READY, CableClub_EventScript_AbortLinkSomeoneNotReady_Frlg
	goto_if_eq VAR_RESULT, LINKUP_DIFF_SELECTIONS, CableClub_EventScript_AbortLinkDifferentSelections_Frlg
	goto_if_eq VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS, CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants_Frlg
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_AbortLink_Frlg
	goto_if_eq VAR_RESULT, LINKUP_CONNECTION_ERROR, CableClub_EventScript_AbortLinkConnectionError_Frlg
	goto_if_eq VAR_RESULT, LINKUP_PLAYER_NOT_READY, CableClub_EventScript_AbortLinkPlayerNotReady_Frlg
	goto_if_eq VAR_RESULT, LINKUP_PARTNER_NOT_READY, CableClub_EventScript_AbortLinkOtherTrainerNotReady_Frlg
	end

CableClub_EventScript_EnterTradeCenter_Frlg::
	setvar VAR_0x8004, USING_TRADE_CENTER
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	messageautoscroll CableClub_Text_PleaseEnter_Frlg
	waitmessage
	call CableClub_EventScript_OpenDirectCornerBarrier_Frlg
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement LOCALID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement LOCALID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideplayer
	closedoor 9, 1
	waitdooranim
	release
	special SetCableClubWarp
	setwarp MAP_TRADE_CENTER_FRLG, 5, 8
	special DoCableClubWarp
	end

CableClub_EventScript_CheckPartyTradeRequirements_Frlg::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_lt VAR_RESULT, 2, CableClub_EventScript_NeedTwoMonsToTrade_Frlg
	specialvar VAR_RESULT, DoesPartyHaveEnigmaBerry
	goto_if_eq VAR_RESULT, TRUE, CableClub_EventScript_CantTradeEnigmaBerry_Frlg
	setvar VAR_RESULT, TRUE
	return

CableClub_EventScript_NeedTwoMonsToTrade_Frlg::
	msgbox CableClub_Text_NeedTwoMonsToTrade_Frlg
	setvar VAR_RESULT, FALSE
	return

CableClub_EventScript_CantTradeEnigmaBerry_Frlg::
	msgbox CableClub_Text_CantTradeEnigmaBerry_Frlg
	setvar VAR_RESULT, FALSE
	return

@ Record Corner is nopped in FRLG
CableClub_EventScript_RecordCorner_Frlg::
	end

CableClub_EventScript_AbortLinkPlayerNotReady_Frlg::
	special CloseLink
	msgbox CableClub_Text_NotSetUpForFarAwayRegion_Frlg
	release
	end

CableClub_EventScript_AbortLinkOtherTrainerNotReady_Frlg::
	special CloseLink
	msgbox CableClub_Text_OtherTrainerNotReady_Frlg
	release
	end

CableClub_EventScript_AbortLinkConnectionError_Frlg::
	special CloseLink
	msgbox CableClub_Text_LinkErrorPleaseReset_Frlg
	release
	end

CableClub_EventScript_AbortLinkSomeoneNotReady_Frlg::
	special CloseLink
	msgbox CableClub_Text_SomeoneIsNotReadyToLink_Frlg
	release
	end

CableClub_EventScript_AbortLinkDifferentSelections_Frlg::
	special CloseLink
	msgbox CableClub_Text_PlayersMadeDifferentSelections_Frlg
	release
	end

CableClub_EventScript_AbortLink_Frlg::
	special CloseLink
	msgbox CableClub_Text_PleaseVisitAgain_Frlg
	release
	end

CableClub_EventScript_AbortMinigame_Frlg::
	special CloseLink
	msgbox CableClub_Text_ComeAgain_Frlg
	release
	end

@ Unused
CableClub_EventScript_CableClubWarp_Frlg::
	special SetCableClubWarp
	special DoCableClubWarp
	end

CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants_Frlg::
	special CloseLink
	msgbox CableClub_Text_IncorrectNumberOfParticipants_Frlg
	release
	end

CableClub_EventScript_AbortLinkPlayerHasBadEgg_Frlg::
	special CloseLink
	msgbox CableClub_Text_YouHaveAMonThatCantBeTaken_Frlg
	release
	end

CableClub_EventScript_WirelessClubAdjustements_Frlg::
	msgbox Text_WirelessClubUndergoingAdjustments
	release
	end

CableClub_EventScript_NotReadyYet_Frlg::
	msgbox Text_AppearsToBeUndergoingAdjustments
	releaseall
	end

Movement_AttendantFaceDown_Frlg::
	face_down
	step_end

@ Unused
Movement_AttendantFaceRight_Frlg::
	face_right
	step_end

Movement_AttendantFaceLeft_Frlg::
	face_left
	step_end

Movement_PlayerExitLinkRoom_Frlg::
	walk_down
	walk_down
	step_end

Movement_PlayerApproachLinkRoomRight_Frlg::
	walk_right
	walk_up
	walk_up
	step_end

Movement_PlayerApproachLinkRoomLeft_Frlg::
	walk_left
	walk_up
	walk_up
	step_end

Movement_PlayerEnterLinkRoom_Frlg::
	walk_up
	step_end

@ Unused
Movement_PlayerFaceAttendantLeft_Frlg::
	face_left
	step_end

Movement_PlayerFaceAttendantRight_Frlg::
	face_right
	step_end

Movement_PlayerEnterMinigameRoom_Frlg::
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

CableClub_EventScript_ShowBattleRecords_Frlg::
	lockall
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, 0
	special ShowTrainerHillRecords
	releaseall
	end

BattleColosseum_2P_EventScript_PlayerSpot0::
	setvar VAR_0x8005, 0
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special ColosseumPlayerSpotTriggered
	end

BattleColosseum_2P_EventScript_PlayerSpot1::
	setvar VAR_0x8005, 1
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special ColosseumPlayerSpotTriggered
	end

BattleColosseum_4P_EventScript_PlayerSpot0::
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	goto_if_eq VAR_RESULT, 0, BattleColosseum_4P_EventScript_CancelSpotTrigger_Frlg
	setvar VAR_0x8005, 0
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special ColosseumPlayerSpotTriggered
	end

BattleColosseum_4P_EventScript_PlayerSpot1::
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	goto_if_eq VAR_RESULT, 0, BattleColosseum_4P_EventScript_CancelSpotTrigger_Frlg
	setvar VAR_0x8005, 1
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special ColosseumPlayerSpotTriggered
	end

BattleColosseum_4P_EventScript_PlayerSpot2::
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	goto_if_eq VAR_RESULT, 0, BattleColosseum_4P_EventScript_CancelSpotTrigger_Frlg
	setvar VAR_0x8005, 2
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special ColosseumPlayerSpotTriggered
	end

BattleColosseum_4P_EventScript_PlayerSpot3::
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	goto_if_eq VAR_RESULT, 0, BattleColosseum_4P_EventScript_CancelSpotTrigger_Frlg
	setvar VAR_0x8005, 3
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special ColosseumPlayerSpotTriggered
	end

BattleColosseum_4P_EventScript_CancelSpotTrigger_Frlg::
	end

TradeCenter_EventScript_Chair0::
	setvar VAR_0x8005, 0
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special PlayerEnteredTradeSeat
	end

TradeCenter_EventScript_Chair1::
	setvar VAR_0x8005, 1
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special PlayerEnteredTradeSeat
	end

@ Unused
TradeCenter_EventScript_Chair2_Frlg::
	setvar VAR_0x8005, 2
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special PlayerEnteredTradeSeat
	end

@ Unused
TradeCenter_EventScript_Chair3_Frlg::
	setvar VAR_0x8005, 3
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special PlayerEnteredTradeSeat
	end

@ Nop in FRLG
@ Separate labels to match GetDirectionForEventScript
RecordCorner_EventScript_Spot0::
RecordCorner_EventScript_Spot1::
RecordCorner_EventScript_Spot2::
RecordCorner_EventScript_Spot3::
	end

CableClub_EventScript_ReadTrainerCard_Frlg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox Text_LookedAtPlayersTrainerCard_Frlg
	fadescreen FADE_TO_BLACK
	special Script_ShowLinkTrainerCard
	end

CableClub_EventScript_ReadTrainerCardColored_Frlg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox Text_LookedAtPlayersTrainerCardColored_Frlg
	fadescreen FADE_TO_BLACK
	special Script_ShowLinkTrainerCard
	end

CableClub_EventScript_TooBusyToNotice_Frlg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox Text_TrainerTooBusyToNotice_Frlg
	closemessage
	end

BattleColosseum_2P_EventScript_Attendant_Frlg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special Script_FacePlayer
	msgbox Text_TakeSeatStartBattle_Frlg
	special Script_ClearHeldMovement
	closemessage
	end

TradeCenter_EventScript_Attendant_Frlg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special Script_FacePlayer
	msgbox Text_TakeSeatStartTrade_Frlg
	special Script_ClearHeldMovement
	closemessage
	end

@ Nop in FRLG
RecordCorner_EventScript_Attendant_Frlg::
	end

TradeCenter_ConfirmLeaveRoom_Frlg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox Text_TerminateLinkIfYouLeaveRoom_Frlg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TradeCenter_TerminateLink_Frlg
	erasebox 0, 0, 29, 19
	releaseall
	end

TradeCenter_TerminateLink_Frlg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	messageautoscroll Text_TerminateLinkConfirmation
	waitmessage
	special ExitLinkRoom
	end

CableClub_EventScript_DoLinkRoomExit_Frlg::
	special CleanupLinkRoomState
	special ReturnFromLinkRoom
	end

CableClub_EventScript_UnionRoomAttendant_Frlg::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_WirelessClubAdjustements_Frlg
	specialvar VAR_RESULT, IsBadEggInParty
	goto_if_eq VAR_RESULT, TRUE, CableClub_EventScript_AbortLinkPlayerHasBadEgg_Frlg
	copyvar VAR_0x8007, VAR_LAST_TALKED
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_UnionRoomAdapterNotConnected_Frlg
	message CableClub_Text_WelcomeUnionRoomEnter_Frlg
	waitmessage
	goto CableClub_EventScript_AskEnterUnionRoom_Frlg
	end

CableClub_EventScript_AskEnterUnionRoom_Frlg::
	multichoice 18, 6, MULTI_YESNOINFO, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_EnterUnionRoom_Frlg
	case 1, CableClub_EventScript_AbortLink_Frlg
	case 2, CableClub_EventScript_UnionRoomInfo_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink_Frlg
	end

CableClub_EventScript_UnionRoomInfo_Frlg::
	message CableClub_Text_UnionRoomInfo_Frlg
	waitmessage
	goto CableClub_EventScript_AskEnterUnionRoom_Frlg
	end

CableClub_EventScript_EnterUnionRoom_Frlg::
	call CableClub_EventScript_CheckPartyUnionRoomRequirements_Frlg
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_AbortLink_Frlg
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink_Frlg
	msgbox CableClub_Text_EnjoyUnionRoom_Frlg
	closemessage
	special HealPlayerParty
	setvar VAR_0x8004, USING_UNION_ROOM
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	call CableClub_EventScript_OpenUnionRoomBarrier_Frlg
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	applymovement LOCALID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 5, 1
	waitdooranim
	applymovement LOCALID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideplayer
	closedoor 5, 1
	waitdooranim
	special Script_ResetUnionRoomTrade
	special SetCableClubWarp
	warpspinenter MAP_UNION_ROOM_FRLG, 7, 11
	waitstate
	special RunUnionRoom
	waitstate
	end

CableClub_EventScript_CheckPartyUnionRoomRequirements_Frlg::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_lt VAR_RESULT, 2, CableClub_EventScript_NeedTwoMonsForUnionRoom_Frlg
	specialvar VAR_RESULT, DoesPartyHaveEnigmaBerry
	goto_if_eq VAR_RESULT, TRUE, CableClub_EventScript_NoEnigmaBerryInUnionRoom_Frlg
	setvar VAR_RESULT, TRUE
	return

CableClub_EventScript_NeedTwoMonsForUnionRoom_Frlg::
	msgbox CableClub_Text_NeedTwoMonsForUnionRoom_Frlg
	goto EventScript_SetResultFalse
	end

CableClub_EventScript_NoEnigmaBerryInUnionRoom_Frlg::
	msgbox CableClub_Text_NoEnigmaBerryInUnionRoom_Frlg
	goto EventScript_SetResultFalse
	end

CableClub_EventScript_UnionRoomAdapterNotConnected_Frlg::
	msgbox CableClub_Text_UnionRoomAdapterNotConnected_Frlg
	release
	return

CableClub_EventScript_WirelessClubAttendant_Frlg::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_WirelessClubAdjustements_Frlg
	msgbox CableClub_Text_AskAboutLinking_Frlg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CableClub_EventScript_DontAskAboutLinking_Frlg
	msgbox CableClub_Text_ExplainWirelessClub_Frlg
	release
	return

CableClub_EventScript_DontAskAboutLinking_Frlg::
	msgbox CableClub_Text_HopeYouEnjoyWirelessSystem_Frlg
	release
	return

CableClub_EventScript_DirectCornerAttendant_Frlg::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_WirelessClubAdjustements_Frlg
	specialvar VAR_RESULT, IsBadEggInParty
	goto_if_eq VAR_RESULT, TRUE, CableClub_EventScript_AbortLinkPlayerHasBadEgg_Frlg
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_WelcomeToCableClub_Frlg
	message CableClub_Text_WelcomeWhichDirectCornerRoom_Frlg
	waitmessage
	delay 15
	goto CableClub_EventScript_DirectCornerSelectService_Frlg
	end

CableClub_EventScript_DirectCornerSelectService_Frlg::
	goto_if_unset FLAG_GOT_POWDER_JAR, CableClub_EventScript_DirectCornerNoBerry_Frlg
	multichoice 0, 0, MULTI_WIRELESS_NO_RECORD, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_WirelessTrade_Frlg
	case 1, CableClub_EventScript_WirelessBattleSelect_Frlg
	case 2, CableClub_EventScript_WirelessBerryCrush_Frlg
	case 3, CableClub_EventScript_AbortLink_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink_Frlg
	end

CableClub_EventScript_DirectCornerNoBerry_Frlg::
	multichoice 0, 0, MULTI_WIRELESS_NO_RECORD_BERRY, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_WirelessTrade_Frlg
	case 1, CableClub_EventScript_WirelessBattleSelect_Frlg
	case 2, CableClub_EventScript_AbortLink_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink_Frlg
	end

CableClub_EventScript_WirelessTrade_Frlg::
	msgbox CableClub_Text_TradePokemon_Frlg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CableClub_EventScript_AbortLink_Frlg
	call CableClub_EventScript_CheckPartyTradeRequirements_Frlg
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_AbortLink_Frlg
	setvar VAR_0x8004, LINK_GROUP_TRADE
	goto CableClub_EventScript_SaveAndChooseLinkLeader_Frlg
	end

CableClub_EventScript_WirelessBattleSelect_Frlg::
	message CableClub_Text_PlayWhichBattleMode_Frlg
	waitmessage
	multichoice 0, 0, MULTI_BATTLE_MODE, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_WirelessSingleBattle_Frlg
	case 1, CableClub_EventScript_WirelessDoubleBattle_Frlg
	case 2, CableClub_EventScript_WirelessMultiBattle_Frlg
	case 3, CableClub_EventScript_WirelessBattleInfo_Frlg
	case 4, CableClub_EventScript_AbortLink_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink_Frlg
	end

CableClub_EventScript_WirelessSingleBattle_Frlg::
	setvar VAR_0x8004, LINK_GROUP_SINGLE_BATTLE
	goto CableClub_EventScript_SaveAndChooseLinkLeader_Frlg
	end

CableClub_EventScript_WirelessDoubleBattle_Frlg::
	special HasEnoughMonsForDoubleBattle
	goto_if_ne VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS, CableClub_EventScript_TwoMonsNeededForWirelessDoubleBattle_Frlg
	setvar VAR_0x8004, LINK_GROUP_DOUBLE_BATTLE
	goto CableClub_EventScript_SaveAndChooseLinkLeader_Frlg
	end

CableClub_EventScript_TwoMonsNeededForWirelessDoubleBattle_Frlg::
	msgbox CableClub_Text_NeedTwoMonsForDoubleBattle_Frlg
	goto CableClub_EventScript_WirelessBattleSelect_Frlg
	end

CableClub_EventScript_WirelessMultiBattle_Frlg::
	setvar VAR_0x8004, LINK_GROUP_MULTI_BATTLE
	goto CableClub_EventScript_SaveAndChooseLinkLeader_Frlg
	end

CableClub_EventScript_WirelessBattleInfo_Frlg::
	msgbox CableClub_Text_ExplainBattleModes_Frlg
	goto CableClub_EventScript_WirelessBattleSelect_Frlg
	end

CableClub_EventScript_WirelessBerryCrush_Frlg::
	msgbox CableClub_Text_UseBerryCrush_Frlg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CableClub_EventScript_AbortLink_Frlg
	special HasAtLeastOneBerry
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_NeedBerryForBerryCrush_Frlg
	setvar VAR_0x8004, LINK_GROUP_BERRY_CRUSH
	goto CableClub_EventScript_SaveAndChooseLinkLeader_Frlg
	end

CableClub_EventScript_NeedBerryForBerryCrush_Frlg::
	msgbox CableClub_Text_NeedBerryForBerryCrush_Frlg
	goto CableClub_EventScript_DirectCornerSelectService_Frlg
	end

CableClub_EventScript_SaveAndChooseLinkLeader_Frlg::
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink_Frlg
	switch VAR_0x8004
	case LINK_GROUP_TRADE, CableClub_EventScript_ChooseLinkLeaderFrom2_Frlg
	case LINK_GROUP_SINGLE_BATTLE, CableClub_EventScript_ChooseLinkLeaderFrom2_Frlg
	case LINK_GROUP_DOUBLE_BATTLE, CableClub_EventScript_ChooseLinkLeaderFrom2_Frlg
	case LINK_GROUP_MULTI_BATTLE, CableClub_EventScript_ChooseLinkLeaderFrom4_Frlg
	case LINK_GROUP_BERRY_CRUSH, CableClub_EventScript_ChooseLinkLeader_Frlg
	end

CableClub_EventScript_ChooseLinkLeaderFrom2_Frlg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	message CableClub_Text_ChooseGroupLeaderOfTwo_Frlg
	waitmessage
	call EventScript_RestorePrevTextColor
	multichoice 13, 6, MULTI_LINK_LEADER, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_TryJoinGroup2Players_Frlg
	case 1, CableClub_EventScript_TryLeadGroup2Players_Frlg
	case 2, CableClub_EventScript_AbortLink_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink_Frlg
	end

CableClub_EventScript_TryLeadGroup2Players_Frlg::
	call CableClub_EventScript_TryBecomeLinkLeader_Frlg
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom_Frlg
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeaderFrom2_Frlg
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryLeadGroup2Players_Frlg
	release
	return

CableClub_EventScript_TryJoinGroup2Players_Frlg::
	call CableClub_EventScript_TryJoinLinkGroup_Frlg
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom_Frlg
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeaderFrom2_Frlg
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryJoinGroup2Players_Frlg
	release
	return

CableClub_EventScript_ChooseLinkLeaderFrom4_Frlg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	message CableClub_Text_ChooseGroupLeaderOfFour_Frlg
	waitmessage
	call EventScript_RestorePrevTextColor
	multichoice 13, 6, MULTI_LINK_LEADER, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_TryJoinGroup4Players_Frlg
	case 1, CableClub_EventScript_TryLeadGroup4Players_Frlg
	case 2, CableClub_EventScript_AbortLink_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink_Frlg
	end

CableClub_EventScript_TryLeadGroup4Players_Frlg::
	call CableClub_EventScript_TryBecomeLinkLeader_Frlg
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom_Frlg
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeaderFrom4_Frlg
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryLeadGroup4Players_Frlg
	release
	return

CableClub_EventScript_TryJoinGroup4Players_Frlg::
	call CableClub_EventScript_TryJoinLinkGroup_Frlg
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom_Frlg
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeaderFrom4_Frlg
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryJoinGroup4Players_Frlg
	release
	return

CableClub_EventScript_ChooseLinkLeader_Frlg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	message CableClub_Text_ChooseGroupLeader_Frlg
	waitmessage
	call EventScript_RestorePrevTextColor
	multichoice 13, 6, MULTI_LINK_LEADER, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_TryJoinGroupXPlayers_Frlg
	case 1, CableClub_EventScript_TryLeadGroupXPlayers_Frlg
	case 2, CableClub_EventScript_AbortLink_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_AbortLink_Frlg
	end

CableClub_EventScript_TryLeadGroupXPlayers_Frlg::
	call CableClub_EventScript_TryBecomeLinkLeader_Frlg
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom_Frlg
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeader_Frlg
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryLeadGroupXPlayers_Frlg
	release
	return

CableClub_EventScript_TryJoinGroupXPlayers_Frlg::
	call CableClub_EventScript_TryJoinLinkGroup_Frlg
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom_Frlg
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeader_Frlg
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryJoinGroupXPlayers_Frlg
	release
	return

CableClub_EventScript_TryBecomeLinkLeader_Frlg::
	special TryBecomeLinkLeader
	return

CableClub_EventScript_TryJoinLinkGroup_Frlg::
	special TryJoinLinkGroup
	return

CableClub_EventScript_EnterWirelessLinkRoom_Frlg::
	messageautoscroll CableClub_Text_DirectYouToYourRoom_Frlg
	waitmessage
	delay 60
	closemessage
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call CableClub_EventScript_OpenDirectCornerBarrier_Frlg
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement LOCALID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement LOCALID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideplayer
	closedoor 9, 1
	waitdooranim
	release
	waitstate
	end

CableClub_EventScript_ShowWirelessCommunicationScreen_Frlg::
	lockall
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_NotReadyYet_Frlg
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_AdapterNotConnected_Frlg
	fadescreen FADE_TO_BLACK
	special ShowWirelessCommunicationScreen
	msgbox CableClub_Text_ParticipantsStepUpToCounter_Frlg
	releaseall
	end

CableClub_EventScript_AdapterNotConnected_Frlg::
	msgbox CableClub_Text_AdapterNotConnected_Frlg
	releaseall
	end

CableClub_EventScript_OpenUnionRoomBarrier_Frlg::
	setmetatile 5, 3, METATILE_PokemonCenterFrlg_Floor_ShadeLeft, 0
	return

CableClub_EventScript_CloseUnionRoomBarrier_Frlg::
	setmetatile 5, 3, METATILE_PokemonCenterFrlg_CounterBarrier, 1
	return

CableClub_EventScript_OpenDirectCornerBarrier_Frlg::
	setmetatile 9, 3, METATILE_PokemonCenterFrlg_Floor_ShadeLeft, 0
	return

CableClub_EventScript_CloseDirectCornerBarrier_Frlg::
	setmetatile 9, 3, METATILE_PokemonCenterFrlg_CounterBarrier, 1
	return

CableClub_EventScript_OpenGameCornerBarrier_Frlg::
	setmetatile 5, 3, METATILE_GameCorner_CheckeredFloor_ShadeLeft, 0
	return

CableClub_EventScript_CloseGameCornerBarrier_Frlg::
	setmetatile 5, 3, METATILE_GameCorner_CounterBarrier, 1
	return

CableClub_OnResume_Frlg::
	special InitUnionRoom
	end

JoyfulGameCorner_EventScript_InfoMan2_Frlg::
	lock
	faceplayer
	message Text_DescribeWhichGame_Frlg
	waitmessage
	multichoice 0, 0, MULTI_WIRELESS_MINIGAME, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_PokemonJumpInfo_Frlg
	case 1, CableClub_EventScript_DodrioBerryPickingInfo_Frlg
	case 2, CableClub_EventScript_MinigameInfoExit_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_MinigameInfoExit_Frlg
	end

CableClub_EventScript_PokemonJumpInfo_Frlg::
	msgbox Text_PokemonJumpInfo_Frlg
	release
	end

CableClub_EventScript_DodrioBerryPickingInfo_Frlg::
	msgbox Text_DodrioBerryPickingInfo_Frlg
	release
	end

CableClub_EventScript_MinigameInfoExit_Frlg::
	msgbox Text_TalkToManToPlay_Frlg
	release
	end

JoyfulGameCorner_EventScript_MinigameAttendant_Frlg::
	lock
	faceplayer
	message Text_WelcomeCanYouWait_Frlg
	waitmessage
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_AdapterNotConnectedMinigame_Frlg
	delay 60
	message Text_PlayWhichGame_Frlg
	waitmessage
	multichoice 0, 0, MULTI_WIRELESS_MINIGAME, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_PlayPokemonJump_Frlg
	case 1, CableClub_EventScript_PlayDodrioBerryPicking_Frlg
	case 2, CableClub_EventScript_AbortMinigame_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_AbortMinigame_Frlg
	end

CableClub_EventScript_PlayPokemonJump_Frlg::
	setvar VAR_0x8005, 0
	special IsPokemonJumpSpeciesInParty
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_NoEligiblePkmn_Frlg
	msgbox Text_EnterWhichPokemon_Frlg
	setvar VAR_0x8005, 0
	special ChooseMonForWirelessMinigame
	goto_if_ge VAR_0x8004, PARTY_SIZE, CableClub_EventScript_AbortMinigame_Frlg
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortMinigame_Frlg
	setvar VAR_0x8004, LINK_GROUP_POKEMON_JUMP
	goto CableClub_EventScript_ChooseLinkLeaderMinigame_Frlg
	end

CableClub_EventScript_PlayDodrioBerryPicking_Frlg::
	setvar VAR_0x8005, 1
	special IsDodrioInParty
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_NoEligiblePkmn_Frlg
	msgbox Text_EnterWhichPokemon_Frlg
	setvar VAR_0x8005, 1
	special ChooseMonForWirelessMinigame
	goto_if_ge VAR_0x8004, PARTY_SIZE, CableClub_EventScript_AbortMinigame_Frlg
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortMinigame_Frlg
	setvar VAR_0x8004, LINK_GROUP_BERRY_PICKING
	goto CableClub_EventScript_ChooseLinkLeaderMinigame_Frlg
	end

CableClub_EventScript_ChooseLinkLeaderMinigame_Frlg::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	message CableClub_Text_ChooseGroupLeader_Frlg
	waitmessage
	call EventScript_RestorePrevTextColor
	multichoice 13, 6, MULTI_LINK_LEADER, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_TryJoinMinigameLinkGroup_Frlg
	case 1, CableClub_EventScript_TryBecomeMinigameLinkLeader_Frlg
	case 2, CableClub_EventScript_AbortMinigame_Frlg
	case MULTI_B_PRESSED, CableClub_EventScript_AbortMinigame_Frlg
	end

CableClub_EventScript_TryBecomeMinigameLinkLeader_Frlg::
	call CableClub_EventScript_TryBecomeLinkLeader_Frlg
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterMinigame_Frlg
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeaderMinigame_Frlg
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryBecomeMinigameLinkLeader_Frlg
	release
	return

CableClub_EventScript_TryJoinMinigameLinkGroup_Frlg::
	call CableClub_EventScript_TryJoinLinkGroup_Frlg
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterMinigame_Frlg
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeaderMinigame_Frlg
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryJoinMinigameLinkGroup_Frlg
	release
	return

CableClub_EventScript_EnterMinigame_Frlg::
	messageautoscroll Text_AllGoodToGo_Frlg
	waitmessage
	delay 120
	closemessage
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call CableClub_EventScript_OpenGameCornerBarrier_Frlg
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement LOCALID_PLAYER, Movement_PlayerEnterMinigameRoom
	waitmovement 0
	hideplayer
	release
	waitstate
	end

CableClub_EventScript_AdapterNotConnectedMinigame_Frlg::
	msgbox Text_AdapterNotConnectedMinigame_Frlg
	release
	end

CableClub_EventScript_NoEligiblePkmn_Frlg::
	msgbox EventScript_ExplainPokemonJumpRequirements_Frlg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CableClub_EventScript_AbortMinigame_Frlg
	call_if_eq VAR_0x8005, 0, CableClub_EventScript_ExplainPokemonJumpRequirements_Frlg
	call_if_eq VAR_0x8005, 1, CableClub_EventScript_ExplainDodrioBerryPickingRequirements_Frlg
	goto CableClub_EventScript_AbortMinigame_Frlg
	end

CableClub_EventScript_ExplainPokemonJumpRequirements_Frlg::
	msgbox Text_ShortJumpingPokemonAllowed_Frlg
	return

CableClub_EventScript_ExplainDodrioBerryPickingRequirements_Frlg::
	msgbox Text_OnlyDodrioAllowed_Frlg
	return

TwoIsland_JoyfulGameCorner_EventScript_ShowPokemonJumpRecords::
	lockall
	special ShowPokemonJumpRecords
	releaseall
	end

TwoIsland_JoyfulGameCorner_EventScript_ShowDodrioBerryPickingRecords::
	lockall
	special ShowDodrioBerryPickingRecords
	releaseall
	end

CableClub_Text_WelcomeWhichCableClubService_Frlg::
	.string "Bienvenue au CENTRE TROC\n"
	.string "du CLUB LINK POKéMON.\p"
	.string "Lequel de nos services\n"
	.string "souhaiteriez-vous utiliser?$"

CableClub_Text_WhichService_Frlg::
	.string "Lequel de nos services\n"
	.string "souhaiteriez-vous utiliser?$"

CableClub_Text_TradeMonsUsingLinkCable_Frlg::
	.string "Echanger ses POKéMON avec un\n"
	.string "câble GBA Game Link.$"

CableClub_Text_BattleUsingLinkCable_Frlg::
	.string "Vous pouvez affronter un autre\n"
	.string "joueur avec un câble Game Link.$"

@ Unused, translated in Emerald
CableClub_Text_CloseThisMenu_Frlg::
	.string "おわります$"

CableClub_Text_NeedTwoMonsForDoubleBattle_Frlg::
	.string "Pour jouer en COMBAT DUO, il faut\n"
	.string "avoir au moins deux POKéMON.$"

CableClub_Text_NeedTwoMonsToTrade_Frlg::
	.string "Pour un échange, \p"
	.string "il faut avoir au moins deux\n"
	.string "POKéMON en sa possession.$"

CableClub_Text_CantTradeEnigmaBerry_Frlg::
	.string "Un POKéMON tenant la BAIE\n"
	.string "{STR_VAR_1} ne peut pas être échangé.$"

CableClub_Text_PleaseWaitBCancel_Frlg::
	.string "Veuillez patienter.\n"
	.string "Bouton B: Annuler$"

CableClub_Text_WhenAllPlayersReadyAConfirmBCancel_Frlg::
	.string "Quand tous les joueurs sont prêts…\n"
	.string "Bouton A: Confirmer\l"
	.string "Bouton B: Annuler$"

CableClub_Text_StartLinkWithXPlayersAConfirmBCancel_Frlg::
	.string "Démarrer connexion entre les {STR_VAR_1}\n"
	.string "joueurs.\l"
	.string "Bouton A: Confirmer\l"
	.string "Bouton B: Annuler$"

CableClub_Text_AwaitingLinkupBCancel_Frlg::
	.string "Connexion en cours…\n"
	.string "Bouton B: Annuler$"

@ Unused, translated in Emerald
CableClub_Text_OkayToSaveProgress_Frlg::
	.string "はじめる　まえに　レポートを\n"
	.string "かきますが　よろしいですか？$"

CableClub_Text_PleaseEnter_Frlg::
	.string "Veuillez entrer.$"

CableClub_Text_DirectYouToYourRoom_Frlg::
	.string "Je vais vous mener à la salle.$"

CableClub_Text_SomeoneIsNotReadyToLink_Frlg::
	.string "Quelqu'un n'est pas prêt à se\n"
	.string "connecter.\p"
	.string "Veuillez revenir une fois que tous\n"
	.string "les joueurs seront prêts.$"

CableClub_Text_LinkErrorPleaseReset_Frlg::
	.string "Erreur de connexion…\n"
	.string "Vérifier les branchements et\l"
	.string "réinitialiser les consoles.$"

CableClub_Text_PlayersMadeDifferentSelections_Frlg::
	.string "Les joueurs connectés semblent\n"
	.string "ne pas avoir fait le même choix.$"

CableClub_Text_PleaseVisitAgain_Frlg::
	.string "Revenez quand vous voulez.$"

CableClub_Text_IncorrectNumberOfParticipants_Frlg::
	.string "Le nombre de participants n'est pas\n"
	.string "correct.$"

CableClub_Text_CantSingleBattleWithXPlayers_Frlg::
	.string "Il est impossible de jouer avec {STR_VAR_1}\n"
	.string "joueurs en mode COMBAT SOLO.$"

CableClub_Text_CantDoubleBattleWithXPlayers_Frlg::
	.string "Il est impossible de jouer avec {STR_VAR_1}\n"
	.string "joueurs en mode COMBAT DUO.$"

CableClub_Text_NeedFourPlayers_Frlg::
	.string "Il faut être quatre joueurs pour\n"
	.string "jouer à ce mode de combat.$"

CableClub_Text_PleaseConfirmNumberAndRestart_Frlg::
	.string "Veuillez confirmer le nombre de\n"
	.string "joueurs et recommencer.$"

Text_TerminateLinkIfYouLeaveRoom_Frlg::
	.string "La connexion prendra fin si vous\n"
	.string "quittez la pièce. Sortir?$"

Text_TerminateLinkConfirmation_Frlg::
	.string "Fin de la connexion. On vous\n"
	.string "conduira à la sortie de la pièce.\l"
	.string "Veuillez patienter.$"

Text_TrainerTooBusyToNotice_Frlg::
	.string "Ce DRESSEUR est trop occupé\n"
	.string "pour vous voir…$"


Text_LookedAtPlayersTrainerCard_Frlg::
	.string "Bravo! Tu peux regarder la CARTE\n"
	.string "DRESSEUR de {STR_VAR_1}!$"

Text_LookedAtPlayersTrainerCardColored_Frlg::
	.string "Bravo! Tu peux regarder la CARTE\n"
	.string "DRESSEUR de {STR_VAR_1}!\p"
	.string "C'est une carte en {STR_VAR_2}!$"

Text_TakeSeatStartBattle_Frlg::
	.string "Veuillez prendre place et\n"
	.string "commencer à combattre.$"

Text_TakeSeatStartTrade_Frlg::
	.string "Veuillez prendre place et\n"
	.string "commencer l'échange.$"

@ Unused, leftover from RS
RecordCorner_Text_ThanksForComing_Frlg::
	.string "ごりよう　ありがとう　ございました$"

CableClub_Text_TrainerCardDataOverwritten_Frlg::
	.string "Les données sur la CARTE DRESSEUR\n"
	.string "vont être écrasées.$"

CableClub_Text_HopeToSeeYouAgain_Frlg::
	.string "A une prochaine fois!$"

CableClub_Text_NotSetUpForFarAwayRegion_Frlg::
	.string "Je suis terriblement désolée.\p"
	.string "Nous ne sommes pas équipés pour\n"
	.string "effectuer des échanges avec des\l"
	.string "DRESSEURS d'une région si lointaine.$"

CableClub_Text_OtherTrainerNotReady_Frlg::
	.string "L'autre DRESSEUR n'est pas prêt.$"

CableClub_Text_YouHaveAMonThatCantBeTaken_Frlg::
	.string "Au moins un POKéMON ne peut\n"
	.string "pas être pris.$"

CableClub_Text_AdapterNotConnected_Frlg::
	.string "L'adaptateur sans fil GBA n'est pas\n"
	.string "connecté correctement.$"

CableClub_Text_ParticipantsStepUpToCounter_Frlg::
	.string "Les participants doivent se\n"
	.string "présenter à la réception.$"

@ Unused, translated in Emerald
CableClub_Text_Hello_Frlg::
	.string "こんにちは！$"

@ Unused, translated in Emerald
CableClub_Text_PleaseWait_Frlg::
	.string "しょうしょう　おまちください$"

CableClub_Text_YouMayTradeHere_Frlg::
	.string "Vous pouvez y faire des échanges\n"
	.string "de POKéMON avec un ami.$"

CableClub_Text_YouMayBattleHere_Frlg::
	.string "Vous pouvez affronter vos amis ici.$"

CableClub_Text_CanMakeBerryPowder_Frlg::
	.string "De deux à cinq DRESSEURS peuvent\n"
	.string "faire de la POUDRE BAIE ensemble.$"

@ Unused, Record Mix nopped
CableClub_Text_CanMixRecords_Frlg::
	.string "ワイヤレス　クラブでの\n"
	.string "あそびかたを　せつめいします$"

CableClub_Text_CancelSelectedItem_Frlg::
	.string "Annule le MENU sélectionné.$"

@ Unused, translated in Emerald
CableClub_Text_WhichBattleMode_Frlg::
	.string "どちらの　しょうぶに　しますか？$"

@ Unused, translated in Emerald
CableClub_Text_ReturnsToPreviousStep_Frlg::
	.string "ひとつ　まえに　もどります$"

CableClub_Text_NeedBerryForBerryCrush_Frlg::
	.string "Pour utiliser le BROYEUR DE BAIES,\n"
	.string "il faut avoir au moins une BAIE.$"

CableClub_Text_NeedTwoMonsForUnionRoom_Frlg::
	.string "Pour entrer dans la SALLE UNION,\n"
	.string "il faut avoir au moins deux PKMN.$"

CableClub_Text_NoEnigmaBerryInUnionRoom_Frlg::
	.string "Un PKMN tenant la BAIE {STR_VAR_1} ne\n"
	.string "peut entrer dans la SALLE UNION.$"

CableClub_Text_UnionRoomAdapterNotConnected_Frlg::
	.string "C'est la SALLE UNION du\n"
	.string "CLUB SANS FIL POKéMON.\p"
	.string "Votre adaptateur sans fil GBA\n"
	.string "n'est pas connecté correctement.\p"
	.string "Revenez plus tard.$"

Text_PlayerIsPlayingRightNowGoForIt_Frlg::
	.string "On dirait que {STR_VAR_1} est en\n"
	.string "train de jouer.\l"
	.string "Allez-y!$"

Text_DescribeWhichGame_Frlg::
	.string "Je peux vous expliquer les règles\n"
	.string "du jeu, si vous le souhaitez.\p"
	.string "Vous voulez des infos sur\n"
	.string "quel jeu?$"

Text_PokemonJumpInfo_Frlg::
	.string "SAUT POKéMON\p"
	.string "Faites sauter votre POKéMON à\n"
	.string "la corde avec le bouton A.\p"
	.string "Seuls les POKéMON jusqu'à\n"
	.string "environ 70 cm peuvent participer.\p"
	.string "Les POKéMON capables seulement\n"
	.string "de nager, creuser ou voler\p"
	.string "ne sont pas vraiment bons au saut\n"
	.string "et ne peuvent donc pas participer.\p"
	.string "Des choses intéressantes arrivent\n"
	.string "si tout le monde saute en rythme.$"

Text_DodrioBerryPickingInfo_Frlg::
	.string "ATTRAPE-BAIES DODRIO\p"
	.string "Faites bouger les têtes de DODRIO\n"
	.string "pour attraper les BAIES.\p"
	.string "Appuyez sur gauche, haut et droite\n"
	.string "sur la manette {PLUS}.\p"
	.string "Pour jouer à ce jeu, vous devez\n"
	.string "avoir un DODRIO.$"

Text_TalkToManToPlay_Frlg::
	.string "Si vous voulez commencer un jeu,\n"
	.string "allez voir l'homme à côté.$"

Text_WelcomeCanYouWait_Frlg::
	.string "Salut! Vous pouvez jouer en\n"
	.string "utilisant le système de\l"
	.string "communication sans fil.\p"
	.string "Vous pouvez patienter encore\n"
	.string "un petit peu? $"

CableClub_Text_ComeAgain_Frlg::
	.string "Très bien, à bientôt.$"

Text_AdapterNotConnectedMinigame_Frlg::
	.string "L'adaptateur sans fil GBA n'est\n"
	.string "pas connecté.\p"
	.string "Revenez quand il sera branché!$"

Text_PlayWhichGame_Frlg::
	.string "Très bien, quel jeu\n"
	.string "voulez-vous commencer?$"

Text_EnterWhichPokemon_Frlg::
	.string "Quel POKéMON choisissez-vous?$"

Text_AllGoodToGo_Frlg::
	.string "Parfait, ça va bientôt commencer.\n"
	.string "Ne vous faites pas battre.$"

@ Unused, translated in Emerald
Text_LeavingDoComeAgain_Frlg::
	.string "きょうは　けえるのか？\n"
	.string "またこいよ！$"

EventScript_ExplainPokemonJumpRequirements_Frlg::
	.string "Aucun de vos POKéMON ne peut\n"
	.string "participer…\p"
	.string "Voulez-vous savoir quels POKéMON\n"
	.string "peuvent participer?$"

Text_ShortJumpingPokemonAllowed_Frlg::
	.string "Le SAUT POKéMON est ouvert aux\n"
	.string "POKéMON jusqu'à environ 70 cm.\p"
	.string "Les POKéMON ne pouvant pas sauter\n"
	.string "ne peuvent pas participer.\p"
	.string "Comme ceux qui ne peuvent que\n"
	.string "nager, voler ou creuser.\p"
	.string "Voilà, c'est tout ce qu'il faut\n"
	.string "savoir.$"

Text_OnlyDodrioAllowed_Frlg::
	.string "ATTRAPE-BAIES DODRIO\n"
	.string "Le nom parle de lui-même.\p"
	.string "Il vous faut un DODRIO pour\n"
	.string "participer.$"

@ Unused, translated in Emerald
Text_RetryFromStartPlease_Frlg::
	.string "もういちど　はじめから\n"
	.string "やりなおして　みて　くれ$"

CableClub_Text_WelcomeWhichDirectCornerRoom_Frlg::
	.string "Bienvenue au CLUB SANS FIL\n"
	.string "POKéMON.\p"
	.string "Vous pouvez communiquer avec\n"
	.string "vos amis à partir d'ici.\p"
	.string "A quelle salle voulez-vous\n"
	.string "accéder?$"

CableClub_Text_TradePokemon_Frlg::
	.string "Voulez-vous échanger un POKéMON?$"

CableClub_Text_PlayWhichBattleMode_Frlg::
	.string "A quel mode de combat\n"
	.string "voulez-vous jouer?$"

CableClub_Text_UseBerryCrush_Frlg::
	.string "Voulez-vous utiliser le\n"
	.string "BROYEUR DE BAIES?$"

CableClub_Text_ExplainBattleModes_Frlg::
	.string "Il existe trois modes de combat.\p"
	.string "En COMBAT SOLO, deux DRESSEURS\n"
	.string "avec au moins un POKéMON chacun\l"
	.string "combattent.\p"
	.string "Chaque DRESSEUR ne peut envoyer\n"
	.string "qu'un seul POKéMON à la fois au\l"
	.string "combat. \p"
	.string "En COMBAT DUO, deux DRESSEURS\n"
	.string "avec au moins deux POKéMON chacun\l"
	.string "combattent.\p"
	.string "Chaque DRESSEUR envoie au combat\n"
	.string "deux POKéMON en même temps.\p"
	.string "En COMBAT MULTI, quatre DRESSEURS\n"
	.string "avec au moins un POKéMON chacun\l"
	.string "combattent.\p"
	.string "Chaque DRESSEUR ne peut envoyer\n"
	.string "qu'un seul POKéMON à la fois au\l"
	.string "combat.$"

CableClub_Text_ChooseGroupLeaderOfTwo_Frlg::
	.string "Veuillez choisir lequel de vous\n"
	.string "deux sera le MENEUR.\p"
	.string "L'autre joueur devra ensuite\n"
	.string "choisir “JOINDRE”.$"

CableClub_Text_ChooseGroupLeaderOfFour_Frlg::
	.string "Veuillez choisir lequel d'entre\n"
	.string "vous sera le MENEUR du GROUPE.\p"
	.string "Les autres joueurs devront ensuite\n"
	.string "choisir “JOINDRE”.$"

CableClub_Text_ChooseGroupLeader_Frlg::
	.string "Veuillez choisir lequel d'entre\n"
	.string "vous sera le MENEUR du GROUPE.\p"
	.string "Les autres joueurs devront ensuite\n"
	.string "choisir “JOINDRE”.$"

CableClub_Text_WelcomeUnionRoomEnter_Frlg::
	.string "Bienvenue à la SALLE UNION du\n"
	.string "CLUB SANS FIL POKéMON.\p"
	.string "Vous pouvez y communiquer avec\n"
	.string "d'autres DRESSEURS. Même avec\l"
	.string "ceux que vous ne connaissez pas.$"

CableClub_Text_UnionRoomInfo_Frlg::
	.string "Les DRESSEURS dans la SALLE\n"
	.string "UNION sont ceux autour de vous qui\l"
	.string "ont aussi pénétré dans la salle.\p"
	.string "Vous pouvez faire plein de choses\n"
	.string "ici, comme par exemple discuter.\p"
	.string "Vous pouvez faire entrer 2 POKéMON\n"
	.string "jusqu'au niveau 30 pour un combat\p"
	.string "un contre un. Vous pouvez aussi\n"
	.string "participer à des tchats\p"
	.string "réunissant de 2 à 5 personnes.\p"
	.string "Ou vous pouvez encore enregistrer\n"
	.string "un POKéMON pour un échange.\p"
	.string "Voulez-vous entrer dans la SALLE?$"

CableClub_Text_EnjoyUnionRoom_Frlg::
	.string "J'espère que vous aimerez votre\n"
	.string "visite dans la SALLE UNION.$"

CableClub_Text_FirstTimeRightThisWay_Frlg::
	.string "Bonjour!\n"
	.string "Je suis ZADIA.\p"
	.string "C'est la première fois que je\n"
	.string "vous vois ici.\p"
	.string "Je vais vous montrer comment le\n"
	.string "système sans fil fonctionne.\p"
	.string "Je dois d'abord vous faire visiter\n"
	.string "cet étage du CENTRE POKéMON.\p"
	.string "Par ici, s'il vous plaît.$"

CableClub_Text_ExplainWirelessClubFirstTime_Frlg::
	.string "Au niveau supérieur, il y a\n"
	.string "deux salles.\p"
	.string "Tout d'abord, la salle à gauche\n"
	.string "est la SALLE UNION.\p"
	.string "Vous pouvez vous connecter avec\n"
	.string "les DRESSEURS autour de vous\l"
	.string "qui sont dans la SALLE UNION.\p"
	.string "Vous pouvez parler, faire des\n"
	.string "échanges ou combattre avec eux.\p"
	.string "Ensuite, la salle à droite\n"
	.string "est la SALLE LINK DIRECT. \p"
	.string "Vous pouvez combattre ou faire\n"
	.string "des échanges avec vos amis.\p"
	.string "Si l'adaptateur sans fil n'est pas\n"
	.string "utilisé, vous pouvez toujours vous\l"
	.string "connecter avec un câble Game Link.\p"
	.string "Si c'est le cas, allez directement\n"
	.string "dans la SALLE LINK DIRECT.\p"
	.string "J'espère que vous apprécierez\n"
	.string "le système sans fil.$"

CableClub_Text_AskAboutLinking_Frlg::
	.string "Bonjour {PLAYER}!\p"
	.string "Je suis ZADIA, je m'occupe du 1er\n"
	.string "étage du CENTRE POKéMON.\p"
	.string "Y a-t-il quelque chose que vous\n"
	.string "aimeriez savoir sur la connexion?$"

CableClub_Text_ExplainWirelessClub_Frlg::
	.string "Laissez-moi vous décrire le\n"
	.string "CLUB SANS FIL POKéMON.\p"
	.string "Au niveau supérieur, il y a\n"
	.string "deux salles.\p"
	.string "Tout d'abord, la salle à gauche\n"
	.string "est la SALLE UNION.\p"
	.string "Vous pouvez vous connecter avec\n"
	.string "les DRESSEURS autour de vous\l"
	.string "qui sont dans la SALLE UNION.\p"
	.string "Vous pouvez parler, faire des\n"
	.string "échanges ou combattre avec eux.\p"
	.string "Ensuite, la salle à droite\n"
	.string "est la SALLE LINK DIRECT. \p"
	.string "Vous pouvez combattre ou faire\n"
	.string "des échanges avec vos amis.\p"
	.string "Dans certains cas, vous ne\n"
	.string "pourrez vous connecter avec\l"
	.string "vos amis dans aucune des salles.\p"
	.string "Si c'est le cas, rapprochez-vous\n"
	.string "de vos amis.\p"
	.string "Si l'adaptateur sans fil n'est pas\n"
	.string "utilisé, vous pouvez toujours vous\l"
	.string "connecter avec un câble Game Link.\p"
	.string "Si c'est le cas, allez directement\n"
	.string "dans la SALLE LINK DIRECT.\p"
	.string "J'espère que vous apprécierez\n"
	.string "le système sans fil.$"

CableClub_Text_HopeYouEnjoyWirelessSystem_Frlg::
	.string "J'espère que vous apprécierez\n"
	.string "le système sans fil.$"

Text_WirelessClubUndergoingAdjustments::
	.string "Je suis vraiment désolée.\p"
	.string "Le CLUB SANS FIL POKéMON\n"
	.string "est encore en préparation.$"

Text_AppearsToBeUndergoingAdjustments::
	.string "Ils sont en train d'effectuer\n"
	.string "des réglages…$"

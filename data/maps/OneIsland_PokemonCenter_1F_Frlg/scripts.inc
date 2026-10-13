OneIsland_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OneIsland_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	map_script MAP_SCRIPT_ON_LOAD, OneIsland_PokemonCenter_1F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OneIsland_PokemonCenter_1F_OnFrame
	.byte 0

OneIsland_PokemonCenter_1F_OnLoad::
	call_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, OneIsland_PokemonCenter_1F_EventScript_SetRubyMetatile
	call_if_set FLAG_IS_CHAMPION, OneIsland_PokemonCenter_1F_EventScript_SetNetworkMachineOn
	end

OneIsland_PokemonCenter_1F_EventScript_SetRubyMetatile::
	setmetatile 13, 4, METATILE_PokemonCenterFrlg_NetworkMachine_Ruby, 1
	return

OneIsland_PokemonCenter_1F_EventScript_SetSapphireMetatile::
	setmetatile 16, 4, METATILE_PokemonCenterFrlg_NetworkMachine_Sapphire, 1
	return

OneIsland_PokemonCenter_1F_EventScript_SetNetworkMachineOn::
	call OneIsland_PokemonCenter_1F_EventScript_SetSapphireMetatile
	setmetatile 14, 4, METATILE_PokemonCenterFrlg_NetworkMachine_ScreenLeft_On, 1
	setmetatile 15, 4, METATILE_PokemonCenterFrlg_NetworkMachine_ScreenRight_On, 1
	return

OneIsland_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_ONE_ISLAND
	call_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 6, OneIsland_PokemonCenter_1F_EventScript_SetCelioQuestDone
	call_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 0, OneIsland_PokemonCenter_1F_EventScript_SetBillCelioFirstMeetingPos
	call_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 2, OneIsland_PokemonCenter_1F_EventScript_SetBillCelioReadyToLeavePos
	end

OneIsland_PokemonCenter_1F_EventScript_SetCelioQuestDone::
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 7
	return

OneIsland_PokemonCenter_1F_EventScript_SetBillCelioFirstMeetingPos::
	setobjectxyperm LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, 9, 8
	setobjectmovementtype LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, MOVEMENT_TYPE_FACE_UP
	setobjectxyperm LOCALID_CELIO, 15, 6
	setobjectmovementtype LOCALID_CELIO, MOVEMENT_TYPE_FACE_UP
	return

OneIsland_PokemonCenter_1F_EventScript_SetBillCelioReadyToLeavePos::
	setobjectxyperm LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, 14, 7
	setobjectmovementtype LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm LOCALID_CELIO, 14, 8
	setobjectmovementtype LOCALID_CELIO, MOVEMENT_TYPE_FACE_LEFT
	return

OneIsland_PokemonCenter_1F_OnFrame::
	map_script_2 VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 0, OneIsland_PokemonCenter_1F_EventScript_MeetCelioScene
	.2byte 0

OneIsland_PokemonCenter_1F_EventScript_MeetCelioScene::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerWalkToCelio
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, OneIsland_PokemonCenter_1F_Movement_BillWalkToCelio
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_BillHeyThereCelio
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_CELIO, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_CELIO, Common_Movement_Delay48
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CelioCantBelieveYouCameOut
	msgbox OneIsland_PokemonCenter_1F_Text_BillHowsYourResearchComing
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_ThisIsMyBuddyCelio
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	call_if_set FLAG_SYS_GAME_CLEAR, OneIsland_PokemonCenter_1F_EventScript_IntroducePlayerChamp
	call_if_unset FLAG_SYS_GAME_CLEAR, OneIsland_PokemonCenter_1F_EventScript_IntroducePlayerNotChamp
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CelioThatsReallyImpressive
	msgbox OneIsland_PokemonCenter_1F_Text_BillBringMeUpToSpeed
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CelioPCsCantLinkWithYours
	closemessage
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_BillLetMeHelpYou
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CanYouDeliverThisMeteoritePlayer
	msgreceiveditem OneIsland_PokemonCenter_1F_Text_AcceptedMeteoriteFromBill, ITEM_METEORITE, 1, MUS_RG_OBTAIN_KEY_ITEM
	additem ITEM_METEORITE
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CelioPleaseTakeThis
	giveitem_msg OneIsland_PokemonCenter_1F_Text_ObtainedTriPass, ITEM_TRI_PASS, 1, MUS_RG_OBTAIN_KEY_ITEM
	msgbox OneIsland_PokemonCenter_1F_Text_PassLetsYouTravelBetweenIslands
	call_if_ge VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, OneIsland_PokemonCenter_1F_EventScript_ReceiveTownMapPage
	call_if_lt VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, OneIsland_PokemonCenter_1F_EventScript_ReceiveTownMap
	setflag FLAG_SYS_SEVII_MAP_123
	msgbox OneIsland_PokemonCenter_1F_Text_BillCatchYouLater
	closemessage
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	setflag FLAG_SYS_PC_STORAGE_DISABLED
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1
	releaseall
	end

OneIsland_PokemonCenter_1F_EventScript_IntroducePlayerChamp::
	msgbox OneIsland_PokemonCenter_1F_Text_PlayerIsReigningPokemonChamp
	return

OneIsland_PokemonCenter_1F_EventScript_IntroducePlayerNotChamp::
	msgbox OneIsland_PokemonCenter_1F_Text_PlayerIsRisingPokemonChamp
	return

OneIsland_PokemonCenter_1F_EventScript_ReceiveTownMapPage::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message OneIsland_PokemonCenter_1F_Text_ReceivedExtraPageForTownMap
	waitmessage
	waitfanfare
	call EventScript_RestorePrevTextColor
	return

OneIsland_PokemonCenter_1F_EventScript_ReceiveTownMap::
	setflag FLAG_HIDE_TOWN_MAP
	setvar VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2
	giveitem_msg OneIsland_PokemonCenter_1F_Text_ReceivedTownMap, ITEM_TOWN_MAP, 1, MUS_RG_OBTAIN_KEY_ITEM
	return

OneIsland_PokemonCenter_1F_Movement_PlayerWalkToCelio::
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

OneIsland_PokemonCenter_1F_Movement_BillWalkToCelio::
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_in_place_faster_right
	step_end

@ Unused
OneIsland_PokemonCenter_1F_Movement_WalkUp:
	walk_up
	step_end

@ Unused
OneIsland_PokemonCenter_1F_Movement_StepAsideLeft::
	walk_left
	walk_in_place_faster_right
	step_end

OneIsland_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

OneIsland_PokemonCenter_1F_EventScript_Bill::
	lock
	goto_if_set FLAG_SEVII_DETOUR_FINISHED, OneIsland_PokemonCenter_1F_EventScript_BillGoTakeStroll
	msgbox OneIsland_PokemonCenter_1F_Text_HmmHowAboutLikeThis
	release
	end

OneIsland_PokemonCenter_1F_EventScript_BillGoTakeStroll::
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_FacePlayer
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_GotPCWorkingStrollAWhileMore
	release
	end

OneIsland_PokemonCenter_1F_EventScript_Celio::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 7, OneIsland_PokemonCenter_1F_EventScript_CelioGiveBillFact
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 6, OneIsland_PokemonCenter_1F_EventScript_CelioJustGivenSapphire
	goto_if_set FLAG_RECOVERED_SAPPHIRE, OneIsland_PokemonCenter_1F_EventScript_GiveCelioSapphire
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, OneIsland_PokemonCenter_1F_EventScript_ExplainRainbowPass
	goto_if_set FLAG_GOT_RUBY, OneIsland_PokemonCenter_1F_EventScript_GiveCelioRuby
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 4, OneIsland_PokemonCenter_1F_EventScript_CelioWaitingForRuby
	specialvar VAR_RESULT, IsNationalPokedexEnabled
	goto_if_eq VAR_RESULT, TRUE, OneIsland_PokemonCenter_1F_EventScript_CelioRequestRuby
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 3, OneIsland_PokemonCenter_1F_EventScript_CelioPlayerMissingNationalDex
	msgbox OneIsland_PokemonCenter_1F_Text_SorryForBeingPoorHost
	closemessage
	applymovement LOCALID_CELIO, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

OneIsland_PokemonCenter_1F_EventScript_CelioGiveBillFact::
	msgbox OneIsland_PokemonCenter_1F_Text_CelioHearingRumorsAboutYou
	random 3
	goto_if_eq VAR_RESULT, 0, OneIsland_PokemonCenter_1F_EventScript_BillFact1
	goto_if_eq VAR_RESULT, 1, OneIsland_PokemonCenter_1F_EventScript_BillFact2
	famechecker FAMECHECKER_BILL, 5
	msgbox OneIsland_PokemonCenter_1F_Text_BillCantStomachMilk
	release
	end

OneIsland_PokemonCenter_1F_EventScript_BillFact1::
	famechecker FAMECHECKER_BILL, 3
	msgbox OneIsland_PokemonCenter_1F_Text_BillsFirstMonWasAbra
	release
	end

OneIsland_PokemonCenter_1F_EventScript_BillFact2::
	famechecker FAMECHECKER_BILL, 4
	msgbox OneIsland_PokemonCenter_1F_Text_BillsHometownInGoldenrod
	release
	end

OneIsland_PokemonCenter_1F_EventScript_CelioJustGivenSapphire::
	msgbox OneIsland_PokemonCenter_1F_Text_WishYouBestOfLuck
	release
	end

OneIsland_PokemonCenter_1F_EventScript_GiveCelioSapphire::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_OBTAIN_TMHM
	message OneIsland_PokemonCenter_1F_Text_HandedSapphireToCelio
	waitmessage
	waitfanfare
	call EventScript_RestorePrevTextColor
	removeitem ITEM_SAPPHIRE
	msgbox OneIsland_PokemonCenter_1F_Text_ThankYouGiveMeTime
	closemessage
	applymovement LOCALID_CELIO, OneIsland_PokemonCenter_1F_Movement_CelioPutGemInMachine
	waitmovement 0
	playse SE_CLICK
	call OneIsland_PokemonCenter_1F_EventScript_SetSapphireMetatile
	special DrawWholeMapView
	msgbox OneIsland_PokemonCenter_1F_Text_OkayThisIsGood
	closemessage
	delay 60
	applymovement LOCALID_CELIO, OneIsland_PokemonCenter_1F_Movement_CelioCheckMachine
	waitmovement 0
	delay 30
	applymovement LOCALID_CELIO, OneIsland_PokemonCenter_1F_Movement_CelioCheckMachine
	waitmovement 0
	delay 40
	playse SE_PC_ON
	call OneIsland_PokemonCenter_1F_EventScript_SetNetworkMachineOn
	special DrawWholeMapView
	msgbox OneIsland_PokemonCenter_1F_Text_LinkedUpWithLanette
	applymovement LOCALID_CELIO, Common_Movement_FacePlayer
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_ManagedToLinkWithHoennThankYou
	special SetPostgameFlags
	setflag FLAG_IS_CHAMPION
	setflag FLAG_HIDE_CERULEAN_CAVE_GUARD
	setflag FLAG_HIDE_LORELEI_IN_HER_HOUSE
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 6
	special InitRoamer
	release
	end

OneIsland_PokemonCenter_1F_EventScript_ExplainRainbowPass::
	msgbox OneIsland_PokemonCenter_1F_Text_PassLetYouGetToAllIslands
	release
	end

OneIsland_PokemonCenter_1F_EventScript_GiveCelioRuby::
	msgbox OneIsland_PokemonCenter_1F_Text_OhThats
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_OBTAIN_TMHM
	message OneIsland_PokemonCenter_1F_Text_HandedRubyToCelio
	waitmessage
	waitfanfare
	call EventScript_RestorePrevTextColor
	closemessage
	applymovement LOCALID_CELIO, OneIsland_PokemonCenter_1F_Movement_CelioPutGemInMachine
	waitmovement 0
	playse SE_CLICK
	call OneIsland_PokemonCenter_1F_EventScript_SetRubyMetatile
	special DrawWholeMapView
	delay 30
	applymovement LOCALID_CELIO, Common_Movement_FacePlayer
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_MayIAskOneMoreFavor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OneIsland_PokemonCenter_1F_EventScript_DeclineHelpCelio
	goto OneIsland_PokemonCenter_1F_EventScript_GiveRainbowPass
	end

OneIsland_PokemonCenter_1F_EventScript_DeclineHelpCelio::
	msgbox OneIsland_PokemonCenter_1F_Text_PleaseINeedYourHelp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OneIsland_PokemonCenter_1F_EventScript_DeclineHelpCelio
	goto OneIsland_PokemonCenter_1F_EventScript_GiveRainbowPass
	end

OneIsland_PokemonCenter_1F_EventScript_GiveRainbowPass::
	msgbox OneIsland_PokemonCenter_1F_Text_AnotherGemstoneInSeviiIslands
	removeitem ITEM_RUBY
	removeitem ITEM_TRI_PASS
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5
	additem ITEM_RAINBOW_PASS
	setflag FLAG_SYS_SEVII_MAP_4567
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message OneIsland_PokemonCenter_1F_Text_ReturnedTriPassForRainbowPass
	waitmessage
	waitfanfare
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message OneIsland_PokemonCenter_1F_Text_ObtainedExtraMapPage
	waitmessage
	waitfanfare
	call EventScript_RestorePrevTextColor
	goto OneIsland_PokemonCenter_1F_EventScript_ExplainRainbowPass
	end

OneIsland_PokemonCenter_1F_EventScript_CelioWaitingForRuby::
	msgbox OneIsland_PokemonCenter_1F_Text_TryingToFindGem
	release
	end

OneIsland_PokemonCenter_1F_EventScript_CelioRequestRuby::
	msgbox OneIsland_PokemonCenter_1F_Text_CelioCaughtMoreMonMaybeICanBeUseful
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_YoullBeTradingFromTrainersFarAway
	applymovement LOCALID_CELIO, Common_Movement_FacePlayer
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_NeedsSpecialGemstone
	setvar VAR_MAP_SCENE_MT_EMBER_EXTERIOR, 1
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 4
	release
	end

OneIsland_PokemonCenter_1F_EventScript_CelioPlayerMissingNationalDex::
	msgbox OneIsland_PokemonCenter_1F_Text_CelioImModifyingMyNetworkMachine
	release
	end

OneIsland_PokemonCenter_1F_Movement_CelioCheckMachine::
	walk_in_place_up
	delay_8
	walk_in_place_up
	step_end

OneIsland_PokemonCenter_1F_Movement_CelioPutGemInMachine::
	walk_in_place_faster_up
	walk_in_place_up
	delay_16
	walk_in_place_up
	walk_in_place_up
	step_end

OneIsland_PokemonCenter_1F_EventScript_LittleBoy::
	msgbox OneIsland_PokemonCenter_1F_Text_CameFromPalletDontKnowIt, MSGBOX_NPC
	end

OneIsland_PokemonCenter_1F_EventScript_Hiker::
	msgbox OneIsland_PokemonCenter_1F_Text_EnormousVolcanoOnIsland, MSGBOX_NPC
	end

OneIsland_PokemonCenter_1F_EventScript_BattleGirl::
	lock
	faceplayer
	goto_if_set FLAG_IS_CHAMPION, OneIsland_PokemonCenter_1F_EventScript_BattleGirlHoennLinked
	msgbox OneIsland_PokemonCenter_1F_Text_WishICouldTradeWithBoyfriend
	release
	end

OneIsland_PokemonCenter_1F_EventScript_BattleGirlHoennLinked::
	msgbox OneIsland_PokemonCenter_1F_Text_TradedWithFarAwayBoyfriend
	release
	end

OneIsland_PokemonCenter_1F_EventScript_NetworkMachine::
	lockall
	goto_if_set FLAG_IS_CHAMPION, OneIsland_PokemonCenter_1F_EventScript_NetworkMachineLinkedWithHoenn
	goto_if_set FLAG_SEVII_DETOUR_FINISHED, OneIsland_PokemonCenter_1F_EventScript_NetworkMachineLinkedWithKanto
	msgbox OneIsland_PokemonCenter_1F_Text_MachineUnderAdjustment
	releaseall
	end

OneIsland_PokemonCenter_1F_EventScript_NetworkMachineLinkedWithKanto::
	msgbox OneIsland_PokemonCenter_1F_Text_MachineLinkedWithKanto
	releaseall
	end

OneIsland_PokemonCenter_1F_EventScript_NetworkMachineLinkedWithHoenn::
	msgbox OneIsland_PokemonCenter_1F_Text_MachineLinkedWithKantoAndHoenn
	releaseall
	end

OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandTriggerTop::
	lockall
	setvar VAR_TEMP_1, 1
	goto OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandScene
	end

OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandTriggerMidTop::
	lockall
	setvar VAR_TEMP_1, 2
	goto OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandScene
	end

OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandTriggerMidBottom::
	lockall
	setvar VAR_TEMP_1, 3
	goto OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandScene
	end

OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 4
	goto OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandScene
	end

OneIsland_PokemonCenter_1F_EventScript_LeaveOneIslandScene::
	textcolor NPC_TEXT_COLOR_MALE
	playse SE_PIN
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_BillOhHeyPlayer
	closemessage
	call_if_eq VAR_TEMP_1, 1, OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillTop
	call_if_eq VAR_TEMP_1, 2, OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillMidTop
	call_if_eq VAR_TEMP_1, 3, OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillMidBottom
	call_if_eq VAR_TEMP_1, 4, OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillBottom
	delay 10
	msgbox OneIsland_PokemonCenter_1F_Text_BillWeGotItDone
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CelioJobWentQuick
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_BillYouveLearnedALot
	msgbox OneIsland_PokemonCenter_1F_Text_CelioOhReallyEhehe
	closemessage
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 10
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 15
	msgbox OneIsland_PokemonCenter_1F_Text_BillWeShouldHeadBackToKanto
	closemessage
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 15
	applymovement LOCALID_CELIO, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox OneIsland_PokemonCenter_1F_Text_CelioPromiseIllShowYouAroundSometime
	closemessage
	delay 25
	applymovement LOCALID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerExit
	applymovement LOCALID_ONE_ISLAND_POKEMON_CENTER_BILL, OneIsland_PokemonCenter_1F_Movement_BillExit
	waitmovement 0
	playse SE_EXIT
	setflag FLAG_HIDE_ONE_ISLAND_POKECENTER_BILL
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 3
	clearflag FLAG_HIDE_CINNABAR_BILL
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND, 3
	setvar VAR_0x8004, SEAGALLOP_ONE_ISLAND
	setvar VAR_0x8006, SEAGALLOP_CINNABAR_ISLAND
	goto EventScript_SetSail
	end

OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillTop::
	applymovement LOCALID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillTop
	waitmovement 0
	return

OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillMidTop::
	applymovement LOCALID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillMidTop
	waitmovement 0
	return

OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillMidBottom::
	applymovement LOCALID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillMidBottom
	waitmovement 0
	return

OneIsland_PokemonCenter_1F_EventScript_PlayerWalkToBillBottom::
	applymovement LOCALID_PLAYER, OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillBottom
	waitmovement 0
	return

OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillTop::
	walk_right
	walk_down
	walk_in_place_faster_right
	step_end

OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillMidTop::
	walk_right
	step_end

OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillMidBottom::
	walk_right
	walk_up
	walk_in_place_faster_right
	step_end

OneIsland_PokemonCenter_1F_Movement_PlayerWalkToBillBottom::
	walk_right
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

@ Unused
OneIsland_PokemonCenter_1F_Movement_DelayWalkInPlaceLeft::
	delay_16
	delay_16
	delay_4
	walk_in_place_faster_left
	step_end

@ Unused
OneIsland_PokemonCenter_1F_Movement_WalkInPlaceDown::
	walk_in_place_fast_down
	step_end

OneIsland_PokemonCenter_1F_Movement_PlayerExit::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

OneIsland_PokemonCenter_1F_Movement_BillExit::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

OneIsland_PokemonCenter_1F_Text_BillHeyThereCelio::
	.string "LEO: Salut CILEO!$"

OneIsland_PokemonCenter_1F_Text_CelioCantBelieveYouCameOut::
	.string "CILEO: LEO!\p"
	.string "J'arrive pas à croire que tu\n"
	.string "sois venu.$"

OneIsland_PokemonCenter_1F_Text_BillHowsYourResearchComing::
	.string "LEO: Eh bien oui, je suis là.\p"
	.string "Alors, comment avancent tes\n"
	.string "recherches?\p"
	.string "… Oh, une seconde!$"

OneIsland_PokemonCenter_1F_Text_ThisIsMyBuddyCelio::
	.string "Il faut que je vous présente.\n"
	.string "{PLAYER}, voilà mon ami CILEO.\p"
	.string "C'est un fou d'informatique.$"

OneIsland_PokemonCenter_1F_Text_PlayerIsRisingPokemonChamp::
	.string "CILEO, je te présente {PLAYER}.\p"
	.string "{PLAYER} sera très bientôt un grand\n"
	.string "CHAMPION, j'en suis sûr!$"

OneIsland_PokemonCenter_1F_Text_PlayerIsReigningPokemonChamp::
	.string "CILEO, je te présente {PLAYER}.\n"
	.string "Le CHAMPION en titre.$"

OneIsland_PokemonCenter_1F_Text_CelioThatsReallyImpressive::
	.string "CILEO: Impressionnant.\p"
	.string "Je dois bien avouer que je ne\n"
	.string "suis pas doué pour le combat.\p"
	.string "En tout cas, je suis ravi de te\n"
	.string "rencontrer.$"

OneIsland_PokemonCenter_1F_Text_BillBringMeUpToSpeed::
	.string "LEO: Bon, dis-moi tout.\n"
	.string "Comment fonctionne ta machine?$"

OneIsland_PokemonCenter_1F_Text_CelioPCsCantLinkWithYours::
	.string "CILEO: Plutôt pas mal.\p"
	.string "Mais le problème c'est que nous\n"
	.string "sommes éloignés de tout ici.\p"
	.string "Et le PC ne peut pas se connecter\n"
	.string "au tien, LEO.$"

OneIsland_PokemonCenter_1F_Text_BillLetMeHelpYou::
	.string "LEO: Ah oui?\n"
	.string "Laisse-moi jeter un œil.\p"
	.string "… Hum…\n"
	.string "Je crois que ça peut s'arranger.\p"
	.string "Tu veux bien que je t'aide?$"

OneIsland_PokemonCenter_1F_Text_CanYouDeliverThisMeteoritePlayer::
	.string "{PLAYER}, est-ce que je peux te\n"
	.string "demander d'attendre un peu?\p"
	.string "En fait, j'ai même un service à\n"
	.string "te demander.\p"
	.string "L'île voisine s'appelle l'ILE 2.\p"
	.string "Il y a un type qui dirige la\n"
	.string "SALLE DE JEU, c'est un\p"
	.string "passionné de pierres précieuses\n"
	.string "et de roches rares.\p"
	.string "Est-ce que tu pourrais lui\n"
	.string "apporter ce METEORITE?$"

OneIsland_PokemonCenter_1F_Text_AcceptedMeteoriteFromBill::
	.string "{PLAYER} accepte de prendre le\n"
	.string "METEORITE.$"

OneIsland_PokemonCenter_1F_Text_CelioPleaseTakeThis::
	.string "CILEO: {PLAYER}, si tu vas sur\n"
	.string "l'ILE 2, prends ça avec toi.$"

OneIsland_PokemonCenter_1F_Text_PassLetsYouTravelBetweenIslands::
	.string "C'est un PASSE pour le ferry\n"
	.string "reliant les îles entre elles.\p"
	.string "Avec ça, tu pourras aller sur les\n"
	.string "ILES 1, 2 et 3.\p"
	.string "Oh, il faudrait aussi que tu\n"
	.string "prennes ça.$"

OneIsland_PokemonCenter_1F_Text_ReceivedExtraPageForTownMap::
	.string "{PLAYER} obtient une page\n"
	.string "supplémentaire pour sa CARTE.$"

OneIsland_PokemonCenter_1F_Text_ReceivedTownMap::
	.string "{PLAYER} obtient la\n"
	.string "CARTE!$"

OneIsland_PokemonCenter_1F_Text_BillCatchYouLater::
	.string "LEO: On se revoit plus tard.\p"
	.string "Dis bonjour au type de la SALLE\n"
	.string "DE JEU pour moi.$"

OneIsland_PokemonCenter_1F_Text_HmmHowAboutLikeThis::
	.string "Hum…\n"
	.string "Et si on essayait comme ça!$"

OneIsland_PokemonCenter_1F_Text_GotPCWorkingStrollAWhileMore::
	.string "Oh, {PLAYER}!\p"
	.string "Tu as vu?\n"
	.string "Le PC fonctionne enfin!\p"
	.string "Mais j'ai encore quelques trucs\n"
	.string "à montrer à CILEO.\p"
	.string "Tu peux repasser un peu\n"
	.string "plus tard?$"

OneIsland_PokemonCenter_1F_Text_SorryForBeingPoorHost::
	.string "Je suis vraiment désolé d'accaparer\n"
	.string "LEO.\p"
	.string "J'espère que tu ne m'en voudras\n"
	.string "pas trop.$"

OneIsland_PokemonCenter_1F_Text_UsualPCServicesUnavailable::
	.string "Services habituels inaccessibles…$"

OneIsland_PokemonCenter_1F_Text_BillOhHeyPlayer::
	.string "LEO: Oh!\n"
	.string "{PLAYER}!$"

OneIsland_PokemonCenter_1F_Text_BillWeGotItDone::
	.string "LEO: Qu'est-ce qui t'a retenu\n"
	.string "comme ça?\p"
	.string "Nous, on a terminé! Les PC\n"
	.string "fonctionnent à merveille.$"

OneIsland_PokemonCenter_1F_Text_CelioJobWentQuick::
	.string "CILEO: LEO est un vrai pro.\p"
	.string "Il a réussi à tout mettre en ligne\n"
	.string "en un rien de temps.$"

OneIsland_PokemonCenter_1F_Text_BillYouveLearnedALot::
	.string "LEO: Non, non.\n"
	.string "C'était vraiment rien.\p"
	.string "Tout ça c'est grâce à toi CILEO,\n"
	.string "j'aurais rien pu faire seul.$"

OneIsland_PokemonCenter_1F_Text_CelioOhReallyEhehe::
	.string "CILEO: Oh?\n"
	.string "Merci…$"

OneIsland_PokemonCenter_1F_Text_BillWeShouldHeadBackToKanto::
	.string "LEO: Bon, maintenant que tout\n"
	.string "fonctionne, on peut repartir\p"
	.string "pour KANTO.\n"
	.string "A bientôt CILEO.$"

OneIsland_PokemonCenter_1F_Text_CelioPromiseIllShowYouAroundSometime::
	.string "CILEO: {PLAYER}, je suis vraiment\n"
	.string "désolé d'avoir passé tout ce\p"
	.string "temps sur le PC.\p"
	.string "C'est promis, la prochaine fois,\n"
	.string "je te ferai visiter les îles.$"

OneIsland_PokemonCenter_1F_Text_CelioImModifyingMyNetworkMachine::
	.string "CILEO: Salut!\p"
	.string "On dirait que tu as plein de choses\n"
	.string "à faire aujourd'hui.\p"
	.string "Comment je vais?\p"
	.string "Eh bien, j'effectue quelques mises\n"
	.string "à jour sur ma machine.\p"
	.string "Quand j'aurai terminé, j'espère\n"
	.string "que tu seras la première personne\p"
	.string "à l'utiliser, {PLAYER}.$"

OneIsland_PokemonCenter_1F_Text_CelioCaughtMoreMonMaybeICanBeUseful::
	.string "CILEO: {PLAYER}, tout se passe\n"
	.string "bien pour toi?\p"
	.string "Oh, je vois que tu as attrapé\n"
	.string "plein de POKéMON.\p"
	.string "Tu sais quoi? Je crois que je\n"
	.string "pourrais t'être utile.$"

OneIsland_PokemonCenter_1F_Text_YoullBeTradingFromTrainersFarAway::
	.string "Je suis en train d'apporter des\n"
	.string "modifications à ma machine.\p"
	.string "Quand j'aurai terminé, tu\n"
	.string "pourras échanger des POKéMON\p"
	.string "avec des DRESSEURS qui se\n"
	.string "trouvent très loin d'ici.$"

OneIsland_PokemonCenter_1F_Text_NeedsSpecialGemstone::
	.string "Il y a juste un problème.\p"
	.string "Pour que ça fonctionne, il me\n"
	.string "faut une pierre spéciale.\p"
	.string "Elle est censée se trouver\n"
	.string "sur l'ILE 1, mais je ne\p"
	.string "l'ai pas encore trouvée.\p"
	.string "Qui sait où elle peut bien se\n"
	.string "trouver?$"

OneIsland_PokemonCenter_1F_Text_TryingToFindGem::
	.string "Je cherchais déjà cette pierre\n"
	.string "pendant mes études.\p"
	.string "Résultat, je n'ai ni mon diplôme,\n"
	.string "ni la pierre…\p"
	.string "Je sais que je peux compter sur\n"
	.string "LEO pour faire avancer mes\p"
	.string "recherches. Mais cette fois, je\n"
	.string "voudrais réussir tout seul.$"

OneIsland_PokemonCenter_1F_Text_OhThats::
	.string "Oh!\n"
	.string "M-mais c'est…$"

OneIsland_PokemonCenter_1F_Text_HandedRubyToCelio::
	.string "{PLAYER} donne le RUBIS à\n"
	.string "CILEO.$"

OneIsland_PokemonCenter_1F_Text_MayIAskOneMoreFavor::
	.string "Merci!\p"
	.string "{PLAYER}, je ne sais pas comment\n"
	.string "te remercier.\p"
	.string "… … …  … … …\p"
	.string "… Est-ce que je peux te demander\n"
	.string "encore une grosse faveur?$"

OneIsland_PokemonCenter_1F_Text_PleaseINeedYourHelp::
	.string "Ce… Ce n'est pas\n"
	.string "compliqué, je t'en prie.$"

OneIsland_PokemonCenter_1F_Text_AnotherGemstoneInSeviiIslands::
	.string "Quand j'étudiais les pierres\n"
	.string "précieuses, j'ai découvert\p"
	.string "quelque chose d'important.\p"
	.string "Il y a une autre pierre qui va de\n"
	.string "pair avec ce RUBIS.\p"
	.string "Cette pierre devrait se trouver\n"
	.string "sur les ILES SEVII.\p"
	.string "{PLAYER}, pourrais-tu chercher\n"
	.string "cette pierre pour moi?\p"
	.string "Tiens, montre-moi ton PASSE\n"
	.string "et la CARTE.$"

OneIsland_PokemonCenter_1F_Text_ReturnedTriPassForRainbowPass::
	.string "{PLAYER} rend le TRI-PASSE et\n"
	.string "reçoit le PASSE PRISME.$"

OneIsland_PokemonCenter_1F_Text_ObtainedExtraMapPage::
	.string "Et reçoit une page supplémentaire\n"
	.string "pour la CARTE.$"

OneIsland_PokemonCenter_1F_Text_PassLetYouGetToAllIslands::
	.string "C'est mon PASSE personnel\n"
	.string "pour le ferry.\p"
	.string "Avec ça, tu peux aller sur les\n"
	.string "ILES SEVII.\p"
	.string "{PLAYER}, j'ai vraiment besoin de\n"
	.string "ton aide.$"

OneIsland_PokemonCenter_1F_Text_HandedSapphireToCelio::
	.string "{PLAYER} donne le SAPHIR à CILEO.$"

OneIsland_PokemonCenter_1F_Text_ThankYouGiveMeTime::
	.string "CILEO: Voilà la pierre qui va de\n"
	.string "pair avec le RUBIS.\p"
	.string "{PLAYER}, tu as dû te donner du mal\n"
	.string "pour l'obtenir, n'est-ce pas?\p"
	.string "Ne dis rien, je sais que ça a\n"
	.string "dû être difficile.\p"
	.string "Merci énormément!\p"
	.string "A mon tour de te rendre service!\n"
	.string "Donne-moi juste un instant.$"

OneIsland_PokemonCenter_1F_Text_OkayThisIsGood::
	.string "OK, c'est bon…$"

OneIsland_PokemonCenter_1F_Text_LinkedUpWithLanette::
	.string "J'ai réussi!\n"
	.string "Je me suis connecté avec ANNETTE!$"

OneIsland_PokemonCenter_1F_Text_ManagedToLinkWithHoennThankYou::
	.string "{PLAYER}…\n"
	.string "{PLAYER}, j'ai réussi!\p"
	.string "J'ai réussi à me connecter avec\n"
	.string "les DRESSEURS de HOENN.\p"
	.string "Ma machine est complètement\n"
	.string "opérationnelle!\p"
	.string "{PLAYER}, tout ça,\n"
	.string "c'est grâce à toi!\p"
	.string "Merci, mes rêves se sont enfin\n"
	.string "réalisés…$"

OneIsland_PokemonCenter_1F_Text_WishYouBestOfLuck::
	.string "…\n"
	.string "J'en ai les larmes aux yeux.\p"
	.string "En tout cas, je te souhaite de\n"
	.string "réussir dans ta quête de\p"
	.string "POKéMON exotiques.\n"
	.string "Bonne chance {PLAYER}!$"

OneIsland_PokemonCenter_1F_Text_CelioHearingRumorsAboutYou::
	.string "CILEO: Hello!\p"
	.string "{PLAYER}, j'ai entendu plein de\n"
	.string "choses sur toi.$"

OneIsland_PokemonCenter_1F_Text_BillsFirstMonWasAbra::
	.string "{PLAYER}, c'est quoi ton type\n"
	.string "de POKéMON préféré?\p"
	.string "LEO est un POKéMANIAC,\n"
	.string "il aime tous les types de POKéMON.\p"
	.string "Apparemment, son premier POKéMON\n"
	.string "était un ABRA.$"

OneIsland_PokemonCenter_1F_Text_BillsHometownInGoldenrod::
	.string "Au fait, {PLAYER}, tu es de\n"
	.string "BOURG PALETTE, non?\p"
	.string "Il paraît que c'est une petite\n"
	.string "ville très agréable.\p"
	.string "LEO vient de GOLDENROD,\n"
	.string "sa famille y habite toujours.\p"
	.string "On raconte que c'est une ville\n"
	.string "qui aime faire la fête.\p"
	.string "J'aimerais y aller un jour.$"

OneIsland_PokemonCenter_1F_Text_BillCantStomachMilk::
	.string "{PLAYER}, y a-t-il des choses que\n"
	.string "tu ne supportes pas?\p"
	.string "Apparemment, LEO est allergique\n"
	.string "au lait, c'est dingue.$"

OneIsland_PokemonCenter_1F_Text_CameFromPalletDontKnowIt::
	.string "Oh, un étranger!\n"
	.string "Salut, tu viens d'où?\p"
	.string "BOURG PALETTE?\n"
	.string "Connais pas!$"

OneIsland_PokemonCenter_1F_Text_EnormousVolcanoOnIsland::
	.string "Sur cette île, il y a un énorme\n"
	.string "volcan.\p"
	.string "Il n'est pas entré en éruption\n"
	.string "depuis longtemps.\p"
	.string "Ça te tente une petite balade?$"

OneIsland_PokemonCenter_1F_Text_WishICouldTradeWithBoyfriend::
	.string "J'adorerais pouvoir échanger des\n"
	.string "POKéMON avec mon copain\p"
	.string "qui habite très loin d'ici…$"

OneIsland_PokemonCenter_1F_Text_TradedWithFarAwayBoyfriend::
	.string "J'ai pu échanger des POKéMON\n"
	.string "avec mon copain qui\p"
	.string "habite très loin d'ici.\p"
	.string "C'est grâce à CILEO et toi que\n"
	.string "c'est enfin possible.\p"
	.string "Alors, du fond du cœur, merci!$"

OneIsland_PokemonCenter_1F_Text_MachineUnderAdjustment::
	.string "NIVEAU DE CONNEXION 0\p"
	.string "Système de gestion de POKéMON\n"
	.string "en construction.$"

OneIsland_PokemonCenter_1F_Text_MachineLinkedWithKanto::
	.string "NIVEAU DE CONNEXION 1\p"
	.string "Lien établi avec la région de\n"
	.string "KANTO.$"

OneIsland_PokemonCenter_1F_Text_MachineLinkedWithKantoAndHoenn::
	.string "NIVEAU DE CONNEXION 2\p"
	.string "Lien établi avec les régions de\n"
	.string "KANTO et HOENN.$"

OneIsland_PokemonCenter_1F_Text_ObtainedTriPass::
	.string "Obtient le TRI-PASSE!$"


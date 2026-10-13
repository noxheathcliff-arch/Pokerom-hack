PewterCity_Museum_1F_Frlg_MapScripts::
	.byte 0

PewterCity_Museum_1F_EventScript_Scientist1::
	lock
	faceplayer
	goto_if_eq VAR_FACING, DIR_WEST, PewterCity_Museum_1F_EventScript_Scientist1BehindCounter
	goto_if_eq VAR_FACING, DIR_SOUTH, PewterCity_Museum_1F_EventScript_Scientist1BehindCounter
	goto_if_eq VAR_FACING, DIR_NORTH, PewterCity_Museum_1F_EventScript_Scientist1BehindCounter
	msgbox PewterCity_Museum_1F_Text_PleaseEnjoyYourself
	release
	end

PewterCity_Museum_1F_EventScript_Scientist1BehindCounter::
	msgbox PewterCity_Museum_1F_Text_DoYouKnowWhatAmberIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_Museum_1F_EventScript_AmberHasGeneticMatter
	goto_if_eq VAR_RESULT, NO, PewterCity_Museum_1F_EventScript_ExplainAmber
	end

PewterCity_Museum_1F_EventScript_AmberHasGeneticMatter::
	msgbox PewterCity_Museum_1F_Text_AmberContainsGeneticMatter
	applymovement LOCALID_MUSEUM_SCIENTIST1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PewterCity_Museum_1F_EventScript_ExplainAmber::
	msgbox PewterCity_Museum_1F_Text_AmberIsFossilizedSap
	applymovement LOCALID_MUSEUM_SCIENTIST1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PewterCity_Museum_1F_EventScript_EntranceTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto PewterCity_Museum_1F_EventScript_EntranceTrigger
	end

PewterCity_Museum_1F_EventScript_EntranceTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto PewterCity_Museum_1F_EventScript_EntranceTrigger
	end

PewterCity_Museum_1F_EventScript_EntranceTriggerRight::
	lockall
	setvar VAR_TEMP_1, 2
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto PewterCity_Museum_1F_EventScript_EntranceTrigger
	end

PewterCity_Museum_1F_EventScript_EntranceTrigger::
	textcolor NPC_TEXT_COLOR_MALE
	showmoneybox 0, 0
	msgbox PewterCity_Museum_1F_Text_Its50YForChildsTicket, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PewterCity_Museum_1F_EventScript_TryPayForTicket
	msgbox PewterCity_Museum_1F_Text_ComeAgain
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, PewterCity_Museum_1F_Movement_ForcePlayerExit
	waitmovement 0
	releaseall
	end

PewterCity_Museum_1F_EventScript_TryPayForTicket::
	checkmoney 50
	goto_if_eq VAR_RESULT, FALSE, PewterCity_Museum_1F_EventScript_NotEnoughMoney
	closemessage
	call_if_eq VAR_TEMP_1, 0, PewterCity_Museum_1F_EventScript_PlayerApproachCounterLeft
	call_if_eq VAR_TEMP_1, 1, PewterCity_Museum_1F_EventScript_PlayerApproachCounterMid
	call_if_eq VAR_TEMP_1, 2, PewterCity_Museum_1F_EventScript_PlayerApproachCounterRight
	playse SE_SHOP
	removemoney 50
	updatemoneybox
	waitse
	msgbox PewterCity_Museum_1F_Text_Right50YThankYou
	setvar VAR_MAP_SCENE_PEWTER_CITY_MUSEUM_1F, 1
	hidemoneybox
	releaseall
	end

PewterCity_Museum_1F_EventScript_PlayerApproachCounterLeft::
	applymovement LOCALID_PLAYER, PewterCity_Museum_1F_Movement_ApproachCounterLeft
	waitmovement 0
	return

PewterCity_Museum_1F_EventScript_PlayerApproachCounterMid::
	applymovement LOCALID_PLAYER, PewterCity_Museum_1F_Movement_ApproachCounterMid
	waitmovement 0
	return

PewterCity_Museum_1F_EventScript_PlayerApproachCounterRight::
	applymovement LOCALID_PLAYER, PewterCity_Museum_1F_Movement_ApproachCounterRight
	waitmovement 0
	return

PewterCity_Museum_1F_EventScript_NotEnoughMoney::
	msgbox PewterCity_Museum_1F_Text_DontHaveEnoughMoney
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, PewterCity_Museum_1F_Movement_ForcePlayerExit
	waitmovement 0
	releaseall
	end

PewterCity_Museum_1F_Movement_ForcePlayerExit::
	walk_down
	step_end

PewterCity_Museum_1F_Movement_ApproachCounterLeft::
	walk_right
	walk_right
	delay_8
	walk_in_place_right
	step_end

PewterCity_Museum_1F_Movement_ApproachCounterMid::
	walk_right
	delay_8
	walk_in_place_right
	step_end

PewterCity_Museum_1F_Movement_ApproachCounterRight::
	delay_8
	walk_in_place_right
	step_end

PewterCity_Museum_1F_EventScript_Scientist2::
	msgbox PewterCity_Museum_1F_Text_WeHaveTwoFossilsOnExhibit, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_OldMan::
	msgbox PewterCity_Museum_1F_Text_ShouldBeGratefulForLongLife, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_OldAmberScientist::
	lock
	faceplayer
	goto_if_set FLAG_GOT_OLD_AMBER, PewterCity_Museum_1F_EventScript_AlreadyGotOldAmber
	msgbox PewterCity_Museum_1F_Text_WantYouToGetAmberExamined
	checkitemspace ITEM_OLD_AMBER
	goto_if_eq VAR_RESULT, FALSE, PewterCity_Museum_1F_EventScript_NoRoomForOldAmber
	setflag FLAG_GOT_OLD_AMBER
	removeobject LOCALID_OLD_AMBER
	giveitem_msg PewterCity_Museum_1F_Text_ReceivedOldAmberFromMan, ITEM_OLD_AMBER, 1, MUS_RG_OBTAIN_KEY_ITEM
	release
	end

PewterCity_Museum_1F_EventScript_NoRoomForOldAmber::
	msgbox PewterCity_Museum_1F_Text_DontHaveSpaceForThis
	release
	end

PewterCity_Museum_1F_EventScript_AlreadyGotOldAmber::
	msgbox PewterCity_Museum_1F_Text_GetOldAmberChecked
	release
	end

PewterCity_Museum_1F_EventScript_OldAmber::
	msgbox PewterCity_Museum_1F_Text_BeautifulPieceOfAmber, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_AerodactylFossil::
	lockall
	setvar VAR_0x8004, SPECIES_AERODACTYL
	setvar VAR_0x8005, 10
	setvar VAR_0x8006, 3
	special OpenMuseumFossilPic
	msgbox PewterCity_Museum_1F_Text_AerodactylFossil
	special CloseMuseumFossilPic
	releaseall
	end

PewterCity_Museum_1F_EventScript_KabutopsFossil::
	lockall
	setvar VAR_0x8004, SPECIES_KABUTOPS
	setvar VAR_0x8005, 10
	setvar VAR_0x8006, 3
	special OpenMuseumFossilPic
	msgbox PewterCity_Museum_1F_Text_KabutopsFossil
	special CloseMuseumFossilPic
	releaseall
	end

PewterCity_Museum_1F_Text_Its50YForChildsTicket::
	.string "50¥ le ticket pour un enfant.\p"
	.string "Voulez-vous entrer?$"

PewterCity_Museum_1F_Text_ComeAgain::
	.string "A bientôt!$"

PewterCity_Museum_1F_Text_Right50YThankYou::
	.string "50¥! Parfait!\n"
	.string "Merci!$"

PewterCity_Museum_1F_Text_DontHaveEnoughMoney::
	.string "Vous n'avez pas assez d'argent.$"

PewterCity_Museum_1F_Text_PleaseEnjoyYourself::
	.string "Bonne visite!$"

PewterCity_Museum_1F_Text_DoYouKnowWhatAmberIs::
	.string "Ne te cache pas dans l'ombre!\p"
	.string "Enfin, si ça t'amuse! Au fait,\n"
	.string "sais-tu ce que c'est l'AMBRE?$"

PewterCity_Museum_1F_Text_AmberContainsGeneticMatter::
	.string "Dans un certain labo, on essaie de\n"
	.string "régénérer les anciens POKéMON\p"
	.string "grâce à leur information génétique\n"
	.string "contenue dans de l'AMBRE.$"

PewterCity_Museum_1F_Text_AmberIsFossilizedSap::
	.string "L'AMBRE est en fait de la sève\n"
	.string "tombée des arbres.\p"
	.string "Avec le temps, la sève se\n"
	.string "fossilise pour devenir de l'AMBRE.$"

@ Unused
PewterCity_Museum_1F_Text_PleaseGoAround::
	.string "あちらへ　おまわりください$"

PewterCity_Museum_1F_Text_ShouldBeGratefulForLongLife::
	.string "Je ne pensais pas que je pourrais\n"
	.string "vivre suffisamment vieux pour\p"
	.string "pouvoir voir des os de dragon.$"

PewterCity_Museum_1F_Text_WantYouToGetAmberExamined::
	.string "Je crois qu'il y a des traces\n"
	.string "d'ADN de POKéMON dans ce\l"
	.string "morceau d'ambre.\p"
	.string "Ça serait une avancée scientifique\n"
	.string "incroyable si on pouvait\p"
	.string "régénérer un POKéMON à partir de\n"
	.string "cette pierre! Non? Hein?\p"
	.string "Mais personne ne m'écoute!\p"
	.string "J'ai une faveur à te demander!\p"
	.string "Apporte ça à mon LABO POKéMON\n"
	.string "pour l'examiner!$"

PewterCity_Museum_1F_Text_ReceivedOldAmberFromMan::
	.string "{PLAYER} obtient le\n"
	.string "VIEIL AMBRE!$"

PewterCity_Museum_1F_Text_GetOldAmberChecked::
	.string "Chut! Va faire examiner ce morceau\n"
	.string "d'AMBRE!$"

PewterCity_Museum_1F_Text_DontHaveSpaceForThis::
	.string "Ton inventaire est plein!$"

PewterCity_Museum_1F_Text_WeHaveTwoFossilsOnExhibit::
	.string "Nous avons 2 fossiles dont nous\n"
	.string "sommes très fiers! Ce sont des\l"
	.string "POKéMON préhistoriques!$"

PewterCity_Museum_1F_Text_BeautifulPieceOfAmber::
	.string "Il y a un beau morceau d'AMBRE\n"
	.string "d'un éclat doré!!$"

PewterCity_Museum_1F_Text_AerodactylFossil::
	.string "Fossile de PTERA\n"
	.string "Un POKéMON rare et ancien.$"

PewterCity_Museum_1F_Text_KabutopsFossil::
	.string "Fossile du KABUTOPS\n"
	.string "Un POKéMON rare et ancien.$"


FuchsiaCity_WardensHouse_Frlg_MapScripts::
	.byte 0

FuchsiaCity_WardensHouse_EventScript_Warden::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HM04, FuchsiaCity_WardensHouse_EventScript_ExplainStrength
	goto_if_set FLAG_HIDE_SAFARI_ZONE_WEST_GOLD_TEETH, FuchsiaCity_WardensHouse_EventScript_GiveGoldTeeth
	msgbox FuchsiaCity_WardensHouse_Text_HifFuffHefifoo, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, FuchsiaCity_WardensHouse_EventScript_WardenYes
	call_if_eq VAR_RESULT, NO, FuchsiaCity_WardensHouse_EventScript_WardenNo
	release
	end

FuchsiaCity_WardensHouse_EventScript_GiveGoldTeeth::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_OBTAIN_TMHM
	message FuchsiaCity_WardensHouse_Text_GaveGoldTeethToWarden
	waitmessage
	waitfanfare
	msgbox FuchsiaCity_WardensHouse_Text_WardenPoppedInHisTeeth
	call EventScript_RestorePrevTextColor
	checkplayergender
	call_if_eq VAR_RESULT, MALE, FuchsiaCity_WardensHouse_EventScript_WardenThanksMale
	call_if_eq VAR_RESULT, FEMALE, FuchsiaCity_WardensHouse_EventScript_WardenThanksFemale
	giveitem_msg FuchsiaCity_WardensHouse_Text_ReceivedHM04FromWarden, ITEM_HM04
	setflag FLAG_GOT_HM04
	removeitem ITEM_GOLD_TEETH
	release
	end

FuchsiaCity_WardensHouse_EventScript_WardenThanksMale::
	msgbox FuchsiaCity_WardensHouse_Text_ThanksSonGiveYouSomething
	return

FuchsiaCity_WardensHouse_EventScript_WardenThanksFemale::
	msgbox FuchsiaCity_WardensHouse_Text_ThanksLassieGiveYouSomething
	return

FuchsiaCity_WardensHouse_EventScript_WardenYes::
	msgbox FuchsiaCity_WardensHouse_Text_AhHowheeHoHoo
	return

FuchsiaCity_WardensHouse_EventScript_WardenNo::
	msgbox FuchsiaCity_WardensHouse_Text_HeOhayHeHaHoo
	return

FuchsiaCity_WardensHouse_EventScript_ExplainStrength::
	msgbox FuchsiaCity_WardensHouse_Text_ExplainStrength
	release
	end

FuchsiaCity_WardensHouse_EventScript_DisplaySign1::
	msgbox FuchsiaCity_WardensHouse_Text_MonPhotosFossilsOnDisplay, MSGBOX_SIGN
	end

FuchsiaCity_WardensHouse_EventScript_DisplaySign2::
	msgbox FuchsiaCity_WardensHouse_Text_OldMonMerchandiseOnDisplay, MSGBOX_SIGN
	end

FuchsiaCity_WardensHouse_Text_HifFuffHefifoo::
	.string "GARDIEN: Hif fuff hefifou!\p"
	.string "Ha fof ha fif eu hafahi ho.\n"
	.string "Heff hi fwi!$"

FuchsiaCity_WardensHouse_Text_AhHowheeHoHoo::
	.string "Ah hahee ho hoo!\n"
	.string "Eef ee hafahi ho!$"

FuchsiaCity_WardensHouse_Text_HeOhayHeHaHoo::
	.string "Ha?\n"
	.string "Hai fou heh ha hoo ih haheh!$"

FuchsiaCity_WardensHouse_Text_GaveGoldTeethToWarden::
	.string "{PLAYER} donne la DENT D'OR au\n"
	.string "GARDIEN!$"

FuchsiaCity_WardensHouse_Text_WardenPoppedInHisTeeth::
	.string "Le GARDIEN peut remettre son\n"
	.string "dentier!$"

FuchsiaCity_WardensHouse_Text_ThanksSonGiveYouSomething::
	.string "GARDIEN: Merci, gamin! C'était un\n"
	.string "peu dur de me faire comprendre.\p"
	.string "J'pouvais plus travailler!\n"
	.string "Quelle horreur!\p"
	.string "Tiens, voilà pour te remercier.$"

FuchsiaCity_WardensHouse_Text_ThanksLassieGiveYouSomething::
	.string "GARDIEN: Merci, gamine! C'était un\n"
	.string "peu dur de me faire comprendre.\p"
	.string "J'pouvais plus travailler!\n"
	.string "Quelle horreur!\p"
	.string "Tiens, voilà pour te remercier.$"

FuchsiaCity_WardensHouse_Text_ReceivedHM04FromWarden::
	.string "{PLAYER} reçoit la\n"
	.string "CS04!$"

FuchsiaCity_WardensHouse_Text_ExplainStrength::
	.string "GARDIEN: la CS04 contient FORCE!\p"
	.string "Tes POKéMON pourront déplacer des\n"
	.string "rochers.\p"
	.string "Au fait, as-tu trouvé la CABANE\n"
	.string "SECRETE dans le PARC SAFARI?$"

@ Unused
FuchsiaCity_WardensHouse_Text_YouHaveTooMuchStuff::
	.string "なんや　にもつ\n"
	.string "いっぱいやんけ！$"

FuchsiaCity_WardensHouse_Text_MonPhotosFossilsOnDisplay::
	.string "Photos et fossiles de POKéMON.$"

FuchsiaCity_WardensHouse_Text_OldMonMerchandiseOnDisplay::
	.string "Tout plein de trucs POKéMON!$"


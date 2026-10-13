SafariZone_SecretHouse_Frlg_MapScripts::
	.byte 0

SafariZone_SecretHouse_EventScript_Attendant::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HM03, SafariZone_SecretHouse_EventScript_ExplainSurf
	msgbox SafariZone_SecretHouse_Text_CongratsYouveWon
	checkitemspace ITEM_HM03
	goto_if_eq VAR_RESULT, FALSE, SafariZone_SecretHouse_EventScript_NoRoomForHM03
	giveitem_msg SafariZone_SecretHouse_Text_ReceivedHM03FromAttendant, ITEM_HM03
	msgbox SafariZone_SecretHouse_Text_ExplainSurf
	setflag FLAG_GOT_HM03
	release
	end

SafariZone_SecretHouse_EventScript_NoRoomForHM03::
	msgbox SafariZone_SecretHouse_Text_DontHaveRoomForPrize
	release
	end

SafariZone_SecretHouse_EventScript_ExplainSurf::
	msgbox SafariZone_SecretHouse_Text_ExplainSurf
	release
	end

SafariZone_SecretHouse_Text_CongratsYouveWon::
	.string "Ah! Quand même!\p"
	.string "Enfin quelqu'un qui découvre\n"
	.string "la CABANE SECRETE!\p"
	.string "J'avais peur que personne ne\n"
	.string "gagne notre prix.\p"
	.string "Félicitations!\n"
	.string "Tu as gagné!$"

SafariZone_SecretHouse_Text_ReceivedHM03FromAttendant::
	.string "{PLAYER} obtient la CS03\n"
	.string "de l'intendant!$"

SafariZone_SecretHouse_Text_ExplainSurf::
	.string "CS03 contient SURF!\p"
	.string "Un POKéMON pourra te faire\n"
	.string "naviguer sur les flots!\p"
	.string "En plus, cette CS peut s'utiliser à\n"
	.string "l'infini!\p"
	.string "T'en as de la chance!$"

SafariZone_SecretHouse_Text_DontHaveRoomForPrize::
	.string "Heu… Tu n'as pas assez de place\n"
	.string "pour recevoir ce prix fabuleux!$"


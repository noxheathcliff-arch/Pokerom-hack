Route16_House_Frlg_MapScripts::
	.byte 0

Route16_House_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HM02, Route16_House_EventScript_AlreadyGotHM02
	msgbox Route16_House_Text_FoundMySecretRetreat
	checkitemspace ITEM_HM02
	goto_if_eq VAR_RESULT, FALSE, Route16_House_EventScript_NoRoomForHM02
	giveitem_msg Route16_House_Text_ReceivedHM02FromGirl, ITEM_HM02
	msgbox Route16_House_Text_ExplainHM02
	setflag FLAG_GOT_HM02
	release
	end

Route16_House_EventScript_NoRoomForHM02::
	msgbox Route16_House_Text_DontHaveAnyRoomForThis
	release
	end

Route16_House_EventScript_AlreadyGotHM02::
	msgbox Route16_House_Text_ExplainHM02
	release
	end

Route16_House_EventScript_Fearow::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_FEAROW, CRY_MODE_NORMAL
	msgbox Route16_House_Text_Fearow
	waitmoncry
	release
	end

Route16_House_Text_FoundMySecretRetreat::
	.string "Oh!\n"
	.string "Tu as trouvé ma cache secrète!\p"
	.string "Prends ceci. En échange, ne dis\n"
	.string "à personne que tu m'as vue!$"

Route16_House_Text_ReceivedHM02FromGirl::
	.string "{PLAYER} obtient la\n"
	.string "CS02!$"

Route16_House_Text_ExplainHM02::
	.string "CS02: VOL. C'est une capacité\n"
	.string "très pratique.\p"
	.string "Fais-en bon usage!$"

Route16_House_Text_DontHaveAnyRoomForThis::
	.string "Ton inventaire est plein.$"

Route16_House_Text_Fearow::
	.string "RAPASDEPIC: Piiiiiik!$"


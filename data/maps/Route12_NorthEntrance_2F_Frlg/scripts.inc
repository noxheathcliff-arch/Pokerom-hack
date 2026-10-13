Route12_NorthEntrance_2F_Frlg_MapScripts::
	.byte 0

Route12_NorthEntrance_2F_EventScript_LeftBinoculars::
	msgbox Route12_NorthEntrance_2F_Text_TheresManFishing, MSGBOX_SIGN
	end

Route12_NorthEntrance_2F_EventScript_RightBinoculars::
	msgbox Route12_NorthEntrance_2F_Text_ItsPokemonTower, MSGBOX_SIGN
	end

Route12_NorthEntrance_2F_EventScript_Lass::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM27, Route12_NorthEntrance_2F_EventScript_ExplainTM27
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route12_NorthEntrance_2F_EventScript_TakeTMMale
	call_if_eq VAR_RESULT, FEMALE, Route12_NorthEntrance_2F_EventScript_TakeTMFemale
	checkitemspace ITEM_TM27
	goto_if_eq VAR_RESULT, FALSE, Route12_NorthEntrance_2F_EventScript_NoRoomForTM27
	giveitem_msg Route12_NorthEntrance_2F_Text_ReceivedTM27FromLittleGirl, ITEM_TM27
	msgbox Route12_NorthEntrance_2F_Text_ExplainTM27
	setflag FLAG_GOT_TM27
	release
	end

Route12_NorthEntrance_2F_EventScript_TakeTMMale::
	msgbox Route12_NorthEntrance_2F_Text_TakeTMDontNeedAnymoreMale
	return

Route12_NorthEntrance_2F_EventScript_TakeTMFemale::
	msgbox Route12_NorthEntrance_2F_Text_TakeTMDontNeedAnymoreFemale
	return

Route12_NorthEntrance_2F_EventScript_NoRoomForTM27::
	msgbox Route12_NorthEntrance_2F_Text_DontHaveRoomForThis
	release
	end

Route12_NorthEntrance_2F_EventScript_ExplainTM27::
	msgbox Route12_NorthEntrance_2F_Text_ExplainTM27
	release
	end

@ Male and female text identical, differ (presumably) in JP
Route12_NorthEntrance_2F_Text_TakeTMDontNeedAnymoreMale::
	.string "Les cendres de mes POKéMON sont\n"
	.string "dans la TOUR POKéMON.\p"
	.string "Tiens! Prends cette CT. Je n'en ai\n"
	.string "plus besoin…$"

Route12_NorthEntrance_2F_Text_TakeTMDontNeedAnymoreFemale::
	.string "Les cendres de mes POKéMON sont\n"
	.string "dans la TOUR POKéMON.\p"
	.string "Tiens! Prends cette CT. Je n'en ai\n"
	.string "plus besoin…$"

Route12_NorthEntrance_2F_Text_ReceivedTM27FromLittleGirl::
	.string "{PLAYER} obtient\n"
	.string "CT27!$"

Route12_NorthEntrance_2F_Text_ExplainTM27::
	.string "La CT27 s'appelle RETOUR.\p"
	.string "Si tu traites bien tes POKéMON,\n"
	.string "ils te le rendront en se donnant\p"
	.string "plus de mal au combat.$"

Route12_NorthEntrance_2F_Text_DontHaveRoomForThis::
	.string "Ton inventaire est plein!$"

Route12_NorthEntrance_2F_Text_TheresManFishing::
	.string "Vous regardez dans les jumelles.\p"
	.string "Vous voyez un pêcheur!$"

Route12_NorthEntrance_2F_Text_ItsPokemonTower::
	.string "Vous regardez dans les jumelles.\p"
	.string "Vous voyez la TOUR POKéMON!$"


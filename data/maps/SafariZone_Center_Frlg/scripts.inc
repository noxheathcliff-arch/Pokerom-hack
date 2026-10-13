SafariZone_Center_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SafariZone_Center_OnTransition
	.byte 0

SafariZone_Center_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SAFARI_ZONE_CENTER
	end

SafariZone_Center_EventScript_RestHouseSign::
	msgbox SafariZone_Center_Text_RestHouse, MSGBOX_SIGN
	end

SafariZone_Center_EventScript_TrainerTips::
	msgbox SafariZone_Center_Text_PressStartToCheckTime, MSGBOX_SIGN
	end

SafariZone_Center_EventScript_AreaSign::
	msgbox SafariZone_Center_Text_CenterArea, MSGBOX_SIGN
	end

SafariZone_Center_Text_RestHouse::
	.string "ABRI$"

SafariZone_Center_Text_PressStartToCheckTime::
	.string "ASTUCE\p"
	.string "Appuyez sur START pour consulter\n"
	.string "le chronomètre!$"

SafariZone_Center_Text_CenterArea::
	.string "PARC CENTRAL$"


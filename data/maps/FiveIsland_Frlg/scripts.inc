FiveIsland_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FiveIsland_OnTransition
	.byte 0

FiveIsland_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_FIVE_ISLAND
	end

FiveIsland_EventScript_IslandSign::
	msgbox FiveIsland_Text_IslandSign, MSGBOX_SIGN
	end

FiveIsland_EventScript_BugCatcher::
	msgbox FiveIsland_Text_WeirdBuildingInMeadow, MSGBOX_NPC
	end

FiveIsland_EventScript_Fisher::
	msgbox FiveIsland_Text_BeenGettingBusierAroundHere, MSGBOX_NPC
	end

FiveIsland_Text_IslandSign::
	.string "ILE 5\p"
	.string "L'île où le temps s'écoule comme\n"
	.string "une rivière$"

FiveIsland_Text_WeirdBuildingInMeadow::
	.string "Oh, ça craint. Je voulais jouer\n"
	.string "dans le PRE.\p"
	.string "Mais ils nous ont collé ça en\n"
	.string "plein milieu. J'peux plus jouer!$"

FiveIsland_Text_BeenGettingBusierAroundHere::
	.string "Il y a de plus en plus d'agitation\n"
	.string "par ici récemment.\p"
	.string "Et ça fait longtemps que j'ai\n"
	.string "pas eu de bonne prise.$"


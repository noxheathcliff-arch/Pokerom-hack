SixIsland_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SixIsland_OnTransition
	.byte 0

SixIsland_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SIX_ISLAND
	end

SixIsland_EventScript_Hiker::
	msgbox SixIsland_Text_ThatWayToWaterPathRuinValley, MSGBOX_NPC
	end

SixIsland_EventScript_Boy::
	msgbox SixIsland_Text_SkyAtNightIsFantastic, MSGBOX_NPC
	end

SixIsland_EventScript_IslandSign::
	msgbox SixIsland_Text_IslandSign, MSGBOX_SIGN
	end

SixIsland_Text_IslandSign::
	.string "ILE 6\n"
	.string "Lîle de la sagesse$"

SixIsland_Text_ThatWayToWaterPathRuinValley::
	.string "En allant par là, tu arriveras\n"
	.string "à AGUALCANAL.\p"
	.string "Continue dessus si tu veux\n"
	.string "voir la VALLEE RUINE.$"

SixIsland_Text_SkyAtNightIsFantastic::
	.string "Quand on est aussi loin des\n"
	.string "lumières de la ville, la nuit,\p"
	.string "on peut voir toutes les étoiles\n"
	.string "dans le ciel.$"


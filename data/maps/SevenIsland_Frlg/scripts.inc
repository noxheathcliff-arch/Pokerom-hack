SevenIsland_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_OnTransition
	.byte 0

SevenIsland_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SEVEN_ISLAND
	end

SevenIsland_EventScript_IslandSign::
	msgbox SevenIsland_Text_IslandSign, MSGBOX_SIGN
	end

SevenIsland_EventScript_OldWoman::
	msgbox SevenIsland_Text_IslandsMadeInSevenDays, MSGBOX_NPC
	end

SevenIsland_EventScript_Scientist::
	msgbox SevenIsland_Text_IslandVirtuallyUntouched, MSGBOX_NPC
	end

Text_SwordsDanceTeach::
	.string "Y'a pas beaucoup de monde qui\n"
	.string "passe dans le coin.\p"
	.string "Si je m'entraîne là, je deviendrai\n"
	.string "de plus en plus fort, c'est sûr!\p"
	.string "Ouais, de plus en plus fort…\p"
	.string "Ça te dirait d'apprendre cette\n"
	.string "capacité? C'est DANSE-LAMES.$"

Text_SwordsDanceDeclined::
	.string "Ben, tant pis.$"

Text_SwordsDanceWhichMon::
	.string "Cool, choisis le POKéMON qui\n"
	.string "doit l'apprendre.$"

Text_SwordsDanceTaught::
	.string "Si seulement on pouvait toujours\n"
	.string "progresser, ça serait mortel!$"

SevenIsland_Text_IslandSign::
	.string "ILE 7\n"
	.string "L'île de l'infinité$"

SevenIsland_Text_IslandsMadeInSevenDays::
	.string "On appelle ces 7 îles les ILES\n"
	.string "SEVII, mais je sais pas pourquoi.\p"
	.string "… En tout cas c'est plein\n"
	.string "de jeunes ici.\p"
	.string "A ce qu'on raconte, elles auraient\n"
	.string "été créées en 7 jours.$"

SevenIsland_Text_IslandVirtuallyUntouched::
	.string "Ces îles ont été conservées dans\n"
	.string "leur état naturel.\p"
	.string "Ça rend les excursions un peu\n"
	.string "plus difficiles que la normale.$"


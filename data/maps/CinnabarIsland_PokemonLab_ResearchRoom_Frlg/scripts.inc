CinnabarIsland_PokemonLab_ResearchRoom_Frlg_MapScripts::
	.byte 0

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_MetronomeTutor::
	goto EventScript_MetronomeTutor
	end

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_Scientist::
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_EeveeCanEvolveIntroThreeMons, MSGBOX_NPC
	end

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_Computer::
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_LegendaryBirdEmail, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_ResearchRoom_EventScript_AmberPipe::
	msgbox CinnabarIsland_PokemonLab_ResearchRoom_Text_AnAmberPipe, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_ResearchRoom_Text_EeveeCanEvolveIntroThreeMons::
	.string "EVOLI peut évoluer en un type\n"
	.string "de POKéMON parmi trois différents.$"

CinnabarIsland_PokemonLab_ResearchRoom_Text_LegendaryBirdEmail::
	.string "Il y a un e-mail!\p"
	.string "… … …\p"
	.string "Il existe trois POKéMON oiseau \n"
	.string "légendaires.\p"
	.string "Ce sont ARTIKODIN, ELECTHOR\n"
	.string "et SULFURA.\p"
	.string "On ne sait rien d'eux.\p"
	.string "Nous pensons aller explorer les\n"
	.string "grottes près d'AZURIA.\p"
	.string "De : L'EQUIPE DE RECHERCHE\n"
	.string "POKéMON …$"

CinnabarIsland_PokemonLab_ResearchRoom_Text_AnAmberPipe::
	.string "Une pipe en ambre!$"


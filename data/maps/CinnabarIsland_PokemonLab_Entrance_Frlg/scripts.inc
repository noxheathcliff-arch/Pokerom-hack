CinnabarIsland_PokemonLab_Entrance_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_PokemonLab_Entrance_OnTransition
	.byte 0

CinnabarIsland_PokemonLab_Entrance_OnTransition::
	call_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1, CinnabarIsland_PokemonLab_Entrance_EventScript_ReadyFossil
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_ReadyFossil::
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 2
	return

CinnabarIsland_PokemonLab_Entrance_EventScript_Scientist::
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_StudyMonsExtensively, MSGBOX_NPC
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_DrFujiPhoto::
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_PhotoOfLabFounderDrFuji, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_MeetingRoomSign::
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_MeetingRoomSign, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_RAndDRoomSign::
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_RAndDRoomSign, MSGBOX_SIGN
	end

CinnabarIsland_PokemonLab_Entrance_EventScript_TestingRoomSign::
	msgbox CinnabarIsland_PokemonLab_Entrance_Text_TestingRoomSign, MSGBOX_SIGN
	end

CinnabarIsland_Gym_Text_PhotoOfBlaineAndFuji::
	.string "C'est une photo d'AUGUSTE\n"
	.string "et de MR. FUJI.\p"
	.string "Ils sont côte à côte en souriant.$"

CinnabarIsland_PokemonLab_Entrance_Text_StudyMonsExtensively::
	.string "Ici on étudie les POKéMON.\p"
	.string "On nous amène souvent des POKéMON\n"
	.string "rares pour les étudier.$"

CinnabarIsland_PokemonLab_Entrance_Text_PhotoOfLabFounderDrFuji::
	.string "Voici une photo du créateur de ce\n"
	.string "LABO: Le DR FUJI!$"

CinnabarIsland_PokemonLab_Entrance_Text_MeetingRoomSign::
	.string "LABO POKéMON\n"
	.string "Salle de réunion$"

CinnabarIsland_PokemonLab_Entrance_Text_RAndDRoomSign::
	.string "Département Recherche et\n"
	.string "Développement du LABO POKéMON$"

CinnabarIsland_PokemonLab_Entrance_Text_TestingRoomSign::
	.string "LABO POKéMON\n"
	.string "Salle de test$"


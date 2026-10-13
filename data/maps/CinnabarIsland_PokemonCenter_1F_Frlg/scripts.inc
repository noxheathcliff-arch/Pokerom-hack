CinnabarIsland_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

CinnabarIsland_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_CINNABAR_ISLAND
	end

CinnabarIsland_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

CinnabarIsland_PokemonCenter_1F_EventScript_Gentleman::
	msgbox CinnabarIsland_PokemonCenter_1F_Text_VisitUnionRoom, MSGBOX_NPC
	end

CinnabarIsland_PokemonCenter_1F_EventScript_CooltrainerF::
	msgbox CinnabarIsland_PokemonCenter_1F_Text_CinnabarGymLocked, MSGBOX_NPC
	end

CinnabarIsland_PokemonCenter_1F_EventScript_Youngster::
	msgbox CinnabarIsland_PokemonCenter_1F_Text_EvolutionCanWaitForNewMoves, MSGBOX_NPC
	end

CinnabarIsland_PokemonCenter_1F_EventScript_Bill::
	lock
	faceplayer
	msgbox CinnabarIsland_PokemonCenter_1F_Text_ReadyToSailToOneIsland, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonCenter_1F_EventScript_NotReadyToSail
	msgbox CinnabarIsland_PokemonCenter_1F_Text_LetsGo
	closemessage
	playbgm MUS_FOLLOW_ME, 1
	savebgm MUS_FOLLOW_ME
	setflag FLAG_DONT_TRANSITION_MUSIC
	setflag FLAG_HIDE_CINNABAR_POKECENTER_BILL
	delay 20
	call_if_eq VAR_FACING, DIR_SOUTH, CinnabarIsland_PokemonCenter_1F_EventScript_ExitWithBillSouth
	call_if_eq VAR_FACING, DIR_EAST, CinnabarIsland_PokemonCenter_1F_EventScript_ExitWithBillEast
	call_if_eq VAR_FACING, DIR_WEST, CinnabarIsland_PokemonCenter_1F_EventScript_ExitWithBillWest
	removeobject LOCALID_CINNABAR_POKEMON_CENTER_BILL
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_2, 1
	clearflag FLAG_HIDE_CINNABAR_BILL
	warp MAP_CINNABAR_ISLAND, 14, 11
	waitstate
	release
	end

CinnabarIsland_PokemonCenter_1F_EventScript_ExitWithBillSouth::
	applymovement LOCALID_CINNABAR_POKEMON_CENTER_BILL, CinnabarIsland_PokemonCenter_1F_Movement_BillExit
	applymovement LOCALID_PLAYER, CinnabarIsland_PokemonCenter_1F_Movement_PlayerExitSouth
	waitmovement 0
	return

CinnabarIsland_PokemonCenter_1F_EventScript_ExitWithBillEast::
	applymovement LOCALID_CINNABAR_POKEMON_CENTER_BILL, CinnabarIsland_PokemonCenter_1F_Movement_BillExitEast
	applymovement LOCALID_PLAYER, CinnabarIsland_PokemonCenter_1F_Movement_PlayerExitEast
	waitmovement 0
	return

CinnabarIsland_PokemonCenter_1F_EventScript_ExitWithBillWest::
	applymovement LOCALID_CINNABAR_POKEMON_CENTER_BILL, CinnabarIsland_PokemonCenter_1F_Movement_BillExit
	applymovement LOCALID_PLAYER, CinnabarIsland_PokemonCenter_1F_Movement_PlayerExitWest
	waitmovement 0
	return

CinnabarIsland_PokemonCenter_1F_EventScript_NotReadyToSail::
	msgbox CinnabarIsland_PokemonCenter_1F_Text_OhNotDoneYet
	release
	end

CinnabarIsland_PokemonCenter_1F_Movement_BillExit::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	delay_8
	set_invisible
	step_end

CinnabarIsland_PokemonCenter_1F_Movement_PlayerExitSouth::
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	delay_16
	walk_down
	step_end

CinnabarIsland_PokemonCenter_1F_Movement_BillExitEast::
	walk_up
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	delay_8
	set_invisible
	step_end

CinnabarIsland_PokemonCenter_1F_Movement_PlayerExitEast::
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	delay_8
	walk_down
	delay_8
	set_invisible
	step_end

CinnabarIsland_PokemonCenter_1F_Movement_PlayerExitWest::
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	delay_16
	walk_down
	step_end

CinnabarIsland_PokemonCenter_1F_Text_CinnabarGymLocked::
	.string "Je suis venue visiter l'ARENE de\n"
	.string "CRAMOIS'ILE, mais c'est fermé.\p"
	.string "Il doit bien y avoir une clé\n"
	.string "quelque part.\p"
	.string "Dans ce vieux manoir peut-être.\p"
	.string "Il paraît qu'un ami du CHAMPION\n"
	.string "d'ARENE vivait là-bas.$"

CinnabarIsland_PokemonCenter_1F_Text_VisitUnionRoom::
	.string "T'as beaucoup d'amis?\p"
	.string "C'est sympa de se connecter\n"
	.string "avec ses copains.\p"
	.string "Mais qui sait? En visitant souvent\n"
	.string "la SALLE UNION, tu pourrais\p"
	.string "peut-être tomber sur de nouveaux\n"
	.string "DRESSEURS et t'en faire des amis.\p"
	.string "Je pense vraiment que ça vaut le\n"
	.string "coup d'y aller souvent.$"

CinnabarIsland_PokemonCenter_1F_Text_EvolutionCanWaitForNewMoves::
	.string "Les POKéMON peuvent apprendre des\n"
	.string "techniques même après avoir annulé\l"
	.string "une évolution.\p"
	.string "On peut lancer une évolution après\n"
	.string "avoir appris une technique!!!$"

CinnabarIsland_PokemonCenter_1F_Text_ReadyToSailToOneIsland::
	.string "LEO: Hé, tu m'as fait attendre!\n"
	.string "On part pour l'ILE 1?$"

CinnabarIsland_PokemonCenter_1F_Text_OhNotDoneYet::
	.string "Non? Toujours pas?$"

CinnabarIsland_PokemonCenter_1F_Text_LetsGo::
	.string "Allez, c'est parti!$"


PokemonLeague_LancesRoom_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_LancesRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, PokemonLeague_LancesRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_LancesRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_LancesRoom_OnFrame
	.byte 0

PokemonLeague_LancesRoom_OnResume::
	setvar VAR_0x8004, 3
	call PokemonLeague_EventScript_DoLightingEffect
	end

PokemonLeague_LancesRoom_OnLoad::
	call_if_eq VAR_MAP_SCENE_POKEMON_LEAGUE, 4, PokemonLeague_LancesRoom_EventScript_CloseEntry
	call_if_set FLAG_DEFEATED_LANCE, PokemonLeague_LancesRoom_EventScript_SetDoorOpen
	end

PokemonLeague_LancesRoom_EventScript_CloseEntry::
	call PokemonLeague_LancesRoom_EventScript_SetEntryClosed
	return

PokemonLeague_LancesRoom_EventScript_SetDoorOpen::
	call PokemonLeague_EventScript_SetDoorOpenLance
	return

PokemonLeague_LancesRoom_OnWarp::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_LancesRoom_EventScript_TurnPlayerNorth
	.2byte 0

PokemonLeague_LancesRoom_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

PokemonLeague_LancesRoom_OnFrame::
	map_script_2 VAR_MAP_SCENE_POKEMON_LEAGUE, 3, PokemonLeague_LancesRoom_EventScript_EnterRoom
	.2byte 0

PokemonLeague_LancesRoom_EventScript_EnterRoom::
	lockall
	applymovement LOCALID_PLAYER, PokemonLeague_LancesRoom_Movement_WalkThroughCorridor
	waitmovement 0
	setflag FLAG_TEMP_2
	call PokemonLeague_LancesRoom_EventScript_SetEntryClosed
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	setvar VAR_MAP_SCENE_POKEMON_LEAGUE, 4
	releaseall
	end

PokemonLeague_LancesRoom_EventScript_SetEntryClosed::
	setmetatile 5, 14, METATILE_PokemonLeague_Entry_TopLeft_Closed, 1
	setmetatile 6, 14, METATILE_PokemonLeague_Entry_TopMid_Closed, 1
	setmetatile 7, 14, METATILE_PokemonLeague_Entry_TopRight_Closed, 1
	setmetatile 5, 15, METATILE_PokemonLeague_Entry_BottomLeft_Closed, 1
	setmetatile 6, 15, METATILE_PokemonLeague_Entry_BottomMid_Closed, 1
	setmetatile 7, 15, METATILE_PokemonLeague_Entry_BottomRight_Closed, 1
	setmetatile 6, 16, METATILE_PokemonLeague_Floor_ShadeFull_Lance, 0
	setmetatile 7, 16, METATILE_PokemonLeague_Floor_ShadeFull_Lance, 0
	return

PokemonLeague_LancesRoom_Movement_WalkThroughCorridor::
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLeague_LancesRoom_EventScript_Lance::
	lock
	faceplayer
	famechecker FAMECHECKER_LANCE, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	goto_if_set FLAG_DEFEATED_LANCE, PokemonLeague_LancesRoom_EventScript_PostBattle
	famechecker FAMECHECKER_LANCE, 0
	famechecker FAMECHECKER_LANCE, 1
	call_if_unset FLAG_SYS_GAME_CLEAR, PokemonLeague_LancesRoom_EventScript_Intro
	call_if_set FLAG_SYS_GAME_CLEAR, PokemonLeague_LancesRoom_EventScript_RematchIntro
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	call_if_unset FLAG_IS_CHAMPION, PokemonLeague_LancesRoom_EventScript_Battle
	call_if_set FLAG_IS_CHAMPION, PokemonLeague_LancesRoom_EventScript_Rematch
	clearflag FLAG_TEMP_5
	goto PokemonLeague_LancesRoom_EventScript_DefeatedLance
	end

PokemonLeague_LancesRoom_EventScript_Intro::
	msgbox PokemonLeague_LancesRoom_Text_Intro
	return

PokemonLeague_LancesRoom_EventScript_RematchIntro::
	msgbox PokemonLeague_LancesRoom_Text_RematchIntro
	return

PokemonLeague_LancesRoom_EventScript_Battle::
	trainerbattle_no_intro TRAINER_ELITE_FOUR_LANCE, PokemonLeague_LancesRoom_Text_Defeat
	return

PokemonLeague_LancesRoom_EventScript_Rematch::
	trainerbattle_no_intro TRAINER_ELITE_FOUR_LANCE_2, PokemonLeague_LancesRoom_Text_Defeat
	return

PokemonLeague_LancesRoom_EventScript_PostBattle::
	msgbox PokemonLeague_LancesRoom_Text_PostBattle
	release
	end

PokemonLeague_LancesRoom_EventScript_DefeatedLance::
	setvar VAR_0x8004, 0
	special Script_TryGainNewFanFromCounterFrlg
	setflag FLAG_DEFEATED_LANCE
	call PokemonLeague_EventScript_OpenDoorLance
	msgbox PokemonLeague_LancesRoom_Text_PostBattle
	closemessage
	release
	end

PokemonLeague_LancesRoom_EventScript_LanceMoveOutOfWayLeft::
	applymovement LOCALID_LANCE, PokemonLeague_LancesRoom_Movement_LanceMoveOutOfWayLeft
	waitmovement 0
	return

PokemonLeague_LancesRoom_EventScript_LanceMoveOutOfWayRight::
	applymovement LOCALID_LANCE, PokemonLeague_LancesRoom_Movement_LanceMoveOutOfWayRight
	waitmovement 0
	return

PokemonLeague_LancesRoom_Movement_LanceMoveOutOfWayLeft::
	walk_left
	walk_in_place_faster_right
	step_end

PokemonLeague_LancesRoom_Movement_LanceMoveOutOfWayRight::
	walk_right
	walk_in_place_faster_left
	step_end

PokemonLeague_LancesRoom_Text_Intro::
	.string "Ah! Enfin… J'ai entendu parler\n"
	.string "de toi, {PLAYER}!\p"
	.string "Je règne sur le CONSEIL 4!\n"
	.string "Mon nom est PETER, le DRESSEUR\l"
	.string "de dragons!\p"
	.string "Les dragons sont des POKéMON\n"
	.string "mythiques!\p"
	.string "Les capturer et les entraîner est\n"
	.string "difficile mais leurs pouvoirs\l"
	.string "sont supérieurs!\p"
	.string "Ils sont presque invincibles!\p"
	.string "Le glas de la défaite et de la\n"
	.string "honte sonne pour toi…\p"
	.string "L'entends-tu, {PLAYER}!?{PLAY_BGM MUS_RG_ENCOUNTER_GYM_LEADER}$"

PokemonLeague_LancesRoom_Text_RematchIntro::
	.string "Ah! C'est encore toi,\n"
	.string "{PLAYER}!\p"
	.string "Je règne sur le CONSEIL 4!\n"
	.string "Moi, PETER, je suis le DRESSEUR\l"
	.string "de dragons!\p"
	.string "Les dragons sont des POKéMON\n"
	.string "mythiques!\p"
	.string "Les capturer et les entraîner est\n"
	.string "difficile mais leurs pouvoirs\l"
	.string "sont supérieurs!\p"
	.string "Ils sont presque invincibles!\p"
	.string "Le glas de la défaite et de la\n"
	.string "honte sonne pour toi…\p"
	.string "L'entends-tu, {PLAYER}?{PLAY_BGM MUS_RG_ENCOUNTER_GYM_LEADER}$"

PokemonLeague_LancesRoom_Text_Defeat::
	.string "Incroyable!\p"
	.string "Tu as bien mérité le titre de…\n"
	.string "MAITRE POKéMON!$"

PokemonLeague_LancesRoom_Text_PostBattle::
	.string "Comment mes dragons ont-ils\n"
	.string "pu succomber à tes attaques,\l"
	.string "{PLAYER}?\p"
	.string "Tu es désormais le MAITRE de\n"
	.string "la LIGUE POKéMON!\p"
	.string "Enfin… Pas tout à fait. Une\n"
	.string "épreuve doit encore t'être\l"
	.string "imposée…\p"
	.string "Un grand DRESSEUR t'attend.\n"
	.string "Son nom est…\p"
	.string "{RIVAL}!\p"
	.string "Il a vaincu le CONSEIL 4\n"
	.string "avant toi!\p"
	.string "C'est le vrai MAITRE de la\n"
	.string "LIGUE POKéMON!$"


SixIsland_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SixIsland_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SixIsland_PokemonCenter_1F_OnFrame
	.byte 0

SixIsland_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_SIX_ISLAND
	call_if_eq VAR_MAP_SCENE_SIX_ISLAND_POKEMON_CENTER_1F, 0, SixIsland_PokemonCenter_1F_EventScript_ShowRival
	end

SixIsland_PokemonCenter_1F_EventScript_ShowRival::
	clearflag FLAG_HIDE_SIX_ISLAND_POKECENTER_RIVAL
	return

SixIsland_PokemonCenter_1F_OnFrame::
	map_script_2 VAR_MAP_SCENE_SIX_ISLAND_POKEMON_CENTER_1F, 0, SixIsland_PokemonCenter_1F_EventScript_RivalScene
	.2byte 0

SixIsland_PokemonCenter_1F_EventScript_RivalScene::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_SIX_ISLAND_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	applymovement LOCALID_SIX_ISLAND_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SIX_ISLAND_RIVAL, Common_Movement_Delay48
	waitmovement 0
	delay 25
	applymovement LOCALID_SIX_ISLAND_RIVAL, SixIsland_PokemonCenter_1F_Movement_RivalApproach
	waitmovement 0
	msgbox SixIsland_PokemonCenter_1F_Text_RivalImpossibleToGetAllMonsAroundHere
	closemessage
	applymovement LOCALID_PLAYER, SixIsland_PokemonCenter_1F_Movement_PlayerWatchRivalExit
	applymovement LOCALID_SIX_ISLAND_RIVAL, SixIsland_PokemonCenter_1F_Movement_RivalExit
	waitmovement 0
	fadedefaultbgm
	playse SE_EXIT
	delay 35
	removeobject LOCALID_SIX_ISLAND_RIVAL
	setvar VAR_MAP_SCENE_SIX_ISLAND_POKEMON_CENTER_1F, 1
	setvar VAR_MAP_SCENE_FOUR_ISLAND, 1
	releaseall
	end

SixIsland_PokemonCenter_1F_Movement_RivalApproach::
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

SixIsland_PokemonCenter_1F_Movement_RivalExit::
	delay_16
	delay_4
	walk_down
	step_end

SixIsland_PokemonCenter_1F_Movement_PlayerWatchRivalExit::
	walk_left
	walk_in_place_faster_right
	step_end

SixIsland_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

SixIsland_PokemonCenter_1F_EventScript_Hiker::
	msgbox SixIsland_PokemonCenter_1F_Text_SomethingHiddenOnThisIsland, MSGBOX_NPC
	end

SixIsland_PokemonCenter_1F_EventScript_OldMan::
	msgbox SixIsland_PokemonCenter_1F_Text_SomeMonsEvolveByTradingWithHeldItem, MSGBOX_NPC
	end

SixIsland_PokemonCenter_1F_Text_SomethingHiddenOnThisIsland::
	.string "J'ai cherché les RUINES pendant\n"
	.string "dix ans…\p"
	.string "Mais non, en fait ça fait déjà\n"
	.string "vingt ans…\p"
	.string "Mais j'ai cette sensation qu'il y\n"
	.string "a quelque chose de caché ici.$"

SixIsland_PokemonCenter_1F_Text_SomeMonsEvolveByTradingWithHeldItem::
	.string "Tu sais que certains POKéMON\n"
	.string "évoluent grâce aux échanges, non?\p"
	.string "Mais savais-tu qu'il y en avait\n"
	.string "aussi d'autres?\p"
	.string "Ceux-là n'évoluent qu'en tenant\n"
	.string "certains objets pendant un échange.$"

SixIsland_PokemonCenter_1F_Text_RivalImpossibleToGetAllMonsAroundHere::
	.string "{RIVAL}: Salut {PLAYER}!\n"
	.string "Ça avance ton POKéDEX?\p"
	.string "J'crois bien que c'est pas possible\n"
	.string "d'attraper tous les POKéMON juste\p"
	.string "en les cherchant dans le coin.\p"
	.string "Y'en a peut-être dont on connaît\n"
	.string "rien, très loin d'ici.\p"
	.string "… … …  … … …  … … …\p"
	.string "Bon, de toute façon si j'y arrive\n"
	.string "pas, alors toi j'en parle même pas!\p"
	.string "Mais faut pas non plus que ça\n"
	.string "m'empêche de dormir.\p"
	.string "Je vais continuer de les attraper à\n"
	.string "mon rythme, tout en les entraînant.\p"
	.string "Alors ça sert à rien de rester ici,\n"
	.string "autant rentrer à la maison.\p"
	.string "Tchao minable!$"


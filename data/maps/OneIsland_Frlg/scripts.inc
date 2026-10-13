OneIsland_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OneIsland_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OneIsland_OnFrame
	.byte 0

OneIsland_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_ONE_ISLAND
	end

OneIsland_OnFrame::
	map_script_2 VAR_MAP_SCENE_ONE_ISLAND_HARBOR, 2, OneIsland_EventScript_EnterOneIslandFirstTime
	.2byte 0

OneIsland_EventScript_EnterOneIslandFirstTime::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_PLAYER, OneIsland_Movement_PlayerExitHarbor
	waitmovement 0
	msgbox OneIsland_Text_BillLetsGoSeeCelio
	closemessage
	applymovement LOCALID_ONE_ISLAND_BILL, OneIsland_Movement_BillWalkToPokeCenter
	applymovement LOCALID_PLAYER, OneIsland_Movement_PlayerWalkToPokeCenter
	waitmovement 0
	opendoor 14, 5
	waitdooranim
	applymovement LOCALID_ONE_ISLAND_BILL, OneIsland_Movement_BillEnterPokeCenter
	applymovement LOCALID_PLAYER, OneIsland_Movement_PlayerEnterPokeCenter
	waitmovement 0
	closedoor 14, 5
	waitdooranim
	removeobject LOCALID_ONE_ISLAND_BILL
	setvar VAR_MAP_SCENE_ONE_ISLAND_HARBOR, 3
	warp MAP_ONE_ISLAND_POKEMON_CENTER_1F, 9, 9
	waitstate
	releaseall
	end

	.macro walk_to_pokecenter
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	.endm

OneIsland_Movement_PlayerWalkToPokeCenter::
	walk_up
	walk_to_pokecenter
	step_end

OneIsland_Movement_PlayerEnterPokeCenter::
	walk_up
	walk_up
	set_invisible
	step_end

OneIsland_Movement_PlayerExitHarbor::
	walk_up
	step_end

OneIsland_Movement_BillWalkToPokeCenter::
	walk_to_pokecenter
	walk_up
	step_end

OneIsland_Movement_BillEnterPokeCenter::
	walk_up
	set_invisible
	step_end

OneIsland_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_IS_CHAMPION, OneIsland_EventScript_OldManLinkHoenn
	goto_if_set FLAG_SEVII_DETOUR_FINISHED, OneIsland_EventScript_OldManLinkKanto
	msgbox OneIsland_Text_LuckyToHaveCelioHere
	release
	end

OneIsland_EventScript_OldManLinkKanto::
	msgbox OneIsland_Text_HavePCLinkageWithKanto
	release
	end

OneIsland_EventScript_OldManLinkHoenn::
	msgbox OneIsland_Text_HavePCLinkageWithHoenn
	release
	end

OneIsland_EventScript_BaldingMan::
	msgbox OneIsland_Text_IsntWarmClimateHereGreat, MSGBOX_NPC
	end

OneIsland_EventScript_IslandSign::
	msgbox OneIsland_Text_IslandSign, MSGBOX_SIGN
	end

OneIsland_EventScript_PokemonNetCenterSign::
	msgbox OneIsland_Text_PokemonNetCenterSign, MSGBOX_SIGN
	end

OneIsland_Text_BillLetsGoSeeCelio::
	.string "LEO: On y est!\n"
	.string "Voilà l'ILE 1.\p"
	.string "Il y a plusieurs îles dans le coin,\n"
	.string "nous sommes sur l'une d'elles.\p"
	.string "Mon ami CILEO a mis ce bateau \n"
	.string "à ma disposition pour venir ici.\p"
	.string "Il a la responsabilité du réseau\n"
	.string "informatique de l'île.\p"
	.string "Mais tu auras une meilleure idée\n"
	.string "en le rencontrant, allons-y!$"

Text_WhereDoYouWantToSail::
	.string "Ohé, moussaillon!\n"
	.string "Où veux-tu aller?$"

OneIsland_Text_LuckyToHaveCelioHere::
	.string "Sur cette île, nous sommes vraiment\n"
	.string "au milieu de nulle part.\p"
	.string "Nous avons beaucoup de chance\n"
	.string "d'avoir quelqu'un comme CILEO.\p"
	.string "Ma petite-fille se met dans tous\n"
	.string "ses états pour un ami de CILEO.\p"
	.string "Quelque chose à voir avec un\n"
	.string "POKéMANIAC, ou un truc du genre.\p"
	.string "Je ne suis pas sûr de comprendre,\n"
	.string "mais CILEO est vraiment génial.$"

OneIsland_Text_HavePCLinkageWithKanto::
	.string "Ma petite-fille est toute excitée\n"
	.string "par une nouvelle invention.\p"
	.string "Elle dit que nous sommes connectés\n"
	.string "aux habitants de KANTO.\p"
	.string "Je ne suis pas sûr de comprendre,\n"
	.string "mais CILEO est vraiment génial.$"

OneIsland_Text_HavePCLinkageWithHoenn::
	.string "Ma petite-fille est toute excitée\n"
	.string "par une nouvelle invention.\p"
	.string "Elle dit que nous sommes enfin\n"
	.string "connectés aux habitants de HOENN.\p"
	.string "Je ne suis pas sûr de comprendre,\n"
	.string "mais CILEO est vraiment génial.\p"
	.string "Ce serait le mari idéal pour ma\n"
	.string "petite-fille.$"

OneIsland_Text_IslandSign::
	.string "ILE 1\n"
	.string "Les amis se réunissent ici$"

OneIsland_Text_PokemonNetCenterSign::
	.string "Pour relier le monde entier\n"
	.string "CENTRE RESEAU POKéMON$"

@ Unused
OneIsland_Text_ReturnToCinnabar::
	.string "グレンタウンに　もどりますか？$"

OneIsland_Text_IsntWarmClimateHereGreat::
	.string "Bonjour, tu fais du tourisme?\n"
	.string "Tu aimes le coin?$"


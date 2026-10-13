ThreeIsland_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ThreeIsland_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

ThreeIsland_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_THREE_ISLAND
	end

ThreeIsland_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

ThreeIsland_PokemonCenter_1F_EventScript_Sailor::
	msgbox ThreeIsland_PokemonCenter_1F_Text_ImpossibleToSurfBetweenIslands, MSGBOX_NPC
	end

ThreeIsland_PokemonCenter_1F_EventScript_Lass::
	msgbox ThreeIsland_PokemonCenter_1F_Text_AlwaysBerriesInBerryForest, MSGBOX_NPC
	end

ThreeIsland_PokemonCenter_1F_EventScript_Rocker::
	msgbox ThreeIsland_PokemonCenter_1F_Text_PCNetworkCanLinkWithKanto, MSGBOX_NPC
	end

ThreeIsland_PokemonCenter_1F_Text_PCNetworkCanLinkWithKanto::
	.string "Oh, t'es au courant?\p"
	.string "Notre réseau peut enfin se\n"
	.string "connecter aux PC DE KANTO.\p"
	.string "Je sais pas comment ils ont\n"
	.string "fait, mais la vache, c'est génial!$"

ThreeIsland_PokemonCenter_1F_Text_ImpossibleToSurfBetweenIslands::
	.string "Le SURF ne peut pas être pratiqué\n"
	.string "entre ces îles.\p"
	.string "Les courants sont beaucoup\n"
	.string "trop dangereux.$"

ThreeIsland_PokemonCenter_1F_Text_AlwaysBerriesInBerryForest::
	.string "Et si on broyait des BAIES?\p"
	.string "Il y en a tellement aux BOIS\n"
	.string "BAIES que ça serait pas du gâchis.$"


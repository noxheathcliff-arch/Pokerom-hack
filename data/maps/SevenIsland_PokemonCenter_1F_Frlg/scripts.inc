SevenIsland_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SevenIsland_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_SEVEN_ISLAND
	end

SevenIsland_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

SevenIsland_PokemonCenter_1F_EventScript_OldMan::
	msgbox SevenIsland_PokemonCenter_1F_Text_EventsDependingOnConnections, MSGBOX_NPC
	end

SevenIsland_PokemonCenter_1F_EventScript_Sailor::
	msgbox SevenIsland_PokemonCenter_1F_Text_DidYouRideSeagallopHere, MSGBOX_NPC
	end

SevenIsland_PokemonCenter_1F_EventScript_Beauty::
	msgbox SevenIsland_PokemonCenter_1F_Text_CheckOutTrainerTower, MSGBOX_NPC
	end

SevenIsland_PokemonCenter_1F_Text_EventsDependingOnConnections::
	.string "Sur cette île, des évènements\n"
	.string "se produisent selon les connexions.\p"
	.string "Tu me demandes lesquelles?\p"
	.string "Il y en a quatre que tu devras\n"
	.string "découvrir par toi-même.$"

SevenIsland_PokemonCenter_1F_Text_DidYouRideSeagallopHere::
	.string "Tu as déjà embarqué sur un\n"
	.string "FERRY FLECHE DES MERS?\p"
	.string "Il y en a au moins dix.\p"
	.string "Mais je ne connais malheureusement\n"
	.string "pas toutes leurs destinations.$"

SevenIsland_PokemonCenter_1F_Text_CheckOutTrainerTower::
	.string "Si tu crois en toi, tu devrais aller\n"
	.string "à la TOUR DRESSEURS.$"


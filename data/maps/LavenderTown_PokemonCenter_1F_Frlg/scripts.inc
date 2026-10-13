LavenderTown_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

LavenderTown_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_LAVENDER_TOWN
	end

LavenderTown_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

LavenderTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox LavenderTown_PokemonCenter_1F_Text_RocketsDoAnythingForMoney, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_1F_EventScript_Lass::
	msgbox LavenderTown_PokemonCenter_1F_Text_CubonesMotherKilledByRockets, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_1F_EventScript_Youngster::
	msgbox LavenderTown_PokemonCenter_1F_Text_PeoplePayForCuboneSkulls, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_1F_Text_RocketsDoAnythingForMoney::
	.string "La TEAM ROCKET ferait n'importe\n"
	.string "quoi pour de l'argent!$"

LavenderTown_PokemonCenter_1F_Text_CubonesMotherKilledByRockets::
	.string "J'ai vu la mère d'OSSELAIT\n"
	.string "essayer d'échapper à la \l"
	.string "TEAM ROCKET!\p"
	.string "Mais elle n'a pas réussi…$"

LavenderTown_PokemonCenter_1F_Text_PeoplePayForCuboneSkulls::
	.string "Les OSSELAIT portent un crâne,\n"
	.string "non?\p"
	.string "Certains seraient prêts à payer\n"
	.string "le prix fort pour en avoir un!$"


ViridianCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

ViridianCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_VIRIDIAN_CITY
	end

ViridianCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

ViridianCity_PokemonCenter_1F_EventScript_Boy::
	msgbox ViridianCity_PokemonCenter_1F_Text_PokeCenterInEveryTown, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox ViridianCity_PokemonCenter_1F_Text_FeelFreeToUsePC, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox ViridianCity_PokemonCenter_1F_Text_PokeCentersHealMons, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_1F_Text_FeelFreeToUsePC::
	.string "Tu peux utiliser le PC.\p"
	.string "C'est l'hôtesse qui me l'a dit!\n"
	.string "Elle est mignonne en plus!$"

ViridianCity_PokemonCenter_1F_Text_PokeCenterInEveryTown::
	.string "Il y a un CENTRE POKéMON dans\n"
	.string "chaque grande ville.\p"
	.string "Tu peux y soigner gratuitement tes\n"
	.string "POKéMON!$"

ViridianCity_PokemonCenter_1F_Text_PokeCentersHealMons::
	.string "Les CENTRES POKéMON soignent tous\n"
	.string "les POKéMON blessés ou KO!$"


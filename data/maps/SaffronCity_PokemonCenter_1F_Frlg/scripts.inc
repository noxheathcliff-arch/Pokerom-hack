SaffronCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SaffronCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_SAFFRON_CITY
	end

SaffronCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

SaffronCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox SaffronCity_PokemonCenter_1F_Text_SilphCoVictimOfFame, MSGBOX_NPC
	end

SaffronCity_PokemonCenter_1F_EventScript_Woman::
	msgbox SaffronCity_PokemonCenter_1F_Text_GrowthRatesDifferBySpecies, MSGBOX_NPC
	end

SaffronCity_PokemonCenter_1F_EventScript_Youngster::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_SILPH_CO_11F, 1, SaffronCity_PokemonCenter_1F_EventScript_YoungsterRocketsGone
	msgbox SaffronCity_PokemonCenter_1F_Text_GreatIfEliteFourCameBeatRockets
	release
	end

SaffronCity_PokemonCenter_1F_EventScript_YoungsterRocketsGone::
	msgbox SaffronCity_PokemonCenter_1F_Text_TeamRocketTookOff
	release
	end

SaffronCity_PokemonCenter_1F_Text_GrowthRatesDifferBySpecies::
	.string "Les POKéMON grandissent\n"
	.string "différemment selon les espèces.$"

SaffronCity_PokemonCenter_1F_Text_SilphCoVictimOfFame::
	.string "La SYLPHE SARL est très connue.\p"
	.string "C'est pourquoi la TEAM ROCKET l'a\n"
	.string "investie!$"

SaffronCity_PokemonCenter_1F_Text_GreatIfEliteFourCameBeatRockets::
	.string "Pourquoi le CONSEIL 4 ne vient\n"
	.string "pas chasser la TEAM ROCKET?$"

SaffronCity_PokemonCenter_1F_Text_TeamRocketTookOff::
	.string "La TEAM ROCKET est partie!\n"
	.string "Alors c'est la fête! Youpi!$"


CeladonCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

CeladonCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_CELADON_CITY
	end

CeladonCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

CeladonCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox CeladonCity_PokemonCenter_1F_Text_PokeFluteAwakensSleepingMons, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_1F_EventScript_CooltrainerF::
	msgbox CeladonCity_PokemonCenter_1F_Text_RodeHereFromFuchsia, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox CeladonCity_PokemonCenter_1F_Text_GoToCyclingRoadIfIHadBike, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_1F_Text_PokeFluteAwakensSleepingMons::
	.string "La POKéFLUTE réveille les POKéMON\n"
	.string "grâce aux ultrasons!$"

CeladonCity_PokemonCenter_1F_Text_RodeHereFromFuchsia::
	.string "J'ai pris la PISTE CYCLABLE depuis\n"
	.string "PARMANIE!\p"
	.string "Je suis complètement épuisée.$"

CeladonCity_PokemonCenter_1F_Text_GoToCyclingRoadIfIHadBike::
	.string "Si j'avais une BICYCLETTE, j'irais\n"
	.string "sur la PISTE CYCLABLE!$"


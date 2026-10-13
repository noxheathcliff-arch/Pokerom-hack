FuchsiaCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FuchsiaCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_FUCHSIA_CITY
	end

FuchsiaCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

FuchsiaCity_PokemonCenter_1F_EventScript_Man::
	msgbox FuchsiaCity_PokemonCenter_1F_Text_CantBecomeGoodTrainerWithOneMon, MSGBOX_NPC
	end

FuchsiaCity_PokemonCenter_1F_EventScript_CooltrainerF::
	msgbox FuchsiaCity_PokemonCenter_1F_Text_PokemonLeagueWestOfViridian, MSGBOX_NPC
	end

FuchsiaCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox FuchsiaCity_PokemonCenter_1F_Text_VisitSafariZoneForPokedex, MSGBOX_NPC
	end

FuchsiaCity_PokemonCenter_1F_Text_CantBecomeGoodTrainerWithOneMon::
	.string "Un seul POKéMON puissant n'est pas\n"
	.string "suffisant.\p"
	.string "Mais tous les faire évoluer de\n"
	.string "façon égale n'est pas facile.$"

FuchsiaCity_PokemonCenter_1F_Text_PokemonLeagueWestOfViridian::
	.string "Il y a un petit passage à l'Ouest\n"
	.string "de JADIELLE.\p"
	.string "Il mène au quartier général de la\n"
	.string "LIGUE POKéMON. Ce QG est la plus\l"
	.string "haute autorité des DRESSEURS.$"

FuchsiaCity_PokemonCenter_1F_Text_VisitSafariZoneForPokedex::
	.string "LE PARC SAFARI regorge de\n"
	.string "POKéMON.\p"
	.string "On peut y trouver plein\n"
	.string "de POKéMON très rares!$"


CeruleanCity_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

CeruleanCity_PokemonCenter_1F_OnTransition::
	setrespawn HEAL_LOCATION_CERULEAN_CITY
	end

CeruleanCity_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

CeruleanCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox CeruleanCity_PokemonCenter_1F_Text_EveryoneCallsBillPokemaniac, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_1F_EventScript_Rocker::
	msgbox CeruleanCity_PokemonCenter_1F_Text_BillDoesWhateverForRareMons, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_1F_EventScript_Youngster::
	lock
	faceplayer
	famechecker FAMECHECKER_BILL, 1
	msgbox CeruleanCity_PokemonCenter_1F_Text_BillCollectsRareMons
	release
	end

CeruleanCity_PokemonCenter_1F_EventScript_Lass::
	msgbox CeruleanCity_PokemonCenter_1F_Text_TryTradingUpstairs, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_1F_Text_BillDoesWhateverForRareMons::
	.string "Sacré LEO!\p"
	.string "Il donnerait n'importe quoi pour\n"
	.string "mettre la main sur un POKéMON\l"
	.string "rare!$"

CeruleanCity_PokemonCenter_1F_Text_EveryoneCallsBillPokemaniac::
	.string "Tu connais LEO?\p"
	.string "On raconte que c'est un vrai\n"
	.string "POKéMANIAC!\p"
	.string "Les gens sont juste jaloux\n"
	.string "de LEO.\p"
	.string "Nous sommes tous un peu \n"
	.string "POKéMANIAC, non?$"

CeruleanCity_PokemonCenter_1F_Text_BillCollectsRareMons::
	.string "LEO a une sacrée collection de\n"
	.string "POKéMON!\p"
	.string "Et des rares, en plus…$"

CeruleanCity_PokemonCenter_1F_Text_TryTradingUpstairs::
	.string "Tu devrais aller à l'étage pour\n"
	.string "faire des échanges avec tes amis.\p"
	.string "Tu peux avoir plus de POKéMON\n"
	.string "en faisant des échanges.\p"
	.string "En plus, les POKéMON échangés\n"
	.string "grandissent plus rapidement.$"


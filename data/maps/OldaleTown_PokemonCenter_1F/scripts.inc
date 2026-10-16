OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_OLDALE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
	.string "Le PC du coin est ouvert aux Dresseurs.\n"
	.string "Enfin… aux Dresseurs recensés.\p"
	.string "On dit que le Rempart lit les registres\n"
	.string "de stockage. Moi, je n’y mets plus rien.$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
	.string "Le Centre soigne gratuitement.\n"
	.string "Même les arrivants, figure-toi.\p"
	.string "Mon oncle trouve ça scandaleux.\n"
	.string "Moi, je trouve que l’infirmière a raison.$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.string "L’étage est fermé jusqu’à nouvel ordre.\n"
	.string "Ordre de qui? Personne ne sait.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.string "L’étage du Centre est fermé. Les\n"
	.string "échanges à distance sont suspendus.\p"
	.string "Paraît que la Passerelle fera mieux.\n"
	.string "‘Le monde en une seconde.’\p"
	.string "Le monde? Moi, je voudrais juste\n"
	.string "joindre ma sœur à Mérouville.$"


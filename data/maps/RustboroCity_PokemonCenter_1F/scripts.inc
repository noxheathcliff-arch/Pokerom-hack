RustboroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_PokemonCenter_1F_OnFrame
	.byte 0

RustboroCity_PokemonCenter_1F_OnFrame:
	@ Demo: C11 end-of-demo scene (VAR_ROUTE116_STATE 2 = C10 done)
	map_script_2 VAR_ROUTE116_STATE, 2, CF_C11_Scene
	.2byte 0

RustboroCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_RUSTBORO_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Man::
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Boy::
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Girl::
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities:
	.string "Mon Pokémon est Naïf, celui de mon\n"
	.string "ami est Jovial. Chacun sa nature.\p"
	.string "Les arrivants aussi ont un caractère.\n"
	.string "J’en ai vu un protéger son petit.\p"
	.string "Ça ne colle pas avec ce que\n"
	.string "raconte le Rempart.$"

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon:
	.string "Le Centre est plein de mineurs\n"
	.string "blessés. Et de leurs Pokémon.\p"
	.string "Éboulements, morsures… Les\n"
	.string "galeries ne pardonnent pas.\p"
	.string "L’infirmière n’a pas dormi depuis\n"
	.string "trois jours. Sois patient.$"

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor:
	.string "Tu as vu les affiches dehors?\n"
	.string "‘Il a sauvé Sylphe.’\p"
	.string "Un garçon de Kanto, casquette rouge.\n"
	.string "Paraît qu’il est ici, à Hoenn.\p"
	.string "Les gens disent qu’il porte malheur.\n"
	.string "Les anneaux l’auraient suivi.$"


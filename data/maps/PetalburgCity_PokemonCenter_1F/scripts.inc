PetalburgCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

PetalburgCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

PetalburgCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_PETALBURG_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_FatMan::
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP, MSGBOX_NPC
	end

PetalburgCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	msgbox PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsStarterInParty
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo::
	call_if_eq VAR_STARTER_MON, 0, PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType
	call_if_eq VAR_STARTER_MON, 1, PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType
	call_if_eq VAR_STARTER_MON, 2, PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_SayTreeckoType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayTorchicType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_SayMudkipType::
	msgbox PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_Text_PCStorageSystem:
	.string "Le stockage PC, quelle invention.\n"
	.string "Ou quelle surveillance, c’est selon.\p"
	.string "On dit que le Rempart consulte\n"
	.string "les boîtes de tout le monde.\p"
	.string "Moi, j’ai vidé les miennes.\n"
	.string "On n’est jamais trop prudent.$"

PetalburgCity_PokemonCenter_1F_Text_OranBerryRegainedHP:
	.string "Quand mon POKéMON mange une\n"
	.string "BAIE ORAN, il récupère des PV!$"

PetalburgCity_PokemonCenter_1F_Text_ManyTypesOfPokemon:
	.string "Chaque type a ses forces\n"
	.string "et ses faiblesses.\p"
	.string "Les arrivants aussi, figure-toi.\n"
	.string "Ils ne sont pas invincibles.\p"
	.string "Les gens l’oublient, avec la peur.\n"
	.string "Un bon type, et ils reculent.$"

PetalburgCity_PokemonCenter_1F_Text_TreeckoIsGrassType:
	.string "Ton Arcko, par exemple, est de type\n"
	.string "Plante.\p"
	.string "Fort contre l’Eau et le Sol,\n"
	.string "mais faible face au Feu.\p"
	.string "Évite les arrivants qui crachent\n"
	.string "des flammes. Il y en a.$"

PetalburgCity_PokemonCenter_1F_Text_TorchicIsFireType:
	.string "Ton Poussifeu, par exemple, est\n"
	.string "de type Feu.\p"
	.string "Fort contre la Plante et l’Insecte,\n"
	.string "mais faible face à l’Eau.\p"
	.string "Au Bois Clémenti, il fera des\n"
	.string "ravages. Attention aux arbres.$"

PetalburgCity_PokemonCenter_1F_Text_MudkipIsWaterType:
	.string "Ton Gobou, par exemple, est de type\n"
	.string "Eau.\p"
	.string "Fort contre le Feu, mais faible\n"
	.string "face à la Plante et à l’Électrik.\p"
	.string "Au Bois Clémenti, sois prudent.\n"
	.string "Tout y est vert.$"


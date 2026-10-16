RustboroCity_Flat1_1F_MapScripts::
	.byte 0

RustboroCity_Flat1_1F_EventScript_Man::
	msgbox RustboroCity_Flat1_1F_Text_EveryPokemonHasAbility, MSGBOX_NPC
	end

RustboroCity_Flat1_1F_EventScript_Woman::
	msgbox RustboroCity_Flat1_1F_Text_PokemonStrange, MSGBOX_NPC
	end

RustboroCity_Flat1_1F_Text_EveryPokemonHasAbility:
	.string "Chaque Pokémon a un talent\n"
	.string "bien à lui.\p"
	.string "Ceux des arrivants, on ne les\n"
	.string "connaît pas. C’est ça qui fait peur.$"

RustboroCity_Flat1_1F_Text_PokemonStrange:
	.string "Hé! On frappe avant d’entrer!\n"
	.string "On n’est pas dans un moulin!\p"
	.string "Avec ce qui tombe du ciel, entrer\n"
	.string "chez les gens sans prévenir…\p"
	.string "… Bon, ça va. Tu n’as pas l’air\n"
	.string "d’un arrivant. Enfin, je crois.$"


OldaleTown_House2_MapScripts::
	.byte 0

OldaleTown_House2_EventScript_Woman::
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man::
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp:
	.string "Mon fils veut s’engager dans la brigade.\n"
	.string "Il a quatorze ans.\p"
	.string "Les Pokémon s’endurcissent au combat.\n"
	.string "Les enfants aussi, hélas.$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon:
	.string "Avec une équipe forte, on va plus loin.\n"
	.string "Moi, je veux aller jusqu’à Clémenti.\p"
	.string "Le Rempart recrute, là-bas. Norman\n"
	.string "donne un insigne à ceux qui tiennent.\p"
	.string "Maman ne veut pas. Mais Maman\n"
	.string "ne sort plus de la maison.$"


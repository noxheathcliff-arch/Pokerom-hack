RustboroCity_House3_MapScripts::
	.byte 0

RustboroCity_House3_EventScript_OldMan::
	msgbox RustboroCity_House3_Text_IGivePerfectlySuitedNicknames, MSGBOX_NPC
	end

RustboroCity_House3_EventScript_OldWoman::
	msgbox RustboroCity_House3_Text_NamingPikachuPekachu, MSGBOX_NPC
	end

@ Misspelling on purpose, see nickname
RustboroCity_House3_EventScript_Pekachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox RustboroCity_House3_Text_Pekachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_House3_Text_IGivePerfectlySuitedNicknames:
	.string "Hé! On frappe avant d’entrer, jeune\n"
	.string "homme! Ça se fait encore, non?\p"
	.string "Bon. Moi, je donne à mes Pokémon\n"
	.string "des surnoms parfaits.\p"
	.string "Celui-là, c’est Pekachu. Un Pikachu\n"
	.string "de Kanto. Il ne quitte pas la maison.\p"
	.string "La brigade n’aime pas trop\n"
	.string "les Pokémon de Kanto, ces temps-ci.$"

RustboroCity_House3_Text_NamingPikachuPekachu:
	.string "Pekachu… Mon mari n’a aucune\n"
	.string "imagination.\p"
	.string "Mais je l’aime, ce petit. Un Pikachu\n"
	.string "ici, c’est rare. Et mal vu.\p"
	.string "Si tu vois la brigade dans la rue,\n"
	.string "ne leur parle pas de lui.$"

RustboroCity_House3_Text_Pekachu:
	.string "PEKACHU: Peka!$"


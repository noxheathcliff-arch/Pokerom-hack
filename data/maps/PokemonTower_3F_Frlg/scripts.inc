PokemonTower_3F_Frlg_MapScripts::
	.byte 0

PokemonTower_3F_EventScript_Patricia::
	trainerbattle_single TRAINER_CHANNELER_PATRICIA, PokemonTower_3F_Text_PatriciaIntro, PokemonTower_3F_Text_PatriciaDefeat
	msgbox PokemonTower_3F_Text_PatriciaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_3F_EventScript_Carly::
	trainerbattle_single TRAINER_CHANNELER_CARLY, PokemonTower_3F_Text_CarlyIntro, PokemonTower_3F_Text_CarlyDefeat
	msgbox PokemonTower_3F_Text_CarlyPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_3F_EventScript_Hope::
	trainerbattle_single TRAINER_CHANNELER_HOPE, PokemonTower_3F_Text_HopeIntro, PokemonTower_3F_Text_HopeDefeat
	msgbox PokemonTower_3F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_3F_Text_HopeIntro::
	.string "Urrg… Awaa…\n"
	.string "Huhu… graa…$"

PokemonTower_3F_Text_HopeDefeat::
	.string "Ha!\n"
	.string "Je suis sauvée!$"

PokemonTower_3F_Text_HopePostBattle::
	.string "Un SPECTRE est identifiable avec\n"
	.string "un SCOPE SYLPHE.$"

PokemonTower_3F_Text_CarlyIntro::
	.string "Kekeke…\n"
	.string "Kwaaah!$"

PokemonTower_3F_Text_CarlyDefeat::
	.string "Hmm?\n"
	.string "Qu'est-ce que je fais là?$"

PokemonTower_3F_Text_CarlyPostBattle::
	.string "Pardon!\n"
	.string "J'étais possédée!$"

PokemonTower_3F_Text_PatriciaIntro::
	.string "VADE RETRO!\n"
	.string "Esprit infernal!$"

PokemonTower_3F_Text_PatriciaDefeat::
	.string "Pfiou!\n"
	.string "L'esprit s'en est allé!$"

PokemonTower_3F_Text_PatriciaPostBattle::
	.string "Mes amies étaient aussi possédées!$"


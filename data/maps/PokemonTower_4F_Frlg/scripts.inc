PokemonTower_4F_Frlg_MapScripts::
	.byte 0

PokemonTower_4F_EventScript_Paula::
	trainerbattle_single TRAINER_CHANNELER_PAULA, PokemonTower_4F_Text_PaulaIntro, PokemonTower_4F_Text_PaulaDefeat
	msgbox PokemonTower_4F_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_4F_EventScript_Laurel::
	trainerbattle_single TRAINER_CHANNELER_LAUREL, PokemonTower_4F_Text_LaurelIntro, PokemonTower_4F_Text_LaurelDefeat
	msgbox PokemonTower_4F_Text_LaurelPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_4F_EventScript_Jody::
	trainerbattle_single TRAINER_CHANNELER_JODY, PokemonTower_4F_Text_JodyIntro, PokemonTower_4F_Text_JodyDefeat
	msgbox PokemonTower_4F_Text_JodyPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_4F_Text_PaulaIntro::
	.string "Un SPECTRE!\n"
	.string "Rhaaaaaa!$"

PokemonTower_4F_Text_PaulaDefeat::
	.string "Ben!\n"
	.string "Où est le SPECTRE?$"

PokemonTower_4F_Text_PaulaPostBattle::
	.string "J'ai dû rêver…$"

PokemonTower_4F_Text_LaurelIntro::
	.string "Sois maudit!!!!\n"
	.string "Kwaaah!$"

PokemonTower_4F_Text_LaurelDefeat::
	.string "QUOI!$"

PokemonTower_4F_Text_LaurelPostBattle::
	.string "Nous ne pouvons pas identifier\n"
	.string "les SPECTRES.$"

PokemonTower_4F_Text_JodyIntro::
	.string "Huhuhu…\n"
	.string "Ne me frappe pas!$"

PokemonTower_4F_Text_JodyDefeat::
	.string "Hein?\n"
	.string "Qui? Quoi?$"

PokemonTower_4F_Text_JodyPostBattle::
	.string "Que les âmes des POKéMON\n"
	.string "disparus reposent en paix!$"


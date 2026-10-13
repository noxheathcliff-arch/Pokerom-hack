PokemonMansion_B1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonMansion_B1F_OnLoad
	.byte 0

PokemonMansion_B1F_OnLoad::
	call_if_set FLAG_POKEMON_MANSION_SWITCH_STATE, PokemonMansion_EventScript_PressSwitch_B1F
	end

PokemonMansion_B1F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 3
	call PokemonMansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

PokemonMansion_B1F_EventScript_DiarySep1st::
	msgbox PokemonMansion_B1F_Text_MewtwoIsFarTooPowerful, MSGBOX_SIGN
	end

PokemonMansion_B1F_EventScript_Lewis::
	trainerbattle_single TRAINER_BURGLAR_LEWIS, PokemonMansion_B1F_Text_LewisIntro, PokemonMansion_B1F_Text_LewisDefeat
	msgbox PokemonMansion_B1F_Text_LewisPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_B1F_EventScript_Ivan::
	trainerbattle_single TRAINER_SCIENTIST_IVAN, PokemonMansion_B1F_Text_IvanIntro, PokemonMansion_B1F_Text_IvanDefeat
	msgbox PokemonMansion_B1F_Text_IvanPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_B1F_Text_LewisIntro::
	.string "Oh-oh.\n"
	.string "Où que je suis, moi?$"

PokemonMansion_B1F_Text_LewisDefeat::
	.string "Oups.$"

PokemonMansion_B1F_Text_LewisPostBattle::
	.string "De bons objets traînent dans\n"
	.string "le coin.$"

PokemonMansion_B1F_Text_IvanIntro::
	.string "La science?\n"
	.string "C'est le pied.$"

PokemonMansion_B1F_Text_IvanDefeat::
	.string "…\n"
	.string "Bah pourquoi?$"

PokemonMansion_B1F_Text_IvanPostBattle::
	.string "J'adore cet endroit! J'y fais mon\n"
	.string "internat!$"

PokemonMansion_B1F_Text_MewtwoIsFarTooPowerful::
	.string "Rapport: 1er Septembre.\n"
	.string "MEWTWO est trop puissant.\p"
	.string "Nous sommes impuissants face à\n"
	.string "ses pièges…$"


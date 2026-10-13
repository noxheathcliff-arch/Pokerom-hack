PokemonMansion_3F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PokemonMansion_3F_OnLoad
	.byte 0

PokemonMansion_3F_OnLoad::
	call_if_set FLAG_POKEMON_MANSION_SWITCH_STATE, PokemonMansion_EventScript_PressSwitch_3F
	end

PokemonMansion_3F_EventScript_Statue::
	lockall
	setvar VAR_0x8004, 2
	call PokemonMansion_EventScript_SecretSwitch
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	releaseall
	end

PokemonMansion_3F_EventScript_DiaryFeb6th::
	msgbox PokemonMansion_1F_Text_MewGaveBirthToMewtwo, MSGBOX_SIGN
	end

PokemonMansion_3F_EventScript_Simon::
	trainerbattle_single TRAINER_BURGLAR_SIMON, PokemonMansion_1F_Text_SimonIntro, PokemonMansion_1F_Text_SimonDefeat
	msgbox PokemonMansion_1F_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_3F_EventScript_Braydon::
	trainerbattle_single TRAINER_SCIENTIST_BRAYDON, PokemonMansion_1F_Text_BraydonIntro, PokemonMansion_1F_Text_BraydonDefeat
	msgbox PokemonMansion_1F_Text_BraydonPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonMansion_1F_Text_SimonIntro::
	.string "Fouiii…\n"
	.string "C'est grand ici!$"

PokemonMansion_1F_Text_SimonDefeat::
	.string "Yargl!$"

PokemonMansion_1F_Text_SimonPostBattle::
	.string "Mais où est donc mon complice?$"

PokemonMansion_1F_Text_BraydonIntro::
	.string "Mon mentor vivait ici autrefois.$"

PokemonMansion_1F_Text_BraydonDefeat::
	.string "!!!\n"
	.string "Impressionnant!$"

PokemonMansion_1F_Text_BraydonPostBattle::
	.string "T'as perdu ton chemin?\n"
	.string "Essaie de sauter par là-bas!$"

PokemonMansion_1F_Text_MewGaveBirthToMewtwo::
	.string "Rapport: 6 Février.\n"
	.string "MEW est papa (ou maman?).\p"
	.string "Le petit a été baptisé MEWTWO.$"


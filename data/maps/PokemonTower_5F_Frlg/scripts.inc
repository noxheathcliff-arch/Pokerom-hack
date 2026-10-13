PokemonTower_5F_Frlg_MapScripts::
	.byte 0

PokemonTower_5F_EventScript_Channeler::
	msgbox PokemonTower_5F_Text_RestHereInPurifiedSpace, MSGBOX_NPC
	end

PokemonTower_5F_EventScript_PurifiedZone::
	lockall
	fadescreen FADE_TO_WHITE
	special HealPlayerParty
	fadescreen FADE_FROM_WHITE
	msgbox PokemonTower_5F_Text_PurifiedZoneMonsFullyHealed
	setvar VAR_TEMP_1, 1
	releaseall
	end

PokemonTower_5F_EventScript_ExitPurifiedZone::
	lockall
	setvar VAR_TEMP_1, 0
	releaseall
	end

PokemonTower_5F_EventScript_Tammy::
	trainerbattle_single TRAINER_CHANNELER_TAMMY, PokemonTower_5F_Text_TammyIntro, PokemonTower_5F_Text_TammyDefeat
	msgbox PokemonTower_5F_Text_TammyPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_EventScript_Ruth::
	trainerbattle_single TRAINER_CHANNELER_RUTH, PokemonTower_5F_Text_RuthIntro, PokemonTower_5F_Text_RuthDefeat
	msgbox PokemonTower_5F_Text_RuthPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_EventScript_Karina::
	trainerbattle_single TRAINER_CHANNELER_KARINA, PokemonTower_5F_Text_KarinaIntro, PokemonTower_5F_Text_KarinaDefeat
	msgbox PokemonTower_5F_Text_KarinaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_EventScript_Janae::
	trainerbattle_single TRAINER_CHANNELER_JANAE, PokemonTower_5F_Text_JanaeIntro, PokemonTower_5F_Text_JanaeDefeat
	msgbox PokemonTower_5F_Text_JanaePostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_Text_RestHereInPurifiedSpace::
	.string "Approche, enfant!\p"
	.string "J'ai scellé cet endroit grâce à\n"
	.string "ma sainte magie blanche!\p"
	.string "Tu peux te reposer ici!$"

PokemonTower_5F_Text_TammyIntro::
	.string "Donne… moi…\n"
	.string "ton… âme…$"

PokemonTower_5F_Text_TammyDefeat::
	.string "Glargh!$"

PokemonTower_5F_Text_TammyPostBattle::
	.string "J'étais possédée!$"

PokemonTower_5F_Text_RuthIntro::
	.string "Viens… avec…\n"
	.string "nous…$"

PokemonTower_5F_Text_RuthDefeat::
	.string "Hein!\n"
	.string "J'ai fait un cauchemar!$"

PokemonTower_5F_Text_RuthPostBattle::
	.string "J'étais possédée!$"

PokemonTower_5F_Text_KarinaIntro::
	.string "Zombis!$"

PokemonTower_5F_Text_KarinaDefeat::
	.string "Hein?$"

PokemonTower_5F_Text_KarinaPostBattle::
	.string "Je suis revenue à la raison!$"

PokemonTower_5F_Text_JanaeIntro::
	.string "Poyé Polomi!\n"
	.string "Le mal est parmi nous…$"

PokemonTower_5F_Text_JanaeDefeat::
	.string "Quoi?\n"
	.string "Jeune taoïste, tu oses m'ôter le\l"
	.string "yang de la bouche!$"

PokemonTower_5F_Text_JanaePostBattle::
	.string "Mon Tao à moi, c'est le plus beau\n"
	.string "des Taos!$"

PokemonTower_5F_Text_PurifiedZoneMonsFullyHealed::
	.string "Vous pénétrez dans une zone\n"
	.string "sanctuaire!\p"
	.string "Les POKéMON de {PLAYER} sont\n"
	.string "soignés!$"


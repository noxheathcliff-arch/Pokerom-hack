PokemonTower_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonTower_1F_OnTransition
	.byte 0

PokemonTower_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_POKEMON_TOWER_1F
	end

PokemonTower_1F_EventScript_Channeler::
	msgbox PokemonTower_1F_Text_SenseSpiritsUpToMischief, MSGBOX_NPC
	end

PokemonTower_1F_EventScript_Woman1::
	msgbox PokemonTower_1F_Text_GrowlitheWhyDidYouDie, MSGBOX_NPC
	end

PokemonTower_1F_EventScript_BaldingMan::
	msgbox PokemonTower_1F_Text_CameToPrayForDepartedClefairy, MSGBOX_NPC
	end

PokemonTower_1F_EventScript_Woman2::
	lock
	faceplayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, PokemonTower_1F_EventScript_Woman2MalePlayer
	msgbox PokemonTower_1F_Text_ComeToPayRespectsGirl
	release
	end

PokemonTower_1F_EventScript_Woman2MalePlayer::
	msgbox PokemonTower_1F_Text_ComeToPayRespectsSon
	release
	end

PokemonTower_1F_EventScript_WorkerF::
	msgbox PokemonTower_1F_Text_ErectedInMemoryOfDeadMons, MSGBOX_NPC
	end

PokemonTower_1F_Text_ErectedInMemoryOfDeadMons::
	.string "La TOUR POKéMON a été érigée en\n"
	.string "mémoire des braves POKéMON\l"
	.string "disparus au combat.$"

PokemonTower_1F_Text_ComeToPayRespectsSon::
	.string "Tu es venu leur rendre hommage?\p"
	.string "C'est tout à ton honneur,\n"
	.string "mon petit!$"

PokemonTower_1F_Text_ComeToPayRespectsGirl::
	.string "Tu es venu leur rendre hommage?\p"
	.string "C'est tout à ton honneur,\n"
	.string "ma petite!$"

PokemonTower_1F_Text_CameToPrayForDepartedClefairy::
	.string "Je suis venu prier pour mon\n"
	.string "MELOFEE.\p"
	.string "Sniff!\n"
	.string "J'arrête pas de pleurer…$"

PokemonTower_1F_Text_GrowlitheWhyDidYouDie::
	.string "Mon CANINOS…\n"
	.string "Tu me manques…$"

PokemonTower_1F_Text_SenseSpiritsUpToMischief::
	.string "Je suis une EXORCISTE!\n"
	.string "Je chasse les esprits!$"


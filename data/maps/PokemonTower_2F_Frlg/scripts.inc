PokemonTower_2F_Frlg_MapScripts::
	.byte 0

PokemonTower_2F_EventScript_Channeler::
	msgbox PokemonTower_2F_Text_SilphScopeCouldUnmaskGhosts, MSGBOX_NPC
	end

PokemonTower_2F_EventScript_RivalTriggerRight::
	lockall
	setvar VAR_TEMP_1, 0
	goto PokemonTower_2F_EventScript_Rival
	end

PokemonTower_2F_EventScript_RivalTriggerDown::
	lockall
	setvar VAR_TEMP_1, 1
	goto PokemonTower_2F_EventScript_Rival
	end

PokemonTower_2F_EventScript_Rival::
	textcolor NPC_TEXT_COLOR_MALE
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	call_if_eq VAR_TEMP_1, 0, PokemonTower_2F_EventScript_RivalFacePlayerRight
	call_if_eq VAR_TEMP_1, 1, PokemonTower_2F_EventScript_RivalFacePlayerDown
	applymovement LOCALID_POKEMON_TOWER_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_POKEMON_TOWER_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox PokemonTower_2F_Text_RivalIntro
	setvar VAR_LAST_TALKED, LOCALID_POKEMON_TOWER_RIVAL
	call_if_eq VAR_STARTER_MON, 2, PokemonTower_2F_EventScript_RivalSquirtle
	call_if_eq VAR_STARTER_MON, 1, PokemonTower_2F_EventScript_RivalBulbasaur
	call_if_eq VAR_STARTER_MON, 0, PokemonTower_2F_EventScript_RivalCharmander
	msgbox PokemonTower_2F_Text_RivalPostBattle
	closemessage
	playbgm MUS_RG_RIVAL_EXIT, 0
	call_if_eq VAR_TEMP_1, 0, PokemonTower_2F_EventScript_RivalExitRight
	call_if_eq VAR_TEMP_1, 1, PokemonTower_2F_EventScript_RivalExitDown
	playse SE_EXIT
	delay 25
	fadedefaultbgm
	removeobject LOCALID_POKEMON_TOWER_RIVAL
	setvar VAR_MAP_SCENE_POKEMON_TOWER_2F, 1
	releaseall
	end

PokemonTower_2F_EventScript_RivalFacePlayerRight::
	applymovement LOCALID_POKEMON_TOWER_RIVAL, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

PokemonTower_2F_EventScript_RivalFacePlayerDown::
	applymovement LOCALID_POKEMON_TOWER_RIVAL, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

PokemonTower_2F_EventScript_RivalSquirtle::
	trainerbattle_no_intro TRAINER_RIVAL_POKEMON_TOWER_SQUIRTLE, PokemonTower_2F_Text_RivalDefeat
	return

PokemonTower_2F_EventScript_RivalBulbasaur::
	trainerbattle_no_intro TRAINER_RIVAL_POKEMON_TOWER_BULBASAUR, PokemonTower_2F_Text_RivalDefeat
	return

PokemonTower_2F_EventScript_RivalCharmander::
	trainerbattle_no_intro TRAINER_RIVAL_POKEMON_TOWER_CHARMANDER, PokemonTower_2F_Text_RivalDefeat
	return

PokemonTower_2F_EventScript_RivalExitRight::
	applymovement LOCALID_POKEMON_TOWER_RIVAL, PokemonTower_2F_Movement_RivalExitRight
	waitmovement 0
	return

PokemonTower_2F_EventScript_RivalExitDown::
	applymovement LOCALID_POKEMON_TOWER_RIVAL, PokemonTower_2F_Movement_RivalExitDown
	waitmovement 0
	return

PokemonTower_2F_Movement_RivalExitRight::
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PokemonTower_2F_Movement_RivalExitDown::
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PokemonTower_2F_Text_RivalIntro::
	.string "{RIVAL}: Hé, {PLAYER}!\n"
	.string "Qu'est-ce que tu fais là?\l"
	.string "Tes POKéMON sont pas morts?\p"
	.string "Je peux quand même les mettre\n"
	.string "KO! Aucun problème!$"

PokemonTower_2F_Text_RivalDefeat::
	.string "Hein?\n"
	.string "Saleté, va!\p"
	.string "Je ne jouais pas sérieusement!$"

PokemonTower_2F_Text_RivalPostBattle::
	.string "Où en est ton POKéDEX?\n"
	.string "Je viens de capturer un OSSELAIT!\p"
	.string "Je n'ai pas encore trouvé\n"
	.string "d'OSSATUEUR!\p"
	.string "Je crois qu'il n'en reste plus!\p"
	.string "Je dois y aller! J'ai du\n"
	.string "pain sur la planche!\p"
	.string "Tchao!$"

PokemonTower_2F_Text_SilphScopeCouldUnmaskGhosts::
	.string "Nous ne pouvons pas identifier\n"
	.string "les SPECTRES!\p"
	.string "Un SCOPE SYLPHE pourrait les\n"
	.string "démasquer.$"


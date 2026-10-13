PokemonLeague_ChampionsRoom_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PokemonLeague_ChampionsRoom_OnWarp
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_ChampionsRoom_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_ChampionsRoom_OnFrame
	.byte 0

PokemonLeague_ChampionsRoom_OnResume::
	setvar VAR_0x8004, 4
	call PokemonLeague_EventScript_DoLightingEffect
	call_if_eq VAR_STARTER_MON, 2, PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerSquirtle
	call_if_eq VAR_STARTER_MON, 1, PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerBulbasaur
	call_if_eq VAR_STARTER_MON, 0, PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerCharmander
	end

PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerSquirtle::
	goto_if_defeated TRAINER_CHAMPION_FIRST_SQUIRTLE, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	goto_if_defeated TRAINER_CHAMPION_REMATCH_SQUIRTLE, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	return

PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerBulbasaur::
	goto_if_defeated TRAINER_CHAMPION_FIRST_BULBASAUR, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	goto_if_defeated TRAINER_CHAMPION_REMATCH_BULBASAUR, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	return

PokemonLeague_ChampionsRoom_EventScript_CheckStopTriggerCharmander::
	goto_if_defeated TRAINER_CHAMPION_FIRST_CHARMANDER, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	goto_if_defeated TRAINER_CHAMPION_REMATCH_CHARMANDER, PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	return

PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger::
	setvar VAR_TEMP_1, 1
	return

PokemonLeague_ChampionsRoom_OnWarp::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_ChampionsRoom_EventScript_TurnPlayerNorth
	.2byte 0

PokemonLeague_ChampionsRoom_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

PokemonLeague_ChampionsRoom_OnFrame::
	map_script_2 VAR_TEMP_1, 0, PokemonLeague_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

PokemonLeague_ChampionsRoom_EventScript_EnterRoom::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	setflag FLAG_TEMP_2
	applymovement LOCALID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerEnter
	waitmovement 0
	delay 20
	call_if_unset FLAG_SYS_GAME_CLEAR, PokemonLeague_ChampionsRoom_EventScript_Intro
	call_if_set FLAG_SYS_GAME_CLEAR, PokemonLeague_ChampionsRoom_EventScript_RematchIntro
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	savebgm MUS_VICTORY_GYM_LEADER
	call_if_unset FLAG_IS_CHAMPION, PokemonLeague_ChampionsRoom_EventScript_Battle
	call_if_set FLAG_IS_CHAMPION, PokemonLeague_ChampionsRoom_EventScript_Rematch
	setflag FLAG_TEMP_4
	clearflag FLAG_TEMP_5
	setflag FLAG_DEFEATED_CHAMP
	setflag FLAG_TEMP_4
	msgbox PokemonLeague_ChampionsRoom_Text_PostBattle
	playbgm MUS_RG_SLOW_PALLET, 0
	addobject LOCALID_CHAMPIONS_ROOM_PROF_OAK
	msgbox PokemonLeague_ChampionsRoom_Text_OakPlayer
	closemessage
	applymovement LOCALID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerWatchOakEnter
	applymovement LOCALID_KANTO_CHAMPIONS_ROOM_RIVAL, PokemonLeague_ChampionsRoom_Movement_RivalWatchOakEnter
	applymovement LOCALID_CHAMPIONS_ROOM_PROF_OAK, PokemonLeague_ChampionsRoom_Movement_OakEnter
	waitmovement 0
	delay 25
	specialvar VAR_RESULT, GetStarterPokemon
	bufferspeciesname STR_VAR_1, VAR_RESULT
	msgbox PokemonLeague_ChampionsRoom_Text_OakCongratulations
	applymovement LOCALID_CHAMPIONS_ROOM_PROF_OAK, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_KANTO_CHAMPIONS_ROOM_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_OakImDisappointedRival
	closemessage
	applymovement LOCALID_CHAMPIONS_ROOM_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 20
	msgbox PokemonLeague_ChampionsRoom_Text_OakPlayerComeWithMe
	closemessage
	delay 13
	applymovement LOCALID_CHAMPIONS_ROOM_PROF_OAK, PokemonLeague_ChampionsRoom_Movement_OakExit
	applymovement LOCALID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	setvar VAR_TEMP_1, 1
	warp MAP_POKEMON_LEAGUE_HALL_OF_FAME, 5, 12
	waitstate
	releaseall
	end

PokemonLeague_ChampionsRoom_EventScript_QuestLogEnd::
	call PokemonLeague_ChampionsRoom_EventScript_StopSceneTrigger
	releaseall
	end

PokemonLeague_ChampionsRoom_EventScript_Battle::
	call_if_eq VAR_STARTER_MON, 2, PokemonLeague_ChampionsRoom_EventScript_BattleSquirtle
	call_if_eq VAR_STARTER_MON, 1, PokemonLeague_ChampionsRoom_EventScript_BattleBulbasaur
	call_if_eq VAR_STARTER_MON, 0, PokemonLeague_ChampionsRoom_EventScript_BattleCharmander
	return

PokemonLeague_ChampionsRoom_EventScript_Rematch::
	call_if_eq VAR_STARTER_MON, 2, PokemonLeague_ChampionsRoom_EventScript_RematchSquirtle
	call_if_eq VAR_STARTER_MON, 1, PokemonLeague_ChampionsRoom_EventScript_RematchBulbasaur
	call_if_eq VAR_STARTER_MON, 0, PokemonLeague_ChampionsRoom_EventScript_RematchCharmander
	return

PokemonLeague_ChampionsRoom_EventScript_Intro::
	msgbox PokemonLeague_ChampionsRoom_Text_Intro
	return

PokemonLeague_ChampionsRoom_EventScript_RematchIntro::
	msgbox PokemonLeague_ChampionsRoom_Text_RematchIntro
	return

PokemonLeague_ChampionsRoom_EventScript_BattleSquirtle::
	trainerbattle_no_intro TRAINER_CHAMPION_FIRST_SQUIRTLE, PokemonLeague_ChampionsRoom_Text_Defeat
	return

PokemonLeague_ChampionsRoom_EventScript_BattleBulbasaur::
	trainerbattle_no_intro TRAINER_CHAMPION_FIRST_BULBASAUR, PokemonLeague_ChampionsRoom_Text_Defeat
	return

PokemonLeague_ChampionsRoom_EventScript_BattleCharmander::
	trainerbattle_no_intro TRAINER_CHAMPION_FIRST_CHARMANDER, PokemonLeague_ChampionsRoom_Text_Defeat
	return

PokemonLeague_ChampionsRoom_EventScript_RematchSquirtle::
	trainerbattle_no_intro TRAINER_CHAMPION_REMATCH_SQUIRTLE, PokemonLeague_ChampionsRoom_Text_Defeat
	return

PokemonLeague_ChampionsRoom_EventScript_RematchBulbasaur::
	trainerbattle_no_intro TRAINER_CHAMPION_REMATCH_BULBASAUR, PokemonLeague_ChampionsRoom_Text_Defeat
	return

PokemonLeague_ChampionsRoom_EventScript_RematchCharmander::
	trainerbattle_no_intro TRAINER_CHAMPION_REMATCH_CHARMANDER, PokemonLeague_ChampionsRoom_Text_Defeat
	return

PokemonLeague_ChampionsRoom_Movement_PlayerEnter::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLeague_ChampionsRoom_Movement_PlayerExit::
	delay_16
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

PokemonLeague_ChampionsRoom_Movement_PlayerWatchOakEnter::
	delay_8
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

PokemonLeague_ChampionsRoom_Movement_OakEnter::
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_in_place_faster_down
	delay_16
	step_end

PokemonLeague_ChampionsRoom_Movement_OakExit::
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

PokemonLeague_ChampionsRoom_Movement_RivalWatchOakEnter::
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

PokemonLeague_ChampionsRoom_Text_Intro::
	.string "{RIVAL}: Salut {PLAYER}!\p"
	.string "Je t'attends depuis longtemps!\p"
	.string "Ton devoir en tant qu'adversaire\n"
	.string "est d'entraîner mes POKéMON.\p"
	.string "En améliorant mon POKéDEX, j'ai\n"
	.string "cherché des POKéMON surpuissants!\p"
	.string "J'ai ainsi créé l'équipe ultime,\n"
	.string "efficace contre tous les types de\l"
	.string "POKéMON!\p"
	.string "Ça t'épate, hein?\p"
	.string "Je suis le MAITRE de la LIGUE\n"
	.string "POKéMON!\p"
	.string "Tu sais c'que ça veut dire?\p"
	.string "Ecoute ça, minable!\p"
	.string "Je suis le DRESSEUR le plus\n"
	.string "puissant du monde! Yaaa!$"

PokemonLeague_ChampionsRoom_Text_RematchIntro::
	.string "{RIVAL}: Salut {PLAYER}!\p"
	.string "T'en as pas eu assez?\p"
	.string "Ton devoir en tant qu'adversaire\n"
	.string "est d'entraîner mes POKéMON.\p"
	.string "En améliorant mon POKéDEX, j'ai\n"
	.string "cherché des POKéMON surpuissants!\p"
	.string "J'ai ainsi créé l'équipe ultime,\n"
	.string "efficace contre tous les types de\l"
	.string "POKéMON!\p"
	.string "Ça t'épate, hein?\p"
	.string "Je suis le MAITRE de la LIGUE\n"
	.string "POKéMON!\p"
	.string "Tu sais c'que ça veut dire?\p"
	.string "Ecoute ça, minable!\p"
	.string "Je suis le DRESSEUR le plus\n"
	.string "puissant du monde! Yaaa!$"

PokemonLeague_ChampionsRoom_Text_Defeat::
	.string "NON! IMPOSSIBLE!!!\n"
	.string "Mon équipe de rêve est fichue!\p"
	.string "Après en avoir tant bavé, je me\n"
	.string "fais battre? Et par toi?\p"
	.string "Mon rêve de gloire…\n"
	.string "Disparu! C'est pas juste!$"

PokemonLeague_ChampionsRoom_Text_Victory::
	.string "はーはッ！\n"
	.string "かった！　かった！　かった！\p"
	.string "{PLAYER}に　まける　ような\n"
	.string "おれさま　では　なーい！\p"
	.string "ま！　ポケモンの\n"
	.string "てんさい　{RIVAL}さま　あいてに\l"
	.string "ここまで　よく　がんばった！\p"
	.string "ほめて　つかわす！\n"
	.string "はーッ！　はーはッはッ！$"

PokemonLeague_ChampionsRoom_Text_PostBattle::
	.string "Qu… Comm… Hein?\n"
	.string "Moi? Pourquoi?\l"
	.string "WHAAAAAAAAAAA!\p"
	.string "J'ai entraîné mes POKéMON à la\n"
	.string "perfection…\p"
	.string "Et zut alors! Tu es le nouveau\n"
	.string "MAITRE de la LIGUE POKéMON!\p"
	.string "Alors ça… Ça me sidère.$"

PokemonLeague_ChampionsRoom_Text_OakPlayer::
	.string "CHEN: {PLAYER}!$"

PokemonLeague_ChampionsRoom_Text_OakCongratulations::
	.string "CHEN: Tu as gagné!\n"
	.string "Félicitations!\p"
	.string "Tu es le nouveau MAITRE de\n"
	.string "la LIGUE POKéMON!\p"
	.string "Tu as tant changé depuis ton\n"
	.string "départ avec {STR_VAR_1}.\p"
	.string "{PLAYER}, je suis fier de toi!$"

PokemonLeague_ChampionsRoom_Text_OakImDisappointedRival::
	.string "CHEN: {RIVAL}!\n"
	.string "Je suis… déçu!\p"
	.string "Apprenant que tu avais vaincu le\n"
	.string "CONSEIL 4, je suis venu en\l"
	.string "vitesse!\p"
	.string "Mais le temps d'arriver jusqu'ici,\n"
	.string "tu avais déjà perdu…\p"
	.string "{RIVAL}! As-tu compris pourquoi\n"
	.string "ton équipe s'est fait battre?\p"
	.string "Tu as oublié de traiter tes\n"
	.string "POKéMON avec amour!\p"
	.string "Sans ça, tu ne pourras\n"
	.string "jamais devenir CHAMPION.$"

PokemonLeague_ChampionsRoom_Text_OakPlayerComeWithMe::
	.string "CHEN: {PLAYER}!\p"
	.string "Tu as compris que tu dois aussi\n"
	.string "cette victoire à tes POKéMON.\p"
	.string "Le lien que tu as créé avec eux\n"
	.string "est merveilleux.\p"
	.string "{PLAYER}!\n"
	.string "Suis-moi!$"


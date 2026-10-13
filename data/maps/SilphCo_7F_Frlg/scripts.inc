SilphCo_7F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_7F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SilphCo_7F_OnTransition
	.byte 0

SilphCo_7F_OnLoad::
	call_if_unset FLAG_SILPH_7F_DOOR_1, EventScript_Close7FDoor1
	call_if_unset FLAG_SILPH_7F_DOOR_2, EventScript_Close7FDoor2
	call_if_unset FLAG_SILPH_7F_DOOR_3, EventScript_Close7FDoor3
	end

SilphCo_7F_OnTransition::
	call_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_SetObjRocketsGone
	end

SilphCo_7F_EventScript_SetObjRocketsGone::
	setobjectmovementtype LOCALID_SILPH_CO_7F_WORKER_M2, MOVEMENT_TYPE_FACE_UP
	return

SilphCo_7F_EventScript_RivalTriggerTop::
	lockall
	setvar VAR_TEMP_1, 0
	goto SilphCo_7F_EventScript_RivalScene
	end

SilphCo_7F_EventScript_RivalTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 1
	goto SilphCo_7F_EventScript_RivalScene
	end

SilphCo_7F_EventScript_RivalScene::
	textcolor NPC_TEXT_COLOR_MALE
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	applymovement LOCALID_SILPH_CO_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_SILPH_CO_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox SilphCo_7F_Text_RivalWhatKeptYou
	call_if_eq VAR_TEMP_1, 0, SilphCo_7F_EventScript_RivalApproachTop
	call_if_eq VAR_TEMP_1, 1, SilphCo_7F_EventScript_RivalApproachBottom
	msgbox SilphCo_7F_Text_RivalIntro
	setvar VAR_LAST_TALKED, LOCALID_SILPH_CO_RIVAL
	call_if_eq VAR_STARTER_MON, 2, SilphCo_7F_EventScript_RivalSquirtle
	call_if_eq VAR_STARTER_MON, 1, SilphCo_7F_EventScript_RivalBulbasaur
	call_if_eq VAR_STARTER_MON, 0, SilphCo_7F_EventScript_RivalCharmander
	msgbox SilphCo_7F_Text_RivalPostBattle
	closemessage
	playbgm MUS_RG_RIVAL_EXIT, 0
	call_if_eq VAR_TEMP_1, 0, SilphCo_7F_EventScript_RivalExitTop
	call_if_eq VAR_TEMP_1, 1, SilphCo_7F_EventScript_RivalExitBottom
	playse SE_WARP_IN
	fadedefaultbgm
	removeobject LOCALID_SILPH_CO_RIVAL
	waitse
	setvar VAR_MAP_SCENE_SILPH_CO_7F, 1
	releaseall
	end

SilphCo_7F_EventScript_RivalApproachTop::
	closemessage
	applymovement LOCALID_SILPH_CO_RIVAL, SilphCo_7F_Movement_RivalApproachTop
	waitmovement 0
	return

SilphCo_7F_EventScript_RivalApproachBottom::
	return

SilphCo_7F_EventScript_RivalSquirtle::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_SQUIRTLE, SilphCo_7F_Text_RivalDefeat
	return

SilphCo_7F_EventScript_RivalBulbasaur::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_BULBASAUR, SilphCo_7F_Text_RivalDefeat
	return

SilphCo_7F_EventScript_RivalCharmander::
	trainerbattle_no_intro TRAINER_RIVAL_SILPH_CHARMANDER, SilphCo_7F_Text_RivalDefeat
	return

SilphCo_7F_EventScript_RivalExitTop::
	applymovement LOCALID_SILPH_CO_RIVAL, SilphCo_7F_Movement_RivalExitTop
	waitmovement 0
	return

SilphCo_7F_EventScript_RivalExitBottom::
	applymovement LOCALID_SILPH_CO_RIVAL, SilphCo_7F_Movement_RivalExitBottom
	waitmovement 0
	return

SilphCo_7F_Movement_RivalApproachTop::
	walk_up
	step_end

SilphCo_7F_Movement_RivalExitTop::
	walk_right
	walk_right
	walk_right
	walk_up
	delay_16
	step_end

SilphCo_7F_Movement_RivalExitBottom::
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	delay_16
	step_end

SilphCo_7F_EventScript_LaprasGuy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_LAPRAS_FROM_SILPH, SilphCo_7F_EventScript_AlreadyGotLapras
	msgbox SilphCo_7F_Text_HaveMonForSavingUs
	setvar VAR_TEMP_1, SPECIES_LAPRAS
	givemon SPECIES_LAPRAS, 25
	goto_if_eq VAR_RESULT, 0, SilphCo_7F_EventScript_ReceiveLaprasParty
	goto_if_eq VAR_RESULT, 1, SilphCo_7F_EventScript_ReceiveLaprasPC
	goto_if_eq VAR_RESULT, 2, Common_EventScript_NoMoreRoomForPokemon
	release
	end

SilphCo_7F_EventScript_ReceiveLaprasParty::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message SilphCo_7F_Text_ObtainedLaprasFromEmployee
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_LAPRAS
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SilphCo_7F_EventScript_EndReceiveLapras
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto SilphCo_7F_EventScript_EndReceiveLapras
	end

SilphCo_7F_EventScript_ReceiveLaprasPC::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	playfanfare MUS_LEVEL_UP
	message SilphCo_7F_Text_ObtainedLaprasFromEmployee
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_LAPRAS
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SilphCo_7F_EventScript_LaprasTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto SilphCo_7F_EventScript_LaprasTransferredToPC
	end

SilphCo_7F_EventScript_LaprasTransferredToPC::
	call Common_EventScript_TransferredToPC
	goto SilphCo_7F_EventScript_EndReceiveLapras
	end

SilphCo_7F_EventScript_EndReceiveLapras::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox SilphCo_7F_Text_ExplainLapras
	setflag FLAG_GOT_LAPRAS_FROM_SILPH
	release
	end

SilphCo_7F_EventScript_AlreadyGotLapras::
	msgbox SilphCo_7F_Text_RocketBossWentToBoardroom
	release
	end

SilphCo_7F_EventScript_WorkerM1::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_WorkerM1RocketsGone
	msgbox SilphCo_7F_Text_RocketsAfterMasterBall
	release
	end

SilphCo_7F_EventScript_WorkerM1RocketsGone::
	msgbox SilphCo_7F_Text_CanceledMasterBallProject
	release
	end

SilphCo_7F_EventScript_WorkerM2::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_WorkerM2RocketsGone
	msgbox SilphCo_7F_Text_BadIfTeamRocketTookOver
	release
	end

SilphCo_7F_EventScript_WorkerM2RocketsGone::
	msgbox SilphCo_7F_Text_WowYouChasedOffTeamRocket
	release
	end

SilphCo_7F_EventScript_WorkerF::
	lock
	faceplayer
	goto_if_ge VAR_MAP_SCENE_SILPH_CO_11F, 1, SilphCo_7F_EventScript_WorkerFRocketsGone
	msgbox SilphCo_7F_Text_ReallyDangerousHere
	release
	end

SilphCo_7F_EventScript_WorkerFRocketsGone::
	msgbox SilphCo_7F_Text_ThankYouSoMuch
	release
	end

SilphCo_7F_EventScript_FloorSign::
	msgbox SilphCo_7F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_7F_EventScript_Joshua::
	trainerbattle_single TRAINER_SCIENTIST_JOSHUA, SilphCo_7F_Text_JoshuaIntro, SilphCo_7F_Text_JoshuaDefeat
	msgbox SilphCo_7F_Text_JoshuaPostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_33, SilphCo_7F_Text_Grunt1Intro, SilphCo_7F_Text_Grunt1Defeat
	msgbox SilphCo_7F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_34, SilphCo_7F_Text_Grunt2Intro, SilphCo_7F_Text_Grunt2Defeat
	msgbox SilphCo_7F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_EventScript_Grunt3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_35, SilphCo_7F_Text_Grunt3Intro, SilphCo_7F_Text_Grunt3Defeat
	msgbox SilphCo_7F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_7F_Text_HaveMonForSavingUs::
	.string "Oh! Tu n'es pas un ROCKET! Es-tu\n"
	.string "là pour nous sauver? Merci!\p"
	.string "Prends donc ce joli POKéMON en\n"
	.string "cadeau.$"

SilphCo_7F_Text_ObtainedLaprasFromEmployee::
	.string "{PLAYER} reçoit un LOKHLASS.$"

SilphCo_7F_Text_ExplainLapras::
	.string "C'est un LOKHLASS.\n"
	.string "Il est très intelligent.\p"
	.string "Nous le gardions dans le labo,\n"
	.string "mais il sera mieux avec toi!\p"
	.string "Tu seras un bon DRESSEUR\n"
	.string "pour LOKHLASS!\p"
	.string "C'est un bon nageur, il pourra même\n"
	.string "te transporter sur l'eau!$"

SilphCo_7F_Text_RocketBossWentToBoardroom::
	.string "Le chef de la TEAM ROCKET est\n"
	.string "dans la salle du conseil…\p"
	.string "Le PDG va bien?\n"
	.string "Je suis très inquiet.$"

SilphCo_7F_Text_RocketsAfterMasterBall::
	.string "La TEAM ROCKET voulait s'emparer\n"
	.string "de la MASTER BALL pouvant\l"
	.string "attraper n'importe quel POKéMON!$"

SilphCo_7F_Text_CanceledMasterBallProject::
	.string "Le projet MASTER BALL fut annulé\n"
	.string "à cause de la TEAM ROCKET.$"

SilphCo_7F_Text_BadIfTeamRocketTookOver::
	.string "Grâce au ciel, la TEAM ROCKET\n"
	.string "n'a pas pu investir la SYLPHE ou\l"
	.string "voler nos POKéMON!$"

SilphCo_7F_Text_WowYouChasedOffTeamRocket::
	.string "Woah!\p"
	.string "Tu as vraiment battu la\n"
	.string "TEAM ROCKET?$"

SilphCo_7F_Text_ReallyDangerousHere::
	.string "Hé toi!\n"
	.string "C'est dangereux par ici!\p"
	.string "Tu es là pour me sauver?\n"
	.string "Impossible!$"

SilphCo_7F_Text_ThankYouSoMuch::
	.string "Enfin libre!\n"
	.string "Merci merci!$"

SilphCo_7F_Text_Grunt3Intro::
	.string "Heu?\n"
	.string "Alerte! Alerte!$"

SilphCo_7F_Text_Grunt3Defeat::
	.string "Oups.\n"
	.string "Perdu! Perdu!$"

SilphCo_7F_Text_Grunt3PostBattle::
	.string "Tu ne pourras pas trouver mon\n"
	.string "chef juste en te baladant!$"

SilphCo_7F_Text_JoshuaIntro::
	.string "Nyah ha ha!\p"
	.string "Tu me prends pour un employé de\n"
	.string "la SYLPHE?$"

SilphCo_7F_Text_JoshuaDefeat::
	.string "…\n"
	.string "Fichu!$"

SilphCo_7F_Text_JoshuaPostBattle::
	.string "Bien que tu sois jeune, tu te\n"
	.string "débrouilles pas trop mal!$"

SilphCo_7F_Text_Grunt1Intro::
	.string "Je suis l'un des 4 FRERES ROCKET!$"

SilphCo_7F_Text_Grunt1Defeat::
	.string "Yaaah!\n"
	.string "Frères! A l'aide!$"

SilphCo_7F_Text_Grunt1PostBattle::
	.string "Pas grave. Mes frères se\n"
	.string "chargeront de toi, mon petit!$"

SilphCo_7F_Text_Grunt2Intro::
	.string "Un jeune intrus?\n"
	.string "Mais! C'est toi!$"

SilphCo_7F_Text_Grunt2Defeat::
	.string "OK.\n"
	.string "J'ai perdu.$"

SilphCo_7F_Text_Grunt2PostBattle::
	.string "Rentre chez toi!\n"
	.string "Mon chef est sans pitié!$"

SilphCo_7F_Text_RivalWhatKeptYou::
	.string "{RIVAL}: Qu'est-ce qui t'a retenu\n"
	.string "{PLAYER}?$"

SilphCo_7F_Text_RivalIntro::
	.string "{RIVAL}: Hahaha! J'étais sûr que\n"
	.string "tu passerais par là!\p"
	.string "La TEAM ROCKET te pose des\n"
	.string "problèmes? Quel dommage!\p"
	.string "Je t'ai vu à SAFRANIA.\n"
	.string "T'as fait des progrès?$"

SilphCo_7F_Text_RivalDefeat::
	.string "Oh non!\n"
	.string "Tu vas affronter le chef de\l"
	.string "la TEAM ROCKET!$"

SilphCo_7F_Text_RivalPostBattle::
	.string "OK, {PLAYER}!\p"
	.string "Je décampe!\p"
	.string "Grâce à mon joli POKéDEX, je\n"
	.string "découvre qui est fort et quelles\l"
	.string "sont toutes les évolutions!\p"
	.string "Je vais à la LIGUE POKéMON\n"
	.string "pour détrôner le CONSEIL 4!\p"
	.string "Je serai bientôt le DRESSEUR le\n"
	.string "plus puissant du monde!\p"
	.string "Bonne chance, {PLAYER}!\p"
	.string "Tu en auras besoin.\n"
	.string "Tchao!$"

SilphCo_7F_Text_FloorSign::
	.string "SYLPHE SARL.\n"
	.string "6ème étage.$"


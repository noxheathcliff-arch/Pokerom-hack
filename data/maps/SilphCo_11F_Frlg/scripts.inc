SilphCo_11F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_11F_OnLoad
	.byte 0

SilphCo_11F_OnLoad::
	call_if_unset FLAG_SILPH_11F_DOOR, EventScript_Close11FDoor
	end

SilphCo_11F_EventScript_President::
	lock
	faceplayer
	goto_if_set FLAG_GOT_MASTER_BALL_FROM_SILPH, SilphCo_11F_EventScript_AlreadyGotMasterBall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, SilphCo_11F_EventScript_PresidentThanksMale
	call_if_eq VAR_RESULT, FEMALE, SilphCo_11F_EventScript_PresidentThanksFemale
	checkitemspace ITEM_MASTER_BALL
	goto_if_eq VAR_RESULT, FALSE, SilphCo_11F_EventScript_NoRoomForMasterBall
	giveitem_msg SilphCo_11F_Text_ObtainedMasterBallFromPresident, ITEM_MASTER_BALL, 1, MUS_RG_OBTAIN_KEY_ITEM
	msgbox SilphCo_11F_Text_ThatsOurSecretPrototype
	setflag FLAG_GOT_MASTER_BALL_FROM_SILPH
	release
	end

SilphCo_11F_EventScript_PresidentThanksMale::
	msgbox SilphCo_11F_Text_ThanksForSavingMeDearBoy
	return

SilphCo_11F_EventScript_PresidentThanksFemale::
	msgbox SilphCo_11F_Text_ThanksForSavingMeDearGirl
	return

SilphCo_11F_EventScript_NoRoomForMasterBall::
	msgbox SilphCo_11F_Text_YouHaveNoRoomForThis
	release
	end

SilphCo_11F_EventScript_AlreadyGotMasterBall::
	msgbox SilphCo_11F_Text_ThatsOurSecretPrototype
	release
	end

SilphCo_11F_EventScript_Secretary::
	msgbox SilphCo_11F_Text_ThanksForRescuingUs, MSGBOX_NPC
	end

SilphCo_11F_EventScript_GiovanniTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto SilphCo_11F_EventScript_BattleGiovanni
	end

SilphCo_11F_EventScript_GiovanniTriggerRight::
	lockall
	setvar VAR_TEMP_1, 1
	goto SilphCo_11F_EventScript_BattleGiovanni
	end

SilphCo_11F_EventScript_BattleGiovanni::
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_SILPH_CO_GIOVANNI, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 25
	msgbox SilphCo_11F_Text_GiovanniIntro
	closemessage
	call_if_eq VAR_TEMP_1, 0, SilphCo_11F_EventScript_GiovanniApproachLeft
	call_if_eq VAR_TEMP_1, 1, SilphCo_11F_EventScript_GiovanniApproachRight
	setvar VAR_LAST_TALKED, LOCALID_SILPH_CO_GIOVANNI
	trainerbattle_no_intro TRAINER_BOSS_GIOVANNI_2, SilphCo_11F_Text_GiovanniDefeat
	msgbox SilphCo_11F_Text_GiovanniPostBattle
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_SILPH_CO_GIOVANNI
	removeobject LOCALID_SILPH_CO_11F_GRUNT1
	removeobject LOCALID_SILPH_CO_11F_GRUNT2
	fadescreen FADE_FROM_BLACK
	setvar VAR_MAP_SCENE_SILPH_CO_11F, 1
	setflag FLAG_HIDE_SAFFRON_ROCKETS
	clearflag FLAG_HIDE_SAFFRON_CIVILIANS
	releaseall
	end

SilphCo_11F_EventScript_GiovanniApproachLeft::
	applymovement LOCALID_SILPH_CO_GIOVANNI, SilphCo_11F_Movement_GiovanniApproachLeft
	applymovement LOCALID_PLAYER, SilphCo_11F_Movement_PlayerFaceGiovanni
	waitmovement 0
	return

SilphCo_11F_EventScript_GiovanniApproachRight::
	applymovement LOCALID_SILPH_CO_GIOVANNI, SilphCo_11F_Movement_GiovanniApproachRight
	waitmovement 0
	return

SilphCo_11F_Movement_GiovanniApproachLeft::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

SilphCo_11F_Movement_GiovanniApproachRight::
	walk_down
	walk_down
	walk_down
	step_end

SilphCo_11F_Movement_PlayerFaceGiovanni::
	delay_16
	delay_16
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_right
	step_end

@ Unused
SilphCo_11F_EventScript_Monitor::
	msgbox SilphCo_11F_Text_MonitorHasMonsOnIt, MSGBOX_SIGN
	end

SilphCo_11F_EventScript_FloorSign::
	msgbox SilphCo_11F_Text_FloorSign, MSGBOX_SIGN
	end

SilphCo_11F_EventScript_Grunt1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_40, SilphCo_11F_Text_Grunt1Intro, SilphCo_11F_Text_Grunt1Defeat
	msgbox SilphCo_11F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_11F_EventScript_Grunt2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_41, SilphCo_11F_Text_Grunt2Intro, SilphCo_11F_Text_Grunt2Defeat
	msgbox SilphCo_11F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SilphCo_11F_Text_ThanksForSavingMeDearBoy::
	.string "PRESIDENT: Merci d'avoir sauvé\n"
	.string "la SYLPHE, mon garçon!\p"
	.string "Je n'oublierai jamais\n"
	.string "cet exploit!\p"
	.string "Tu mérites une récompense!\p"
	.string "L'argent n'est pas un problème\n"
	.string "pour moi!\p"
	.string "Tiens… Je crois que ceci\n"
	.string "te fera plaisir!$"

SilphCo_11F_Text_ThanksForSavingMeDearGirl::
	.string "PRESIDENT: Merci d'avoir sauvé\n"
	.string "la SYLPHE, jeune fille!\p"
	.string "Je n'oublierai jamais\n"
	.string "cet exploit!\p"
	.string "Tu mérites une récompense!\p"
	.string "L'argent n'est pas un problème\n"
	.string "pour moi!\p"
	.string "Tiens… Je crois que ceci\n"
	.string "te fera plaisir!$"

SilphCo_11F_Text_ObtainedMasterBallFromPresident::
	.string "{PLAYER} obtient une MASTER BALL\n"
	.string "du PRESIDENT!$"

SilphCo_11F_Text_ThatsOurSecretPrototype::
	.string "PRESIDENT: Tu ne peux en acheter\n"
	.string "nulle part!\p"
	.string "C'est notre prototype secret:\n"
	.string "la MASTER BALL!\p"
	.string "Elle peut attraper n'importe\n"
	.string "quel POKéMON!\p"
	.string "Alors utilise-la avec sagesse.$"

SilphCo_11F_Text_YouHaveNoRoomForThis::
	.string "Tu n'as pas assez de place sur toi.$"

SilphCo_11F_Text_ThanksForRescuingUs::
	.string "SECRETAIRE: Merci de nous avoir\n"
	.string "tous sauvés!\p"
	.string "Ton courage est exemplaire.$"

SilphCo_11F_Text_GiovanniIntro::
	.string "Ah, {PLAYER}!\n"
	.string "Une fois encore, nos routes se\l"
	.string "croisent…\p"
	.string "Le PRESIDENT et moi discutons\n"
	.string "d'une affaire très importante.\p"
	.string "Viens pas te mêler de tout ça…\p"
	.string "Ou prépare-toi à souffrir!$"

SilphCo_11F_Text_GiovanniDefeat::
	.string "Arrgh!!\n"
	.string "Encore perdu!?$"

SilphCo_11F_Text_GiovanniPostBattle::
	.string "NOoOoOoOon!\p"
	.string "Notre invasion de la SYLPHE est\n"
	.string "fichue!\p"
	.string "Mais la TEAM ROCKET est\n"
	.string "invincible!\p"
	.string "{PLAYER}! N'oublie jamais que tous\n"
	.string "les POKéMON sont pour la TEAM\l"
	.string "ROCKET!\p"
	.string "Je pars, mais…\n"
	.string "Je reviendrai bientôt.$"

SilphCo_11F_Text_Grunt2Intro::
	.string "Holà toi!\n"
	.string "On bouge pas!$"

SilphCo_11F_Text_Grunt2Defeat::
	.string "Non…\n"
	.string "Pitié!$"

SilphCo_11F_Text_Grunt2PostBattle::
	.string "Tu cherches mon chef?\n"
	.string "Tu tiens à avoir des problèmes?$"

SilphCo_11F_Text_Grunt1Intro::
	.string "Halte! As-tu un rendez-vous en\n"
	.string "règle avec mon chef?$"

SilphCo_11F_Text_Grunt1Defeat::
	.string "Gaah!\n"
	.string "J'me suis fait démolir!$"

SilphCo_11F_Text_Grunt1PostBattle::
	.string "Prends garde…\p"
	.string "Les POKéMON de mon chef sont\n"
	.string "terribles!$"

SilphCo_11F_Text_MonitorHasMonsOnIt::
	.string "Des POKéMON sur le moniteur!$"

SilphCo_11F_Text_FloorSign::
	.string "SYLPHE SARL.\n"
	.string "10ème étage.$"


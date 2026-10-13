.equ FOUND_FIRST_SWITCH, FLAG_TEMP_1
.equ SWITCH1_ID,         VAR_0x8004
.equ SWITCH2_ID,         VAR_0x8005
.equ TRASH_CAN_ID,       VAR_0x8008

VermilionCity_Gym_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VermilionCity_Gym_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_Gym_OnTransition
	.byte 0

VermilionCity_Gym_OnLoad::
	call_if_set FOUND_FIRST_SWITCH, VermilionCity_Gym_EventScript_SetOneBeamOff
	call_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_SetBeamsOff
	end

VermilionCity_Gym_EventScript_SetOneBeamOff::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_HalfOn, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_HalfOn, 1
	setmetatile 5, 6, METATILE_VermilionGym_Beam_MidTop_HalfOn, 1
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_HalfOn, 1
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_HalfOn, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_HalfOn, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_HalfOn, 1
	setmetatile 5, 7, METATILE_VermilionGym_Beam_MidBottom_HalfOn, 1
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_HalfOn, 1
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_HalfOn, 1
	return

VermilionCity_Gym_EventScript_SetBeamsOff::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Off, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_Off, 0
	setmetatile 5, 6, METATILE_VermilionGym_Floor, 0
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_Off, 0
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_Off, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Off, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_Off, 0
	setmetatile 5, 7, METATILE_VermilionGym_Floor, 0
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_Off, 0
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Off, 1
	return

VermilionCity_Gym_OnTransition::
	call VermilionCity_Gym_EventScript_InitTrashCans
	end

VermilionCity_Gym_EventScript_InitTrashCans::
	goto_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, Common_EventScript_NopReturn
	special SetVermilionTrashCans
	copyvar VAR_TEMP_0, SWITCH1_ID
	copyvar VAR_TEMP_1, SWITCH2_ID
	return

VermilionCity_Gym_EventScript_TrashCan1::
	lockall
	setvar TRASH_CAN_ID, 1
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan2::
	lockall
	setvar TRASH_CAN_ID, 2
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan3::
	lockall
	setvar TRASH_CAN_ID, 3
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan4::
	lockall
	setvar TRASH_CAN_ID, 4
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan5::
	lockall
	setvar TRASH_CAN_ID, 5
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan6::
	lockall
	setvar TRASH_CAN_ID, 6
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan7::
	lockall
	setvar TRASH_CAN_ID, 7
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan8::
	lockall
	setvar TRASH_CAN_ID, 8
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan9::
	lockall
	setvar TRASH_CAN_ID, 9
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan10::
	lockall
	setvar TRASH_CAN_ID, 10
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan11::
	lockall
	setvar TRASH_CAN_ID, 11
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan12::
	lockall
	setvar TRASH_CAN_ID, 12
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan13::
	lockall
	setvar TRASH_CAN_ID, 13
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan14::
	lockall
	setvar TRASH_CAN_ID, 14
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan15::
	lockall
	setvar TRASH_CAN_ID, 15
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan::
	copyvar SWITCH1_ID, VAR_TEMP_0
	copyvar SWITCH2_ID, VAR_TEMP_1
	goto_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_LocksAlreadyOpen
	goto_if_set FOUND_FIRST_SWITCH, VermilionCity_Gym_EventScript_TrySwitchTwo
	goto_if_eq SWITCH1_ID, TRASH_CAN_ID, VermilionCity_Gym_EventScript_FoundSwitchOne
	msgbox VermilionCity_Gym_Text_NopeOnlyTrashHere
	releaseall
	end

VermilionCity_Gym_EventScript_FoundSwitchOne::
	msgbox VermilionCity_Gym_Text_SwitchUnderTrashFirstLockOpened
	playse SE_PIN
	waitse
	call VermilionCity_Gym_EventScript_SetOneBeamOff
	special DrawWholeMapView
	setflag FOUND_FIRST_SWITCH
	releaseall
	end

VermilionCity_Gym_EventScript_TrySwitchTwo::
	goto_if_eq SWITCH2_ID, TRASH_CAN_ID, VermilionCity_Gym_EventScript_FoundSwitchTwo
	msgbox VermilionCity_Gym_Text_OnlyTrashLocksWereReset
	clearflag FOUND_FIRST_SWITCH
	special SetVermilionTrashCans
	copyvar VAR_TEMP_0, SWITCH1_ID
	copyvar VAR_TEMP_1, SWITCH2_ID
	call VermilionCity_Gym_EventScript_SetBeamsOn
	special DrawWholeMapView
	releaseall
	end

VermilionCity_Gym_EventScript_FoundSwitchTwo::
	msgbox VermilionCity_Gym_Text_SecondLockOpened
	closemessage
	call VermilionCity_Gym_EventScript_SetBeamsOff
	special DrawWholeMapView
	playse SE_UNLOCK
	waitse
	setflag FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES
	releaseall
	end

VermilionCity_Gym_EventScript_LocksAlreadyOpen::
	msgbox VermilionCity_Gym_Text_NopeOnlyTrashHere
	releaseall
	end

VermilionCity_Gym_EventScript_SetBeamsOn::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_On, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_On, 1
	setmetatile 5, 6, METATILE_VermilionGym_Beam_MidTop, 1
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_On, 1
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_On, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_On, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_On, 1
	setmetatile 5, 7, METATILE_VermilionGym_Beam_MidBottom, 1
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_On, 1
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_On, 1
	return

VermilionCity_Gym_EventScript_LtSurge::
	famechecker FAMECHECKER_LTSURGE, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_LT_SURGE, VermilionCity_Gym_Text_LtSurgeIntro, VermilionCity_Gym_Text_LtSurgeDefeat, VermilionCity_Gym_EventScript_DefeatedLtSurge, NO_MUSIC
	goto_if_unset FLAG_GOT_TM34_FROM_SURGE, VermilionCity_Gym_EventScript_GiveTM34
	msgbox VermilionCity_Gym_Text_LtSurgePostBattle
	release
	end

VermilionCity_Gym_EventScript_DefeatedLtSurge::
	famechecker FAMECHECKER_LTSURGE, 1
	call_if_unset FLAG_GOT_HM05, VermilionCity_Gym_EventScript_ShowOaksAide
	clearflag FLAG_HIDE_FAME_CHECKER_LT_SURGE_JOURNAL
	setflag FLAG_DEFEATED_LT_SURGE
	setflag FLAG_BADGE03_GET
	set_gym_trainers_frlg 3
	goto VermilionCity_Gym_EventScript_GiveTM34
	end

VermilionCity_Gym_EventScript_ShowOaksAide::
	clearflag FLAG_HIDE_VERMILION_CITY_OAKS_AIDE
	return

VermilionCity_Gym_EventScript_GiveTM34::
	msgbox VermilionCity_Gym_Text_ExplainThunderBadgeTakeThis
	checkitemspace ITEM_TM34
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_Gym_EventScript_NoRoomForTM34
	giveitem_msg VermilionCity_Gym_Text_ReceivedTM34FromLtSurge, ITEM_TM34
	setflag FLAG_GOT_TM34_FROM_SURGE
	msgbox VermilionCity_Gym_Text_ExplainTM34
	release
	end

VermilionCity_Gym_EventScript_NoRoomForTM34::
	msgbox VermilionCity_Gym_Text_MakeRoomInYourBag
	release
	end

VermilionCity_Gym_EventScript_Dwayne::
	trainerbattle_single TRAINER_SAILOR_DWAYNE, VermilionCity_Gym_Text_DwayneIntro, VermilionCity_Gym_Text_DwayneDefeat
	famechecker FAMECHECKER_LTSURGE, 4
	msgbox VermilionCity_Gym_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_Baily::
	trainerbattle_single TRAINER_ENGINEER_BAILY, VermilionCity_Gym_Text_BailyIntro, VermilionCity_Gym_Text_BailyDefeat
	msgbox VermilionCity_Gym_Text_BailyPostBattle, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_Tucker::
	trainerbattle_single TRAINER_GENTLEMAN_TUCKER, VermilionCity_Gym_Text_TuckerIntro, VermilionCity_Gym_Text_TuckerDefeat, VermilionCity_Gym_EventScript_DefeatedTucker
	famechecker FAMECHECKER_LTSURGE, 3
	msgbox VermilionCity_Gym_Text_TuckerPostBattle, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_DefeatedTucker::
	famechecker FAMECHECKER_LTSURGE, 2
	release
	end

VermilionCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LT_SURGE, VermilionCity_Gym_EventScript_GymGuyPostVictory
	msgbox VermilionCity_Gym_Text_GymGuyAdvice
	release
	end

VermilionCity_Gym_EventScript_GymGuyPostVictory::
	msgbox VermilionCity_Gym_Text_GymGuyPostVictory
	release
	end

VermilionCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, VermilionCity_Gym_EventScript_GymStatuePostVictory
	msgbox VermilionCity_Gym_Text_GymStatue
	releaseall
	end

VermilionCity_Gym_EventScript_GymStatuePostVictory::
	msgbox VermilionCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

VermilionCity_Gym_Text_LtSurgeIntro::
	.string "Hé!\n"
	.string "Tu fais quoi là?\p"
	.string "Tu ne résisterais pas longtemps en\n"
	.string "temps de guerre!\p"
	.string "Je vais t'avouer quelque\n"
	.string "chose, les POKéMON ELECTRIK\p"
	.string "m'ont sauvé pendant la guerre.\p"
	.string "Ils ont paralysé mes ennemis avec\n"
	.string "leurs éclairs! Comme je te le dis!\p"
	.string "Et y va t'arriver la même chose!\n"
	.string "Compte tes dents! Tu vas morfler!{PLAY_BGM MUS_RG_ENCOUNTER_GYM_LEADER}$"

VermilionCity_Gym_Text_LtSurgePostBattle::
	.string "Un p'tit conseil!\p"
	.string "L'électricité est très puissante!\p"
	.string "Mais elle est inutile face à des\n"
	.string "POKéMON SOL!$"

VermilionCity_Gym_Text_ExplainThunderBadgeTakeThis::
	.string "Le BADGEFOUDRE augmente la\n"
	.string "VITESSE de tes POKéMON!\p"
	.string "Il permet aussi à tes POKéMON\n"
	.string "d'utiliser VOL!\p"
	.string "T'es quelqu'un de pas ordinaire!\n"
	.string "Prends ça!$"

VermilionCity_Gym_Text_ReceivedTM34FromLtSurge::
	.string "{PLAYER} reçoit\n"
	.string "la CT34!$"

VermilionCity_Gym_Text_ExplainTM34::
	.string "CT34 : ONDE DE CHOC!\p"
	.string "Enseigne-la à un\n"
	.string "POKéMON ELECTRIK!$"

VermilionCity_Gym_Text_MakeRoomInYourBag::
	.string "Revue d'paquetage la bleusaille,\n"
	.string "ton inventaire est plein!$"

VermilionCity_Gym_Text_LtSurgeDefeat::
	.string "Whoo!\p"
	.string "T'iras loin toi.\p"
	.string "Très bien, prends le BADGEFOUDRE!$"

VermilionCity_Gym_Text_TuckerIntro::
	.string "A l'armée, MAJOR BOB\n"
	.string "était mon supérieur.\p"
	.string "C'était très instructif d'être sous\n"
	.string "ses ordres.$"

VermilionCity_Gym_Text_TuckerDefeat::
	.string "Stop!\n"
	.string "J'en peux plus!$"

VermilionCity_Gym_Text_TuckerPostBattle::
	.string "Tu ne trouves pas les\n"
	.string "interrupteurs?\p"
	.string "Le MAJOR BOB a toujours été\n"
	.string "reconnu pour sa nature prudente.$"

VermilionCity_Gym_Text_BailyIntro::
	.string "J'suis un poids plume, mais j'suis\n"
	.string "bon avec l'électricité!$"

VermilionCity_Gym_Text_BailyDefeat::
	.string "Argh!\n"
	.string "J'suis grillé!$"

VermilionCity_Gym_Text_BailyPostBattle::
	.string "OK, je parle!\p"
	.string "Le MAJOR BOB a caché des boutons\n"
	.string "pour ouvrir les portes…\l"
	.string "… Quelque part!$"

VermilionCity_Gym_Text_DwayneIntro::
	.string "C'est pas un endroit pour les\n"
	.string "gamins, ici!$"

VermilionCity_Gym_Text_DwayneDefeat::
	.string "Argh!\n"
	.string "Tu m'as eu par surprise!$"

VermilionCity_Gym_Text_DwaynePostBattle::
	.string "C'est le MAJOR BOB lui-même\n"
	.string "qui a installé les pièges de cette\p"
	.string "ARENE. Il a mis des double verrous\n"
	.string "partout. Voici un indice!\p"
	.string "Appuie sur le premier bouton,\n"
	.string "le deuxième est juste à côté!$"

VermilionCity_Gym_Text_GymGuyAdvice::
	.string "Salut,\n"
	.string "CHAMPION en herbe!\p"
	.string "Le MAJOR BOB a un surnom. On\n"
	.string "l'appelle… L'Américain Survolté!\p"
	.string "Il est expert en POKéMON\n"
	.string "ELECTRIK!\p"
	.string "C'est pas bon pour les POKéMON\n"
	.string "VOL et EAU! \p"
	.string "Fais aussi attention à la\n"
	.string "paralysie.\p"
	.string "Le MAJOR BOB est très prudent!\p"
	.string "Ça sera pas facile du tout\n"
	.string "d'arriver jusqu'à lui!$"

VermilionCity_Gym_Text_GymGuyPostVictory::
	.string "Wouh!\n"
	.string "Ce match était survolté!$"

VermilionCity_Gym_Text_GymStatue::
	.string "ARENE POKéMON de CARMIN SUR MER\n"
	.string "CHAMPION: MAJOR BOB\p"
	.string "VAINQUEURS:\n"
	.string "{RIVAL}$"

VermilionCity_Gym_Text_GymStatuePlayerWon::
	.string "ARENE POKéMON de CARMIN SUR MER\n"
	.string "CHAMPION: MAJOR BOB\p"
	.string "VAINQUEURS:\n"
	.string "{RIVAL}, {PLAYER}$"

VermilionCity_Gym_Text_NopeOnlyTrashHere::
	.string "Non!\n"
	.string "Il y a juste une poubelle ici.$"

VermilionCity_Gym_Text_SwitchUnderTrashFirstLockOpened::
	.string "Oh! Un bouton sous la poubelle!\n"
	.string "Dingue!\p"
	.string "Le premier verrou est levé!$"

VermilionCity_Gym_Text_SecondLockOpened::
	.string "Le deuxième verrou est levé!\n"
	.string "La porte s'ouvre!$"

VermilionCity_Gym_Text_OnlyTrashLocksWereReset::
	.string "Non!\n"
	.string "Il y a juste une poubelle ici.\p"
	.string "Oups… Les verrous sont en place!$"


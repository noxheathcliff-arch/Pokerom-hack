@ Hack: Confluence demo chapter 1 (SLICE_DEMO_CH0-1 C1-C11, walls s7, neutralizations s8). Edit this file directly.
@ Conventions: visibility flags set = hidden; "M" boxes are 2 lines <= 208 px; Brice present = checkfollowernpc.
@ State variables (vanilla vars reused, vanilla scripts neutralized): VAR_STEVENS_HOUSE_STATE (C1: 0 -> 1),
@ VAR_PETALBURG_WOODS_STATE (C3: 0 -> 1), VAR_RUSTBORO_CITY_STATE (C4: 0 -> 10, C7: 10 -> 11),
@ VAR_DEVON_CORP_3F_STATE (C6: 0 -> 1), VAR_RUSTURF_TUNNEL_STATE (C8: 0 -> 1),
@ VAR_ROUTE116_STATE (C10: 0 -> 2, C11: 2 -> 3).

@ ---------------------------------------------------------------- helpers

@ Says the line only if Brice is the follower
	.macro cf_bsay text:req
	checkfollowernpc
	goto_if_eq VAR_RESULT, FALSE, 1f
	msgbox \text, MSGBOX_DEFAULT
1:
	.endm

@ VAR_RESULT = decision option; jump to label if it equals opt
	.macro cf_if_dec n:req, opt:req, label:req
	checkdecision \n
	goto_if_eq VAR_RESULT, \opt, \label
	.endm

@ Removes min(amt, money) (amt < 512): the whole amount if affordable, else everything (binary greedy)
	.macro cf_lose_money amt:req
	checkmoney \amt
	goto_if_eq VAR_RESULT, FALSE, 2f
	removemoney \amt
	goto 9f
2:
	.irp c, 256, 128, 64, 32, 16, 8, 4, 2, 1
	checkmoney \c
	goto_if_eq VAR_RESULT, FALSE, 3f
	removemoney \c
3:
	.endr
9:
	.endm

@ N + 1 (bounded to 3), VAR_CF_WORLD bits 0-1
CF_IncN::
	getbits VAR_CF_WORLD, 0, 2
	goto_if_ge VAR_RESULT, 3, CF_IncN_Done
	addvar VAR_RESULT, 1
	setbits VAR_CF_WORLD, 0, 2, VAR_RESULT
CF_IncN_Done::
	return

CF_Nop::
	end

CF_Mov_Up2:
	walk_up
	walk_up
	step_end

CF_Mov_Down1:
	walk_down
	step_end

@ ---------------------------------------------------------------- walls (s7)

CF_Wall_QG::
	msgbox CF1_T_000, MSGBOX_NPC
	end

CF_Wall_R116::
	msgbox CF1_T_001, MSGBOX_NPC
	end

CF_Wall_R115_Talk::
	msgbox CF1_T_002, MSGBOX_NPC
	end

CF_Wall_R115::
	lockall
	msgbox CF1_T_002, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CF_Mov_Down1
	waitmovement 0
	releaseall
	end

CF_Cutter::
	msgbox CF1_T_003, MSGBOX_NPC
	end

@ Rustboro mart: no Escape Rope while Z-02 = ENVAHI
CF_Mart_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	getbits VAR_CF_ECO, 2, 2
	goto_if_eq VAR_RESULT, ECO_ENVAHI, CF_Mart_NoRope
	pokemart RustboroCity_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

CF_Mart_NoRope::
	pokemart CF_Mart_Stock_NoRope
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
CF_Mart_Stock_NoRope:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	pokemartlistend

@ ---------------------------------------------------------------- C1: QG du Rempart (D017)

CF_C1_Show::
	clearflag FLAG_CF_VIS_17
	checkdecision 17
	goto_if_ne VAR_RESULT, DEC_NONE, CF_C1_Show_Celeo
	clearflag FLAG_CF_VIS_18
CF_C1_Show_Celeo::
	checkdecision 6
	goto_if_ne VAR_RESULT, DEC_A, CF_C1_Show_End
	clearflag FLAG_CF_VIS_03
CF_C1_Show_End::
	return

CF_C1_Scene::
	checkdecision 17
	goto_if_ne VAR_RESULT, DEC_NONE, CF_Nop
	lockall
	msgbox CF1_T_004, MSGBOX_DEFAULT
	cf_if_dec 2, DEC_A, CF_C1_NormanA
	msgbox CF1_T_005, MSGBOX_DEFAULT
	goto CF_C1_AfterNorman

CF_C1_NormanA::
	msgbox CF1_T_006, MSGBOX_DEFAULT
CF_C1_AfterNorman::
	cf_if_dec 6, DEC_A, CF_C1_Celeo
CF_C1_Flora::
	msgbox CF1_T_007, MSGBOX_DEFAULT
	cf_if_dec 7, DEC_A, CF_C1_FloraA
	msgbox CF1_T_008, MSGBOX_DEFAULT
	goto CF_C1_Offer

CF_C1_FloraA::
	msgbox CF1_T_009, MSGBOX_DEFAULT
	goto CF_C1_Offer

CF_C1_Celeo::
	msgbox CF1_T_010, MSGBOX_DEFAULT
	msgbox CF1_T_011, MSGBOX_DEFAULT
	msgbox CF1_T_012, MSGBOX_DEFAULT
	cf_if_dec 1, DEC_A, CF_C1_CeleoA
	msgbox CF1_T_013, MSGBOX_DEFAULT
	goto CF_C1_Flora

CF_C1_CeleoA::
	msgbox CF1_T_014, MSGBOX_DEFAULT
	goto CF_C1_Flora

CF_C1_Offer::
	msgbox CF1_T_015, MSGBOX_DEFAULT
	message CF1_T_016
	waitmessage
	dynmultipush CF1_T_017, 0
	dynmultipush CF1_T_018, 1
	dynmultistack 0, 0, TRUE, 2, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	closemessage
	switch VAR_RESULT
	case 0, CF_C1_Accept
	case 1, CF_C1_Refuse
	end

CF_C1_Accept::
	msgbox CF1_T_019, MSGBOX_DEFAULT
	setdecision_once 17, DEC_A, CF_C1_Common
	setflag FLAG_CF_INSIGNE
	addaffinity VAR_CF_REP_L, 3
	subaffinity VAR_CF_REP_A, 3
	goto CF_C1_Common

CF_C1_Refuse::
	msgbox CF1_T_020, MSGBOX_DEFAULT
	setdecision_once 17, DEC_B, CF_C1_Common
	subaffinity VAR_CF_REP_L, 2
	addaffinity VAR_CF_REP_A, 1
	goto CF_C1_Common

CF_C1_Common::
	msgbox CF1_T_021, MSGBOX_DEFAULT
	closemessage
	setvar VAR_STEVENS_HOUSE_STATE, 1
	setflag FLAG_CF_VIS_18
	removeobject LOCALID_CF_GYM_FLORA
	releaseall
	end

CF_C1_NormanTalk::
	msgbox CF1_T_021, MSGBOX_NPC
	end

CF_C1_FloraTalk::
	msgbox CF1_T_007, MSGBOX_NPC
	end

CF_C1_CeleoTalk::
	lock
	faceplayer
	cf_if_dec 1, DEC_A, CF_C1_CeleoTalkA
	msgbox CF1_T_013, MSGBOX_DEFAULT
	release
	end

CF_C1_CeleoTalkA::
	msgbox CF1_T_014, MSGBOX_DEFAULT
	release
	end

@ Coach (Petalburg Pokemon Center)
CF_C1_Coach::
	lock
	faceplayer
	msgbox CF1_T_022, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CF_C1_CoachYes
	clearflag FLAG_CHOOSE_BATTLE_LEAD
	goto CF_C1_CoachEnd

CF_C1_CoachYes::
	setflag FLAG_CHOOSE_BATTLE_LEAD
CF_C1_CoachEnd::
	msgbox CF1_T_023, MSGBOX_DEFAULT
	release
	end

@ ---------------------------------------------------------------- C2: barrage du Bois

CF_C2_BarrageTalk::
	msgbox CF1_T_024, MSGBOX_NPC
	end

CF_C2_Barrage::
	goto_if_set FLAG_CF_VIS_10, CF_Nop
	lockall
	msgbox CF1_T_024, MSGBOX_DEFAULT
	goto_if_set FLAG_CF_INSIGNE, CF_C2_Insigne
	getbits VAR_CF_WORLD, 0, 2
	goto_if_ge VAR_RESULT, 1, CF_C2_Registered
	checkfollowernpc
	goto_if_eq VAR_RESULT, FALSE, CF_C2_Fallback
	goto_if_lt VAR_CF_BR, 50, CF_C2_Fallback
	msgbox CF1_T_025, MSGBOX_DEFAULT
	msgbox CF1_T_026, MSGBOX_DEFAULT
	goto CF_C2_Pass

CF_C2_Insigne::
	msgbox CF1_T_027, MSGBOX_DEFAULT
	goto CF_C2_Pass

CF_C2_Registered::
	msgbox CF1_T_028, MSGBOX_DEFAULT
	goto CF_C2_Pass

CF_C2_Fallback::
	msgbox CF1_T_029, MSGBOX_DEFAULT
	msgbox CF1_T_030, MSGBOX_DEFAULT
	goto CF_C2_Pass

CF_C2_Pass::
	closemessage
	setflag FLAG_CF_VIS_10
	removeobject LOCALID_CF_R104_BAR_A1
	removeobject LOCALID_CF_R104_BAR_A2
	removeobject LOCALID_CF_R104_BAR_B1
	removeobject LOCALID_CF_R104_BAR_B2
	releaseall
	end

@ ---------------------------------------------------------------- C3: Flora au Bois (D008)

CF_C3_Scene::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, CF_Mov_Up2
	waitmovement 0
	msgbox CF1_T_031, MSGBOX_DEFAULT
	msgbox CF1_T_032, MSGBOX_DEFAULT
	cf_bsay CF1_T_033
	msgbox CF1_T_034, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_CF_NO_WHITEOUT
	trainerbattle_scene_declinable TRAINER_BROOKE_4, CF1_T_035, CF1_T_036, FLAG_CF_REFUS_FLORA1, CF_D008_Refus
	goto_if_set TRAINER_FLAGS_START + TRAINER_BROOKE_4, CF_D008_Won
	goto CF_D008_Lost

CF_D008_Won::
	clearflag FLAG_CF_NO_WHITEOUT
	special HealPlayerParty
	msgbox CF1_T_037, MSGBOX_DEFAULT
	msgbox CF1_T_038, MSGBOX_DEFAULT
	setdecision_once 8, DEC_A, CF_C3_End
	subaffinity VAR_CF_FL, 3
	subaffinity VAR_CF_REP_L, 3
	setflag FLAG_CF_BOIS_SAUVES
	clearflag FLAG_CF_VIS_23
	addobject LOCALID_CF_WOODS_WOOLOO_S
	addobject LOCALID_CF_WOODS_YAMPER_S
	addobject LOCALID_CF_WOODS_APPLIN_S
	goto CF_C3_End

CF_D008_Lost::
	clearflag FLAG_CF_NO_WHITEOUT
	special HealPlayerParty
	msgbox CF1_T_039, MSGBOX_DEFAULT
	setdecision_once 8, DEC_B, CF_C3_End
	addaffinity VAR_CF_FL, 2
	addaffinity VAR_CF_REP_L, 1
	cf_lose_money 300
	goto CF_C3_End

CF_D008_Refus::
	clearflag FLAG_CF_NO_WHITEOUT
	msgbox CF1_T_040, MSGBOX_DEFAULT
	msgbox CF1_T_041, MSGBOX_DEFAULT
	setdecision_once 8, DEC_C, CF_C3_End
	addaffinity VAR_CF_FL, 3
	subaffinity VAR_CF_BR, 2
	goto CF_C3_End

CF_C3_End::
	closemessage
	setvar VAR_PETALBURG_WOODS_STATE, 1
	setflag FLAG_CF_VIS_19
	setflag FLAG_CF_VIS_21
	setflag FLAG_CF_VIS_22
	removeobject LOCALID_PETALBURG_WOODS_GRUNT
	removeobject LOCALID_CF_WOODS_POLICE_L
	removeobject LOCALID_CF_WOODS_POLICE_R
	removeobject LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE
	removeobject LOCALID_CF_WOODS_YAMPER
	removeobject LOCALID_CF_WOODS_APPLIN
	releaseall
	end

CF_C3_SavedWooloo::
	msgbox CF1_T_042, MSGBOX_NPC
	end

CF_C3_SavedYamper::
	msgbox CF1_T_043, MSGBOX_NPC
	end

CF_C3_SavedApplin::
	msgbox CF1_T_044, MSGBOX_NPC
	end

@ ---------------------------------------------------------------- C4: l'affiche (D009)

CF_C4_PosterRead::
	msgbox CF1_T_045, MSGBOX_SIGN
	end

CF_C4_Poster::
	lockall
	msgbox CF1_T_045, MSGBOX_DEFAULT
	msgbox CF1_T_046, MSGBOX_DEFAULT
	checkfollowernpc
	goto_if_eq VAR_RESULT, FALSE, CF_C4_NoBrice
	msgbox CF1_T_047, MSGBOX_DEFAULT
	goto CF_C4_Menu

CF_C4_NoBrice::
	clearflag FLAG_CF_VIS_24
	addobject LOCALID_CF_RUST_PASSANTE
	msgbox CF1_T_048, MSGBOX_DEFAULT
CF_C4_Menu::
	closemessage
	dynmultipush CF1_T_049, 0
	dynmultipush CF1_T_050, 1
	dynmultistack 0, 0, TRUE, 2, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	closemessage
	switch VAR_RESULT
	case 0, CF_C4_Stay
	case 1, CF_C4_Leave
	end

CF_C4_Stay::
	msgbox CF1_T_051, MSGBOX_DEFAULT
	cf_bsay CF1_T_052
	setdecision_once 9, DEC_A, CF_C4_End
	setflag FLAG_CF_DOS_AFFICHE_SYLPHE
	addaffinity VAR_CF_BR, 2
	addaffinity VAR_CF_RK, 2
	call CF_IncN
	goto CF_C4_End

CF_C4_Leave::
	msgbox CF1_T_053, MSGBOX_DEFAULT
	setdecision_once 9, DEC_B, CF_C4_End
	subaffinity VAR_CF_BR, 1
	goto CF_C4_End

CF_C4_End::
	closemessage
	setvar VAR_RUSTBORO_CITY_STATE, 10
	setflag FLAG_CF_VIS_24
	removeobject LOCALID_CF_RUST_PASSANTE
	releaseall
	end

@ ---------------------------------------------------------------- C5: "Ferrand" (D013)

CF_C5_Ferrand::
	lock
	faceplayer
	checkdecision 13
	goto_if_ne VAR_RESULT, DEC_NONE, CF_C5_Again
	msgbox CF1_T_054, MSGBOX_DEFAULT
	message CF1_T_055
	waitmessage
	dynmultipush CF1_T_056, 0
	dynmultipush CF1_T_050, 1
	dynmultistack 0, 0, TRUE, 2, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	closemessage
	switch VAR_RESULT
	case 0, CF_C5_Talk
	case 1, CF_C5_Go
	end

CF_C5_Talk::
	msgbox CF1_T_057, MSGBOX_DEFAULT
	msgbox CF1_T_058, MSGBOX_DEFAULT
	cf_bsay CF1_T_059
	setdecision_once 13, DEC_A, CF_C5_End
	setflag FLAG_CF_LAMBDA_REMARQUE
	addaffinity VAR_CF_RK, 3
	goto CF_C5_End

CF_C5_Go::
	msgbox CF1_T_060, MSGBOX_DEFAULT
	setdecision_once 13, DEC_B, CF_C5_End
	subaffinity VAR_CF_BR, 1
	goto CF_C5_End

CF_C5_Again::
	msgbox CF1_T_061, MSGBOX_DEFAULT
CF_C5_End::
	release
	end

@ ---------------------------------------------------------------- C6: Passerelle (D011)

CF_C6_Show::
	clearflag FLAG_CF_VIS_26
	clearflag FLAG_CF_VIS_27
	clearflag FLAG_CF_VIS_04
	return

CF_C6_Scene::
	lockall
	msgbox CF1_T_062, MSGBOX_DEFAULT
	msgbox CF1_T_063, MSGBOX_DEFAULT
	msgbox CF1_T_064, MSGBOX_DEFAULT
	msgbox CF1_T_065, MSGBOX_DEFAULT
	cf_if_dec 1, DEC_A, CF_C6_CeleoA
	msgbox CF1_T_066, MSGBOX_DEFAULT
	goto CF_C6_President

CF_C6_CeleoA::
	msgbox CF1_T_067, MSGBOX_DEFAULT
CF_C6_President::
	cf_if_dec 9, DEC_A, CF_C6_PresidentA
	msgbox CF1_T_068, MSGBOX_DEFAULT
	goto CF_C6_Photo

CF_C6_PresidentA::
	msgbox CF1_T_069, MSGBOX_DEFAULT
CF_C6_Photo::
	message CF1_T_070
	waitmessage
	dynmultipush CF1_T_071, 0
	dynmultipush CF1_T_050, 1
	dynmultistack 0, 0, TRUE, 2, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	closemessage
	switch VAR_RESULT
	case 0, CF_C6_Pose
	case 1, CF_C6_Decline
	end

CF_C6_Pose::
	msgbox CF1_T_072, MSGBOX_DEFAULT
	setdecision_once 11, DEC_A, CF_C6_Common
	addaffinity VAR_CF_REP_C, 5
	subaffinity VAR_CF_REP_P, 3
	call CF_IncN
	goto CF_C6_Common

CF_C6_Decline::
	msgbox CF1_T_073, MSGBOX_DEFAULT
	setdecision_once 11, DEC_B, CF_C6_Common
	subaffinity VAR_CF_REP_C, 3
	addaffinity VAR_CF_REP_P, 2
	goto CF_C6_Common

CF_C6_Common::
	msgbox CF1_T_074, MSGBOX_DEFAULT
	giveitem ITEM_LETTER
	msgbox CF1_T_075, MSGBOX_DEFAULT
	cf_if_dec 5, DEC_B, CF_C6_BriceEnters
CF_C6_Done::
	closemessage
	setvar VAR_DEVON_CORP_3F_STATE, 1
	releaseall
	end

CF_C6_BriceEnters::
	checkfollowernpc
	goto_if_eq VAR_RESULT, TRUE, CF_C6_Done
	msgbox CF1_T_076, MSGBOX_DEFAULT
	closemessage
	createfollowernpc OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL, FNPC_ALL_LAND
	goto CF_C6_Done

CF_C6_RochardTalk::
	msgbox CF1_T_075, MSGBOX_NPC
	end

CF_C6_PresidentTalk::
	msgbox CF1_T_063, MSGBOX_NPC
	end

CF_C6_LeoTalk::
	msgbox CF1_T_064, MSGBOX_NPC
	end

CF_C6_LanetteTalk::
	msgbox CF1_T_065, MSGBOX_NPC
	end

CF_C6_CeleoTalk::
	lock
	faceplayer
	cf_if_dec 1, DEC_A, CF_C6_CeleoTalkA
	msgbox CF1_T_066, MSGBOX_DEFAULT
	release
	end

CF_C6_CeleoTalkA::
	msgbox CF1_T_067, MSGBOX_DEFAULT
	release
	end

@ ---------------------------------------------------------------- C7: le petit voleur (D012)

CF_C7_Thief::
	cf_if_dec 11, DEC_NONE, CF_Nop
	lockall
	clearflag FLAG_CF_VIS_28
	addobject LOCALID_CF_RUST_HOOPA
	delay 20
	msgbox CF1_T_077, MSGBOX_DEFAULT
	cf_bsay CF1_T_078
	message CF1_T_079
	waitmessage
	checkitem ITEM_ORAN_BERRY
	goto_if_eq VAR_RESULT, FALSE, CF_C7_MenuNoBerry
	dynmultipush CF1_T_080, 0
	dynmultipush CF1_T_081, 1
	dynmultipush CF1_T_082, 2
	dynmultistack 0, 0, TRUE, 3, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	goto CF_C7_Choice

CF_C7_MenuNoBerry::
	dynmultipush CF1_T_081, 1
	dynmultipush CF1_T_082, 2
	dynmultistack 0, 0, TRUE, 2, FALSE, 0, DYN_MULTICHOICE_CB_NONE
CF_C7_Choice::
	closemessage
	switch VAR_RESULT
	case 0, CF_C7_Berry
	case 1, CF_C7_Chase
	case 2, CF_C7_Nothing
	end

CF_C7_Berry::
	removeitem ITEM_ORAN_BERRY
	msgbox CF1_T_083, MSGBOX_DEFAULT
	cf_bsay CF1_T_084
	setdecision_once 12, DEC_A, CF_C7_End
	addaffinity VAR_CF_HO, 5
	subaffinity VAR_CF_BR, 2
	goto CF_C7_End

CF_C7_Chase::
	msgbox CF1_T_085, MSGBOX_DEFAULT
	cf_bsay CF1_T_086
	setdecision_once 12, DEC_B, CF_C7_End
	subaffinity VAR_CF_HO, 3
	addaffinity VAR_CF_BR, 2
	setvar VAR_0x8004, 8
	call CF_IncBV
	goto CF_C7_End

CF_C7_Nothing::
	cf_bsay CF1_T_087
	setdecision_once 12, DEC_C, CF_C7_End
	addaffinity VAR_CF_HO, 1
	subaffinity VAR_CF_BR, 1
	goto CF_C7_End

CF_C7_End::
	closemessage
	setvar VAR_RUSTBORO_CITY_STATE, 11
	setflag FLAG_CF_VIS_28
	removeobject LOCALID_CF_RUST_HOOPA
	releaseall
	end

@ ---------------------------------------------------------------- C8: les mines (D010)

CF_C8_Scene::
	lockall
	msgbox CF1_T_088, MSGBOX_DEFAULT
	msgbox CF1_T_089, MSGBOX_DEFAULT
	msgbox CF1_T_090, MSGBOX_DEFAULT
	msgbox CF1_T_091, MSGBOX_DEFAULT
	msgbox CF1_T_092, MSGBOX_DEFAULT
	message CF1_T_093
	waitmessage
	dynmultipush CF1_T_094, 0
	dynmultipush CF1_T_095, 1
	dynmultipush CF1_T_096, 2
	dynmultistack 0, 0, TRUE, 3, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	closemessage
	switch VAR_RESULT
	case 0, CF_C8_Move
	case 1, CF_C8_Data
	case 2, CF_C8_Leave
	end

CF_C8_Move::
	msgbox CF1_T_097, MSGBOX_DEFAULT
	setdecision_once 10, DEC_A, CF_C8_Hide
	setbits VAR_CF_ECO, 2, 2, ECO_RESTAURE
	addaffinity VAR_CF_REP_I, 3
	subaffinity VAR_CF_REP_P, 3
	setflag FLAG_CF_BROCK_PROTEGES
	goto CF_C8_Hide

CF_C8_Data::
	msgbox CF1_T_098, MSGBOX_DEFAULT
	setdecision_once 10, DEC_B, CF_C8_End
	setbits VAR_CF_ECO, 2, 2, ECO_MIXTE
	addaffinity VAR_CF_REP_C, 3
	addaffinity VAR_CF_REP_P, 2
	subaffinity VAR_CF_REP_A, 2
	goto CF_C8_End

CF_C8_Leave::
	msgbox CF1_T_099, MSGBOX_DEFAULT
	setdecision_once 10, DEC_C, CF_C8_Hide
	setbits VAR_CF_ECO, 2, 2, ECO_ABATTU
	addaffinity VAR_CF_REP_L, 4
	addaffinity VAR_CF_REP_P, 3
	subaffinity VAR_CF_REP_I, 3
	subaffinity VAR_CF_TI, 2
	goto CF_C8_Hide

CF_C8_Hide::
	setflag FLAG_CF_VIS_34
	removeobject LOCALID_CF_TUN_CHARBI
	removeobject LOCALID_CF_TUN_STRASSIE
CF_C8_End::
	cf_bsay CF1_T_100
	msgbox CF1_T_101, MSGBOX_DEFAULT
	closemessage
	setvar VAR_RUSTURF_TUNNEL_STATE, 1
	setflag FLAG_CF_VIS_31
	removeobject LOCALID_CF_TUN_ROXANNE
	releaseall
	end

CF_C8_MinerTalk::
	msgbox CF1_T_088, MSGBOX_NPC
	end

CF_C8_CharbiTalk::
	msgbox CF1_T_102, MSGBOX_NPC
	end

CF_C8_StrassieTalk::
	msgbox CF1_T_103, MSGBOX_NPC
	end

@ Pierre's challenge (content, not counted): after badge 1
CF_C8_Pierre::
	lock
	faceplayer
	goto_if_set FLAG_BADGE01_GET, CF_C8_PierreDuel
	msgbox CF1_T_091, MSGBOX_DEFAULT
	release
	end

CF_C8_PierreDuel::
	getbits VAR_CF_ECO, 2, 2
	goto_if_eq VAR_RESULT, ECO_RESTAURE, CF_C8_PierreDuel5
	trainerbattle_single_declinable TRAINER_VALERIE_4, CF1_T_104, CF1_T_105, 0
	goto CF_C8_PierreAfter

CF_C8_PierreDuel5::
	trainerbattle_single_declinable TRAINER_VALERIE_5, CF1_T_104, CF1_T_105, 0
CF_C8_PierreAfter::
	msgbox CF1_T_106, MSGBOX_DEFAULT
	release
	end

@ ---------------------------------------------------------------- C9: Roxanne (D016)

CF_C9_Reward::
	raisecap 18
	giveitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	cf_if_dec 16, DEC_NONE, CF_C9_Ask
	release
	end

CF_C9_Ask::
	msgbox CF1_T_107, MSGBOX_DEFAULT
	message CF1_T_108
	waitmessage
	dynmultipush CF1_T_109, 0
	dynmultipush CF1_T_018, 1
	dynmultistack 0, 0, TRUE, 2, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	closemessage
	switch VAR_RESULT
	case 0, CF_C9_Give
	case 1, CF_C9_Refuse
	end

CF_C9_Give::
	msgbox CF1_T_110, MSGBOX_DEFAULT
	setdecision_once 16, DEC_A, CF_C9_End
	addaffinity VAR_CF_REP_L, 3
	subaffinity VAR_CF_BR, 2
	goto CF_C9_End

CF_C9_Refuse::
	cf_bsay CF1_T_111
	msgbox CF1_T_112, MSGBOX_DEFAULT
	setdecision_once 16, DEC_B, CF_C9_End
	subaffinity VAR_CF_REP_L, 2
	addaffinity VAR_CF_BR, 2
	goto CF_C9_End

CF_C9_End::
	release
	end

@ Gym door (Rustboro): closed until D010 (Roxanne is in the mines)
CF_C9_GymGate::
	cf_if_dec 10, DEC_NONE, CF_C9_GymClosed
	end

CF_C9_GymClosed::
	lockall
	msgbox CF1_T_113, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CF_Mov_Down1
	waitmovement 0
	releaseall
	end

@ ---------------------------------------------------------------- C10: contrebandiers de la R116 (D014, D015)

CF_R116_Show::
	checkdecision 16
	goto_if_ne VAR_RESULT, DEC_A, CF_R116_Show_End
	clearflag FLAG_CF_VIS_13
CF_R116_Show_End::
	return

CF_C10_NetTalk::
	msgbox CF1_T_114, MSGBOX_NPC
	end

CF_C10_Scene::
	goto_if_unset FLAG_BADGE01_GET, CF_Nop
	lockall
	cf_if_dec 16, DEC_A, CF_C10_Net
CF_C10_Brice::
	cf_bsay CF1_T_115
	clearflag FLAG_CF_VIS_35
	clearflag FLAG_CF_VIS_36
	clearflag FLAG_CF_VIS_37
	cf_if_dec 13, DEC_A, CF_C10_ShowFerrand
CF_C10_ShowHoopa::
	goto_if_lt VAR_CF_HO, 25, CF_C10_Spawn
	clearflag FLAG_CF_VIS_30
CF_C10_Spawn::
	addobject LOCALID_CF_R116_LANCE
	addobject LOCALID_CF_R116_GRUNT_A
	addobject LOCALID_CF_R116_GRUNT_B
	addobject LOCALID_CF_R116_FERRAND
	addobject LOCALID_CF_R116_HOOPA
	delay 20
	msgbox CF1_T_116, MSGBOX_DEFAULT
	msgbox CF1_T_117, MSGBOX_DEFAULT
	msgbox CF1_T_118, MSGBOX_DEFAULT
	cf_if_dec 13, DEC_A, CF_C10_Ferrand
CF_C10_Poster::
	cf_if_dec 9, DEC_A, CF_C10_PosterA
CF_C10_Menu::
	dynmultipush CF1_T_119, 0
	dynmultipush CF1_T_120, 1
	dynmultipush CF1_T_121, 2
	dynmultistack 0, 0, TRUE, 3, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	closemessage
	switch VAR_RESULT
	case 0, CF_C10_Fight
	case 1, CF_C10_Watch
	case 2, CF_C10_Warn
	end

CF_C10_Net::
	msgbox CF1_T_114, MSGBOX_DEFAULT
	goto CF_C10_Brice

CF_C10_ShowFerrand::
	clearflag FLAG_CF_VIS_25
	goto CF_C10_ShowHoopa

CF_C10_Ferrand::
	cf_bsay CF1_T_122
	msgbox CF1_T_123, MSGBOX_DEFAULT
	setflag FLAG_CF_VIS_25
	removeobject LOCALID_CF_R116_FERRAND
	goto CF_C10_Poster

CF_C10_PosterA::
	message CF1_T_124
	waitmessage
	goto CF_C10_Menu

CF_C10_Fight::
	setflag FLAG_CF_NO_WHITEOUT
	trainerbattle_scene_no_intro TRAINER_GRUNT_PETALBURG_WOODS, CF1_T_125
	goto_if_unset TRAINER_FLAGS_START + TRAINER_GRUNT_PETALBURG_WOODS, CF_C10_FightEnd
	trainerbattle_scene_no_intro TRAINER_GRUNT_RUSTURF_TUNNEL, CF1_T_126
CF_C10_FightEnd::
	clearflag FLAG_CF_NO_WHITEOUT
	special HealPlayerParty
	msgbox CF1_T_127, MSGBOX_DEFAULT
	call CF_C10_LoseItem
	msgbox CF1_T_128, MSGBOX_DEFAULT
	setdecision_once 14, DEC_A, CF_C10_End
	subaffinity VAR_CF_RK, 3
	addaffinity VAR_CF_REP_L, 1
	cf_lose_money 200
	goto CF_C10_End

CF_C10_Watch::
	msgbox CF1_T_129, MSGBOX_DEFAULT
	msgbox CF1_T_130, MSGBOX_DEFAULT
	cf_bsay CF1_T_131
	setdecision_once 14, DEC_B, CF_C10_End
	setflag FLAG_CF_DOS_HORAIRE_R116
	addaffinity VAR_CF_RK, 3
	goto CF_C10_End

CF_C10_Warn::
	msgbox CF1_T_132, MSGBOX_DEFAULT
	clearflag FLAG_CF_VIS_20
	addobject LOCALID_CF_R116_FLORA
	cf_if_dec 8, DEC_A, CF_C10_FloraA
	msgbox CF1_T_133, MSGBOX_DEFAULT
	goto CF_C10_Warn2

CF_C10_FloraA::
	msgbox CF1_T_134, MSGBOX_DEFAULT
CF_C10_Warn2::
	msgbox CF1_T_135, MSGBOX_DEFAULT
	setdecision_once 14, DEC_C, CF_C10_End
	addaffinity VAR_CF_REP_L, 3
	subaffinity VAR_CF_REP_A, 2
	subaffinity VAR_CF_TI, 1
	goto CF_C10_End

CF_C10_End::
	closemessage
	setflag FLAG_CF_VIS_35
	setflag FLAG_CF_VIS_36
	setflag FLAG_CF_VIS_30
	setflag FLAG_CF_VIS_25
	setflag FLAG_CF_VIS_20
	removeobject LOCALID_CF_R116_LANCE
	removeobject LOCALID_CF_R116_GRUNT_A
	removeobject LOCALID_CF_R116_HOOPA
	removeobject LOCALID_CF_R116_FERRAND
	removeobject LOCALID_CF_R116_FLORA
	setvar VAR_ROUTE116_STATE, 2
	releaseall
	end

@ One item of the first owned kind among: Super Potion, Potion, Antidote, Poke Ball
CF_C10_LoseItem::
	checkitem ITEM_SUPER_POTION
	goto_if_eq VAR_RESULT, TRUE, CF_C10_LoseSuper
	checkitem ITEM_POTION
	goto_if_eq VAR_RESULT, TRUE, CF_C10_LosePotion
	checkitem ITEM_ANTIDOTE
	goto_if_eq VAR_RESULT, TRUE, CF_C10_LoseAntidote
	checkitem ITEM_POKE_BALL
	goto_if_eq VAR_RESULT, TRUE, CF_C10_LoseBall
	return

CF_C10_LoseSuper::
	bufferitemname STR_VAR_1, ITEM_SUPER_POTION
	removeitem ITEM_SUPER_POTION
	goto CF_C10_LoseMsg

CF_C10_LosePotion::
	bufferitemname STR_VAR_1, ITEM_POTION
	removeitem ITEM_POTION
	goto CF_C10_LoseMsg

CF_C10_LoseAntidote::
	bufferitemname STR_VAR_1, ITEM_ANTIDOTE
	removeitem ITEM_ANTIDOTE
	goto CF_C10_LoseMsg

CF_C10_LoseBall::
	bufferitemname STR_VAR_1, ITEM_POKE_BALL
	removeitem ITEM_POKE_BALL
CF_C10_LoseMsg::
	msgbox CF1_T_136, MSGBOX_DEFAULT
	return

@ The ruined grunt (D015)
CF_C10_SbireB::
	lock
	faceplayer
	cf_if_dec 15, DEC_NONE, CF_C10_SbireBTalk
	release
	end

CF_C10_SbireBTalk::
	msgbox CF1_T_137, MSGBOX_DEFAULT
	msgbox CF1_T_138, MSGBOX_DEFAULT
	cf_if_dec 11, DEC_A, CF_C10_SbireBPhotoA
	msgbox CF1_T_139, MSGBOX_DEFAULT
	goto CF_C10_SbireBMenu

CF_C10_SbireBPhotoA::
	msgbox CF1_T_140, MSGBOX_DEFAULT
CF_C10_SbireBMenu::
	closemessage
	checkmoney 500
	goto_if_eq VAR_RESULT, FALSE, CF_C10_SbireBMenuPoor
	dynmultipush CF1_T_141, 0
	dynmultipush CF1_T_050, 1
	dynmultistack 0, 0, TRUE, 2, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	goto CF_C10_SbireBChoice

CF_C10_SbireBMenuPoor::
	dynmultipush CF1_T_050, 1
	dynmultistack 0, 0, TRUE, 1, FALSE, 0, DYN_MULTICHOICE_CB_NONE
CF_C10_SbireBChoice::
	closemessage
	switch VAR_RESULT
	case 0, CF_C10_Give
	case 1, CF_C10_NoGive
	end

CF_C10_Give::
	msgbox CF1_T_142, MSGBOX_DEFAULT
	setdecision_once 15, DEC_A, CF_C10_SbireBEnd
	subaffinity VAR_CF_RK, 2
	addaffinity VAR_CF_REP_P, 2
	removemoney 500
	clearflag FLAG_CF_VIS_38
	goto CF_C10_SbireBEnd

CF_C10_NoGive::
	msgbox CF1_T_143, MSGBOX_DEFAULT
	setdecision_once 15, DEC_B, CF_C10_SbireBEnd
	addaffinity VAR_CF_RK, 2
	goto CF_C10_SbireBEnd

CF_C10_SbireBEnd::
	closemessage
	setflag FLAG_CF_VIS_37
	removeobject LOCALID_CF_R116_GRUNT_B
	release
	end

CF_C10_ExMiner::
	msgbox CF1_T_144, MSGBOX_NPC
	end

@ ---------------------------------------------------------------- C11: end of the demo

CF_C11_Scene::
	lockall
	checkfollowernpc
	goto_if_eq VAR_RESULT, FALSE, CF_C11_Brice
	destroyfollowernpc
CF_C11_Brice::
	clearflag FLAG_CF_VIS_43
	addobject LOCALID_CF_PC_BRICE
	delay 20
	msgbox CF1_T_145, MSGBOX_DEFAULT
	getbits VAR_CF_ECO, 2, 2
	goto_if_eq VAR_RESULT, ECO_RESTAURE, CF_C11_BulletinR
	goto_if_eq VAR_RESULT, ECO_ABATTU, CF_C11_BulletinA
	msgbox CF1_T_146, MSGBOX_DEFAULT
	goto CF_C11_Recap

CF_C11_BulletinR::
	msgbox CF1_T_147, MSGBOX_DEFAULT
	goto CF_C11_Recap

CF_C11_BulletinA::
	msgbox CF1_T_148, MSGBOX_DEFAULT
CF_C11_Recap::
	cf_if_dec 1, DEC_A, CF_C11_RecapA
	msgbox CF1_T_149, MSGBOX_DEFAULT
	goto CF_C11_Recap6

CF_C11_RecapA::
	msgbox CF1_T_150, MSGBOX_DEFAULT
CF_C11_Recap6::
	cf_if_dec 6, DEC_A, CF_C11_Recap6A
CF_C11_Recap8::
	cf_if_dec 8, DEC_A, CF_C11_Recap8A
CF_C11_Recap15::
	cf_if_dec 15, DEC_A, CF_C11_Recap15A
	goto CF_C11_Thief

CF_C11_Recap6A::
	msgbox CF1_T_151, MSGBOX_DEFAULT
	goto CF_C11_Recap8

CF_C11_Recap8A::
	msgbox CF1_T_152, MSGBOX_DEFAULT
	goto CF_C11_Recap15

CF_C11_Recap15A::
	msgbox CF1_T_153, MSGBOX_DEFAULT
CF_C11_Thief::
	clearflag FLAG_CF_VIS_29
	addobject LOCALID_CF_PC_HOOPA
	goto_if_ge VAR_CF_HO, 25, CF_C11_ThiefGift
	goto_if_le VAR_CF_HO, 18, CF_C11_ThiefTake
	msgbox CF1_T_154, MSGBOX_DEFAULT
	goto CF_C11_Thesis

CF_C11_ThiefGift::
	msgbox CF1_T_155, MSGBOX_DEFAULT
	giveitem ITEM_ORAN_BERRY
	msgbox CF1_T_156, MSGBOX_DEFAULT
	goto CF_C11_Thesis

CF_C11_ThiefTake::
	msgbox CF1_T_157, MSGBOX_DEFAULT
	checkitem ITEM_POKE_BALL
	goto_if_eq VAR_RESULT, FALSE, CF_C11_Thesis
	removeitem ITEM_POKE_BALL
CF_C11_Thesis::
	setflag FLAG_CF_VIS_29
	removeobject LOCALID_CF_PC_HOOPA
	msgbox CF1_T_158, MSGBOX_DEFAULT
	msgbox CF1_T_159, MSGBOX_DEFAULT
	msgbox CF1_T_160, MSGBOX_DEFAULT
	msgbox CF1_T_161, MSGBOX_DEFAULT
	closemessage
	setvar VAR_CF_CHAPTER, 2
	setvar VAR_ROUTE116_STATE, 3
	call Common_EventScript_SaveGame
	releaseall
	end

CF_C11_BriceTalk::
	msgbox CF1_T_158, MSGBOX_NPC
	end

CF_C11_Bulletin::
	getbits VAR_CF_ECO, 2, 2
	goto_if_eq VAR_RESULT, ECO_RESTAURE, CF_C11_BulletinSignR
	goto_if_eq VAR_RESULT, ECO_ABATTU, CF_C11_BulletinSignA
	msgbox CF1_T_146, MSGBOX_SIGN
	end

CF_C11_BulletinSignR::
	msgbox CF1_T_147, MSGBOX_SIGN
	end

CF_C11_BulletinSignA::
	msgbox CF1_T_148, MSGBOX_SIGN
	end

@ ---------------------------------------------------------------- generated boxes (<= 208 px, 2 lines)

CF1_T_000::
	.string "Bureaux du Rempart. Défense\n"
	.string "d’entrer.$"

CF1_T_001::
	.string "Au-delà, c’est la zone des anneaux.\n"
	.string "Interdit.$"

CF1_T_002::
	.string "Route 115 fermée : hordes.\n"
	.string "Revenez plus tard.$"

CF1_T_003::
	.string "La Coupe ? Quand les traversées\n"
	.string "reprendront, petit.$"

CF1_T_004::
	.string "Red. Le Rempart a une règle :\n"
	.string "ici, rien ne passe sans contrôle.$"

CF1_T_005::
	.string "Le Passeur, hein ? Mon registre\n"
	.string "déteste les surnoms.$"

CF1_T_006::
	.string "Votre nom est sur ma liste. Ne\n"
	.string "me faites pas regretter de l’y avoir.$"

CF1_T_007::
	.string "Flora, cadette de la brigade.\n"
	.string "Et la fille de ce monsieur.$"

CF1_T_008::
	.string "Merci pour le Zigzaton d’hier.\n"
	.string "Il est au chaud.$"

CF1_T_009::
	.string "Il paraît que tu as gardé un\n"
	.string "arrivant. Déclaré, j’espère ?$"

CF1_T_010::
	.string "Votre ingénieur a dormi ici.\n"
	.string "Il réclamait un avocat.$"

CF1_T_011::
	.string "Red ! Dis-leur que je suis venu\n"
	.string "de moi-même !$"

CF1_T_012::
	.string "Il peut partir. Sous votre\n"
	.string "responsabilité.$"

CF1_T_013::
	.string "Mon disque prouve l’heure de chaque\n"
	.string "transfert. Ils vont voir.$"

CF1_T_014::
	.string "Sans mon disque, je n’ai que ma\n"
	.string "parole. Ici, ça ne vaut rien.$"

CF1_T_015::
	.string "Nos barrages ferment les routes.\n"
	.string "Ceci vous les ouvre.$"

CF1_T_016::
	.string "Norman tend un insigne du\n"
	.string "Rempart.$"

CF1_T_017::
	.string "Accepter l’insigne$"

CF1_T_018::
	.string "Refuser$"

CF1_T_019::
	.string "Portez-le bien en vue. Les gens\n"
	.string "sauront de quel côté vous êtes.$"

CF1_T_020::
	.string "À votre guise. Chaque barrage\n"
	.string "vous demandera un garant.$"

CF1_T_021::
	.string "Flora part au Bois Clémenti. Une\n"
	.string "horde y niche. Allez voir.$"

CF1_T_022::
	.string "Moi, j’entraîne. Tu veux choisir ton\n"
	.string "Pokémon de tête avant un duel ?$"

CF1_T_023::
	.string "C’est noté. Reviens me voir pour\n"
	.string "changer d’avis.$"

CF1_T_024::
	.string "Barrage du Rempart. Le Bois est\n"
	.string "fermé aux civils.$"

CF1_T_025::
	.string "Il est avec moi. Mon père s’en\n"
	.string "porte garant.$"

CF1_T_026::
	.string "Le fils de Seko… Bon. Passez.$"

CF1_T_027::
	.string "L’insigne. Passez, monsieur.$"

CF1_T_028::
	.string "Red, de Kanto ? Le chef vous a\n"
	.string "inscrit. Passez.$"

CF1_T_029::
	.string "Pas d’insigne, pas de garant ?\n"
	.string "Alors vous attendez.$"

CF1_T_030::
	.string "Laisse, je l’emmène. Sous escorte.\n"
	.string "Tu me suis, Red.$"

CF1_T_031::
	.string "Trois arrivants de Galar. Ils\n"
	.string "pillent les nids des Nirondelle.$"

CF1_T_032::
	.string "Ordre du Rempart : on les abat.\n"
	.string "Rien de personnel.$"

CF1_T_033::
	.string "Les abattre ? Ils sont juste\n"
	.string "perdus, Flora !$"

CF1_T_034::
	.string "Red s’avance entre la brigade et\n"
	.string "les arrivants.$"

CF1_T_035::
	.string "Tu veux les protéger ? Alors\n"
	.string "prouve-le. En duel.$"

CF1_T_036::
	.string "D’accord, d’accord ! Tu as gagné.$"

CF1_T_037::
	.string "Ils filent. Mon père va adorer\n"
	.string "mon rapport.$"

CF1_T_038::
	.string "Flora s’en souviendra. Moi aussi.$"

CF1_T_039::
	.string "Au moins, tu t’es battu. Frais de\n"
	.string "brigade : 300 Pokédollars.$"

CF1_T_040::
	.string "On les laisse faire ?$"

CF1_T_041::
	.string "Sage décision. Je te salue, Red.$"

CF1_T_042::
	.string "Moumouton bêle doucement.$"

CF1_T_043::
	.string "Voltoutou jappe joyeusement.$"

CF1_T_044::
	.string "Verpom roule sur lui-même.$"

CF1_T_045::
	.string "Une affiche : ‘Il a sauvé Sylphe.\n"
	.string "Sylphe relie le monde.’$"

CF1_T_046::
	.string "‘Passerelle, depuis cinq mois.’\n"
	.string "Un garçon de dos, casquette rouge.$"

CF1_T_047::
	.string "…C’est toi. Sur l’affiche,\n"
	.string "c’est toi.$"

CF1_T_048::
	.string "Vous ressemblez au garçon de\n"
	.string "l’affiche. Celui de Kanto.$"

CF1_T_049::
	.string "Rester devant$"

CF1_T_050::
	.string "Partir$"

CF1_T_051::
	.string "Un passant prend une photo. Red\n"
	.string "ne bouge pas.$"

CF1_T_052::
	.string "Un contrat, je parie. Signé contre\n"
	.string "la Master Ball, à onze ans.$"

CF1_T_053::
	.string "C’était toi ? …Pas de réponse.\n"
	.string "D’accord.$"

CF1_T_054::
	.string "Le célèbre Red ! Ferrand, ingénieur\n"
	.string "Passerelle. Enchanté.$"

CF1_T_055::
	.string "Le Rubis et le Saphir… Vous les\n"
	.string "avez tenus longtemps ?$"

CF1_T_056::
	.string "Le laisser parler$"

CF1_T_057::
	.string "Fascinant. Et vous logez où,\n"
	.string "ces jours-ci ? Pure curiosité.$"

CF1_T_058::
	.string "Ferrand note quelque chose, puis\n"
	.string "fredonne un air léger.$"

CF1_T_059::
	.string "Il parle comme un vendeur, ton\n"
	.string "ingénieur.$"

CF1_T_060::
	.string "Ferrand vous regarde partir.$"

CF1_T_061::
	.string "Passerelle vous plaît ? Revenez\n"
	.string "quand vous voulez.$"

CF1_T_062::
	.string "Bienvenue chez Devon ! Voici\n"
	.string "Passerelle : le monde en une seconde.$"

CF1_T_063::
	.string "Sylphe fournit le Cœur, Devon le\n"
	.string "réseau. Une belle alliance.$"

CF1_T_064::
	.string "J’ai écrit la couche de transfert.\n"
	.string "Elle marche. Trop bien, même.$"

CF1_T_065::
	.string "Mes boîtes stockent tout. Et je\n"
	.string "tiens des journaux. De tout.$"

CF1_T_066::
	.string "Mon disque dit que mon nœud est\n"
	.string "propre. Je le prouverai.$"

CF1_T_067::
	.string "J’avais un disque. Un anneau\n"
	.string "l’a pris. Comme par hasard.$"

CF1_T_068::
	.string "Vous ne vous êtes pas reconnu ?\n"
	.string "Sur l’affiche, en bas ?$"

CF1_T_069::
	.string "Red ! Vous avez vu l’affiche ?\n"
	.string "Vous étiez si… vendeur.$"

CF1_T_070::
	.string "Une photo avec moi, près du\n"
	.string "Kiosque ? Pour la presse.$"

CF1_T_071::
	.string "Poser$"

CF1_T_072::
	.string "Flash. Le Président serre la main\n"
	.string "de Red. Longtemps.$"

CF1_T_073::
	.string "Ha. Ha. Une autre fois,\n"
	.string "peut-être.$"

CF1_T_074::
	.string "Un service ? Une lettre pour mon\n"
	.string "fils, Pierre Rochard. Il est à Myokara.$"

CF1_T_075::
	.string "Les traversées reprendront bientôt.\n"
	.string "Enfin, j’espère.$"

CF1_T_076::
	.string "Red ! Mon père a fini, me voilà.\n"
	.string "J’ai raté quoi ?$"

CF1_T_077::
	.string "Un petit cercle d’or s’ouvre près\n"
	.string "de Brice. Une main violette en sort.$"

CF1_T_078::
	.string "Mon carnet ! Rends-moi ça, espèce\n"
	.string "de… de quoi, d’ailleurs ?$"

CF1_T_079::
	.string "Une silhouette violette, à peine\n"
	.string "plus grande qu’un Skitty.$"

CF1_T_080::
	.string "Lancer une baie$"

CF1_T_081::
	.string "Le poursuivre$"

CF1_T_082::
	.string "Ne rien faire$"

CF1_T_083::
	.string "Il attrape la baie au vol, sourit,\n"
	.string "et disparaît. Avec le carnet.$"

CF1_T_084::
	.string "Super. Il a mon carnet ET ta\n"
	.string "baie.$"

CF1_T_085::
	.string "Red court. Quatre pages tombent.\n"
	.string "Le voleur file vers l’est.$"

CF1_T_086::
	.string "Quatre pages… Il est parti vers\n"
	.string "l’est. Je note.$"

CF1_T_087::
	.string "Tu ne fais rien ?! C’était tout\n"
	.string "mon recensement !$"

CF1_T_088::
	.string "Ils mangent le charbon. Les galeries\n"
	.string "s’effondrent. On est tous virés.$"

CF1_T_089::
	.string "Roxanne, championne. Et prof. Il\n"
	.string "me faut des données, pas des cris.$"

CF1_T_090::
	.string "Pierre, d’Argenta. Je suis coincé\n"
	.string "ici depuis que les ports ont fermé.$"

CF1_T_091::
	.string "Je peux les emmener. J’élève des\n"
	.string "Pokémon. Chez moi, c’est pareil.$"

CF1_T_092::
	.string "Les emmener ? Ou on les abat, et\n"
	.string "on rouvre demain !$"

CF1_T_093::
	.string "Red. Tu as vu ces anneaux de près.\n"
	.string "Que fait-on ?$"

CF1_T_094::
	.string "Déplacer avec Pierre$"

CF1_T_095::
	.string "Relevés pour Roxanne$"

CF1_T_096::
	.string "Laisser les mineurs$"

CF1_T_097::
	.string "Merci. Galerie fermée une semaine,\n"
	.string "et ils partent avec moi.$"

CF1_T_098::
	.string "Un protocole : on balise, on rouvre,\n"
	.string "on compte. Je te citerai.$"

CF1_T_099::
	.string "La galerie se vide. Un mineur\n"
	.string "pleure son Charbi apprivoisé.$"

CF1_T_100::
	.string "Je note l’état de la galerie.\n"
	.string "On verra ce qui revient.$"

CF1_T_101::
	.string "Je t’attends à l’arène. Tu as gagné\n"
	.string "le droit d’essayer.$"

CF1_T_102::
	.string "Charbi crépite doucement.$"

CF1_T_103::
	.string "Strassie scintille faiblement.$"

CF1_T_104::
	.string "Un duel entre bloqués ?\n"
	.string "Sans rancune.$"

CF1_T_105::
	.string "Solide. Tu as de la roche dans\n"
	.string "le cœur.$"

CF1_T_106::
	.string "Reviens quand tu veux. Les galeries\n"
	.string "m’attendent.$"

CF1_T_107::
	.string "Joli combat. Une dernière chose :\n"
	.string "tes observations sur les anneaux.$"

CF1_T_108::
	.string "Le Rempart me les demande. Je\n"
	.string "peux les transmettre ?$"

CF1_T_109::
	.string "Donner$"

CF1_T_110::
	.string "Des données, pas des cris. Merci.$"

CF1_T_111::
	.string "Nos chiffres restent à nous.$"

CF1_T_112::
	.string "Je respecte. Le Rempart, moins.$"

CF1_T_113::
	.string "Arène fermée. Roxanne est aux mines,\n"
	.string "par la Route 116.$"

CF1_T_114::
	.string "Nos filets sont posés là-bas.\n"
	.string "Grâce à vos chiffres. Merci.$"

CF1_T_115::
	.string "Chut. Des hommes en noir, près\n"
	.string "des rochers. Ils attendent.$"

CF1_T_116::
	.string "Quatre minutes. Préparez les cages.\n"
	.string "Le cercle sera gros, ce soir.$"

CF1_T_117::
	.string "Et si la brigade débarque ?$"

CF1_T_118::
	.string "Le Rempart paie les arrivants\n"
	.string "abattus. Nous, on les revend.$"

CF1_T_119::
	.string "Les affronter$"

CF1_T_120::
	.string "Observer, caché$"

CF1_T_121::
	.string "Prévenir la brigade$"

CF1_T_122::
	.string "Attends… Le type avec eux. C’est\n"
	.string "Ferrand, l’ingénieur de Devon !$"

CF1_T_123::
	.string "Ferrand s’éloigne en fredonnant.$"

CF1_T_124::
	.string "Hé, le gamin de l’affiche ! Le\n"
	.string "champion de Kanto !$"

CF1_T_125::
	.string "Tu cognes fort, gamin.$"

CF1_T_126::
	.string "Je… je n’aurais pas dû venir.$"

CF1_T_127::
	.string "Le cercle s’ouvre quand même. Il\n"
	.string "prend quelque chose dans le sac.$"

CF1_T_128::
	.string "Tu me coûtes une nuit, champion.\n"
	.string "On se reverra.$"

CF1_T_129::
	.string "Lance regarde sa montre. Une\n"
	.string "minute pile avant le cercle.$"

CF1_T_130::
	.string "Le cercle s’ouvre. Les sbires mettent\n"
	.string "trois arrivants en cage.$"

CF1_T_131::
	.string "Il savait l’heure. À la minute\n"
	.string "près. Comment ?$"

CF1_T_132::
	.string "Brice siffle. La brigade arrive\n"
	.string "en courant, Flora en tête.$"

CF1_T_133::
	.string "Merci, Red. On s’en occupe.$"

CF1_T_134::
	.string "Encore toi. Cette fois, on est\n"
	.string "du même côté.$"

CF1_T_135::
	.string "Un sbire est arrêté. Les arrivants\n"
	.string "saisis partent… vers l’abattage.$"

CF1_T_136::
	.string "{STR_VAR_1} a disparu dans\n"
	.string "l’anneau.$"

CF1_T_137::
	.string "Je suis pas un voleur. J’étais\n"
	.string "mineur, avant les anneaux.$"

CF1_T_138::
	.string "Ils paient 200 P la nuit. Ma fille\n"
	.string "mange, comme ça.$"

CF1_T_139::
	.string "T’as pas souri sur leur photo,\n"
	.string "toi. Je l’ai vu dans le journal.$"

CF1_T_140::
	.string "Et toi, tu poses en photo avec\n"
	.string "ceux qui nous ont virés.$"

CF1_T_141::
	.string "Donner 500 P$"

CF1_T_142::
	.string "…Pour rentrer. D’accord. Je jette\n"
	.string "cette casquette. Merci.$"

CF1_T_143::
	.string "Il remet sa casquette et suit\n"
	.string "les autres dans le noir.$"

CF1_T_144::
	.string "Je reprends lundi. Merci, Red.$"

CF1_T_145::
	.string "Le soir tombe sur Mérouville.$"

CF1_T_146::
	.string "Bulletin : galeries balisées.\n"
	.string "Devon rouvre sous protocole.$"

CF1_T_147::
	.string "Bulletin : galeries fermées. Les\n"
	.string "Skitty reviennent sur la R116.$"

CF1_T_148::
	.string "Bulletin : galeries rouvertes. Plus\n"
	.string "un arrivant. Plus grand-chose.$"

CF1_T_149::
	.string "Ton équipe est quelque part.\n"
	.string "On la retrouvera.$"

CF1_T_150::
	.string "Pikachu guérit chez Papa. Il\n"
	.string "t’attend.$"

CF1_T_151::
	.string "M. Marco attend toujours Piko.\n"
	.string "Garde bien sa clochette.$"

CF1_T_152::
	.string "Les trois de Galar dorment au Bois.\n"
	.string "Grâce à toi.$"

CF1_T_153::
	.string "Ton mineur est rentré. Il t’a\n"
	.string "salué, tu l’as vu ?$"

CF1_T_154::
	.string "Contre la vitre, une ombre violette.\n"
	.string "Elle observe, puis s’en va.$"

CF1_T_155::
	.string "Contre la vitre, une ombre violette.\n"
	.string "Elle pose une baie, et des pages.$"

CF1_T_156::
	.string "Il rend mes pages ! Drôle de\n"
	.string "voleur.$"

CF1_T_157::
	.string "Contre la vitre, une ombre violette.\n"
	.string "Une Poké Ball disparaît du sac.$"

CF1_T_158::
	.string "Des gens arrivent, d’autres partent.\n"
	.string "Et personne ne demande pourquoi.$"

CF1_T_159::
	.string "Les traversées reprennent bientôt,\n"
	.string "paraît-il. Moi, j’y crois moyen.$"

CF1_T_160::
	.string "Fin de la démo de Pokémon\n"
	.string "Confluence. Merci d’avoir joué !$"

CF1_T_161::
	.string "La suite arrive bientôt. Votre\n"
	.string "partie va être sauvegardée.$"

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
	setspeaker CF_N1_Brice
	msgbox \text, MSGBOX_DEFAULT
1:
	.endm

@ Movement on Brice (NPC follower) if present
	.macro cf_bmove mvt:req
	checkfollowernpc
	goto_if_eq VAR_RESULT, FALSE, 1f
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, \mvt
	waitmovement 0
1:
	.endm

@ Spoken line with namebox (string label CF_N1_*)
	.macro cf_say name:req, text:req
	setspeaker \name
	msgbox \text, MSGBOX_DEFAULT
	.endm

@ Narration line (clears the namebox)
	.macro cf_narr text:req
	setspeaker SP_NAME_NONE
	msgbox \text, MSGBOX_DEFAULT
	.endm

@ Talk-to NPC line with namebox
	.macro cf_npc name:req, text:req
	lock
	faceplayer
	setspeaker \name
	msgbox \text, MSGBOX_DEFAULT
	release
	end
	.endm

@ Object emote: ! (with SE_PIN) or ?
	.macro cf_excl id:req
	playse SE_PIN
	applymovement \id, Common_Movement_ExclamationMark
	waitmovement 0
	.endm

@ ! emote on Brice (if present)
	.macro cf_bexcl
	checkfollowernpc
	goto_if_eq VAR_RESULT, FALSE, 1f
	playse SE_PIN
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_ExclamationMark
	waitmovement 0
1:
	.endm

	.macro cf_quest id:req
	applymovement \id, Common_Movement_QuestionMark
	waitmovement 0
	.endm

	.macro cf_move id:req, mvt:req
	applymovement \id, \mvt
	waitmovement 0
	.endm

@ Camera shake (vertical, horizontal, count, delay)
	.macro cf_shake v=0, h=4, n=8, d=4
	setvar VAR_0x8004, \v
	setvar VAR_0x8005, \h
	setvar VAR_0x8006, \n
	setvar VAR_0x8007, \d
	special ShakeCamera
	waitstate
	.endm

@ Red turns toward an object (dominant axis; vertical on ties). Clobbers VAR_0x8000-0x8006.
	.macro cf_face id:req
	setvar VAR_0x8000, \id
	call CF_FaceObj
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

@ VAR_0x8000 = localId. 0x8001/0x8002 = |dx|/|dy|, 0x8005/0x8006 = horizontal/vertical side.
CF_FaceObj::
	getobjectxy VAR_0x8000, CURRENT_POSITION, VAR_0x8001, VAR_0x8002
	getplayerxy VAR_0x8003, VAR_0x8004
	setvar VAR_0x8005, DIR_EAST
	goto_if_ge VAR_0x8001, VAR_0x8003, CF_FaceObj_DX
	setvar VAR_0x8005, DIR_WEST
	copyvar VAR_0x8006, VAR_0x8003
	subvar VAR_0x8006, VAR_0x8001
	copyvar VAR_0x8001, VAR_0x8006
	goto CF_FaceObj_Y
CF_FaceObj_DX:
	subvar VAR_0x8001, VAR_0x8003
CF_FaceObj_Y:
	setvar VAR_0x8006, DIR_SOUTH
	goto_if_ge VAR_0x8002, VAR_0x8004, CF_FaceObj_DY
	setvar VAR_0x8006, DIR_NORTH
	copyvar VAR_0x8003, VAR_0x8004
	subvar VAR_0x8003, VAR_0x8002
	copyvar VAR_0x8002, VAR_0x8003
	goto CF_FaceObj_Pick
CF_FaceObj_DY:
	subvar VAR_0x8002, VAR_0x8004
CF_FaceObj_Pick:
	goto_if_lt VAR_0x8002, VAR_0x8001, CF_FaceObj_H
	goto_if_eq VAR_0x8006, DIR_NORTH, CF_FaceObj_N
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	return
CF_FaceObj_N:
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	return
CF_FaceObj_H:
	goto_if_eq VAR_0x8005, DIR_WEST, CF_FaceObj_W
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	return
CF_FaceObj_W:
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
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

CF1_M_Jump:
	jump_in_place_down
	step_end

CF1_M_Down2:
	walk_down
	walk_down
	step_end

CF1_M_Up1Down:
	walk_up
	face_down
	step_end

CF1_M_Shiver:
	walk_in_place_faster_left
	walk_in_place_faster_right
	walk_in_place_faster_left
	walk_in_place_faster_right
	step_end

@ ---------------------------------------------------------------- speaker names (chapter 1)

CF_N1_Norman:
	.string "NORMAN$"
CF_N1_Flora:
	.string "FLORA$"
CF_N1_Brice:
	.string "BRICE$"
CF_N1_Celeo:
	.string "CÉLÉO$"
CF_N1_Agent:
	.string "AGENT$"
CF_N1_Ferrand:
	.string "FERRAND$"
CF_N1_President:
	.string "PRÉSIDENT$"
CF_N1_Leo:
	.string "LÉO$"
CF_N1_Lanette:
	.string "LANETTE$"
CF_N1_Rochard:
	.string "ROCHARD$"
CF_N1_Roxanne:
	.string "ROXANNE$"
CF_N1_Pierre:
	.string "PIERRE$"
CF_N1_Mineur:
	.string "MINEUR$"
CF_N1_Lance:
	.string "LANCE$"
CF_N1_Sbire:
	.string "SBIRE$"
CF_N1_Passante:
	.string "PASSANTE$"
CF_N1_Coach:
	.string "COACH$"
CF_N1_Habitant:
	.string "HABITANT$"
	.align 2

@ ---------------------------------------------------------------- walls (s7)

CF_Wall_QG::
	cf_npc CF_N1_Agent, CF1_T_000

CF_Wall_R116::
	cf_npc CF_N1_Agent, CF1_T_001

CF_Wall_R115_Talk::
	cf_npc CF_N1_Agent, CF1_T_002

CF_Wall_R115::
	lockall
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	cf_say CF_N1_Agent, CF1_T_002
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CF_Mov_Down1
	waitmovement 0
	releaseall
	end

CF_Cutter::
	cf_npc CF_N1_Habitant, CF1_T_003

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
	cf_excl LOCALID_PETALBURG_GYM_NORMAN
	cf_move LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkDown
	cf_face LOCALID_PETALBURG_GYM_NORMAN
	cf_say CF_N1_Norman, CF1_T_004
	cf_if_dec 2, DEC_A, CF_C1_NormanA
	cf_say CF_N1_Norman, CF1_T_005
	goto CF_C1_AfterNorman

CF_C1_NormanA::
	cf_say CF_N1_Norman, CF1_T_006
CF_C1_AfterNorman::
	cf_if_dec 6, DEC_A, CF_C1_Celeo
CF_C1_Flora::
	closemessage
	cf_move LOCALID_CF_GYM_FLORA, Common_Movement_WalkDown
	cf_face LOCALID_CF_GYM_FLORA
	cf_say CF_N1_Flora, CF1_T_007
	cf_if_dec 7, DEC_A, CF_C1_FloraA
	cf_say CF_N1_Flora, CF1_T_008
	goto CF_C1_Offer

CF_C1_FloraA::
	cf_say CF_N1_Flora, CF1_T_009
	goto CF_C1_Offer

CF_C1_Celeo::
	closemessage
	turnobject LOCALID_CF_GYM_BRIGADIER, DIR_WEST
	cf_say CF_N1_Agent, CF1_T_010
	closemessage
	playse SE_PIN
	applymovement LOCALID_CF_GYM_CELEO, Common_Movement_ExclamationMark
	waitmovement 0
	cf_move LOCALID_CF_GYM_CELEO, CF1_M_Jump
	cf_move LOCALID_CF_GYM_CELEO, Common_Movement_WalkDown
	cf_face LOCALID_CF_GYM_CELEO
	cf_say CF_N1_Celeo, CF1_T_011
	closemessage
	turnobject LOCALID_PETALBURG_GYM_NORMAN, DIR_EAST
	cf_say CF_N1_Norman, CF1_T_012
	closemessage
	turnobject LOCALID_PETALBURG_GYM_NORMAN, DIR_SOUTH
	turnobject LOCALID_CF_GYM_BRIGADIER, DIR_SOUTH
	cf_face LOCALID_CF_GYM_CELEO
	cf_if_dec 1, DEC_A, CF_C1_CeleoA
	cf_say CF_N1_Celeo, CF1_T_013
	goto CF_C1_Flora

CF_C1_CeleoA::
	cf_say CF_N1_Celeo, CF1_T_014
	goto CF_C1_Flora

CF_C1_Offer::
	turnobject LOCALID_CF_GYM_FLORA, DIR_EAST
	cf_face LOCALID_PETALBURG_GYM_NORMAN
	cf_say CF_N1_Norman, CF1_T_015
	closemessage
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceDown
	waitmovement 0
	setspeaker SP_NAME_NONE
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
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	cf_say CF_N1_Norman, CF1_T_019
	setdecision_once 17, DEC_A, CF_C1_Common
	setflag FLAG_CF_INSIGNE
	addaffinity VAR_CF_REP_L, 3
	subaffinity VAR_CF_REP_A, 3
	goto CF_C1_Common

CF_C1_Refuse::
	applymovement LOCALID_CF_GYM_FLORA, Common_Movement_QuestionMark
	waitmovement 0
	cf_say CF_N1_Norman, CF1_T_020
	setdecision_once 17, DEC_B, CF_C1_Common
	subaffinity VAR_CF_REP_L, 2
	addaffinity VAR_CF_REP_A, 1
	goto CF_C1_Common

CF_C1_Common::
	cf_say CF_N1_Norman, CF1_T_021
	closemessage
	turnobject LOCALID_CF_GYM_FLORA, DIR_SOUTH
	@ Red standing right below Flora (3,109): she walks around him
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 3, CF_C1_FloraAround
	applymovement LOCALID_CF_GYM_FLORA, CF1_M_C1_FloraLeave
	goto CF_C1_FloraGone
CF_C1_FloraAround:
	applymovement LOCALID_CF_GYM_FLORA, CF1_M_C1_FloraLeaveL
CF_C1_FloraGone:
	applymovement LOCALID_PETALBURG_GYM_NORMAN, CF1_M_Up1Down
	waitmovement LOCALID_CF_GYM_FLORA
	playse SE_EXIT
	setvar VAR_STEVENS_HOUSE_STATE, 1
	setflag FLAG_CF_VIS_18
	removeobject LOCALID_CF_GYM_FLORA
	waitmovement LOCALID_PETALBURG_GYM_NORMAN
	releaseall
	end

CF1_M_C1_FloraLeave:
	walk_down
	walk_down
	walk_right
	walk_down
	step_end

CF1_M_C1_FloraLeaveL:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_right
	walk_down
	step_end

CF_C1_NormanTalk::
	cf_npc CF_N1_Norman, CF1_T_021

CF_C1_FloraTalk::
	cf_npc CF_N1_Flora, CF1_T_007

CF_C1_CeleoTalk::
	lock
	faceplayer
	setspeaker CF_N1_Celeo
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
	setspeaker CF_N1_Coach
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
	cf_npc CF_N1_Agent, CF1_T_024

@ VAR_0x8008 = guard in front of Red, VAR_0x8009 = his partner
CF_C2_Barrage::
	goto_if_set FLAG_CF_VIS_10, CF_Nop
	lockall
	getplayerxy VAR_0x8004, VAR_0x8005
	call CF_C2_PickGuards
	cf_excl VAR_0x8008
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	cf_say CF_N1_Agent, CF1_T_024
	goto_if_set FLAG_CF_INSIGNE, CF_C2_Insigne
	getbits VAR_CF_WORLD, 0, 2
	goto_if_ge VAR_RESULT, 1, CF_C2_Registered
	checkfollowernpc
	goto_if_eq VAR_RESULT, FALSE, CF_C2_Fallback
	goto_if_lt VAR_CF_BR, 50, CF_C2_Fallback
	closemessage
	cf_bmove Common_Movement_ExclamationMark
	cf_say CF_N1_Brice, CF1_T_025
	closemessage
	applymovement VAR_0x8009, Common_Movement_QuestionMark
	waitmovement 0
	cf_say CF_N1_Agent, CF1_T_026
	goto CF_C2_Pass

CF_C2_Insigne::
	closemessage
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceDown
	waitmovement 0
	cf_say CF_N1_Agent, CF1_T_027
	goto CF_C2_Pass

CF_C2_Registered::
	cf_say CF_N1_Agent, CF1_T_028
	goto CF_C2_Pass

CF_C2_Fallback::
	cf_say CF_N1_Agent, CF1_T_029
	closemessage
	call CF_C2_PartnerFaces
	cf_say CF_N1_Agent, CF1_T_030
	goto CF_C2_Pass

CF_C2_Pass::
	closemessage
	turnobject VAR_0x8008, DIR_SOUTH
	turnobject VAR_0x8009, DIR_SOUTH
	call CF_C2_StepAside
	setflag FLAG_CF_VIS_10
	goto_if_ge VAR_0x8004, 32, CF_C2_PassB
	removeobject LOCALID_CF_R104_BAR_B1
	removeobject LOCALID_CF_R104_BAR_B2
	releaseall
	end

CF_C2_PassB::
	removeobject LOCALID_CF_R104_BAR_A1
	removeobject LOCALID_CF_R104_BAR_A2
	releaseall
	end

CF_C2_PickGuards::
	goto_if_ge VAR_0x8004, 32, CF_C2_PickB
	setvar VAR_0x8008, LOCALID_CF_R104_BAR_A1
	setvar VAR_0x8009, LOCALID_CF_R104_BAR_A2
	goto_if_eq VAR_0x8004, 10, CF_C2_PickRet
	setvar VAR_0x8008, LOCALID_CF_R104_BAR_A2
	setvar VAR_0x8009, LOCALID_CF_R104_BAR_A1
	return

CF_C2_PickB::
	setvar VAR_0x8008, LOCALID_CF_R104_BAR_B1
	setvar VAR_0x8009, LOCALID_CF_R104_BAR_B2
	goto_if_eq VAR_0x8004, 32, CF_C2_PickRet
	setvar VAR_0x8008, LOCALID_CF_R104_BAR_B2
	setvar VAR_0x8009, LOCALID_CF_R104_BAR_B1
CF_C2_PickRet::
	return

@ Partner turns toward the guard in front of Red (left one = A1/B1)
CF_C2_PartnerFaces::
	goto_if_eq VAR_0x8009, LOCALID_CF_R104_BAR_A1, CF_C2_PartnerFacesE
	goto_if_eq VAR_0x8009, LOCALID_CF_R104_BAR_B1, CF_C2_PartnerFacesE
	turnobject VAR_0x8009, DIR_WEST
	turnobject VAR_0x8008, DIR_EAST
	return

CF_C2_PartnerFacesE::
	turnobject VAR_0x8009, DIR_EAST
	turnobject VAR_0x8008, DIR_WEST
	return

@ Left guard steps left, right guard steps right: the road opens
@ Rows beside the guards are walls: the guard in Red's column steps back (north) to open the way.
CF_C2_StepAside::
	applymovement VAR_0x8008, CF1_M_C2_StepBack
	waitmovement 0
	return

CF1_M_C2_StepBack:
	walk_up
	face_down
	step_end

@ ---------------------------------------------------------------- C3: Flora au Bois (D008)

CF_C3_Scene::
	lockall
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 27, CF_C3_FromRight
	cf_move OBJ_EVENT_ID_PLAYER, CF_Mov_Up2
	goto CF_C3_InPlace
CF_C3_FromRight::
	cf_move OBJ_EVENT_ID_PLAYER, CF1_M_C3_PlayerL
CF_C3_InPlace::
	playmoncry SPECIES_WOOLOO, CRY_MODE_ENCOUNTER
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, CF1_M_Shiver
	applymovement LOCALID_CF_WOODS_YAMPER, CF1_M_Shiver
	applymovement LOCALID_CF_WOODS_APPLIN, CF1_M_Shiver
	waitmovement 0
	waitmoncry
	cf_say CF_N1_Flora, CF1_T_031
	closemessage
	turnobject LOCALID_CF_WOODS_POLICE_L, DIR_EAST
	turnobject LOCALID_CF_WOODS_POLICE_R, DIR_WEST
	cf_say CF_N1_Flora, CF1_T_032
	closemessage
	turnobject LOCALID_CF_WOODS_POLICE_L, DIR_SOUTH
	turnobject LOCALID_CF_WOODS_POLICE_R, DIR_SOUTH
	cf_bmove Common_Movement_ExclamationMark
	cf_bsay CF1_T_033
	closemessage
	@ Wooloo scurries aside, the three turn toward Red
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, CF1_M_C3_WoolooAside
	applymovement LOCALID_CF_WOODS_YAMPER, CF1_M_Jump
	applymovement LOCALID_CF_WOODS_APPLIN, CF1_M_Jump
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	cf_narr CF1_T_034
	closemessage
	@ Flora comes down to Red
	cf_excl LOCALID_PETALBURG_WOODS_GRUNT
	cf_move LOCALID_PETALBURG_WOODS_GRUNT, CF1_M_C3_FloraIn
	setflag FLAG_CF_NO_WHITEOUT
	trainerbattle_scene_declinable TRAINER_BROOKE_4, CF1_T_035, CF1_T_036, FLAG_CF_REFUS_FLORA1, CF_D008_Refus
	goto_if_set TRAINER_FLAGS_START + TRAINER_BROOKE_4, CF_D008_Won
	goto CF_D008_Lost

CF_D008_Won::
	clearflag FLAG_CF_NO_WHITEOUT
	special HealPlayerParty
	@ The three arrivals flee into the woods
	playmoncry SPECIES_YAMPER, CRY_MODE_NORMAL
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, CF1_M_FleeLeft
	applymovement LOCALID_CF_WOODS_APPLIN, CF1_M_FleeLeft
	applymovement LOCALID_CF_WOODS_YAMPER, CF1_M_C3_YamperFlee
	waitmovement 0
	waitmoncry
	removeobject LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE
	removeobject LOCALID_CF_WOODS_APPLIN
	removeobject LOCALID_CF_WOODS_YAMPER
	turnobject LOCALID_PETALBURG_WOODS_GRUNT, DIR_EAST
	cf_say CF_N1_Flora, CF1_T_037
	closemessage
	turnobject LOCALID_PETALBURG_WOODS_GRUNT, DIR_SOUTH
	cf_say CF_N1_Agent, CF1_T_038
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
	cf_say CF_N1_Flora, CF1_T_039
	setdecision_once 8, DEC_B, CF_C3_End
	addaffinity VAR_CF_FL, 2
	addaffinity VAR_CF_REP_L, 1
	cf_lose_money 300
	playse SE_SHOP
	call CF_C3_Taken
	goto CF_C3_End

CF_D008_Refus::
	clearflag FLAG_CF_NO_WHITEOUT
	cf_narr CF1_T_040
	cf_say CF_N1_Flora, CF1_T_041
	setdecision_once 8, DEC_C, CF_C3_End
	addaffinity VAR_CF_FL, 3
	subaffinity VAR_CF_BR, 2
	call CF_C3_Taken
	goto CF_C3_End

@ The brigade closes in on the three arrivals (off-screen outcome)
CF_C3_Taken::
	closemessage
	applymovement LOCALID_CF_WOODS_POLICE_L, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_CF_WOODS_POLICE_R, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playmoncry SPECIES_WOOLOO, CRY_MODE_WEAK
	waitmoncry
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE
	removeobject LOCALID_CF_WOODS_YAMPER
	removeobject LOCALID_CF_WOODS_APPLIN
	fadescreen FADE_FROM_BLACK
	return

CF_C3_End::
	closemessage
	@ Flora and her patrol leave west along the open row 16 (rows 12-15 are trees)
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, CF1_M_C3_FloraOut
	applymovement LOCALID_CF_WOODS_POLICE_L, CF1_M_C3_PoliceLOut
	applymovement LOCALID_CF_WOODS_POLICE_R, CF1_M_C3_PoliceROut
	waitmovement 0
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

CF1_M_C3_PlayerL:
	walk_up
	walk_up
	walk_left
	face_up
	step_end

CF1_M_C3_WoolooAside:
	jump_in_place_down
	walk_up
	walk_right
	face_down
	step_end

CF1_M_C3_YamperFlee:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

CF1_M_C3_FloraOut:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

CF1_M_C3_PoliceLOut:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

CF1_M_C3_PoliceROut:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

CF1_M_C3_FloraIn:
	walk_down
	walk_down
	walk_down
	step_end

CF1_M_FleeLeft:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

CF1_M_FleeRight:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

CF_C3_SavedWooloo::
	lock
	faceplayer
	playmoncry SPECIES_WOOLOO, CRY_MODE_NORMAL
	msgbox CF1_T_042, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CF_C3_SavedYamper::
	lock
	faceplayer
	playmoncry SPECIES_YAMPER, CRY_MODE_NORMAL
	msgbox CF1_T_043, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CF_C3_SavedApplin::
	lock
	faceplayer
	playmoncry SPECIES_APPLIN, CRY_MODE_NORMAL
	msgbox CF1_T_044, MSGBOX_DEFAULT
	waitmoncry
	release
	end

@ ---------------------------------------------------------------- C4: l'affiche (D009)

CF_C4_PosterRead::
	msgbox CF1_T_045, MSGBOX_SIGN
	end

CF_C4_Poster::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	cf_narr CF1_T_045
	cf_narr CF1_T_046
	checkfollowernpc
	goto_if_eq VAR_RESULT, FALSE, CF_C4_NoBrice
	cf_bexcl
	cf_bsay CF1_T_047
	goto CF_C4_Menu

CF_C4_NoBrice::
	closemessage
	setobjectxyperm LOCALID_CF_RUST_PASSANTE, 24, 52
	clearflag FLAG_CF_VIS_24
	addobject LOCALID_CF_RUST_PASSANTE
	applymovement LOCALID_CF_RUST_PASSANTE, CF1_M_C4_PassanteIn
	waitmovement 0
	setobjectxyperm LOCALID_CF_RUST_PASSANTE, 17, 52
	cf_excl LOCALID_CF_RUST_PASSANTE
	cf_face LOCALID_CF_RUST_PASSANTE
	cf_say CF_N1_Passante, CF1_T_048
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
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	cf_narr CF1_T_051
	closemessage
	playse SE_RG_BALL_CLICK
	fadescreenspeed FADE_TO_WHITE, 0
	fadescreenspeed FADE_FROM_WHITE, 0
	waitse
	cf_bsay CF1_T_052
	setdecision_once 9, DEC_A, CF_C4_End
	setflag FLAG_CF_DOS_AFFICHE_SYLPHE
	addaffinity VAR_CF_BR, 2
	addaffinity VAR_CF_RK, 2
	call CF_IncN
	goto CF_C4_End

CF_C4_Leave::
	checkfollowernpc
	goto_if_eq VAR_RESULT, FALSE, CF_C4_LeaveP
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	setspeaker CF_N1_Brice
	goto CF_C4_LeaveSay
CF_C4_LeaveP:
	cf_face LOCALID_CF_RUST_PASSANTE
	setspeaker CF_N1_Passante
CF_C4_LeaveSay:
	msgbox CF1_T_053, MSGBOX_DEFAULT
	setdecision_once 9, DEC_B, CF_C4_End
	subaffinity VAR_CF_BR, 1
	goto CF_C4_End

CF_C4_End::
	closemessage
	setvar VAR_RUSTBORO_CITY_STATE, 10
	goto_if_set FLAG_CF_VIS_24, CF_C4_End2
	applymovement LOCALID_CF_RUST_PASSANTE, CF1_M_C4_PassanteOut
	waitmovement 0
CF_C4_End2:
	setflag FLAG_CF_VIS_24
	removeobject LOCALID_CF_RUST_PASSANTE
	releaseall
	end

CF1_M_C4_PassanteIn:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end

CF1_M_C4_PassanteOut:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

@ ---------------------------------------------------------------- C5: "Ferrand" (D013)

CF_C5_Ferrand::
	lock
	faceplayer
	checkdecision 13
	goto_if_ne VAR_RESULT, DEC_NONE, CF_C5_Again
	cf_excl VAR_LAST_TALKED
	cf_say CF_N1_Ferrand, CF1_T_054
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
	cf_say CF_N1_Ferrand, CF1_T_057
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceUp
	waitmovement 0
	cf_narr CF1_T_058
	cf_bexcl
	cf_bsay CF1_T_059
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	setdecision_once 13, DEC_A, CF_C5_End
	setflag FLAG_CF_LAMBDA_REMARQUE
	addaffinity VAR_CF_RK, 3
	goto CF_C5_End

CF_C5_Go::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	cf_narr CF1_T_060
	setdecision_once 13, DEC_B, CF_C5_End
	subaffinity VAR_CF_BR, 1
	goto CF_C5_End

CF_C5_Again::
	cf_say CF_N1_Ferrand, CF1_T_061
CF_C5_End::
	release
	end

@ ---------------------------------------------------------------- C6: Passerelle (D011)

CF_C6_Show::
	clearflag FLAG_CF_VIS_26
	clearflag FLAG_CF_VIS_27
	clearflag FLAG_CF_VIS_04
	return

@ Red arrives by the stairs (2,2) and walks to the President (15,5)
CF_C6_Scene::
	lockall
	cf_excl LOCALID_CF_DEVON_PRESIDENT
	cf_say CF_N1_President, CF1_T_062
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CF1_M_C6_PlayerIn
	waitmovement 0
	cf_say CF_N1_President, CF1_T_063
	closemessage
	applymovement LOCALID_CF_DEVON_LEO, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	cf_say CF_N1_Leo, CF1_T_064
	closemessage
	applymovement LOCALID_CF_DEVON_LANETTE, Common_Movement_FaceRight
	waitmovement 0
	cf_say CF_N1_Lanette, CF1_T_065
	closemessage
	applymovement LOCALID_CF_DEVON_CELEO, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	setspeaker CF_N1_Celeo
	cf_if_dec 1, DEC_A, CF_C6_CeleoA
	msgbox CF1_T_066, MSGBOX_DEFAULT
	goto CF_C6_President

CF_C6_CeleoA::
	msgbox CF1_T_067, MSGBOX_DEFAULT
CF_C6_President::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	setspeaker CF_N1_President
	cf_if_dec 9, DEC_A, CF_C6_PresidentA
	msgbox CF1_T_068, MSGBOX_DEFAULT
	goto CF_C6_Photo

CF_C6_PresidentA::
	msgbox CF1_T_069, MSGBOX_DEFAULT
CF_C6_Photo::
	applymovement LOCALID_CF_DEVON_PRESIDENT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
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
	playse SE_RG_BALL_CLICK
	fadescreenspeed FADE_TO_WHITE, 0
	fadescreenspeed FADE_FROM_WHITE, 0
	waitse
	cf_narr CF1_T_072
	setdecision_once 11, DEC_A, CF_C6_Common
	addaffinity VAR_CF_REP_C, 5
	subaffinity VAR_CF_REP_P, 3
	call CF_IncN
	goto CF_C6_Common

CF_C6_Decline::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	cf_say CF_N1_President, CF1_T_073
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	setdecision_once 11, DEC_B, CF_C6_Common
	subaffinity VAR_CF_REP_C, 3
	addaffinity VAR_CF_REP_P, 2
	goto CF_C6_Common

CF_C6_Common::
	cf_say CF_N1_President, CF1_T_074
	setspeaker SP_NAME_NONE
	giveitem ITEM_LETTER
	applymovement LOCALID_CF_DEVON_ROCHARD, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	cf_say CF_N1_Rochard, CF1_T_075
	cf_if_dec 5, DEC_B, CF_C6_BriceEnters
CF_C6_Done::
	closemessage
	setvar VAR_DEVON_CORP_3F_STATE, 1
	releaseall
	end

@ Brice comes up the stairs (object hidden by an always-set flag) and joins
CF_C6_BriceEnters::
	checkfollowernpc
	goto_if_eq VAR_RESULT, TRUE, CF_C6_Done
	closemessage
	playse SE_EXIT
	addobject LOCALID_CF_DEVON_BRICE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_CF_DEVON_BRICE, CF1_M_C6_BriceIn
	waitmovement 0
	cf_say CF_N1_Brice, CF1_T_076
	closemessage
	removeobject LOCALID_CF_DEVON_BRICE
	createfollowernpc OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL, FNPC_ALL_LAND
	goto CF_C6_Done

CF1_M_C6_PlayerIn:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	face_right
	step_end

CF1_M_C6_BriceIn:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	face_right
	step_end

CF_C6_RochardTalk::
	cf_npc CF_N1_Rochard, CF1_T_075

CF_C6_PresidentTalk::
	cf_npc CF_N1_President, CF1_T_063

CF_C6_LeoTalk::
	cf_npc CF_N1_Leo, CF1_T_064

CF_C6_LanetteTalk::
	cf_npc CF_N1_Lanette, CF1_T_065

CF_C6_CeleoTalk::
	lock
	faceplayer
	setspeaker CF_N1_Celeo
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
	playse SE_M_TELEPORT
	clearflag FLAG_CF_VIS_84
	addobject LOCALID_CF_RUST_PORTAL
	clearflag FLAG_CF_VIS_28
	addobject LOCALID_CF_RUST_HOOPA
	waitse
	playmoncry SPECIES_HOOPA, CRY_MODE_NORMAL
	cf_narr CF1_T_077
	waitmoncry
	closemessage
	setflag FLAG_CF_VIS_84
	removeobject LOCALID_CF_RUST_PORTAL
	cf_bexcl
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_CF_RUST_HOOPA, CF1_M_Jump
	waitmovement 0
	cf_bsay CF1_T_078
	setspeaker SP_NAME_NONE
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
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_CF_RUST_HOOPA, CF1_M_Jump
	waitmovement 0
	cf_narr CF1_T_083
	closemessage
	call CF_C7_Vanish
	cf_bsay CF1_T_084
	setdecision_once 12, DEC_A, CF_C7_End
	addaffinity VAR_CF_HO, 5
	subaffinity VAR_CF_BR, 2
	goto CF_C7_End

CF_C7_Chase::
	applymovement LOCALID_CF_RUST_HOOPA, CF1_M_C7_HoopaFlee
	applymovement OBJ_EVENT_ID_PLAYER, CF1_M_C7_Run
	waitmovement LOCALID_CF_RUST_HOOPA
	waitmovement OBJ_EVENT_ID_PLAYER
	removeobject LOCALID_CF_RUST_HOOPA
	cf_narr CF1_T_085
	cf_bsay CF1_T_086
	setdecision_once 12, DEC_B, CF_C7_End
	subaffinity VAR_CF_HO, 3
	addaffinity VAR_CF_BR, 2
	setvar VAR_0x8004, 8
	call CF_IncBV
	goto CF_C7_End

CF_C7_Nothing::
	call CF_C7_Vanish
	cf_bsay CF1_T_087
	setdecision_once 12, DEC_C, CF_C7_End
	addaffinity VAR_CF_HO, 1
	subaffinity VAR_CF_BR, 1
	goto CF_C7_End

CF_C7_Vanish:
	playse SE_M_TELEPORT
	removeobject LOCALID_CF_RUST_HOOPA
	waitse
	return

CF_C7_End::
	closemessage
	setvar VAR_RUSTBORO_CITY_STATE, 11
	setflag FLAG_CF_VIS_28
	removeobject LOCALID_CF_RUST_HOOPA
	releaseall
	end

@ (14,18) -> around the wall at x15/16 -> east along row 21
CF1_M_C7_HoopaFlee:
	walk_fast_down
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

CF1_M_C7_Run:
	walk_fast_right
	walk_fast_right
	walk_in_place_faster_right
	step_end

@ ---------------------------------------------------------------- C8: les mines (D010)

@ White flash (ring / photo)
	.macro cf_flash
	fadescreenspeed FADE_TO_WHITE, 0
	fadescreenspeed FADE_FROM_WHITE, 0
	.endm

CF_C8_Scene::
	lockall
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_ne VAR_0x8005, 5, CF_C8_Start
	cf_move OBJ_EVENT_ID_PLAYER, CF1_M_Up1
CF_C8_Start::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	playse SE_M_ROCK_THROW
	cf_shake 2, 0, 6, 3
	waitse
	cf_excl LOCALID_CF_TUN_MINER_1
	turnobject LOCALID_CF_TUN_MINER_1, DIR_WEST
	cf_say CF_N1_Mineur, CF1_T_088
	closemessage
	cf_move LOCALID_CF_TUN_ROXANNE, Common_Movement_WalkInPlaceFasterLeft
	cf_say CF_N1_Roxanne, CF1_T_089
	closemessage
	cf_move LOCALID_CF_TUN_PIERRE, CF1_M_C8_PierreIn
	cf_say CF_N1_Pierre, CF1_T_090
	closemessage
	turnobject LOCALID_CF_TUN_PIERRE, DIR_EAST
	playmoncry SPECIES_ROLYCOLY, CRY_MODE_NORMAL
	cf_move LOCALID_CF_TUN_CHARBI, CF1_M_Jump
	waitmoncry
	playmoncry SPECIES_CARBINK, CRY_MODE_NORMAL
	cf_move LOCALID_CF_TUN_STRASSIE, CF1_M_Jump
	waitmoncry
	turnobject LOCALID_CF_TUN_PIERRE, DIR_WEST
	cf_say CF_N1_Pierre, CF1_T_091
	closemessage
	cf_excl LOCALID_CF_TUN_MINER_2
	turnobject LOCALID_CF_TUN_MINER_2, DIR_EAST
	cf_say CF_N1_Mineur, CF1_T_092
	closemessage
	turnobject LOCALID_CF_TUN_MINER_2, DIR_WEST
	cf_move LOCALID_CF_TUN_ROXANNE, Common_Movement_WalkInPlaceFasterLeft
	setspeaker CF_N1_Roxanne
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
	cf_say CF_N1_Pierre, CF1_T_097
	closemessage
	turnobject LOCALID_CF_TUN_PIERRE, DIR_EAST
	playmoncry SPECIES_ROLYCOLY, CRY_MODE_NORMAL
	applymovement LOCALID_CF_TUN_CHARBI, CF1_M_FleeRight
	applymovement LOCALID_CF_TUN_STRASSIE, CF1_M_FleeRight
	waitmovement LOCALID_CF_TUN_CHARBI
	waitmovement LOCALID_CF_TUN_STRASSIE
	waitmoncry
	turnobject LOCALID_CF_TUN_PIERRE, DIR_WEST
	setdecision_once 10, DEC_A, CF_C8_Hide
	setbits VAR_CF_ECO, 2, 2, ECO_RESTAURE
	addaffinity VAR_CF_REP_I, 3
	subaffinity VAR_CF_REP_P, 3
	setflag FLAG_CF_BROCK_PROTEGES
	goto CF_C8_Hide

CF_C8_Data::
	playse SE_RG_CARD_FLIP
	cf_move LOCALID_CF_TUN_ROXANNE, Common_Movement_WalkInPlaceFasterLeft
	waitse
	cf_say CF_N1_Roxanne, CF1_T_098
	setdecision_once 10, DEC_B, CF_C8_End
	setbits VAR_CF_ECO, 2, 2, ECO_MIXTE
	addaffinity VAR_CF_REP_C, 3
	addaffinity VAR_CF_REP_P, 2
	subaffinity VAR_CF_REP_A, 2
	goto CF_C8_End

CF_C8_Leave::
	playmoncry SPECIES_ROLYCOLY, CRY_MODE_WEAK
	cf_move LOCALID_CF_TUN_CHARBI, CF1_M_Shiver
	waitmoncry
	applymovement LOCALID_CF_TUN_CHARBI, CF1_M_FleeRight
	applymovement LOCALID_CF_TUN_STRASSIE, CF1_M_FleeRight
	waitmovement LOCALID_CF_TUN_CHARBI
	waitmovement LOCALID_CF_TUN_STRASSIE
	turnobject LOCALID_CF_TUN_MINER_2, DIR_SOUTH
	cf_narr CF1_T_099
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
	turnobject LOCALID_CF_TUN_ROXANNE, DIR_WEST
	cf_say CF_N1_Roxanne, CF1_T_101
	closemessage
	applymovement LOCALID_CF_TUN_ROXANNE, CF1_M_C8_RoxOut
	applymovement OBJ_EVENT_ID_PLAYER, CF1_M_C8_PlayerWatch
	waitmovement LOCALID_CF_TUN_ROXANNE
	waitmovement OBJ_EVENT_ID_PLAYER
	setvar VAR_RUSTURF_TUNNEL_STATE, 1
	setflag FLAG_CF_VIS_31
	removeobject LOCALID_CF_TUN_ROXANNE
	releaseall
	end

CF1_M_Up1:
	walk_up
	step_end

CF1_M_C8_PierreIn:
	walk_left
	step_end

@ (10,5) -> west along the corridor, then down the side gallery
CF1_M_C8_RoxOut:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

CF1_M_C8_PlayerWatch:
	face_down
	delay_16
	delay_16
	face_left
	step_end

CF_C8_MinerTalk::
	cf_npc CF_N1_Mineur, CF1_T_088

CF_C8_CharbiTalk::
	lock
	faceplayer
	playmoncry SPECIES_ROLYCOLY, CRY_MODE_NORMAL
	cf_narr CF1_T_102
	waitmoncry
	release
	end

CF_C8_StrassieTalk::
	lock
	faceplayer
	playmoncry SPECIES_CARBINK, CRY_MODE_NORMAL
	cf_narr CF1_T_103
	waitmoncry
	release
	end

@ Pierre's challenge (content, not counted): after badge 1
CF_C8_Pierre::
	lock
	faceplayer
	setspeaker CF_N1_Pierre
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
	setspeaker CF_N1_Pierre
	msgbox CF1_T_106, MSGBOX_DEFAULT
	release
	end

@ ---------------------------------------------------------------- C9: Roxanne (D016)

CF_C9_Reward::
	raisecap 18
	setspeaker SP_NAME_NONE
	giveitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	cf_say CF_N1_Roxanne, RustboroCity_Gym_Text_ExplainRockTomb
	cf_if_dec 16, DEC_NONE, CF_C9_Ask
	release
	end

CF_C9_Ask::
	closemessage
	cf_move VAR_LAST_TALKED, Common_Movement_FacePlayer
	cf_say CF_N1_Roxanne, CF1_T_107
	setspeaker CF_N1_Roxanne
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
	cf_move OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	playse SE_RG_CARD_FLIP
	waitse
	cf_say CF_N1_Roxanne, CF1_T_110
	setdecision_once 16, DEC_A, CF_C9_End
	addaffinity VAR_CF_REP_L, 3
	subaffinity VAR_CF_BR, 2
	goto CF_C9_End

CF_C9_Refuse::
	cf_bexcl
	cf_bsay CF1_T_111
	cf_say CF_N1_Roxanne, CF1_T_112
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
	cf_narr CF1_T_113
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
	cf_npc CF_N1_Agent, CF1_T_114

@ Player is on x=40, y 10..15: walk up to (40,10), facing the gang
CF_C10_ToRow10::
	getplayerxy VAR_0x8004, VAR_0x8005
CF_C10_ToRow10_Loop::
	goto_if_le VAR_0x8005, 10, CF_C10_ToRow10_Done
	cf_move OBJ_EVENT_ID_PLAYER, CF1_M_Up1
	subvar VAR_0x8005, 1
	goto CF_C10_ToRow10_Loop
CF_C10_ToRow10_Done::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	return

CF_C10_Scene::
	goto_if_unset FLAG_BADGE01_GET, CF_Nop
	lockall
	call CF_C10_ToRow10
	cf_if_dec 16, DEC_A, CF_C10_Net
CF_C10_Brice::
	cf_bexcl
	cf_bsay CF1_T_115
	closemessage
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
	goto_if_set FLAG_CF_VIS_25, CF_C10_SpawnHoopa
	addobject LOCALID_CF_R116_FERRAND
CF_C10_SpawnHoopa::
	goto_if_set FLAG_CF_VIS_30, CF_C10_Spawned
	addobject LOCALID_CF_R116_HOOPA
	playmoncry SPECIES_HOOPA, CRY_MODE_WEAK
	waitmoncry
CF_C10_Spawned::
	delay 20
	turnobject LOCALID_CF_R116_LANCE, DIR_EAST
	cf_say CF_N1_Lance, CF1_T_116
	turnobject LOCALID_CF_R116_GRUNT_A, DIR_SOUTH
	cf_say CF_N1_Sbire, CF1_T_117
	cf_move LOCALID_CF_R116_LANCE, Common_Movement_WalkInPlaceFasterRight
	cf_say CF_N1_Lance, CF1_T_118
	closemessage
	turnobject LOCALID_CF_R116_LANCE, DIR_WEST
	turnobject LOCALID_CF_R116_GRUNT_A, DIR_WEST
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
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	cf_say CF_N1_Agent, CF1_T_114
	closemessage
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	goto CF_C10_Brice

CF_C10_ShowFerrand::
	clearflag FLAG_CF_VIS_25
	goto CF_C10_ShowHoopa

CF_C10_Ferrand::
	cf_bexcl
	cf_bsay CF1_T_122
	closemessage
	cf_move LOCALID_CF_R116_FERRAND, CF1_M_C10_FerrandOut
	cf_narr CF1_T_123
	closemessage
	setflag FLAG_CF_VIS_25
	removeobject LOCALID_CF_R116_FERRAND
	goto CF_C10_Poster

CF_C10_PosterA::
	cf_excl LOCALID_CF_R116_GRUNT_A
	setspeaker CF_N1_Sbire
	message CF1_T_124
	waitmessage
	goto CF_C10_Menu

CF_C10_Fight::
	setflag FLAG_CF_NO_WHITEOUT
	cf_excl LOCALID_CF_R116_GRUNT_A
	cf_move LOCALID_CF_R116_GRUNT_A, CF1_M_C10_GruntAIn
	trainerbattle_scene_no_intro TRAINER_GRUNT_PETALBURG_WOODS, CF1_T_125
	goto_if_unset TRAINER_FLAGS_START + TRAINER_GRUNT_PETALBURG_WOODS, CF_C10_FightEnd
	cf_move LOCALID_CF_R116_GRUNT_A, CF1_M_C10_GruntABack
	cf_excl LOCALID_CF_R116_GRUNT_B
	cf_move LOCALID_CF_R116_GRUNT_B, CF1_M_C10_GruntBIn
	trainerbattle_scene_no_intro TRAINER_GRUNT_RUSTURF_TUNNEL, CF1_T_126
	cf_move LOCALID_CF_R116_GRUNT_B, CF1_M_C10_GruntBBack
CF_C10_FightEnd::
	clearflag FLAG_CF_NO_WHITEOUT
	special HealPlayerParty
	playse SE_M_TELEPORT
	clearflag FLAG_CF_VIS_85
	addobject LOCALID_CF_R116_PORTAL
	cf_flash
	cf_shake 0, 3, 6, 4
	waitse
	cf_narr CF1_T_127
	call CF_C10_LoseItem
	turnobject LOCALID_CF_R116_LANCE, DIR_WEST
	cf_say CF_N1_Lance, CF1_T_128
	setdecision_once 14, DEC_A, CF_C10_End
	subaffinity VAR_CF_RK, 3
	addaffinity VAR_CF_REP_L, 1
	cf_lose_money 200
	goto CF_C10_End

CF_C10_Watch::
	turnobject LOCALID_CF_R116_LANCE, DIR_SOUTH
	cf_narr CF1_T_129
	closemessage
	playse SE_M_TELEPORT
	clearflag FLAG_CF_VIS_85
	addobject LOCALID_CF_R116_PORTAL
	cf_flash
	cf_shake 0, 3, 6, 4
	waitse
	cf_narr CF1_T_130
	cf_bsay CF1_T_131
	setdecision_once 14, DEC_B, CF_C10_End
	setflag FLAG_CF_DOS_HORAIRE_R116
	addaffinity VAR_CF_RK, 3
	goto CF_C10_End

CF_C10_Warn::
	cf_narr CF1_T_132
	closemessage
	setobjectxyperm LOCALID_CF_R116_FLORA, 35, 11
	clearflag FLAG_CF_VIS_20
	addobject LOCALID_CF_R116_FLORA
	cf_move LOCALID_CF_R116_FLORA, CF1_M_C10_FloraIn
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	cf_if_dec 8, DEC_A, CF_C10_FloraA
	cf_say CF_N1_Flora, CF1_T_133
	goto CF_C10_Warn2

CF_C10_FloraA::
	cf_say CF_N1_Flora, CF1_T_134
CF_C10_Warn2::
	closemessage
	cf_move LOCALID_CF_R116_FLORA, CF1_M_C10_FloraOn
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	cf_excl LOCALID_CF_R116_LANCE
	cf_narr CF1_T_135
	setdecision_once 14, DEC_C, CF_C10_End
	addaffinity VAR_CF_REP_L, 3
	subaffinity VAR_CF_REP_A, 2
	subaffinity VAR_CF_TI, 1
	goto CF_C10_End

@ Lance steps back to the ring and the gang vanishes with it
CF_C10_End::
	closemessage
	turnobject LOCALID_CF_R116_LANCE, DIR_EAST
	cf_move LOCALID_CF_R116_LANCE, CF1_M_C10_LanceOut
	playse SE_M_TELEPORT
	cf_flash
	setflag FLAG_CF_VIS_35
	setflag FLAG_CF_VIS_36
	setflag FLAG_CF_VIS_30
	setflag FLAG_CF_VIS_25
	setflag FLAG_CF_VIS_20
	removeobject LOCALID_CF_R116_LANCE
	setflag FLAG_CF_VIS_85
	removeobject LOCALID_CF_R116_PORTAL
	removeobject LOCALID_CF_R116_GRUNT_A
	removeobject LOCALID_CF_R116_HOOPA
	removeobject LOCALID_CF_R116_FERRAND
	removeobject LOCALID_CF_R116_FLORA
	waitse
	setvar VAR_ROUTE116_STATE, 2
	releaseall
	end

@ (43,9) -> down the slope and away east
CF1_M_C10_FerrandOut:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

@ (45,9) -> (41,10), facing Red at (40,10)
CF1_M_C10_GruntAIn:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	step_end

CF1_M_C10_GruntABack:
	walk_right
	walk_up
	face_left
	step_end

@ (45,11) -> (41,10)
CF1_M_C10_GruntBIn:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	step_end

@ (41,10) -> back to (45,11)
CF1_M_C10_GruntBBack:
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	face_left
	step_end

@ (35,11) -> (40,11), right below Red
CF1_M_C10_FloraIn:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_up
	step_end

CF1_M_C10_FloraOn:
	walk_fast_right
	walk_fast_right
	face_right
	step_end

CF1_M_C10_LanceOut:
	walk_right
	walk_right
	walk_right
	step_end

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
	cf_narr CF1_T_136
	return

@ The ruined grunt (D015)
CF_C10_SbireB::
	lock
	faceplayer
	cf_if_dec 15, DEC_NONE, CF_C10_SbireBTalk
	release
	end

CF_C10_SbireBTalk::
	cf_say CF_N1_Sbire, CF1_T_137
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
	playse SE_SHOP
	waitse
	cf_say CF_N1_Sbire, CF1_T_142
	setdecision_once 15, DEC_A, CF_C10_SbireBEnd
	subaffinity VAR_CF_RK, 2
	addaffinity VAR_CF_REP_P, 2
	removemoney 500
	clearflag FLAG_CF_VIS_38
	goto CF_C10_SbireBEnd

CF_C10_NoGive::
	cf_narr CF1_T_143
	setdecision_once 15, DEC_B, CF_C10_SbireBEnd
	addaffinity VAR_CF_RK, 2
	goto CF_C10_SbireBEnd

CF_C10_SbireBEnd::
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_CF_VIS_37
	removeobject LOCALID_CF_R116_GRUNT_B
	fadescreen FADE_FROM_BLACK
	release
	end

CF_C10_ExMiner::
	cf_npc CF_N1_Mineur, CF1_T_144

@ ---------------------------------------------------------------- C11: end of the demo

@ Brice (6,4) and Red turn toward each other
CF_C11_FaceBrice::
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_lt VAR_0x8004, 6, CF_C11_FB_West
	goto_if_gt VAR_0x8004, 6, CF_C11_FB_East
	goto_if_lt VAR_0x8005, 4, CF_C11_FB_North
	turnobject LOCALID_CF_PC_BRICE, DIR_SOUTH
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	return

CF_C11_FB_North::
	turnobject LOCALID_CF_PC_BRICE, DIR_NORTH
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	return

CF_C11_FB_West::
	turnobject LOCALID_CF_PC_BRICE, DIR_WEST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	return

CF_C11_FB_East::
	turnobject LOCALID_CF_PC_BRICE, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	return

CF_C11_Scene::
	lockall
	checkfollowernpc
	goto_if_eq VAR_RESULT, FALSE, CF_C11_Brice
	destroyfollowernpc
CF_C11_Brice::
	clearflag FLAG_CF_VIS_43
	addobject LOCALID_CF_PC_BRICE
	delay 20
	cf_narr CF1_T_145
	closemessage
	cf_excl LOCALID_CF_PC_BRICE
	call CF_C11_FaceBrice
	setspeaker SP_NAME_NONE
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
	setspeaker CF_N1_Brice
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
	closemessage
	playse SE_M_TELEPORT
	clearflag FLAG_CF_VIS_29
	addobject LOCALID_CF_PC_HOOPA
	waitse
	playmoncry SPECIES_HOOPA, CRY_MODE_NORMAL
	cf_excl LOCALID_CF_PC_BRICE
	turnobject LOCALID_CF_PC_BRICE, DIR_WEST
	cf_face LOCALID_CF_PC_HOOPA
	waitmoncry
	setspeaker SP_NAME_NONE
	goto_if_ge VAR_CF_HO, 25, CF_C11_ThiefGift
	goto_if_le VAR_CF_HO, 18, CF_C11_ThiefTake
	msgbox CF1_T_154, MSGBOX_DEFAULT
	goto CF_C11_Thesis

CF_C11_ThiefGift::
	cf_move LOCALID_CF_PC_HOOPA, CF1_M_Jump
	msgbox CF1_T_155, MSGBOX_DEFAULT
	giveitem ITEM_ORAN_BERRY
	cf_say CF_N1_Brice, CF1_T_156
	goto CF_C11_Thesis

CF_C11_ThiefTake::
	cf_move LOCALID_CF_PC_HOOPA, CF1_M_Jump
	playse SE_BALL
	msgbox CF1_T_157, MSGBOX_DEFAULT
	checkitem ITEM_POKE_BALL
	goto_if_eq VAR_RESULT, FALSE, CF_C11_Thesis
	removeitem ITEM_POKE_BALL
CF_C11_Thesis::
	closemessage
	playse SE_M_TELEPORT
	setflag FLAG_CF_VIS_29
	removeobject LOCALID_CF_PC_HOOPA
	waitse
	call CF_C11_FaceBrice
	cf_say CF_N1_Brice, CF1_T_158
	msgbox CF1_T_159, MSGBOX_DEFAULT
	cf_narr CF1_T_160
	msgbox CF1_T_161, MSGBOX_DEFAULT
	closemessage
	setvar VAR_CF_CHAPTER, 2
	setvar VAR_ROUTE116_STATE, 3
	call Common_EventScript_SaveGame
	releaseall
	end

CF_C11_BriceTalk::
	cf_npc CF_N1_Brice, CF1_T_158

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
	.string "d’entrer, monsieur.$"

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
	.string "me faites pas regretter ce choix.$"

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
	.string "Il a réclamé un avocat. Toute\p"
	.string "la nuit.$"

CF1_T_011::
	.string "Red ! Dis-leur que je suis venu\n"
	.string "de moi-même ! Dis-leur !$"

CF1_T_012::
	.string "Il peut partir. Sous votre\n"
	.string "responsabilité.$"

CF1_T_013::
	.string "Mon disque date chaque transfert,\n"
	.string "à la seconde. Ils vont voir.$"

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
	.string "Moi, j’entraîne. Tu veux choisir\n"
	.string "ton Pokémon de tête avant un duel ?$"

CF1_T_023::
	.string "C’est noté. Reviens me voir\n"
	.string "si tu changes d’avis.$"

CF1_T_024::
	.string "Barrage du Rempart. Le Bois est\n"
	.string "fermé aux civils.$"

CF1_T_025::
	.string "Il est avec moi. Mon père s’en\n"
	.string "porte garant. Vérifiez donc.$"

CF1_T_026::
	.string "Le fils de Seko… Bon. Passez.$"

CF1_T_027::
	.string "Ah, l’insigne. Passez, monsieur.$"

CF1_T_028::
	.string "Red, de Kanto ? Le chef vous a\n"
	.string "inscrit. Passez.$"

CF1_T_029::
	.string "Pas d’insigne, pas de garant ?\n"
	.string "Alors vous attendez.$"

CF1_T_030::
	.string "Laisse, je m’en charge. Monsieur,\n"
	.string "vous me suivez. Sous escorte.$"

CF1_T_031::
	.string "Trois arrivants de Galar. Ils\n"
	.string "pillent les nids des Nirondelle.$"

CF1_T_032::
	.string "Ordre du Rempart : on les abat.\n"
	.string "…Rien de personnel.$"

CF1_T_033::
	.string "Les abattre ?! Flora, ils sont\n"
	.string "juste perdus !$"

CF1_T_034::
	.string "Red s’avance entre la brigade et\n"
	.string "les arrivants.$"

CF1_T_035::
	.string "Tu veux les protéger ? Alors\n"
	.string "prouve-le. En duel.$"

CF1_T_036::
	.string "D’accord, d’accord ! T’as gagné.$"

CF1_T_037::
	.string "Ils filent. Mon père va adorer\n"
	.string "mon rapport. …Ou pas.$"

CF1_T_038::
	.string "Flora s’en souviendra.\n"
	.string "Et moi aussi, monsieur.$"

CF1_T_039::
	.string "Au moins, t’as essayé. Frais de\n"
	.string "brigade : 300 Pokédollars.$"

CF1_T_040::
	.string "Red hésite… et laisse la brigade\n"
	.string "faire son travail.$"

CF1_T_041::
	.string "Sage décision. Je te salue, Red.\n"
	.string "…Même si ça me plaît pas non plus.$"

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
	.string "…C’est toi. Sur l’affiche.\n"
	.string "C’est toi, Red !$"

CF1_T_048::
	.string "Excusez-moi… Vous ressemblez au\n"
	.string "garçon de l’affiche. De Kanto.$"

CF1_T_049::
	.string "Rester devant$"

CF1_T_050::
	.string "Partir$"

CF1_T_051::
	.string "Un passant prend une photo. Red\n"
	.string "ne bouge pas.$"

CF1_T_052::
	.string "Un contrat, je parie. Signé pour\n"
	.string "une Master Ball, à onze ans ?$"

CF1_T_053::
	.string "C’était… Non ? Pas de réponse.\n"
	.string "D’accord. Je n’insiste pas.$"

CF1_T_054::
	.string "Le célèbre Red ! Ferrand, ingénieur\n"
	.string "Passerelle. Vraiment enchanté.$"

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
	.string "ingénieur. Je note.$"

CF1_T_060::
	.string "Ferrand vous regarde partir.$"

CF1_T_061::
	.string "Passerelle vous plaît ? Revenez\n"
	.string "quand vous voulez. Vraiment.$"

CF1_T_062::
	.string "Bienvenue chez Devon ! Voici la\n"
	.string "Passerelle : le monde en 1 seconde.$"

CF1_T_063::
	.string "Sylphe fournit le Cœur, Devon le\n"
	.string "réseau. Une si belle alliance !$"

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
	.string "…Sur l’affiche, en bas de la rue ?$"

CF1_T_069::
	.string "Red ! Vous avez vu l’affiche ?\n"
	.string "Vous y êtes si… vendeur !$"

CF1_T_070::
	.string "Une petite photo avec moi, près\n"
	.string "du Kiosque ? Pour la presse !$"

CF1_T_071::
	.string "Poser$"

CF1_T_072::
	.string "Flash. Le Président serre la main\n"
	.string "de Red. Longtemps.$"

CF1_T_073::
	.string "Ha. Ha. Une autre fois,\n"
	.string "peut-être.$"

CF1_T_074::
	.string "Un service, Red ? Une lettre pour\n"
	.string "mon fils, Pierre Rochard, à Myokara.$"

CF1_T_075::
	.string "Les traversées reprendront bientôt.\n"
	.string "Enfin, j’espère.$"

CF1_T_076::
	.string "Red ! Mon père m’a libéré, me\n"
	.string "voilà ! J’ai raté quoi ?$"

CF1_T_077::
	.string "Un petit cercle d’or s’ouvre tout\n"
	.string "près. Une main violette en sort.$"

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
	.string "baie. On s’est fait avoir.$"

CF1_T_085::
	.string "Red court. Quatre pages tombent.\n"
	.string "Le voleur file vers l’est.$"

CF1_T_086::
	.string "Quatre pages… Il est parti vers\n"
	.string "l’est. Je note.\p"
	.string "Sur les pages qui me restent.$"

CF1_T_087::
	.string "Tu fais rien ?! C’était tout\n"
	.string "mon recensement !$"

CF1_T_088::
	.string "Ils bouffent le charbon, les\n"
	.string "galeries s’effondrent. On est\p"
	.string "tous virés !$"

CF1_T_089::
	.string "Roxanne, championne. Et prof. Il\n"
	.string "me faut des données, pas des cris.$"

CF1_T_090::
	.string "Pierre, d’Argenta. Je suis coincé\n"
	.string "ici depuis que les ports ont fermé.$"

CF1_T_091::
	.string "Je peux les emmener. J’élève des\n"
	.string "Pokémon. Chez moi, ils seraient\p"
	.string "à leur place.$"

CF1_T_092::
	.string "Les emmener ? On les abat, oui,\n"
	.string "et on rouvre demain !$"

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
	.string "et ils repartent avec moi.$"

CF1_T_098::
	.string "Un protocole : on balise, on rouvre,\n"
	.string "on compte. Je te citerai.$"

CF1_T_099::
	.string "La galerie se vide. Un mineur\n"
	.string "pleure son Charbi apprivoisé.$"

CF1_T_100::
	.string "Je note l’état de la galerie.\n"
	.string "On verra bien ce qui revient.$"

CF1_T_101::
	.string "Je t’attends à l’arène. Tu as gagné\n"
	.string "le droit d’essayer.$"

CF1_T_102::
	.string "Charbi crépite doucement.$"

CF1_T_103::
	.string "Strassie scintille faiblement.$"

CF1_T_104::
	.string "Un petit duel entre coincés ?\n"
	.string "Sans rancune.$"

CF1_T_105::
	.string "Solide. Tu as de la roche dans\n"
	.string "le cœur.$"

CF1_T_106::
	.string "Reviens quand tu veux. Moi, les\n"
	.string "galeries m’attendent.$"

CF1_T_107::
	.string "Joli combat. Une dernière chose :\n"
	.string "tes observations sur les anneaux.$"

CF1_T_108::
	.string "Le Rempart me les réclame. Je\n"
	.string "peux les leur transmettre ?$"

CF1_T_109::
	.string "Donner$"

CF1_T_110::
	.string "Des données, pas des cris. Merci.$"

CF1_T_111::
	.string "Nos chiffres restent à nous.\n"
	.string "C’est mon carnet, après tout.$"

CF1_T_112::
	.string "Je respecte. Le Rempart, moins.$"

CF1_T_113::
	.string "Arène fermée. Roxanne est aux mines,\n"
	.string "par la Route 116.$"

CF1_T_114::
	.string "Nos filets sont posés là-bas.\n"
	.string "Grâce à vos chiffres. Merci.$"

CF1_T_115::
	.string "Chut !… Des hommes en noir, près\n"
	.string "des rochers. Ils attendent.$"

CF1_T_116::
	.string "Quatre minutes. Préparez les cages.\n"
	.string "Le cercle sera gros, ce soir.$"

CF1_T_117::
	.string "Et… si la brigade débarque, chef ?$"

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
	.string "Hé ! C’est le gamin de l’affiche !\n"
	.string "Le champion de Kanto !$"

CF1_T_125::
	.string "Tu cognes fort, gamin.$"

CF1_T_126::
	.string "Je… J’aurais pas dû venir.$"

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
	.string "près. …Comment c’est possible ?$"

CF1_T_132::
	.string "Un sifflet strident. La brigade\n"
	.string "accourt, Flora en tête.$"

CF1_T_133::
	.string "Merci, Red. On prend le relais.$"

CF1_T_134::
	.string "Encore toi. Cette fois, on est\n"
	.string "du même côté. Ça change.$"

CF1_T_135::
	.string "Un sbire est arrêté. Les arrivants\n"
	.string "saisis partent… vers l’abattage.$"

CF1_T_136::
	.string "{STR_VAR_1} a disparu dans\n"
	.string "l’anneau.$"

CF1_T_137::
	.string "Je suis pas un voleur, hein.\n"
	.string "J’étais mineur, avant les anneaux.$"

CF1_T_138::
	.string "Ils paient 200 P la nuit. Avec ça,\n"
	.string "ma fille mange.$"

CF1_T_139::
	.string "Toi, t’as refusé leur photo.\n"
	.string "Ça s’est su, en ville.$"

CF1_T_140::
	.string "Et toi, t’as posé en photo avec\n"
	.string "ceux qui nous ont virés.$"

CF1_T_141::
	.string "Donner 500 P$"

CF1_T_142::
	.string "…500 P. De quoi rentrer chez moi.\n"
	.string "D’accord. Je jette la casquette.\p"
	.string "Merci. Vraiment.$"

CF1_T_143::
	.string "Il remet sa casquette et suit\n"
	.string "les autres dans le noir.$"

CF1_T_144::
	.string "Ma fille m’a ouvert la porte. La\n"
	.string "mine me reprend lundi. Merci, Red.$"

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
	.string "On la retrouvera. Je le note.$"

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
	.string "Ton mineur est rentré chez sa\n"
	.string "fille. Il t’a salué, tu l’as vu ?$"

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

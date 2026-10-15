@ Hack: Confluence demo prologue (SLICE_DEMO_CH0-1 P1-P6). Edit this file directly.
@ Visibility flags: set = hidden. State vars: VAR_ROUTE104_STATE (P1: 0 -> 3), VAR_BRINEY_HOUSE_STATE (P2: 0 -> 9),
@ VAR_PETALBURG_CITY_STATE (20 = D006 b mini-scene), VAR_BIRCH_LAB_STATE (P3: 0 -> 5), VAR_ROUTE101_STATE (P4: 2 -> 3),
@ VAR_LITTLEROOT_RIVAL_STATE (P5: 4 -> 6, P6: 6 -> 7).
@ Namebox: every spoken line goes through cfp_say (speaker label = CF_N0_*), narration through cfp_nar (no box).
@ Staging objects: VIS_86-88 lab balls, VIS_89-92 Route 104 Pikachu/Gyarados/Ursaring/Tauros (see FLAGS_VARS_REGISTRY).

	.macro cfp_say spk:req, txt:req
	setspeaker \spk
	msgbox \txt, MSGBOX_DEFAULT
	.endm

	.macro cfp_nar txt:req
	setspeaker 0
	msgbox \txt, MSGBOX_DEFAULT
	.endm

@ ---------------------------------------------------------------- helpers

@ VAR_0x8004 = bit shift of the 4-bit BVCOUNT field (0 PROT, 4 ACC, 8 COMP); +1 clamped to 15
CF_IncBV::
	getbits VAR_CF_BVCOUNT, VAR_0x8004, 4
	goto_if_ge VAR_RESULT, 15, CF_IncBV_Done
	addvar VAR_RESULT, 1
	setbits VAR_CF_BVCOUNT, VAR_0x8004, 4, VAR_RESULT
CF_IncBV_Done::
	return

CF_GivePrologueTeam::
	givemon SPECIES_PIKACHU, 62, ITEM_LIGHT_BALL, gender=MON_MALE, move1=MOVE_THUNDERBOLT, move2=MOVE_QUICK_ATTACK, move3=MOVE_IRON_TAIL, move4=MOVE_THUNDER
	givemon SPECIES_CHARIZARD, 64, move1=MOVE_FLAMETHROWER, move2=MOVE_AIR_SLASH, move3=MOVE_DRAGON_PULSE, move4=MOVE_FOCUS_BLAST
	givemon SPECIES_VENUSAUR, 64, move1=MOVE_LEAF_STORM, move2=MOVE_SLUDGE_BOMB, move3=MOVE_SLEEP_POWDER, move4=MOVE_SYNTHESIS
	givemon SPECIES_BLASTOISE, 64, move1=MOVE_HYDRO_PUMP, move2=MOVE_BLIZZARD, move3=MOVE_FLASH_CANNON, move4=MOVE_FOCUS_BLAST
	givemon SPECIES_SNORLAX, 63, move1=MOVE_BODY_SLAM, move2=MOVE_REST, move3=MOVE_SNORE, move4=MOVE_CRUNCH
	givemon SPECIES_LAPRAS, 62, move1=MOVE_SURF, move2=MOVE_ICE_BEAM, move3=MOVE_PSYCHIC, move4=MOVE_SING
	return

CFP_Shake::
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special ShakeCamera
	waitstate
	return

@ ---------------------------------------------------------------- P1: la plage (Route 104)

CFP_P1_FaceSea::
	applymovement LOCALID_CF_R104_MARCO, Common_Movement_FaceLeft
	applymovement LOCALID_CF_R104_CELEO, Common_Movement_FaceLeft
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovement LOCALID_CF_R104_MARCO
	waitmovement LOCALID_CF_R104_CELEO
	waitmovement LOCALID_PLAYER
	return

CF_P1_Beach::
	lockall
	call CF_GivePrologueTeam
	cfp_nar CF_T_000
	cfp_say CF_N0_Marco, CF_T_001
	cfp_say CF_N0_Marco, CF_T_002
	cfp_say CF_N0_Celeo, CF_T_003
	cfp_say CF_N0_Celeo, CF_T_004
	cfp_say CF_N0_Celeo, CF_T_005
	cfp_say CF_N0_Celeo, CF_T_006
	closemessage
	playse SE_M_TELEPORT
	call CFP_Shake
	playse SE_PIN
	applymovement LOCALID_CF_R104_MARCO, Common_Movement_ExclamationMark
	applymovement LOCALID_CF_R104_CELEO, Common_Movement_ExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement LOCALID_CF_R104_MARCO
	waitmovement LOCALID_CF_R104_CELEO
	waitmovement LOCALID_PLAYER
	cfp_say CF_N0_Marco, CF_T_007
	closemessage
	call CFP_P1_FaceSea
	cfp_nar CF_T_008
	closemessage
	playse SE_THUNDERSTORM
	call CFP_Shake
	cfp_nar CF_T_009
	closemessage
	@ Tauros charges up the beach
	clearflag FLAG_CF_VIS_92
	addobject LOCALID_CF_R104_TAUROS
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_CF_R104_CELEO, Common_Movement_FaceDown
	applymovement LOCALID_CF_R104_TAUROS, CFP_Mov_TaurosCharge
	waitmovement LOCALID_CF_R104_TAUROS
	playse SE_M_TAKE_DOWN
	playmoncry SPECIES_TAUROS, CRY_MODE_NORMAL
	waitmoncry
	setobjectxyperm LOCALID_CF_R104_TAUROS, 15, 59
	cfp_say CF_N0_Celeo, CF_T_010
	closemessage
	setflag FLAG_CF_NO_WHITEOUT
	setwildbattle SPECIES_TAUROS, 42
	dowildbattle
	applymovement LOCALID_CF_R104_TAUROS, CFP_Mov_FastDown6
	waitmovement LOCALID_CF_R104_TAUROS
	removeobject LOCALID_CF_R104_TAUROS
	cfp_nar CF_T_011
	closemessage
	@ Ursaring comes down from the north
	clearflag FLAG_CF_VIS_91
	addobject LOCALID_CF_R104_URSARING
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_CF_R104_MARCO, Common_Movement_FaceRight
	applymovement LOCALID_CF_R104_CELEO, Common_Movement_FaceUp
	applymovement LOCALID_CF_R104_URSARING, CFP_Mov_FastDown4
	waitmovement LOCALID_CF_R104_URSARING
	playmoncry SPECIES_URSARING, CRY_MODE_NORMAL
	waitmoncry
	setobjectxyperm LOCALID_CF_R104_URSARING, 15, 55
	setwildbattle SPECIES_URSARING, 43
	dowildbattle
	applymovement LOCALID_CF_R104_URSARING, CFP_Mov_FastUp6
	waitmovement LOCALID_CF_R104_URSARING
	removeobject LOCALID_CF_R104_URSARING
	@ Gyarados rises from the sea
	call CFP_P1_FaceSea
	playse SE_M_SURF
	clearflag FLAG_CF_VIS_90
	addobject LOCALID_CF_R104_GYARADOS
	playmoncry SPECIES_GYARADOS, CRY_MODE_NORMAL
	call CFP_Shake
	waitmoncry
	setwildbattle SPECIES_GYARADOS, 45
	dowildbattle
	playse SE_M_DIVE
	removeobject LOCALID_CF_R104_GYARADOS
	cfp_say CF_N0_Marco, CF_T_012
	cfp_nar CF_T_013
	closemessage
	playse SE_M_TELEPORT
	call CFP_Shake
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement LOCALID_PLAYER
	cfp_nar CF_T_014
	closemessage
	playse SE_BALL_OPEN
	clearflag FLAG_CF_VIS_89
	addobject LOCALID_CF_R104_PIKACHU
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	waitmoncry
	playse SE_PIN
	applymovement LOCALID_CF_R104_CELEO, Common_Movement_ExclamationMark
	waitmovement LOCALID_CF_R104_CELEO
	cfp_say CF_N0_Celeo, CF_T_015
	setspeaker 0
	message CF_T_016
	waitmessage
	dynmultipush CF_T_017, 0
	dynmultipush CF_T_018, 1
	dynmultistack 0, 0, TRUE, 2, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	closemessage
	switch VAR_RESULT
	case 0, CF_P1_PikachuChoice
	case 1, CF_P1_BagChoice
	end

CF_P1_PikachuChoice::
	applymovement LOCALID_CF_R104_PIKACHU, CFP_Mov_PikaHop
	waitmovement LOCALID_CF_R104_PIKACHU
	removeobject LOCALID_CF_R104_PIKACHU
	cfp_nar CF_T_019
	cfp_nar CF_T_020
	cfp_say CF_N0_Celeo, CF_T_021
	setdecision_once 1, DEC_A, CF_P1_Common
	setbits VAR_CF_WORLD, 14, 2, 1
	subaffinity VAR_CF_REP_I, 3
	goto CF_P1_Common

CF_P1_BagChoice::
	applymovement LOCALID_CF_R104_PIKACHU, CFP_Mov_PikaFall
	waitmovement LOCALID_CF_R104_PIKACHU
	playse SE_M_DIVE
	removeobject LOCALID_CF_R104_PIKACHU
	cfp_nar CF_T_022
	cfp_nar CF_T_023
	cfp_say CF_N0_Celeo, CF_T_024
	setdecision_once 1, DEC_B, CF_P1_Common
	setflag FLAG_CF_DOS_JOURNAL_NOEUD
	addaffinity VAR_CF_REP_I, 5
	subaffinity VAR_CF_REP_C, 3
	goto CF_P1_Common

CF_P1_Common::
	clearparty
	clearflag FLAG_CF_NO_WHITEOUT
	cfp_say CF_N0_Marco, CF_T_025
	closemessage
	applymovement LOCALID_CF_R104_MARCO, CFP_Mov_Up2
	applymovement LOCALID_CF_R104_CELEO, CFP_Mov_Up2
	waitmovement LOCALID_CF_R104_MARCO
	waitmovement LOCALID_CF_R104_CELEO
	setflag FLAG_CF_VIS_00
	setflag FLAG_CF_VIS_01
	setflag FLAG_CF_VIS_89
	setflag FLAG_CF_VIS_90
	setflag FLAG_CF_VIS_91
	setflag FLAG_CF_VIS_92
	setvar VAR_ROUTE104_STATE, 3
	fadescreen FADE_TO_BLACK
	warp MAP_ROUTE104_MR_BRINEYS_HOUSE, 5, 7
	waitstate
	end

@ ---------------------------------------------------------------- P2: chez M. Marco

CF_P2_ShowCeleo::
	clearflag FLAG_CF_VIS_02
	return

CFP_P2_CeleoLeaves::
	applymovement LOCALID_CF_BRINEY_CELEO, CFP_Mov_CeleoExit
	waitmovement LOCALID_CF_BRINEY_CELEO
	playse SE_EXIT
	removeobject LOCALID_CF_BRINEY_CELEO
	return

CF_P2_Home::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	waitmovement LOCALID_PLAYER
	cfp_say CF_N0_Marco, CF_T_026
	cfp_say CF_N0_Marco, CF_T_027
	cfp_say CF_N0_Marco, CF_T_028
	cfp_say CF_N0_Marco, CF_T_029
	cfp_say CF_N0_Marco, CF_T_030
	cfp_say CF_N0_Marco, CF_T_031
	setspeaker 0
	message CF_T_032
	waitmessage
	dynmultipush CF_T_033, 0
	dynmultipush CF_T_034, 1
	dynmultistack 0, 0, TRUE, 2, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	closemessage
	switch VAR_RESULT
	case 0, CF_P2_Stay
	case 1, CF_P2_Follow
	end

CF_P2_Stay::
	cfp_say CF_N0_Marco, CF_T_035
	cfp_say CF_N0_Marco, CF_T_036
	cfp_say CF_N0_Celeo, CF_T_037
	closemessage
	call CFP_P2_CeleoLeaves
	setdecision_once 6, DEC_A, CF_P2_StayEnd
	setflag FLAG_CF_DOS_CLOCHETTE_PIKO
	setflag FLAG_CF_MARCO_ALLIE
	subaffinity VAR_CF_REP_L, 2
CF_P2_StayEnd::
	cfp_say CF_N0_Marco, CF_T_038
	cfp_say CF_N0_Marco, CF_T_039
	cfp_nar CF_T_040
	closemessage
	setflag FLAG_CF_VIS_02
	setvar VAR_BRINEY_HOUSE_STATE, 9
	fadescreen FADE_TO_BLACK
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 11
	waitstate
	end

CF_P2_Follow::
	cfp_say CF_N0_Celeo, CF_T_041
	closemessage
	call CFP_P2_CeleoLeaves
	setdecision_once 6, DEC_B, CF_P2_FollowEnd
	addaffinity VAR_CF_REP_I, 2
CF_P2_FollowEnd::
	cfp_say CF_N0_Marco, CF_T_042
	cfp_say CF_N0_Marco, CF_T_043
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	waitmovement LOCALID_PLAYER
	setflag FLAG_CF_VIS_02
	setvar VAR_BRINEY_HOUSE_STATE, 9
	setvar VAR_PETALBURG_CITY_STATE, 20
	fadescreen FADE_TO_BLACK
	warp MAP_PETALBURG_CITY, 3, 11
	waitstate
	end

CF_Briney_Home::
	lock
	faceplayer
	cfp_say CF_N0_Marco, CF_T_044
	release
	end

@ Petalburg west entrance mini-scene (D006 b)
CF_P2_PetalburgShow::
	clearflag FLAG_CF_VIS_40
	clearflag FLAG_CF_VIS_41
	return

CF_P2_PetalburgScene::
	lockall
	delay 20
	applymovement LOCALID_CF_PETAL_POLICE, CFP_Mov_Left6
	waitmovement LOCALID_CF_PETAL_POLICE
	playse SE_PIN
	applymovement LOCALID_CF_PETAL_POLICE, Common_Movement_ExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement LOCALID_CF_PETAL_POLICE
	waitmovement LOCALID_PLAYER
	cfp_say CF_N0_Agent, CF_T_045
	cfp_say CF_N0_Celeo, CF_T_046
	cfp_say CF_N0_Agent, CF_T_047
	closemessage
	applymovement LOCALID_CF_PETAL_POLICE, CFP_Mov_UpFaceDown
	waitmovement LOCALID_CF_PETAL_POLICE
	applymovement LOCALID_CF_PETAL_CELEO, CFP_Mov_Right4
	applymovement LOCALID_PLAYER, CFP_Mov_Right3
	waitmovement LOCALID_CF_PETAL_CELEO
	waitmovement LOCALID_PLAYER
	setflag FLAG_CF_VIS_40
	setflag FLAG_CF_VIS_41
	setvar VAR_PETALBURG_CITY_STATE, 1
	cfp_nar CF_T_048
	closemessage
	fadescreen FADE_TO_BLACK
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 11
	waitstate
	end

@ ---------------------------------------------------------------- P3: le labo de Seko

@ OnTransition of the lab: starter table + balls during the P3 scene, hurt Pikachu if D001 = A
CF_Lab_ShowPikachu::
	call_if_eq VAR_BIRCH_LAB_STATE, 0, CFP_Lab_ShowTable
	getbits VAR_CF_WORLD, 14, 2
	goto_if_eq VAR_RESULT, 1, CF_Lab_ShowPikachuYes
	return

CFP_Lab_ShowTable::
	setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
	clearflag FLAG_CF_VIS_86
	clearflag FLAG_CF_VIS_87
	clearflag FLAG_CF_VIS_88
	return

CF_Lab_ShowPikachuYes::
	clearflag FLAG_CF_VIS_05
	return

CF_Lab_HurtPikachu::
	lock
	cfp_nar CF_T_049
	release
	end

CF_P3_Lab::
	lockall
	applymovement LOCALID_PLAYER, CFP_Mov_Up6
	waitmovement LOCALID_PLAYER
	applymovement LOCALID_BIRCHS_LAB_BIRCH, Common_Movement_FaceDown
	waitmovement LOCALID_BIRCHS_LAB_BIRCH
	playse SE_PIN
	applymovement LOCALID_BIRCHS_LAB_BIRCH, Common_Movement_ExclamationMark
	waitmovement LOCALID_BIRCHS_LAB_BIRCH
	cfp_say CF_N0_Seko, CF_T_050
	cfp_say CF_N0_Seko, CF_T_051
	getbits VAR_CF_WORLD, 14, 2
	goto_if_eq VAR_RESULT, 1, CF_P3_PikachuHurt
	cfp_say CF_N0_Seko, CF_T_052
	goto CF_P3_Starter

CF_P3_PikachuHurt::
	cfp_say CF_N0_Seko, CF_T_053
	cfp_say CF_N0_Seko, CF_T_054
	goto CF_P3_Starter

CF_P3_Starter::
	cfp_say CF_N0_Seko, CF_T_055
	cfp_say CF_N0_Seko, CF_T_056
	closemessage
	applymovement LOCALID_BIRCHS_LAB_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement LOCALID_BIRCHS_LAB_BIRCH
	applymovement LOCALID_PLAYER, CFP_Mov_Right3FaceUp
	waitmovement LOCALID_PLAYER
	setspeaker 0
	message CF_T_057
	waitmessage
	dynmultipush CF_T_058, 0
	dynmultipush CF_T_059, 1
	dynmultipush CF_T_060, 2
	dynmultistack 0, 0, TRUE, 3, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	closemessage
	switch VAR_RESULT
	case 0, CF_P3_Treecko
	case 1, CF_P3_Torchic
	case 2, CF_P3_Mudkip
	end

CF_P3_Treecko::
	playse SE_BALL_OPEN
	removeobject LOCALID_CF_LAB_BALL_TREECKO
	givemon SPECIES_TREECKO, 5
	setvar VAR_STARTER_MON, 0
	setdecision_once 4, DEC_A, CF_P3_StarterGot
	cfp_nar CF_P3_Text_GotTreecko
	goto CF_P3_StarterGot

CF_P3_Torchic::
	playse SE_BALL_OPEN
	removeobject LOCALID_CF_LAB_BALL_TORCHIC
	givemon SPECIES_TORCHIC, 5
	setvar VAR_STARTER_MON, 1
	setdecision_once 4, DEC_B, CF_P3_StarterGot
	cfp_nar CF_P3_Text_GotTorchic
	goto CF_P3_StarterGot

CF_P3_Mudkip::
	playse SE_BALL_OPEN
	removeobject LOCALID_CF_LAB_BALL_MUDKIP
	givemon SPECIES_MUDKIP, 5
	setvar VAR_STARTER_MON, 2
	setdecision_once 4, DEC_C, CF_P3_StarterGot
	cfp_nar CF_P3_Text_GotMudkip
	goto CF_P3_StarterGot

CF_P3_StarterGot::
	closemessage
	applymovement LOCALID_PLAYER, CFP_Mov_Left3FaceUp
	waitmovement LOCALID_PLAYER
	applymovement LOCALID_BIRCHS_LAB_BIRCH, Common_Movement_FaceDown
	waitmovement LOCALID_BIRCHS_LAB_BIRCH
	cfp_say CF_N0_Seko, CF_T_061
	cfp_say CF_N0_Seko, CF_T_062
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	additem ITEM_POKE_BALL, 5
	additem ITEM_ORAN_BERRY, 1
	playfanfare MUS_OBTAIN_ITEM
	cfp_nar CF_P3_Text_GotItems
	waitfanfare
	cfp_say CF_N0_Seko, CF_T_063
	setspeaker 0
	message CF_T_064
	waitmessage
	dynmultipush CF_T_065, 0
	dynmultipush CF_T_066, 1
	dynmultistack 0, 0, TRUE, 2, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	closemessage
	switch VAR_RESULT
	case 0, CF_P3_Normal
	case 1, CF_P3_Hard
	end

CF_P3_Normal::
	setdifficulty DIFFICULTY_NORMAL
	goto CF_P3_Phone

CF_P3_Hard::
	setdifficulty DIFFICULTY_HARD
	goto CF_P3_Phone

CF_P3_Phone::
	playse SE_PIN
	applymovement LOCALID_BIRCHS_LAB_BIRCH, Common_Movement_ExclamationMark
	waitmovement LOCALID_BIRCHS_LAB_BIRCH
	cfp_say CF_N0_Assistant, CF_T_067
	cfp_say CF_N0_Seko, CF_T_068
	cfp_nar CF_T_069
	cfp_say CF_N0_Norman, CF_T_070
	setspeaker 0
	message CF_T_071
	waitmessage
	dynmultipush CF_T_072, 0
	dynmultipush CF_T_073, 1
	dynmultistack 0, 0, TRUE, 2, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	closemessage
	switch VAR_RESULT
	case 0, CF_P3_NameGiven
	case 1, CF_P3_Anonymous
	end

CF_P3_NameGiven::
	cfp_nar CF_T_074
	cfp_say CF_N0_Norman, CF_T_075
	cfp_say CF_N0_Norman, CF_T_076
	cfp_say CF_N0_Norman, CF_T_077
	setdecision_once 2, DEC_A, CF_P3_Letter
	setbits VAR_CF_WORLD, 0, 2, 2
	addaffinity VAR_CF_REP_L, 3
	addaffinity VAR_CF_RK, 3
	goto CF_P3_Letter

CF_P3_Anonymous::
	cfp_say CF_N0_Seko, CF_T_078
	cfp_say CF_N0_Norman, CF_T_079
	cfp_say CF_N0_Norman, CF_T_080
	setdecision_once 2, DEC_B, CF_P3_Letter
	setbits VAR_CF_WORLD, 0, 2, 0
	subaffinity VAR_CF_REP_L, 3
	addaffinity VAR_CF_BR, 2
	goto CF_P3_Letter

CF_P3_Letter::
	cfp_say CF_N0_Seko, CF_T_081
	cfp_nar CF_T_082
	setspeaker 0
	message CF_T_083
	waitmessage
	dynmultipush CF_T_084, 0
	dynmultipush CF_T_085, 1
	dynmultistack 0, 0, TRUE, 2, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	closemessage
	switch VAR_RESULT
	case 0, CF_P3_LetterShown
	case 1, CF_P3_LetterKept
	end

CF_P3_LetterShown::
	cfp_say CF_N0_Seko, CF_T_086
	cfp_say CF_N0_Seko, CF_T_087
	cfp_say CF_N0_Seko, CF_T_088
	setdecision_once 5, DEC_A, CF_P3_End
	setflag FLAG_CF_CHEN_LETTRE_MONTREE
	addaffinity VAR_CF_BR, 2
	goto CF_P3_End

CF_P3_LetterKept::
	cfp_nar CF_T_089
	cfp_say CF_N0_Seko, CF_T_090
	setdecision_once 5, DEC_B, CF_P3_End
	subaffinity VAR_CF_BR, 2
	goto CF_P3_End

CF_P3_End::
	cfp_say CF_N0_Seko, CF_T_091
	closemessage
	removeobject LOCALID_CF_LAB_BALL_TREECKO
	removeobject LOCALID_CF_LAB_BALL_TORCHIC
	removeobject LOCALID_CF_LAB_BALL_MUDKIP
	setvar VAR_BIRCH_LAB_STATE, 5
	releaseall
	end

@ Seko heals the team every time he is spoken to (whole demo)
CF_Lab_Seko::
	lock
	faceplayer
	special HealPlayerParty
	playfanfare MUS_HEAL
	waitfanfare
	cfp_say CF_N0_Seko, CF_T_092
	release
	end

@ ---------------------------------------------------------------- P4: la ronde de Brice (Route 101)

CF_P4_Show::
	clearflag FLAG_CF_VIS_06
	clearflag FLAG_CF_VIS_08
	return

CFP_P4_MonsFlee::
	applymovement LOCALID_CF_R101_A, CFP_Mov_FleeLeft
	applymovement LOCALID_CF_R101_B, CFP_Mov_FleeRight
	applymovement LOCALID_CF_R101_C, CFP_Mov_FleeUp
	waitmovement LOCALID_CF_R101_A
	waitmovement LOCALID_CF_R101_B
	waitmovement LOCALID_CF_R101_C
	removeobject LOCALID_CF_R101_A
	removeobject LOCALID_CF_R101_B
	removeobject LOCALID_CF_R101_C
	return

CF_Route101_BriceRound::
	lockall
	applymovement LOCALID_PLAYER, CFP_Mov_Up3
	waitmovement LOCALID_PLAYER
	applymovement LOCALID_ROUTE101_BIRCH, CFP_Mov_Panic
	applymovement LOCALID_CF_R101_A, CFP_Mov_Hop
	applymovement LOCALID_CF_R101_B, CFP_Mov_Hop
	applymovement LOCALID_CF_R101_C, CFP_Mov_Hop
	playmoncry SPECIES_SPEAROW, CRY_MODE_NORMAL
	waitmovement LOCALID_ROUTE101_BIRCH
	waitmovement LOCALID_CF_R101_A
	waitmovement LOCALID_CF_R101_B
	waitmovement LOCALID_CF_R101_C
	waitmoncry
	playse SE_PIN
	applymovement LOCALID_ROUTE101_BIRCH, Common_Movement_ExclamationMark
	waitmovement LOCALID_ROUTE101_BIRCH
	applymovement LOCALID_ROUTE101_BIRCH, Common_Movement_FaceDown
	waitmovement LOCALID_ROUTE101_BIRCH
	cfp_say CF_N0_Brice, CF_T_093
	cfp_say CF_N0_Brice, CF_T_094
	cfp_nar CF_T_095
	setspeaker 0
	message CF_T_096
	waitmessage
	dynmultipush CF_T_097, 0
	dynmultipush CF_T_098, 1
	dynmultistack 0, 0, TRUE, 2, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	closemessage
	switch VAR_RESULT
	case 0, CF_P4_Help
	case 1, CF_P4_Watch
	end

CF_P4_Help::
	closemessage
	setflag FLAG_CF_NO_WHITEOUT
	setwildbattle SPECIES_SPEAROW, 5
	dowildbattle
	clearflag FLAG_CF_NO_WHITEOUT
	special HealPlayerParty
	call CFP_P4_MonsFlee
	cfp_say CF_N0_Brice, CF_T_099
	setdecision_once 3, DEC_A, CF_P4_Common
	addaffinity VAR_CF_BR, 3
	subaffinity VAR_CF_HO, 1
	setvar VAR_0x8004, 0
	call CF_IncBV
	goto CF_P4_Common

CF_P4_Watch::
	cfp_nar CF_T_100
	cfp_nar CF_T_101
	closemessage
	call CFP_P4_MonsFlee
	cfp_say CF_N0_Brice, CF_T_102
	cfp_say CF_N0_Brice, CF_T_103
	setdecision_once 3, DEC_B, CF_P4_Common
	subaffinity VAR_CF_BR, 3
	setvar VAR_0x8004, 8
	call CF_IncBV
	goto CF_P4_Common

CF_P4_Common::
	cfp_say CF_N0_Brice, CF_T_104
	closemessage
	clearflag FLAG_NO_WILD_ENCOUNTERS
	setflag FLAG_CF_VIS_06
	setflag FLAG_CF_VIS_08
	setvar VAR_ROUTE101_STATE, 3
	fadescreen FADE_TO_BLACK
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 7, 2
	waitstate
	end

@ ---------------------------------------------------------------- P5: matin chez les Seko

CF_P5_Mom::
	cfp_say CF_N0_MmeSeko, CF_T_105
	cfp_say CF_N0_MmeSeko, CF_T_106
	setflag FLAG_RECEIVED_RUNNING_SHOES
	playfanfare MUS_OBTAIN_ITEM
	cfp_nar CF_P5_Text_GotShoes
	waitfanfare
	return

CF_MmeSeko_Talk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_RUNNING_SHOES, CF_MmeSeko_Again
	call CF_P5_Mom
	release
	end

CF_MmeSeko_Again::
	cfp_say CF_N0_MmeSeko, CF_T_107
	release
	end

CF_P5_ExitTrigger::
	lockall
	goto_if_set FLAG_RECEIVED_RUNNING_SHOES, CF_P5_ExitBrice
	getplayerxy VAR_0x8004, VAR_0x8005
	call_if_eq VAR_0x8004, 8, CFP_P5_MomTo8
	call_if_ne VAR_0x8004, 8, CFP_P5_MomTo9
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovement LOCALID_PLAYER
	call CF_P5_Mom
CF_P5_ExitBrice::
	cfp_say CF_N0_Brice, CF_T_108
	closemessage
	setvar VAR_LITTLEROOT_RIVAL_STATE, 6
	releaseall
	end

CFP_P5_MomTo8::
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, CFP_Mov_Right5
	waitmovement LOCALID_RIVALS_HOUSE_1F_MOM
	return

CFP_P5_MomTo9::
	applymovement LOCALID_RIVALS_HOUSE_1F_MOM, CFP_Mov_Right6
	waitmovement LOCALID_RIVALS_HOUSE_1F_MOM
	return

@ ---------------------------------------------------------------- P6: Route 103, duel et Zigzaton de Galar

CF_P6_ShowBrice::
	clearflag FLAG_CF_VIS_07
	return

CF_Route103_BriceDuel::
	lockall
	applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
	waitmovement LOCALID_ROUTE103_RIVAL
	checkdecision 3
	goto_if_eq VAR_RESULT, DEC_A, CF_P6_IntroA
	cfp_say CF_N0_Brice, CF_T_109
	goto CF_P6_Battle

CF_P6_IntroA::
	cfp_say CF_N0_Brice, CF_T_110
	goto CF_P6_Battle

CF_P6_Battle::
	closemessage
	setflag FLAG_CF_NO_WHITEOUT
	checkdecision 4
	goto_if_eq VAR_RESULT, DEC_A, CF_P6_VsTorchic
	goto_if_eq VAR_RESULT, DEC_B, CF_P6_VsMudkip
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TREECKO, CF_P6_Text_Defeated
	goto_if_set TRAINER_FLAGS_START + TRAINER_BRENDAN_ROUTE_103_TREECKO, CF_P6_Won
	goto CF_P6_Lost

CF_P6_VsTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TORCHIC, CF_P6_Text_Defeated
	goto_if_set TRAINER_FLAGS_START + TRAINER_BRENDAN_ROUTE_103_TORCHIC, CF_P6_Won
	goto CF_P6_Lost

CF_P6_VsMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, CF_P6_Text_Defeated
	goto_if_set TRAINER_FLAGS_START + TRAINER_BRENDAN_ROUTE_103_MUDKIP, CF_P6_Won
	goto CF_P6_Lost

CF_P6_Won::
	cfp_say CF_N0_Brice, CF_T_111
	goto CF_P6_AfterDuel

CF_P6_Lost::
	cfp_say CF_N0_Brice, CF_T_112
	goto CF_P6_AfterDuel

CF_P6_AfterDuel::
	clearflag FLAG_CF_NO_WHITEOUT
	special HealPlayerParty
	closemessage
	clearflag FLAG_CF_VIS_16
	addobject LOCALID_CF_R103_ZIGZAGOON
	applymovement LOCALID_CF_R103_ZIGZAGOON, CFP_Mov_ZigLimp
	waitmovement LOCALID_CF_R103_ZIGZAGOON
	playmoncry SPECIES_ZIGZAGOON_GALAR, CRY_MODE_NORMAL
	waitmoncry
	cfp_nar CF_T_113
	closemessage
	applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FaceRight
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement LOCALID_ROUTE103_RIVAL
	waitmovement LOCALID_PLAYER
	cfp_say CF_N0_Brice, CF_T_114
	closemessage
	clearflag FLAG_CF_VIS_09
	addobject LOCALID_CF_R103_POLICE
	applymovement LOCALID_CF_R103_POLICE, CFP_Mov_Left7
	waitmovement LOCALID_CF_R103_POLICE
	playse SE_PIN
	applymovement LOCALID_CF_R103_POLICE, Common_Movement_ExclamationMark
	waitmovement LOCALID_CF_R103_POLICE
	cfp_say CF_N0_Agent, CF_T_115
	setspeaker 0
	message CF_T_116
	waitmessage
	dynmultipush CF_T_117, 0
	dynmultipush CF_T_118, 1
	dynmultistack 0, 0, TRUE, 2, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	closemessage
	switch VAR_RESULT
	case 0, CF_P6_Capture
	case 1, CF_P6_Leave
	end

CF_P6_Capture::
	playse SE_BALL_OPEN
	removeobject LOCALID_CF_R103_ZIGZAGOON
	givemon SPECIES_ZIGZAGOON_GALAR, 5
	playfanfare MUS_OBTAIN_ITEM
	cfp_nar CF_P6_Text_GotZigzagoon
	waitfanfare
	cfp_say CF_N0_Agent, CF_T_119
	cfp_say CF_N0_Brice, CF_T_120
	setdecision_once 7, DEC_A, CF_P6_End
	subaffinity VAR_CF_REP_L, 2
	setvar VAR_0x8004, 4
	call CF_IncBV
	goto CF_P6_End

CF_P6_Leave::
	cfp_say CF_N0_Agent, CF_T_121
	closemessage
	applymovement LOCALID_CF_R103_POLICE, CFP_Mov_Right8
	applymovement LOCALID_CF_R103_ZIGZAGOON, CFP_Mov_Right8
	waitmovement LOCALID_CF_R103_POLICE
	waitmovement LOCALID_CF_R103_ZIGZAGOON
	removeobject LOCALID_CF_R103_ZIGZAGOON
	removeobject LOCALID_CF_R103_POLICE
	cfp_say CF_N0_Brice, CF_T_122
	setdecision_once 7, DEC_B, CF_P6_End
	addaffinity VAR_CF_REP_L, 2
	setvar VAR_0x8004, 0
	call CF_IncBV
	goto CF_P6_End

CF_P6_End::
	closemessage
	applymovement LOCALID_CF_R103_POLICE, CFP_Mov_Right8
	waitmovement LOCALID_CF_R103_POLICE
	removeobject LOCALID_CF_R103_POLICE
	removeobject LOCALID_CF_R103_ZIGZAGOON
	setflag FLAG_CF_VIS_16
	setflag FLAG_CF_VIS_09
	setvar VAR_CF_CHAPTER, 1
	clearflag FLAG_CF_VIS_39
	setvar VAR_OLDALE_TOWN_STATE, 1
	setvar VAR_LITTLEROOT_RIVAL_STATE, 7
	applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
	waitmovement LOCALID_ROUTE103_RIVAL
	checkdecision 5
	goto_if_eq VAR_RESULT, DEC_A, CF_P6_BriceFollows
	cfp_say CF_N0_Brice, CF_T_123
	closemessage
	removeobject LOCALID_ROUTE103_RIVAL
	setflag FLAG_CF_VIS_07
	releaseall
	end

CF_P6_BriceFollows::
	cfp_say CF_N0_Brice, CF_T_124
	closemessage
	removeobject LOCALID_ROUTE103_RIVAL
	setflag FLAG_CF_VIS_07
	createfollowernpc OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL, FNPC_ALL_LAND
	releaseall
	end

@ ---------------------------------------------------------------- movements (CFP_Mov_*, prologue only)

CFP_Mov_TaurosCharge:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	face_up
	step_end

CFP_Mov_FastDown6:
	walk_fast_down
	walk_fast_down
	walk_fast_down
CFP_Mov_FastDown3:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

CFP_Mov_FastDown4:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

CFP_Mov_FastUp6:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

CFP_Mov_PikaHop:
	jump_in_place_right
	jump_in_place_right
	step_end

CFP_Mov_PikaFall:
	jump_in_place_left
	jump_2_left
	step_end

CFP_Mov_Up2:
	walk_up
	walk_up
	step_end

CFP_Mov_Up3:
	walk_up
	walk_up
	walk_up
	step_end

CFP_Mov_Up6:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CFP_Mov_CeleoExit:
	walk_down
	walk_down
	walk_right
	walk_down
	step_end

CFP_Mov_Left7:
	walk_left
CFP_Mov_Left6:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

CFP_Mov_UpFaceDown:
	walk_up
	face_down
	step_end

CFP_Mov_Right8:
	walk_right
	walk_right
CFP_Mov_Right6:
	walk_right
CFP_Mov_Right5:
	walk_right
CFP_Mov_Right4:
	walk_right
CFP_Mov_Right3:
	walk_right
	walk_right
	walk_right
	step_end

CFP_Mov_Right3FaceUp:
	walk_right
	walk_right
	walk_right
	face_up
	step_end

CFP_Mov_Left3FaceUp:
	walk_left
	walk_left
	walk_left
	face_up
	step_end

CFP_Mov_Panic:
	walk_in_place_fast_left
	walk_in_place_fast_right
	walk_in_place_fast_left
	walk_in_place_fast_right
	step_end

CFP_Mov_Hop:
	jump_in_place_down
	jump_in_place_down
	step_end

CFP_Mov_FleeLeft:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

CFP_Mov_FleeRight:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

CFP_Mov_FleeUp:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

CFP_Mov_ZigLimp:
	walk_slow_left
	walk_slow_up
	walk_slow_left
	step_end

@ ---------------------------------------------------------------- speaker names (namebox, ROM pointers)

CF_N0_Marco::
	.string "Marco$"
CF_N0_Celeo::
	.string "Ciléo$"
CF_N0_Seko::
	.string "Seko$"
CF_N0_Brice::
	.string "Brice$"
CF_N0_MmeSeko::
	.string "Mme Seko$"
CF_N0_Norman::
	.string "Norman$"
CF_N0_Agent::
	.string "Agent$"
CF_N0_Assistant::
	.string "Assistant$"

@ ---------------------------------------------------------------- texts (non-dialogue)

CF_P3_Text_GotTreecko::
	.string "Red reçoit Arcko !$"

CF_P3_Text_GotTorchic::
	.string "Red reçoit Poussifeu !$"

CF_P3_Text_GotMudkip::
	.string "Red reçoit Gobou !$"

CF_P3_Text_GotItems::
	.string "Red reçoit le Pokédex, 5 Poké Balls\n"
	.string "et 1 Baie Oran.$"

CF_P5_Text_GotShoes::
	.string "Red reçoit les Chaussures de Course !$"

CF_P6_Text_GotZigzagoon::
	.string "Red reçoit un Zigzaton de Galar !$"

CF_P6_Text_Defeated::
	.string "Le duel est fini !\n"
	.string "Alors, qui a gagné ?$"

@ ---------------------------------------------------------------- generated boxes (<= 208 px, 2 lines)

CF_T_000::
	.string "Nuit. Route 104, côte sud\n"
	.string "de Hoenn. Les ports sont fermés.$"

CF_T_001::
	.string "On y est. Pas de lumière,\n"
	.string "pas de bruit, d’accord ?$"

CF_T_002::
	.string "Si la brigade vous trouve, moi,\n"
	.string "je vous ai jamais vus.$"

CF_T_003::
	.string "Merci, monsieur Marco. Red,\n"
	.string "tu as tout ? Tes six Balls ?$"

CF_T_004::
	.string "Les gemmes que tu m’as rapportées\n"
	.string "stabilisent mon nœud. Tu te rappelles ?$"

CF_T_005::
	.string "Ma machine relie Kanto et Hoenn.\n"
	.string "Elle n’ouvre rien du tout.$"

CF_T_006::
	.string "Je dois le prouver à leur Ligue.\n"
	.string "Avant qu’ils nous accusent de tout.$"

CF_T_007::
	.string "Chut ! Regardez la mer…$"

CF_T_008::
	.string "Un cercle d’or s’ouvre au-dessus\n"
	.string "de l’eau. Il en tombe des formes.$"

CF_T_009::
	.string "Des Pokémon. Affolés, ils\n"
	.string "chargent la plage.$"

CF_T_010::
	.string "Des Pokémon de chez nous !\n"
	.string "Red, protège-nous !$"

CF_T_011::
	.string "D’autres arrivent. L’anneau ne\n"
	.string "se referme pas.$"

CF_T_012::
	.string "Ils fuient… Petit, t’as une\n"
	.string "sacrée équipe.$"

CF_T_013::
	.string "Le sable s’illumine sous les pieds\n"
	.string "de Red. Un second cercle.$"

CF_T_014::
	.string "Les Balls glissent de sa ceinture.\n"
	.string "Il ne peut rattraper qu’une chose.$"

CF_T_015::
	.string "Mon sac ! Le disque du nœud !\n"
	.string "Red !$"

CF_T_016::
	.string "Tendre la main vers…$"

CF_T_017::
	.string "Pikachu$"

CF_T_018::
	.string "Le sac de Ciléo$"

CF_T_019::
	.string "Pikachu saute. Red le saisit\n"
	.string "au vol. L’anneau avale le reste.$"

CF_T_020::
	.string "Pikachu a heurté les rochers.\n"
	.string "Il respire, mais ne bouge plus.$"

CF_T_021::
	.string "Mon disque… Tant pis. Il est\n"
	.string "vivant, c’est le principal.$"

CF_T_022::
	.string "Red attrape le sac. Pikachu\n"
	.string "bondit vers lui, trop tard.$"

CF_T_023::
	.string "Le cercle se ferme. Il ne reste\n"
	.string "qu’une plage vide.$"

CF_T_024::
	.string "Red… Je suis désolé. Ton\n"
	.string "équipe… Pikachu…$"

CF_T_025::
	.string "Venez chez moi, vite. La brigade\n"
	.string "fait sa ronde à l’aube.$"

CF_T_026::
	.string "Asseyez-vous. Y a du thé,\n"
	.string "et y a pas de questions.$"

CF_T_027::
	.string "Moi aussi, un anneau m’a pris\n"
	.string "quelqu’un. Piko, ma Goélise.$"

CF_T_028::
	.string "C’était il y a huit jours, sur le\n"
	.string "ponton. Un cercle d’or, et plus rien.$"

CF_T_029::
	.string "Je dois aller à Clémenti cette\n"
	.string "nuit. Me déclarer à leur QG.$"

CF_T_030::
	.string "Si j’attends, ils diront que les\n"
	.string "Kantonais se cachent.$"

CF_T_031::
	.string "Et toi, petit ? Tu restes ici,\n"
	.string "ou tu suis ton ami ?$"

CF_T_032::
	.string "Que fait Red ?$"

CF_T_033::
	.string "Rester$"

CF_T_034::
	.string "Suivre Ciléo$"

CF_T_035::
	.string "Bon choix. Tiens, la clochette\n"
	.string "de Piko. Garde-la pour moi.$"

CF_T_036::
	.string "Si tu croises un cercle d’or,\n"
	.string "écoute bien. Elle tintait toujours.$"

CF_T_037::
	.string "Alors j’y vais seul. On se\n"
	.string "retrouve à Clémenti.$"

CF_T_038::
	.string "Le professeur Seko, à Bourg-en-Vol,\n"
	.string "soigne les blessés.$"

CF_T_039::
	.string "Bêtes ou gens. Dis-lui que tu\n"
	.string "viens de ma part.$"

CF_T_040::
	.string "Une heure de marche plus tard,\n"
	.string "Bourg-en-Vol dort encore.$"

CF_T_041::
	.string "Merci. À deux, on aura l’air\n"
	.string "moins louches. Enfin, j’espère.$"

CF_T_042::
	.string "Le professeur Seko, à Bourg-en-Vol,\n"
	.string "soigne les blessés.$"

CF_T_043::
	.string "Bêtes ou gens. Dis-lui que tu\n"
	.string "viens de ma part.$"

CF_T_044::
	.string "Pas de traversée cette semaine.\n"
	.string "La brigade surveille la mer.$"

CF_T_045::
	.string "Halte. Couvre-feu. Vos noms,\n"
	.string "et ce que vous faites dehors.$"

CF_T_046::
	.string "Ciléo, ingénieur de Kanto.\n"
	.string "Je viens me déclarer.$"

CF_T_047::
	.string "Un Kantonais qui vient tout seul ?\n"
	.string "Ça, c’est nouveau. Passez.$"

CF_T_048::
	.string "Une heure de marche plus tard,\n"
	.string "Bourg-en-Vol dort encore.$"

CF_T_049::
	.string "Pikachu dort, une bande autour\n"
	.string "des côtes. Il respire doucement.$"

CF_T_050::
	.string "Un visiteur à cette heure ?\n"
	.string "Marco t’envoie, c’est ça ?$"

CF_T_051::
	.string "Je suis Seko. J’étudie où vivent\n"
	.string "les Pokémon. Où ils vivaient.$"

CF_T_052::
	.string "Ton équipe entière, aspirée ?\n"
	.string "Je suis désolé, petit.$"

CF_T_053::
	.string "Ton Pikachu… Pose-le là. Côtes\n"
	.string "fêlées. Il lui faut du repos.$"

CF_T_054::
	.string "Plusieurs semaines. Il reste\n"
	.string "ici, je m’en occupe.$"

CF_T_055::
	.string "Sans Pokémon, tu ne passeras\n"
	.string "pas la nuit. Pas avec ce qui rôde.$"

CF_T_056::
	.string "Ces trois-là sont nés à Hoenn.\n"
	.string "Choisis celui qui te ressemble.$"

CF_T_057::
	.string "Choisis un Pokémon$"

CF_T_058::
	.string "Arcko$"

CF_T_059::
	.string "Poussifeu$"

CF_T_060::
	.string "Gobou$"

CF_T_061::
	.string "Prends aussi ça. Et mon Pokédex :\n"
	.string "note tout ce que tu vois.$"

CF_T_062::
	.string "Surtout ce qui vient d’ailleurs.$"

CF_T_063::
	.string "Une question de méthode. Tu veux\n"
	.string "des combats durs, ou normaux ?$"

CF_T_064::
	.string "Difficulté$"

CF_T_065::
	.string "Normaux$"

CF_T_066::
	.string "Durs$"

CF_T_067::
	.string "Professeur ! Le QG du Rempart,\n"
	.string "au téléphone. C’est Norman.$"

CF_T_068::
	.string "Norman dirige le Rempart. Il veut\n"
	.string "savoir qui débarque la nuit.$"

CF_T_069::
	.string "Seko tend le combiné à Red.$"

CF_T_070::
	.string "Un étranger sans papiers sur ma\n"
	.string "côte. Votre nom.$"

CF_T_071::
	.string "Votre nom ?$"

CF_T_072::
	.string "Donner son nom$"

CF_T_073::
	.string "Rester anonyme$"

CF_T_074::
	.string "Red écrit son nom sur le registre.\n"
	.string "Seko le lit au téléphone.$"

CF_T_075::
	.string "Red. Le champion de Kanto.\n"
	.string "Bien.$"

CF_T_076::
	.string "Accréditation de crise, niveau un.\n"
	.string "Vous combattrez les hordes.$"

CF_T_077::
	.string "Un faux pas, et vous repartez\n"
	.string "en cale. Avec votre nom dessus.$"

CF_T_078::
	.string "Il ne dira rien. Mon fils l’appellera\n"
	.string "le Passeur, je parie.$"

CF_T_079::
	.string "Anonyme ? Alors accréditation\n"
	.string "provisoire. Sous garant.$"

CF_T_080::
	.string "Mon QG, demain matin. Sinon,\n"
	.string "la cale.$"

CF_T_081::
	.string "Ceci est arrivé pour toi par\n"
	.string "Passerelle. Ça vient de Kanto.$"

CF_T_082::
	.string "Une lettre du Prof. Chen :\n"
	.string "‘Envoie-moi tout. Avant Seko.’$"

CF_T_083::
	.string "La lettre ?$"

CF_T_084::
	.string "Montrer la lettre$"

CF_T_085::
	.string "La garder$"

CF_T_086::
	.string "‘Avant Seko’… Ce vieux renard\n"
	.string "de Chen.$"

CF_T_087::
	.string "Tant pis pour lui. Mon registre\n"
	.string "est à toi. Mon fils aussi.$"

CF_T_088::
	.string "Demain, Brice t’accompagne. Il\n"
	.string "connaît chaque barrage.$"

CF_T_089::
	.string "Red range la lettre. Seko fait\n"
	.string "semblant de ne rien voir.$"

CF_T_090::
	.string "Brice finira son recensement ici\n"
	.string "demain. Il te rejoindra plus tard.$"

CF_T_091::
	.string "Mon fils est encore dehors, sur\n"
	.string "la Route 101. Tu me le ramènes ?$"

CF_T_092::
	.string "Voilà, ton équipe est soignée.\n"
	.string "Reviens quand tu veux, petit.$"

CF_T_093::
	.string "Six… sept… Et un Piafabec.\n"
	.string "Non, deux !$"

CF_T_094::
	.string "Hé, vous trois ! Je vous recense,\n"
	.string "je vous mange pas !$"

CF_T_095::
	.string "Les arrivants grognent. Ils\n"
	.string "encerclent Brice.$"

CF_T_096::
	.string "Que fait Red ?$"

CF_T_097::
	.string "Intervenir$"

CF_T_098::
	.string "Rester et observer$"

CF_T_099::
	.string "Merci ! Tu es tombé du ciel ?\n"
	.string "Je suis Brice. Le fils de Seko.$"

CF_T_100::
	.string "Red ne bouge pas. Les arrivants\n"
	.string "fuient tous vers le même point.$"

CF_T_101::
	.string "Vers la plage, là où le ciel\n"
	.string "brillait une heure plus tôt.$"

CF_T_102::
	.string "Aïe ! Il m’a griffé… Tu aurais\n"
	.string "pu m’aider, toi !$"

CF_T_103::
	.string "…Attends. Ils fuient tous vers\n"
	.string "la mer. Je le note.$"

CF_T_104::
	.string "Tu dors chez nous ce soir.\n"
	.string "Maman a toujours un lit en trop.$"

CF_T_105::
	.string "Bonjour ! Brice m’a tout raconté.\n"
	.string "Enfin, sa version.$"

CF_T_106::
	.string "Tiens, des Chaussures de Course.\n"
	.string "Par ici, on court beaucoup.$"

CF_T_107::
	.string "Brice t’attend sur la Route 103.\n"
	.string "Allez, file !$"

CF_T_108::
	.string "Je pars devant, Route 103.\n"
	.string "Un duel d’essai, ça te dit ?$"

CF_T_109::
	.string "Celui qui regarde sans bouger !\n"
	.string "Voyons si tu sais te battre.$"

CF_T_110::
	.string "Le héros d’hier soir ! Voyons\n"
	.string "si tu es aussi bon de jour.$"

CF_T_111::
	.string "Joli ! Je note : Red, très fort,\n"
	.string "ne parle pas.$"

CF_T_112::
	.string "Ha ! Pas mal quand même. Je note :\n"
	.string "Red, à entraîner.$"

CF_T_113::
	.string "Un Zigzaton pas comme les autres\n"
	.string "sort des herbes. Il boite.$"

CF_T_114::
	.string "Noir et blanc… Un Zigzaton de\n"
	.string "Galar ! Il n’a rien à faire ici.$"

CF_T_115::
	.string "Brigade du Rempart. On ramasse\n"
	.string "les arrivants blessés. Écartez-vous.$"

CF_T_116::
	.string "Le Zigzaton de Galar$"

CF_T_117::
	.string "Le capturer$"

CF_T_118::
	.string "Le laisser$"

CF_T_119::
	.string "Hé ! C’est un arrivant. Vous devrez\n"
	.string "le déclarer au QG.$"

CF_T_120::
	.string "On le déclare ou pas ? …Moi,\n"
	.string "je n’ai rien vu.$"

CF_T_121::
	.string "Merci. Il sera soigné. Enfin…\n"
	.string "on verra.$"

CF_T_122::
	.string "Je note son numéro. Je veux savoir\n"
	.string "ce qu’il devient.$"

CF_T_123::
	.string "Mon père veut que je finisse ici.\n"
	.string "Je te rejoins à Mérouville !$"

CF_T_124::
	.string "Direction Clémenti. Le QG de Norman,\n"
	.string "c’est l’ancienne arène.$"

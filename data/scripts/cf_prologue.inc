@ Hack: Confluence demo prologue (SLICE_DEMO_CH0-1 P1-P6). Edit this file directly.
@ Visibility flags: set = hidden. State vars: VAR_ROUTE104_STATE (P1: 0 -> 3), VAR_BRINEY_HOUSE_STATE (P2: 0 -> 9),
@ VAR_PETALBURG_CITY_STATE (20 = D006 b mini-scene), VAR_BIRCH_LAB_STATE (P3: 0 -> 5), VAR_ROUTE101_STATE (P4: 2 -> 3),
@ VAR_LITTLEROOT_RIVAL_STATE (P5: 4 -> 6, P6: 6 -> 7).

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
	givemon SPECIES_PIKACHU, 62, ITEM_LIGHT_BALL, move1=MOVE_THUNDERBOLT, move2=MOVE_QUICK_ATTACK, move3=MOVE_IRON_TAIL, move4=MOVE_THUNDER
	givemon SPECIES_CHARIZARD, 64, move1=MOVE_FLAMETHROWER, move2=MOVE_AIR_SLASH, move3=MOVE_DRAGON_PULSE, move4=MOVE_FOCUS_BLAST
	givemon SPECIES_VENUSAUR, 64, move1=MOVE_LEAF_STORM, move2=MOVE_SLUDGE_BOMB, move3=MOVE_SLEEP_POWDER, move4=MOVE_SYNTHESIS
	givemon SPECIES_BLASTOISE, 64, move1=MOVE_HYDRO_PUMP, move2=MOVE_BLIZZARD, move3=MOVE_FLASH_CANNON, move4=MOVE_FOCUS_BLAST
	givemon SPECIES_SNORLAX, 63, move1=MOVE_BODY_SLAM, move2=MOVE_REST, move3=MOVE_SNORE, move4=MOVE_CRUNCH
	givemon SPECIES_LAPRAS, 62, move1=MOVE_SURF, move2=MOVE_ICE_BEAM, move3=MOVE_PSYCHIC, move4=MOVE_SING
	return

@ ---------------------------------------------------------------- P1: la plage (Route 104)

CF_P1_Beach::
	lockall
	call CF_GivePrologueTeam
	msgbox CF_T_000, MSGBOX_DEFAULT
	msgbox CF_T_001, MSGBOX_DEFAULT
	msgbox CF_T_002, MSGBOX_DEFAULT
	msgbox CF_T_003, MSGBOX_DEFAULT
	msgbox CF_T_004, MSGBOX_DEFAULT
	msgbox CF_T_005, MSGBOX_DEFAULT
	msgbox CF_T_006, MSGBOX_DEFAULT
	msgbox CF_T_007, MSGBOX_DEFAULT
	msgbox CF_T_008, MSGBOX_DEFAULT
	msgbox CF_T_009, MSGBOX_DEFAULT
	msgbox CF_T_010, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_CF_NO_WHITEOUT
	setwildbattle SPECIES_TAUROS, 42
	dowildbattle
	msgbox CF_T_011, MSGBOX_DEFAULT
	closemessage
	setwildbattle SPECIES_URSARING, 43
	dowildbattle
	setwildbattle SPECIES_GYARADOS, 45
	dowildbattle
	msgbox CF_T_012, MSGBOX_DEFAULT
	msgbox CF_T_013, MSGBOX_DEFAULT
	msgbox CF_T_014, MSGBOX_DEFAULT
	msgbox CF_T_015, MSGBOX_DEFAULT
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
	msgbox CF_T_019, MSGBOX_DEFAULT
	msgbox CF_T_020, MSGBOX_DEFAULT
	msgbox CF_T_021, MSGBOX_DEFAULT
	setdecision_once 1, DEC_A, CF_P1_Common
	setbits VAR_CF_WORLD, 14, 2, 1
	subaffinity VAR_CF_REP_I, 3
	goto CF_P1_Common

CF_P1_BagChoice::
	msgbox CF_T_022, MSGBOX_DEFAULT
	msgbox CF_T_023, MSGBOX_DEFAULT
	msgbox CF_T_024, MSGBOX_DEFAULT
	setdecision_once 1, DEC_B, CF_P1_Common
	setflag FLAG_CF_DOS_JOURNAL_NOEUD
	addaffinity VAR_CF_REP_I, 5
	subaffinity VAR_CF_REP_C, 3
	goto CF_P1_Common

CF_P1_Common::
	clearparty
	clearflag FLAG_CF_NO_WHITEOUT
	msgbox CF_T_025, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_CF_VIS_00
	setflag FLAG_CF_VIS_01
	setvar VAR_ROUTE104_STATE, 3
	fadescreen FADE_TO_BLACK
	warp MAP_ROUTE104_MR_BRINEYS_HOUSE, 5, 7
	waitstate
	end

@ ---------------------------------------------------------------- P2: chez M. Marco

CF_P2_ShowCeleo::
	clearflag FLAG_CF_VIS_02
	return

CF_P2_Home::
	lockall
	msgbox CF_T_026, MSGBOX_DEFAULT
	msgbox CF_T_027, MSGBOX_DEFAULT
	msgbox CF_T_028, MSGBOX_DEFAULT
	msgbox CF_T_029, MSGBOX_DEFAULT
	msgbox CF_T_030, MSGBOX_DEFAULT
	msgbox CF_T_031, MSGBOX_DEFAULT
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
	msgbox CF_T_035, MSGBOX_DEFAULT
	msgbox CF_T_036, MSGBOX_DEFAULT
	msgbox CF_T_037, MSGBOX_DEFAULT
	setdecision_once 6, DEC_A, CF_P2_StayEnd
	setflag FLAG_CF_DOS_CLOCHETTE_PIKO
	setflag FLAG_CF_MARCO_ALLIE
	subaffinity VAR_CF_REP_L, 2
CF_P2_StayEnd::
	msgbox CF_T_038, MSGBOX_DEFAULT
	msgbox CF_T_039, MSGBOX_DEFAULT
	msgbox CF_T_040, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_CF_VIS_02
	setvar VAR_BRINEY_HOUSE_STATE, 9
	fadescreen FADE_TO_BLACK
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 11
	waitstate
	end

CF_P2_Follow::
	msgbox CF_T_041, MSGBOX_DEFAULT
	setdecision_once 6, DEC_B, CF_P2_FollowEnd
	addaffinity VAR_CF_REP_I, 2
CF_P2_FollowEnd::
	msgbox CF_T_042, MSGBOX_DEFAULT
	msgbox CF_T_043, MSGBOX_DEFAULT
	closemessage
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
	msgbox CF_T_044, MSGBOX_DEFAULT
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
	msgbox CF_T_045, MSGBOX_DEFAULT
	msgbox CF_T_046, MSGBOX_DEFAULT
	msgbox CF_T_047, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_CF_VIS_40
	setflag FLAG_CF_VIS_41
	setvar VAR_PETALBURG_CITY_STATE, 1
	msgbox CF_T_048, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 11
	waitstate
	end

@ ---------------------------------------------------------------- P3: le labo de Seko

CF_Lab_ShowPikachu::
	getbits VAR_CF_WORLD, 14, 2
	goto_if_eq VAR_RESULT, 1, CF_Lab_ShowPikachuYes
	return

CF_Lab_ShowPikachuYes::
	clearflag FLAG_CF_VIS_05
	return

CF_Lab_HurtPikachu::
	lock
	msgbox CF_T_049, MSGBOX_DEFAULT
	release
	end

CF_P3_Lab::
	lockall
	msgbox CF_T_050, MSGBOX_DEFAULT
	msgbox CF_T_051, MSGBOX_DEFAULT
	getbits VAR_CF_WORLD, 14, 2
	goto_if_eq VAR_RESULT, 1, CF_P3_PikachuHurt
	msgbox CF_T_052, MSGBOX_DEFAULT
	goto CF_P3_Starter

CF_P3_PikachuHurt::
	msgbox CF_T_053, MSGBOX_DEFAULT
	msgbox CF_T_054, MSGBOX_DEFAULT
	goto CF_P3_Starter

CF_P3_Starter::
	msgbox CF_T_055, MSGBOX_DEFAULT
	msgbox CF_T_056, MSGBOX_DEFAULT
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
	givemon SPECIES_TREECKO, 5
	setvar VAR_STARTER_MON, 0
	setdecision_once 4, DEC_A, CF_P3_StarterGot
	msgbox CF_P3_Text_GotTreecko, MSGBOX_DEFAULT
	goto CF_P3_StarterGot

CF_P3_Torchic::
	givemon SPECIES_TORCHIC, 5
	setvar VAR_STARTER_MON, 1
	setdecision_once 4, DEC_B, CF_P3_StarterGot
	msgbox CF_P3_Text_GotTorchic, MSGBOX_DEFAULT
	goto CF_P3_StarterGot

CF_P3_Mudkip::
	givemon SPECIES_MUDKIP, 5
	setvar VAR_STARTER_MON, 2
	setdecision_once 4, DEC_C, CF_P3_StarterGot
	msgbox CF_P3_Text_GotMudkip, MSGBOX_DEFAULT
	goto CF_P3_StarterGot

CF_P3_StarterGot::
	msgbox CF_T_061, MSGBOX_DEFAULT
	msgbox CF_T_062, MSGBOX_DEFAULT
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	additem ITEM_POKE_BALL, 5
	additem ITEM_ORAN_BERRY, 1
	playfanfare MUS_OBTAIN_ITEM
	msgbox CF_P3_Text_GotItems, MSGBOX_DEFAULT
	waitfanfare
	msgbox CF_T_063, MSGBOX_DEFAULT
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
	msgbox CF_T_067, MSGBOX_DEFAULT
	msgbox CF_T_068, MSGBOX_DEFAULT
	msgbox CF_T_069, MSGBOX_DEFAULT
	msgbox CF_T_070, MSGBOX_DEFAULT
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
	msgbox CF_T_074, MSGBOX_DEFAULT
	msgbox CF_T_075, MSGBOX_DEFAULT
	msgbox CF_T_076, MSGBOX_DEFAULT
	msgbox CF_T_077, MSGBOX_DEFAULT
	setdecision_once 2, DEC_A, CF_P3_Letter
	setbits VAR_CF_WORLD, 0, 2, 2
	addaffinity VAR_CF_REP_L, 3
	addaffinity VAR_CF_RK, 3
	goto CF_P3_Letter

CF_P3_Anonymous::
	msgbox CF_T_078, MSGBOX_DEFAULT
	msgbox CF_T_079, MSGBOX_DEFAULT
	msgbox CF_T_080, MSGBOX_DEFAULT
	setdecision_once 2, DEC_B, CF_P3_Letter
	setbits VAR_CF_WORLD, 0, 2, 0
	subaffinity VAR_CF_REP_L, 3
	addaffinity VAR_CF_BR, 2
	goto CF_P3_Letter

CF_P3_Letter::
	msgbox CF_T_081, MSGBOX_DEFAULT
	msgbox CF_T_082, MSGBOX_DEFAULT
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
	msgbox CF_T_086, MSGBOX_DEFAULT
	msgbox CF_T_087, MSGBOX_DEFAULT
	msgbox CF_T_088, MSGBOX_DEFAULT
	setdecision_once 5, DEC_A, CF_P3_End
	setflag FLAG_CF_CHEN_LETTRE_MONTREE
	addaffinity VAR_CF_BR, 2
	goto CF_P3_End

CF_P3_LetterKept::
	msgbox CF_T_089, MSGBOX_DEFAULT
	msgbox CF_T_090, MSGBOX_DEFAULT
	setdecision_once 5, DEC_B, CF_P3_End
	subaffinity VAR_CF_BR, 2
	goto CF_P3_End

CF_P3_End::
	msgbox CF_T_091, MSGBOX_DEFAULT
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
	msgbox CF_T_092, MSGBOX_DEFAULT
	release
	end

@ ---------------------------------------------------------------- P4: la ronde de Brice (Route 101)

CF_P4_Show::
	clearflag FLAG_CF_VIS_06
	clearflag FLAG_CF_VIS_08
	return

CF_Route101_BriceRound::
	lockall
	msgbox CF_T_093, MSGBOX_DEFAULT
	msgbox CF_T_094, MSGBOX_DEFAULT
	msgbox CF_T_095, MSGBOX_DEFAULT
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
	removeobject LOCALID_CF_R101_A
	removeobject LOCALID_CF_R101_B
	removeobject LOCALID_CF_R101_C
	msgbox CF_T_099, MSGBOX_DEFAULT
	setdecision_once 3, DEC_A, CF_P4_Common
	addaffinity VAR_CF_BR, 3
	subaffinity VAR_CF_HO, 1
	setvar VAR_0x8004, 0
	call CF_IncBV
	goto CF_P4_Common

CF_P4_Watch::
	msgbox CF_T_100, MSGBOX_DEFAULT
	msgbox CF_T_101, MSGBOX_DEFAULT
	closemessage
	removeobject LOCALID_CF_R101_A
	removeobject LOCALID_CF_R101_B
	removeobject LOCALID_CF_R101_C
	msgbox CF_T_102, MSGBOX_DEFAULT
	msgbox CF_T_103, MSGBOX_DEFAULT
	setdecision_once 3, DEC_B, CF_P4_Common
	subaffinity VAR_CF_BR, 3
	setvar VAR_0x8004, 8
	call CF_IncBV
	goto CF_P4_Common

CF_P4_Common::
	msgbox CF_T_104, MSGBOX_DEFAULT
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
	msgbox CF_T_105, MSGBOX_DEFAULT
	msgbox CF_T_106, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_RUNNING_SHOES
	playfanfare MUS_OBTAIN_ITEM
	msgbox CF_P5_Text_GotShoes, MSGBOX_DEFAULT
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
	msgbox CF_T_107, MSGBOX_DEFAULT
	release
	end

CF_P5_ExitTrigger::
	lockall
	call_if_unset FLAG_RECEIVED_RUNNING_SHOES, CF_P5_Mom
	msgbox CF_T_108, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LITTLEROOT_RIVAL_STATE, 6
	releaseall
	end

@ ---------------------------------------------------------------- P6: Route 103, duel et Zigzaton de Galar

CF_P6_ShowBrice::
	clearflag FLAG_CF_VIS_07
	return

CF_Route103_BriceDuel::
	lockall
	applymovement LOCALID_ROUTE103_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	checkdecision 3
	goto_if_eq VAR_RESULT, DEC_A, CF_P6_IntroA
	msgbox CF_T_109, MSGBOX_DEFAULT
	goto CF_P6_Battle

CF_P6_IntroA::
	msgbox CF_T_110, MSGBOX_DEFAULT
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
	msgbox CF_T_111, MSGBOX_DEFAULT
	goto CF_P6_AfterDuel

CF_P6_Lost::
	msgbox CF_T_112, MSGBOX_DEFAULT
	goto CF_P6_AfterDuel

CF_P6_AfterDuel::
	clearflag FLAG_CF_NO_WHITEOUT
	special HealPlayerParty
	closemessage
	clearflag FLAG_CF_VIS_16
	clearflag FLAG_CF_VIS_09
	addobject LOCALID_CF_R103_ZIGZAGOON
	addobject LOCALID_CF_R103_POLICE
	delay 20
	msgbox CF_T_113, MSGBOX_DEFAULT
	msgbox CF_T_114, MSGBOX_DEFAULT
	msgbox CF_T_115, MSGBOX_DEFAULT
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
	givemon SPECIES_ZIGZAGOON_GALAR, 5
	playfanfare MUS_OBTAIN_ITEM
	msgbox CF_P6_Text_GotZigzagoon, MSGBOX_DEFAULT
	waitfanfare
	removeobject LOCALID_CF_R103_ZIGZAGOON
	msgbox CF_T_119, MSGBOX_DEFAULT
	msgbox CF_T_120, MSGBOX_DEFAULT
	setdecision_once 7, DEC_A, CF_P6_End
	subaffinity VAR_CF_REP_L, 2
	setvar VAR_0x8004, 4
	call CF_IncBV
	goto CF_P6_End

CF_P6_Leave::
	removeobject LOCALID_CF_R103_ZIGZAGOON
	msgbox CF_T_121, MSGBOX_DEFAULT
	msgbox CF_T_122, MSGBOX_DEFAULT
	setdecision_once 7, DEC_B, CF_P6_End
	addaffinity VAR_CF_REP_L, 2
	setvar VAR_0x8004, 0
	call CF_IncBV
	goto CF_P6_End

CF_P6_End::
	closemessage
	removeobject LOCALID_CF_R103_POLICE
	setflag FLAG_CF_VIS_16
	setflag FLAG_CF_VIS_09
	setvar VAR_CF_CHAPTER, 1
	clearflag FLAG_CF_VIS_39
	setvar VAR_OLDALE_TOWN_STATE, 1
	setvar VAR_LITTLEROOT_RIVAL_STATE, 7
	checkdecision 5
	goto_if_eq VAR_RESULT, DEC_A, CF_P6_BriceFollows
	msgbox CF_T_123, MSGBOX_DEFAULT
	closemessage
	removeobject LOCALID_ROUTE103_RIVAL
	setflag FLAG_CF_VIS_07
	releaseall
	end

CF_P6_BriceFollows::
	msgbox CF_T_124, MSGBOX_DEFAULT
	closemessage
	removeobject LOCALID_ROUTE103_RIVAL
	setflag FLAG_CF_VIS_07
	createfollowernpc OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL, FNPC_ALL_LAND
	releaseall
	end

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

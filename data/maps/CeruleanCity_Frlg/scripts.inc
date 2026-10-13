CeruleanCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_OnTransition
	.byte 0

CeruleanCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_CERULEAN_CITY
	call_if_unset FLAG_GOT_SS_TICKET, CeruleanCity_EventScript_BlockExits
	end

CeruleanCity_EventScript_BlockExits::
	setobjectxyperm LOCALID_CERULEAN_POLICEMAN, 30, 12
	setobjectxyperm LOCALID_CERULEAN_SLOWBRO, 26, 31
	setobjectxyperm LOCALID_CERULEAN_LASS, 27, 31
	return

CeruleanCity_EventScript_RivalTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto CeruleanCity_EventScript_Rival
	end

CeruleanCity_EventScript_RivalTriggerMid::
	lockall
	setvar VAR_TEMP_1, 1
	setobjectxyperm LOCALID_CERULEAN_RIVAL, 23, 0
	goto CeruleanCity_EventScript_Rival
	end

CeruleanCity_EventScript_RivalTriggerRight::
	lockall
	setvar VAR_TEMP_1, 2
	setobjectxyperm LOCALID_CERULEAN_RIVAL, 24, 0
	goto CeruleanCity_EventScript_Rival
	end

CeruleanCity_EventScript_Rival::
	textcolor NPC_TEXT_COLOR_MALE
	setvar VAR_MAP_SCENE_ROUTE22, 2
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	addobject LOCALID_CERULEAN_RIVAL
	applymovement LOCALID_CERULEAN_RIVAL, CeruleanCity_Movement_RivalEnter
	waitmovement 0
	msgbox CeruleanCity_Text_RivalIntro
	setvar VAR_LAST_TALKED, LOCALID_CERULEAN_RIVAL
	call_if_eq VAR_STARTER_MON, 2, CeruleanCity_EventScript_RivalSquirtle
	call_if_eq VAR_STARTER_MON, 1, CeruleanCity_EventScript_RivalBulbasaur
	call_if_eq VAR_STARTER_MON, 0, CeruleanCity_EventScript_RivalCharmander
	famechecker FAMECHECKER_BILL, 0
	msgbox CeruleanCity_Text_RivalPostBattle
	closemessage
	playbgm MUS_RG_RIVAL_EXIT, 0
	call_if_eq VAR_TEMP_1, 0, CeruleanCity_EventScript_RivalStartExit
	call_if_eq VAR_TEMP_1, 1, CeruleanCity_EventScript_RivalStartExit
	call_if_eq VAR_TEMP_1, 2, CeruleanCity_EventScript_RivalStartExitRight
	msgbox CeruleanCity_Text_OhRightLittlePresentAsFavor
	setvar VAR_MAP_SCENE_CERULEAN_CITY_RIVAL, 1
	setflag FLAG_GOT_FAME_CHECKER
	giveitem ITEM_FAME_CHECKER
	msgbox CeruleanCity_Text_ExplainFameCheckerSmellYa
	closemessage
	applymovement LOCALID_CERULEAN_RIVAL, CeruleanCity_Movement_RivalExit
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_CERULEAN_RIVAL
	releaseall
	end

CeruleanCity_EventScript_RivalSquirtle::
	trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_SQUIRTLE, CeruleanCity_Text_RivalDefeat
	return

CeruleanCity_EventScript_RivalBulbasaur::
	trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_BULBASAUR, CeruleanCity_Text_RivalDefeat
	return

CeruleanCity_EventScript_RivalCharmander::
	trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_CHARMANDER, CeruleanCity_Text_RivalDefeat
	return

CeruleanCity_EventScript_RivalStartExit::
	applymovement LOCALID_PLAYER, CeruleanCity_Movement_PlayerWatchRivalExit
	applymovement LOCALID_CERULEAN_RIVAL, CeruleanCity_Movement_RivalStartExit
	waitmovement 0
	return

CeruleanCity_EventScript_RivalStartExitRight::
	applymovement LOCALID_PLAYER, CeruleanCity_Movement_PlayerWatchRivalExitRight
	applymovement LOCALID_CERULEAN_RIVAL, CeruleanCity_Movement_RivalStartExitRight
	waitmovement 0
	return

CeruleanCity_Movement_PlayerWatchRivalExit::
	delay_16
	delay_8
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_down
	step_end

CeruleanCity_Movement_PlayerWatchRivalExitRight::
	delay_16
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

CeruleanCity_Movement_RivalEnter::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CeruleanCity_Movement_RivalStartExit::
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_16
	delay_16
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CeruleanCity_Movement_RivalStartExitRight::
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_16
	delay_16
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

CeruleanCity_Movement_RivalExit::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CeruleanCity_EventScript_Grunt::
	lock
	faceplayer
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_EventScript_GruntDefeated
	message CeruleanCity_Text_GruntIntro
	waitmessage
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	waitbuttonpress
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_Text_GruntDefeat
	setvar VAR_MAP_SCENE_CERULEAN_CITY_ROCKET, 1
	goto CeruleanCity_EventScript_GruntDefeated
	end

CeruleanCity_EventScript_GruntDefeated::
	msgbox CeruleanCity_Text_OkayIllReturnStolenTM
	checkitemspace ITEM_TM28
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_EventScript_NoRoomForTM28
	giveitem_msg CeruleanCity_Text_RecoveredTM28FromGrunt, ITEM_TM28
	msgbox CeruleanCity_Text_BetterGetMovingBye
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_CERULEAN_GRUNT
	fadescreenswapbuffers FADE_FROM_BLACK
	setflag FLAG_GOT_TM28_FROM_ROCKET
	release
	end

CeruleanCity_EventScript_NoRoomForTM28::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox CeruleanCity_Text_MakeRoomForThisCantRun
	release
	end

CeruleanCity_EventScript_GruntTriggerTop::
	lockall
	setvar VAR_TEMP_1, 0
	applymovement LOCALID_CERULEAN_GRUNT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	goto CeruleanCity_EventScript_GruntTrigger
	end

CeruleanCity_EventScript_GruntTriggerBottom::
	lockall
	setvar VAR_TEMP_1, 1
	applymovement LOCALID_CERULEAN_GRUNT, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	goto CeruleanCity_EventScript_GruntTrigger
	end

CeruleanCity_EventScript_GruntTrigger::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox CeruleanCity_Text_GruntIntro
	setvar VAR_LAST_TALKED, LOCALID_CERULEAN_GRUNT
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_5, CeruleanCity_Text_GruntDefeat
	setvar VAR_MAP_SCENE_CERULEAN_CITY_ROCKET, 1
	goto CeruleanCity_EventScript_GruntDefeated
	end

CeruleanCity_EventScript_Policeman::
	lock
	faceplayer
	msgbox CeruleanCity_Text_PeopleHereWereRobbed
	closemessage
	applymovement LOCALID_CERULEAN_POLICEMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeruleanCity_EventScript_LittleBoy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SS_TICKET, CeruleanCity_EventScript_LittleBoySlowbroMoved
	msgbox CeruleanCity_Text_IfSlowbroWasntThereCouldCutTree
	release
	end

CeruleanCity_EventScript_LittleBoySlowbroMoved::
	msgbox CeruleanCity_Text_YouCanCutDownSmallTrees
	release
	end

CeruleanCity_EventScript_BaldingMan::
	msgbox CeruleanCity_Text_PokemonEncyclopediaAmusing, MSGBOX_NPC
	end

CeruleanCity_EventScript_Youngster::
	msgbox CeruleanCity_Text_TrainerLifeIsToughIsntIt, MSGBOX_NPC
	end

CeruleanCity_EventScript_CeruleanCaveGuard::
	msgbox CeruleanCity_Text_ThisIsCeruleanCave, MSGBOX_NPC
	end

CeruleanCity_EventScript_Woman::
	lock
	faceplayer
	msgbox CeruleanCity_Text_WantBrightRedBicycle
	closemessage
	applymovement LOCALID_CERULEAN_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeruleanCity_EventScript_Lass::
	lock
	random 3
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, CeruleanCity_EventScript_SlowbroCommand1
	call_if_eq VAR_0x8008, 1, CeruleanCity_EventScript_SlowbroCommand2
	call_if_eq VAR_0x8008, 2, CeruleanCity_EventScript_SlowbroCommand3
	waitmessage
	delay 40
	playse SE_PIN
	applymovement LOCALID_CERULEAN_SLOWBRO, Common_Movement_QuestionMark
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 0, CeruleanCity_EventScript_SlowbroFailed1
	call_if_eq VAR_0x8008, 1, CeruleanCity_EventScript_SlowbroFailed2
	call_if_eq VAR_0x8008, 2, CeruleanCity_EventScript_SlowbroFailed3
	release
	end

CeruleanCity_EventScript_SlowbroCommand1::
	message CeruleanCity_Text_SlowbroUseSonicboom
	return

CeruleanCity_EventScript_SlowbroCommand2::
	message CeruleanCity_Text_SlowbroPunch
	return

CeruleanCity_EventScript_SlowbroCommand3::
	message CeruleanCity_Text_SlowbroWithdraw
	return

CeruleanCity_EventScript_SlowbroFailed1::
	msgbox CeruleanCity_Text_SlowbroPayAttention
	return

CeruleanCity_EventScript_SlowbroFailed2::
	msgbox CeruleanCity_Text_NoYouBlewItAgain
	return

CeruleanCity_EventScript_SlowbroFailed3::
	msgbox CeruleanCity_Text_HardToControlMonsObedience
	return

CeruleanCity_EventScript_Slowbro::
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	call_if_eq VAR_0x8008, 0, CeruleanCity_EventScript_SlowbroText1
	call_if_eq VAR_0x8008, 1, CeruleanCity_EventScript_SlowbroText2
	call_if_eq VAR_0x8008, 2, CeruleanCity_EventScript_SlowbroText3
	call_if_eq VAR_0x8008, 3, CeruleanCity_EventScript_SlowbroText4
	release
	end

CeruleanCity_EventScript_SlowbroText1::
	msgbox CeruleanCity_Text_SlowbroTookSnooze
	return

CeruleanCity_EventScript_SlowbroText2::
	msgbox CeruleanCity_Text_SlowbroLoafingAround
	return

CeruleanCity_EventScript_SlowbroText3::
	msgbox CeruleanCity_Text_SlowbroTurnedAway
	return

CeruleanCity_EventScript_SlowbroText4::
	msgbox CeruleanCity_Text_SlowbroIgnoredOrders
	return

CeruleanCity_EventScript_CitySign::
	msgbox CeruleanCity_Text_CitySign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_TrainerTips::
	msgbox CeruleanCity_Text_TrainerTipsHeldItems, MSGBOX_SIGN
	end

CeruleanCity_EventScript_BikeShopSign::
	msgbox CeruleanCity_Text_BikeShopSign, MSGBOX_SIGN
	end

CeruleanCity_EventScript_GymSign::
	lockall
	famechecker FAMECHECKER_MISTY, 0
	msgbox CeruleanCity_Text_GymSign
	releaseall
	end

CeruleanCity_Text_RivalIntro::
	.string "{RIVAL}: Yo! {PLAYER}!\p"
	.string "Alors tu t'en sors?\p"
	.string "Moi c'est l'pied! J'ai attrapé plein\n"
	.string "de POKéMON super puissants!\p"
	.string "Fais-moi voir ce que t'as\n"
	.string "attrapé, {PLAYER}!$"

CeruleanCity_Text_RivalDefeat::
	.string "Houlà!\n"
	.string "Calmos!\l"
	.string "T'as gagné, OK!$"

CeruleanCity_Text_RivalPostBattle::
	.string "{RIVAL}: Hé! T'sais quoi?\p"
	.string "J'suis allé chez LEO et y m'a\n"
	.string "montré ses POKéMON rares!\p"
	.string "Ça m'a rajouté plein d'pages à\n"
	.string "mon POKéDEX!\p"
	.string "Tout l'monde sait que LEO est\n"
	.string "un POKéMANIAC!\p"
	.string "Il a même inventé le stockage des\n"
	.string "POKéMON sur PC!\p"
	.string "T'as qu'à aller l'voir!\p"
	.string "Bon, je trace.\n"
	.string "Tchao!$"

CeruleanCity_Text_OhRightLittlePresentAsFavor::
	.string "Ouais, c'est ça…\p"
	.string "J'ai les boules pour toi. J'te jure,\n"
	.string "t'es toujours derrière moi.\p"
	.string "Bon, j'vais te donner un cadeau,\n"
	.string "mais c'est une faveur.$"

CeruleanCity_Text_ExplainFameCheckerSmellYa::
	.string "C'est parfait pour une pipelette\n"
	.string "comme toi.\p"
	.string "J'en ai pas besoin parce que\n"
	.string "j'en ai rien à faire des autres.\p"
	.string "Allez, j'suis plus là,\n"
	.string "tchao!$"

CeruleanCity_Text_GruntIntro::
	.string "Holà!\n"
	.string "C'est pas chez toi, ici…\p"
	.string "Quoi? Moi?\p"
	.string "J'suis innocent! Hein? Quoi?\n"
	.string "Tu m'crois pas? Tu m'cherches?$"

CeruleanCity_Text_GruntDefeat::
	.string "SBIRE: Stop!\n"
	.string "J'me rends! J'fais pas le poids!$"

CeruleanCity_Text_OkayIllReturnStolenTM::
	.string "OK! Voilà la CT qu'j'ai volée!$"

CeruleanCity_Text_RecoveredTM28FromGrunt::
	.string "{PLAYER} récupère\n"
	.string "CT28!$"

CeruleanCity_Text_BetterGetMovingBye::
	.string "J'décampe…\n"
	.string "Bye bye!$"

CeruleanCity_Text_MakeRoomForThisCantRun::
	.string "Tu dois faire de la place\n"
	.string "si tu veux que je te la donne!$"

CeruleanCity_Text_TrainerLifeIsToughIsntIt::
	.string "T'es un DRESSEUR aussi?\p"
	.string "Capturer… Collectionner…\n"
	.string "Combattre… Dur, hein?$"

CeruleanCity_Text_YouCanCutDownSmallTrees::
	.string "Les POKéMON peuvent couper des\n"
	.string "petits buissons avec COUPE.\p"
	.string "Même le petit arbre devant la\n"
	.string "boutique peut être coupé.\p"
	.string "Mais il doit bien y avoir un autre\n"
	.string "moyen de passer.$"

CeruleanCity_Text_IfSlowbroWasntThereCouldCutTree::
	.string "Si ce FLAGADOSS n'était pas là,\n"
	.string "tu pourrais couper ces arbustes.\p"
	.string "Comme ça, tu pourrais passer\n"
	.string "de l'autre côté.\p"
	.string "Mais il doit bien y avoir un autre\n"
	.string "moyen de passer.$"

CeruleanCity_Text_PokemonEncyclopediaAmusing::
	.string "Tu fais une encyclopédie sur les\n"
	.string "POKéMON? Pas mal.$"

CeruleanCity_Text_PeopleHereWereRobbed::
	.string "Ces pauvres gens ont été volés.\p"
	.string "L'odieuse TEAM ROCKET est\n"
	.string "derrière tout ça. C'est sûr!\p"
	.string "Même les forces de police ont du\n"
	.string "mal à lutter!$"

CeruleanCity_Text_SlowbroUseSonicboom::
	.string "Allez! FLAGADOSS!\n"
	.string "Attaque! Attaque!$"

CeruleanCity_Text_SlowbroPayAttention::
	.string "Allez, FLAGADOSS, fais\n"
	.string "un peu attention.$"

CeruleanCity_Text_SlowbroPunch::
	.string "FLAGADOSS, cogne!$"

CeruleanCity_Text_NoYouBlewItAgain::
	.string "Mais non!\n"
	.string "Tu fais n'importe quoi!$"

CeruleanCity_Text_SlowbroWithdraw::
	.string "FLAGADOSS, REPLI!$"

CeruleanCity_Text_HardToControlMonsObedience::
	.string "Non! Pas ça! Pfff…\n"
	.string "C'est dur de contrôler un POKéMON!\p"
	.string "Seuls les bons DRESSEURS se font\n"
	.string "obéir de leurs POKéMON!$"

CeruleanCity_Text_SlowbroTookSnooze::
	.string "FLAGADOSS pionce comme une masse.$"

CeruleanCity_Text_SlowbroLoafingAround::
	.string "FLAGADOSS flâne…$"

CeruleanCity_Text_SlowbroTurnedAway::
	.string "FLAGADOSS se balade…$"

CeruleanCity_Text_SlowbroIgnoredOrders::
	.string "FLAGADOSS ignore les ordres…$"

CeruleanCity_Text_WantBrightRedBicycle::
	.string "Je veux une jolie bicyclette!\p"
	.string "Je la veux toute rouge!$"

CeruleanCity_Text_ThisIsCeruleanCave::
	.string "Des POKéMON trop puissants vivent\n"
	.string "ici, dans la CAVE AZUREE!\p"
	.string "Seuls les DRESSEURS spéciaux\n"
	.string "ont le droit d'y pénétrer.\p"
	.string "Il te faudra tout d'abord devenir\n"
	.string "le MAITRE de la LIGUE\p"
	.string "POKéMON, mais aussi\n"
	.string "avoir réussi un excellent parcours.$"

CeruleanCity_Text_CitySign::
	.string "AZURIA\n"
	.string "Baignée par une aura d'un bleu\l"
	.string "mystérieux$"

CeruleanCity_Text_TrainerTipsHeldItems::
	.string "ASTUCE\p"
	.string "Les POKéMON peuvent porter\n"
	.string "des objets.\p"
	.string "Certains objets portés peuvent\n"
	.string "même être utilisés en combat.$"

CeruleanCity_Text_BikeShopSign::
	.string "Plus vite que le vent, plus vite\n"
	.string "dans les villes!\p"
	.string "… CYCLES A GOGO$"

CeruleanCity_Text_GymSign::
	.string "ARENE POKéMON d'AZURIA\n"
	.string "CHAMPION: ONDINE\l"
	.string "La sirène en shorts.$"


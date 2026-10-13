SaffronCity_Dojo_Frlg_MapScripts::
	.byte 0

SaffronCity_Dojo_EventScript_TriggerMasterBattleLeft::
	lockall
	setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
	applymovement LOCALID_KARATE_MASTER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	releaseall
	end

SaffronCity_Dojo_EventScript_TriggerMasterBattleRight::
	lockall
	setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
	applymovement LOCALID_KARATE_MASTER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	releaseall
	end

SaffronCity_Dojo_EventScript_HitmonleeBall::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HITMON_FROM_DOJO, SaffronCity_Dojo_EventScript_AlreadyGotHitmon
	showmonpic SPECIES_HITMONLEE, 10, 3
	setvar VAR_TEMP_1, SPECIES_HITMONLEE
	applymovement LOCALID_KARATE_MASTER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox SaffronCity_Dojo_Text_YouWantHitmonlee, MSGBOX_YESNO
	call EventScript_RestorePrevTextColor
	goto_if_eq VAR_RESULT, YES, SaffronCity_Dojo_EventScript_GiveHitmon
	hidemonpic
	release
	end

SaffronCity_Dojo_EventScript_AlreadyGotHitmon::
	msgbox SaffronCity_Dojo_Text_BetterNotGetGreedy
	release
	end

SaffronCity_Dojo_EventScript_HitmonchanBall::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HITMON_FROM_DOJO, SaffronCity_Dojo_EventScript_AlreadyGotHitmon
	showmonpic SPECIES_HITMONCHAN, 10, 3
	setvar VAR_TEMP_1, SPECIES_HITMONCHAN
	applymovement LOCALID_KARATE_MASTER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox SaffronCity_Dojo_Text_YouWantHitmonchan, MSGBOX_YESNO
	call EventScript_RestorePrevTextColor
	goto_if_eq VAR_RESULT, YES, SaffronCity_Dojo_EventScript_GiveHitmon
	hidemonpic
	release
	end

SaffronCity_Dojo_EventScript_GiveHitmon::
	hidemonpic
	givemon VAR_TEMP_1, 25
	goto_if_eq VAR_RESULT, 0, SaffronCity_Dojo_EventScript_ReceivedHitmonParty
	goto_if_eq VAR_RESULT, 1, SaffronCity_Dojo_EventScript_ReceivedHitmonPC
	goto_if_eq VAR_RESULT, 2, Common_EventScript_NoMoreRoomForPokemon
	release
	end

SaffronCity_Dojo_EventScript_ReceivedHitmonParty::
	removeobject VAR_LAST_TALKED
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	playfanfare MUS_LEVEL_UP
	message SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster
	waitmessage
	waitfanfare
	setflag FLAG_GOT_HITMON_FROM_DOJO
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_EndGiveMon
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto SaffronCity_Dojo_EventScript_EndGiveMon
	end

SaffronCity_Dojo_EventScript_ReceivedHitmonPC::
	removeobject VAR_LAST_TALKED
	bufferspeciesname STR_VAR_1, VAR_TEMP_1
	playfanfare MUS_LEVEL_UP
	message SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster
	waitmessage
	waitfanfare
	setflag FLAG_GOT_HITMON_FROM_DOJO
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SaffronCity_Dojo_EventScript_TransferredHitmonToPC
	call Common_EventScript_NameReceivedBoxMon
	goto SaffronCity_Dojo_EventScript_TransferredHitmonToPC
	end

SaffronCity_Dojo_EventScript_TransferredHitmonToPC::
	call Common_EventScript_TransferredToPC
	goto SaffronCity_Dojo_EventScript_EndGiveMon
	end

SaffronCity_Dojo_EventScript_EndGiveMon::
	release
	end

SaffronCity_Dojo_EventScript_Statue::
	msgbox SaffronCity_Dojo_Text_FightingDojo, MSGBOX_SIGN
	end

SaffronCity_Dojo_EventScript_LeftScroll::
	msgbox SaffronCity_Dojo_Text_EnemiesOnEverySide, MSGBOX_SIGN
	end

SaffronCity_Dojo_EventScript_RightScroll::
	msgbox SaffronCity_Dojo_Text_GoesAroundComesAround, MSGBOX_SIGN
	end

SaffronCity_Dojo_EventScript_Hitoshi::
	trainerbattle_single TRAINER_BLACK_BELT_HITOSHI, SaffronCity_Dojo_Text_HitoshiIntro, SaffronCity_Dojo_Text_HitoshiDefeat
	msgbox SaffronCity_Dojo_Text_HitoshiPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_Hideki::
	trainerbattle_single TRAINER_BLACK_BELT_HIDEKI, SaffronCity_Dojo_Text_HidekiIntro, SaffronCity_Dojo_Text_HidekiDefeat
	msgbox SaffronCity_Dojo_Text_HidekiPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_Aaron::
	trainerbattle_single TRAINER_BLACK_BELT_AARON, SaffronCity_Dojo_Text_AaronIntro, SaffronCity_Dojo_Text_AaronDefeat
	msgbox SaffronCity_Dojo_Text_AaronPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_Mike::
	trainerbattle_single TRAINER_BLACK_BELT_MIKE, SaffronCity_Dojo_Text_MikeIntro, SaffronCity_Dojo_Text_MikeDefeat
	msgbox SaffronCity_Dojo_Text_MikePostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_MasterKoichi::
	trainerbattle_single TRAINER_BLACK_BELT_KOICHI, SaffronCity_Dojo_Text_MasterKoichiIntro, SaffronCity_Dojo_Text_MasterKoichiDefeat, SaffronCity_Dojo_EventScript_DefeatedMasterKoichi
	goto_if_set FLAG_GOT_HITMON_FROM_DOJO, SaffronCity_Dojo_EventScript_MasterKoichiAlreadyGotHitmon
	msgbox SaffronCity_Dojo_Text_ChoosePrizedFightingMon, MSGBOX_AUTOCLOSE
	end

SaffronCity_Dojo_EventScript_MasterKoichiAlreadyGotHitmon::
	msgbox SaffronCity_Dojo_Text_StayAndTrainWithUs
	release
	end

SaffronCity_Dojo_EventScript_DefeatedMasterKoichi::
	setvar VAR_MAP_SCENE_SAFFRON_CITY_DOJO, 1
	release
	end

SaffronCity_Dojo_Text_MasterKoichiIntro::
	.string "Jeune DRESSEUR!\p"
	.string "Je suis le GRAND MAITRE de\n"
	.string "KARATE! Je suis le CHAMPION!\p"
	.string "Tu me provoques?\n"
	.string "Tu veux m'affronter?\p"
	.string "Je n'aurai aucune pitié!\n"
	.string "HAHAHA! Ayaaaaa!$"

SaffronCity_Dojo_Text_MasterKoichiDefeat::
	.string "STOP!\n"
	.string "Tu m'as battu! J'ai honte!$"

SaffronCity_Dojo_Text_ChoosePrizedFightingMon::
	.string "OK, tu as gagné!\p"
	.string "Mais ne va pas le crier sur tous\n"
	.string "les toits! Tu sais te battre, on a\l"
	.string "compris!\p"
	.string "Tiens, prends ça!\n"
	.string "Tu as gagné un POKéMON COMBAT!\p"
	.string "Choisis celui que tu veux!$"

SaffronCity_Dojo_Text_StayAndTrainWithUs::
	.string "Reste avec nous pour faire du\n"
	.string "KARATE!$"

SaffronCity_Dojo_Text_MikeIntro::
	.string "Roooh!\n"
	.string "Enlève tes chaussures!$"

SaffronCity_Dojo_Text_MikeDefeat::
	.string "J'abandonne!$"

SaffronCity_Dojo_Text_MikePostBattle::
	.string "Tu te tais, tu t'assois et tu\n"
	.string "attends le grand maître!\p"
	.string "Tu vas comprendre ta douleur!\n"
	.string "Il est invincible.$"

SaffronCity_Dojo_Text_HidekiIntro::
	.string "T'as des prétentions?\n"
	.string "Montre-moi!$"

SaffronCity_Dojo_Text_HidekiDefeat::
	.string "Un point pour toi!$"

SaffronCity_Dojo_Text_HidekiPostBattle::
	.string "Notre maître est un pro.\n"
	.string "Prépare-toi à perdre!$"

SaffronCity_Dojo_Text_AaronIntro::
	.string "J'ai peur de rien!\p"
	.string "Le matin, j'casse des pierres\n"
	.string "pour m'entraîner!$"

SaffronCity_Dojo_Text_AaronDefeat::
	.string "Woaa! Les pierres, ça rend pas\n"
	.string "les coups!$"

SaffronCity_Dojo_Text_AaronPostBattle::
	.string "La seule chose qui nous fait peur\n"
	.string "c'est les pouvoirs psy!$"

SaffronCity_Dojo_Text_HitoshiIntro::
	.string "Ayah!\p"
	.string "Tu joues avec ta vie!\n"
	.string "Ce DOJO, c'est pour les balèzes!$"

SaffronCity_Dojo_Text_HitoshiDefeat::
	.string "Ouille!\n"
	.string "J'suis KO!$"

SaffronCity_Dojo_Text_HitoshiPostBattle::
	.string "Les meilleurs combattants\n"
	.string "du pays sont ici!$"

SaffronCity_Dojo_Text_YouWantHitmonlee::
	.string "Tu veux KICKLEE, l'expert\n"
	.string "en coups de pied?$"

SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster::
	.string "{PLAYER} reçoit un\n"
	.string "{STR_VAR_1}!$"

SaffronCity_Dojo_Text_YouWantHitmonchan::
	.string "Tu veux TYGNON, le puncheur?$"

SaffronCity_Dojo_Text_ReceivedMonFromKarateMaster2::
	.string "{PLAYER}は　カラテ　だいおう　から\n"
	.string "{STR_VAR_1}を　もらった！$"

SaffronCity_Dojo_Text_BetterNotGetGreedy::
	.string "Tss tss tss!\n"
	.string "Faut pas être trop gourmand…$"

SaffronCity_Dojo_Text_EnemiesOnEverySide::
	.string "Ne compte que sur toi!$"

SaffronCity_Dojo_Text_GoesAroundComesAround::
	.string "Respecte ton ennemi!$"

SaffronCity_Dojo_Text_FightingDojo::
	.string "DOJO$"


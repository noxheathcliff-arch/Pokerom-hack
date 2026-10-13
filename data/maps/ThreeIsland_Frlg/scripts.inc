ThreeIsland_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ThreeIsland_OnTransition
	.byte 0

ThreeIsland_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_THREE_ISLAND
	call_if_set FLAG_RESCUED_LOSTELLE, ThreeIsland_EventScript_HideAntiBikers
	call_if_eq VAR_MAP_SCENE_THREE_ISLAND, 4, ThreeIsland_EventScript_SetAntiBikersMovementAfterBikers
	end

ThreeIsland_EventScript_HideAntiBikers::
	setflag FLAG_HIDE_THREE_ISLAND_ANTIBIKERS
	return

ThreeIsland_EventScript_SetAntiBikersMovementAfterBikers::
	setobjectmovementtype LOCALID_THREE_ISLAND_ANTIBIKER1, MOVEMENT_TYPE_LOOK_AROUND
	setobjectmovementtype LOCALID_THREE_ISLAND_ANTIBIKER2, MOVEMENT_TYPE_LOOK_AROUND
	return

ThreeIsland_EventScript_Biker::
	lock
	setvar VAR_TEMP_1, 2
	call ThreeIsland_EventScript_BikerArgumentScene
	release
	end

ThreeIsland_EventScript_AntiBiker1::
	lock
	goto_if_set FLAG_GOT_FULL_RESTORE_FROM_THREE_ISLAND_DEFENDER, ThreeIsland_EventScript_AntiBiker1GotFullRestore
	goto_if_eq VAR_MAP_SCENE_THREE_ISLAND, 4, ThreeIsland_EventScript_GiveFullRestore
	setvar VAR_TEMP_1, 0
	call ThreeIsland_EventScript_BikerArgumentScene
	release
	end

ThreeIsland_EventScript_AntiBiker1GotFullRestore::
	applymovement LOCALID_THREE_ISLAND_ANTIBIKER1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox ThreeIsland_Text_YouveGotImpressiveMons
	release
	end

ThreeIsland_EventScript_GiveFullRestore::
	applymovement LOCALID_THREE_ISLAND_ANTIBIKER1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox ThreeIsland_Text_ThankYouOhYourMonGotHurt
	checkitemspace ITEM_FULL_RESTORE
	goto_if_eq VAR_RESULT, FALSE, ThreeIsland_EventScript_NoRoomForFullRestore
	msgreceiveditem ThreeIsland_Text_GivenFullRestore, ITEM_FULL_RESTORE
	additem ITEM_FULL_RESTORE
	setflag FLAG_GOT_FULL_RESTORE_FROM_THREE_ISLAND_DEFENDER
	msgbox ThreeIsland_Text_YouveGotImpressiveMons
	release
	end

ThreeIsland_EventScript_NoRoomForFullRestore::
	msgbox ThreeIsland_Text_OhYourBagIsFull
	release
	end

ThreeIsland_EventScript_BikerArgumentScene::
	call_if_eq VAR_TEMP_1, 1, ThreeIsland_EventScript_PlayerFaceLeft
	call_if_eq VAR_TEMP_1, 2, ThreeIsland_EventScript_PlayerFaceLeft
	applymovement LOCALID_THREE_ISLAND_ANTIBIKER1, ThreeIsland_Movement_SpeakRight
	waitmovement 0
	msgbox ThreeIsland_Text_GoBackToKanto
	call_if_eq VAR_TEMP_1, 0, ThreeIsland_EventScript_PlayerFaceRight
	call_if_eq VAR_TEMP_1, 1, ThreeIsland_EventScript_PlayerFaceRight
	call_if_eq VAR_TEMP_1, 2, ThreeIsland_EventScript_PlayerFaceBiker
	applymovement LOCALID_THREE_ISLAND_BIKER1, ThreeIsland_Movement_SpeakLeft
	waitmovement 0
	msgbox ThreeIsland_Text_BossIsOnHisWay
	call_if_eq VAR_TEMP_1, 0, ThreeIsland_EventScript_PlayerFaceUp
	call_if_eq VAR_TEMP_1, 1, ThreeIsland_EventScript_PlayerFaceUp
	call_if_eq VAR_TEMP_1, 2, ThreeIsland_EventScript_PlayerFaceAntiBiker
	applymovement LOCALID_THREE_ISLAND_ANTIBIKER2, ThreeIsland_Movement_SpeakRight
	waitmovement 0
	msgbox ThreeIsland_Text_GetOffIslandNow
	call_if_eq VAR_TEMP_1, 0, ThreeIsland_EventScript_PlayerFaceRight
	call_if_eq VAR_TEMP_1, 1, ThreeIsland_EventScript_PlayerFaceRight
	call_if_eq VAR_TEMP_1, 2, ThreeIsland_EventScript_PlayerFaceBiker
	applymovement LOCALID_THREE_ISLAND_BIKER3, ThreeIsland_Movement_SpeakLeft
	waitmovement 0
	msgbox ThreeIsland_Text_WhosGonnaMakeMe
	return

ThreeIsland_EventScript_PlayerFaceUp::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

@ Unused
ThreeIsland_EventScript_PlayerFaceDown::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

ThreeIsland_EventScript_PlayerFaceLeft::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

ThreeIsland_EventScript_PlayerFaceRight::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

ThreeIsland_EventScript_PlayerFaceBiker::
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_ge VAR_0x8004, 9, ThreeIsland_EventScript_PlayerFaceUp
	goto ThreeIsland_EventScript_PlayerFaceRight
	end

ThreeIsland_EventScript_PlayerFaceAntiBiker::
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_ge VAR_0x8004, 9, ThreeIsland_EventScript_PlayerFaceLeft
	goto ThreeIsland_EventScript_PlayerFaceUp
	end

ThreeIsland_EventScript_AntiBiker2::
	lock
	goto_if_eq VAR_MAP_SCENE_THREE_ISLAND, 4, ThreeIsland_EventScript_AntiBiker2BikersGone
	setvar VAR_TEMP_1, 1
	call ThreeIsland_EventScript_BikerArgumentScene
	release
	end

ThreeIsland_EventScript_AntiBiker2BikersGone::
	applymovement LOCALID_THREE_ISLAND_ANTIBIKER2, Common_Movement_FacePlayer
	waitmovement 0
	msgbox ThreeIsland_Text_LostelleWentOffTowardsBondBridge
	release
	end

ThreeIsland_EventScript_BikerBossIntroTrigger::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_THREE_ISLAND_ANTIBIKER1, ThreeIsland_Movement_SpeakRight
	waitmovement 0
	msgbox ThreeIsland_Text_AreYouBossGoBackToKanto
	applymovement LOCALID_PAXTON, ThreeIsland_Movement_SpeakLeft
	waitmovement 0
	msgbox ThreeIsland_Text_JustGotHerePal
	applymovement LOCALID_THREE_ISLAND_ANTIBIKER1, ThreeIsland_Movement_SpeakRight
	waitmovement 0
	msgbox ThreeIsland_Text_FollowersRaisingHavoc
	applymovement LOCALID_PAXTON, ThreeIsland_Movement_SpeakLeft
	waitmovement 0
	msgbox ThreeIsland_Text_OughtToBeThankingUs
	applymovement LOCALID_THREE_ISLAND_ANTIBIKER1, ThreeIsland_Movement_SpeakRight
	waitmovement 0
	msgbox ThreeIsland_Text_YouCowardsToughInPack
	setvar VAR_MAP_SCENE_THREE_ISLAND, 3
	releaseall
	end

ThreeIsland_Movement_SpeakLeft::
	walk_in_place_left
	step_end

ThreeIsland_Movement_SpeakRight::
	walk_in_place_right
	step_end

ThreeIsland_EventScript_BattleBikersTriggerLeft::
	lockall
	setvar VAR_TEMP_1, 0
	goto ThreeIsland_EventScript_BattleBikersScene
	end

ThreeIsland_EventScript_BattleBikersTriggerMidLeft::
	lockall
	setvar VAR_TEMP_1, 1
	goto ThreeIsland_EventScript_BattleBikersScene
	end

ThreeIsland_EventScript_BattleBikersTriggerMid::
	lockall
	setvar VAR_TEMP_1, 2
	goto ThreeIsland_EventScript_BattleBikersScene
	end

ThreeIsland_EventScript_BattleBikersTriggerMidRight::
	lockall
	setvar VAR_TEMP_1, 3
	goto ThreeIsland_EventScript_BattleBikersScene
	end

ThreeIsland_EventScript_BattleBikersTriggerRight::
	lockall
	setvar VAR_TEMP_1, 4
	goto ThreeIsland_EventScript_BattleBikersScene
	end

ThreeIsland_EventScript_BattleBikersScene::
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_THREE_ISLAND_BIKER1, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_THREE_ISLAND_BIKER1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_THREE_ISLAND_BIKER1, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_THREE_ISLAND_BIKER1, ThreeIsland_Movement_BikerApproach
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_BOY, 0
	msgbox ThreeIsland_Text_WannaMakeSomethingOfYourStaring, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ThreeIsland_EventScript_LeaveBikersAlone
	msgbox ThreeIsland_Text_Biker1Intro
	setvar VAR_LAST_TALKED, LOCALID_THREE_ISLAND_BIKER1
	trainerbattle_no_intro TRAINER_BIKER_GOON, ThreeIsland_Text_Biker1Defeat
	applymovement LOCALID_THREE_ISLAND_BIKER1, ThreeIsland_Movement_BikerSpeak
	waitmovement 0
	msgbox ThreeIsland_Text_Biker1PostBattle
	closemessage
	applymovement LOCALID_THREE_ISLAND_BIKER2, ThreeIsland_Movement_BikerApproach
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_BOY, 0
	msgbox ThreeIsland_Text_Biker2Intro
	setvar VAR_LAST_TALKED, LOCALID_THREE_ISLAND_BIKER2
	trainerbattle_no_intro TRAINER_BIKER_GOON_2, ThreeIsland_Text_Biker2Defeat
	applymovement LOCALID_THREE_ISLAND_BIKER2, ThreeIsland_Movement_BikerSpeak
	waitmovement 0
	msgbox ThreeIsland_Text_Biker2PostBattle
	closemessage
	applymovement LOCALID_THREE_ISLAND_BIKER3, ThreeIsland_Movement_BikerApproach
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_BOY, 0
	msgbox ThreeIsland_Text_Biker3Intro
	setvar VAR_LAST_TALKED, LOCALID_THREE_ISLAND_BIKER3
	trainerbattle_no_intro TRAINER_BIKER_GOON_3, ThreeIsland_Text_Biker3Defeat
	applymovement LOCALID_THREE_ISLAND_BIKER3, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_THREE_ISLAND_BIKER4, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_THREE_ISLAND_BIKER5, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox ThreeIsland_Text_Biker3PostBattle
	closemessage
	delay 45
	call_if_eq VAR_TEMP_1, 0, ThreeIsland_EventScript_PaxtonApproachLeft
	call_if_eq VAR_TEMP_1, 1, ThreeIsland_EventScript_PaxtonApproachMidLeft
	call_if_eq VAR_TEMP_1, 2, ThreeIsland_EventScript_PaxtonApproachMid
	call_if_eq VAR_TEMP_1, 3, ThreeIsland_EventScript_PaxtonApproachMidRight
	call_if_eq VAR_TEMP_1, 4, ThreeIsland_EventScript_PaxtonApproachRight
	playbgm MUS_RG_ENCOUNTER_BOY, 0
	msgbox ThreeIsland_Text_PaxtonIntro
	setvar VAR_LAST_TALKED, LOCALID_PAXTON
	trainerbattle_no_intro TRAINER_CUE_BALL_PAXTON, ThreeIsland_Text_PaxtonDefeat
	msgbox ThreeIsland_Text_PaxtonPostBattle
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_PAXTON
	removeobject LOCALID_THREE_ISLAND_BIKER1
	removeobject LOCALID_THREE_ISLAND_BIKER2
	removeobject LOCALID_THREE_ISLAND_BIKER3
	removeobject LOCALID_THREE_ISLAND_BIKER4
	removeobject LOCALID_THREE_ISLAND_BIKER5
	removeobject LOCALID_THREE_ISLAND_BIKER6
	fadescreenswapbuffers FADE_FROM_BLACK
	setvar VAR_MAP_SCENE_THREE_ISLAND, 4
	releaseall
	end

ThreeIsland_EventScript_PaxtonApproachLeft::
	applymovement LOCALID_THREE_ISLAND_BIKER3, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PAXTON, ThreeIsland_Movement_PaxtonApproachLeft
	waitmovement 0
	return

ThreeIsland_EventScript_PaxtonApproachMidLeft::
	applymovement LOCALID_THREE_ISLAND_BIKER3, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PAXTON, ThreeIsland_Movement_PaxtonApproachMidLeft
	waitmovement 0
	return

ThreeIsland_EventScript_PaxtonApproachMid::
	applymovement LOCALID_THREE_ISLAND_BIKER3, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PAXTON, ThreeIsland_Movement_PaxtonApproachMid
	applymovement LOCALID_PLAYER, ThreeIsland_Movement_PlayerFacePaxton
	waitmovement 0
	return

ThreeIsland_EventScript_PaxtonApproachMidRight::
	applymovement LOCALID_THREE_ISLAND_BIKER3, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PLAYER, ThreeIsland_Movement_PlayerFacePaxton
	applymovement LOCALID_PAXTON, ThreeIsland_Movement_PaxtonApproachMidRight
	waitmovement 0
	return

ThreeIsland_EventScript_PaxtonApproachRight::
	applymovement LOCALID_THREE_ISLAND_BIKER3, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PLAYER, ThreeIsland_Movement_PlayerFacePaxton
	applymovement LOCALID_PAXTON, ThreeIsland_Movement_PaxtonApproachRight
	waitmovement 0
	return

ThreeIsland_EventScript_LeaveBikersAlone::
	msgbox ThreeIsland_Text_ThatsSmart
	closemessage
	applymovement LOCALID_PLAYER, ThreeIsland_Movement_PlayerLeaveBikers
	waitmovement 0
	applymovement LOCALID_THREE_ISLAND_BIKER1, ThreeIsland_Movement_Biker1ReturnToPack
	waitmovement 0
	fadedefaultbgm
	releaseall
	end

ThreeIsland_Movement_PlayerLeaveBikers::
	walk_down
	step_end

ThreeIsland_Movement_BikerApproach::
	walk_down
	step_end

ThreeIsland_Movement_Biker1ReturnToPack::
	walk_up
	walk_in_place_faster_left
	step_end

ThreeIsland_Movement_BikerSpeak::
	walk_in_place_down
	step_end

ThreeIsland_Movement_PaxtonApproachLeft::
	walk_down
	walk_left
	walk_in_place_faster_down
	step_end

ThreeIsland_Movement_PaxtonApproachMidLeft::
	walk_down
	step_end

ThreeIsland_Movement_PaxtonApproachMid::
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

ThreeIsland_Movement_PlayerFacePaxton::
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

ThreeIsland_Movement_PaxtonApproachMidRight::
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_right
	step_end

ThreeIsland_Movement_PaxtonApproachRight::
	walk_down
	walk_down
	walk_right
	walk_right
	walk_in_place_faster_right
	step_end

ThreeIsland_EventScript_Woman::
	msgbox ThreeIsland_Text_WouldntWantToSeeBikersHereAgain, MSGBOX_NPC
	end

ThreeIsland_EventScript_LittleBoy::
	msgbox ThreeIsland_Text_WhenDodouEvolvesGoingToPlayGame, MSGBOX_NPC
	end

ThreeIsland_EventScript_Doduo::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DODUO, CRY_MODE_NORMAL
	msgbox ThreeIsland_Text_Doduo
	waitmoncry
	release
	end

ThreeIsland_EventScript_IslandSign::
	msgbox ThreeIsland_Text_IslandSign, MSGBOX_SIGN
	end

ThreeIsland_EventScript_Biker6::
	msgbox ThreeIsland_Text_IslandBelongsToUs, MSGBOX_NPC
	end

ThreeIsland_Text_IslandSign::
	.string "ILE 3\n"
	.string "L'île où on se sent chez soi$"

ThreeIsland_Text_IslandBelongsToUs::
	.string "Yahaaa!\p"
	.string "A partir d'aujourd'hui, cette\n"
	.string "île nous appartient!$"

ThreeIsland_Text_GoBackToKanto::
	.string "On a pas besoin de vous ici.\n"
	.string "Retournez chez vous à KANTO!$"

ThreeIsland_Text_BossIsOnHisWay::
	.string "Hé, va pleurer ailleurs. Notre boss\n"
	.string "va bientôt arriver.\p"
	.string "Quand il sera là, on va vous faire\n"
	.string "une démonstration de moto que\p"
	.string "vous risquez pas d'oublier!$"

ThreeIsland_Text_GetOffIslandNow::
	.string "Q-quoi?? Pas tant que je serai\n"
	.string "en vie! Partez tout de suite!$"

ThreeIsland_Text_WhosGonnaMakeMe::
	.string "Et qui me fera partir?$"

ThreeIsland_Text_AreYouBossGoBackToKanto::
	.string "C'est toi le chef de cette bande?\n"
	.string "Repartez pour KANTO maintenant!$"

ThreeIsland_Text_JustGotHerePal::
	.string "Hahaa?\p"
	.string "Comme c'est dommage, je\n"
	.string "viens juste d'arriver.\p"
	.string "Quel manque de courtoisie,\n"
	.string "tu arriverais presque à m'énerver.$"

ThreeIsland_Text_FollowersRaisingHavoc::
	.string "Votre gang de motards a semé la\n"
	.string "panique depuis son arrivée ici.\p"
	.string "Est-ce que vous vous rendez\n"
	.string "compte des problèmes que vous\p"
	.string "créez sur cette petite île?$"

ThreeIsland_Text_OughtToBeThankingUs::
	.string "Non, mon gars, j'me rends pas\n"
	.string "compte du tout.\p"
	.string "Regarde autour de toi.\n"
	.string "Y'a rien à faire ici, \p"
	.string "on vous apporte un peu de\n"
	.string "changement.\p"
	.string "Mais si tu tiens tant à retrouver\n"
	.string "ta vie ennuyeuse,\p"
	.string "tu peux toujours essayer de\n"
	.string "nous faire partir.$"

ThreeIsland_Text_YouCowardsToughInPack::
	.string "Grrr… Bande de lâches…\p"
	.string "Vous faites les durs parce que\n"
	.string "vous êtes en groupe…$"

ThreeIsland_Text_WannaMakeSomethingOfYourStaring::
	.string "Quoi, kess tu mates?\n"
	.string "Tu sais pas que c'est pas poli?\p"
	.string "Tu cherches vraiment à ce que\n"
	.string "je m'énerve ou quoi?$"

ThreeIsland_Text_ThatsSmart::
	.string "Bonne réponse. Alors fais-moi\n"
	.string "de l'air maintenant.$"

ThreeIsland_Text_Biker1Intro::
	.string "Hahaha, t'as du cran au moins. Tu\n"
	.string "vas te souvenir de cette raclée…$"

ThreeIsland_Text_Biker1Defeat::
	.string "Quoi…\n"
	.string "J'peux pas le croire!$"

ThreeIsland_Text_Biker1PostBattle::
	.string "Ne t'avise pas de te moquer!$"

ThreeIsland_Text_Biker2Intro::
	.string "T'es pas de KANTO? Tu devrais\n"
	.string "être de notre côté!$"

ThreeIsland_Text_Biker2Defeat::
	.string "Arrête de te la raconter!$"

ThreeIsland_Text_Biker2PostBattle::
	.string "C'est quoi ton problème?\n"
	.string "T'as pas besoin de t'énerver!\p"
	.string "Vraiment pas cool!$"

ThreeIsland_Text_Biker3Intro::
	.string "On a demandé au chef de venir\n"
	.string "ici, mais t'as tout gâché!\p"
	.string "Tu nous fous la honte!$"

ThreeIsland_Text_Biker3Defeat::
	.string "… … …   … … …$"

ThreeIsland_Text_Biker3PostBattle::
	.string "Boss, tu dois faire quelque chose\n"
	.string "contre c'mioche!$"

ThreeIsland_Text_PaxtonIntro::
	.string "Je t'ai regardé, t'en as vraiment\n"
	.string "fait assez, tu crois pas?\p"
	.string "T'es qui? T'es avec eux ou quoi?\p"
	.string "Alors tu vas te battre à leur\n"
	.string "place, OK?$"

ThreeIsland_Text_PaxtonDefeat::
	.string "OK, ça suffit!\n"
	.string "On va partir!\p"
	.string "On est bien contents de quitter\n"
	.string "cette île de vieux!$"

ThreeIsland_Text_PaxtonPostBattle::
	.string "On en avait marre de ces\n"
	.string "bouseux de toute façon!$"

ThreeIsland_Text_ThankYouOhYourMonGotHurt::
	.string "Merci du fond du cœur. Ces voyous\n"
	.string "ne créaient que des problèmes.\p"
	.string "Oh, regarde. Tu as un POKéMON\n"
	.string "blessé.$"

ThreeIsland_Text_GivenFullRestore::
	.string "{PLAYER} reçoit une\n"
	.string "GUERISON.$"

ThreeIsland_Text_OhYourBagIsFull::
	.string "Oh!\n"
	.string "Ton SAC est plein.$"

ThreeIsland_Text_YouveGotImpressiveMons::
	.string "Tes POKéMON sont vraiment\n"
	.string "impressionnants.$"

ThreeIsland_Text_LostelleWentOffTowardsBondBridge::
	.string "Si seulement quelqu'un fort\n"
	.string "comme toi pouvait habiter ici…\p"
	.string "J'espère au moins que tu resteras\n"
	.string "quelque temps.\p"
	.string "… Pardon? Oh, tu\n"
	.string "cherches LOSTELLE?\p"
	.string "Elle est partie vers le PONT DU\n"
	.string "LIEN il n'y a pas longtemps.$"

ThreeIsland_Text_WouldntWantToSeeBikersHereAgain::
	.string "L'ILE 3 est l'île la plus populaire\n"
	.string "du coin.\p"
	.string "Bon, ça manque pourtant\n"
	.string "quelquefois d'animation.\p"
	.string "Mais je souhaite vraiment que ces\n"
	.string "MOTARDS ne reviennent pas.$"

ThreeIsland_Text_WhenDodouEvolvesGoingToPlayGame::
	.string "Je vais aller dresser mon DODUO\n"
	.string "dans les BOIS BAIES.\p"
	.string "Quand il aura évolué, on ira jouer\n"
	.string "à un jeu sur l'ILE 2.$"

ThreeIsland_Text_Doduo::
	.string "DODUO: Dudoo!$"


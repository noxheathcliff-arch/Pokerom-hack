.equ RECEIVED_TOWN_MAP, VAR_TEMP_1

PalletTown_RivalsHouse_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_RivalsHouse_OnTransition
	.byte 0

PalletTown_RivalsHouse_OnTransition::
	call_if_lt VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, PalletTown_RivalsHouse_EventScript_MoveDaisyToTable
	call_if_ge VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, PalletTown_RivalsHouse_EventScript_AlreadyReceivedTownMap
	end

PalletTown_RivalsHouse_EventScript_MoveDaisyToTable::
	setobjectmovementtype LOCALID_DAISY, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LOCALID_DAISY, 5, 4
	return

PalletTown_RivalsHouse_EventScript_AlreadyReceivedTownMap::
	setvar RECEIVED_TOWN_MAP, TRUE
	return

PalletTown_RivalsHouse_EventScript_Daisy::
	lock
	faceplayer
	famechecker FAMECHECKER_DAISY, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	goto_if_set FLAG_SYS_GAME_CLEAR, PalletTown_RivalsHouse_EventScript_GroomMon
	goto_if_eq RECEIVED_TOWN_MAP, TRUE, PalletTown_RivalsHouse_EventScript_PleaseGiveMonsRest
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2, PalletTown_RivalsHouse_EventScript_ExplainTownMap
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 1, PalletTown_RivalsHouse_EventScript_GiveTownMap
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1, PalletTown_RivalsHouse_EventScript_HeardBattledRival
	msgbox PalletTown_RivalsHouse_Text_HiBrothersAtLab
	closemessage
	applymovement LOCALID_DAISY, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PalletTown_RivalsHouse_EventScript_HeardBattledRival::
	msgbox PalletTown_RivalsHouse_Text_HeardYouBattledRival
	release
	end

PalletTown_RivalsHouse_EventScript_GroomMon::
	goto_if_lt VAR_MASSAGE_COOLDOWN_STEP_COUNTER, 500, PalletTown_RivalsHouse_EventScript_RateMonFriendship
	msgbox PalletTown_RivalsHouse_Text_LikeMeToGroomMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PalletTown_RivalsHouse_EventScript_DeclineGrooming
	msgbox PalletTown_RivalsHouse_Text_GroomWhichOne
	special ChoosePartyMon
	lock
	faceplayer
	goto_if_ge VAR_0x8004, PARTY_SIZE, PalletTown_RivalsHouse_EventScript_DeclineGrooming
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, PalletTown_RivalsHouse_EventScript_CantGroomEgg
	msgbox PalletTown_RivalsHouse_Text_LookingNiceInNoTime
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special DaisyMassageServices
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox PalletTown_RivalsHouse_Text_ThereYouGoAllDone
	release
	end

PalletTown_RivalsHouse_EventScript_CantGroomEgg::
	msgbox PalletTown_RivalsHouse_Text_CantGroomAnEgg
	release
	end

PalletTown_RivalsHouse_EventScript_DeclineGrooming::
	msgbox PalletTown_RivalsHouse_Text_DontNeedAnyGrooming
	release
	end

PalletTown_RivalsHouse_EventScript_RateMonFriendship::
	msgbox PalletTown_RivalsHouse_Text_MayISeeFirstMon
	specialvar VAR_RESULT, GetLeadMonFriendship
	switch VAR_RESULT
	case 0, PalletTown_RivalsHouse_EventScript_MonFriendshipLowest
	case 1, PalletTown_RivalsHouse_EventScript_MonFriendshipLower
	case 2, PalletTown_RivalsHouse_EventScript_MonFriendshipLow
	case 3, PalletTown_RivalsHouse_EventScript_MonFriendshipMid
	case 4, PalletTown_RivalsHouse_EventScript_MonFriendshipHigh
	case 5, PalletTown_RivalsHouse_EventScript_MonFriendshipHigher
	case 6, PalletTown_RivalsHouse_EventScript_MonFriendshipHighest
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipLowest::
	msgbox PalletTown_RivalsHouse_Text_WhyWouldMonHateYouSoMuch
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipLower::
	msgbox PalletTown_RivalsHouse_Text_DontLikeWayItGlaresAtYou
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipLow::
	msgbox PalletTown_RivalsHouse_Text_NotFamiliarWithYouYet
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipMid::
	msgbox PalletTown_RivalsHouse_Text_ItsWarmingUpToYou
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipHigh::
	msgbox PalletTown_RivalsHouse_Text_ItsQuiteFriendly
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipHigher::
	msgbox PalletTown_RivalsHouse_Text_ItLooksVeryHappy
	release
	end

PalletTown_RivalsHouse_EventScript_MonFriendshipHighest::
	msgbox PalletTown_RivalsHouse_Text_CouldntLoveYouMore
	release
	end

PalletTown_RivalsHouse_EventScript_PleaseGiveMonsRest::
	msgbox PalletTown_RivalsHouse_Text_PleaseGiveMonsRest
	release
	end

PalletTown_RivalsHouse_EventScript_GiveTownMap::
	msgbox PalletTown_RivalsHouse_Text_ErrandForGrandpaThisWillHelp
	closemessage
	checkitemspace ITEM_TOWN_MAP
	goto_if_eq VAR_RESULT, FALSE, PalletTown_RivalsHouse_EventScript_NoRoomForTownMap
	applymovement LOCALID_DAISY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	removeobject LOCALID_TOWN_MAP
	setvar VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2
	delay 15
	applymovement LOCALID_DAISY, Common_Movement_FacePlayer
	waitmovement 0
	delay 12
	giveitem_msg PalletTown_RivalsHouse_Text_ReceivedTownMapFromDaisy, ITEM_TOWN_MAP, 1, MUS_RG_OBTAIN_KEY_ITEM
	release
	end

PalletTown_RivalsHouse_EventScript_NoRoomForTownMap::
	msgbox PalletTown_RivalsHouse_Text_DontHaveSpaceForThis
	release
	end

PalletTown_RivalsHouse_EventScript_ExplainTownMap::
	msgbox PalletTown_RivalsHouse_Text_ExplainTownMap
	release
	end

PalletTown_RivalsHouse_EventScript_TownMap::
	msgbox PalletTown_RivalsHouse_Text_ItsBigMapOfKanto, MSGBOX_NPC
	end

PalletTown_RivalsHouse_EventScript_Bookshelf::
	msgbox PalletTown_RivalsHouse_Text_ShelvesCrammedFullOfBooks, MSGBOX_SIGN
	end

PalletTown_RivalsHouse_EventScript_Picture::
	msgbox PalletTown_RivalsHouse_Text_LovelyAndSweetClefairy, MSGBOX_SIGN
	end

PalletTown_RivalsHouse_Text_HiBrothersAtLab::
	.string "NINA: Salut {PLAYER}!\p"
	.string "{RIVAL} est dans le labo de pépé!$"

PalletTown_RivalsHouse_Text_HeardYouBattledRival::
	.string "NINA: {PLAYER}, il paraît que tu as\n"
	.string "combattu {RIVAL}.\p"
	.string "J'aurais aimé voir ça!$"

PalletTown_RivalsHouse_Text_ErrandForGrandpaThisWillHelp::
	.string "Tu pars explorer la région\n"
	.string "pour pépé?\p"
	.string "Prends ceci, ça peut servir!$"

PalletTown_RivalsHouse_Text_ReceivedTownMapFromDaisy::
	.string "{PLAYER} reçoit la\n"
	.string "CARTE!$"

PalletTown_RivalsHouse_Text_DontHaveSpaceForThis::
	.string "Ton inventaire est plein.$"

PalletTown_RivalsHouse_Text_ExplainTownMap::
	.string "Utilise la CARTE pour connaître ta\n"
	.string "position.$"

PalletTown_RivalsHouse_Text_PleaseGiveMonsRest::
	.string "NINA: Comme les gens, les POKéMON\n"
	.string "sont des êtres vivants.\p"
	.string "Ils doivent aussi se reposer quand\n"
	.string "ils sont fatigués.$"

PalletTown_RivalsHouse_Text_ItsBigMapOfKanto::
	.string "C'est une carte!\n"
	.string "Ça peut être utile!$"

PalletTown_RivalsHouse_Text_ShelvesCrammedFullOfBooks::
	.string "Des bouquins sur les POKéMON!$"

PalletTown_RivalsHouse_Text_LikeMeToGroomMon::
	.string "NINA: Salut! Ça tombe bien,\n"
	.string "j'allais faire du thé. En veux-tu?\p"
	.string "Oh, tes POKéMON sont sales.\n"
	.string "Tu veux que j'en bichonne un?$"

PalletTown_RivalsHouse_Text_DontNeedAnyGrooming::
	.string "NINA: Tu ne veux pas que je m'en\n"
	.string "occupe?\l"
	.string "OK. Un peu de thé, alors…$"

PalletTown_RivalsHouse_Text_GroomWhichOne::
	.string "NINA: Lequel dois-je bichonner?$"

PalletTown_RivalsHouse_Text_LookingNiceInNoTime::
	.string "NINA: OK, je vais le faire beau en\n"
	.string "deux secondes.$"

PalletTown_RivalsHouse_Text_ThereYouGoAllDone::
#ifdef BUGFIX @ The localizers missed what should be a textcolor change in the localizations.
	.string "{COLOR DARK_GRAY}{STR_VAR_1} a l'air heureux.\p"
	.string "{COLOR RED}NINA: Voilààà! C'est fini!\n"
	.string "{FONT_NORMAL}{STR_VAR_1} a l'air heureux.\p"
	.string "NINA: Voilààà! C'est fini!\n"
	.string "Alors? Il est beau, hein?\p"
	.string "Un joli petit POKéMON.$"
#else @ In the JP games, gender-based text used a different font instead of different colors.
#endif

PalletTown_RivalsHouse_Text_CantGroomAnEgg::
	.string "NINA: Oh, désolée. Je ne peux pas\n"
	.string "m'occuper d'un OEUF.$"

PalletTown_RivalsHouse_Text_MayISeeFirstMon::
	.string "NINA: Tes POKéMON te le rendront\n"
	.string "bien si tu les élèves avec amour.\p"
	.string "Par exemple, {PLAYER}, je peux\n"
	.string "voir ton premier POKéMON?$"

PalletTown_RivalsHouse_Text_CouldntLoveYouMore::
	.string "Il ne pourrait pas t'aimer plus\n"
	.string "que maintenant.\p"
	.string "Ton POKéMON est vraiment\n"
	.string "heureux avec toi.$"

PalletTown_RivalsHouse_Text_ItLooksVeryHappy::
	.string "Il a l'air heureux.\p"
	.string "Si seulement {RIVAL} pouvait voir\n"
	.string "ça et en tirer des leçons.$"

PalletTown_RivalsHouse_Text_ItsQuiteFriendly::
	.string "Il t'aime bien. Continue\n"
	.string "comme ça!$"

PalletTown_RivalsHouse_Text_ItsWarmingUpToYou::
	.string "Il commence à s'attacher à toi.\p"
	.string "La confiance va s'instaurer entre\n"
	.string "vous deux.$"

PalletTown_RivalsHouse_Text_NotFamiliarWithYouYet::
	.string "Il n'est pas encore habitué à toi.\p"
	.string "Les POKéMON sont toujours\n"
	.string "un peu craintifs au début.$"

PalletTown_RivalsHouse_Text_DontLikeWayItGlaresAtYou::
	.string "{PLAYER}, je n'aime pas beaucoup\n"
	.string "la façon dont il te regarde.\p"
	.string "Tu devrais être un peu plus\n"
	.string "sympa avec.$"

PalletTown_RivalsHouse_Text_WhyWouldMonHateYouSoMuch::
	.string "… Ça me fait mal au cœur\n"
	.string "de dire ça, mais…\p"
	.string "Y'a-t-il une raison pour laquelle\n"
	.string "il te déteste tant?$"

PalletTown_RivalsHouse_Text_LovelyAndSweetClefairy::
	.string "Le gentil et adorable MELOFEE.$"


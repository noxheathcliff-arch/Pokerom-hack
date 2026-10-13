.equ SHOWN_REQUESTED_MON, FLAG_TEMP_2

FiveIsland_ResortGorgeous_House_Frlg_MapScripts::
	.byte 0

FiveIsland_ResortGorgeous_House_EventScript_Selphy::
	lock
	faceplayer
	goto_if_set SHOWN_REQUESTED_MON, FiveIsland_ResortGorgeous_House_EventScript_JustFulfilledRequest
	goto_if_eq VAR_RESORT_GORGEOUS_REQUESTED_MON, 0xFFFF, FiveIsland_ResortGorgeous_House_EventScript_RequestTookTooLong
	goto_if_ne VAR_RESORT_GORGEOUS_REQUESTED_MON, SPECIES_NONE, FiveIsland_ResortGorgeous_House_EventScript_CheckForRequestedMon
	msgbox FiveIsland_ResortGorgeous_House_Text_PleaseHearMyWish
	goto FiveIsland_ResortGorgeous_House_EventScript_RequestMon
	end

FiveIsland_ResortGorgeous_House_EventScript_RequestMon::
	special SampleResortGorgeousMonAndReward
	msgbox FiveIsland_ResortGorgeous_House_Text_WishToSeeMonPlease
	release
	end

FiveIsland_ResortGorgeous_House_EventScript_RequestTookTooLong::
	msgbox FiveIsland_ResortGorgeous_House_Text_OhImTiredOfWaiting
	goto FiveIsland_ResortGorgeous_House_EventScript_RequestMon
	end

FiveIsland_ResortGorgeous_House_EventScript_CheckForRequestedMon::
	copyvar VAR_0x8004, VAR_RESORT_GORGEOUS_REQUESTED_MON
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	goto_if_eq VAR_RESULT, TRUE, FiveIsland_ResortGorgeous_House_EventScript_ShowRequestedMon
	goto FiveIsland_ResortGorgeous_House_EventScript_RequestMon
	end

FiveIsland_ResortGorgeous_House_EventScript_ShowRequestedMon::
	special SampleResortGorgeousMonAndReward
	msgbox FiveIsland_ResortGorgeous_House_Text_MonYouCaughtForMeThankYou
	addobject LOCALID_RESORT_GORGEOUS_HOUSE_BUTLER
	applymovement LOCALID_RESORT_GORGEOUS_HOUSE_BUTLER, FiveIsland_ResortGorgeous_House_Movement_ButlerEnter
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
	msgbox FiveIsland_ResortGorgeous_House_Text_ButlerYesMyLady
	applymovement LOCALID_RESORT_GORGEOUS_HOUSE_SELPHY, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox FiveIsland_ResortGorgeous_House_Text_SelphyGiveTokenOfAppreciation
	textcolor NPC_TEXT_COLOR_MALE
	msgbox FiveIsland_ResortGorgeous_House_Text_ButlerIShallDoAsYouBid
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, FiveIsland_ResortGorgeous_House_EventScript_ButlerApproachPlayerNorth
	call_if_eq VAR_FACING, DIR_SOUTH, FiveIsland_ResortGorgeous_House_EventScript_ButlerApproachPlayerSouth
	call_if_eq VAR_FACING, DIR_EAST, FiveIsland_ResortGorgeous_House_EventScript_ButlerApproachPlayerEast
	call_if_eq VAR_FACING, DIR_WEST, FiveIsland_ResortGorgeous_House_EventScript_ButlerApproachPlayerWest
	copyobjectxytoperm LOCALID_RESORT_GORGEOUS_HOUSE_BUTLER
	msgbox FiveIsland_ResortGorgeous_House_Text_ButlerPleaseAcceptThisAsHerThanks
	giveitem VAR_RESORT_GORGEOUS_REWARD
	goto_if_eq VAR_RESULT, FALSE, FiveIsland_ResortGorgeous_House_EventScript_NoRoomForReward
	setflag SHOWN_REQUESTED_MON
	setvar VAR_RESORT_GORGEOUS_REQUESTED_MON, SPECIES_NONE
	release
	end

FiveIsland_ResortGorgeous_House_EventScript_ButlerApproachPlayerNorth::
	applymovement LOCALID_RESORT_GORGEOUS_HOUSE_SELPHY, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_RESORT_GORGEOUS_HOUSE_BUTLER, FiveIsland_ResortGorgeous_House_Movement_ButlerApproachPlayerNorth
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

FiveIsland_ResortGorgeous_House_EventScript_ButlerApproachPlayerSouth::
	applymovement LOCALID_RESORT_GORGEOUS_HOUSE_BUTLER, FiveIsland_ResortGorgeous_House_Movement_ButlerApproachPlayerSouth
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

FiveIsland_ResortGorgeous_House_EventScript_ButlerApproachPlayerEast::
	applymovement LOCALID_RESORT_GORGEOUS_HOUSE_SELPHY, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_RESORT_GORGEOUS_HOUSE_BUTLER, FiveIsland_ResortGorgeous_House_Movement_ButlerApproachPlayerEast
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

FiveIsland_ResortGorgeous_House_EventScript_ButlerApproachPlayerWest::
	applymovement LOCALID_RESORT_GORGEOUS_HOUSE_BUTLER, FiveIsland_ResortGorgeous_House_Movement_ButlerApproachPlayerWest
	waitmovement 0
	return

FiveIsland_ResortGorgeous_House_EventScript_NoRoomForReward::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox FiveIsland_ResortGorgeous_House_Text_ButlerBagAppearsToBeFull
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox FiveIsland_ResortGorgeous_House_Text_OhHowDisappointing
	setflag SHOWN_REQUESTED_MON
	setvar VAR_RESORT_GORGEOUS_REQUESTED_MON, SPECIES_NONE
	release
	end

FiveIsland_ResortGorgeous_House_EventScript_JustFulfilledRequest::
	msgbox FiveIsland_ResortGorgeous_House_Text_SelphyWishYouBestOfLuck
	release
	end

FiveIsland_ResortGorgeous_House_Movement_ButlerApproachPlayerNorth::
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

FiveIsland_ResortGorgeous_House_Movement_ButlerApproachPlayerSouth::
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

FiveIsland_ResortGorgeous_House_Movement_ButlerApproachPlayerEast::
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

@ Very odd. If the player is talking to Selphy facing West, then the player has clipped through the table
@ In this case rather than approach the player the Butler walks up, which clips the Butler into a wall
FiveIsland_ResortGorgeous_House_Movement_ButlerApproachPlayerWest::
	walk_up
	step_end

FiveIsland_ResortGorgeous_House_Movement_ButlerEnter::
	walk_in_place_down
	step_end

@ Addressed as "Sebastian" but speaks only as "Butler"
FiveIsland_ResortGorgeous_House_EventScript_Butler::
	msgbox FiveIsland_ResortGorgeous_House_Text_LadySelphySmileHasBrillianceOfSun, MSGBOX_NPC
	end

FiveIsland_ResortGorgeous_House_Text_PleaseHearMyWish::
	.string "THEMIS: Oh?\n"
	.string "Est-ce qu'on se connaît?\p"
	.string "Oh, mais c'est pas grave.\p"
	.string "Je m'ennuie, tu voudrais pas\n"
	.string "me rendre un service?$"

FiveIsland_ResortGorgeous_House_Text_WishToSeeMonPlease::
	.string "Il y a un POKéMON que j'aimerais\n"
	.string "voir. C'est {STR_VAR_1}.\p"
	.string "Je veux en voir un maintenant.\n"
	.string "Exauce mon souhait!$"

FiveIsland_ResortGorgeous_House_Text_OhImTiredOfWaiting::
	.string "THEMIS: Oh, je m'ennuie tellement.\n"
	.string "J'en ai assez de t'attendre.\p"
	.string "Je te pardonne pour cette fois,\n"
	.string "mais ne recommence pas.$"

FiveIsland_ResortGorgeous_House_Text_MonYouCaughtForMeThankYou::
	.string "THEMIS: Tiens, salut.\p"
	.string "Oh, mais… c'est le {STR_VAR_1}\n"
	.string "que tu devais me ramener.\p"
	.string "C'est marrant, il te ressemble\n"
	.string "un peu, tu trouves pas?\p"
	.string "En tout cas, c'est très gentil\n"
	.string "de ta part!\p"
	.string "… …  … …  … …\n"
	.string "Eh bien? Il y a un problème?\p"
	.string "Tu peux disposer maintenant.\p"
	.string "… …  … …  … …\n"
	.string "Ah oui, je comprends.\p"
	.string "SEBASTIAN!\n"
	.string "Veuillez venir s'il vous plaît!$"

FiveIsland_ResortGorgeous_House_Text_ButlerYesMyLady::
	.string "MAJORDOME: Oui?$"

FiveIsland_ResortGorgeous_House_Text_SelphyGiveTokenOfAppreciation::
	.string "THEMIS: SEBASTIAN, veuillez donner\n"
	.string "à cette personne la preuve de\p"
	.string "ma reconnaissance.$"

FiveIsland_ResortGorgeous_House_Text_ButlerIShallDoAsYouBid::
	.string "MAJORDOME: Oui mademoiselle.\n"
	.string "Comme vous voudrez.$"

FiveIsland_ResortGorgeous_House_Text_ButlerPleaseAcceptThisAsHerThanks::
	.string "MAJORDOME: Veuillez recevoir ceci\n"
	.string "de la part de mademoiselle THEMIS.$"

FiveIsland_ResortGorgeous_House_Text_ButlerBagAppearsToBeFull::
	.string "MAJORDOME: Quel dommage, votre\n"
	.string "SAC semble être déjà plein.$"

FiveIsland_ResortGorgeous_House_Text_OhHowDisappointing::
	.string "Oh…\n"
	.string "Comme c'est dommage.$"

FiveIsland_ResortGorgeous_House_Text_SelphyWishYouBestOfLuck::
	.string "THEMIS: Je vous souhaite toute\n"
	.string "la réussite possible.$"

FiveIsland_ResortGorgeous_House_Text_LadySelphySmileHasBrillianceOfSun::
	.string "MAJORDOME: Le sourire de\n"
	.string "mademoiselle THEMIS a l'éclat\l"
	.string "du soleil.\p"
	.string "J'espère que vous réussirez à\n"
	.string "le lui rendre. $"


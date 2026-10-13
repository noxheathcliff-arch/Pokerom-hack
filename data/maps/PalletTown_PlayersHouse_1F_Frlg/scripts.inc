PalletTown_PlayersHouse_1F_Frlg_MapScripts::
	.byte 0

PalletTown_PlayersHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_set FLAG_BEAT_RIVAL_IN_OAKS_LAB, PalletTown_PlayersHouse_1F_EventScript_MomHeal
	checkplayergender
	call_if_eq VAR_RESULT, MALE, PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouMale
	call_if_eq VAR_RESULT, FEMALE, PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouFemale
	closemessage
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouMale::
	msgbox PalletTown_PlayersHouse_1F_Text_AllBoysLeaveOakLookingForYou
	return

PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouFemale::
	msgbox PalletTown_PlayersHouse_1F_Text_AllGirlsLeaveOakLookingForYou
	return

PalletTown_PlayersHouse_1F_EventScript_MomHeal::
	msgbox PalletTown_PlayersHouse_1F_Text_YouShouldTakeQuickRest
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox PalletTown_PlayersHouse_1F_Text_LookingGreatTakeCare
	release
	end

@ Displays special text if interacted with from side or back (which are normally inaccessible)
PalletTown_PlayersHouse_1F_EventScript_TV::
	lockall
	goto_if_eq VAR_FACING, DIR_NORTH, PalletTown_PlayersHouse_1F_EventScript_TVScreen
	msgbox PalletTown_PlayersHouse_1F_Text_OopsWrongSide
	releaseall
	end

PalletTown_PlayersHouse_1F_EventScript_TVScreen::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, PalletTown_PlayersHouse_1F_EventScript_TVScreenMale
	call_if_eq VAR_RESULT, FEMALE, PalletTown_PlayersHouse_1F_EventScript_TVScreenFemale
	releaseall
	end

PalletTown_PlayersHouse_1F_EventScript_TVScreenMale::
	msgbox PalletTown_PlayersHouse_1F_Text_MovieOnTVFourBoysOnRailroad
	return

PalletTown_PlayersHouse_1F_EventScript_TVScreenFemale::
	msgbox PalletTown_PlayersHouse_1F_Text_MovieOnTVGirlOnBrickRoad
	return

PalletTown_PlayersHouse_1F_Text_AllBoysLeaveOakLookingForYou::
	.string "MAMAN: Bon…\p"
	.string "Tous les garçons quittent\n"
	.string "un jour la maison. C'est la vie!\p"
	.string "Le PROF. CHEN te cherche. Il est\n"
	.string "dans la maison voisine.$"

PalletTown_PlayersHouse_1F_Text_AllGirlsLeaveOakLookingForYou::
	.string "MAMAN: Bon…\p"
	.string "Il paraît que c'est le rêve de\n"
	.string "toutes les filles de voyager.\p"
	.string "Le PROF. CHEN te cherche. Il est\n"
	.string "dans la maison voisine.$"

PalletTown_PlayersHouse_1F_Text_YouShouldTakeQuickRest::
	.string "MAMAN: {PLAYER}!\n"
	.string "Tu devrais faire une sieste.$"

PalletTown_PlayersHouse_1F_Text_LookingGreatTakeCare::
	.string "MAMAN: Ah, bien! Tes POKéMON et\n"
	.string "toi êtes en pleine forme!$"

PalletTown_PlayersHouse_1F_Text_MovieOnTVFourBoysOnRailroad::
	.string "Il y a un film à la télé.\p"
	.string "Y'a un gars cool dans un taxi.\p"
	.string "Bon…\n"
	.string "Je ferais bien d'y aller.$"

PalletTown_PlayersHouse_1F_Text_MovieOnTVGirlOnBrickRoad::
	.string "Il y a un film à la télé.\p"
	.string "C'est le Seigneur des Agneaux.\p"
	.string "Bon…\n"
	.string "Je ferais bien d'y aller.$"

PalletTown_PlayersHouse_1F_Text_OopsWrongSide::
	.string "Oups, mauvais côté.$"

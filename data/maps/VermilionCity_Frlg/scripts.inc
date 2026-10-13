VermilionCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VermilionCity_OnFrame
	.byte 0

VermilionCity_OnFrame::
	map_script_2 VAR_MAP_SCENE_VERMILION_CITY, 2, VermilionCity_EventScript_ExitSSAnne
	.2byte 0

VermilionCity_EventScript_ExitSSAnne::
	lockall
	applymovement LOCALID_PLAYER, VermilionCity_Movement_ExitSSAnne
	waitmovement 0
	setvar VAR_MAP_SCENE_VERMILION_CITY, 3
	releaseall
	end

VermilionCity_Movement_ExitSSAnne::
	walk_up
	walk_up
	step_end

VermilionCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_VERMILION_CITY
	call_if_set FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION, VermilionCity_EventScript_HideOaksAide
	end

VermilionCity_EventScript_HideOaksAide::
	setflag FLAG_HIDE_VERMILION_CITY_OAKS_AIDE
	return

VermilionCity_EventScript_Woman::
	msgbox VermilionCity_Text_GrimerMultipliesInSludge, MSGBOX_NPC
	end

VermilionCity_EventScript_OldMan1::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_OldMan1SSAnneLeft
	msgbox VermilionCity_Text_DidYouSeeSSAnneInHarbor
	release
	end

VermilionCity_EventScript_OldMan1SSAnneLeft::
	msgbox VermilionCity_Text_SSAnneHasDepartedForYear
	release
	end

VermilionCity_EventScript_FerrySailor::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresent
	msgbox VermilionCity_Text_WelcomeToTheSSAnne
	release
	end

VermilionCity_EventScript_CheckHasMysticTicket::
	goto_if_unset FLAG_ENABLE_SHIP_NAVEL_ROCK, EventScript_SetResultFalse
	checkitem ITEM_MYSTIC_TICKET
	goto_if_eq VAR_RESULT, FALSE, EventScript_SetResultFalse
	goto EventScript_SetResultTrue
	end

VermilionCity_EventScript_CheckHasAuroraTicket::
	goto_if_unset FLAG_ENABLE_SHIP_BIRTH_ISLAND, EventScript_SetResultFalse
	checkitem ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, FALSE, EventScript_SetResultFalse
	goto EventScript_SetResultTrue
	end

VermilionCity_EventScript_CheckSeagallopPresent::
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1, VermilionCity_EventScript_ChooseSeagallopDestTriPass
	msgbox VermilionCity_Text_TheShipSetSail
	release
	end

VermilionCity_EventScript_ChooseSeagallopDestRainbowPass::
	call VermilionCity_EventScript_CheckHasMysticTicket
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticTicket
	call VermilionCity_EventScript_CheckHasAuroraTicket
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasAuroraTicket
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	message VermilionCity_Text_BoardSeagallopRainbowPass
	waitmessage
	goto EventScript_SeviiDestinationsPage1
	end

VermilionCity_EventScript_HasMysticTicket::
	call VermilionCity_EventScript_CheckHasAuroraTicket
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticAndAuroraTickets
	call_if_unset FLAG_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
	message VermilionCity_Text_BoardSeagallopFerry
	waitmessage
	multichoice 17, 6, MULTI_SEVII_NAVEL, FALSE
	switch VAR_RESULT
	case 0, EventScript_SeviiDestinationsPage1
	case 1, EventScript_SailToNavelRock
	case 2, EventScript_CancelSail
	case 127, EventScript_CancelSail
	end

VermilionCity_EventScript_ShowMysticTicket::
	setflag FLAG_SHOWN_MYSTIC_TICKET
	msgbox VermilionCity_Text_OhMysticTicketTakeYouToNavelRock
	return

VermilionCity_EventScript_HasAuroraTicket::
	call_if_unset FLAG_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
	message VermilionCity_Text_BoardSeagallopFerry
	waitmessage
	multichoice 13, 6, MULTI_SEVII_BIRTH, FALSE
	switch VAR_RESULT
	case 0, EventScript_SeviiDestinationsPage1
	case 1, EventScript_SailToBirthIsland
	case 2, EventScript_CancelSail
	case 127, EventScript_CancelSail
	end

VermilionCity_EventScript_ShowAuroraTicket::
	setflag FLAG_SHOWN_AURORA_TICKET
	msgbox VermilionCity_Text_OhAuroraTicketTakeYouToBirthIsland
	return

VermilionCity_EventScript_HasMysticAndAuroraTickets::
	call_if_unset FLAG_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
	call_if_unset FLAG_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
	message VermilionCity_Text_BoardSeagallopFerry
	waitmessage
	multichoice 13, 5, MULTI_SEVII_NAVEL_BIRTH, FALSE
	switch VAR_RESULT
	case 0, EventScript_SeviiDestinationsPage1
	case 1, EventScript_SailToNavelRock
	case 2, EventScript_SailToBirthIsland
	case 3, EventScript_CancelSail
	case 127, EventScript_CancelSail
	end

EventScript_SailToNavelRock::
	msgbox VermilionCity_Text_Seagallop10Departing
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	setvar VAR_0x8006, SEAGALLOP_NAVEL_ROCK
	goto EventScript_SetSail
	end

EventScript_SailToBirthIsland::
	msgbox VermilionCity_Text_Seagallop12Departing
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	setvar VAR_0x8006, SEAGALLOP_BIRTH_ISLAND
	goto EventScript_SetSail
	end

VermilionCity_EventScript_ChooseSeagallopDestTriPass::
	message VermilionCity_Text_BoardSeagallopTriPass
	waitmessage
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	multichoice 19, 5, MULTI_SEAGALLOP_123, FALSE
	switch VAR_RESULT
	case 0, EventScript_SailToOneIsland2
	case 1, EventScript_SailToTwoIsland2
	case 2, EventScript_SailToThreeIsland2
	case 3, EventScript_CancelSail
	case 127, EventScript_CancelSail
	end

@ Unreachable
Vermilion_EventScript_Unused::
	release
	end

VermilionCity_EventScript_CheckTicketLeft::
	lockall
	goto VermilionCity_EventScript_CheckTicket
	end

VermilionCity_EventScript_CheckTicketRight::
	lockall
	goto VermilionCity_EventScript_CheckTicket
	end

VermilionCity_EventScript_ExitedTicketCheck::
	lockall
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 0
	releaseall
	end

VermilionCity_EventScript_CheckTicket::
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_VERMILION_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresentTrigger
	msgbox VermilionCity_Text_DoYouHaveATicket
	goto_if_unset FLAG_GOT_SS_TICKET, VermilionCity_EventScript_DontHaveSSTicket
	msgbox VermilionCity_Text_FlashedSSTicket
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 1
	releaseall
	end

VermilionCity_EventScript_DontHaveSSTicket::
	msgbox VermilionCity_Text_DontHaveNeededSSTicket
	closemessage
	goto VermilionCity_EventScript_WalkUpPier
	end

VermilionCity_EventScript_CheckSeagallopPresentTrigger::
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1, VermilionCity_EventScript_ChooseSeagallopDestTriPass
	msgbox VermilionCity_Text_TheShipSetSail
	closemessage
	goto VermilionCity_EventScript_WalkUpPier
	end

VermilionCity_EventScript_Sailor::
	msgbox VermilionCity_Text_SSAnneVisitsOnceAYear, MSGBOX_NPC
	end

VermilionCity_EventScript_OaksAide::
	lock
	faceplayer
	setflag FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION
	msgbox VermilionCity_Text_Route2AideHasPackageForYou
	release
	end

VermilionCity_EventScript_OldMan2::
	msgbox VermilionCity_Text_BuildingOnThisLand, MSGBOX_NPC
	end

VermilionCity_EventScript_Machop::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
	msgbox VermilionCity_Text_Machop
	waitmoncry
	msgbox VermilionCity_Text_MachopStompingLandFlat
	release
	end

VermilionCity_EventScript_CitySign::
	msgbox VermilionCity_Text_CitySign, MSGBOX_SIGN
	end

VermilionCity_EventScript_SnorlaxNotice::
	msgbox VermilionCity_Text_SnorlaxBlockingRoute12, MSGBOX_SIGN
	end

VermilionCity_EventScript_PokemonFanClubSign::
	msgbox VermilionCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

VermilionCity_EventScript_GymSign::
	lockall
	famechecker FAMECHECKER_LTSURGE, 0
	msgbox VermilionCity_Text_GymSign
	releaseall
	end

VermilionCity_EventScript_HarborSign::
	msgbox VermilionCity_Text_VermilionHarbor, MSGBOX_SIGN
	end

VermilionCity_Text_GrimerMultipliesInSludge::
	.string "On fait attention à l'environnement!\p"
	.string "On dit que les TADMORV se\n"
	.string "multiplient en zone toxique!$"

VermilionCity_Text_DidYouSeeSSAnneInHarbor::
	.string "As-tu vu L'OCEANE au port?$"

VermilionCity_Text_SSAnneHasDepartedForYear::
	.string "L'OCEANE a levé l'ancre!\p"
	.string "Il reviendra l'an prochain.$"

VermilionCity_Text_BuildingOnThisLand::
	.string "Je construis un immeuble sur ce\n"
	.string "terrain.\p"
	.string "Mes POKéMON dament le sol\n"
	.string "pour faire les fondations.$"

VermilionCity_Text_Machop::
	.string "MACHOC: Maaaaa! Machoooo!$"

VermilionCity_Text_MachopStompingLandFlat::
	.string "Un MACHOC pilonne le sol.$"

VermilionCity_Text_SSAnneVisitsOnceAYear::
	.string "L'OCEANE est un paquebot de luxe.\p"
	.string "Nous nous rendons à CARMIN SUR\n"
	.string "MER une fois par an.$"

VermilionCity_Text_CitySign::
	.string "CARMIN SUR MER\p"
	.string "Le port aux crépuscules\n"
	.string "flamboyants$"

VermilionCity_Text_SnorlaxBlockingRoute12::
	.string "AVIS!\p"
	.string "La ROUTE 12 peut être bloquée par\n"
	.string "un POKéMON endormi.\p"
	.string "Prendre la GROTTE pour rejoindre\n"
	.string "LAVANVILLE.\p"
	.string "POLICE DE CARMIN SUR MER$"

VermilionCity_Text_PokemonFanClubSign::
	.string "FAN CLUB POKéMON\p"
	.string "Tous les dingues de POKéMON\n"
	.string "sont bienvenus!$"

VermilionCity_Text_GymSign::
	.string "ARENE POKéMON de CARMIN SUR MER\n"
	.string "CHAMPION: MAJOR BOB\l"
	.string "L'Américain Survolté!$"

VermilionCity_Text_VermilionHarbor::
	.string "PORT DE CARMIN SUR MER$"

VermilionCity_Text_WelcomeToTheSSAnne::
	.string "Bienvenue à bord de L'OCEANE!$"

VermilionCity_Text_DoYouHaveATicket::
	.string "Bienvenue à bord de L'OCEANE!\p"
	.string "Puis-je voir votre passe?$"

VermilionCity_Text_FlashedSSTicket::
	.string "{FONT_NORMAL}{PLAYER} montre le\n"
	.string "PASSE BATEAU en frimant.\p"
	.string "{FONT_MALE}Heu… merci!\n"
	.string "Bienvenue à bord!$"

VermilionCity_Text_DontHaveNeededSSTicket::
	.string "{FONT_NORMAL}{PLAYER} n'a pas de passe!\p"
	.string "{FONT_MALE}Désolé!\p"
	.string "Il vous faut un passe pour monter\n"
	.string "à bord.$"

VermilionCity_Text_TheShipSetSail::
	.string "L'OCEANE a levé l'ancre.$"

VermilionCity_Text_BoardSeagallopTriPass::
	.string "Ah, vous avez le TRI-PASSE.\p"
	.string "Voulez-vous monter à bord\n"
	.string "d'un FERRY FLECHE DES MERS?$"

VermilionCity_Text_Seagallop7Departing::
	.string "OK, tout est en ordre.\p"
	.string "Préparez-vous au départ de\n"
	.string "la FLECHE DES MERS 7.$"

VermilionCity_Text_BoardSeagallopRainbowPass::
	.string "Ah, vous avez le PASSE PRISME.\p"
	.string "Voulez-vous monter à bord\n"
	.string "d'un FERRY FLECHE DES MERS?$"

VermilionCity_Text_OhMysticTicketTakeYouToNavelRock::
	.string "Oh, c'est le TICKETMYSTIK!\n"
	.string "C'est un ticket très rare.\p"
	.string "Nous serons heureux de vous\n"
	.string "amener au ROC NOMBRI.$"

VermilionCity_Text_OhAuroraTicketTakeYouToBirthIsland::
	.string "Oh, c'est le TICKETAURORA!\n"
	.string "C'est un ticket très rare.\p"
	.string "Nous serons heureux de vous\n"
	.string "amener à l'ILE AURORE.$"

VermilionCity_Text_BoardSeagallopFerry::
	.string "Voulez-vous monter à bord\n"
	.string "d'un FERRY FLECHE DES MERS?$"

VermilionCity_Text_Seagallop10Departing::
	.string "Très bien, tout est en ordre.\n"
	.string "Vous pouvez monter à bord.\p"
	.string "Préparez-vous au départ de\n"
	.string "la FLECHE DES MERS 10.$"

VermilionCity_Text_Seagallop12Departing::
	.string "Très bien, tout est en ordre.\n"
	.string "Vous pouvez monter à bord.\p"
	.string "Préparez-vous au départ de\n"
	.string "la FLECHE DES MERS 12.$"

VermilionCity_Text_Route2AideHasPackageForYou::
	.string "Tiens, bonjour {PLAYER}!\n"
	.string "Comment vas-tu?\p"
	.string "Je suis un des ASSISTANTS du\n"
	.string "PROF. CHEN.\p"
	.string "Tu as déjà rencontré un autre\n"
	.string "assistant?\p"
	.string "Il avait un paquet pour toi de la\n"
	.string "part du PROFESSEUR.\p"
	.string "Il a dit qu'il partait à ta\n"
	.string "rencontre vers la ROUTE 2.\p"
	.string "Si tu vas par là, essaie de le\n"
	.string "trouver, {PLAYER}.$"


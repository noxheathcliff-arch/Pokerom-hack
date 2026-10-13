CeladonCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_OnTransition
	.byte 0

CeladonCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_CELADON_CITY
	end

CeladonCity_EventScript_LittleGirl::
	msgbox CeladonCity_Text_GotMyKoffingInCinnabar, MSGBOX_NPC
	end

CeladonCity_EventScript_OldMan1::
	lock
	msgbox CeladonCity_Text_GymIsGreatFullOfWomen
	release
	end

CeladonCity_EventScript_Woman::
	msgbox CeladonCity_Text_GameCornerIsBadForCitysImage, MSGBOX_NPC
	end

CeladonCity_EventScript_OldMan2::
	msgbox CeladonCity_Text_BlewItAllAtSlots, MSGBOX_NPC
	end

CeladonCity_EventScript_SoftboiledTutor::
	goto EventScript_SoftboiledTutor
	end

CeladonCity_EventScript_FatMan::
	lock
	faceplayer
	msgbox CeladonCity_Text_MyTrustedPalPoliwrath
	closemessage
	applymovement LOCALID_CELADON_FAT_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeladonCity_EventScript_Poliwrath::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWRATH, CRY_MODE_NORMAL
	msgbox CeladonCity_Text_Poliwrath
	closemessage
	waitmoncry
	applymovement LOCALID_CELADON_POLIWRATH, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeladonCity_EventScript_RocketGrunt1::
	msgbox CeladonCity_Text_KeepOutOfTeamRocketsWay, MSGBOX_NPC
	end

CeladonCity_EventScript_RocketGrunt2::
	msgbox CeladonCity_Text_GetLostOrIllPunchYou, MSGBOX_NPC
	end

CeladonCity_EventScript_Boy::
	msgbox CeladonCity_Text_ScaldedTongueOnTea, MSGBOX_NPC
	end

CeladonCity_EventScript_SilphCoScientist::
	msgbox CeladonCity_Text_SomeoneStoleSilphScope, MSGBOX_NPC
	end

CeladonCity_EventScript_TrainerTips1::
	msgbox CeladonCity_Text_ExplainXAccuracyDireHit, MSGBOX_SIGN
	end

CeladonCity_EventScript_CitySign::
	msgbox CeladonCity_Text_CitySign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GymSign::
	lockall
	famechecker FAMECHECKER_ERIKA, 0
	msgbox CeladonCity_Text_GymSign
	releaseall
	end

CeladonCity_EventScript_MansionSign::
	msgbox CeladonCity_Text_MansionSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_DeptStoreSign::
	msgbox CeladonCity_Text_DeptStoreSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_TrainerTips2::
	msgbox CeladonCity_Text_GuardSpecProtectsFromStatus, MSGBOX_SIGN
	end

CeladonCity_EventScript_PrizeExchangeSign::
	msgbox CeladonCity_Text_PrizeExchangeSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GameCornerSign::
	msgbox CeladonCity_Text_GameCornerSign, MSGBOX_SIGN
	end

CeladonCity_Text_GotMyKoffingInCinnabar::
	.string "J'ai eu mon SMOGO à CRAMOIS'ILE!\p"
	.string "Il est gentil mais il crache du\n"
	.string "poison pour un rien!$"

CeladonCity_Text_GymIsGreatFullOfWomen::
	.string "Héhé! Cette ARENE est terrible!\n"
	.string "Y'a plein de jolies filles!$"

CeladonCity_Text_GameCornerIsBadForCitysImage::
	.string "Nous faisons tout pour que la\n"
	.string "sécurité règne à CELADOPOLE.\p"
	.string "C'est pour ça que ce CASINO n'est\n"
	.string "pas bon pour notre image!$"

CeladonCity_Text_BlewItAllAtSlots::
	.string "Pfff…\n"
	.string "J'ai tout perdu au CASINO!\p"
	.string "J'aurais dû acheter un prix avec\n"
	.string "mes JETONS avant de tout dépenser!$"

CeladonCity_Text_MyTrustedPalPoliwrath::
	.string "C'est mon copain: TARTARD!\p"
	.string "Ce n'était qu'un TETARTE avant\n"
	.string "d'utiliser une PIERRE EAU!$"

CeladonCity_Text_Poliwrath::
	.string "TARTARD: Tarta! Taaaar!$"

CeladonCity_Text_GetLostOrIllPunchYou::
	.string "Kess tu mates?$"

CeladonCity_Text_KeepOutOfTeamRocketsWay::
	.string "Laisse la TEAM tranquille!$"

CeladonCity_Text_ExplainXAccuracyDireHit::
	.string "ASTUCE\p"
	.string "PRECISION + augmente la précision\n"
	.string "des attaques!\p"
	.string "MUSCLE + augmente les chances\n"
	.string "d'effectuer des coups critiques!\p"
	.string "Les meilleurs objets sont en vente\n"
	.string "au CENTRE COMMERCIAL de\l"
	.string "CELADOPOLE!$"

CeladonCity_Text_CitySign::
	.string "CELADOPOLE\n"
	.string "Ville aux rêves arc-en-ciel$"

CeladonCity_Text_GymSign::
	.string "CELADOPOLE ARENE POKéMON\n"
	.string "CHAMPION: ERIKA\l"
	.string "Le combat par les plantes!$"

CeladonCity_Text_MansionSign::
	.string "MANOIR CELADON$"

CeladonCity_Text_DeptStoreSign::
	.string "Au CENTRE COMMERCIAL de\n"
	.string "CELADOPOLE on trouve de tout!$"

CeladonCity_Text_GuardSpecProtectsFromStatus::
	.string "ASTUCE\p"
	.string "DEFENSE SPEC protège les POKéMON\n"
	.string "des changements de statut\l"
	.string "pendant un combat.\p"
	.string "Y'a tout c'qui faut au CENTRE\n"
	.string "COMMERCIAL de CELADOPOLE!$"

CeladonCity_Text_PrizeExchangeSign::
	.string "CHANGE des JETONS contre de\n"
	.string "super prix!$"

CeladonCity_Text_GameCornerSign::
	.string "CASINO ROCKET\n"
	.string "Club de jeu pour adultes!$"

CeladonCity_Text_ScaldedTongueOnTea::
	.string "Aaaah!\n"
	.string "je me suis brûlé la langue!\p"
	.string "La gentille dame de la PENSION\n"
	.string "m'a donné du THE.\p"
	.string "Mais c'était brûlant! J'aurais dû\n"
	.string "souffler un peu dessus avant.$"

Text_SoftboiledTeach::
	.string "Enfin! Depuis le temps que\n"
	.string "je voulais te parler!\p"
	.string "Ça doit être la chance qui nous\n"
	.string "a enfin réunis.\p"
	.string "Je voudrais fêter ça en\n"
	.string "t'apprenant E-COQUE.$"

Text_SoftboiledDeclined::
	.string "Je serai toujours là si tu\n"
	.string "as besoin.\p"
	.string "J'espère qu'on se reverra\n"
	.string "bientôt.$"

Text_SoftboiledWhichMon::
	.string "Alors, quel POKéMON aura la\n"
	.string "chance d'apprendre E-COQUE?$"

Text_SoftboiledTaught::
	.string "Je te souhaite bonne chance!$"

CeladonCity_Text_SomeoneStoleSilphScope::
	.string "Aaaah! Qu'est-ce que je peux\n"
	.string "faire?\p"
	.string "Quelqu'un a volé le SCOPE SYLPHE.\p"
	.string "Le voleur est parti en courant par\n"
	.string "là mais je l'ai perdu de vue.\p"
	.string "Où est-ce qu'il peut bien\n"
	.string "être maintenant?$"


ViridianCity_School_Frlg_MapScripts::
	.byte 0

ViridianCity_School_EventScript_Lass::
	lock
	faceplayer
	msgbox ViridianCity_School_Text_TryingToMemorizeNotes
	closemessage
	applymovement LOCALID_SCHOOL_LASS, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

ViridianCity_School_EventScript_Woman::
	lock
	faceplayer
	msgbox ViridianCity_School_Text_ReadBlackboardCarefully
	closemessage
	applymovement LOCALID_SCHOOL_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

ViridianCity_School_EventScript_Notebook::
	lockall
	msgbox ViridianCity_School_Text_NotebookFirstPage
	msgbox ViridianCity_School_Text_TurnThePage, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_StopReadingNotebook
	msgbox ViridianCity_School_Text_NotebookSecondPage
	msgbox ViridianCity_School_Text_TurnThePage, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_StopReadingNotebook
	msgbox ViridianCity_School_Text_NotebookThirdPage
	msgbox ViridianCity_School_Text_TurnThePage, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_StopReadingNotebook
	msgbox ViridianCity_School_Text_NotebookFourthPage
	applymovement LOCALID_SCHOOL_LASS, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	textcolor NPC_TEXT_COLOR_FEMALE
	msgbox ViridianCity_School_Text_HeyDontLookAtMyNotes
	releaseall
	end

ViridianCity_School_EventScript_StopReadingNotebook::
	releaseall
	end

ViridianCity_School_EventScript_Blackboard::
	lockall
	msgbox ViridianCity_School_Text_BlackboardListsStatusProblems
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ChooseBlackboardTopic::
	message ViridianCity_School_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 7, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, ViridianCity_School_EventScript_ReadSleep
	case 1, ViridianCity_School_EventScript_ReadPoison
	case 2, ViridianCity_School_EventScript_ReadParalysis
	case 3, ViridianCity_School_EventScript_ReadBurn
	case 4, ViridianCity_School_EventScript_ReadFreeze
	case 5, ViridianCity_School_EventScript_ExitBlackboard
	case 127, ViridianCity_School_EventScript_ExitBlackboard
	end

ViridianCity_School_EventScript_ReadSleep::
	msgbox ViridianCity_School_Text_ExplainSleep
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ReadBurn::
	msgbox ViridianCity_School_Text_ExplainBurn
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ReadPoison::
	msgbox ViridianCity_School_Text_ExplainPoison
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ReadFreeze::
	msgbox ViridianCity_School_Text_ExplainFreeze
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ReadParalysis::
	msgbox ViridianCity_School_Text_ExplainParalysis
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
	end

ViridianCity_School_EventScript_ExitBlackboard::
	releaseall
	end

ViridianCity_School_Text_TryingToMemorizeNotes::
	.string "Pfouh!\n"
	.string "J'essaie d'apprendre mes leçons.$"

ViridianCity_School_Text_ReadBlackboardCarefully::
	.string "OK!\p"
	.string "Lis attentivement le tableau\n"
	.string "avant de partir!$"

ViridianCity_School_Text_NotebookFirstPage::
	.string "Vous examinez le journal!\p"
	.string "Première page…\p"
	.string "Les POKé BALLS peuvent capturer\n"
	.string "les POKéMON.\p"
	.string "Jusqu'à 6 POKéMON sont\n"
	.string "transportables.\p"
	.string "Les personnes s'occupant des\n"
	.string "POKéMON sont des DRESSEURS\l"
	.string "de POKéMON.$"

ViridianCity_School_Text_NotebookSecondPage::
	.string "Deuxième page…\p"
	.string "Un POKéMON sauvage et en pleine\n"
	.string "forme est difficile à capturer,\l"
	.string "alors affaiblissez-le!\p"
	.string "Le poison, la brûlure et les autres\n"
	.string "types de dégâts sont aussi\l"
	.string "efficaces!$"

ViridianCity_School_Text_NotebookThirdPage::
	.string "Troisième page…\p"
	.string "Le but de chaque DRESSEUR est\n"
	.string "d'affronter les autres DRESSEURS\l"
	.string "dans des combats de POKéMON.\p"
	.string "Les combats se tiennent en\n"
	.string "permanence dans les ARENES\l"
	.string "POKéMON.$"

ViridianCity_School_Text_NotebookFourthPage::
	.string "Quatrième page…\p"
	.string "Le rêve de chaque DRESSEUR est de\n"
	.string "vaincre les 8 CHAMPIONS des\l"
	.string "différentes ARENES POKéMON.\p"
	.string "Ces victoires donnent le droit\n"
	.string "d'affronter…\p"
	.string "le CONSEIL 4 de la LIGUE\n"
	.string "POKéMON!$"

ViridianCity_School_Text_TurnThePage::
	.string "Tourner la page?$"

ViridianCity_School_Text_HeyDontLookAtMyNotes::
	.string "FILLE: Hé!\n"
	.string "Ne lis pas mon journal!$"

ViridianCity_School_Text_BlackboardListsStatusProblems::
	.string "Le tableau décrit les changements\n"
	.string "de STATUT des POKéMON pendant\l"
	.string "un combat.$"

ViridianCity_School_Text_ReadWhichTopic::
	.string "Lire quel sujet?$"

ViridianCity_School_Text_ExplainSleep::
	.string "Un POKéMON ne peut attaquer\n"
	.string "s'il est endormi!\p"
	.string "Un POKéMON reste endormi même\n"
	.string "après un combat.\p"
	.string "Un REVEIL peut le remettre\n"
	.string "sur pied!$"

ViridianCity_School_Text_ExplainBurn::
	.string "La BRULURE réduit la puissance.\n"
	.string "Elle inflige aussi des dégâts\l"
	.string "continus.\p"
	.string "La brûlure ne disparaît pas après\n"
	.string "un combat.\p"
	.string "L'ANTI-BRULE soigne les grands\n"
	.string "brûlés!$"

ViridianCity_School_Text_ExplainPoison::
	.string "Un POKéMON empoisonné voit son\n"
	.string "énergie se vider doucement.\p"
	.string "Le poison ne disparaît pas après\n"
	.string "un combat.\p"
	.string "L'ANTIDOTE soigne le poison!$"

ViridianCity_School_Text_ExplainFreeze::
	.string "Un POKéMON gelé reste\n"
	.string "immobile!\p"
	.string "Il reste gelé même après la fin du\n"
	.string "combat.\p"
	.string "Un ANTIGEL peut réchauffer un\n"
	.string "POKéMON!$"

ViridianCity_School_Text_ExplainParalysis::
	.string "La paralysie peut annuler certaines\n"
	.string "attaques!\p"
	.string "La paralysie ne disparaît pas après\n"
	.string "un combat.\p"
	.string "L'ANTI-PARA soigne toute paralysie!$"


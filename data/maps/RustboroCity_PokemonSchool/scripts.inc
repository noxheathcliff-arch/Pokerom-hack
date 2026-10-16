RustboroCity_PokemonSchool_MapScripts::
	.byte 0

RustboroCity_PokemonSchool_EventScript_Blackboard::
	lockall
	msgbox RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic::
	message RustboroCity_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_PokemonSchool_EventScript_Poison
	case 1, RustboroCity_PokemonSchool_EventScript_Paralysis
	case 2, RustboroCity_PokemonSchool_EventScript_Sleep
	case 3, RustboroCity_PokemonSchool_EventScript_Burn
	case 4, RustboroCity_PokemonSchool_EventScript_Freeze
	case 5, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	case MULTI_B_PRESSED, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	end

RustboroCity_PokemonSchool_EventScript_Poison::
	msgbox RustboroCity_PokemonSchool_Text_ExplainPoison, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Paralysis::
	msgbox RustboroCity_PokemonSchool_Text_ExplainParalysis, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Sleep::
	msgbox RustboroCity_PokemonSchool_Text_ExplainSleep, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Burn::
	msgbox RustboroCity_PokemonSchool_Text_ExplainBurn, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Freeze::
	msgbox RustboroCity_PokemonSchool_Text_ExplainFreeze, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ExitTopicSelect::
	releaseall
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid1::
	msgbox RustboroCity_PokemonSchool_Text_TradingRightNow, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid2::
	msgbox RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_RichBoy::
	msgbox RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_Lass::
	msgbox RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_SchoolKidM::
	msgbox RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_StudentNotebook::
	msgbox RustboroCity_PokemonSchool_Text_StudentsNotes, MSGBOX_SIGN
	end

RustboroCity_PokemonSchool_EventScript_Teacher::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, RustboroCity_PokemonSchool_EventScript_GaveQuickClaw
	call_if_eq VAR_FACING, DIR_EAST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast
	call_if_eq VAR_FACING, DIR_WEST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest
	msgbox RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setflag FLAG_RECEIVED_QUICK_CLAW
	release
	end

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_GaveQuickClaw::
	msgbox RustboroCity_PokemonSchool_Text_ExplainQuickClaw, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	release
	end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	step_end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

RustboroCity_PokemonSchool_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE, RustboroCity_PokemonSchool_EventScript_ScottWatchStudents
	goto_if_set FLAG_MET_SCOTT_RUSTBORO, RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_RUSTBORO
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready::
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge::
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottWatchStudents::
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges:
	.string "Ce tableau liste les changements de\n"
	.string "statut pouvant toucher les POKéMON\l"
	.string "au combat.$"

RustboroCity_PokemonSchool_Text_ReadWhichTopic:
	.string "Lire quel sujet?$"

RustboroCity_PokemonSchool_Text_ExplainPoison:
	.string "Si un POKéMON est empoisonné, ses PV\n"
	.string "diminuent régulièrement.\p"
	.string "Les effets du poison perdurent\n"
	.string "après un combat.\p"
	.string "Les PV d'un POKéMON empoisonné\n"
	.string "continuent à diminuer hors combat.\p"
	.string "L'ANTIDOTE remédie à l'empoisonnement.$"

RustboroCity_PokemonSchool_Text_ExplainParalysis:
	.string "Si un POKéMON est paralysé, sa\n"
	.string "VITESSE diminue.\p"
	.string "Il peut aussi être dans l'incapacité\n"
	.string "de se déplacer pendant le combat.\p"
	.string "La paralysie persiste après le combat.\n"
	.string "L'ANTI-PARA permet d'y remédier.$"

RustboroCity_PokemonSchool_Text_ExplainSleep:
	.string "Si un POKéMON s'endort, il est\n"
	.string "dans l'incapacité d'attaquer.\p"
	.string "Le POKéMON peut se réveiller de\n"
	.string "lui-même, mais s'il est endormi à\l"
	.string "la fin du combat, il le restera ensuite.\p"
	.string "Le REVEIL le sortira de son sommeil.$"

RustboroCity_PokemonSchool_Text_ExplainBurn:
	.string "Une brûlure réduit la puissance\n"
	.string "d'ATTAQUE et les PV de la victime.\p"
	.string "Une brûlure persiste après le combat.\n"
	.string "L'ANTI-BRULE permet d'y remédier.$"

RustboroCity_PokemonSchool_Text_ExplainFreeze:
	.string "Si un POKéMON est gelé, il n'est\n"
	.string "plus d'aucune aide.\p"
	.string "Il restera gelé après le combat.\n"
	.string "L'ANTIGEL permet de le dégeler.$"

RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw:
	.string "Roxanne est aux mines, alors\n"
	.string "c’est moi qui fais la classe.\p"
	.string "Toi, tu n’es pas inscrit. Mais\n"
	.string "tu as le regard de quelqu’un qui a vu.\p"
	.string "Prends ça. Tu en feras meilleur\n"
	.string "usage que mes élèves.$"

RustboroCity_PokemonSchool_Text_ExplainQuickClaw:
	.string "Un Pokémon qui tient la Vive Griffe\n"
	.string "attaque parfois en premier.\p"
	.string "Face à un arrivant, frapper le\n"
	.string "premier, c’est souvent survivre.\p"
	.string "J’enseignais la stratégie. On me\n"
	.string "demande d’enseigner la survie.$"

RustboroCity_PokemonSchool_Text_TradingRightNow:
	.string "Je fais un échange avec mon copain.\n"
	.string "Un Pokémon contre un autre.\p"
	.string "On doit tout déclarer au Rempart,\n"
	.string "maintenant. Même les échanges!$"

RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot:
	.string "J’ai enfin un Grainipiot!\n"
	.string "Je l’ai déclaré, promis.\p"
	.string "Le monsieur du Rempart l’a pesé,\n"
	.string "mesuré, et il l’a noté.$"

RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems:
	.string "Un Pokémon peut tenir un objet,\n"
	.string "mais pas boire une Potion seul.\p"
	.string "Mon père dit que c’est pareil pour nous.\n"
	.string "On tient ce qu’on nous donne.\p"
	.string "Le Rempart nous donne des ordres.\n"
	.string "Lui, il les tient.$"

RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself:
	.string "Un Pokémon confus peut se\n"
	.string "blesser lui-même.\p"
	.string "En ce moment, toute la ville est\n"
	.string "confuse. On se blesse entre nous.\p"
	.string "Mes parents ne se parlent plus.\n"
	.string "Papa veut entrer dans la brigade.$"

RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry:
	.string "Un Pokémon qui tient une Baie\n"
	.string "se soigne tout seul…\p"
	.string "Je note tout. Comme Roxanne.\n"
	.string "Et comme le garçon du recensement.\p"
	.string "Tu sais, celui qui dit ‘je note’\n"
	.string "tout le temps? C’est mon modèle.$"

RustboroCity_PokemonSchool_Text_StudentsNotes:
	.string "C'est le carnet de cet étudiant…\p"
	.string "On attrape les POKéMON avec des\n"
	.string "POKé BALLS.\p"
	.string "Jusqu'à six POKéMON peuvent\n"
	.string "accompagner un DRESSEUR.\p"
	.string "Un DRESSEUR est une personne\n"
	.string "qui attrape des POKéMON, les fait\l"
	.string "progresser et se bat avec eux.\p"
	.string "L'objectif du DRESSEUR est de battre\n"
	.string "les puissants CHAMPIONS qui attendent\l"
	.string "les adversaires dans les ARÈNES\l"
	.string "POKéMON.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut:
	.string "Ne fais pas attention à moi.\n"
	.string "Je regarde, c’est tout.\p"
	.string "Le Rempart m’envoie repérer les\n"
	.string "élèves doués. Pour la brigade.\p"
	.string "Ils ont douze ans, treize…\n"
	.string "Norman dit que l’âge ne compte pas.\p"
	.string "Toi, tu n’es pas élève. Ce regard-là,\n"
	.string "ça ne s’apprend pas à l’école.\p"
	.string "… J’ai déjà vu ta tête quelque part.\n"
	.string "Bah. Ça me reviendra.$"

RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown:
	.string "Du potentiel, ici. Beaucoup.\n"
	.string "Dommage qu’on les veuille au front.$"

RustboroCity_PokemonSchool_Text_ScottStoneBadge:
	.string "Tiens! C’est l’insigne de Roxanne?\n"
	.string "Elle ne le donne pas souvent.\p"
	.string "Le Rempart voudra ton nom,\n"
	.string "tu sais. Les bons Dresseurs, ça se note.\p"
	.string "Moi, je ne te l’ai pas demandé.\n"
	.string "Retiens-le bien.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge:
	.string "Ne fais pas attention à moi.\n"
	.string "Je repère des élèves pour le Rempart.\p"
	.string "Hé… C’est l’insigne de Roxanne?\n"
	.string "Elle ne le donne pas souvent.\p"
	.string "Le Rempart voudra ton nom,\n"
	.string "tu sais. Les bons Dresseurs, ça se note.\p"
	.string "Moi, je ne te l’ai pas demandé.\n"
	.string "Retiens-le bien.$"


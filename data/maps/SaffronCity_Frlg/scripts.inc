SaffronCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_OnTransition
	.byte 0

SaffronCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SAFFRON_CITY
	call_if_unset FLAG_RESCUED_MR_FUJI, SaffronCity_EventScript_MoveDoorGuardGrunt
	end

SaffronCity_EventScript_MoveDoorGuardGrunt::
	setobjectxyperm LOCALID_SAFFRON_DOOR_GUARD_GRUNT, 33, 31
	return

SaffronCity_EventScript_RocketGrunt1::
	msgbox SaffronCity_Text_WhatDoYouWantGetLost, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt2::
	msgbox SaffronCity_Text_BossTakeTownForTeamRocket, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt3::
	msgbox SaffronCity_Text_DontGetDefiantOrIllHurtYou, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt4::
	msgbox SaffronCity_Text_SaffronBelongsToTeamRocket, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt5::
	msgbox SaffronCity_Text_CriminalLifeMakesMeFeelAlive, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt6::
	msgbox SaffronCity_Text_WatchWhereYoureWalking, MSGBOX_NPC
	end

SaffronCity_EventScript_RocketGrunt7::
	msgbox SaffronCity_Text_WeCanExploitMonsAroundWorld, MSGBOX_NPC
	end

SaffronCity_EventScript_DoorGuardGrunt::
	lock
	goto_if_set FLAG_RESCUED_MR_FUJI, SaffronCity_EventScript_DoorGuardAsleep
	applymovement LOCALID_SAFFRON_DOOR_GUARD_GRUNT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SaffronCity_Text_ImASecurityGuard
	release
	end

SaffronCity_EventScript_DoorGuardAsleep::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox SaffronCity_Text_HesTakingASnooze
	release
	end

SaffronCity_EventScript_WorkerM::
	msgbox SaffronCity_Text_YouBeatTeamRocket, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster::
	msgbox SaffronCity_Text_SafeToGoOutAgain, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass::
	msgbox SaffronCity_Text_PeopleComingBackToSaffron, MSGBOX_NPC
	end

SaffronCity_EventScript_Boy::
	msgbox SaffronCity_Text_FlewHereOnPidgeot, MSGBOX_NPC
	end

SaffronCity_EventScript_Pidgeot::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEOT, CRY_MODE_NORMAL
	msgbox SaffronCity_Text_Pidgeot
	waitmoncry
	release
	end

SaffronCity_EventScript_Man::
	msgbox SaffronCity_Text_SawRocketBossEscaping, MSGBOX_NPC
	end

SaffronCity_EventScript_CitySign::
	msgbox SaffronCity_Text_CitySign, MSGBOX_SIGN
	end

SaffronCity_EventScript_DojoSign::
	msgbox SaffronCity_Text_FightingDojo, MSGBOX_SIGN
	end

SaffronCity_EventScript_GymSign::
	lockall
	famechecker FAMECHECKER_SABRINA, 0
	msgbox SaffronCity_Text_GymSign
	releaseall
	end

SaffronCity_EventScript_TrainerTips1::
	msgbox SaffronCity_Text_FullHealCuresStatus, MSGBOX_SIGN
	end

SaffronCity_EventScript_TrainerTips2::
	msgbox SaffronCity_Text_GreatBallImprovedCatchRate, MSGBOX_SIGN
	end

SaffronCity_EventScript_SilphCoSign::
	msgbox SaffronCity_Text_SilphCoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MrPsychicsHouseSign::
	msgbox SaffronCity_Text_MrPsychicsHouse, MSGBOX_SIGN
	end

SaffronCity_EventScript_SilphProductSign::
	msgbox SaffronCity_Text_SilphsLatestProduct, MSGBOX_SIGN
	end

SaffronCity_EventScript_TrainerFanClubSign::
	msgbox SaffronCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

SaffronCity_Text_WhatDoYouWantGetLost::
	.string "Kess tu veux?\n"
	.string "Du vent!$"

SaffronCity_Text_BossTakeTownForTeamRocket::
	.string "Le CHEF dit qu'il contrôlera\n"
	.string "cette ville!$"

SaffronCity_Text_DontGetDefiantOrIllHurtYou::
	.string "Bouge de là!$"

SaffronCity_Text_SaffronBelongsToTeamRocket::
	.string "SAFRANIA appartient à la\n"
	.string "TEAM ROCKET!$"

SaffronCity_Text_CriminalLifeMakesMeFeelAlive::
	.string "Rien de mieux qu'une vie de\n"
	.string "criminel pour se sentir vivant!$"

SaffronCity_Text_WatchWhereYoureWalking::
	.string "Tu m'as marché sur le pied,\n"
	.string "non?$"

SaffronCity_Text_WeCanExploitMonsAroundWorld::
	.string "Avec la SYLPHE dans notre poche,\n"
	.string "les POKéMON du monde entier\p"
	.string "seront à nous! On va être\n"
	.string "super riches.$"

SaffronCity_Text_YouBeatTeamRocket::
	.string "Tu as vraiment battu la TEAM\n"
	.string "ROCKET? Incroyable!$"

SaffronCity_Text_SafeToGoOutAgain::
	.string "Ouais! La TEAM est partie!\n"
	.string "On peut enfin respirer!$"

SaffronCity_Text_PeopleComingBackToSaffron::
	.string "Tout le monde va vite revenir à\n"
	.string "SAFRANIA maintenant que\p"
	.string "la TEAM ROCKET est partie.$"

SaffronCity_Text_FlewHereOnPidgeot::
	.string "Je suis venu ici en volant sur mon\n"
	.string "ROUCARNAGE après avoir lu les\p"
	.string "nouvelles de la SYLPHE.\p"
	.string "Tout est déjà fini?\n"
	.string "J'ai tout loupé?$"

SaffronCity_Text_Pidgeot::
	.string "ROUCARNAGE: Rou!$"

SaffronCity_Text_SawRocketBossEscaping::
	.string "J'ai vu le CHEF de la TEAM ROCKET\n"
	.string "s'enfuir de la SYLPHE.$"

SaffronCity_Text_ImASecurityGuard::
	.string "Moi…\n"
	.string "J'suis un garde.\p"
	.string "Les nabots tout louches, moi,\n"
	.string "j'les laisse pas passer!$"

SaffronCity_Text_HesTakingASnooze::
	.string "…\n"
	.string "(ronffl)…\p"
	.string "Ah! Il dort!$"

SaffronCity_Text_CitySign::
	.string "SAFRANIA\n"
	.string "Là où le commerce est roi$"

SaffronCity_Text_FightingDojo::
	.string "DOJO$"

SaffronCity_Text_GymSign::
	.string "ARENE POKéMON de SAFRANIA \n"
	.string "CHAMPION: MORGANE\l"
	.string "Maîtresse des POKéMON PSY!$"

SaffronCity_Text_FullHealCuresStatus::
	.string "ASTUCE\p"
	.string "TOTAL SOIN fait disparaître tous\n"
	.string "les changements de statut\p"
	.string "comme sommeil, brûlure,\n"
	.string "paralysie ou gel par exemple.\p"
	.string "C'est un peu cher mais ça vaut\n"
	.string "le coup.$"

SaffronCity_Text_GreatBallImprovedCatchRate::
	.string "ASTUCE\p"
	.string "La SUPER BALL augmente les\n"
	.string "chances de capture.\p"
	.string "Faites un essai sur des POKéMON\n"
	.string "difficiles à attraper.$"

SaffronCity_Text_SilphCoSign::
	.string "SYLPHE SARL SIEGE SOCIAL$"

SaffronCity_Text_MrPsychicsHouse::
	.string "MAISON DE MR. PSY$"

SaffronCity_Text_SilphsLatestProduct::
	.string "Dernier produit de la SYLPHE!\p"
	.string "La date de sortie est encore à\n"
	.string "déterminer…$"

SaffronCity_Text_TrainerFanClubSign::
	.string "FAN CLUB DES DRESSEURS POKéMON\p"
	.string "Des noms de DRESSEURS sont\n"
	.string "inscrits sur le panneau…$"

SaffronCity_Text_HowCanClubNotRecognizeLance::
	.string "Ce FAN CLUB…\n"
	.string "Personne n'a une petite idée?\p"
	.string "Comment ne peuvent-ils pas\n"
	.string "reconnaître le génie de PETER?\p"
	.string "Il défend la justice!\n"
	.string "Il est posé et pourtant passionné!\l"
	.string "C'est le plus grand, c'est PETER!$"


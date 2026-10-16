Route116_TunnelersRestHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_TunnelersRestHouse_OnTransition
	.byte 0

Route116_TunnelersRestHouse_OnTransition:
	setflag FLAG_LANDMARK_TUNNELERS_REST_HOUSE
	end

Route116_TunnelersRestHouse_EventScript_Tunneler1::
	msgbox Route116_TunnelersRestHouse_Text_WeHadToStopBoring, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler2::
	msgbox Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler3::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, Route116_TunnelersRestHouse_EventScript_TunnelOpened
	msgbox Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_EventScript_TunnelOpened::
	msgbox Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_Text_WeHadToStopBoring:
	.string "Le Tunnel Mérazon, c’est là-bas.\n"
	.string "On le perçait pour Vergazon.\p"
	.string "Puis les anneaux. Des arrivants\n"
	.string "dans les galeries. Ça mange le charbon!\p"
	.string "Les étais craquent, ça s’effondre.\n"
	.string "Chantier arrêté. On attend.\p"
	.string "On attend quoi? Personne ne sait.\n"
	.string "La paie, peut-être.$"

Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf:
	.string "Un type creuse seul vers Vergazon.\n"
	.string "À la main, sans machine.\p"
	.string "Il dit qu’il ne dérange pas les\n"
	.string "arrivants. Qu’eux le laissent passer.\p"
	.string "Le reste de l’équipe le croit fou.\n"
	.string "Moi, je l’envie un peu.\p"
	.string "Et la nuit, des hommes en noir\n"
	.string "passent devant. Avec des cages.$"

Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel:
	.string "Hé! C’est un local d’ouvriers, ici.\n"
	.string "Pas une salle d’attente.\p"
	.string "Tu veux Vergazon? Sans le tunnel,\n"
	.string "il faut le bateau jusqu’à Myokara.\p"
	.string "Et les ports sont fermés. Alors tu\n"
	.string "attends, comme nous tous.$"

Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough:
	.string "Le tunnel pour Vergazon est\n"
	.string "enfin percé!\p"
	.string "Avec les arrivants, ça a pris\n"
	.string "des mois. Mais on a tenu.$"


CeruleanCity_Gym_Frlg_MapScripts::
	.byte 0

CeruleanCity_Gym_EventScript_Misty::
	famechecker FAMECHECKER_MISTY, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_MISTY, CeruleanCity_Gym_Text_MistyIntro, CeruleanCity_Gym_Text_MistyDefeat, CeruleanCity_Gym_EventScript_MistyDefeated, NO_MUSIC
	goto_if_unset FLAG_GOT_TM03_FROM_MISTY, CeruleanCity_Gym_EventScript_GiveTM03
	msgbox CeruleanCity_Gym_Text_ExplainTM03
	release
	end

CeruleanCity_Gym_EventScript_MistyDefeated::
	famechecker FAMECHECKER_MISTY, 1
	setflag FLAG_DEFEATED_MISTY
	setflag FLAG_BADGE02_GET
	setrespawn HEAL_LOCATION_CERULEAN_CITY
	set_gym_trainers_frlg 2
	goto CeruleanCity_Gym_EventScript_GiveTM03
	end

CeruleanCity_Gym_EventScript_GiveTM03::
	msgbox CeruleanCity_Gym_Text_ExplainCascadeBadge
	checkitemspace ITEM_TM03
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_Gym_EventScript_NoRoomForTM03
	giveitem_msg CeruleanCity_Gym_Text_ReceivedTM03FromMisty, ITEM_TM03
	setflag FLAG_GOT_TM03_FROM_MISTY
	msgbox CeruleanCity_Gym_Text_ExplainTM03
	release
	end

CeruleanCity_Gym_EventScript_NoRoomForTM03::
	msgbox CeruleanCity_Gym_Text_BetterMakeRoomForThis
	release
	end

CeruleanCity_Gym_EventScript_Diana::
	trainerbattle_single TRAINER_PICNICKER_DIANA, CeruleanCity_Gym_Text_DianaIntro, CeruleanCity_Gym_Text_DianaDefeat
	msgbox CeruleanCity_Gym_Text_DianaPostBattle, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_Luis::
	trainerbattle_single TRAINER_SWIMMER_MALE_LUIS, CeruleanCity_Gym_Text_LuisIntro, CeruleanCity_Gym_Text_LuisDefeat
	famechecker FAMECHECKER_MISTY, 2
	msgbox CeruleanCity_Gym_Text_LuisPostBattle, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MISTY, CeruleanCity_Gym_EventScript_GymGuyPostVictory
	msgbox CeruleanCity_Gym_Text_GymGuyAdvice
	release
	end

CeruleanCity_Gym_EventScript_GymGuyPostVictory::
	msgbox CeruleanCity_Gym_Text_WeMakePrettyGoodTeam
	release
	end

CeruleanCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, CeruleanCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeruleanCity_Gym_Text_GymStatue
	releaseall
	end

CeruleanCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeruleanCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeruleanCity_Gym_Text_MistyIntro::
	.string "Tiens, un nouveau visage!\p"
	.string "Si tu veux être un vrai DRESSEUR,\n"
	.string "il te faut une stratégie pour tes\l"
	.string "POKéMON!\p"
	.string "C'est quoi ta tactique pour\n"
	.string "capturer les POKéMON sauvages?\p"
	.string "Ma tactique? Attaquer\n"
	.string "avec des POKéMON EAU!{PLAY_BGM MUS_RG_ENCOUNTER_GYM_LEADER}$"

CeruleanCity_Gym_Text_ExplainTM03::
	.string "La CT03 contient VIBRAQUA!\p"
	.string "Apprends-la à un POKéMON EAU!$"

CeruleanCity_Gym_Text_ExplainCascadeBadge::
	.string "Le BADGECASCADE oblige tous les\n"
	.string "POKéMON d'un niveau inférieur à 30\l"
	.string "à t'obéir!\p"
	.string "Cela comprend aussi les POKéMON\n"
	.string "obtenus pendant un échange.\p"
	.string "En plus, tu peux maintenant\n"
	.string "utiliser la CS COUPE,\l"
	.string "même hors des combats!\p"
	.string "Tu peux COUPER les arbustes et\n"
	.string "ouvrir de nouveaux chemins!\p"
	.string "Tu gagnes aussi ma CT favorite!$"

CeruleanCity_Gym_Text_ReceivedTM03FromMisty::
	.string "{PLAYER} reçoit\n"
	.string "la CT03!$"

CeruleanCity_Gym_Text_BetterMakeRoomForThis::
	.string "Ton inventaire est plein!$"

CeruleanCity_Gym_Text_MistyDefeat::
	.string "Whouha!\n"
	.string "T'es super balèze!\p"
	.string "Très bien!\p"
	.string "Je te donne le BADGECASCADE pour\n"
	.string "m'avoir battue!$"

CeruleanCity_Gym_Text_DianaIntro::
	.string "Je suis assez bonne pour toi!\p"
	.string "ONDINE attendra!$"

CeruleanCity_Gym_Text_DianaDefeat::
	.string "Oh!\n"
	.string "J'me suis fait écraser!$"

CeruleanCity_Gym_Text_DianaPostBattle::
	.string "Tu dois te battre contre d'autres\n"
	.string "DRESSEURS pour connaître ton\l"
	.string "vrai niveau.$"

CeruleanCity_Gym_Text_LuisIntro::
	.string "Plaouff!\p"
	.string "J'suis preums!\n"
	.string "Baston!$"

CeruleanCity_Gym_Text_LuisDefeat::
	.string "Glargh!\n"
	.string "C'est dingue!$"

CeruleanCity_Gym_Text_LuisPostBattle::
	.string "ONDINE est super forte!\p"
	.string "Elle ne va pas se faire avoir par\n"
	.string "quelqu'un comme toi!$"

CeruleanCity_Gym_Text_GymGuyAdvice::
	.string "Salut à toi!\n"
	.string "Futur CHAMPION!\p"
	.string "Un conseil?\p"
	.string "Le CHAMPION, ONDINE, est une\n"
	.string "spécialiste des POKéMON EAU.\p"
	.string "Mais tu peux absorber l'EAU avec\n"
	.string "des POKéMON PLANTE!\p"
	.string "Ou, tu peux aussi les griller avec\n"
	.string "des POKéMON ELECTRIK.$"

CeruleanCity_Gym_Text_WeMakePrettyGoodTeam::
	.string "Tu as battu ONDINE! Génial!\p"
	.string "Toi et moi, on forme une super\n"
	.string "équipe!$"

CeruleanCity_Gym_Text_GymStatue::
	.string "ARENE POKéMON d'AZURIA\n"
	.string "CHAMPION: ONDINE\p"
	.string "VAINQUEURS:\n"
	.string "{RIVAL}$"

CeruleanCity_Gym_Text_GymStatuePlayerWon::
	.string "ARENE POKéMON d'AZURIA\n"
	.string "CHAMPION: ONDINE\p"
	.string "VAINQUEURS:\n"
	.string "{RIVAL}, {PLAYER}$"


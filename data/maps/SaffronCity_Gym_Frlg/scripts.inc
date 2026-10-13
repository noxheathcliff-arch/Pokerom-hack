SaffronCity_Gym_Frlg_MapScripts::
	.byte 0

SaffronCity_Gym_EventScript_Sabrina::
	famechecker FAMECHECKER_SABRINA, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_SABRINA, SaffronCity_Gym_Text_SabrinaIntro, SaffronCity_Gym_Text_SabrinaDefeat, SaffronCity_Gym_EventScript_DefeatedSabrina, NO_MUSIC
	goto_if_unset FLAG_GOT_TM04_FROM_SABRINA, SaffronCity_Gym_EventScript_GiveTM04
	msgbox SaffronCity_Gym_Text_ExplainTM04
	release
	end

SaffronCity_Gym_EventScript_DefeatedSabrina::
	famechecker FAMECHECKER_SABRINA, 2
	famechecker FAMECHECKER_SABRINA, 3
	clearflag FLAG_HIDE_SAFFRON_CITY_POKECENTER_SABRINA_JOURNALS
	setflag FLAG_DEFEATED_SABRINA
	setflag FLAG_BADGE06_GET
	set_gym_trainers_frlg 6
	goto SaffronCity_Gym_EventScript_GiveTM04
	end

SaffronCity_Gym_EventScript_GiveTM04::
	msgbox SaffronCity_Gym_Text_ExplainMarshBadgeTakeThis
	checkitemspace ITEM_TM04
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_Gym_EventScript_NoRoomForTM04
	giveitem_msg SaffronCity_Gym_Text_ReceivedTM04FromSabrina, ITEM_TM04
	setflag FLAG_GOT_TM04_FROM_SABRINA
	msgbox SaffronCity_Gym_Text_SabrinaPostBattle
	release
	end

SaffronCity_Gym_EventScript_NoRoomForTM04::
	msgbox SaffronCity_Gym_Text_BagFullOfOtherItems
	release
	end

SaffronCity_Gym_EventScript_Johan::
	trainerbattle_single TRAINER_PSYCHIC_JOHAN, SaffronCity_Gym_Text_JohanIntro, SaffronCity_Gym_Text_JohanDefeat
	msgbox SaffronCity_Gym_Text_JohanPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Tyron::
	trainerbattle_single TRAINER_PSYCHIC_TYRON, SaffronCity_Gym_Text_TyronIntro, SaffronCity_Gym_Text_TyronDefeat
	famechecker FAMECHECKER_SABRINA, 5
	msgbox SaffronCity_Gym_Text_TyronPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Cameron::
	trainerbattle_single TRAINER_PSYCHIC_CAMERON, SaffronCity_Gym_Text_CameronIntro, SaffronCity_Gym_Text_CameronDefeat
	msgbox SaffronCity_Gym_Text_CameronPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_PSYCHIC_PRESTON, SaffronCity_Gym_Text_PrestonIntro, SaffronCity_Gym_Text_PrestonDefeat
	msgbox SaffronCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Amanda::
	trainerbattle_single TRAINER_CHANNELER_AMANDA, SaffronCity_Gym_Text_AmandaIntro, SaffronCity_Gym_Text_AmandaDefeat
	msgbox SaffronCity_Gym_Text_AmandaPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Stacy::
	trainerbattle_single TRAINER_CHANNELER_STACY, SaffronCity_Gym_Text_StacyIntro, SaffronCity_Gym_Text_StacyDefeat
	msgbox SaffronCity_Gym_Text_StacyPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Tasha::
	trainerbattle_single TRAINER_CHANNELER_TASHA, SaffronCity_Gym_Text_TashaIntro, SaffronCity_Gym_Text_TashaDefeat
	msgbox SaffronCity_Gym_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SABRINA, SaffronCity_Gym_EventScript_GymGuyPostVictory
	msgbox SaffronCity_Gym_Text_GymGuyAdvice
	release
	end

SaffronCity_Gym_EventScript_GymGuyPostVictory::
	msgbox SaffronCity_Gym_Text_GymGuyPostVictory
	release
	end

SaffronCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, SaffronCity_Gym_EventScript_GymStatuePostVictory
	msgbox SaffronCity_Gym_Text_GymStatue
	releaseall
	end

SaffronCity_Gym_EventScript_GymStatuePostVictory::
	msgbox SaffronCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

SaffronCity_Gym_Text_SabrinaIntro::
	.string "J'avais prédit ton arrivée!\p"
	.string "J'ai des pouvoirs psychiques depuis\n"
	.string "l'enfance.\p"
	.string "J'ai appris à plier des cuillères\n"
	.string "par la force de l'esprit. C'est\l"
	.string "pas super utile, mais ça en jette!\p"
	.string "Je n'aime pas les combats, mais si\n"
	.string "tu insistes, je vais te montrer mes\l"
	.string "pouvoirs!$"

SaffronCity_Gym_Text_SabrinaDefeat::
	.string "Ha! Je suis surprise!\n"
	.string "Tu as gagné.\p"
	.string "C'est vrai, je n'ai pas fait de mon\n"
	.string "mieux! Tu mérites ta victoire!\p"
	.string "Tu gagnes le BADGE MARAIS!$"

SaffronCity_Gym_Text_SabrinaPostBattle::
	.string "Tout le monde est un peu médium!\n"
	.string "Il faut juste travailler ses dons!$"

SaffronCity_Gym_Text_ExplainMarshBadgeTakeThis::
	.string "Avec le BADGE MARAIS, les POKéMON\n"
	.string "de niveau 70 t'obéiront!\p"
	.string "Les POKéMON plus puissants seront\n"
	.string "incontrôlables lors des combats!\p"
	.string "Fais en sorte que tes POKéMON ne\n"
	.string "dépassent pas cette limite!\p"
	.string "Tiens! Prends ça aussi!$"

SaffronCity_Gym_Text_ReceivedTM04FromSabrina::
	.string "{PLAYER} reçoit la CT04\n"
	.string "de MORGANE.$"

SaffronCity_Gym_Text_ExplainTM04::
	.string "C'est PLENITUDE.\p"
	.string "Avec cette capacité, les POKéMON\n"
	.string "se concentrent et augmentent leur\p"
	.string "ATQ. SPE. et leur DEF. SPE.$"

SaffronCity_Gym_Text_BagFullOfOtherItems::
	.string "Ton inventaire est plein!$"

SaffronCity_Gym_Text_AmandaIntro::
	.string "MORGANE est une petite parvenue!\n"
	.string "Mais je l'aime bien!$"

SaffronCity_Gym_Text_AmandaDefeat::
	.string "Rhhâ!\n"
	.string "J'suis nulle!$"

SaffronCity_Gym_Text_AmandaPostBattle::
	.string "Dans une baston, ce qui est\n"
	.string "important, c'est la volonté de\l"
	.string "gagner!\p"
	.string "Si tu veux gagner face à MORGANE,\n"
	.string "concentre-toi sur la victoire!$"

SaffronCity_Gym_Text_JohanIntro::
	.string "Nos pouvoirs occultes te font\n"
	.string "peur?$"

SaffronCity_Gym_Text_JohanDefeat::
	.string "Nyan!\n"
	.string "T'as pas l'air effrayé!$"

SaffronCity_Gym_Text_JohanPostBattle::
	.string "Les POKéMON PSY craignent les\n"
	.string "INSECTES et les SPECTRES!$"

SaffronCity_Gym_Text_StacyIntro::
	.string "L'aura du maître déteint sur ses\n"
	.string "POKéMON.\p"
	.string "Tes POKéMON doivent être\n"
	.string "forts alors!$"

SaffronCity_Gym_Text_StacyDefeat::
	.string "Argh!\n"
	.string "Je l'savais!$"

SaffronCity_Gym_Text_StacyPostBattle::
	.string "J'ai encore beaucoup à apprendre…\p"
	.string "Je dois maîtriser PSYKO et\n"
	.string "l'enseigner à mes POKéMON.$"

SaffronCity_Gym_Text_TyronIntro::
	.string "Tu comprends hein?\p"
	.string "La puissance seule sans la\n"
	.string "maîtrise ne sert à rien!$"

SaffronCity_Gym_Text_TyronDefeat::
	.string "Huh!\n"
	.string "J'appelle pas ça rien!$"

SaffronCity_Gym_Text_TyronPostBattle::
	.string "MORGANE a pulvérisé le grand\n"
	.string "MAITRE de KARATE!$"

SaffronCity_Gym_Text_TashaIntro::
	.string "Toi… Moi… Nos POKéMON…\n"
	.string "FIGHT!$"

SaffronCity_Gym_Text_TashaDefeat::
	.string "Puff!\n"
	.string "J'ai perdu!$"

SaffronCity_Gym_Text_TashaPostBattle::
	.string "J'avais prévu ce qui s'est passé.$"

SaffronCity_Gym_Text_CameronIntro::
	.string "MORGANE est jeune mais c'est\n"
	.string "aussi notre CHAMPION!\p"
	.string "Tu vas en baver avant\n"
	.string "de l'atteindre!$"

SaffronCity_Gym_Text_CameronDefeat::
	.string "Oups!\n"
	.string "J'ai rien capté!$"

SaffronCity_Gym_Text_CameronPostBattle::
	.string "Il y avait deux ARENES POKéMON à\n"
	.string "SAFRANIA.\p"
	.string "Le DOJO KARATE a perdu son titre\n"
	.string "d'ARENE le jour où nous l'avons\l"
	.string "pulvérisé!\p"
	.string "Il ne pouvait pas y avoir deux\n"
	.string "ARENES ici.$"

SaffronCity_Gym_Text_PrestonIntro::
	.string "Le CHAMPION de l'ARENE POKéMON\n"
	.string "de SAFRANIA est une médium psy!\p"
	.string "Tu veux voir MORGANE, hein?\n"
	.string "Je lis tes pensées, ne mens pas!$"

SaffronCity_Gym_Text_PrestonDefeat::
	.string "Arrrgh!$"

SaffronCity_Gym_Text_PrestonPostBattle::
	.string "J'ai lu dans ton esprit! C'est pas\n"
	.string "très clair dedans!$"

SaffronCity_Gym_Text_GymGuyAdvice::
	.string "Salut!\n"
	.string "Graine de CHAMPION!\p"
	.string "Les POKéMON de MORGANE sont\n"
	.string "des POKéMON PSY!\p"
	.string "Les POKéMON COMBAT sont\n"
	.string "désavantagés!\p"
	.string "Ils deviennent dingues avant de\n"
	.string "pouvoir porter un coup!$"

SaffronCity_Gym_Text_GymGuyPostVictory::
	.string "Pouvoirs psy? Hmmm…\n"
	.string "Si j'en avais, je gagnerais!$"

SaffronCity_Gym_Text_GymStatue::
	.string "ARENE POKéMON de SAFRANIA\n"
	.string "CHAMPION: MORGANE\p"
	.string "VAINQUEURS:\n"
	.string "{RIVAL}$"

SaffronCity_Gym_Text_GymStatuePlayerWon::
	.string "ARENE POKéMON de SAFRANIA\n"
	.string "CHAMPION: MORGANE\p"
	.string "VAINQUEURS:\n"
	.string "{RIVAL}, {PLAYER}$"


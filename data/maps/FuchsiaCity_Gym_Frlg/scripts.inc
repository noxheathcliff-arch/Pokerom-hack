FuchsiaCity_Gym_Frlg_MapScripts::
	.byte 0

FuchsiaCity_Gym_EventScript_Koga::
	famechecker FAMECHECKER_KOGA, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_KOGA, FuchsiaCity_Gym_Text_KogaIntro, FuchsiaCity_Gym_Text_KogaDefeat, FuchsiaCity_Gym_EventScript_DefeatedKoga, NO_MUSIC
	goto_if_unset FLAG_GOT_TM06_FROM_KOGA, FuchsiaCity_Gym_EventScript_GiveTM06
	msgbox FuchsiaCity_Gym_Text_KogaPostBattle
	release
	end

FuchsiaCity_Gym_EventScript_DefeatedKoga::
	famechecker FAMECHECKER_KOGA, 1
	clearflag FLAG_HIDE_FAME_CHECKER_KOGA_JOURNAL
	setflag FLAG_DEFEATED_KOGA
	setflag FLAG_BADGE05_GET
	set_gym_trainers_frlg 5
	goto FuchsiaCity_Gym_EventScript_GiveTM06
	end

FuchsiaCity_Gym_EventScript_GiveTM06::
	msgbox FuchsiaCity_Gym_Text_KogaExplainSoulBadge
	checkitemspace ITEM_TM06
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_Gym_EventScript_NoRoomForTM06
	giveitem_msg FuchsiaCity_Gym_Text_ReceivedTM06FromKoga, ITEM_TM06
	setflag FLAG_GOT_TM06_FROM_KOGA
	msgbox FuchsiaCity_Gym_Text_KogaExplainTM06
	release
	end

FuchsiaCity_Gym_EventScript_NoRoomForTM06::
	msgbox FuchsiaCity_Gym_Text_MakeSpaceForThis
	release
	end

FuchsiaCity_Gym_EventScript_Phil::
	trainerbattle_single TRAINER_TAMER_PHIL, FuchsiaCity_Gym_Text_PhilIntro, FuchsiaCity_Gym_Text_PhilDefeat
	msgbox FuchsiaCity_Gym_Text_PhilPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Edgar::
	trainerbattle_single TRAINER_TAMER_EDGAR, FuchsiaCity_Gym_Text_EdgarIntro, FuchsiaCity_Gym_Text_EdgarDefeat
	msgbox FuchsiaCity_Gym_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Kirk::
	trainerbattle_single TRAINER_JUGGLER_KIRK, FuchsiaCity_Gym_Text_KirkIntro, FuchsiaCity_Gym_Text_KirkDefeat
	famechecker FAMECHECKER_KOGA, 2
	msgbox FuchsiaCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Shawn::
	trainerbattle_single TRAINER_JUGGLER_SHAWN, FuchsiaCity_Gym_Text_ShawnIntro, FuchsiaCity_Gym_Text_ShawnDefeat
	msgbox FuchsiaCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Kayden::
	trainerbattle_single TRAINER_JUGGLER_KAYDEN, FuchsiaCity_Gym_Text_KaydenIntro, FuchsiaCity_Gym_Text_KaydenDefeat
	msgbox FuchsiaCity_Gym_Text_KaydenPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Nate::
	trainerbattle_single TRAINER_JUGGLER_NATE, FuchsiaCity_Gym_Text_NateIntro, FuchsiaCity_Gym_Text_NateDefeat
	msgbox FuchsiaCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_KOGA, FuchsiaCity_Gym_EventScript_GymGuyPostVictory
	msgbox FuchsiaCity_Gym_Text_GymGuyAdvice
	release
	end

FuchsiaCity_Gym_EventScript_GymGuyPostVictory::
	msgbox FuchsiaCity_Gym_Text_GymGuyPostVictory
	release
	end

FuchsiaCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE05_GET, FuchsiaCity_Gym_EventScript_GymStatuePostVictory
	msgbox FuchsiaCity_Gym_Text_GymStatue
	releaseall
	end

FuchsiaCity_Gym_EventScript_GymStatuePostVictory::
	msgbox FuchsiaCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

FuchsiaCity_Gym_Text_KogaIntro::
	.string "KOGA: Gwahahaha!\p"
	.string "Tu oses me défier? Moi, le\n"
	.string "grand, le beau, le terrible KOGA?\p"
	.string "Par l'enfer, par le sang, par\n"
	.string "l'acier, j'vais gagner!\p"
	.string "Prépare-toi à affronter mes\n"
	.string "terribles POKéMON POISON!{PLAY_BGM MUS_RG_ENCOUNTER_GYM_LEADER}$"

FuchsiaCity_Gym_Text_KogaDefeat::
	.string "… heu?\n"
	.string "Tu as prouvé ta valeur!\p"
	.string "Ouvre ta main, car voici…\n"
	.string "le BADGE AME!$"

FuchsiaCity_Gym_Text_KogaPostBattle::
	.string "TOXIK fera souffrir de plus en plus\n"
	.string "un POKéMON pendant un combat!\p"
	.string "Les dégâts augmentent si le\n"
	.string "combat se prolonge!\p"
	.string "De quoi terroriser ses ennemis.$"

FuchsiaCity_Gym_Text_KogaExplainSoulBadge::
	.string "Le BADGE AME fera monter la\n"
	.string "DEFENSE de tes POKéMON!\p"
	.string "Il te permettra aussi d'utiliser\n"
	.string "SURF hors des combats!\p"
	.string "Attends!\n"
	.string "Prends aussi ceci!$"

FuchsiaCity_Gym_Text_ReceivedTM06FromKoga::
	.string "{PLAYER} reçoit la\n"
	.string "CT06!$"

FuchsiaCity_Gym_Text_KogaExplainTM06::
	.string "CT06: TOXIK!\p"
	.string "Cette technique secrète et sacrée\n"
	.string "est vieille d'au moins 400 ans.$"

FuchsiaCity_Gym_Text_MakeSpaceForThis::
	.string "Ton inventaire est plein!$"

FuchsiaCity_Gym_Text_KaydenIntro::
	.string "La force ne fait pas tout.\p"
	.string "Avec les POKéMON, l'important\n"
	.string "est d'avoir une bonne stratégie.\p"
	.string "Je te prouverai que la stratégie\n"
	.string "peut vaincre la force.$"

FuchsiaCity_Gym_Text_KaydenDefeat::
	.string "Que?\n"
	.string "Que quoi?$"

FuchsiaCity_Gym_Text_KaydenPostBattle::
	.string "Alors tu mélanges la force\n"
	.string "et l'esprit.\p"
	.string "C'est remarquable pour un DRESSEUR\n"
	.string "de ton âge.$"

FuchsiaCity_Gym_Text_KirkIntro::
	.string "Avant, j'étais magicien.\p"
	.string "Mais j'veux devenir ninja, alors\n"
	.string "j'ai rejoint cette ARENE!$"

FuchsiaCity_Gym_Text_KirkDefeat::
	.string "…\n"
	.string "C'est fini pour moi!$"

FuchsiaCity_Gym_Text_KirkPostBattle::
	.string "Je garderai espoir même dans la\n"
	.string "défaite, selon l'enseignement de\p"
	.string "KOGA, mon maître ninja.$"

FuchsiaCity_Gym_Text_NateIntro::
	.string "Crois-tu pouvoir me battre? Haha!\n"
	.string "Voyons ta technique!$"

FuchsiaCity_Gym_Text_NateDefeat::
	.string "Quoi?\n"
	.string "Tu m'as trompé!$"

FuchsiaCity_Gym_Text_NatePostBattle::
	.string "Les attaques de poison et de\n"
	.string "sommeil sont très puissantes! Oui!$"

FuchsiaCity_Gym_Text_PhilIntro::
	.string "Ne bouge plus!\p"
	.string "Nos fameux murs invisibles sont\n"
	.string "sympas, non? Ça t'énerve?$"

FuchsiaCity_Gym_Text_PhilDefeat::
	.string "Whoa!\n"
	.string "Tu m'as eu!$"

FuchsiaCity_Gym_Text_PhilPostBattle::
	.string "Tu m'as impressionné.\n"
	.string "Voilà un conseil!\p"
	.string "Cherche bien les espaces entre\n"
	.string "les murs…$"

FuchsiaCity_Gym_Text_EdgarIntro::
	.string "J'veux devenir un ninja en\n"
	.string "m'entraînant avec MAITRE KOGA!\p"
	.string "Rien de mieux qu'un ninja pour\n"
	.string "gagner un combat.$"

FuchsiaCity_Gym_Text_EdgarDefeat::
	.string "Aïe!$"

FuchsiaCity_Gym_Text_EdgarPostBattle::
	.string "J'suis nul!$"

FuchsiaCity_Gym_Text_ShawnIntro::
	.string "KOGA fait partie d'une grande\n"
	.string "famille de terribles ninjas!\p"
	.string "Et toi? D'où viens-tu?\n"
	.string "Qui es-tu?$"

FuchsiaCity_Gym_Text_ShawnDefeat::
	.string "…\n"
	.string "Bien plus coriace que je pensais.$"

FuchsiaCity_Gym_Text_ShawnPostBattle::
	.string "Là où il y a de la lumière,\n"
	.string "il y a de l'ombre.\p"
	.string "Que choisis-tu?\n"
	.string "L'ombre ou la lumière?$"

FuchsiaCity_Gym_Text_GymGuyAdvice::
	.string "Hop là!\n"
	.string "Graine de CHAMPION!\p"
	.string "L'ARENE de PARMANIE est un vrai\n"
	.string "casse-tête!\p"
	.string "KOGA te semblera proche, mais de\n"
	.string "nombreux murs le protégeront!\p"
	.string "Trouve les espaces entre les murs\n"
	.string "pour l'atteindre!$"

FuchsiaCity_Gym_Text_GymGuyPostVictory::
	.string "C'est incroyable de voir comme\n"
	.string "les ninjas peuvent faire peur.$"

FuchsiaCity_Gym_Text_GymStatue::
	.string "ARENE POKéMON de PARMANIE\n"
	.string "CHAMPION: KOGA\p"
	.string "VAINQUEURS:\n"
	.string "{RIVAL}$"

FuchsiaCity_Gym_Text_GymStatuePlayerWon::
	.string "ARENE POKéMON de PARMANIE\n"
	.string "CHAMPION: KOGA\p"
	.string "VAINQUEURS:\n"
	.string "{RIVAL}, {PLAYER}$"


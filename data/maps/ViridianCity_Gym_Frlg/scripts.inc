ViridianCity_Gym_Frlg_MapScripts::
	.byte 0

ViridianCity_Gym_EventScript_Giovanni::
	famechecker FAMECHECKER_GIOVANNI, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_GIOVANNI, ViridianCity_Gym_Text_GiovanniIntro, ViridianCity_Gym_Text_GiovanniDefeat, ViridianCity_Gym_EventScript_DefeatedGiovanni, NO_MUSIC
	goto_if_unset FLAG_GOT_TM26_FROM_GIOVANNI, ViridianCity_Gym_EventScript_GiveTM26
	msgbox ViridianCity_Gym_Text_GiovanniPostBattle
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_VIRIDIAN_GIOVANNI
	fadescreen FADE_FROM_BLACK
	release
	end

ViridianCity_Gym_EventScript_DefeatedGiovanni::
	famechecker FAMECHECKER_GIOVANNI, 3
	setflag FLAG_HIDE_MISC_KANTO_ROCKETS
	setflag FLAG_DEFEATED_LEADER_GIOVANNI
	setflag FLAG_BADGE08_GET
	setvar VAR_MAP_SCENE_ROUTE22, 3
	set_gym_trainers_frlg 8
	goto ViridianCity_Gym_EventScript_GiveTM26
	end

ViridianCity_Gym_EventScript_GiveTM26::
	msgbox ViridianCity_Gym_Text_ExplainEarthBadgeTakeThis
	checkitemspace ITEM_TM26
	goto_if_eq VAR_RESULT, FALSE, ViridianCity_Gym_EventScript_NoRoomForTM26
	giveitem_msg ViridianCity_Gym_Text_ReceivedTM26FromGiovanni, ITEM_TM26
	setflag FLAG_GOT_TM26_FROM_GIOVANNI
	msgbox ViridianCity_Gym_Text_ExplainTM26
	release
	end

ViridianCity_Gym_EventScript_NoRoomForTM26::
	msgbox ViridianCity_Gym_Text_YouDoNotHaveSpace
	release
	end

ViridianCity_Gym_EventScript_Jason::
	trainerbattle_single TRAINER_TAMER_JASON, ViridianCity_Gym_Text_JasonIntro, ViridianCity_Gym_Text_JasonDefeat
	msgbox ViridianCity_Gym_Text_JasonPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Cole::
	trainerbattle_single TRAINER_TAMER_COLE, ViridianCity_Gym_Text_ColeIntro, ViridianCity_Gym_Text_ColeDefeat
	msgbox ViridianCity_Gym_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Atsushi::
	trainerbattle_single TRAINER_BLACK_BELT_ATSUSHI, ViridianCity_Gym_Text_AtsushiIntro, ViridianCity_Gym_Text_AtsushiDefeat
	msgbox ViridianCity_Gym_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Kiyo::
	trainerbattle_single TRAINER_BLACK_BELT_KIYO, ViridianCity_Gym_Text_KiyoIntro, ViridianCity_Gym_Text_KiyoDefeat
	msgbox ViridianCity_Gym_Text_KiyoPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Takashi::
	trainerbattle_single TRAINER_BLACK_BELT_TAKASHI, ViridianCity_Gym_Text_TakashiIntro, ViridianCity_Gym_Text_TakashiDefeat
	msgbox ViridianCity_Gym_Text_TakashiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Samuel::
	trainerbattle_single TRAINER_COOLTRAINER_SAMUEL, ViridianCity_Gym_Text_SamuelIntro, ViridianCity_Gym_Text_SamuelDefeat
	msgbox ViridianCity_Gym_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Yuji::
	trainerbattle_single TRAINER_COOLTRAINER_YUJI, ViridianCity_Gym_Text_YujiIntro, ViridianCity_Gym_Text_YujiDefeat
	msgbox ViridianCity_Gym_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Warren::
	trainerbattle_single TRAINER_COOLTRAINER_WARREN, ViridianCity_Gym_Text_WarrenIntro, ViridianCity_Gym_Text_WarrenDefeat
	msgbox ViridianCity_Gym_Text_WarrenPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LEADER_GIOVANNI, ViridianCity_Gym_EventScript_GymGuyPostVictory
	msgbox ViridianCity_Gym_Text_GymGuyAdvice
	release
	end

ViridianCity_Gym_EventScript_GymGuyPostVictory::
	famechecker FAMECHECKER_GIOVANNI, 4
	msgbox ViridianCity_Gym_Text_GymGuyPostVictory
	release
	end

ViridianCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, ViridianCity_Gym_EventScript_GymStatuePostVictory
	msgbox ViridianCity_Gym_Text_GymStatue
	releaseall
	end

ViridianCity_Gym_EventScript_GymStatuePostVictory::
	msgbox ViridianCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

ViridianCity_Gym_Text_GiovanniIntro::
	.string "Fwahaha!\n"
	.string "Te voici dans mon repaire!\p"
	.string "Je voulais reformer la TEAM\n"
	.string "ROCKET ici!\p"
	.string "Mais tu as encore tout fait rater!\n"
	.string "Je suis furieux et c'est très\l"
	.string "mauvais signe pour toi!\p"
	.string "Une fois de plus tu oses me défier,\n"
	.string "moi, le grand GIOVANNI!\p"
	.string "Mais aujourd'hui, tu vas\n"
	.string "le regretter!{PLAY_BGM MUS_RG_ENCOUNTER_ROCKET}$"

ViridianCity_Gym_Text_GiovanniDefeat::
	.string "Ah!\n"
	.string "Voilà ce que j'appelle un vrai\l"
	.string "combat! Tu as gagné!\p"
	.string "En récompense, voici le BADGE\n"
	.string "TERRE!{PAUSE_MUSIC}{PLAY_BGM MUS_OBTAIN_BADGE}{PAUSE}\n"
	.string "{PAUSE 86}{RESUME_MUSIC}$"

ViridianCity_Gym_Text_GiovanniPostBattle::
	.string "Après cette défaite, je ne suis\n"
	.string "plus digne d'être le chef\l"
	.string "de la TEAM ROCKET! \p"
	.string "Ainsi, son existence s'achève\n"
	.string "avec ma défaite!\p"
	.string "Je vais me retirer, loin,\n"
	.string "pour étudier les POKéMON!\p"
	.string "Un jour, nos chemins se croiseront\n"
	.string "à nouveau! Adieu!$"

ViridianCity_Gym_Text_ExplainEarthBadgeTakeThis::
	.string "Grâce au BADGE TERRE, tous les\n"
	.string "POKéMON obéiront à tes ordres!\p"
	.string "Il est la preuve de ta grande\n"
	.string "maîtrise des POKéMON!\p"
	.string "Tu pourras ainsi accéder à la\n"
	.string "LIGUE POKéMON!\p"
	.string "C'est un cadeau que je te fais.\n"
	.string "Va maintenant, et deviens le plus\l"
	.string "grand des DRESSEURS!$"

ViridianCity_Gym_Text_ReceivedTM26FromGiovanni::
	.string "{PLAYER} obtient la CT26!$"

ViridianCity_Gym_Text_ExplainTM26::
	.string "CT26: SEISME!\p"
	.string "Cette attaque peut créer de\n"
	.string "vrais tremblements de terre!\p"
	.string "Je l'ai inventée il y a bien\n"
	.string "longtemps…$"

ViridianCity_Gym_Text_YouDoNotHaveSpace::
	.string "Ton inventaire est plein!$"

ViridianCity_Gym_Text_YujiIntro::
	.string "Hé!\n"
	.string "Tu dois commencer à fatiguer, \l"
	.string "non? $"

ViridianCity_Gym_Text_YujiDefeat::
	.string "Ha!\n"
	.string "J'suis essoufflé!$"

ViridianCity_Gym_Text_YujiPostBattle::
	.string "Il te faudra tout ton courage pour\n"
	.string "te mesurer au… CHAMPION!$"

ViridianCity_Gym_Text_AtsushiIntro::
	.string "Groaar! La colère m'envahit!\n"
	.string "Viens te battre!$"

ViridianCity_Gym_Text_AtsushiDefeat::
	.string "Rargh!$"

ViridianCity_Gym_Text_AtsushiPostBattle::
	.string "Grouargh!$"

ViridianCity_Gym_Text_JasonIntro::
	.string "Avec mes POKéMON, je fais de\n"
	.string "la belle musique!$"

ViridianCity_Gym_Text_JasonDefeat::
	.string "Tu es en parfaite harmonie!$"

ViridianCity_Gym_Text_JasonPostBattle::
	.string "Sais-tu qui est notre CHAMPION?$"

ViridianCity_Gym_Text_KiyoIntro::
	.string "Le karaté est l'art martial ultime!$"

ViridianCity_Gym_Text_KiyoDefeat::
	.string "Ouargh!$"

ViridianCity_Gym_Text_KiyoPostBattle::
	.string "Mes POKéMON sont des karatékas…$"

ViridianCity_Gym_Text_WarrenIntro::
	.string "Je vais t'écraser avec style et\n"
	.string "élégance!$"

ViridianCity_Gym_Text_WarrenDefeat::
	.string "…\n"
	.string "J'ai perdu…$"

ViridianCity_Gym_Text_WarrenPostBattle::
	.string "Le CHAMPION va me taper dessus!$"

ViridianCity_Gym_Text_TakashiIntro::
	.string "J'suis le ROI du KARATE! Ton destin\n"
	.string "repose entre mes mains!$"

ViridianCity_Gym_Text_TakashiDefeat::
	.string "Yaah!$"

ViridianCity_Gym_Text_TakashiPostBattle::
	.string "La LIGUE POKéMON? Toi?\n"
	.string "Hahahahah!!! Tu me fais rire!$"

ViridianCity_Gym_Text_ColeIntro::
	.string "Tes POKéMON vont se courber sous\n"
	.string "mes coups de fouet!$"

ViridianCity_Gym_Text_ColeDefeat::
	.string "Aïee!$"

ViridianCity_Gym_Text_ColePostBattle::
	.string "Attends! Je ne faisais pas\n"
	.string "attention!$"

ViridianCity_Gym_Text_SamuelIntro::
	.string "L'ARENE de JADIELLE était fermée\n"
	.string "depuis longtemps, mais le CHAMPION\l"
	.string "est enfin revenu!$"

ViridianCity_Gym_Text_SamuelDefeat::
	.string "!!!\n"
	.string "Défaite!$"

ViridianCity_Gym_Text_SamuelPostBattle::
	.string "Tu ne pourras pas accéder à la\n"
	.string "LIGUE POKéMON si tu ne bats pas\l"
	.string "notre CHAMPION!$"

ViridianCity_Gym_Text_GymGuyAdvice::
	.string "Salut,\n"
	.string "CHAMPION en herbe!\p"
	.string "Même moi, je ne sais pas qui est\n"
	.string "le CHAMPION de JADIELLE!\p"
	.string "Le combat qui t'attend sera le plus\n"
	.string "dur de tous!\p"
	.string "Le DRESSEUR de cette ARENE aime\n"
	.string "les POKéMON du type SOL!$"

ViridianCity_Gym_Text_GymGuyPostVictory::
	.string "Quoi?! C'était GIOVANNI le\n"
	.string "CHAMPION? Ben ça alors!$"

ViridianCity_Gym_Text_GymStatue::
	.string "ARENE POKéMON de JADIELLE\n"
	.string "CHAMPION: ?\p"
	.string "VAINQUEURS:\n"
	.string "{RIVAL}$"

ViridianCity_Gym_Text_GymStatuePlayerWon::
	.string "ARENE POKéMON de JADIELLE\n"
	.string "CHAMPION: GIOVANNI\p"
	.string "VAINQUEURS:\n"
	.string "{RIVAL}, {PLAYER}$"


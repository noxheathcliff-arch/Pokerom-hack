RustboroCity_Gym_MapScripts::
	.byte 0

RustboroCity_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_RoxanneRematch
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, CF_C9_Reward
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneDefeated::
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	@ Demo: no vanilla state writes (VAR_RUSTBORO_CITY_STATE / VAR_PETALBURG_GYM_STATE are used by the demo scenes)
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	goto CF_C9_Reward
	end

RustboroCity_Gym_EventScript_GiveRockTomb::
	giveitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory::
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified::
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue::
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterRoxanne::
	lockall
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

RustboroCity_Gym_Text_GymGuideAdvice:
	.string "Hé, attends… Red ? Le Maître de\n"
	.string "Kanto, ici, à Mérouville ?\p"
	.string "Je conseille les dresseurs qui\n"
	.string "viennent défier l’Arène.\p"
	.string "D’habitude, ce sont des gamins.\n"
	.string "Mais un conseil, ça ne se refuse pas.\p"
	.string "Roxanne utilise des Pokémon de\n"
	.string "type Roche.\p"
	.string "La Roche encaisse bien, mais craint\n"
	.string "les capacités Eau et Plante.\p"
	.string "Et méfie-toi : elle prend des notes\n"
	.string "pendant le combat. Elle apprend vite.\p"
	.string "Allez, Maître. Montre-lui !$"

RustboroCity_Gym_Text_GymGuidePostVictory:
	.string "Le Badge Roche ! Tu l’as eu sans\n"
	.string "trembler, évidemment.\p"
	.string "Roxanne va passer la nuit à revoir\n"
	.string "ses notes. Elle adore ça.\p"
	.string "Avec un badge de Hoenn, les gens\n"
	.string "d’ici te regarderont autrement.$"

RustboroCity_Gym_Text_JoshIntro:
	.string "Le Maître de Kanto dans notre\n"
	.string "Arène ? Je n’y crois pas !\p"
	.string "Mais je ne vais pas te laisser\n"
	.string "passer sans me battre !$"

RustboroCity_Gym_Text_JoshDefeat:
	.string "Comme à la télé…\n"
	.string "En pire, pour moi.$"

RustboroCity_Gym_Text_JoshPostBattle:
	.string "J’ai vu ton combat contre ton\n"
	.string "rival à la Ligue. En vrai, c’est\p"
	.string "encore plus impressionnant.$"

RustboroCity_Gym_Text_TommyIntro:
	.string "Mademoiselle Roxanne dit qu’un\n"
	.string "titre ne remplace pas la méthode.\p"
	.string "Voyons si c’est vrai pour vous !$"

RustboroCity_Gym_Text_TommyDefeat:
	.string "La méthode… et le titre.\n"
	.string "Les deux, apparemment.$"

RustboroCity_Gym_Text_TommyPostBattle:
	.string "Mademoiselle Roxanne a tout noté.\n"
	.string "Elle vous attend au fond.$"

RustboroCity_Gym_Text_MarcIntro:
	.string "Les barrages du Rempart m’ont\n"
	.string "bloqué en ville tout le mois.\p"
	.string "J’ai eu le temps de m’entraîner.\n"
	.string "Attention, Maître !$"

RustboroCity_Gym_Text_MarcDefeat:
	.string "Un mois d’entraînement…\n"
	.string "Balayé en trois tours.$"

RustboroCity_Gym_Text_MarcPostBattle:
	.string "Roxanne est jeune, mais elle\n"
	.string "connaît la Roche par cœur.\p"
	.string "Elle ne te fera aucun cadeau,\n"
	.string "Maître ou pas.$"

RustboroCity_Gym_Text_RoxanneIntro:
	.string "{PLAYER}. Vous êtes venu.\n"
	.string "Bienvenue à l’Arène de Mérouville.\p"
	.string "Depuis la mine, je n’attends\n"
	.string "que ça. Mes notes sont prêtes.\p"
	.string "Notez bien : je ne vous ferai\n"
	.string "aucun cadeau. Montrez-moi tout !$"

RustboroCity_Gym_Text_RoxanneDefeat:
	.string "… Voilà qui est instructif.\p"
	.string "Mes notes ne disaient pas tout.\n"
	.string "Il va falloir les réécrire.\p"
	.string "Le règlement est clair : Maître\n"
	.string "de Kanto ou non, le badge se gagne.\p"
	.string "Et vous l’avez gagné. Voici le\n"
	.string "Badge Roche officiel.$"

RustboroCity_Gym_Text_ReceivedStoneBadge:
	.string "{PLAYER} reçoit le Badge Roche\n"
	.string "de la part de Roxanne.$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
	.string "Le Badge Roche augmente l’Attaque\n"
	.string "de vos Pokémon.\p"
	.string "Il permet aussi d’utiliser Coupe\n"
	.string "en dehors des combats.\p"
	.string "Et prenez ceci. Pour vos notes.$"

RustboroCity_Gym_Text_ExplainRockTomb:
	.string "La CT39 contient Tomberoche.\p"
	.string "Les rochers infligent des dégâts\n"
	.string "et font baisser la Vitesse.\p"
	.string "Attention : une CT ne sert qu’une\n"
	.string "fois. Choisissez bien l’élève.$"

RustboroCity_Gym_Text_RoxannePostBattle:
	.string "Je vais réécrire mon cours sur\n"
	.string "la Roche. Avec votre combat dedans.\p"
	.string "Mes élèves ne parlent plus que de\n"
	.string "vous. Revenez quand vous voulez.$"

RustboroCity_Gym_Text_GymStatue:
	.string "Arène Pokémon de Mérouville$"

RustboroCity_Gym_Text_GymStatueCertified:
	.string "Arène Pokémon de Mérouville\p"
	.string "Dresseur reconnu par Roxanne :\n"
	.string "{PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall:
	.string "… … … … … …\n"
	.string "… … … … … Bip !\p"
	.string "Roxanne : C’est bien {PLAYER} ?\n"
	.string "Ici Roxanne, de Mérouville.\p"
	.string "J’ai réécrit mon cours sur la\n"
	.string "Roche. Votre combat est dedans.\p"
	.string "Mon Arène sera prête pour une\n"
	.string "revanche. À très bientôt !\p"
	.string "… … … … … …\n"
	.string "… … … … … Clic !$"

RustboroCity_Gym_Text_RegisteredRoxanne:
	.string "Vous avez enregistré Roxanne,\n"
	.string "championne d’Arène, dans le PokéNav.$"

RustboroCity_Gym_Text_RoxannePreRematch:
	.string "Roxanne : Ravie de vous revoir !\p"
	.string "J’ai revu toutes mes notes depuis\n"
	.string "notre dernier combat.\p"
	.string "Voyons ce que ça donne !$"

RustboroCity_Gym_Text_RoxanneRematchDefeat:
	.string "Grr…\n"
	.string "Encore perdu…$"

RustboroCity_Gym_Text_RoxannePostRematch:
	.string "Roxanne : J’ai encore beaucoup à\n"
	.string "apprendre sur les Pokémon.\p"
	.string "Et c’est bien pour ça que\n"
	.string "j’aime autant les combats !$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
	.string "Roxanne : Ravie de vous revoir !\p"
	.string "J’ai revu toutes mes notes depuis\n"
	.string "notre dernier combat.\p"
	.string "Oh, mais… Vous n’avez qu’un\n"
	.string "Pokémon avec vous ?\p"
	.string "Revenez avec au moins deux\n"
	.string "Pokémon, s’il vous plaît.$"

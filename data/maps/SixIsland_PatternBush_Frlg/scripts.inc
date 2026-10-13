SixIsland_PatternBush_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SixIsland_PatternBush_OnTransition
	.byte 0

SixIsland_PatternBush_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SIX_ISLAND_PATTERN_BUSH
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	call_if_ge VAR_TEMP_1, 50, SixIsland_PatternBush_EventScript_SetEscapeRightExit
	call_if_le VAR_TEMP_1, 49, SixIsland_PatternBush_EventScript_SetEscapeLeftExit
	end

SixIsland_PatternBush_EventScript_SetEscapeRightExit::
	setescapewarp MAP_SIX_ISLAND_GREEN_PATH, 255, 64, 10
	return

SixIsland_PatternBush_EventScript_SetEscapeLeftExit::
	setescapewarp MAP_SIX_ISLAND_GREEN_PATH, 255, 45, 10
	return

SixIsland_PatternBush_EventScript_Bethany::
	trainerbattle_single TRAINER_PKMN_BREEDER_BETHANY, SixIsland_PatternBush_Text_BethanyIntro, SixIsland_PatternBush_Text_BethanyDefeat
	msgbox SixIsland_PatternBush_Text_BethanyPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Allison::
	trainerbattle_single TRAINER_PKMN_BREEDER_ALLISON, SixIsland_PatternBush_Text_AllisonIntro, SixIsland_PatternBush_Text_AllisonDefeat
	msgbox SixIsland_PatternBush_Text_AllisonPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Garret::
	trainerbattle_single TRAINER_BUG_CATCHER_GARRET, SixIsland_PatternBush_Text_GarretIntro, SixIsland_PatternBush_Text_GarretDefeat
	msgbox SixIsland_PatternBush_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Jonah::
	trainerbattle_single TRAINER_BUG_CATCHER_JONAH, SixIsland_PatternBush_Text_JonahIntro, SixIsland_PatternBush_Text_JonahDefeat
	msgbox SixIsland_PatternBush_Text_JonahPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Vance::
	trainerbattle_single TRAINER_BUG_CATCHER_VANCE, SixIsland_PatternBush_Text_VanceIntro, SixIsland_PatternBush_Text_VanceDefeat
	msgbox SixIsland_PatternBush_Text_VancePostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Nash::
	trainerbattle_single TRAINER_YOUNGSTER_NASH, SixIsland_PatternBush_Text_NashIntro, SixIsland_PatternBush_Text_NashDefeat
	msgbox SixIsland_PatternBush_Text_NashPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Cordell::
	trainerbattle_single TRAINER_YOUNGSTER_CORDELL, SixIsland_PatternBush_Text_CordellIntro, SixIsland_PatternBush_Text_CordellDefeat
	msgbox SixIsland_PatternBush_Text_CordellPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Dalia::
	trainerbattle_single TRAINER_LASS_DALIA, SixIsland_PatternBush_Text_DaliaIntro, SixIsland_PatternBush_Text_DaliaDefeat
	msgbox SixIsland_PatternBush_Text_DaliaPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Joana::
	trainerbattle_single TRAINER_LASS_JOANA, SixIsland_PatternBush_Text_JoanaIntro, SixIsland_PatternBush_Text_JoanaDefeat
	msgbox SixIsland_PatternBush_Text_JoanaPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Riley::
	trainerbattle_single TRAINER_CAMPER_RILEY, SixIsland_PatternBush_Text_RileyIntro, SixIsland_PatternBush_Text_RileyDefeat
	msgbox SixIsland_PatternBush_Text_RileyPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Marcy::
	trainerbattle_single TRAINER_PICNICKER_MARCY, SixIsland_PatternBush_Text_MarcyIntro, SixIsland_PatternBush_Text_MarcyDefeat
	msgbox SixIsland_PatternBush_Text_MarcyPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_EventScript_Layton::
	trainerbattle_single TRAINER_RUIN_MANIAC_LAYTON, SixIsland_PatternBush_Text_LaytonIntro, SixIsland_PatternBush_Text_LaytonDefeat
	msgbox SixIsland_PatternBush_Text_LaytonPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_PatternBush_Text_BethanyIntro::
	.string "Je suis curieuse de voir comment\n"
	.string "tu élèves tes POKéMON.$"

SixIsland_PatternBush_Text_BethanyDefeat::
	.string "Tu élèves tes POKéMON avec\n"
	.string "beaucoup d'amour!$"

SixIsland_PatternBush_Text_BethanyPostBattle::
	.string "Tu dois élever tes POKéMON comme\n"
	.string "une mère élèverait ses enfants.$"

SixIsland_PatternBush_Text_AllisonIntro::
	.string "Je travaille à préserver l'équilibre\n"
	.string "naturel des POKéMON.$"

SixIsland_PatternBush_Text_AllisonDefeat::
	.string "Tu es incroyable pour quelqu'un\n"
	.string "d'aussi jeune!$"

SixIsland_PatternBush_Text_AllisonPostBattle::
	.string "Je ne dis pas que tu ne dois pas\n"
	.string "attraper de POKéMON.\p"
	.string "Je dis juste qu'il faut les élever\n"
	.string "avec plus de responsabilité.$"

SixIsland_PatternBush_Text_GarretIntro::
	.string "J'ai attrapé un POKéMON INSECTE\n"
	.string "qui ne vit que par ici!$"

SixIsland_PatternBush_Text_GarretDefeat::
	.string "Hehehe… Tu le trouves\n"
	.string "pas génial mon POKéMON?$"

SixIsland_PatternBush_Text_GarretPostBattle::
	.string "Il y a une fille près des BUISSONS\n"
	.string "qui fait combattre son SCARHINO.$"

SixIsland_PatternBush_Text_JonahIntro::
	.string "Tu sais, je ne me sens pas à \n"
	.string "l'aise sans POKéMON INSECTE.$"

SixIsland_PatternBush_Text_JonahDefeat::
	.string "Pas de problème. \p"
	.string "Perdre fait aussi partie de\n"
	.string "l'entraînement de DRESSEUR.$"

SixIsland_PatternBush_Text_JonahPostBattle::
	.string "C'est comme quand tu attrapes\n"
	.string "des insectes. Tu n'abandonnes\p"
	.string "pas au premier papillon qui\n"
	.string "t'échappe, non?$"

SixIsland_PatternBush_Text_VanceIntro::
	.string "Ouaiiis, ouais!!\n"
	.string "Regarde tous les POKéMON INSECTE!$"

SixIsland_PatternBush_Text_VanceDefeat::
	.string "Je me suis fait battre parce que\n"
	.string "j'étais pas concentré!$"

SixIsland_PatternBush_Text_VancePostBattle::
	.string "La prochaine fois, je viendrai\n"
	.string "avec mon petit frère.$"

SixIsland_PatternBush_Text_NashIntro::
	.string "Regarde! Il y a des formes\n"
	.string "marrantes sur le sol.$"

SixIsland_PatternBush_Text_NashDefeat::
	.string "Impressionnant…$"

SixIsland_PatternBush_Text_NashPostBattle::
	.string "Les formes qui sont sur le sol…\p"
	.string "Ça ressemble à ce qu'il y a sur\n"
	.string "les chemises de mon grand-père.$"

SixIsland_PatternBush_Text_CordellIntro::
	.string "Je suis sûr que tu penses que je\n"
	.string "suis un type comme les autres, non?$"

SixIsland_PatternBush_Text_CordellDefeat::
	.string "Tu avais peut-être raison…$"

SixIsland_PatternBush_Text_CordellPostBattle::
	.string "Vous les gens de la ville, toujours\n"
	.string "à frimer avec vos fringues.\p"
	.string "Hum… Ça m'irait bien…\n"
	.string "Tu veux pas me le donner?$"

SixIsland_PatternBush_Text_DaliaIntro::
	.string "Inspire bien fort.\n"
	.string "Respire un peu ce bon air.$"

SixIsland_PatternBush_Text_DaliaDefeat::
	.string "Si tu veux, je pourrais t'apprendre\n"
	.string "à respirer correctement.$"

SixIsland_PatternBush_Text_DaliaPostBattle::
	.string "D'abord, expire bien fort.\n"
	.string "Fais tout sortir d'un coup.\p"
	.string "Quand tes poumons sont vides,\n"
	.string "inspire cet air pur!\p"
	.string "C'est rafraîchissant, non?$"

SixIsland_PatternBush_Text_JoanaIntro::
	.string "J'adore les POKéMON INSECTE.\p"
	.string "C'est pour ça que je suis tout le\n"
	.string "temps ici. \p"
	.string "Est-ce que je suis la seule fille\n"
	.string "comme ça?$"

SixIsland_PatternBush_Text_JoanaDefeat::
	.string "J'ai perdu, mais c'est pas grave!\n"
	.string "Je dois être un peu spéciale…$"

SixIsland_PatternBush_Text_JoanaPostBattle::
	.string "Je vais continuer à collectionner\n"
	.string "les POKéMON INSECTE.\p"
	.string "Est-ce que je suis la seule fille\n"
	.string "comme ça?$"

SixIsland_PatternBush_Text_RileyIntro::
	.string "C'est un bon emplacement. Je\n"
	.string "vais planter ma tente ici.$"

SixIsland_PatternBush_Text_RileyDefeat::
	.string "Dégagé!$"

SixIsland_PatternBush_Text_RileyPostBattle::
	.string "Je vais observer les étoiles à\n"
	.string "partir d'ici.$"

SixIsland_PatternBush_Text_MarcyIntro::
	.string "Aïeuh! Je viens de me faire\n"
	.string "mordre par une bête!$"

SixIsland_PatternBush_Text_MarcyDefeat::
	.string "Je me suis trompée. Je me\n"
	.string "suis juste coupée toute seule.$"

SixIsland_PatternBush_Text_MarcyPostBattle::
	.string "Avec ce genre de coupure, \n"
	.string "un petit bisou et ça repart!$"

SixIsland_PatternBush_Text_LaytonIntro::
	.string "Tu n'as rien remarqué de bizarre\n"
	.string "par ici?$"

SixIsland_PatternBush_Text_LaytonDefeat::
	.string "Tu as bien regardé autour de\n"
	.string "toi?$"

SixIsland_PatternBush_Text_LaytonPostBattle::
	.string "Dans les FORBUISSONS,\n"
	.string "l'herbe ne repousse pas partout.\p"
	.string "De quoi ça pourrait bien venir?$"


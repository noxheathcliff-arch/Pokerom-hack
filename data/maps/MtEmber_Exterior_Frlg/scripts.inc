MtEmber_Exterior_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtEmber_Exterior_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, MtEmber_Exterior_OnLoad
	.byte 0

MtEmber_Exterior_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_MT_EMBER_EXTERIOR
	call_if_eq VAR_MAP_SCENE_MT_EMBER_EXTERIOR, 2, MtEmber_Exterior_EventScript_RocketsFaceDown
	end

MtEmber_Exterior_EventScript_RocketsFaceDown::
	setobjectmovementtype LOCALID_MT_EMBER_GRUNT1, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_MT_EMBER_GRUNT2, MOVEMENT_TYPE_FACE_DOWN
	return

MtEmber_Exterior_OnLoad::
	call_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 4, MtEmber_Exterior_EventScript_OpenCave
	end

MtEmber_Exterior_EventScript_OpenCave::
	setmetatile 42, 39, METATILE_MtEmber_CaveEntrance, 0
	return

MtEmber_Exterior_EventScript_Grunt1::
	lock
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_43, MtEmber_Exterior_EventScript_Grunt1Defeated
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 4, MtEmber_Exterior_EventScript_BattleGrunt1
	msgbox MtEmber_Exterior_Text_WellTryDiggingHere
	release
	end

MtEmber_Exterior_EventScript_Grunt1Defeated::
	msgbox MtEmber_Exterior_Text_Grunt1PostBattle
	release
	end

MtEmber_Exterior_EventScript_BattleGrunt1::
	applymovement LOCALID_MT_EMBER_GRUNT1, Common_Movement_FacePlayer
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	msgbox MtEmber_Exterior_Text_Grunt1Intro
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_43, MtEmber_Exterior_Text_Grunt1Defeat
	msgbox MtEmber_Exterior_Text_Grunt1PostBattle
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_44, MtEmber_Exterior_EventScript_DefeatedBothGrunts
	release
	end

MtEmber_Exterior_EventScript_DefeatedBothGrunts::
	msgbox MtEmber_Exterior_Text_WellRegroupDontStepInsideThere
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_MT_EMBER_GRUNT1
	removeobject LOCALID_MT_EMBER_GRUNT2
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

MtEmber_Exterior_EventScript_Grunt2::
	lock
	faceplayer
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_44, MtEmber_Exterior_EventScript_DefeatedGrunt2
	goto_if_eq VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 4, MtEmber_Exterior_EventScript_BattleGrunt2
	msgbox MtEmber_Exterior_Text_YoureInTheWayGetLost
	closemessage
	applymovement LOCALID_MT_EMBER_GRUNT2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MtEmber_Exterior_EventScript_DefeatedGrunt2::
	msgbox MtEmber_Exterior_Text_Grunt2PostBattle
	release
	end

MtEmber_Exterior_EventScript_BattleGrunt2::
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	msgbox MtEmber_Exterior_Text_Grunt2Intro
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_44, MtEmber_Exterior_Text_Grunt2Defeat
	msgbox MtEmber_Exterior_Text_Grunt2PostBattle
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_43, MtEmber_Exterior_EventScript_DefeatedBothGrunts
	release
	end

MtEmber_Exterior_EventScript_RocketPasswordScene::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	msgbox MtEmber_Exterior_Text_PunchedThroughAtLast
	message MtEmber_Exterior_Text_WhatsPasswordAgain
	waitmessage
	playse SE_PIN
	applymovement LOCALID_MT_EMBER_GRUNT2, Common_Movement_QuestionMark
	waitmovement 0
	waitbuttonpress
	msgbox MtEmber_Exterior_Text_FirstPasswordGoldeen
	applymovement LOCALID_MT_EMBER_GRUNT1, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MT_EMBER_GRUNT1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MT_EMBER_GRUNT1, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MT_EMBER_GRUNT2, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	call MtEmber_Exterior_EventScript_RocketsFaceDown
	msgbox MtEmber_Exterior_Text_SnoopsBeenListeningIn
	setvar VAR_MAP_SCENE_MT_EMBER_EXTERIOR, 2
	releaseall
	end

MtEmber_Exterior_EventScript_Logan::
	trainerbattle_single TRAINER_PKMN_RANGER_LOGAN, MtEmber_Exterior_Text_LoganIntro, MtEmber_Exterior_Text_LoganDefeat
	msgbox MtEmber_Exterior_Text_LoganPostBattle, MSGBOX_AUTOCLOSE
	end

MtEmber_Exterior_EventScript_Beth::
	trainerbattle_single TRAINER_PKMN_RANGER_BETH, MtEmber_Exterior_Text_BethIntro, MtEmber_Exterior_Text_BethDefeat
	msgbox MtEmber_Exterior_Text_BethPostBattle, MSGBOX_AUTOCLOSE
	end

MtEmber_Exterior_EventScript_Jocelyn::
	trainerbattle_single TRAINER_CRUSH_GIRL_JOCELYN, MtEmber_Exterior_Text_JocelynIntro, MtEmber_Exterior_Text_JocelynDefeat
	msgbox MtEmber_Exterior_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

Text_ExplosionTeach::
	.string "Tu imagines? Si ce volcan\n"
	.string "se mettait en éruption?\p"
	.string "Ça serait la fin de tout. C'est\n"
	.string "terrible, non?\p"
	.string "Pendant qu'on tremble de peur,\n"
	.string "tu veux apprendre EXPLOSION?$"

Text_ExplosionDeclined::
	.string "Tu as raison, ça fait trop peur.$"

Text_ExplosionWhichMon::
	.string "T'as vraiment du courage!\p"
	.string "A quel POKéMON enseigner\n"
	.string "EXPLOSION?$"

Text_ExplosionTaught::
	.string "Utiliser EXPLOSION sur ce volcan,\n"
	.string "ça serait…\p"
	.string "Je préfère ne pas y penser!$"

MtEmber_Exterior_Text_WellTryDiggingHere::
	.string "Par ici.\n"
	.string "On va essayer de creuser par là.\p"
	.string "Le trésor dont les ADMINS étaient\n"
	.string "en train de parler doit être ici.$"

MtEmber_Exterior_Text_YoureInTheWayGetLost::
	.string "Qu'est-ce que…\n"
	.string "Tu es sur le chemin, dégage!$"

MtEmber_Exterior_Text_PunchedThroughAtLast::
	.string "Ouf, une bonne chose de faite.\n"
	.string "A nous les trésors maintenant!$"

MtEmber_Exterior_Text_WhatsPasswordAgain::
	.string "On ramène tous les trésors qu'on\n"
	.string "trouve à l'ENTREPOT, bien compris?\p"
	.string "…Oh, et pour les mots de\n"
	.string "passe? Ceux de l'ENTREPOT…$"

MtEmber_Exterior_Text_FirstPasswordGoldeen::
	.string "Quoi, tu as oublié les deux mots\n"
	.string "de passe? Imbécile!\p"
	.string "Le premier c'est:\n"
	.string "“ICI, GIRAFARIG, ICI”.\p"
	.string "Et le deuxième…$"

MtEmber_Exterior_Text_SnoopsBeenListeningIn::
	.string "Hey!\n"
	.string "Quelqu'un nous écoute!$"

MtEmber_Exterior_Text_Grunt1Intro::
	.string "Tu étais en train de nous\n"
	.string "espionner, hein?$"

MtEmber_Exterior_Text_Grunt1Defeat::
	.string "Hein, quoi?$"

MtEmber_Exterior_Text_Grunt1PostBattle::
	.string "Je comprends pas, comment t'as fait\n"
	.string "pour me battre?$"

MtEmber_Exterior_Text_Grunt2Intro::
	.string "Tu veux nos trésors, hein?\n"
	.string "Ne compte pas là-dessus.$"

MtEmber_Exterior_Text_Grunt2Defeat::
	.string "Attends!\n"
	.string "Mais comment…$"

MtEmber_Exterior_Text_Grunt2PostBattle::
	.string "Je vais développer une amnésie\n"
	.string "sélective et oublier ce combat.$"

MtEmber_Exterior_Text_WellRegroupDontStepInsideThere::
	.string "Quelle déculottée…\n"
	.string "On doit se replier.\p"
	.string "Toi, n'essaie même pas d'entrer\n"
	.string "là-dedans!\p"
	.string "Si tu tiens à ta peau, je te\n"
	.string "conseille de rester dehors!$"

MtEmber_Exterior_Text_LoganIntro::
	.string "Un volcan actif est un volcan en\n"
	.string "éruption, ou sur le point de l'être.$"

MtEmber_Exterior_Text_LoganDefeat::
	.string "Pfiuu… C'était chaud!\n"
	.string "Je suis tout en sueur.$"

MtEmber_Exterior_Text_LoganPostBattle::
	.string "Il paraît qu'il y a plus de 1 500\n"
	.string "volcans actifs dans le monde.\p"
	.string "Rien que d'y penser, ça me\n"
	.string "donne chaud.$"

MtEmber_Exterior_Text_BethIntro::
	.string "Tu sais comment les grottes se\n"
	.string "forment à l'intérieur des volcans?$"

MtEmber_Exterior_Text_BethDefeat::
	.string "Aaaah!\n"
	.string "C'est pas normal d'être aussi fort!$"

MtEmber_Exterior_Text_BethPostBattle::
	.string "Quand la lave à la surface du\n"
	.string "magma se durcit mais que l'intérieur\p"
	.string "continue de s'écouler,\n"
	.string "cela crée des grottes volcaniques.$"

MtEmber_Exterior_Text_JocelynIntro::
	.string "Je me suis entraînée pour pouvoir\n"
	.string "supporter la défaite…\p"
	.string "En fait, je me suis surtout durcie\n"
	.string "physiquement. A l'attaque!$"

MtEmber_Exterior_Text_JocelynDefeat::
	.string "J'ai dû en faire trop…$"

MtEmber_Exterior_Text_JocelynPostBattle::
	.string "La façon dont tu m'as éliminée…\p"
	.string "Ça me rappelle quand j'ai cassé\n"
	.string "avec mon copain!$"


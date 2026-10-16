PetalburgWoods_MapScripts::
	.byte 0

PetalburgWoods_EventScript_DevonResearcherLeft::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
	waitmovement 0
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherRight::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
	waitmovement 0
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherIntro::
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
	waitmovement 0
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_DevonResearcherPostBattle::
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaRunAway
	waitmovement 0
	removeobject LOCALID_PETALBURG_WOODS_GRUNT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_BagFull::
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_DevonResearcherFinish::
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
	waitmovement 0
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_RemoveDevonResearcher::
	removeobject LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE
	setvar VAR_PETALBURG_WOODS_STATE, 1
	releaseall
	end

PetalburgWoods_Movement_DevonResearcherLookAround:
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end

PetalburgWoods_Movement_DevonResearcherExitLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
	delay_16
	face_player
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PetalburgWoods_Movement_DevonResearcherExitRight:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_WatchResearcherLeave:
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherStartExit:
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

PetalburgWoods_Movement_AquaApproachResearcherLeft:
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaBackOff:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PetalburgWoods_Movement_AquaRunAway:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachResearcherRight:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaEntrance:
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachPlayer:
	walk_down
	step_end

PetalburgWoods_EventScript_Boy1::
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Boy2::
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end

PetalburgWoods_EventScript_ExplainMiracleSeed::
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_Sign1::
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign2::
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_James::
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
	setvar VAR_0x8004, TRAINER_JAMES_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_TryRegisterJames::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
	release
	end

PetalburgWoods_EventScript_RegisterJames::
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_TryRegisterJames2::
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_RegisterJames2::
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_JamesRematch::
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_Text_NotAOneToBeFound:
	.string "Humm…\n"
	.string "Rien du tout…$"

PetalburgWoods_Text_HaveYouSeenShroomish:
	.string "Salut! T'aurais pas vu un POKéMON\n"
	.string "appelé BALIGNON dans le coin?\p"
	.string "J'aime beaucoup ce POKéMON.$"

PetalburgWoods_Text_IWasGoingToAmbushYou:
	.string "Je voulais te piéger, mais ça fait\n"
	.string "une éternité que tu traînes dans le\l"
	.string "BOIS CLEMENTI!\p"
	.string "Ras l'bol d'attendre! Alors me voilà!$"

PetalburgWoods_Text_HandOverThosePapers:
	.string "Toi! Le CHERCHEUR DE DEVON!\p"
	.string "Donne-moi ces papiers!$"

PetalburgWoods_Text_YouHaveToHelpMe:
	.string "Oh, hé!\p"
	.string "Tu es un DRESSEUR de POKéMON, non?\n"
	.string "Il faut que tu m'aides. S'il te plaît!$"

PetalburgWoods_Text_NoOneCrossesTeamAqua:
	.string "Hum? Tu penses faire quoi?\n"
	.string "Comment! Tu vas le défendre?\p"
	.string "La TEAM AQUA n'a jamais de pitié pour\n"
	.string "ses ennemis. Pas même pour un enfant!\p"
	.string "Viens te battre!$"

PetalburgWoods_Text_YoureKiddingMe:
	.string "Tu m'as bluffé! Quelle force!$"

PetalburgWoods_Text_YouveGotSomeNerve:
	.string "Grrr… Tu as eu le culot de t'opposer\n"
	.string "à la TEAM AQUA!\p"
	.string "Viens et affronte-moi de nouveau!\p"
	.string "C'est ce que j'aurais aimé te dire,\n"
	.string "mais je suis à court de POKéMON…\p"
	.string "Et en plus, nous, la TEAM AQUA, on a\n"
	.string "quelque chose à faire à MEROUVILLE.\p"
	.string "Ça va pour aujourd'hui. J'te laisse\n"
	.string "filer!$"

PetalburgWoods_Text_ThatWasAwfullyClose:
	.string "Ouf…\n"
	.string "Il s'en est fallu de peu!\p"
	.string "Grâce à toi, il ne m'a pas volé ces\n"
	.string "importants papiers.\p"
	.string "Je sais! Pour te remercier, je vais te\n"
	.string "donner cette SUPER BALL.$"

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
	.string "Cette brute de la TEAM AQUA n'a-t-elle\n"
	.string "pas dit qu'ils avaient quelque chose à\l"
	.string "faire à MEROUVILLE?$"

PetalburgWoods_Text_ICantBeWastingTime:
	.string "Oh là là! C'est une catastrophe!\n"
	.string "Je n'ai pas de temps à perdre!$"

PetalburgWoods_Text_YoureLoadedWithItems:
	.string "Tu croules sous les objets. Je ne peux\n"
	.string "pas te donner cette SUPER BALL.$"

PetalburgWoods_Text_GoBugPokemonTeam:
	.string "J'ai attrapé tout un tas de POKéMON!\p"
	.string "Allez, allez, allez!\n"
	.string "Mon équipe de POKéMON INSECTE!$"

PetalburgWoods_Text_ICouldntWin:
	.string "J'avais tous ces POKéMON et\n"
	.string "je n'ai même pas gagné…$"

PetalburgWoods_Text_ImOutOfPokeBalls:
	.string "J'ai attrapé tout un tas de POKéMON.\n"
	.string "Maintenant, je n'ai plus de POKé BALLS.$"

PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
	.string "Si t'emmènes des POKéMON INSECTE à\n"
	.string "l'école, t'es tout de suite populaire!$"

PetalburgWoods_Text_CantBePopularIfILose:
	.string "Je n'peux pas être populaire\n"
	.string "si je perds.$"

PetalburgWoods_Text_PeopleRespectYou:
	.string "Quand tu as un gros POKéMON INSECTE,\n"
	.string "les gens te respectent.$"

PetalburgWoods_Text_IWantRematch1:
	.string "J'aurai ma revanche dès que mes\n"
	.string "POKéMON INSECTE auront grandi!\p"
	.string "Je vais t'enregistrer dans mon POKéNAV!$"

PetalburgWoods_Text_IWantRematch2:
	.string "J'aurai ma revanche dès que mes\n"
	.string "POKéMON INSECTE auront grandi!\p"
	.string "Je vais t'enregistrer dans mon POKéNAV!$"

PetalburgWoods_Text_MyPokemonHaveGrown:
	.string "Mon POKéMON INSECTE a grandi.\n"
	.string "Je vais redevenir populaire.$"

PetalburgWoods_Text_CantBePopularIfLose:
	.string "Je n'peux pas être populaire\n"
	.string "si je perds.$"

PetalburgWoods_Text_IveBeenTrainingHard:
	.string "On devient populaire quand on a des\n"
	.string "POKéMON puissants, pas vrai?\p"
	.string "Alors je m'entraîne dur.$"

PetalburgWoods_Text_StayOutOfTallGrass:
	.string "Yo! Tes Pokémon tiennent le coup?\n"
	.string "Ce bois a changé, tu sais.\p"
	.string "Des anneaux se sont ouverts au-dessus\n"
	.string "des arbres. Plusieurs fois.\p"
	.string "Si ton équipe est faible, ne traîne\n"
	.string "pas dans les herbes. Vraiment pas.$"

PetalburgWoods_Text_HiddenItemsExplanation:
	.string "Je regarde toujours où je marche.\n"
	.string "Il y a des objets cachés par terre.\p"
	.string "Et des choses tombées des anneaux.\n"
	.string "J’ai trouvé un bracelet, hier.\p"
	.string "Gravé dans une langue que personne\n"
	.string "ne lit. Je l’ai jeté. On sait jamais.$"

PetalburgWoods_Text_TryUsingThisItem:
	.string "Toi aussi, tu traverses le bois?\n"
	.string "Tu as l’air aussi perdu que moi.\p"
	.string "Tiens, prends ça. Je ne m’en sers\n"
	.string "pas, et tu en auras plus besoin.$"

PetalburgWoods_Text_MiracleSeedExplanation:
	.string "C’est un Grain Miracle. Tenu par\n"
	.string "un Pokémon, il renforce la Plante.\p"
	.string "Ma grand-mère le cultivait ici,\n"
	.string "avant que le bois devienne dangereux.\p"
	.string "Prends soin de toi, d’accord?\n"
	.string "On ne se croise plus beaucoup, ici.$"

PetalburgWoods_Text_TrainerTipsExperience:
	.string "CONSEILS AUX DRESSEURS\p"
	.string "Tout POKéMON apparaissant au combat,\n"
	.string "même une fois, reçoit des points EXP.\p"
	.string "Pour augmenter le niveau d'un POKéMON,\n"
	.string "il faut le placer en tête de liste.\p"
	.string "Dès le début du combat, échangez-le.\n"
	.string "Il recevra ainsi des points EXP sans \l"
	.string "prendre le moindre risque.$"

PetalburgWoods_Text_TrainerTipsPP:
	.string "CONSEILS AUX DRESSEURS\p"
	.string "En plus des POINTS DE VIE (PV), les\n"
	.string "POKéMON ont des POINTS DE POUVOIR (PP)\l"
	.string "pour utiliser les capacités au combat.\p"
	.string "Si un POKéMON n'a plus de PP, il faut\n"
	.string "l'emmener dans un CENTRE POKéMON.$"


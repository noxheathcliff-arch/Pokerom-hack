ViridianCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_OnTransition
	.byte 0

ViridianCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_VIRIDIAN_CITY
	call_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0, ViridianCity_EventScript_SetOldManBlockingRoad
	call_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1, ViridianCity_EventScript_SetOldManStandingByRoad
	call_if_ge VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2, ViridianCity_EventScript_SetOldManNormal
	call_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR, 0, ViridianCity_EventScript_TryUnlockGym
	end

ViridianCity_EventScript_SetOldManNormal::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OLD_MAN_1
	return

ViridianCity_EventScript_SetOldManStandingByRoad::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OLD_MAN_1
	setobjectxyperm LOCALID_TUTORIAL_MAN, 21, 8
	setobjectmovementtype LOCALID_TUTORIAL_MAN, MOVEMENT_TYPE_LOOK_AROUND
	return

ViridianCity_EventScript_SetOldManBlockingRoad::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OLD_MAN_LYING_DOWN
	setobjectxyperm LOCALID_TUTORIAL_MAN, 21, 11
	setobjectmovementtype LOCALID_TUTORIAL_MAN, MOVEMENT_TYPE_FACE_DOWN
	return

ViridianCity_EventScript_TryUnlockGym::
	goto_if_unset FLAG_BADGE02_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE03_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE04_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE05_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE06_GET, Common_EventScript_NopReturn
	goto_if_unset FLAG_BADGE07_GET, Common_EventScript_NopReturn
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR, 1
	return

ViridianCity_EventScript_GymDoorLocked::
	lockall
	textcolor NPC_TEXT_COLOR_NEUTRAL
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	msgbox ViridianCity_Text_GymDoorsAreLocked
	closemessage
	applymovement LOCALID_PLAYER, ViridianCity_Movement_JumpDownLedge
	waitmovement 0
	releaseall
	end

ViridianCity_Movement_JumpDownLedge::
	jump_2_down
	step_end

ViridianCity_EventScript_CitySign::
	msgbox ViridianCity_Text_CitySign, MSGBOX_SIGN
	end

ViridianCity_EventScript_TrainerTips1::
	msgbox ViridianCity_Text_CatchMonsForEasierBattles, MSGBOX_SIGN
	end

ViridianCity_EventScript_TrainerTips2::
	msgbox ViridianCity_Text_MovesLimitedByPP, MSGBOX_SIGN
	end

ViridianCity_EventScript_GymSign::
	msgbox ViridianCity_Text_GymSign, MSGBOX_SIGN
	end

ViridianCity_EventScript_GymDoor::
	msgbox ViridianCity_Text_GymDoorsAreLocked, MSGBOX_SIGN
	end

ViridianCity_EventScript_Boy::
	msgbox ViridianCity_Text_CanCarryMonsAnywhere, MSGBOX_NPC
	end

@ Other old man, not the tutorial old man
ViridianCity_EventScript_OldMan::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR, 1, ViridianCity_EventScript_OldManGymLeaderReturned
	msgbox ViridianCity_Text_GymClosedWonderWhoLeaderIs
	closemessage
	applymovement LOCALID_VIRIDIAN_OLD_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

ViridianCity_EventScript_OldManGymLeaderReturned::
	msgbox ViridianCity_Text_ViridiansGymLeaderReturned
	release
	end

ViridianCity_EventScript_TutorialOldMan::
	lock
	faceplayer
	goto_if_set FLAG_BADGE01_GET, ViridianCity_EventScript_AskIfTeachyTVHelpful
	goto_if_ge VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2, ViridianCity_EventScript_TutorialCompleted
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1, ViridianCity_EventScript_TutorialStart
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0, ViridianCity_EventScript_TutorialNotReady
	end

ViridianCity_EventScript_AskIfTeachyTVHelpful::
	msgbox ViridianCity_Text_HowsTeachyTVHelping, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianCity_EventScript_TeachyTVNotHelpful
	msgbox ViridianCity_Text_MyGrandsonOnTheShow
	release
	end

ViridianCity_EventScript_TeachyTVNotHelpful::
	msgbox ViridianCity_Text_TooBusyForTeachyTV
	release
	end

ViridianCity_EventScript_TutorialCompleted::
	msgbox ViridianCity_Text_WeakenMonsFirstToCatch
	release
	end

ViridianCity_EventScript_TutorialStart::
	call ViridianCity_EventScript_DoTutorialBattle
	release
	end

@ Unused
ViridianCity_EventScript_WatchToLearnBasics::
	msgbox ViridianCity_Text_WatchThatToLearnBasics
	release
	end

@ Unused. Starts battle after the post battle text, which is odd.
ViridianCity_EventScript_TutorialUnused::
	msgbox ViridianCity_Text_ThatWasEducationalTakeThis
	special StartOldManTutorialBattle
	waitstate
	release
	end

ViridianCity_EventScript_TutorialNotReady::
	msgbox ViridianCity_Text_ThisIsPrivateProperty
	closemessage
	release
	end

ViridianCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox ViridianCity_Text_WantToKnowAboutCaterpillarMons, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, ViridianCity_EventScript_YoungsterExplainCaterpillars
	goto_if_eq VAR_RESULT, NO, ViridianCity_EventScript_YoungsterDeclineExplanation
	end

ViridianCity_EventScript_YoungsterExplainCaterpillars::
	msgbox ViridianCity_Text_ExplainCaterpieWeedle
	release
	end

ViridianCity_EventScript_YoungsterDeclineExplanation::
	msgbox ViridianCity_Text_OhOkayThen
	release
	end

ViridianCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0, ViridianCity_EventScript_WomanRoadBlocked
	msgbox ViridianCity_Text_GoShoppingInPewterOccasionally
	release
	end

ViridianCity_EventScript_WomanRoadBlocked::
	msgbox ViridianCity_Text_GrandpaHasntHadCoffeeYet
	closemessage
	applymovement LOCALID_VIRIDIAN_WOMAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

ViridianCity_EventScript_DreamEaterTutor::
	goto EventScript_DreamEaterTutor
	end

ViridianCity_EventScript_RoadBlocked::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	msgbox ViridianCity_Text_ThisIsPrivateProperty
	closemessage
	applymovement LOCALID_PLAYER, ViridianCity_Movement_WalkDown
	waitmovement 0
	releaseall
	end

ViridianCity_Movement_WalkDown::
	walk_down
	step_end

ViridianCity_EventScript_TutorialTriggerLeft::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_TUTORIAL_MAN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	call ViridianCity_EventScript_DoTutorialBattle
	release
	end

ViridianCity_EventScript_TutorialTriggerRight::
	lockall
	textcolor NPC_TEXT_COLOR_MALE
	applymovement LOCALID_TUTORIAL_MAN, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	call ViridianCity_EventScript_DoTutorialBattle
	release
	end

ViridianCity_EventScript_DoTutorialBattle::
	msgbox ViridianCity_Text_ShowYouHowToCatchMons
	closemessage
	special StartOldManTutorialBattle
	waitstate
	lock
	faceplayer
	msgbox ViridianCity_Text_ThatWasEducationalTakeThis
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2
	giveitem ITEM_TEACHY_TV
	msgbox ViridianCity_Text_WatchThatToLearnBasics
	return

ViridianCity_Text_CanCarryMonsAnywhere::
	.string "C'est une POKé BALL que je vois!\n"
	.string "Alors t'as aussi des POKéMON?\p"
	.string "C'est cool de pouvoir s'en servir\n"
	.string "quand on veut, hein?$"

ViridianCity_Text_GymClosedWonderWhoLeaderIs::
	.string "Cette ARENE POKéMON est\n"
	.string "toujours fermée.\p"
	.string "Mais qui en est le CHAMPION?$"

ViridianCity_Text_ViridiansGymLeaderReturned::
	.string "Le CHAMPION de l'ARENE de\n"
	.string "JADIELLE est de retour!$"

ViridianCity_Text_WantToKnowAboutCaterpillarMons::
	.string "Tu veux tout savoir sur les deux\n"
	.string "types de POKéMON chenille?$"

ViridianCity_Text_OhOkayThen::
	.string "Bon, OK!$"

ViridianCity_Text_ExplainCaterpieWeedle::
	.string "Contrairement à CHENIPAN, ASPICOT\n"
	.string "est venimeux.\p"
	.string "Attention à son DARD-VENIN!$"

ViridianCity_Text_GrandpaHasntHadCoffeeYet::
	.string "Papy!\n"
	.string "Ne sois pas si méchant.\p"
	.string "Je suis désolée.\n"
	.string "Il n'a pas encore eu son café.$"

ViridianCity_Text_GoShoppingInPewterOccasionally::
	.string "Je passe par la FORET DE JADE\n"
	.string "pour faire mes courses à ARGENTA.$"

ViridianCity_Text_ThisIsPrivateProperty::
	.string "Je t'interdis de passer par là!\p"
	.string "C'est une propriété privée!$"

ViridianCity_Text_ShowYouHowToCatchMons::
	.string "Il me fallait juste un café pour\n"
	.string "être sur pied!\p"
	.string "Hum? Qu'est-ce que c'est que\n"
	.string "cette boîte rouge que tu as?\p"
	.string "Ah, alors tu travailles sur\n"
	.string "ton POKéDEX.\p"
	.string "Laisse-moi te donner un\n"
	.string "petit conseil.\p"
	.string "Le POKéDEX se met à jour dès\n"
	.string "que tu attrapes un POKéMON.\p"
	.string "… Tu ne sais pas attraper\n"
	.string "de POKéMON?\p"
	.string "Je crois que je ferais mieux de\n"
	.string "te montrer alors!$"

ViridianCity_Text_ThatWasEducationalTakeThis::
	.string "Et voilà! Si tu n'as pas compris\n"
	.string "avec ça…\p"
	.string "Je voudrais aussi que tu\n"
	.string "prennes ceci.$"

ViridianCity_Text_WatchThatToLearnBasics::
	.string "S'il y a quelque chose que tu\n"
	.string "ne comprends pas, regarde bien.\p"
	.string "Cela t'apprendra les bases pour\n"
	.string "être DRESSEUR de POKéMON.$"

ViridianCity_Text_WeakenMonsFirstToCatch::
	.string "Ahh… Un p'tit somme, un bon café\n"
	.string "et hop! La pêche pour la journée!\p"
	.string "Mais j'ai dû le faire trop fort.\n"
	.string "J'ai la migraine maintenant.\p"
	.string "Au fait, est-ce que tu remplis\n"
	.string "ton POKéDEX?\p"
	.string "Pense à bien affaiblir les\n"
	.string "POKéMON avant de les attraper.$"

ViridianCity_Text_HowsTeachyTVHelping::
	.string "Ahh… Un p'tit somme, un bon café\n"
	.string "et hop! La pêche pour la journée!\p"
	.string "Mais j'ai dû le faire trop fort.\n"
	.string "J'ai la migraine maintenant.\p"
	.string "Au fait, est-ce que tu regardes\n"
	.string "souvent TV ABC?$"

ViridianCity_Text_MyGrandsonOnTheShow::
	.string "Ahaha!\n"
	.string "C'est mon petit-fils à la télé!\p"
	.string "Avec lui, tu vas tout comprendre!$"

ViridianCity_Text_TooBusyForTeachyTV::
	.string "Hum. Tu dois avoir trop de choses\n"
	.string "à faire pour regarder la télé.\p"
	.string "Le temps c'est de l'argent,\n"
	.string "t'as bien raison.$"

ViridianCity_Text_CitySign::
	.string "JADIELLE\n"
	.string "Verte comme l'espérance$"

ViridianCity_Text_CatchMonsForEasierBattles::
	.string "ASTUCE\p"
	.string "Attrapez des POKéMON et\n"
	.string "agrandissez votre collection!\p"
	.string "Plus vous en capturez, plus\n"
	.string "les combats sont faciles!$"

ViridianCity_Text_MovesLimitedByPP::
	.string "ASTUCE\p"
	.string "Les attaques sont limitées par des\n"
	.string "PP (Points de Pouvoir).\p"
	.string "Pour disposer de tous vos PP,\n"
	.string "faites soigner vos POKéMON dans\l"
	.string "un CENTRE POKéMON!$"

ViridianCity_Text_GymSign::
	.string "ARENE POKéMON de JADIELLE$"

ViridianCity_Text_GymDoorsAreLocked::
	.string "Les portes de l'ARENE sont\n"
	.string "fermées…$"


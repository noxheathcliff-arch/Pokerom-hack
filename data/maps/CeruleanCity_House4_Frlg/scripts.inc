.set REWARD_TYPE, VAR_0x8004
.set REWARD_ITEM, VAR_0x8008

CeruleanCity_House4_Frlg_MapScripts::
	.byte 0

CeruleanCity_House4_EventScript_WonderNewsBerryMan::
	lock
	specialvar REWARD_TYPE, WonderNews_GetRewardInfo
	copyvar REWARD_ITEM, VAR_RESULT
	goto_if_eq REWARD_TYPE, NEWS_REWARD_NONE,       CeruleanCity_House4_EventScript_NoNews
	goto_if_eq REWARD_TYPE, NEWS_REWARD_RECV_SMALL, CeruleanCity_House4_EventScript_Reward_RecvSmall
	goto_if_eq REWARD_TYPE, NEWS_REWARD_RECV_BIG,   CeruleanCity_House4_EventScript_Reward_RecvBig
	goto_if_eq REWARD_TYPE, NEWS_REWARD_WAITING,    CeruleanCity_House4_EventScript_Waiting
	goto_if_eq REWARD_TYPE, NEWS_REWARD_SENT_SMALL, CeruleanCity_House4_EventScript_Reward_SentSmall
	goto_if_eq REWARD_TYPE, NEWS_REWARD_SENT_BIG,   CeruleanCity_House4_EventScript_Reward_SentBig
	goto_if_eq REWARD_TYPE, NEWS_REWARD_AT_MAX,     CeruleanCity_House4_EventScript_AtMax
	end

@ Mystery Gift is not enabled, or the player has no saved Wonder News
CeruleanCity_House4_EventScript_NoNews::
	msgbox CeruleanCity_House4_Text_NothingEntertaining
	release
	end

@ Small reward for receiving Wonder News from friend
CeruleanCity_House4_EventScript_Reward_RecvSmall::
	call CeruleanCity_House4_EventScript_MovementReactionToNews
	msgbox CeruleanCity_House4_Text_NewNewsInformativeHaveThis
	giveitem REWARD_ITEM
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House4_EventScript_NoRoomForBerries
	release
	end

@ Big reward for receiving Wonder News from non-friend source
CeruleanCity_House4_EventScript_Reward_RecvBig::
	call CeruleanCity_House4_EventScript_MovementReactionToNews
	msgbox CeruleanCity_House4_Text_IncredibleNewsHaveBerries
	giveitem REWARD_ITEM, 4
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House4_EventScript_NoRoomForBerries
	release
	end

@ Player has not recently sent Wonder News
CeruleanCity_House4_EventScript_Waiting::
	applymovement LOCALID_WONDER_NEWS_BERRY_MAN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox CeruleanCity_House4_Text_WishCouldShareNewsWithOthers
	release
	end

@ Small reward for sending Wonder News every 1-3 times
CeruleanCity_House4_EventScript_Reward_SentSmall::
	call CeruleanCity_House4_EventScript_MovementReactionToNews
	msgbox CeruleanCity_House4_Text_ThanksForSpreadingNewsTakeThis
	giveitem REWARD_ITEM
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House4_EventScript_NoRoomForBerries
	release
	end

@ Big reward for sending Wonder News every 4th time
CeruleanCity_House4_EventScript_Reward_SentBig::
	call CeruleanCity_House4_EventScript_MovementReactionToNews
	msgbox CeruleanCity_House4_Text_MagnificentNewsSpreadHaveBerries
	giveitem REWARD_ITEM, 4
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House4_EventScript_NoRoomForBerries
	release
	end

@ Player has hit reward limit and must wait to receive new rewards
CeruleanCity_House4_EventScript_AtMax::
	applymovement LOCALID_WONDER_NEWS_BERRY_MAN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox CeruleanCity_House4_Text_EnjoyingMyselfWithAllSortsOfNews
	release
	end

CeruleanCity_House4_EventScript_MovementReactionToNews::
	playse SE_PIN
	applymovement LOCALID_WONDER_NEWS_BERRY_MAN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WONDER_NEWS_BERRY_MAN, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_WONDER_NEWS_BERRY_MAN, Common_Movement_Delay48
	waitmovement 0
	return

CeruleanCity_House4_EventScript_NoRoomForBerries::
	msgbox CeruleanCity_House4_Text_YourBerryPouchIsFull
	release
	end

CeruleanCity_House4_Text_NothingEntertaining::
	.string "… Aaah…\n"
	.string "Tellement de temps et rien à faire…\p"
	.string "Y'aurait pas un truc amusant à\n"
	.string "faire dans le coin?$"

CeruleanCity_House4_Text_NewNewsInformativeHaveThis::
	.string "Ah!\n"
	.string "C'est l'heure des infos!\p"
	.string "Hmm…\n"
	.string "Je vois. C'était très intéressant.\p"
	.string "Et bravo pour t'intéresser aux\n"
	.string "infos à ton âge.\p"
	.string "Pour te remercier, je voudrais\n"
	.string "te donner ceci.$"

CeruleanCity_House4_Text_IncredibleNewsHaveBerries::
	.string "Oh oh!\n"
	.string "Des nouvelles fraîches!\p"
	.string "Hm…\p"
	.string "Incroyable, pour des nouvelles,\n"
	.string "ça c'est des nouvelles!\p"
	.string "J'avais pas entendu quelque\n"
	.string "chose comme ça depuis des lustres!\p"
	.string "Tiens, prends ces BAIES en\n"
	.string "remerciement!$"

CeruleanCity_House4_Text_WishCouldShareNewsWithOthers::
	.string "Cette nouvelle est trop incroyable\n"
	.string "pour la garder pour nous…\p"
	.string "Je voudrais la raconter à tout le\n"
	.string "monde…$"

CeruleanCity_House4_Text_ThanksForSpreadingNewsTakeThis::
	.string "Tu as fait suivre l'info pour moi?\p"
	.string "L'important avec l'information, c'est\n"
	.string "de la partager.\p"
	.string "En remerciement, je voudrais te\n"
	.string "donner ceci.$"

CeruleanCity_House4_Text_MagnificentNewsSpreadHaveBerries::
	.string "Tu as encore fait suivre\n"
	.string "l'information? Formidable!\p"
	.string "Il faut que le plus de monde\n"
	.string "possible soit au courant.\p"
	.string "Tu sais quoi?\p"
	.string "Pour te remercier, je vais te\n"
	.string "donner encore plus de BAIES.$"

CeruleanCity_House4_Text_EnjoyingMyselfWithAllSortsOfNews::
	.string "Avec toutes ces nouvelles,\n"
	.string "je risque plus de m'ennuyer!$"

CeruleanCity_House4_Text_YourBerryPouchIsFull::
	.string "Hmm? Ta POCHE A BAIES est pleine.\n"
	.string "Dommage pour le cadeau alors.$"


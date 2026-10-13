Route1_Frlg_MapScripts::
	.byte 0

Route1_EventScript_MartClerk::
	lock
	faceplayer
	goto_if_set FLAG_GOT_POTION_ON_ROUTE_1, Route1_EventScript_AlreadyGotPotion
	msgbox Route1_Text_WorkAtPokeMartTakeSample
	textcolor NPC_TEXT_COLOR_NEUTRAL
	checkitemspace ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	bufferitemname STR_VAR_2, ITEM_POTION
	playfanfare MUS_LEVEL_UP
	message gText_ObtainedTheItem
	waitmessage
	waitfanfare
	additem ITEM_POTION
	msgbox Route1_Text_PutPotionAway
	call EventScript_RestorePrevTextColor
	setflag FLAG_GOT_POTION_ON_ROUTE_1
	release
	end

Route1_EventScript_AlreadyGotPotion::
	msgbox Route1_Text_ComeSeeUsIfYouNeedPokeBalls
	release
	end

Route1_EventScript_Boy::
	msgbox Route1_Text_CanJumpFromLedges, MSGBOX_NPC
	end

Route1_EventScript_RouteSign::
	msgbox Route1_Text_RouteSign, MSGBOX_SIGN
	end

Route1_Text_WorkAtPokeMartTakeSample::
	.string "Salut! Je travaille à la\n"
	.string "BOUTIQUE POKéMON.\p"
	.string "Nous avons plein d'articles! Viens\n"
	.string "nous voir à JADIELLE.\p"
	.string "Prends donc ceci comme\n"
	.string "échantillon!$"

Route1_Text_ComeSeeUsIfYouNeedPokeBalls::
	.string "Nous avons aussi des POKé BALLS\n"
	.string "pour capturer les POKéMON!$"

Route1_Text_PutPotionAway::
	.string "{PLAYER} range la POTION dans la\n"
	.string "POCHE OBJETS du SAC.$"

Route1_Text_CanJumpFromLedges::
	.string "Tu vois tous ces petits talus?\p"
	.string "Tu peux sauter par-dessus!\n"
	.string "C'est dingue, non?\p"
	.string "Tu peux revenir plus vite à\n"
	.string "BOURG PALETTE de cette façon!$"

Route1_Text_RouteSign::
	.string "ROUTE 1\n"
	.string "BOURG PALETTE - JADIELLE$"


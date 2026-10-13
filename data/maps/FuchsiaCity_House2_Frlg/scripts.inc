FuchsiaCity_House2_Frlg_MapScripts::
	.byte 0

FuchsiaCity_House2_EventScript_FishingGurusBrother::
	lock
	faceplayer
	goto_if_set FLAG_GOT_GOOD_ROD, FuchsiaCity_House2_EventScript_AlreadyGotGoodRod
	msgbox FuchsiaCity_House2_Text_DoYouLikeToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_House2_EventScript_GiveGoodRod
	msgbox FuchsiaCity_House2_Text_OhThatsDisappointing
	release
	end

FuchsiaCity_House2_EventScript_AlreadyGotGoodRod::
	msgbox FuchsiaCity_House2_Text_HowAreTheFishBiting
	release
	end

FuchsiaCity_House2_EventScript_GiveGoodRod::
	msgbox FuchsiaCity_House2_Text_LikeYourStyleTakeThis
	checkitemspace ITEM_GOOD_ROD
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_House2_EventScript_NoRoomForGoodRod
	giveitem_msg FuchsiaCity_House2_Text_ReceivedGoodRod, ITEM_GOOD_ROD
	msgbox FuchsiaCity_House2_Text_GoodRodCanCatchBetterMons
	setflag FLAG_GOT_GOOD_ROD
	release
	end

FuchsiaCity_House2_EventScript_NoRoomForGoodRod::
	msgbox FuchsiaCity_House2_Text_YouHaveNoRoomForGift
	release
	end

FuchsiaCity_House2_Text_DoYouLikeToFish::
	.string "Je suis le grand frère du MAITRE\n"
	.string "PECHEUR!\p"
	.string "Moi, mon truc, c'est la pêche!\p"
	.string "T'aimes la pêche?$"

FuchsiaCity_House2_Text_LikeYourStyleTakeThis::
	.string "T'as l'air de quelqu'un de bien!\p"
	.string "Prends ça! Que la Grand' Pêche\n"
	.string "soit avec toi!$"

FuchsiaCity_House2_Text_ReceivedGoodRod::
	.string "{PLAYER} reçoit la SUPER CANNE!$"

FuchsiaCity_House2_Text_GoodRodCanCatchBetterMons::
	.string "Pêcher, c'est la vie!\n"
	.string "Et la vie, c'est la pêche!\p"
	.string "Avec cette SUPER CANNE, tu vas\n"
	.string "pouvoir attraper des\l"
	.string "SUPER POKéMON.$"

FuchsiaCity_House2_Text_OhThatsDisappointing::
	.string "Oh… Je suis très déçu…$"

FuchsiaCity_House2_Text_HowAreTheFishBiting::
	.string "B'jour à toi, {PLAYER}!\p"
	.string "Ça mord? Hein? Hein?$"

FuchsiaCity_House2_Text_YouHaveNoRoomForGift::
	.string "Ha ben non!\p"
	.string "J'avais un cadeau pour toi, mais\n"
	.string "t'as plus de place!$"


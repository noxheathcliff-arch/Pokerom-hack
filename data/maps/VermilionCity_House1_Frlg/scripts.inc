VermilionCity_House1_Frlg_MapScripts::
	.byte 0

VermilionCity_House1_EventScript_FishingGuru::
	lock
	faceplayer
	goto_if_set FLAG_GOT_OLD_ROD, VermilionCity_House1_EventScript_AlreadyGotOldRod
	msgbox VermilionCity_House1_Text_ImFishingGuruDoYouLikeToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, VermilionCity_House1_EventScript_GiveOldRod
	msgbox VermilionCity_House1_Text_OhThatsSoDisappointing
	release
	end

VermilionCity_House1_EventScript_AlreadyGotOldRod::
	msgbox VermilionCity_House1_Text_HowAreTheFishBiting
	release
	end

VermilionCity_House1_EventScript_GiveOldRod::
	checkitemspace ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_House1_EventScript_NoRoomForOldRod
	additem ITEM_OLD_ROD
	msgbox VermilionCity_House1_Text_TakeThisAndFish
	msgreceiveditem VermilionCity_House1_Text_ReceivedOldRodFromFishingGuru, ITEM_OLD_ROD
	setflag FLAG_GOT_OLD_ROD
	msgbox VermilionCity_House1_Text_FishingIsAWayOfLife
	release
	end

VermilionCity_House1_EventScript_NoRoomForOldRod::
	msgbox VermilionCity_House1_Text_NoRoomForNiceGift
	release
	end

VermilionCity_House1_Text_ImFishingGuruDoYouLikeToFish::
	.string "Je suis le… MAITRE PECHEUR!\p"
	.string "La pêche… moi…\n"
	.string "J'adore ça!\p"
	.string "Et toi, p'tite tête?$"

VermilionCity_House1_Text_TakeThisAndFish::
	.string "Cool!\n"
	.string "T'as l'air de quelqu'un de bien!\p"
	.string "Prends ça! Que la Grand' Pêche\n"
	.string "soit avec toi!$"

VermilionCity_House1_Text_ReceivedOldRodFromFishingGuru::
	.string "{PLAYER} obtient la\n"
	.string "CANNE!$"

VermilionCity_House1_Text_FishingIsAWayOfLife::
	.string "La pêche c'est comme la vie!\p"
	.string "Quand ça mord, ça va! \n"
	.string "Quand ça mord pas, ça va pas!$"

VermilionCity_House1_Text_OhThatsSoDisappointing::
	.string "Oh… Je suis très déçu…$"

VermilionCity_House1_Text_HowAreTheFishBiting::
	.string "Tiens, salut {PLAYER}!\p"
	.string "Alors, ça mord?$"

VermilionCity_House1_Text_NoRoomForNiceGift::
	.string "Ha ben non!\p"
	.string "J'avais un cadeau pour toi, mais\n"
	.string "t'as plus de place!$"


CeruleanCity_BikeShop_Frlg_MapScripts::
	.byte 0

CeruleanCity_BikeShop_EventScript_Clerk::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BICYCLE, CeruleanCity_BikeShop_EventScript_AlreadyGotBicycle
	goto_if_set FLAG_GOT_BIKE_VOUCHER, CeruleanCity_BikeShop_EventScript_ExchangeBikeVoucher
	showmoneybox 0, 0
	message CeruleanCity_BikeShop_Text_WelcomeToBikeShop
	waitmessage
	multichoice 11, 0, MULTI_BIKE_SHOP, FALSE
	hidemoneybox
	showmoneybox 0, 0
	switch VAR_RESULT
	case 0, CeruleanCity_BikeShop_EventScript_TryPurchaseBicycle
	case 1, CeruleanCity_BikeShop_EventScript_ClerkGoodbye
	case 127, CeruleanCity_BikeShop_EventScript_ClerkGoodbye
	end

@ The Bicycle price / players money is never actually checked
CeruleanCity_BikeShop_EventScript_TryPurchaseBicycle::
	msgbox CeruleanCity_BikeShop_Text_SorryYouCantAffordIt
	goto CeruleanCity_BikeShop_EventScript_ClerkGoodbye
	end

CeruleanCity_BikeShop_EventScript_ClerkGoodbye::
	msgbox CeruleanCity_BikeShop_Text_ThankYouComeAgain
	hidemoneybox
	release
	end

CeruleanCity_BikeShop_EventScript_ExchangeBikeVoucher::
	msgbox CeruleanCity_BikeShop_Text_OhBikeVoucherHereYouGo
	msgreceiveditem CeruleanCity_BikeShop_Text_ExchangedVoucherForBicycle, ITEM_BICYCLE, 1, MUS_RG_OBTAIN_KEY_ITEM
	setflag FLAG_GOT_BICYCLE
	additem ITEM_BICYCLE
	removeitem ITEM_BIKE_VOUCHER
	msgbox CeruleanCity_BikeShop_Text_ThankYouComeAgain
	release
	end

CeruleanCity_BikeShop_EventScript_AlreadyGotBicycle::
	msgbox CeruleanCity_BikeShop_Text_HowDoYouLikeNewBicycle
	release
	end

@ Unused
CeruleanCity_BikeShop_EventScript_NoRoomForBicycle::
	msgbox CeruleanCity_BikeShop_Text_MakeRoomForBicycle
	release
	end

CeruleanCity_BikeShop_EventScript_Woman::
	msgbox CeruleanCity_BikeShop_Text_CityBikeGoodEnoughForMe, MSGBOX_NPC
	end

CeruleanCity_BikeShop_EventScript_Youngster::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BICYCLE, CeruleanCity_BikeShop_EventScript_YoungsterHaveBike
	msgbox CeruleanCity_BikeShop_Text_BikesCoolButExpensive
	release
	end

CeruleanCity_BikeShop_EventScript_YoungsterHaveBike::
	msgbox CeruleanCity_BikeShop_Text_WowYourBikeIsCool
	release
	end

CeruleanCity_BikeShop_EventScript_Bicycle::
	msgbox CeruleanCity_BikeShop_Text_ShinyNewBicycle, MSGBOX_SIGN
	end

CeruleanCity_BikeShop_Text_WelcomeToBikeShop::
	.string "Bienvenue aux CYCLES A GOGO.\p"
	.string "Nous avons justement une belle\n"
	.string "bicyclette!$"

CeruleanCity_BikeShop_Text_SorryYouCantAffordIt::
	.string "Oh!\n"
	.string "Tu n'as pas assez d'argent!$"

CeruleanCity_BikeShop_Text_OhBikeVoucherHereYouGo::
	.string "Oh! Mais c'est…\p"
	.string "Un BON pour une BICYCLETTE!\p"
	.string "OK!\n"
	.string "Voilà ta BICYCLETTE!$"

CeruleanCity_BikeShop_Text_ExchangedVoucherForBicycle::
	.string "{PLAYER} échange le BON contre une\n"
	.string "BICYCLETTE.$"

CeruleanCity_BikeShop_Text_ThankYouComeAgain::
	.string "Reviens quand tu veux!$"

CeruleanCity_BikeShop_Text_HowDoYouLikeNewBicycle::
	.string "Ça va comme tu veux\n"
	.string "avec ta BICYCLETTE?\p"
	.string "Avec, tu peux aller sur la PISTE\n"
	.string "CYCLABLE et dans les GROTTES!$"

CeruleanCity_BikeShop_Text_MakeRoomForBicycle::
	.string "Ton inventaire est plein!$"

CeruleanCity_BikeShop_Text_CityBikeGoodEnoughForMe::
	.string "Un vélo de ville, c'est ce qu'il y\n"
	.string "a de mieux!\p"
	.string "Il n'y a pas de porte-bagages sur\n"
	.string "un VTT!$"

CeruleanCity_BikeShop_Text_BikesCoolButExpensive::
	.string "Ces vélos sont super mais ils sont\n"
	.string "très chers!$"

CeruleanCity_BikeShop_Text_WowYourBikeIsCool::
	.string "Waouh! \n"
	.string "Ta BICYCLETTE est super cool!$"

@ Unused
CeruleanCity_BikeShop_Text_GermanFoldableBicyleFinallyOnMarket::
	.string "ついに　はつばい！\p"
	.string "ドイツ　せい　さいこうきゅう\n"
	.string "おりたたみ　じてんしゃ！$"

CeruleanCity_BikeShop_Text_ShinyNewBicycle::
	.string "Une BICYCLETTE toute neuve! Top!$"


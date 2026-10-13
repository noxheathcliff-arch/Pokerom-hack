CeruleanCity_House5_Frlg_MapScripts::
	.byte 0

CeruleanCity_House5_EventScript_BerryPowderMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_POWDER_JAR, CeruleanCity_House5_EventScript_AskToExchangePowder
	msgbox CeruleanCity_House1_Text_AnyInterestInBerries, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeruleanCity_House5_EventScript_NoInterestInBerries
	goto_if_unset FLAG_SYS_GOT_BERRY_POUCH, CeruleanCity_House5_EventScript_NoBerries
	msgbox CeruleanCity_House1_Text_HaveJustTheThing
	setflag FLAG_GOT_POWDER_JAR
	giveitem ITEM_POWDER_JAR
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	msgbox CeruleanCity_House1_Text_GoCrushBerriesAtDirectCorner
	release
	end

CeruleanCity_House5_EventScript_NoBerries::
	msgbox CeruleanCity_House1_Text_WhyMustYouLieNoBerries
	release
	end

CeruleanCity_House5_EventScript_NoInterestInBerries::
	msgbox CeruleanCity_House1_Text_TakeInterestInAllSortsOfThings
	release
	end

CeruleanCity_House5_EventScript_AskToExchangePowder::
	special DisplayBerryPowderVendorMenu
	msgbox CeruleanCity_House1_Text_HaveYouBroughtBerryPowder
	goto CeruleanCity_House5_EventScript_ChooseExchangeItem
	end

CeruleanCity_House5_EventScript_ChooseExchangeItem::
	message CeruleanCity_House5_Text_ExchangeWithWhat
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
	special ShowScrollableMultichoice
	switch VAR_RESULT
	case 0, CeruleanCity_House5_EventScript_EnergyPowder
	case 1, CeruleanCity_House5_EventScript_EnergyRoot
	case 2, CeruleanCity_House5_EventScript_HealPowder
	case 3, CeruleanCity_House5_EventScript_RevivalHerb
	case 4, CeruleanCity_House5_EventScript_Protein
	case 5, CeruleanCity_House5_EventScript_Iron
	case 6, CeruleanCity_House5_EventScript_Carbos
	case 7, CeruleanCity_House5_EventScript_Calcium
	case 8, CeruleanCity_House5_EventScript_Zinc
	case 9, CeruleanCity_House5_EventScript_HPUp
	case 10, CeruleanCity_House5_EventScript_PPUp
	case 11, CeruleanCity_House5_EventScript_ExitMenu
	case 127, CeruleanCity_House5_EventScript_ExitMenu
	end

CeruleanCity_House5_EventScript_EnergyPowder::
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
	setvar VAR_0x8009, 50
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_EnergyRoot::
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
	setvar VAR_0x8009, 80
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_HealPowder::
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
	setvar VAR_0x8008, ITEM_HEAL_POWDER
	setvar VAR_0x8009, 50
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_RevivalHerb::
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
	setvar VAR_0x8009, 300
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_Protein::
	bufferitemname STR_VAR_1, ITEM_PROTEIN
	setvar VAR_0x8008, ITEM_PROTEIN
	setvar VAR_0x8009, 1000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_Iron::
	bufferitemname STR_VAR_1, ITEM_IRON
	setvar VAR_0x8008, ITEM_IRON
	setvar VAR_0x8009, 1000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_Carbos::
	bufferitemname STR_VAR_1, ITEM_CARBOS
	setvar VAR_0x8008, ITEM_CARBOS
	setvar VAR_0x8009, 1000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_Calcium::
	bufferitemname STR_VAR_1, ITEM_CALCIUM
	setvar VAR_0x8008, ITEM_CALCIUM
	setvar VAR_0x8009, 1000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_Zinc::
	bufferitemname STR_VAR_1, ITEM_ZINC
	setvar VAR_0x8008, ITEM_ZINC
	setvar VAR_0x8009, 1000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_HPUp::
	bufferitemname STR_VAR_1, ITEM_HP_UP
	setvar VAR_0x8008, ITEM_HP_UP
	setvar VAR_0x8009, 1000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_PPUp::
	bufferitemname STR_VAR_1, ITEM_PP_UP
	setvar VAR_0x8008, ITEM_PP_UP
	setvar VAR_0x8009, 3000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_ExitMenu::
	msgbox CeruleanCity_House1_Text_SeeMeIfYoudLikeToTradePowder
	special RemoveBerryPowderVendorMenu
	release
	end

CeruleanCity_House5_EventScript_ExchangePowderForItem::
	msgbox CeruleanCity_House1_Text_YoullExchangeBerryPowderForItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeruleanCity_House5_EventScript_ChooseExchangeItem
	copyvar VAR_0x8004, VAR_0x8009
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House5_EventScript_NotEnoughBerryPowder
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House5_EventScript_BagIsFull
	copyvar VAR_0x8004, VAR_0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	msgbox CeruleanCity_House1_Text_TradeMoreBerryPowder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CeruleanCity_House5_EventScript_ChooseExchangeItem
	msgbox CeruleanCity_House1_Text_HopeToSeeYouAgain
	special RemoveBerryPowderVendorMenu
	release
	end

CeruleanCity_House5_EventScript_BagIsFull::
	msgbox gText_TheBagIsFull
	special RemoveBerryPowderVendorMenu
	release
	end

CeruleanCity_House5_EventScript_NotEnoughBerryPowder::
	msgbox CeruleanCity_House1_Text_DontHaveEnoughBerryPowder
	goto CeruleanCity_House5_EventScript_ChooseExchangeItem
	end

CeruleanCity_House5_EventScript_BerryCrushRankings::
	lockall
	special ShowBerryCrushRankings
	releaseall
	end

CeruleanCity_House1_Text_AnyInterestInBerries::
	.string "En utilisant de la bonne POUDRE\n"
	.string "BAIE, je peux préparer\p"
	.string "toutes sortes de médicaments.\p"
	.string "Dis-moi, tu t'y connais un peu\n"
	.string "en BAIES?$"

CeruleanCity_House1_Text_HaveJustTheThing::
	.string "Parfait! Alors j'ai juste ce qu'il\n"
	.string "te faut.$"

CeruleanCity_House1_Text_GoCrushBerriesAtDirectCorner::
	.string "Il y a du nouveau au premier\n"
	.string "étage des CENTRES POKéMON.\p"
	.string "Ils ont ajouté une machine pour\n"
	.string "broyer les BAIES dans\p"
	.string "la SALLE LINK DIRECT.\n"
	.string "C'est là que tu interviens.\p"
	.string "Pourrais-tu aller faire de la\n"
	.string "POUDRE pour moi en\p"
	.string "utilisant cette machine?\p"
	.string "N'oublie pas, la machine se trouve\n"
	.string "dans la SALLE LINK DIRECT.\p"
	.string "Je ferai une préparation juste\n"
	.string "pour toi si tu arrives à broyer\p"
	.string "des BAIES et à me ramener\n"
	.string "la POUDRE.$"

CeruleanCity_House1_Text_WhyMustYouLieNoBerries::
	.string "Pourquoi tu me mens?\n"
	.string "Tu n'as pas une seule BAIE!$"

CeruleanCity_House1_Text_TakeInterestInAllSortsOfThings::
	.string "Les BAIES t'intéressent pas?\p"
	.string "A ton âge, il faut s'intéresser à\n"
	.string "plein de choses.$"

CeruleanCity_House1_Text_HaveYouBroughtBerryPowder::
	.string "M'as-tu amené de la POUDRE BAIE?$"

CeruleanCity_House5_Text_ExchangeWithWhat::
	.string "Contre quoi veux-tu\n"
	.string "l'échanger?$"

CeruleanCity_House1_Text_YoullExchangeBerryPowderForItem::
	.string "Je vais te donner 1 {STR_VAR_1}\n"
	.string "contre la POUDRE BAIE.$"

CeruleanCity_House1_Text_DontHaveEnoughBerryPowder::
	.string "Hmm. Tu n'as pas assez de\n"
	.string "POUDRE BAIE.$"

CeruleanCity_House1_Text_TradeMoreBerryPowder::
	.string "Cette POUDRE BAIE a l'air bonne.\n"
	.string "Ça fera de bons médicaments.\p"
	.string "Tu veux échanger ce qui te reste\n"
	.string "contre autre chose?$"

CeruleanCity_House1_Text_HopeToSeeYouAgain::
	.string "Tant pis. J'espère te revoir\n"
	.string "bientôt.$"

CeruleanCity_House1_Text_SeeMeIfYoudLikeToTradePowder::
	.string "Reviens me voir si tu veux encore\n"
	.string "échanger de la POUDRE BAIE.$"


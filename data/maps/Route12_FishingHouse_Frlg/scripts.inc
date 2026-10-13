Route12_FishingHouse_Frlg_MapScripts::
	.byte 0

Route12_FishingHouse_EventScript_FishingGuruBrother::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SUPER_ROD, Route12_FishingHouse_EventScript_CheckMagikarpRecord
	msgbox Route12_FishingHouse_Text_DoYouLikeToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route12_FishingHouse_EventScript_GiveSuperRod
	msgbox Route12_FishingHouse_Text_OhThatsDisappointing
	release
	end

Route12_FishingHouse_EventScript_GiveSuperRod::
	checkitemspace ITEM_SUPER_ROD
	goto_if_eq VAR_RESULT, FALSE, Route12_FishingHouse_EventScript_NoRoomForSuperRod
	additem ITEM_SUPER_ROD
	msgbox Route12_FishingHouse_Text_TakeThisAndFish
	msgreceiveditem Route12_FishingHouse_Text_ReceivedSuperRod, ITEM_SUPER_ROD
	setflag FLAG_GOT_SUPER_ROD
	msgbox Route12_FishingHouse_Text_IfYouCatchBigMagikarpShowMe
	release
	end

Route12_FishingHouse_EventScript_NoRoomForSuperRod::
	msgbox Route12_FishingHouse_Text_NoRoomForGift
	release
	end

Route12_FishingHouse_EventScript_CheckMagikarpRecord::
	setvar VAR_0x8004, SPECIES_MAGIKARP
	specialvar VAR_RESULT, DoesPlayerPartyContainSpecies
	goto_if_eq VAR_RESULT, FALSE, Route12_FishingHouse_EventScript_NoMagikarpInParty
	special GetMagikarpSizeRecordInfo
	msgbox Route12_FishingHouse_Text_OhMagikarpAllowMeToSee
	special ChoosePartyMon
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_ge VAR_RESULT, PARTY_SIZE, Route12_FishingHouse_EventScript_CancelShowMon
	special CompareMagikarpSize
	goto_if_eq VAR_RESULT, 1, Route12_FishingHouse_EventScript_NotMagikarp
	goto_if_eq VAR_RESULT, 2, Route12_FishingHouse_EventScript_NotRecordMagikarp
	goto_if_eq VAR_RESULT, 3, Route12_FishingHouse_EventScript_NewRecordMagikarp
	goto_if_eq VAR_RESULT, 4, Route12_FishingHouse_EventScript_TieRecordMagikarp
	release
	end

Route12_FishingHouse_EventScript_NoMagikarpInParty::
	msgbox Route12_FishingHouse_Text_TryFishingBringMeMagikarp
	release
	end

Route12_FishingHouse_EventScript_CancelShowMon::
	release
	end

Route12_FishingHouse_EventScript_NotMagikarp::
	msgbox Route12_FishingHouse_Text_DoesntLookLikeMagikarp
	release
	end

Route12_FishingHouse_EventScript_NotRecordMagikarp::
	goto_if_unset FLAG_GOT_RECORD_SETTING_MAGIKARP, Route12_FishingHouse_EventScript_NewRecordMagikarp
	msgbox Route12_FishingHouse_Text_HmmXSizeDoesntMeasureUp
	release
	end

Route12_FishingHouse_EventScript_TieRecordMagikarp::
	goto_if_unset FLAG_GOT_RECORD_SETTING_MAGIKARP, Route12_FishingHouse_EventScript_NewRecordMagikarp
	msgbox Route12_FishingHouse_Text_HuhXSizeSameSizeAsLast
	release
	end

Route12_FishingHouse_EventScript_NewRecordMagikarp::
	setflag FLAG_GOT_RECORD_SETTING_MAGIKARP
	msgbox Route12_FishingHouse_Text_WhoaXSizeTakeThis
	giveitem ITEM_NET_BALL
	goto_if_eq VAR_RESULT, FALSE, Route12_FishingHouse_EventScript_NoRoomForNetBall
	msgbox Route12_FishingHouse_Text_LookForwardToGreaterRecords
	release
	end

Route12_FishingHouse_EventScript_NoRoomForNetBall::
	msgbox Route12_FishingHouse_Text_NoRoomForGift
	release
	end

Route12_FishingHouse_EventScript_MagikarpRecordSign::
	lockall
	goto_if_set FLAG_GOT_RECORD_SETTING_MAGIKARP, Route12_FishingHouse_EventScript_MagikarpRecordSignRecordSet
	msgbox Route12_FishingHouse_Text_BlankChartOfSomeSort
	releaseall
	end

Route12_FishingHouse_EventScript_MagikarpRecordSignRecordSet::
	special GetMagikarpSizeRecordInfo
	msgbox Route12_FishingHouse_Text_MostGiganticMagikarpXSize
	releaseall
	end

Route12_FishingHouse_Text_DoYouLikeToFish::
	.string "Je suis le frère du MAITRE\n"
	.string "PECHEUR!\p"
	.string "Moi, dans la vie, j'suis pêcheur!\n"
	.string "J'adore ça!\p"
	.string "T'aimes la pêche, toi?$"

Route12_FishingHouse_Text_TakeThisAndFish::
	.string "Cool! T'as l'air de quelqu'un\n"
	.string "de bien!\p"
	.string "Prends ça! Et bonne pêche!$"

Route12_FishingHouse_Text_ReceivedSuperRod::
	.string "{PLAYER} obtient la\n"
	.string "MEGA CANNE!$"

Route12_FishingHouse_Text_IfYouCatchBigMagikarpShowMe::
	.string "La pêche, c'est comme la vie!\p"
	.string "Quand ça mord, ça va! \n"
	.string "Quand ça mord pas, ça va pas!\p"
	.string "J'ai un service à te demander.\n"
	.string "Si tu attrapes un gros MAGICARPE\p"
	.string "avec cette canne, j'aimerais\n"
	.string "beaucoup que tu me le montres.\p"
	.string "J'adore voir les gros MAGICARPE,\n"
	.string "presque autant que la pêche.$"

Route12_FishingHouse_Text_OhThatsDisappointing::
	.string "Oh…\n"
	.string "Je suis très déçu…$"

Route12_FishingHouse_Text_TryFishingBringMeMagikarp::
	.string "Salut, {PLAYER}!\p"
	.string "Avec cette MEGA CANNE, tu vas\n"
	.string "vider les océans de tous leurs\p"
	.string "POKéMON. Selon les endroits, tu\n"
	.string "en trouveras des différents.\p"
	.string "Et n'oublie pas de me montrer\n"
	.string "un gros MAGICARPE!$"

Route12_FishingHouse_Text_OhMagikarpAllowMeToSee::
	.string "{PLAYER}?\p"
	.string "Tu m'as ramené un MAGICARPE?\n"
	.string "Vite vite, je veux le voir!$"

Route12_FishingHouse_Text_WhoaXSizeTakeThis::
	.string "… Waouh! {STR_VAR_2}!\n"
	.string "Il est gigantesque!\p"
	.string "La pêche n'a plus de secret\n"
	.string "pour toi.\p"
	.string "Prends ça, j'insiste!$"

Route12_FishingHouse_Text_LookForwardToGreaterRecords::
	.string "J'ai hâte de voir tes prochaines\n"
	.string "prises!$"

Route12_FishingHouse_Text_HuhXSizeSameSizeAsLast::
	.string "Hein?\n"
	.string "{STR_VAR_2}?\p"
	.string "C'est la même taille que la\n"
	.string "dernière fois.$"

Route12_FishingHouse_Text_HmmXSizeDoesntMeasureUp::
	.string "Hmmm…\n"
	.string "Celui-là fait {STR_VAR_2} de long.\p"
	.string "Rien à voir avec celui de {STR_VAR_3}\n"
	.string "que tu avais ramené.$"

Route12_FishingHouse_Text_DoesntLookLikeMagikarp::
	.string "Hmmm…\p"
	.string "Ça ressemble pas à\n"
	.string "un MAGICARPE.$"

Route12_FishingHouse_Text_NoRoomForGift::
	.string "Ah ben non!\p"
	.string "J'avais un cadeau pour toi, mais\n"
	.string "t'as plus de place!$"

Route12_FishingHouse_Text_MostGiganticMagikarpXSize::
	.string "Le plus gros MAGICARPE que\n"
	.string "j'ai vu!\p"
	.string "{STR_VAR_3}!$"

Route12_FishingHouse_Text_BlankChartOfSomeSort::
	.string "C'est un classement vierge.\p"
	.string "Il y a de la place pour inscrire\n"
	.string "des records.$"


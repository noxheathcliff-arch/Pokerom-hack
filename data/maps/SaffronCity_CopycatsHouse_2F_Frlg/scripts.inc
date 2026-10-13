SaffronCity_CopycatsHouse_2F_Frlg_MapScripts::
	.byte 0

SaffronCity_CopycatsHouse_2F_EventScript_Doduo::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DODUO, CRY_MODE_NORMAL
	msgbox SaffronCity_CopycatsHouse_2F_Text_Doduo
	waitmoncry
	release
	end

SaffronCity_CopycatsHouse_2F_EventScript_Doll::
	lock
	msgbox SaffronCity_CopycatsHouse_2F_Text_RareMonOnlyDoll
	release
	end

SaffronCity_CopycatsHouse_2F_EventScript_Copycat::
	lock
	faceplayer
	checkitem ITEM_POKE_DOLL
	goto_if_eq VAR_RESULT, TRUE, EventScript_MimicTutor
	checkplayergender
	call_if_eq VAR_RESULT, MALE, SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerMale
	call_if_eq VAR_RESULT, FEMALE, SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerFemale
	release
	end

SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerMale::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyMale
	return

SaffronCity_CopycatsHouse_2F_EventScript_MimicPlayerFemale::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyFemale
	return

SaffronCity_CopycatsHouse_2F_EventScript_Computer::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MySecrets, MSGBOX_SIGN
	end

SaffronCity_CopycatsHouse_2F_EventScript_Game::
	msgbox SaffronCity_CopycatsHouse_2F_Text_MarioWearingABucket, MSGBOX_SIGN
	end

SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyMale::
	.string "{PLAYER}: Salut!\n"
	.string "Tu aimes les POKéMON?\p"
	.string "{PLAYER}: Heu, non\n"
	.string "Je demandais juste!\p"
	.string "{PLAYER}: Hein?\n"
	.string "T'es bizarre toi!\p"
	.string "COPIEUSE: Hmm?\n"
	.string "Arrêter de mimer?\p"
	.string "Mais je ne sais faire que ça!$"

SaffronCity_CopycatsHouse_2F_Text_MimickingFavoriteHobbyFemale::
	.string "{PLAYER}: Salut! Tu dois aimer\n"
	.string "les POKéMON, non?\p"
	.string "{PLAYER}: Heu, non\n"
	.string "Je demandais juste!\p"
	.string "{PLAYER}: Hein?\n"
	.string "T'es bizarre toi!\p"
	.string "COPIEUSE: Hmm?\n"
	.string "Arrêter de mimer?\p"
	.string "Mais je ne sais faire que ça!$"

Text_MimicTeach::
	.string "Whaaaaaa!\n"
	.string "Une POKéPOUPEE!\p"
	.string "C'est pour moi?\n"
	.string "Merci!\p"
	.string "Tiens, prends ça en échange!$"

Text_MimicDeclined::
	.string "T'aimes pas COPIE?$"

Text_MimicWhichMon::
	.string "Moi aussi j'adore! Alors, qui\n"
	.string "va l'apprendre?$"

Text_MimicTaughtMale::
	.string "{PLAYER}: Salut!\n"
	.string "Merci pour la CT31!\p"
	.string "{PLAYER}: Pardon?\p"
	.string "{PLAYER}: Heu…\n"
	.string "C'est aussi cool que ça de\l"
	.string "m'imiter?\p"
	.string "COPIEUSE: Ah non! C'est vraiment la\n"
	.string "galère, t'arrêtes pas d'bouger!$"

Text_MimicTaughtFemale::
	.string "{PLAYER}: Salut!\n"
	.string "Merci pour la CT31!\p"
	.string "{PLAYER}: Pardon?\p"
	.string "{PLAYER}: Heu…\n"
	.string "C'est aussi marrant que ça de\l"
	.string "m'imiter?\p"
	.string "COPIEUSE: Ah non! C'est vraiment la\n"
	.string "galère, t'arrêtes pas d'bouger!$"

SaffronCity_CopycatsHouse_2F_Text_Doduo::
	.string "DODUO: Doduuu!\p"
	.string "JOLI MIROIR, DIS-MOI QUI EST\n"
	.string "LA PLUS BELLE!$"

SaffronCity_CopycatsHouse_2F_Text_RareMonOnlyDoll::
	.string "Ça, un POKéMON rare? Tu t'moques\n"
	.string "de moi! C'est rien qu'une poupée!$"

SaffronCity_CopycatsHouse_2F_Text_MarioWearingABucket::
	.string "Un plombier? Mais…\n"
	.string "Ça a l'air sympa.$"

SaffronCity_CopycatsHouse_2F_Text_MySecrets::
	.string "…\p"
	.string "Mes secrets!\p"
	.string "Mon boulot: je mime!\n"
	.string "Ma passion: les poupées!\l"
	.string "Mon POKéMON préféré: MELOFEE!$"


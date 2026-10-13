SaffronCity_House_Frlg_MapScripts::
	.byte 0

SaffronCity_House_EventScript_Lass::
	msgbox SaffronCity_House_Text_DontLookAtMyLetter, MSGBOX_NPC
	end

SaffronCity_House_EventScript_Youngster::
	msgbox SaffronCity_House_Text_GettingCopycatPokeDoll, MSGBOX_NPC
	end

SaffronCity_House_EventScript_Pidgey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEY, CRY_MODE_NORMAL
	msgbox SaffronCity_House_Text_Pidgey
	waitmoncry
	release
	end

SaffronCity_House_EventScript_Letter::
	msgbox SaffronCity_House_Text_ExplainPPUp, MSGBOX_SIGN
	end

SaffronCity_House_Text_DontLookAtMyLetter::
	.string "Merci pour cette belle lettre, à\n"
	.string "bientôt!\p"
	.string "Hé! R'garde pas c'que j'écris!\n"
	.string "J'suis amoureuse!$"

SaffronCity_House_Text_Pidgey::
	.string "ROUCOOL: Rourou!$"

SaffronCity_House_Text_GettingCopycatPokeDoll::
	.string "La COPIEUSE est mignonne! Je vais\n"
	.string "lui offrir une POKéPOUPEE!$"

SaffronCity_House_Text_ExplainPPUp::
	.string "J'ai reçu comme récompense\n"
	.string "un PP PLUS.\p"
	.string "Il sert à augmenter les PP d'une\n"
	.string "attaque d'un POKéMON.\p"
	.string "Je devrais choisir une attaque\n"
	.string "avec peu de PP.$"


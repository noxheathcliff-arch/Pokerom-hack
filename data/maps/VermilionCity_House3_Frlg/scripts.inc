VermilionCity_House3_Frlg_MapScripts::
	.byte 0

VermilionCity_House3_EventScript_Boy::
	msgbox VermilionCity_House3_Text_PidgeyFlyLetterToSaffron, MSGBOX_NPC
	end

VermilionCity_House3_EventScript_Lass::
	msgbox VermilionCity_House3_Text_SendMyPidgeyToUnionRoom, MSGBOX_NPC
	end

VermilionCity_House3_EventScript_Pidgey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEY, CRY_MODE_NORMAL
	msgbox VermilionCity_House3_Text_Pidgey
	waitmoncry
	release
	end

VermilionCity_House3_EventScript_Letter::
	msgbox VermilionCity_House3_Text_DearPippiLetter, MSGBOX_SIGN
	end

VermilionCity_House3_Text_PidgeyFlyLetterToSaffron::
	.string "Mon ROUCOOL va apporter une\n"
	.string "lettre jusqu'à SAFRANIA au Nord!$"

VermilionCity_House3_Text_Pidgey::
	.string "ROUCOOL: Rourou!$"

VermilionCity_House3_Text_DearPippiLetter::
	.string "Cher JULIO,\n"
	.string "j'espère te voir très bientôt.\p"
	.string "On raconte que SAFRANIA a des\n"
	.string "problèmes avec la TEAM ROCKET.\p"
	.string "CARMIN SUR MER est toujours\n"
	.string "aussi paisible.$"

VermilionCity_House3_Text_SendMyPidgeyToUnionRoom::
	.string "Je veux échanger des LETTRES\n"
	.string "avec plein de gens.\p"
	.string "J'ai envoyé mon ROUCOOL à\n"
	.string "la SALLE UNION pour qu'il\p"
	.string "s'occupe de ma correspondance.$"


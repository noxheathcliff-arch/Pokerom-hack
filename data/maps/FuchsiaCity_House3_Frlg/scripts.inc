FuchsiaCity_House3_Frlg_MapScripts::
	.byte 0

FuchsiaCity_House3_EventScript_MoveDeleter::
	lock
	faceplayer
	msgbox FuchsiaCity_House3_Text_WouldYouLikeToForgetMove, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_House3_EventScript_ChooseMonForMoveDeleter
	goto FuchsiaCity_House3_EventScript_CancelForgetMove
	end

FuchsiaCity_House3_EventScript_ChooseMonForMoveDeleter::
	msgbox FuchsiaCity_House3_Text_WhichMonShouldForgetMove
	special ChoosePartyMon
	goto_if_ge VAR_0x8004, PARTY_SIZE, FuchsiaCity_House3_EventScript_CancelForgetMove
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, FuchsiaCity_House3_EventScript_CantForgetMoveEgg
	special GetNumMovesSelectedMonHas
	goto_if_eq VAR_RESULT, 1, FuchsiaCity_House3_EventScript_CantForgetOnlyMove
	msgbox FuchsiaCity_House3_Text_WhichMoveShouldBeForgotten
	fadescreen FADE_TO_BLACK
	special MoveDeleterChooseMoveToForget
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, FuchsiaCity_House3_EventScript_ChooseMonForMoveDeleter
	special BufferMoveDeleterNicknameAndMove
	msgbox FuchsiaCity_House3_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_House3_EventScript_ForgetMove
	goto FuchsiaCity_House3_EventScript_CancelForgetMove
	end

FuchsiaCity_House3_EventScript_ForgetMove::
	special MoveDeleterForgetMove
	playfanfare MUS_MOVE_DELETED
	waitfanfare
	msgbox FuchsiaCity_House3_Text_MonHasForgottenMoveCompletely
	release
	end

FuchsiaCity_House3_EventScript_CantForgetOnlyMove::
	special BufferMoveDeleterNicknameAndMove
	msgbox FuchsiaCity_House3_Text_MonOnlyKnowsOneMove
	release
	end

FuchsiaCity_House3_EventScript_CantForgetMoveEgg::
	msgbox FuchsiaCity_House3_Text_NoEggShouldKnowMoves
	release
	end

FuchsiaCity_House3_EventScript_CancelForgetMove::
	msgbox FuchsiaCity_House3_Text_ComeAgainToForgetOtherMoves
	release
	end

FuchsiaCity_House3_Text_WouldYouLikeToForgetMove::
	.string "Hum… Ah, oui, je suis l'EFFACEUR\n"
	.string "DE CAPACITES.\p"
	.string "Je fais oublier leurs capacités aux\n"
	.string "POKéMON.\p"
	.string "Tu veux que je le fasse?$"

FuchsiaCity_House3_Text_WhichMonShouldForgetMove::
	.string "Quel POKéMON doit oublier une\n"
	.string "capacité?$"

FuchsiaCity_House3_Text_WhichMoveShouldBeForgotten::
	.string "Quelle capacité doit être oubliée?$"

FuchsiaCity_House3_Text_MonOnlyKnowsOneMove::
	.string "Apparemment, {STR_VAR_1} ne connaît\n"
	.string "qu'une seule capacité…$"

FuchsiaCity_House3_Text_MonsMoveShouldBeForgotten::
	.string "Hum! {STR_VAR_2} de {STR_VAR_1}?\n"
	.string "Cette capacité doit être oubliée?$"

FuchsiaCity_House3_Text_MonHasForgottenMoveCompletely::
	.string "Ça a marché à la perfection!\p"
	.string "{STR_VAR_1} a complètement oublié\n"
	.string "{STR_VAR_2}.$"

FuchsiaCity_House3_Text_ComeAgainToForgetOtherMoves::
	.string "Reviens me voir si tu veux que tes\n"
	.string "POKéMON oublient des capacités.$"

FuchsiaCity_House3_Text_NoEggShouldKnowMoves::
	.string "Quoi? Les OEUFS ne connaissent\n"
	.string "pas de capacité.$"


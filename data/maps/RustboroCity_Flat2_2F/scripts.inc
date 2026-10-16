RustboroCity_Flat2_2F_MapScripts::
	.byte 0

RustboroCity_Flat2_2F_EventScript_OldMan::
	msgbox RustboroCity_Flat2_2F_Text_DevonWasTinyInOldDays, MSGBOX_NPC
	end

RustboroCity_Flat2_2F_EventScript_NinjaBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_PREMIER_BALL_RUSTBORO, RustboroCity_Flat2_2F_EventScript_GavePremierBall
	msgbox RustboroCity_Flat2_2F_Text_MyDaddyMadeThisYouCanHaveIt, MSGBOX_DEFAULT
	giveitem ITEM_PREMIER_BALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_PREMIER_BALL_RUSTBORO
	release
	end

RustboroCity_Flat2_2F_EventScript_GavePremierBall::
	msgbox RustboroCity_Flat2_2F_Text_GoingToWorkAtDevonToo, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat2_2F_Text_DevonWasTinyInOldDays:
	.string "Devon, je l’ai vu naître. Un petit\n"
	.string "atelier, trois machines.\p"
	.string "Ils fabriquaient des Poké Balls\n"
	.string "pour les gamins du quartier.\p"
	.string "Aujourd’hui, ils relient le monde.\n"
	.string "Et le monde nous tombe dessus.$"

RustboroCity_Flat2_2F_Text_MyDaddyMadeThisYouCanHaveIt:
	.string "Mon papa travaille chez Devon!\n"
	.string "Il a fait ça avec ses mains.\p"
	.string "Je m’en sers pas. Tiens!\n"
	.string "Mais le dis pas à la brigade, hein!$"

RustboroCity_Flat2_2F_Text_GoingToWorkAtDevonToo:
	.string "Mon papa travaille sur la Passerelle!\n"
	.string "Plus tard, moi aussi.\p"
	.string "Mais il dit que je dois\n"
	.string "pas le dire aux inconnus.$"


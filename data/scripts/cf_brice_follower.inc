@ Hack: talking to Brice while he follows Red (NPC follower, prologue end -> chapter 1).
@ Wired as the follower's script by both createfollowernpc calls (cf_prologue.inc, cf_chapter1.inc).

CF_Brice_FollowerTalk::
	lock
	faceplayer
	setspeaker CF_N1_Brice
	msgbox CF_Brice_T_HealAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CF_Brice_FollowerNo
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	fadescreen FADE_FROM_BLACK
	setspeaker CF_N1_Brice
	msgbox CF_Brice_T_HealDone, MSGBOX_DEFAULT
	release
	end

CF_Brice_FollowerNo::
	msgbox CF_Brice_T_HealNo, MSGBOX_DEFAULT
	release
	end

CF_Brice_T_HealAsk::
	.string "Tes Pokémon ont l’air crevés.\n"
	.string "On souffle un peu ?$"

CF_Brice_T_HealDone::
	.string "Et voilà, tout le monde est en\n"
	.string "forme. On y retourne ?$"

CF_Brice_T_HealNo::
	.string "Ça marche. Dis-moi si ça change.$"

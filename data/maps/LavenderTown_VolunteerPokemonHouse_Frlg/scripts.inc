LavenderTown_VolunteerPokemonHouse_Frlg_MapScripts::
	.byte 0

LavenderTown_VolunteerPokemonHouse_EventScript_MrFuji::
	lock
	faceplayer
	goto_if_set FLAG_GOT_POKE_FLUTE, LavenderTown_VolunteerPokemonHouse_EventScript_AlreadyHavePokeFlute
	msgbox LavenderTown_VolunteerPokemonHouse_Text_IdLikeYouToHaveThis
	checkitemspace ITEM_POKE_FLUTE
	goto_if_eq VAR_RESULT, FALSE, LavenderTown_VolunteerPokemonHouse_EventScript_NoRoomForPokeFlute
	setflag FLAG_GOT_POKE_FLUTE
	giveitem_msg LavenderTown_VolunteerPokemonHouse_Text_ReceivedPokeFluteFromMrFuji, ITEM_POKE_FLUTE, 1, MUS_RG_OBTAIN_KEY_ITEM
	msgbox LavenderTown_VolunteerPokemonHouse_Text_ExplainPokeFlute
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_AlreadyHavePokeFlute::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_HasPokeFluteHelpedYou
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_NoRoomForPokeFlute::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MustMakeRoomForThis
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_LittleGirl::
	lock
	faceplayer
	famechecker FAMECHECKER_MRFUJI, 0
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MrFujiLooksAfterOrphanedMons
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_LittleBoy::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MonsNiceToHug, MSGBOX_NPC
	end

LavenderTown_VolunteerPokemonHouse_EventScript_Youngster::
	lock
	faceplayer
	goto_if_set FLAG_RESCUED_MR_FUJI, LavenderTown_VolunteerPokemonHouse_EventScript_YoungsterFujiBack
	msgbox LavenderTown_VolunteerPokemonHouse_Text_WhereDidMrFujiGo
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_YoungsterFujiBack::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_MrFujiWasPrayingForCubonesMother
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_Nidorino::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_NIDORINO, CRY_MODE_NORMAL
	msgbox LavenderTown_VolunteerPokemonHouse_Text_Nidorino
	waitmoncry
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_Psyduck::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PSYDUCK, CRY_MODE_NORMAL
	msgbox LavenderTown_VolunteerPokemonHouse_Text_Psyduck
	waitmoncry
	release
	end

LavenderTown_VolunteerPokemonHouse_EventScript_PokemonFanMagazine::
	lockall
	famechecker FAMECHECKER_MRFUJI, 2
	msgbox LavenderTown_VolunteerPokemonHouse_Text_GrandPrizeDrawingClipped
	releaseall
	end

LavenderTown_VolunteerPokemonHouse_EventScript_Bookshelf::
	msgbox LavenderTown_VolunteerPokemonHouse_Text_PokemonMagazinesLineShelf, MSGBOX_SIGN
	end

LavenderTown_PokemonCenter_1F_Text_HearMrFujiNotFromAroundHere::
	.string "Je viens d'emménager ici.\p"
	.string "Il paraît que MR. FUJI n'est\n"
	.string "pas non plus du coin.$"

LavenderTown_VolunteerPokemonHouse_Text_WhereDidMrFujiGo::
	.string "Ce sacré MR. FUJI n'est pas là.\n"
	.string "Où est-il?$"

LavenderTown_VolunteerPokemonHouse_Text_MrFujiWasPrayingForCubonesMother::
	.string "MR. FUJI a prié pour le repos de\n"
	.string "la mère d'OSSELAIT.$"

LavenderTown_VolunteerPokemonHouse_Text_MrFujiLooksAfterOrphanedMons::
	.string "Voici la maison de MR. FUJI.\p"
	.string "C'est vraiment un chic type!\p"
	.string "Il est à la recherche des POKéMON\n"
	.string "orphelins et abandonnés!$"

LavenderTown_VolunteerPokemonHouse_Text_MonsNiceToHug::
	.string "C'est si doux! Faire un câlin à un\n"
	.string "POKéMON, c'est chou!$"

LavenderTown_VolunteerPokemonHouse_Text_Nidorino::
	.string "NIDORINO: Nido!$"

LavenderTown_VolunteerPokemonHouse_Text_Psyduck::
	.string "PSYKOKWAK: Kwak!$"

LavenderTown_VolunteerPokemonHouse_Text_IdLikeYouToHaveThis::
	.string "MR. FUJI: {PLAYER}.\p"
	.string "Ta quête pour compléter ton\n"
	.string "POKéDEX échouera si tu n'aimes pas\l"
	.string "tes POKéMON.\p"
	.string "Je crois que ceci te sera utile.$"

LavenderTown_VolunteerPokemonHouse_Text_ReceivedPokeFluteFromMrFuji::
	.string "{PLAYER} obtient la\n"
	.string "POKéFLUTE!$"

LavenderTown_VolunteerPokemonHouse_Text_ExplainPokeFlute::
	.string "En jouant de la POKéFLUTE, les\n"
	.string "POKéMON endormis se réveilleront.\p"
	.string "Elle marche sur tous les POKéMON.$"

LavenderTown_VolunteerPokemonHouse_Text_MustMakeRoomForThis::
	.string "Ton inventaire est plein!$"

LavenderTown_VolunteerPokemonHouse_Text_HasPokeFluteHelpedYou::
	.string "MR. FUJI: Ma FLUTE t'a été utile?$"

LavenderTown_VolunteerPokemonHouse_Text_GrandPrizeDrawingClipped::
	.string "Grand concours de dessin du\n"
	.string "magazine des fans de POKéMON!\p"
	.string "Le formulaire d'inscription est…\p"
	.string "Il a disparu! Quelqu'un a déjà dû\n"
	.string "l'utiliser.$"

LavenderTown_VolunteerPokemonHouse_Text_PokemonMagazinesLineShelf::
	.string "Des magazines POKéMON!\p"
	.string "Des cahiers POKéMON!\p"
	.string "Des dessins POKéMON!$"


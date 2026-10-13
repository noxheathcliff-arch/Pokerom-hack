EventScript_StartDexNavBattle::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER Common_Movement_ExclamationMark
	waitmovement 0
	waitse
	dowildbattle	
	release
	end

EventScript_NotFoundNearby::
	msgbox sText_NotFoundNearby, MSGBOX_SIGN
	end

EventScript_MovedTooFast::
	msgbox sText_TryMovingSlower, MSGBOX_SIGN
	end

EventScript_PokemonGotAway::
	msgbox sText_PokemonGotAway, MSGBOX_SIGN
	end

EventScript_LostSignal::
	msgbox sText_LostSignal, MSGBOX_SIGN
	end

EventScript_TooDark::
	msgbox sText_TooDark, MSGBOX_SIGN
	end

sText_NotFoundNearby:
    .string "Introuvable dans les environs.\n"
    .string "Cherche ailleurs !$"

sText_TryMovingSlower:
    .string "Le Pokémon s'est enfui !\n"
    .string "Déplace-toi plus lentement.$"

sText_PokemonGotAway:
    .string "Le Pokémon s'est enfui !$"

sText_LostSignal:
    .string "Aucune réaction.\n"
    .string "Le signal est perdu !$"

sText_TooDark:
    .string "Il fait trop sombre pour\n"
    .string "chercher un Pokémon !$"

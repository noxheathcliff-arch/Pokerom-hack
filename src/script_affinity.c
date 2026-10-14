// Hack: helpers for hidden relationship / reputation counters stored in saved vars.
// Script macros: addaffinity / subaffinity (asm/macros/event.inc). Threshold checks use the
// existing goto_if_ge / goto_if_lt / call_if_ge commands. See docs/hack/ENGINE_CHANGES.md.
#include "global.h"
#include "event_data.h"
#include "script.h"
#include "script_affinity.h"

u16 AddAffinityClamped(u16 varId, s32 delta, u16 min, u16 max)
{
    s32 value = (s32)VarGet(varId) + delta;

    if (value < min)
        value = min;
    if (value > max)
        value = max;
    VarSet(varId, value);
    return value;
}

// addaffinity VAR, delta, min, max: VAR = clamp(VAR + delta, min, max); VAR_RESULT = new value.
void Script_AddAffinity(struct ScriptContext *ctx)
{
    u16 varId = ScriptReadHalfword(ctx);
    s16 delta = (s16)ScriptReadHalfword(ctx);
    u16 min = ScriptReadHalfword(ctx);
    u16 max = ScriptReadHalfword(ctx);

    Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE);
    Script_RequestWriteVar(varId);
    Script_RequestWriteVar(VAR_RESULT);

    gSpecialVar_Result = AddAffinityClamped(varId, delta, min, max);
}

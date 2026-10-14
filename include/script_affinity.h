#ifndef GUARD_SCRIPT_AFFINITY_H
#define GUARD_SCRIPT_AFFINITY_H

u16 AddAffinityClamped(u16 varId, s32 delta, u16 min, u16 max);
void Script_AddAffinity(struct ScriptContext *ctx);

#endif // GUARD_SCRIPT_AFFINITY_H

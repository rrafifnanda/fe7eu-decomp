#include "gbafe.h"

u32 GetUnitEfxDebuff(struct Anim *anim) {
    return gpProcEfxStatusUnits[GetAnimPosition(anim)]->debuff;
}

#include "gbafe.h"

void EkrPrepareBanimfx(struct Anim *anim, u16 index) {
    gBanimIdx[GetAnimPosition(anim)] = (s16) index;
    UpdateBanimFrame();
    SwitchAISFrameDataFromBARoundType(anim, 6);
}

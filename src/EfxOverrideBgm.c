#include "gbafe.h"

void EfxOverrideBgm(s32 arg0, s32 arg1) {
    if (!(0x20 & gBmSt.flags)) {
        SetBgmVolume(arg1);
        OverrideBgm(arg0);
    }
}

#include "gbafe.h"

void PlaySFX(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    EfxPlaySE(arg0, arg1);
    M4aPlayWithPostionCtrl(arg0, arg2, arg3);
}

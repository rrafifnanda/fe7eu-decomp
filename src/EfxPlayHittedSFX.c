#include "gbafe.h"

void EfxPlayHittedSFX(struct Anim *arg0) {
    s16 temp_r0;
    s16 temp_r4;
    s16 var_r4;

    var_r4 = -1;
    EfxPlayCriticalHittedSFX();
    temp_r0 = sub_80684B0(arg0);
    switch (temp_r0) {                              /* irregular */
    case 0:
        var_r4 = 0xD4;
        break;
    case 1:
        var_r4 = 0xD5;
        break;
    case 2:
        var_r4 = 0x2CE;
        break;
    }
    temp_r4 = var_r4;
    if (temp_r4 != -1) {
        EfxPlaySE((s32) temp_r4, 0x100);
        M4aPlayWithPostionCtrl(temp_r4, arg0->xPosition, 1);
    }
}

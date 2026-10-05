#include "gbafe.h"

void sub_80963FC(void) {
    s32 var_r4;
    s32 var_r5;
    s32 var_r6;

    var_r6 = 0xDFC0;
    var_r5 = 0x30;
    var_r4 = 3;
    do {
        PutSpriteExt(4, var_r5, 0x10, Sprite_32x16, var_r6);
        var_r6 += 4;
        var_r5 += 0x20;
        var_r4 -= 1;
    } while (var_r4 >= 0);
}

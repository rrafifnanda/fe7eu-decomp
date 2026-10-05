#include "gbafe.h"

s32 (*sub_8004E4C(s32, void *))();                       /* extern */
extern s32 gUnk_080C0C50;
extern s32 gUnk_080C0C6C;

void PutBuildInfo(s32 arg0, s32 arg4) {
    void *spC;
    s32 sp14;

    spC = &arg4;
    sp14 = 0;
    sub_8004E4C(arg0, &gUnk_080C0C50);
    sub_8004E4C(arg0 - 0x40, &gUnk_080C0C6C)();
}

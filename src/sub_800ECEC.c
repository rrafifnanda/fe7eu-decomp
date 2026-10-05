#include "gbafe.h"

extern s32 gUnk_08C00D44;

void sub_800ECEC(u16 arg0, s32 arg1) {
    sub_800ACD0(arg0);
    sub_800ACE8(&gUnk_08C00D44, 0x60, 0, arg1);
}

#include "gbafe.h"

extern s32 gUnk_084295B4;
extern s32 gUnk_08429638;

void sub_80922DC(s32 arg0, s32 arg1) {
    Decompress(&gUnk_084295B4, arg0 + 0x06010000);
    ApplyPaletteExt(&gUnk_08429638, (arg1 + 0x10) << 5, 0x20);
}

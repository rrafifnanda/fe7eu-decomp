#include "gbafe.h"

extern s32 Img_0841E49C;
extern s32 Img_0841E634;
extern s32 gUnk_0841E7F4;

void StoreConvoyWeaponIconGraphics(s32 arg0, s32 arg1) {
    ApplyPaletteExt(&gUnk_0841E7F4, arg1 << 5, 0x20);
    Decompress(&Img_0841E49C, arg0 + 0x06000000);
    Decompress(&Img_0841E634, arg0 + 0x06000200);
}

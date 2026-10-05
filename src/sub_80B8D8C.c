#include "gbafe.h"

extern u8 gUnk_08615A4C;
extern s32 gUnk_08615F00;
extern s32 gUnk_08615F40;
extern u8 gUnk_086167D0;
extern u8 gUnk_0861684C;

void sub_80B8D8C(void) {
    ApplyPaletteExt(&gUnk_08615F40, 0x180, 0x40);
    ApplyPaletteExt(&gUnk_08615F00, 0x1C0, 0x40);
    TmApplyTsa_thm(gBg3Tm, &gUnk_08615A4C, 0xE000U);
    TmApplyTsa_thm(gBg2Tm, &gUnk_086167D0, 0xC280U);
    TmApplyTsa_thm(&gBg2Tm[0x240], &gUnk_0861684C, 0xC280U);
    EnableBgSync(0xC);
}

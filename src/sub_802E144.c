#include "gbafe.h"

extern s32 gUnk_0819514C;
extern s32 gUnk_08195668;

void sub_802E144(void) {
    AllocWeatherParticles(0);
    Decompress(&gUnk_0819514C, (void *)0x020027DC);
    ApplyPaletteExt(&gUnk_08195668, 0x340, 0x20);
}

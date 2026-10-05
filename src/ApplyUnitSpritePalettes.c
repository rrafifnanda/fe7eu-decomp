#include "gbafe.h"

extern s32 Pal_UnitSprites;
extern s32 Pal_UnitSpritesPurple;
extern s32 gUnk_08190188;

void ApplyUnitSpritePalettes(void) {
    ApplyPaletteExt(&Pal_UnitSprites, 0x380, 0x80);
    if (0x40 & gBmSt.flags) {
        ApplyPaletteExt(&Pal_UnitSpritesPurple, 0x360, 0x20);
        return;
    }
    ApplyPaletteExt(&gUnk_08190188, 0x360, 0x20);
}

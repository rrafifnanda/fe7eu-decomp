#include "gbafe.h"

extern s32 gUnk_081DD7F4;
extern s32 gUnk_081DDA48;

void sub_804A930(void *arg0, s32 arg1, s32 arg2) {
    Decompress(&gUnk_081DD7F4, arg0);
    ApplyPaletteExt(&gUnk_081DDA48, arg1 << 5, arg2 << 5);
}

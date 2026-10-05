#include "gbafe.h"

extern u16 gUnk_08C01D0C;

void StartPalFadeToWhite(s32 palid, s32 duration, void *parent) {
    StartPalFade(&gUnk_08C01D0C, palid, duration, parent);
}

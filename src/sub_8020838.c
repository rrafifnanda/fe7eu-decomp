#include "gbafe.h"

void sub_8020838(void) {
    ColorFadeInit();
    sub_80020CC(gPal, 0, 1, -1);
    sub_80020CC(&gPal[0x40], 4, 1, -1);
    FadeBgmOut(4);
}

#include "gbafe.h"

extern s32 gEfxBgSemaphore;

void sub_806137C(void) {
    SpellFx_ClearBG1();
    gEfxBgSemaphore -= 1;
    SpellFx_ClearColorEffects();
}

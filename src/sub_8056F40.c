#include "gbafe.h"

extern s32 gEfxBgSemaphore;

void sub_8056F40(void) {
    gEfxBgSemaphore -= 1;
}

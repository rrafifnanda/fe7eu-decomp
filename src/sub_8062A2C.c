#include "gbafe.h"

extern s32 gEfxBgSemaphore;

void sub_8062A2C(void) {
    gEfxBgSemaphore -= 1;
}

#include "gbafe.h"

extern s32 gEfxBgSemaphore;

void sub_805EBF8(void) {
    gEfxBgSemaphore -= 1;
}

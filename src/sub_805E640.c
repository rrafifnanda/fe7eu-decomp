#include "gbafe.h"

extern s32 gEfxBgSemaphore;

void sub_805E640(void) {
    gEfxBgSemaphore -= 1;
}

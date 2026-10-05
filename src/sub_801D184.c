#include "gbafe.h"

s32 sub_804B2DC(void *, s32, s32, s32);                  /* extern */
extern s32 gUnk_08C04D68;

void sub_801D184(void *arg0) {
    if (gActionSt.id != 0x1B) {
        sub_804B2DC(&gUnk_08C04D68, gBmSt.cursor_sprite_target.x - gBmSt.camera.x, 1, 0x16);
    }
    Proc_Break(arg0);
}

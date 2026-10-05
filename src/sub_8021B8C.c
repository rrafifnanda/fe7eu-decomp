#include "gbafe.h"

s32 sub_804B2DC(void *, s32, s32, s32);                  /* extern */
extern s32 gUnk_08C04D68;

void sub_8021B8C(void) {
    sub_804B2DC(&gUnk_08C04D68, gBmSt.cursor_sprite_target.x - gBmSt.camera.x, 1, 0x16);
}

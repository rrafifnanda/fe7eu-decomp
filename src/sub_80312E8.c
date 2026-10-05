#include "gbafe.h"

void sub_80312E8(void *arg0) {
    SetMapCursorPosition((s32) gActiveUnit->xPos, (s32) (s8) (u8) gActiveUnit->yPos);
    EnsureCameraOntoPosition(arg0, (s32) gActiveUnit->xPos, (s32) gActiveUnit->yPos);
}
/* Warning: struct SMSHandle is not defined (only forward-declared) */

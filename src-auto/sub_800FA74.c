#include "gbafe.h"

s32 SetkeyStIgnoredMask(s32);                         /* extern */

void sub_800FA74(void *arg0) {
    SetkeyStIgnoredMask(arg0->unk30->unk4);
}

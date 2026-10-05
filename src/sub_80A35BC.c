#include "gbafe.h"

void sub_80A35BC(void) {
    s32 temp_r3;

    temp_r3 = *(s32 *)0x02000500;
    *(s32 *)0x02000500 = *(s32 *)0x02000504;
    *(s32 *)0x02000504 = temp_r3;
}

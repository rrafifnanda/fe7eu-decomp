#include "gbafe.h"

void sub_807F16C(s32 arg0, s32 arg1) {
    struct Unit *temp_r0;
    u32 temp_r1;

    temp_r0 = GetUnitFromCharId(arg1);
    temp_r1 = temp_r0->state;
    if (!(0xC & temp_r1)) {
        sub_8012440(arg0, 0);
        return;
    }
    temp_r0->state = temp_r1 | 9;
}
/* Warning: struct SMSHandle is not defined (only forward-declared) */

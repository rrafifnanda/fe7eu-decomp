#include "gbafe.h"

void sub_803EB44(s32 *arg0, u8 arg1, u8 arg2, u8 arg3) {
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r0_4;
    u16 temp_r2;
    u16 temp_r3;
    u8 temp_r6;

    temp_r6 = arg3;
    temp_r3 = gpKeySt->repeated;
    if ((0x40 & temp_r3) && ((temp_r0 = *arg0, (temp_r0 > (s32) arg2)) || (temp_r3 == gpKeySt->pressed))) {
        temp_r0_2 = temp_r0 - 1;
        *arg0 = temp_r0_2;
        if (temp_r0_2 < 0) {
            *arg0 = temp_r6 - 1;
        }
    }
    temp_r2 = gpKeySt->repeated;
    if ((0x80 & temp_r2) && ((temp_r0_3 = *arg0, (temp_r0_3 < (s32) arg1)) || (temp_r2 == gpKeySt->pressed))) {
        temp_r0_4 = temp_r0_3 + 1;
        *arg0 = temp_r0_4;
        *arg0 = temp_r0_4 % (s32) temp_r6;
    }
}

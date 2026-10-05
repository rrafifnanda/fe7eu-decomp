#include "gbafe.h"

s32 SetTalkFlag(s32);                                 /* extern */
s32 sub_8007F68(s32);                                 /* extern */
s32 sub_8007F84(s32);                                 /* extern */

void sub_8040CC8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    sub_8007DF4();
    sub_800968C();
    ResetTextFont();
    StartTalkExt(arg1, arg2, arg0, arg3);
    sub_8007F84(1);
    SetTalkFlag(1);
    SetTalkFlag(2);
    SetTalkFlag(4);
    sub_8007F68(2);
    sub_8008CB8(1);
}

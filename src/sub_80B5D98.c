#include "gbafe.h"

extern struct ProcCmd gUnk_08DB0F44;

void sub_80B5D98(s32 arg0, s32 arg1, s32 arg2) {
    sub_80B45DC(arg2, arg0, arg1, Proc_Find(&gUnk_08DB0F44));
}

#include "gbafe.h"

void sub_8093B5C(void *arg0, u32 arg1) {
    NewSysBlackBoxHandler(arg0);
    SysBlackBoxSetGfx(arg1);
    if ((CheckInLinkArena() << 0x18) == 0) {
        EnableSysBlackBox(0, 4, 0x480, 0xC, 4, 0xC00U);
    } else {
        EnableSysBlackBox(0, 4, 0x488, 0xC, 3, 0xC00U);
    }
    EnableSysBlackBox(1, 0x6C, 0x480, 0x10, 4, 0xC00U);
}

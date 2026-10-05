#include "gbafe.h"

s32 sub_8048494();                                    /* extern */

void sub_8040230(void) {
    if ((CheckInLinkArena() << 0x18) == 0) {
        sub_8048494();
    }
}

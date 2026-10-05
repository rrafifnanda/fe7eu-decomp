#include "gbafe.h"

s8 CheckInLinkArena(void) {
    return ((u8) gBmSt.flags >> 6) & 1;
}

#include "gbafe.h"

void sub_803E0D8(void) {
    SetBgOffset(0U, 0U, 0U);
    SetBgOffset(1U, 0U, 0U);
    SetBgOffset(2U, 0U, 0U);
    SetBgOffset(3U, 0U, 0U);
    TmFill(gBg0Tm, 0);
    TmFill(gBg1Tm, 0);
    TmFill(gBg2Tm, 0);
    TmFill(gBg3Tm, 0);
    EnableBgSync(0xF);
}

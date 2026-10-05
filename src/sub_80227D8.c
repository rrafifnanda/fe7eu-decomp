#include "gbafe.h"

void sub_80227D8(void) {
    InitTextFont((struct Font *)0x02002774, (void *)0x06004000, 0x200, 0);
    TmCopyRect_thm(&gBg0Tm[0x2B], gUiTmScratchA, 9, 0x13);
    TmCopyRect_thm(&gBg1Tm[0x2B], gUiTmScratchB, 9, 0x13);
}

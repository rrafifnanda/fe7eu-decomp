#include "gbafe.h"

s32 sub_806BF78();                                  /* extern */

void EkrRestoreBGM(void) {
    if ((sub_806BF78() == 1) || (0x20 & gBmSt.flags) || (*(s32 *)0x020200A0 == 0)) {
        MakeBgmOverridePersist();
        return;
    }
    RestoreBgm();
}

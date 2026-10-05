#include "gbafe.h"

void sub_804E9A8(void *arg0) {
    if (CheckEkrWindowAppearUnexist() == 1) {
        *(s32 *)0x02017738 = 0;
        Proc_Break(arg0);
    }
}

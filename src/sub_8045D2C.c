#include "gbafe.h"

s32 sub_803D268();                                  /* extern */

void sub_8045D2C(void *arg0) {
    if (sub_803D268() <= 7) {
        Proc_Break(arg0);
    }
}

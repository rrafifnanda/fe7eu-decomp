#include "gbafe.h"

s32 sub_804B08C(s32, s32 *, s32 *);                   /* extern */
s32 sub_804B334(s32, s32 *, s32 *);                   /* extern */
extern s32 gUnk_08C09BDC;

void sub_804B1C0(s32 arg0) {
    s32 sp0;
    s32 sp4;

    sub_804B08C(arg0, &sp0, &sp4);
    sub_804B334(arg0, &sp0, &sp4);
    DisplayFrozenUiHand(sp0, sp4);
    if (0x102 & gpKeySt->pressed) {
        CloseHelpBox();
        sub_8004634(arg0, &gUnk_08C09BDC);
    }
}

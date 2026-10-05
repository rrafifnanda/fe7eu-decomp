#include "gbafe.h"

s32 sub_802E220();                                    /* extern */
extern struct ProcCmd gUnk_08C05414;

void StartBmVSync(void) {
    Proc_Start(&gUnk_08C05414, NULL);
    BmVSync_AnimInit();
    sub_802E220();
    gBmSt.lock_display = 0;
}

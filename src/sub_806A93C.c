#include "gbafe.h"

extern struct ProcCmd gUnk_08C4AB40;

void sub_806A93C(void) {
    Proc_EndEach(&gUnk_08C4AB40);
    *(s32 *)0x02020130 = 1;
}

#include "gbafe.h"

extern struct ProcCmd ProcScr_PrepMenu;

void sub_8090AC0(void) {
    void *temp_r0;

    temp_r0 = Proc_Find(&ProcScr_PrepMenu);
    if (temp_r0 != NULL) {
        Proc_Goto(temp_r0, 0);
    }
}

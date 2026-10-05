#include "gbafe.h"

extern struct ProcCmd ProcScr_menu_scroll;

void LockMenuScrollBar(void) {
    void *temp_r0;

    temp_r0 = Proc_Find(&ProcScr_menu_scroll);
    if (temp_r0 != NULL) {
        Proc_Goto(temp_r0, 1);
    }
}

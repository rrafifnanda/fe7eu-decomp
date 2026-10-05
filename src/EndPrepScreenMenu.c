#include "gbafe.h"

extern struct ProcCmd ProcScr_PrepMenu;

void EndPrepScreenMenu(void) {
    void *temp_r0;

    temp_r0 = Proc_Find(&ProcScr_PrepMenu);
    if (temp_r0 != NULL) {
        sub_8090A1C();
        Proc_Goto(temp_r0, 0xA);
    }
}

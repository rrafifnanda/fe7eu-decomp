#include "gbafe.h"

extern struct ProcCmd ProcScr_AtMenu;

void sub_8041DFC(void *arg0) {
    if (Proc_Find(&ProcScr_AtMenu) == NULL) {
        Proc_Break(arg0);
    }
}

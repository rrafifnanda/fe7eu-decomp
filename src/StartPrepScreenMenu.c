#include "gbafe.h"

extern struct ProcCmd ProcScr_PrepMenu;

void StartPrepScreenMenu(void *arg0) {
    Proc_End(Proc_Find(&ProcScr_PrepMenu));
    Proc_Start(&ProcScr_PrepMenu, arg0);
}

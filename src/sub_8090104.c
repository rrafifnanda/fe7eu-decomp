#include "gbafe.h"

extern struct ProcCmd ProcScr_AtUnkMenu;

void sub_8090104(void) {
    Proc_Start(&ProcScr_AtUnkMenu, (void *)3);
}

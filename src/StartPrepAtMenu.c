#include "gbafe.h"

extern struct ProcCmd ProcScr_AtMenu;

void StartPrepAtMenu(void) {
    Proc_Start(&ProcScr_AtMenu, (void *)3);
}

#include "gbafe.h"

extern struct ProcCmd ProcScr_AtMenu;

void StartPrepAtMenuWithConfig(void) {
    Proc_Start(&ProcScr_AtMenu, (void *)3);
    RemoveSomeUnitItems();
    ResetSioPidPool();
}

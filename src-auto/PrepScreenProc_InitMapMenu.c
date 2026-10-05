#include "gbafe.h"

s32 PrepScreenProc_StartMapMenu();                    /* extern */

void PrepScreenProc_InitMapMenu(void *arg0) {
    arg0->unk58 = 1;
    PrepScreenProc_StartMapMenu();
}

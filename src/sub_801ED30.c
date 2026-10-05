#include "gbafe.h"

void sub_801ED30(void *arg0) {
    if (CountFactionMoveableUnits((s32) gPlaySt.faction) == 0) {
        Proc_End(arg0);
    }
}

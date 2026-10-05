#include "gbafe.h"

extern struct ProcCmd gUnk_08D8B5F4;

void EndCgText(void) {
    Proc_End(Proc_Find(&gUnk_08D8B5F4));
}

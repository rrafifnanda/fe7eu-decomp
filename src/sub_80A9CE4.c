#include "gbafe.h"

extern struct ProcCmd gUnk_08DAE22C;

void sub_80A9CE4(void) {
    Proc_End(Proc_Find(&gUnk_08DAE22C));
}

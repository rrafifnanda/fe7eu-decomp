#include "gbafe.h"

extern struct ProcCmd gUnk_08DB104C;

void sub_80B698C(void) {
    Proc_End(Proc_Find(&gUnk_08DB104C));
}

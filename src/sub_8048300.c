#include "gbafe.h"

extern struct ProcCmd gUnk_08C096DC;

void sub_8048300(void) {
    if (Proc_Find(&gUnk_08C096DC) != NULL) {
        Proc_EndEach(&gUnk_08C096DC);
    }
}

#include "gbafe.h"

extern struct ProcCmd gUnk_08BFFF30;

void sub_800ADAC(void *arg0) {
    Proc_StartBlocking(&gUnk_08BFFF30, arg0);
}

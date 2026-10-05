#include "gbafe.h"

extern struct ProcCmd gUnk_08C08F74;

void sub_8046424(void *arg0) {
    Proc_StartBlocking(&gUnk_08C08F74, arg0);
    Proc_Break(arg0);
}

#include "gbafe.h"

extern struct ProcCmd gUnk_08DADF98;

void StartTactBirthSelect(struct ProcTactInfo *proc) {
    Proc_StartBlocking(&gUnk_08DADF98, proc);
}

#include "gbafe.h"

extern struct ProcCmd ProcScr_BoxDialogue;
extern struct ProcCmd ProcScr_TalkBoxIdle;

void sub_8084CEC(void *arg0) {
    if (Proc_Find(&ProcScr_TalkBoxIdle) != NULL) {
        Proc_Goto(Proc_Find(&ProcScr_BoxDialogue), 0);
        Proc_Goto(arg0, 0);
    }
}

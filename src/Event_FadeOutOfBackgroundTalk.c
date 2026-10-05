#include "gbafe.h"

extern struct ProcCmd gUnk_08BFFEF8;

void Event_FadeOutOfBackgroundTalk(struct EventProc *proc) {
    Proc_StartBlocking(&gUnk_08BFFEF8, proc);
}

#include "gbafe.h"

void EventClearTalkDisplayed(struct EventProc *proc) {
    if ((s8) (u8) proc->unk_4D != 0) {
        ClearTalk();
        return;
    }
    if (Proc_Find(ProcScr_Face) != NULL) {
        sub_80095E4();
        Proc_ForEach(ProcScr_Face, (void (*)(void *)) StartFaceFadeOut);
        proc->sleep_duration = 8;
        sub_80149B4(proc, 8);
    }
}

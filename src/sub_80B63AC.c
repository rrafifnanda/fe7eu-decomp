#include "gbafe.h"

extern struct ProcCmd gUnk_08DB0F44;

void sub_80B63AC(void) {
    Proc_End(Proc_Find(ProcScr_BmFadeIN));
    Proc_End(Proc_Find(&gUnk_08DB0F44));
    ClearTalk();
    EndEachSpriteAnimProc();
    InitBgs(NULL);
}

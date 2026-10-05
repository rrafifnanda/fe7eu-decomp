#include "gbafe.h"

s32 NewEkrPopup();                                    /* extern */

void EkrBattleExecPopup(struct ProcEkrBattle *proc) {
    NewEkrPopup();
    proc->proc_idleCb = (void (*)(void *)) EkrBattleWaitPopup;
}

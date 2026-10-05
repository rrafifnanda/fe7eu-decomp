#include "gbafe.h"

void EkrBattleWaitDragonIntro(struct ProcEkrBattle *proc) {
    if (EkrDragonIntroDone(proc->anim) == 1) {
        proc->proc_idleCb = (void (*)(void *)) EkrBattleExecDragonIntro;
    }
}

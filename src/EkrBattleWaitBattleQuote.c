#include "gbafe.h"

void EkrBattleWaitBattleQuote(struct ProcEkrBattle *proc) {
    if ((IsEventRunning() << 0x18) == 0) {
        EfxPrepareScreenFx();
        EnableBgSync(1);
        NewEkrWindowAppear(0, 7);
        NewEkrNamewinAppear(0, 7, 0);
        DisableEkrGauge();
        UnAsyncEkrDispUP();
        EkrGauge_0804CC28();
        proc->proc_idleCb = (void (*)(void *)) EkrBattleWaitWindowAppear;
    }
}

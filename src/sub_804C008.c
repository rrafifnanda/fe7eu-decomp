#include "gbafe.h"

s8 sub_8068A0C();                                   /* extern */
extern s16 gEkrPairExpGain;

void sub_804C008(struct ProcEkrBattle *proc) {
    s8 temp_r4;

    temp_r4 = sub_8068A0C();
    if (temp_r4 == 1) {
        sub_8068A24();
        gEkrPairExpGain = (s16) temp_r4;
        proc->proc_idleCb = (void (*)(void *)) EkrBattleExecEkrLvup;
    }
}

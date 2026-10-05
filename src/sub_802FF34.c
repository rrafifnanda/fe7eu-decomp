#include "gbafe.h"

void sub_802FF34(void *arg0) {
    gBattleTarget.unit.maxHP = 1;
    gBattleTarget.unit.curHP = 1;
    if ((s8) (u8) gBattleActor.unit.curHP != 0) {
        Proc_Goto(arg0, 1);
    }
}
/* Warning: struct SMSHandle is not defined (only forward-declared) */

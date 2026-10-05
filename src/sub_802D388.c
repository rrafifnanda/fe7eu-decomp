#include "gbafe.h"

void sub_802D388(void *arg0) {
    BattleInitItemEffect(GetUnit((s32) gActionSt.instigator), gActionSt.item_slot);
    sub_802BF8C(gActionSt.x_target, gActionSt.y_target, 0xB, 0);
    BattleApplyItemEffect(arg0);
    gBattleTarget.statusOut = -1;
    StartMineAnim(arg0, (s32) gActionSt.x_target, (s32) gActionSt.y_target);
}
/* Warning: struct SMSHandle is not defined (only forward-declared) */

#include "gbafe.h"

s32 BeginBattleAnimations();                          /* extern */

void sub_802CEB8(s32 arg0) {
    struct Unit *temp_r5;

    BattleInitItemEffect(GetUnit((s32) gActionSt.instigator), gActionSt.item_slot);
    temp_r5 = GetUnit((s32) gActionSt.instigator);
    SetUnitHp(temp_r5, GetUnitMaxHp(GetUnit((s32) gActionSt.instigator)));
    gBattleHitIterator->hpChange = (u8) gBattleActor.unit.curHP - GetUnitCurrentHp(GetUnit((s32) gActionSt.instigator));
    gBattleActor.unit.curHP = (s8) GetUnitCurrentHp(GetUnit((s32) gActionSt.instigator));
    BattleApplyItemEffect(arg0);
    BeginBattleAnimations();
}
/* Warning: struct SMSHandle is not defined (only forward-declared) */

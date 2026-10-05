#include "gbafe.h"

s32 BeginBattleAnimations();                          /* extern */

void sub_802CE54(s32 arg0, s32 arg1) {
    BattleInitItemEffect(GetUnit((s32) gActionSt.instigator), gActionSt.item_slot);
    AddUnitHp(GetUnit((s32) gActionSt.instigator), arg1);
    gBattleHitIterator->hpChange = (u8) gBattleActor.unit.curHP - GetUnitCurrentHp(GetUnit((s32) gActionSt.instigator));
    gBattleActor.unit.curHP = (s8) GetUnitCurrentHp(GetUnit((s32) gActionSt.instigator));
    gBattleActor.weaponBefore = 0x6B;
    BattleApplyItemEffect(arg0);
    BeginBattleAnimations();
}
/* Warning: struct SMSHandle is not defined (only forward-declared) */

#include "gbafe.h"

void FinishDamageDisplay(void) {
    EndAllMus();
    if ((s8) (u8) gBattleActor.unit.curHP != 0) {
        ShowUnitSprite(GetUnit((s32) gActionSt.instigator));
    }
}
/* Warning: struct SMSHandle is not defined (only forward-declared) */

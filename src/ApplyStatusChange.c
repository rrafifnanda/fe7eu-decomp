#include "gbafe.h"

void ApplyStatusChange(void) {
    if ((s32) gBattleTarget.statusOut >= 0) {
        SetUnitStatus(GetUnit((s32) gActionSt.target), (s32) gBattleTarget.statusOut);
        gBattleTarget.statusOut = -1;
    }
}
/* Warning: struct SMSHandle is not defined (only forward-declared) */

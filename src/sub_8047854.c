#include "gbafe.h"

void sub_8047854(void) {
    struct Unit *temp_r4;
    struct Unit *temp_r5;

    temp_r4 = GetUnit((s32) (s8) (u8) gBattleActor.unit.index);
    temp_r5 = GetUnit((s32) (s8) (u8) gBattleTarget.unit.index);
    if (GetUnitCurrentHp(temp_r4) == 0) {
        temp_r4->state |= 5;
    }
    if (GetUnitCurrentHp(temp_r5) == 0) {
        temp_r5->state |= 5;
    }
}
/* Warning: struct SMSHandle is not defined (only forward-declared) */

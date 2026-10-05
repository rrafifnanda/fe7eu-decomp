#include "gbafe.h"

s32 PidStatsRecordDefeatInfo(u8, s32, s32);           /* extern */

void sub_802FD04(struct Unit *arg0) {
    if (GetUnitCurrentHp(arg0) == 0) {
        UnitKill(arg0);
        PidStatsRecordDefeatInfo(arg0->pCharacterData->number, 0, 6);
    }
}
/* Warning: struct SMSHandle is not defined (only forward-declared) */

#include "gbafe.h"

void *sub_8033FE8(s32);                             /* extern */

void InitBattleForecastFramePalettes(void) {
    ApplyPaletteExt(sub_8033FE8((s8) (u8) gBattleActor.unit.index & 0xC0), 0x20, 0x20);
    if (gBattleTarget.unit.index != 0) {
        ApplyPaletteExt(sub_8033FE8(gBattleTarget.unit.index & 0xC0), 0x40, 0x20);
        return;
    }
    ApplyPaletteExt(sub_8033FE8(0xC0), 0x40, 0x20);
}
/* Warning: struct SMSHandle is not defined (only forward-declared) */

#include "gbafe.h"

void sub_802C300(void) {
    s32 var_r5;
    struct Unit *temp_r0;
    u32 temp_r3;

    var_r5 = 1;
    do {
        temp_r0 = GetUnit(var_r5);
        if ((temp_r0 != NULL) && (temp_r0->pCharacterData != NULL)) {
            temp_r3 = temp_r0->state;
            if ((0x80 & temp_r3) && (gBmMapTerrain[temp_r0->yPos][temp_r0->xPos] != 0x22)) {
                temp_r0->state = (temp_r3 & ~0x81) | 0x100;
            }
        }
        var_r5 += 1;
    } while (var_r5 <= 0xBF);
    RefreshEntityMaps();
    RefreshUnitSprites();
}
/* Warning: struct SMSHandle is not defined (only forward-declared) */

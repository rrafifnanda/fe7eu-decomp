#include "gbafe.h"

void sub_807B304(void) {
    s32 var_r4;
    struct Unit *temp_r0;

    var_r4 = 0x81;
    do {
        temp_r0 = GetUnit(var_r4);
        if ((temp_r0 != NULL) && (temp_r0->pCharacterData != NULL)) {
            ClearUnit(temp_r0);
        }
        var_r4 += 1;
    } while (var_r4 <= 0xBF);
}
/* Warning: struct SMSHandle is not defined (only forward-declared) */

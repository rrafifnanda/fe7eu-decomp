#include "gbafe.h"

void ForceDisplayDragonSprite(void) {
    struct Unit *temp_r0;

    temp_r0 = GetUnitFromCharId(0x25);
    if (temp_r0 != NULL) {
        temp_r0->state &= 0xFFFEFFFF;
    }
}
/* Warning: struct SMSHandle is not defined (only forward-declared) */

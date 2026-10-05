#include "gbafe.h"

void EventCall_PutFallNinian(void) {
    struct Unit *temp_r0;

    temp_r0 = GetUnitFromCharId(0xDA);
    if (temp_r0 != NULL) {
        ShowUnitSprite(temp_r0);
        EndEachSpriteAnimProc();
    }
}
/* Warning: struct SMSHandle is not defined (only forward-declared) */

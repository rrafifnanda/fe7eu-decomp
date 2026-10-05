#include "gbafe.h"

s32 WriteCompletedPlaythroughSaveData();              /* extern */

void sub_802EBA0(void) {
    SetNextGameAction(2);
    WriteCompletedPlaythroughSaveData();
}

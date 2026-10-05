#include "gbafe.h"

s32 GetGold();                                      /* extern */
s32 SetGold(s32);                                     /* extern */

void sub_807A6A4(void) {
    SetGold(GetGold() + 0x1388);
}

#include "gbafe.h"

s32 GetGold();                                      /* extern */
s32 SetGold(s32);                                     /* extern */

void sub_807A6BC(s32 arg0) {
    if (GetGold() >= arg0) {
        SetGold(GetGold() - arg0);
    }
}

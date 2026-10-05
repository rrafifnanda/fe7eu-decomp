#include "gbafe.h"

void *sub_802EBCC();                                /* extern */

void sub_809F3EC(void *arg0) {
    ReadSramFast(arg0, sub_802EBCC(), 0xC8U);
}

#include "gbafe.h"

void sub_8091B8C(void) {
    u16 var_r4;

    sub_802EBD4();
    var_r4 = 0;
    do {
        AddItemToConvoy(0x87 - var_r4);
        var_r4 += 1;
    } while ((u32) var_r4 <= 0x63U);
}

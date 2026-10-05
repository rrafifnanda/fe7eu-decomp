#include "gbafe.h"

void sub_802C664(void) {
    u8 temp_r5;

    temp_r5 = gPlaySt.faction;
    gPlaySt.faction = 0x80;
    RefreshEntityMaps();
    gPlaySt.faction = temp_r5;
}

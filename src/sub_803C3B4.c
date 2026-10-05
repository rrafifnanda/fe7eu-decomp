#include "gbafe.h"

void sub_803C3B4(struct Unit *arg0) {
    GetUnitMovementCost(arg0);
    sub_803C2B8();
    SetWorkingBmMap(gBmMapMovement);
    sub_801A0E0(arg0->xPos, arg0->yPos, 0x7C, arg0->index);
}
/* Warning: struct SMSHandle is not defined (only forward-declared) */

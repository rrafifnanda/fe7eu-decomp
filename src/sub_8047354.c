#include "gbafe.h"

void sub_8047354(void *arg0) {
    SetStatScreenExcludedUnitFlags(0x1F);
    StartStatScreen(gActiveUnit, arg0);
}
/* Warning: struct SMSHandle is not defined (only forward-declared) */

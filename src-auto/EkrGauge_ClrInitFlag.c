#include "gbafe.h"

void EkrGauge_ClrInitFlag(void) {
    (*(void **)0x02000068)->unk29 = 0;
}

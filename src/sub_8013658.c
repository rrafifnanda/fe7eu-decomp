#include "gbafe.h"

void sub_8013658(void *arg0, void *arg1) {
    s32 var_r0;

    LZ77UnCompWram(arg0, gBuf);
    var_r0 = GetDataSize(arg0);
    if (var_r0 < 0) {
        var_r0 += 3;
    }
    CpuFastSet(gBuf, arg1, (u32) (var_r0 << 9) >> 0xB);
}

#include "gbafe.h"

extern s32 gUnk_08DB8FC0;

void sub_80BD534(void *arg0, s32 arg1) {
    Decompress(arg0, gUnk_08DB8FC0 + arg1);
}

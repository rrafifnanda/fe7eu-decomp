#include "gbafe.h"

s32 nullsub_7();                                      /* extern */
extern s32 gUnk_0841C754;
extern s32 gUnk_0841C774;
extern s32 gUnk_0841C794;

void sub_8085824(s32 arg0, s32 arg1) {
    void *var_r4;

    var_r4 = NULL;
    switch (arg0) {                                 /* irregular */
    case 0x0:
        var_r4 = &gUnk_0841C754;
        break;
    case 0x80:
        var_r4 = &gUnk_0841C774;
        break;
    case 0x40:
        var_r4 = &gUnk_0841C794;
        break;
    default:
        nullsub_7();
        break;
    }
    ApplyPaletteExt(var_r4, arg1 << 5, 0x20);
}

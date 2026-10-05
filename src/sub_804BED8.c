#include "gbafe.h"

void sub_804BED8(struct ProcEkrBattle *proc) {
    void (*var_r0)(struct ProcEkrBattle *);

    if (*gpEkrTriangleUnits != NULL) {
        sub_806AC9C(gAnims[2]);
        var_r0 = sub_804BF0C;
    } else {
        var_r0 = sub_804BF34;
    }
    proc->proc_idleCb = (void (*)(void *)) var_r0;
}
/* Warning: struct SMSHandle is not defined (only forward-declared) */

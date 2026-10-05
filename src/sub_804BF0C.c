#include "gbafe.h"

s32 nullsub_10();                                     /* extern */
s8 sub_806AC84();                                   /* extern */

void sub_804BF0C(struct ProcEkrBattle *proc) {
    if (sub_806AC84() == 1) {
        nullsub_10();
        proc->timer = 0x1E;
        proc->proc_idleCb = (void (*)(void *)) sub_804BF34;
    }
}

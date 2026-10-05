#include "gbafe.h"

void sub_80BCAAC(struct Proc *proc) {
    proc->x = 0;
    *(s32 *)0x03001620 |= 0x100;
    ArchiveCurrentPalettes();
}

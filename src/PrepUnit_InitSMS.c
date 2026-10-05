#include "gbafe.h"

void PrepUnit_InitSMS(struct ProcPrepUnit *proc) {
    s32 sp0;

    ApplyUnitSpritePalettes();
    sp0 = 0;
    CpuFastSet(&sp0, &gPal[0x1B0], 0x01000008U);
    MakePrepUnitList();
    PrepAutoCapDeployUnits((struct ProcAtMenu *) proc->proc_parent);
    PrepUpdateSMS();
}

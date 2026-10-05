#include "gbafe.h"

s32 StartPrepAtSubMenuUI();                           /* extern */
s32 sub_8087B80(struct ProcAtMenu *);                 /* extern */
extern struct ProcCmd ProcScr_PrepUnitScreen;

void AtMenu_StartSubmenu(struct ProcAtMenu *proc) {
    u32 temp_r0;

    StartPrepAtSubMenuUI();
    temp_r0 = proc->state - 1;
    switch (temp_r0) {
    case 4:
        sub_8087B80(proc);
        break;
    case 1:
        StartPrepItemScreen(proc);
        break;
    case 0:
        Proc_StartBlocking(&ProcScr_PrepUnitScreen, proc);
        break;
    case 3:
        StartFortuneSubMenu(PrepOptionCountToRealIndexByMask((s32) proc->hand_pos, (s32) proc->cmd_mask), proc);
        break;
    case 2:
        StartBgmVolumeChange(0x100, 0x80, 0x20, NULL);
        sub_800F070();
        sub_80A5AF8(proc);
        break;
    }
    Proc_Break(proc);
}

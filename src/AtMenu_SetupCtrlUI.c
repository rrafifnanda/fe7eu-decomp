#include "gbafe.h"

void AtMenu_SetupCtrlUI(struct ProcAtMenu *proc) {
    sub_8090AA4();
    sub_808F2E4(proc);
    ShowSysHandCursor(0x2C, (proc->hand_pos * 0x10) + 0x38, 7, 0x400U);
}

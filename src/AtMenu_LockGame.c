#include "gbafe.h"

void AtMenu_LockGame(struct ProcAtMenu *proc) {
    if ((CheckInLinkArena() << 0x18) == 0) {
        LockGame();
        LockBmDisplay();
    }
}

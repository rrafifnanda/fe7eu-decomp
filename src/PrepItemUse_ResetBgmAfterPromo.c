#include "gbafe.h"

void PrepItemUse_ResetBgmAfterPromo(void) {
    CallSomeSoundMaybe(0x49, 0x100, 0x100, 0x20, NULL);
}

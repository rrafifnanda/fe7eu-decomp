#include "gbafe.h"

void UnregisterEfxSoundSeExist(void) {
    *(s32 *)0x020200A4 = 0;
}

#include "gbafe.h"

void RegisterEfxSoundSeExist(void) {
    *(s32 *)0x020200A4 = 1;
}

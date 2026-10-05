#include "gbafe.h"

void sub_8030A5C(void *arg0) {
    ArchiveCurrentPalettes();
    sub_8013EF8(0x100, 0x100, 0x100, 0xC0, 0xC0, 0xC0, -0xFF0010, 0x40, arg0);
}

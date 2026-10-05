#include "gbafe.h"

void sub_80AD9D0(void) {
    s32 var_r4;

    var_r4 = ((s32) (0 - (u8) (0x40 & gPlaySt.chapterStateBits)) >> 0x1F) & 4;
    if (gPlaySt.chapterModeIndex == 1) {
        var_r4 |= 0x10;
    }
    if (gPlaySt.chapterModeIndex == 2) {
        var_r4 |= 0x20;
    }
    if (gPlaySt.chapterModeIndex == 3) {
        var_r4 |= 0x40;
    }
    PutChapterTitlePalette(1 | var_r4, 0x18);
    PutChapterTitlePalette(var_r4, 0x19);
    EnablePalSync();
    PutChapterTitleBG(0xAC0);
    PutChapterTitleGfx(0xB40, (u32) GetChapterTitle(&gPlaySt));
}

#include "gbafe.h"

void sub_8019428(void) {
    UnpackChapterMap(0x02001000, (s8) (u8) gPlaySt.chapterIndex);
    sub_8019654();
    sub_802C100();
    RefreshTerrainMap();
    sub_80192D4();
}

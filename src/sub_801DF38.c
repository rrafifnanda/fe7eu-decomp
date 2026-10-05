#include "gbafe.h"

void sub_801DF38(s32 arg0) {
    s32 var_r1;

    var_r1 = arg0;
    if (var_r1 < 0) {
        var_r1 = (s32) GetChapterInfo((u32) (s8) (u8) gPlaySt.chapterIndex)->fog;
    }
    gPlaySt.chapterVisionRange = (u8) var_r1;
    RefreshEntityMaps();
    RefreshUnitSprites();
    RenderMap();
}

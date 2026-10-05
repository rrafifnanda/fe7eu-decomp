#include "gbafe.h"

void InitMoreBMapGraphics(void) {
    UnpackChapterMapGraphics((s32) gPlaySt.chapterIndex);
    AllocWeatherParticles((s32) gPlaySt.chapterWeatherId);
    RenderMap();
    RefreshUnitSprites();
    ApplyUnitSpritePalettes();
    ForceSyncUnitSpriteSheet();
    InitSystemTextFont();
}

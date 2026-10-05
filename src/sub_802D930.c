#include "gbafe.h"

void sub_802D930(void) {
    AllocWeatherParticles((s32) gPlaySt.chapterWeatherId);
    SetOnHBlankB(NULL);
}

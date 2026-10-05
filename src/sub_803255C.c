#include "gbafe.h"

void sub_803255C(void *arg0) {
    InitIcons();
    ApplyIconPalettes(4);
    sub_803252C(arg0);
    StartSpriteRefresher(arg0, 2, 0, 0, Sprite_16x16_VFlipped, 6);
}

#include "gbafe.h"

extern struct HelpBoxInfo gUnk_08DAF58C;

void StartChapterStatusHelpBox(void *arg0) {
    LoadHelpBoxGfx((void *)0x06014800, 9);
    StartMovingHelpBox(&gUnk_08DAF58C, arg0);
}

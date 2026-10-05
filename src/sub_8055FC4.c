#include "gbafe.h"

void sub_8055FC4(void *arg0) {
    EndEkrBattleDeamon();
    EndEkrGauge();
    SetMainFunc(OnMain);
    SetOnVBlank(OnVBlank);
    Proc_Break(arg0);
}

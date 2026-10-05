#include "gbafe.h"

void ClearUi(void) {
    TmFill(gBg0Tm, 0);
    TmFill(gBg1Tm, 0);
    EnableBgSync(3);
}

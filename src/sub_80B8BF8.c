#include "gbafe.h"

void sub_80B8BF8(void) {
    if (GetTalkChoiceResult() == 2) {
        SetNextGameAction(5);
        return;
    }
    SetNextGameAction(0xC);
}

#include "gbafe.h"

extern s32 gpProcEfxSpellCast;

void sub_80503B8(void) {
    if (gpProcEfxSpellCast != 0) {
        gpProcEfxSpellCast = 0;
        Proc_End(NULL);
    }
}

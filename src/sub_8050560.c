#include "gbafe.h"

extern s32 gpProcEfxSpellCast;

void sub_8050560(void) {
    if (gpProcEfxSpellCast != 0) {
        gpProcEfxSpellCast = 0;
        Proc_End(NULL);
    }
}

#include "gbafe.h"

s32 sub_8007C64();                                    /* extern */

void ClearTalk(void) {
    sub_80095E4();
    Proc_EndEach(ProcScr_Face);
    InitFaces();
    sub_8007C64();
}

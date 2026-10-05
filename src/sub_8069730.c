#include "gbafe.h"

void sub_8069730(void) {
    ClearText((struct Text *)0x020176F0);
    Text_SetCursor((struct Text *)0x020176F0, 8);
    Text_SetColor((struct Text *)0x020176F0, 2);
    Text_DrawNumber((struct Text *)0x020176F0, (s32) *(u16 *)0x02020108);
    PutText((struct Text *)0x020176F0, &gBg2Tm[0xED]);
}

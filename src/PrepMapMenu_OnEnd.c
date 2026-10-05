#include "gbafe.h"

extern struct ProcCmd ProcScr_PrepHelpPrompt;

void PrepMapMenu_OnEnd(void) {
    EndHelpPromptSprite();
    Proc_EndEach(&ProcScr_PrepHelpPrompt);
}

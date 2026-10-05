#include "gbafe.h"

void EndEkrPopup(void) {
    void *temp_r0;

    temp_r0 = *(void **)0x02020138;
    if (temp_r0 != NULL) {
        Proc_End(temp_r0);
        *(void **)0x02020138 = NULL;
    }
}

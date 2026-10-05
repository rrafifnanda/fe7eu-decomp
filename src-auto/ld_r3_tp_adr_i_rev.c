#include "gbafe.h"

void ld_r3_tp_adr_i_rev(void *arg1) {
    arg1->unk40 = (u8 *) (arg1->unk40 + 1);
}

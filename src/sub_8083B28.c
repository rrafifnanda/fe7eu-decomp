#include "gbafe.h"

void sub_8083B28(void *arg0) {
    if (1 & gpKeySt->pressed) {
        Proc_Break(arg0);
    }
}

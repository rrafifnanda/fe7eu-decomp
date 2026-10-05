#include "gbafe.h"

void sub_80839A4(void *arg0) {
    if (1 & gpKeySt->pressed) {
        Proc_Break(arg0);
    }
}

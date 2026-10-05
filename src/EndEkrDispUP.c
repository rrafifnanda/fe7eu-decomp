#include "gbafe.h"

extern void *gpProcEkrDispUP;

void EndEkrDispUP(void) {
    Proc_End(gpProcEkrDispUP);
}

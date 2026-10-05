#include "gbafe.h"

void EfxFlashRestorePalSync(void *arg0) {
    EnablePalSync();
    Proc_Break(arg0);
}

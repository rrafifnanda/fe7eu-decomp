#include "gbafe.h"

void sub_806A584();                                 /* extern */

void sub_8069BB4(void *arg0) {
    SetOnHBlankA(sub_806A584);
    EnableBgSync(1);
    EnableBgSync(4);
    EnableBgSync(2);
    EnablePalSync();
    Proc_Break(arg0);
}

#include "gbafe.h"

extern void *gpProcEfxWeaponIcon;

void EndProcEfxWeaponIcon(void) {
    if (gpProcEfxWeaponIcon != NULL) {
        Proc_End(gpProcEfxWeaponIcon);
        gpProcEfxWeaponIcon = NULL;
    }
}

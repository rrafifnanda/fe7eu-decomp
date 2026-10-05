#include "gbafe.h"

void ply_xiecv(struct MusicPlayerInfo *arg0, struct MusicPlayerTrack *arg1) {
    u8 *temp_r0;

    temp_r0 = arg1->cmdPtr;
    arg1->echoVolume = *temp_r0;
    arg1->cmdPtr = temp_r0 + 1;
}

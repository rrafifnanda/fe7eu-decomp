#include "gbafe.h"

void sub_80B63DC(s32 arg0) {
    if (0x10 & arg0) {
        StartBgm((s32) GetChapterInfo((u32) (s8) (u8) gPlaySt.chapterIndex)->song_prologue_lyn, NULL);
    }
}

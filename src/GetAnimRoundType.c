#include "gbafe.h"

s16 GetAnimRoundType(struct Anim *anim) {
    return GetBattleAnimRoundType(((anim->nextRoundId - 1) * 2) + GetAnimPosition(anim));
}

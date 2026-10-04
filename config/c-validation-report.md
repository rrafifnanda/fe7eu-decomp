# FE7J C functions vs FE7 EU — validation report

- C files compiled          : 84
- **byte-identical raw**         : **50**
- **byte-identical after link**  : **0**
- differ                     : 21
- files/links failed         : 816

## Byte-identical functions (ready to replace asm)

| function | source | size | EU address | mode |
|---|---|---|---|---|
| SetNextVCount | hardware.c | 0x48 | 0x08001954 | raw |
| RefreshKeyStFromKeys | hardware.c | 0x1d4 | 0x08001A00 | raw |
| ClearKeySt | hardware.c | 0x34 | 0x08001C28 | raw |
| sub_8001FF0 | hardware.c | 0xa4 | 0x08002024 | raw |
| InsertChildProcess | proc.c | 0x18 | 0x080045EC | raw |
| Proc_Goto | proc.c | 0x38 | 0x08004748 | raw |
| sub_8004634 | proc.c | 0x8 | 0x08004780 | raw |
| sub_80049A0 | proc.c | 0x14 | 0x08004AF8 | raw |
| BgFaceEyeBlink_Init | face.c | 0xc | 0x080074D0 | raw |
| TalkAdvance_Init | talk-advance.c | 0x8 | 0x0800A6D8 | raw |
| EvtCmd_SleepFast | eventscr.c | 0x34 | 0x0800B64C | raw |
| EvtCmd_SleepText | eventscr.c | 0x34 | 0x0800B680 | raw |
| SetUnitStatus | unit.c | 0x1c | 0x080179D4 | raw |
| UnitRemoveInvalidItems | unit.c | 0x54 | 0x08017A80 | raw |
| GetUnitItemCount | unit.c | 0x20 | 0x08017AD4 | raw |
| sub_8017B44 | unit.c | 0x38 | 0x08017B50 | raw |
| UnitCheckStatCaps | unit.c | 0xd4 | 0x08018070 | raw |
| UnitHasMagicRank | unit.c | 0x24 | 0x080188E8 | raw |
| sub_80188F4 | unit.c | 0x20 | 0x0801890C | raw |
| GetUnitMiniPortraitId | unit.c | 0x2c | 0x08019008 | raw |
| ChapterIntro_BeginVOpenText | bmfx-chapterintrofx.c | 0x8 | 0x0801FE64 | raw |
| ChapterIntro_BeginCloseText | bmfx-chapterintrofx.c | 0x8 | 0x080202E8 | raw |
| ChapterIntro_BeginFastCloseText | bmfx-chapterintrofx.c | 0x8 | 0x0802033C | raw |
| ChapterIntro_SetFasten | bmfx-chapterintrofx.c | 0x8 | 0x08020580 | raw |
| sub_80217EC | bmfx-niniantransform.c | 0x34 | 0x0802182C | raw |
| GetUnitSupporterCount | support.c | 0x14 | 0x08026B48 | raw |
| InitBonuses | support.c | 0x10 | 0x08026F30 | raw |
| ComputeBattleUnitEffectiveHitRate | battle.c | 0x30 | 0x080292AC | raw |
| ComputeBattleUnitSilencerRate | battle.c | 0x5c | 0x08029384 | raw |
| ComputeBattleUnitStatusBonuses | battle.c | 0x3c | 0x0802941C | raw |
| GenerateBattleUnitStatGainsComparatively | battle.c | 0x64 | 0x08029EA4 | raw |
| CheckBattleUnitStatCaps | battle.c | 0x104 | 0x08029F08 | raw |
| BattleUnitTargetCheckCanCounter | battle.c | 0x2c | 0x0802A6A4 | raw |
| UnitTornOut_Init | eventcall_unittornout.c | 0x8 | 0x0803375C | raw |
| EfxDragonDeadFallBody_Blocking | banim-ekrdragonfx.c | 0xc | 0x080658EC | raw |
| EventQuakefx_Init | eventcall_quakefx.c | 0x8 | 0x0807AF5C | raw |
| DragonSpriteBlinking_Init | eventcall_dragongate.c | 0x8 | 0x0807B404 | raw |
| EventDragonsSpritefx_Init | eventcall_firedragonsprite.c | 0x3c | 0x0807E370 | raw |
| DrawUiGaugeBitmapEdgeColumn | statscreenfx.c | 0x24 | 0x0807F674 | raw |
| DrawUiGaugeBitmapBaseColumn | statscreenfx.c | 0x30 | 0x0807F698 | raw |
| BackgroundSlide_Init | statscreenfx.c | 0x8 | 0x0807F818 | raw |
| ResetHelpBoxInitSize | statscreen-helpbox.c | 0x10 | 0x08081DF4 | raw |
| GetPrepOptionCount | prepscreen.c | 0x24 | 0x0808DC84 | raw |
| PrepItemScreen_OnHBlank | prep_itemscreen.c | 0x34 | 0x080915DC | raw |
| Checksum16 | save_core.c | 0x2c | 0x0809E810 | raw |
| UiCursorHand_Init | cursor-hand.c | 0x2c | 0x080A8E1C | raw |
| SysHandCursor_Init | sysutil.c | 0x8 | 0x080A994C | raw |
| SysBrownBox_Init | sysutil.c | 0x18 | 0x080A9F3C | raw |
| AppendCharacter | sysutil.c | 0xc | 0x080AAFCC | raw |
| HBlank_TitleScreen | titlescreen.c | 0x2c | 0x080BAEC0 | raw |

## Differing

| function | source | size | EU address | missing symbols |
|---|---|---|---|---|
| DummyIrqRoutine | irq.c | 0xc | 0x08000BBC |  |
| ClearMoveList | move-data.c | 0x9c | 0x08002FE8 |  |
| RegisterDataMove | move-data.c | 0x84 | 0x08003084 |  |
| RegisterDataFill | move-data.c | 0x7c | 0x08003108 |  |
| InitOam | oam.c | 0x9c | 0x08003238 |  |
| SyncHiOam | oam.c | 0x58 | 0x080032EC |  |
| SetObjAffine | oam.c | 0xc8 | 0x08003394 |  |
| StartMineAnim | bmfx-minefx.c | 0x7c | 0x080217B0 |  |
| sub_8021820 | bmfx-niniantransform.c | 0xd8 | 0x08021860 |  |
| NinianStartTransformToHunman | bmfx-niniantransform.c | 0x4c | 0x080219AC |  |
| UnpackUiWindowFrameGraphics2 | ui.c | 0x54 | 0x080498A0 |  |
| BattleAIS_ExecCommands | banim-main.c | 0xabc | 0x08053398 |  |
| EventQuakefx_Loop | eventcall_quakefx.c | 0x80 | 0x0807AF64 |  |
| ZephielEpilogue_Loop_BlendCgs | eventcall_zephielepilogue.c | 0x50 | 0x0807BFAC |  |
| PutChapterTitlePalette | chapter-title.c | 0x74 | 0x0808205C |  |
| OnVBlank_SioError | sioerror.c | 0x24 | 0x080867FC |  |
| InitPrepScreenMainMenu | preputil_atmenuitem.c | 0x144 | 0x0808E1A0 |  |
| sub_80A5B44 | savedraw.c | 0x11c | 0x080A5258 |  |
| SpinRotation_Init | savedrawfx.c | 0x34 | 0x080A60D4 |  |
| SpinRotation_Loop | savedrawfx.c | 0x50 | 0x080A6108 |  |
| InitOpScanlineBuf | opanim_scanline.c | 0x50 | 0x080BBBB8 |  |

## Failed

- AnimCreate: anime.c: link failed
- AnimCreate_unused: anime.c: link failed
- AnimDelete: anime.c: link failed
- AnimDisplay: anime.c: link failed
- AnimInterpret: anime.c: link failed
- AnimSort: anime.c: link failed
- EfxDrsmmoyaBG_Loop: banim-efxdrsmmoya.c: link failed
- EfxDrsmmoyaScrollCOL_Delay: banim-efxdrsmmoya.c: link failed
- EfxDrsmmoyaScrollCOL_Loop1: banim-efxdrsmmoya.c: link failed
- EfxDrsmmoyaScrollCOL_Loop3: banim-efxdrsmmoya.c: link failed
- EfxDrsmmoyaScroll_Loop: banim-efxdrsmmoya.c: link failed
- EfxDrsmmoya_Loop: banim-efxdrsmmoya.c: link failed
- NewEfxDrsmmoyaBG: banim-efxdrsmmoya.c: link failed
- NewEfxDrsmmoyaScrollCOL: banim-efxdrsmmoya.c: link failed
- AddEkrDragonStatusAttr: banim-ekrdragon.c: link failed
- AddEkrDragonStatusType: banim-ekrdragon.c: link failed
- CheckEfxDragonDeadFallHead: banim-ekrdragon.c: link failed
- CheckEkrDragonEndingDone: banim-ekrdragon.c: link failed
- EkrDragonIntroDone: banim-ekrdragon.c: link failed
- EkrDragonTmCpyExt: banim-ekrdragon.c: link failed
- EkrDragonTmCpyHFlip: banim-ekrdragon.c: link failed
- EkrDragonTmCpyWithDistance: banim-ekrdragon.c: link failed
- EkrDragon_CustomBgFadeIn: banim-ekrdragon.c: link failed
- EkrDragon_DragonTailDisplay: banim-ekrdragon.c: link failed
- EkrDragon_InBattleIDLE: banim-ekrdragon.c: link failed
- EkrDragon_PreMainBodyIntro: banim-ekrdragon.c: link failed
- EkrDragon_ReloadCustomBgAndFadeOut: banim-ekrdragon.c: link failed
- EkrDragon_ReloadTerrainEtc: banim-ekrdragon.c: link failed
- EkrDragon_StartDragonTailIntro: banim-ekrdragon.c: link failed
- EkrDragon_StartMainBodyFallIn: banim-ekrdragon.c: link failed
- EkrDragon_StartMainBodyIntro: banim-ekrdragon.c: link failed
- EkrDragon_TriggerEnding: banim-ekrdragon.c: link failed
- EkrDragon_TriggerIntroDone: banim-ekrdragon.c: link failed
- EkrDragon_WaitForFadeOut: banim-ekrdragon.c: link failed
- EkrDragon_WaitMainBodyFallIn: banim-ekrdragon.c: link failed
- GetEkrDragonStatusAttr: banim-ekrdragon.c: link failed
- GetEkrDragonStatusType_: banim-ekrdragon.c: link failed
- NewEkrDragon: banim-ekrdragon.c: link failed
- SetEfxDragonDeadFallHead: banim-ekrdragon.c: link failed
- EfxDragonDeadFallBody_Loop1: banim-ekrdragonfx.c: link failed
- EfxDragonDeadFallHead_Loop1: banim-ekrdragonfx.c: link failed
- EfxDragonDeadFallHead_Loop2: banim-ekrdragonfx.c: link failed
- EkrDragonBarkQuake_Loop: banim-ekrdragonfx.c: link failed
- EkrDragonBaseAppear_Loop: banim-ekrdragonfx.c: link failed
- EkrDragonBaseHide_Loop: banim-ekrdragonfx.c: link failed
- EkrDragonBg2ScrollHandler_Loop: banim-ekrdragonfx.c: link failed
- EkrDragonBg2Scroll_OnVBlank: banim-ekrdragonfx.c: link failed
- EkrDragonBg3HfScrollHandler_Loop: banim-ekrdragonfx.c: link failed
- EkrDragonBg3HfScroll_OnVBlank: banim-ekrdragonfx.c: link failed
- EkrDragonBodyBlack_Loop: banim-ekrdragonfx.c: link failed
- EkrDragonFireBG3_Loop: banim-ekrdragonfx.c: link failed
- EkrDragonFlashingWingBg_Loop: banim-ekrdragonfx.c: link failed
- EkrDragonScreenFlashing_Loop1: banim-ekrdragonfx.c: link failed
- EkrDragonScreenFlashing_Loop2: banim-ekrdragonfx.c: link failed
- EkrDragonScreenFlashing_Loop3: banim-ekrdragonfx.c: link failed
- EkrDragonScreenFlashing_RefrainPalette: banim-ekrdragonfx.c: link failed
- EkrDragonTunkFace_Loop: banim-ekrdragonfx.c: link failed
- EkrDragonTunk_Loop1: banim-ekrdragonfx.c: link failed
- EkrDragonTunk_Loop2: banim-ekrdragonfx.c: link failed
- NewEfxDragonDeadFallBody: banim-ekrdragonfx.c: link failed
- NewEfxDragonDeadFallHeadFx: banim-ekrdragonfx.c: link failed
- NewEkrDragonBarkQuake: banim-ekrdragonfx.c: link failed
- NewEkrDragonBaseAppear: banim-ekrdragonfx.c: link failed
- NewEkrDragonBg3HfScrollHandler: banim-ekrdragonfx.c: link failed
- NewEkrDragonFireBG2: banim-ekrdragonfx.c: link failed
- NewEkrDragonFireBg3: banim-ekrdragonfx.c: link failed
- sub_80668B8: banim-ekrdragonfx.c: link failed
- sub_8066950: banim-ekrdragonfx.c: link failed
- AnimScrAdvance: banim-mainutils.c: link failed
- ApplyBanimUniquePalette: banim-mainutils.c: link failed
- EkrChienCHRMain: banim-mainutils.c: link failed
- RegisterAISSheetGraphics: banim-mainutils.c: link failed
- BattleApplyExpGains: battle.c: link failed
- BattleApplyItemEffect: battle.c: link failed
- BattleApplyItemExpGains: battle.c: link failed
- BattleApplyMiscActionExpGains: battle.c: link failed
- BattleApplyReaverEffect: battle.c: link failed
- BattleApplyUnitUpdates: battle.c: link failed
- BattleCheckBraveEffect: battle.c: link failed
- BattleCheckTriangleAttack: battle.c: link failed

# Phase 1 report — FE7J symbols mapped to FE7 EU (AE7X)

- JP symbols parsed  : **6248**
- EU symbols mapped  : **4837** (77.4%)
- uncertain          : 275
- not found          : 1136

- JP reference sha1  : 037702b1febd5c9535262165bf030551d153de81
- EU target sha1     : c37e3bae84b53e6972ed7608541a62896fa5d6a3

## Coverage per asm file

| file | mapped | total |
|---|---|---|
| agb-sram.s | 5 | 5 |
| anim-drv.s | 1 | 1 |
| banim-efxbattle.s | 112 | 132 |
| banim-ekrbattle.s | 35 | 48 |
| banim-ekrgauge.s | 35 | 38 |
| bmfx.s | 67 | 80 |
| bmfx_08020508.s | 39 | 43 |
| bmio.s | 33 | 40 |
| cgtext.s | 35 | 40 |
| chapter-status.s | 15 | 21 |
| code-ai.s | 211 | 243 |
| code-banim-08064458.s | 39 | 46 |
| code-banim.s | 530 | 624 |
| code-banim1.s | 44 | 59 |
| code-banim2.s | 148 | 192 |
| code-sio.s | 310 | 461 |
| code1.s | 243 | 312 |
| code_080AB6FC.s | 94 | 128 |
| code_080AFE38.s | 295 | 389 |
| debug-menu.s | 32 | 56 |
| debug-text.s | 16 | 18 |
| event-08010630.s | 16 | 33 |
| event-engine.s | 36 | 50 |
| eventcall.s | 198 | 277 |
| eventcall_flamebreath.s | 1 | 3 |
| eventcallfx.s | 86 | 140 |
| eventscr.s | 188 | 303 |
| eventscr_08012378.s | 5 | 7 |
| eventscr_snowstorm.s | 1 | 6 |
| gba-syscall.s | 6 | 18 |
| helpbox.s | 56 | 73 |
| item-action.s | 29 | 30 |
| item-use.s | 42 | 56 |
| item.s | 51 | 70 |
| m4a.s | 55 | 58 |
| m4a_1.s | 41 | 43 |
| main.s | 2 | 2 |
| map-menu.s | 130 | 160 |
| map-sel.s | 11 | 18 |
| map.s | 24 | 30 |
| mapanim.s | 216 | 221 |
| mapui.s | 42 | 53 |
| mapwork.s | 20 | 23 |
| msg.s | 1 | 4 |
| mu.s | 93 | 93 |
| opanim.s | 58 | 86 |
| opanim_scanline.s | 5 | 5 |
| player-phase.s | 24 | 35 |
| prep.s | 18 | 27 |
| prep_8099D18.s | 41 | 51 |
| prep_atmenu.s | 31 | 36 |
| prep_fortune.s | 15 | 21 |
| prep_itemlist.s | 6 | 20 |
| prep_itemscreen.s | 33 | 44 |
| prep_itemsell.s | 9 | 19 |
| prep_itemsupply.s | 20 | 38 |
| prep_itemtrade.s | 6 | 9 |
| prep_itemuse.s | 13 | 21 |
| prep_itemusemind.s | 3 | 4 |
| prep_menu.s | 21 | 21 |
| prep_menuscroll.s | 8 | 9 |
| prep_sallycir.s | 4 | 11 |
| prep_uisupport.s | 48 | 65 |
| prep_unitselect.s | 30 | 36 |
| prep_utils.s | 20 | 24 |
| preputil_unitlist.s | 4 | 4 |
| ram-funcs.s | 7 | 7 |
| save.s | 145 | 204 |
| savedraw.s | 10 | 17 |
| savedrawfx.s | 13 | 19 |
| savemenu.s | 30 | 48 |
| savemenu_difficulty.s | 4 | 4 |
| savemenu_tactician.s | 10 | 12 |
| scanline.s | 43 | 43 |
| sioerror.s | 3 | 3 |
| sound.s | 30 | 33 |
| spinning_arrow.s | 8 | 8 |
| statscreen-util.s | 4 | 4 |
| target-sel.s | 62 | 62 |
| text.s | 49 | 73 |
| trade-menu.s | 32 | 40 |
| trap.s | 33 | 40 |
| ui-menu.s | 20 | 37 |
| uiutils.s | 13 | 14 |
| unit-sprite.s | 31 | 38 |
| unitlistscreen.s | 34 | 39 |
| utils.s | 150 | 170 |

## Uncertain (candidate exists, below accept score)

- SetTextFontGlyphs (text.s) score=0.5 jp=0x080052E0 eu=0x080CEC8E
- sub_800AC34 (event-engine.s) score=0.5 jp=0x0800AC34 eu=0x0800ADE0
- sub_800EE60 (eventscr.s) score=0.5 jp=0x0800EE60 eu=0x0800F140
- GetWeaponExpProgressState (item.s) score=0.5 jp=0x08016E8C eu=0x08016D6C
- sub_8016FBC (item.s) score=0.5 jp=0x08016FBC eu=0x08016ED4
- sub_801B040 (mapwork.s) score=0.5 jp=0x0801B040 eu=0x0801B088
- sub_801B96C (debug-menu.s) score=0.5 jp=0x0801B96C eu=0x0801B9C0
- GetBattleForecastPanelSide (code1.s) score=0.5 jp=0x08033884 eu=0x0803399A
- sub_80390F8 (code-ai.s) score=0.5 jp=0x080390F8 eu=0x080392DC
- sub_803E8E8 (code-sio.s) score=0.5 jp=0x0803E8E8 eu=0x0803EB5A
- sub_804B78C (map-sel.s) score=0.5 jp=0x0804B78C eu=0x0804AD28
- sub_804DC18 (banim-ekrgauge.s) score=0.5 jp=0x0804DC18 eu=0x0804D2EC
- sub_8051830 (code-banim1.s) score=0.5 jp=0x08051830 eu=0x08050F30
- sub_806A5C0 (code-banim2.s) score=0.5 jp=0x0806A5C0 eu=0x08069ED4
- sub_80749F0 (mapanim.s) score=0.5 jp=0x080749F0 eu=0x080742B4
- RegisterChapterStats (save.s) score=0.5 jp=0x080A05A0 eu=0x0809FF28
- sub_80A0768 (save.s) score=0.5 jp=0x080A0768 eu=0x080A0344
- sub_80A5C60 (savedraw.s) score=0.5 jp=0x080A5C60 eu=0x080A5374
- sub_80AF68C (code_080AB6FC.s) score=0.5 jp=0x080AF68C eu=0x080AED50
- sub_8014334 (utils.s) score=0.5161 jp=0x08014334 eu=0x080140B4
- PrepUnit_InitGfx (prep_unitselect.s) score=0.5172 jp=0x08093B14 eu=0x080934D0
- sub_802C6A8 (trap.s) score=0.52 jp=0x0802C6A8 eu=0x0802C7CC
- sub_80B19AC (code_080AFE38.s) score=0.5238 jp=0x080B19AC eu=0x080761FC
- sub_8017208 (item.s) score=0.5312 jp=0x08017208 eu=0x08017122
- sub_8023A84 (map-menu.s) score=0.5312 jp=0x08023A84 eu=0x08023AE4
- DoItemUse (item-use.s) score=0.5312 jp=0x08027584 eu=0x0802762C
- CleanupUnitsBeforeChapter (code1.s) score=0.5312 jp=0x0802E8A0 eu=0x0802E9B0
- PrepScreenProc_StartMapMenu (code1.s) score=0.5312 jp=0x08030B88 eu=0x08030CBC
- sub_8051020 (banim-efxbattle.s) score=0.5312 jp=0x08051020 eu=0x08050718
- sub_80518BC (code-banim1.s) score=0.5312 jp=0x080518BC eu=0x08050FB8
- GetEfxSoundType1FromTerrain (code-banim2.s) score=0.5312 jp=0x0806830C eu=0x08067BE8
- sub_806A4F8 (code-banim2.s) score=0.5312 jp=0x0806A4F8 eu=0x08069E06
- sub_806AEFC (code-banim2.s) score=0.5312 jp=0x0806AEFC eu=0x0806A658
- PrepItemUse_HandleItemEffect (prep_itemuse.s) score=0.5312 jp=0x08095E8C eu=0x08095968
- sub_8098F3C (prep_itemsell.s) score=0.5312 jp=0x08098F3C eu=0x080989A0
- GC_ConnectToFE6 (code-sio.s) score=0.5333 jp=0x080448B8 eu=0x0802AB78
- CheckPermanentFlag (eventcall.s) score=0.5333 jp=0x08079F68 eu=0x0807987E
- CheckChapterFlag (eventcall.s) score=0.5333 jp=0x0807A028 eu=0x0807997E
- sub_80441D0 (code-sio.s) score=0.5357 jp=0x080441D0 eu=0x0801E5D8
- sub_807DE80 (eventcallfx.s) score=0.5385 jp=0x0807DE80 eu=0x0800AFB4
- sub_807E050 (eventcallfx.s) score=0.5385 jp=0x0807E050 eu=0x0800AFB4
- sub_807E2CC (eventcallfx.s) score=0.5385 jp=0x0807E2CC eu=0x0800AFB4
- CanUnitPrepScreenUse (prep_utils.s) score=0.5385 jp=0x08091C28 eu=0x080915A4
- sub_80AE970 (code_080AB6FC.s) score=0.5385 jp=0x080AE970 eu=0x080ADFF4
- sub_8043DE0 (code-sio.s) score=0.5556 jp=0x08043DE0 eu=0x080B3D82
- sub_8049A08 (code-sio.s) score=0.5556 jp=0x08049A08 eu=0x08048F90
- sub_80B89AC (code_080AFE38.s) score=0.5556 jp=0x080B89AC eu=0x0804B462
- sub_800F0CC (eventscr.s) score=0.5625 jp=0x0800F0CC eu=0x0800F3B4
- Interpolate (utils.s) score=0.5625 jp=0x08013508 eu=0x08013284
- sub_801F400 (bmfx.s) score=0.5625 jp=0x0801F400 eu=0x0801F4CC

## Not found

- StartBgmVolumeChange (sound.s) jp=0x08003B4C size=0xb0
- IsMusicProc2Running (sound.s) jp=0x08003F04 size=0x24
- MusicProc4Exists (sound.s) jp=0x0800409C size=0x24
- sub_8004E4C (debug-text.s) jp=0x08004E4C size=0x50
- sub_800507C (debug-text.s) jp=0x0800507C size=0x78
- GetLang (text.s) jp=0x0800527C size=0x4
- SetTextFont (text.s) jp=0x08005320 size=0x24
- ClearTextPart (text.s) jp=0x080053E8 size=0x44
- Text_GetChrOffset (text.s) jp=0x0800542C size=0x14
- Text_GetCursor (text.s) jp=0x08005440 size=0x4
- Text_SetCursor (text.s) jp=0x08005444 size=0x4
- Text_Skip (text.s) jp=0x08005448 size=0x8
- Text_SetColor (text.s) jp=0x08005450 size=0x4
- Text_GetColor (text.s) jp=0x08005454 size=0x4
- PutText (text.s) jp=0x08005460 size=0x50
- GetCharTextLen (text.s) jp=0x08005528 size=0x3c
- Text_DrawString (text.s) jp=0x080055DC size=0x74
- Text_DrawNumber (text.s) jp=0x08005650 size=0x54
- GetTextDrawDest (text.s) jp=0x08005740 size=0x24
- SetTextDrawNoClear (text.s) jp=0x08005984 size=0x14
- GetStringTextLenAscii (text.s) jp=0x08005A94 size=0x34
- nullsub_23 (text.s) jp=0x08005AC8 size=0x4
- GetSpriteTextDrawDest (text.s) jp=0x08005BB8 size=0x24
- sub_8005EBC (text.s) jp=0x08005EBC size=0x58
- LoadUnitCore (event-engine.s) jp=0x0800A614 size=0xf8
- sub_800A7A4 (event-engine.s) jp=0x0800A7A4 size=0x1c
- sub_800A7E8 (event-engine.s) jp=0x0800A7E8 size=0x104
- sub_800A8EC (event-engine.s) jp=0x0800A8EC size=0xd4
- sub_800A9C0 (event-engine.s) jp=0x0800A9C0 size=0x34
- sub_800A9F4 (event-engine.s) jp=0x0800A9F4 size=0x70
- sub_800AD60 (event-engine.s) jp=0x0800AD60 size=0x18
- sub_800B06C (event-engine.s) jp=0x0800B06C size=0x50
- sub_800B0BC (event-engine.s) jp=0x0800B0BC size=0x18
- sub_800B188 (event-engine.s) jp=0x0800B188 size=0x78
- sub_800B3DC (event-engine.s) jp=0x0800B3DC size=0x28
- EventStartTalk (eventscr.s) jp=0x0800B848 size=0x84
- sub_800B8CC (eventscr.s) jp=0x0800B8CC size=0x34
- sub_800B900 (eventscr.s) jp=0x0800B900 size=0x3c
- sub_800B93C (eventscr.s) jp=0x0800B93C size=0x58
- sub_800B994 (eventscr.s) jp=0x0800B994 size=0x24
- sub_800BA34 (eventscr.s) jp=0x0800BA34 size=0x28
- Event14_TalkContinue (eventscr.s) jp=0x0800BA5C size=0x30
- sub_800BA8C (eventscr.s) jp=0x0800BA8C size=0x48
- sub_800BAD4 (eventscr.s) jp=0x0800BAD4 size=0x90
- sub_800BB64 (eventscr.s) jp=0x0800BB64 size=0x4c
- sub_800BBF8 (eventscr.s) jp=0x0800BBF8 size=0x50
- sub_800BC48 (eventscr.s) jp=0x0800BC48 size=0x50
- EventEndTalk (eventscr.s) jp=0x0800BCF0 size=0x94
- Event20 (eventscr.s) jp=0x0800BD84 size=0x78
- sub_800BDFC (eventscr.s) jp=0x0800BDFC size=0x70
- sub_800BE6C (eventscr.s) jp=0x0800BE6C size=0x80
- CanDisplayUnitMovement (eventscr.s) jp=0x0800BF1C size=0x4c
- nullsub_26 (eventscr.s) jp=0x0800CC24 size=0x4
- sub_800CEF4 (eventscr.s) jp=0x0800CEF4 size=0x38
- Event3D_ASMC2 (eventscr.s) jp=0x0800D2B0 size=0x34
- Event41_Halt (eventscr.s) jp=0x0800D37C size=0x4
- Event42_Nop (eventscr.s) jp=0x0800D380 size=0x4
- sub_800D4C8 (eventscr.s) jp=0x0800D4C8 size=0x24
- sub_800D4EC (eventscr.s) jp=0x0800D4EC size=0x24
- sub_800D5E8 (eventscr.s) jp=0x0800D5E8 size=0x90
- sub_800D744 (eventscr.s) jp=0x0800D744 size=0x30
- sub_800DBD4 (eventscr.s) jp=0x0800DBD4 size=0x70
- sub_800DC94 (eventscr.s) jp=0x0800DC94 size=0x38
- sub_800DD08 (eventscr.s) jp=0x0800DD08 size=0x68
- sub_800E25C (eventscr.s) jp=0x0800E25C size=0x28
- sub_800E284 (eventscr.s) jp=0x0800E284 size=0xa8
- sub_800E32C (eventscr.s) jp=0x0800E32C size=0x30
- sub_800E36C (eventscr.s) jp=0x0800E36C size=0x24
- sub_800E390 (eventscr.s) jp=0x0800E390 size=0x24
- sub_800E3B4 (eventscr.s) jp=0x0800E3B4 size=0x28
- sub_800E3DC (eventscr.s) jp=0x0800E3DC size=0x30
- sub_800E40C (eventscr.s) jp=0x0800E40C size=0x30
- sub_800E570 (eventscr.s) jp=0x0800E570 size=0x28
- sub_800E598 (eventscr.s) jp=0x0800E598 size=0x28
- sub_800E5C0 (eventscr.s) jp=0x0800E5C0 size=0x2c
- sub_800E60C (eventscr.s) jp=0x0800E60C size=0x1c
- sub_800E65C (eventscr.s) jp=0x0800E65C size=0x3c
- sub_800E698 (eventscr.s) jp=0x0800E698 size=0x3c
- sub_800E6D4 (eventscr.s) jp=0x0800E6D4 size=0x24
- sub_800E6F8 (eventscr.s) jp=0x0800E6F8 size=0x24

## Most common JP->EU deltas

- -0x794: 160
- -0x6f8: 131
- +0x88: 112
- -0x280: 105
- -0x92c: 94
- -0x7e8: 89
- -0x358: 77
- +0x4c: 76
- -0x72c: 72
- -0x760: 63
- +0x70: 59
- +0x128: 56
- +0x114: 53
- +0x5c: 52
- +0x230: 50

## Validation

- `scripts/split_eu.py` emitted 4,837 functions (511,928 bytes) across 87 modules.
- `scripts/verify_split.py` reassembled every module with `arm-none-eabi-as` and
  compared it against the ROM: **87/87 files byte-exact**.
- Spot checks: `ReadSramFast_Core`=0x080C0640, `WriteSramFast`=0x080C0680,
  `VerifySramFast_Core`=0x080C06C0, `SetSramFastFunc`=0x080C070C.

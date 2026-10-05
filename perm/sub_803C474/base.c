

       
       
typedef int __int32_t;
typedef unsigned int __uint32_t;
typedef long int ptrdiff_t;
typedef unsigned long int size_t;
typedef int wchar_t;
typedef unsigned long clock_t;
typedef long time_t;
struct tm
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
};
clock_t clock (void);
double difftime (time_t _time2, time_t _time1);
time_t mktime (struct tm *_timeptr);
time_t time (time_t *_timer);
char *asctime (const struct tm *_tblock);
char *ctime (const time_t *_time);
struct tm *gmtime (const time_t *_timer);
struct tm *localtime (const time_t *_timer);
size_t strftime (char *_s, size_t _maxsize, const char *_fmt, const struct tm *_t);
char *asctime_r (const struct tm *, char *);
char *ctime_r (const time_t *, char *);
struct tm *gmtime_r (const time_t *, struct tm *);
struct tm *localtime_r (const time_t *, struct tm *);
typedef __uint32_t ULong;
struct _glue
{
  struct _glue *_next;
  int _niobs;
  struct __sFILE *_iobs;
};
struct _Bigint
{
  struct _Bigint *_next;
  int _k, _maxwds, _sign, _wds;
  ULong _x[1];
};
struct _atexit {
 struct _atexit *_next;
 int _ind;
 void (*_fns[32])(void);
};
struct __sbuf {
 unsigned char *_base;
 int _size;
};
typedef long _fpos_t;
struct __sFILE {
  unsigned char *_p;
  int _r;
  int _w;
  short _flags;
  short _file;
  struct __sbuf _bf;
  int _lbfsize;
  void * _cookie;
  int (*_read) (void * _cookie, char *_buf, int _n);
  int (*_write) (void * _cookie, const char *_buf, int _n);
  _fpos_t (*_seek) (void * _cookie, _fpos_t _offset, int _whence);
  int (*_close) (void * _cookie);
  struct __sbuf _ub;
  unsigned char *_up;
  int _ur;
  unsigned char _ubuf[3];
  unsigned char _nbuf[1];
  struct __sbuf _lb;
  int _blksize;
  int _offset;
  struct _reent *_data;
};
struct _reent
{
  int _errno;
  struct __sFILE *_stdin, *_stdout, *_stderr;
  int _inc;
  char _emergency[25];
  int _current_category;
  const char *_current_locale;
  int __sdidinit;
  void (*__cleanup) (struct _reent *);
  struct _Bigint *_result;
  int _result_k;
  struct _Bigint *_p5s;
  struct _Bigint **_freelist;
  int _cvtlen;
  char *_cvtbuf;
  union
    {
      struct
        {
          unsigned int _rand_next;
          char * _strtok_last;
          char _asctime_buf[26];
          struct tm _localtime_buf;
          int _gamma_signgam;
        } _reent;
      struct
        {
          unsigned char * _nextf[30];
          unsigned int _nmalloc[30];
        } _unused;
    } _new;
  struct _atexit *_atexit;
  struct _atexit _atexit0;
  void (**(_sig_func))(int);
  struct _glue __sglue;
  struct __sFILE __sf[3];
};
extern struct _reent *_impure_ptr ;
void _reclaim_reent (struct _reent *);
typedef struct
{
  int quot;
  int rem;
} div_t;
typedef struct
{
  long quot;
  long rem;
} ldiv_t;
extern int __mb_cur_max;
void abort (void) ;
int abs (int);
int atexit (void (*__func)(void));
double atof (const char *__nptr);
float atoff (const char *__nptr);
int atoi (const char *__nptr);
long atol (const char *__nptr);
void * bsearch (const void * __key, const void * __base, size_t __nmemb, size_t __size, int (*_compar) (const void *, const void *));
void * calloc (size_t __nmemb, size_t __size);
div_t div (int __numer, int __denom);
void exit (int __status) ;
void free (void *);
char * getenv (const char *__string);
long labs (long);
ldiv_t ldiv (long __numer, long __denom);
void * malloc (size_t __size);
int mblen (const char *, size_t);
int mbtowc (wchar_t *, const char *, size_t);
int _mbtowc_r (struct _reent *, wchar_t *, const char *, size_t, int *);
int wctomb (char *, wchar_t);
int _wctomb_r (struct _reent *, char *, wchar_t, int *);
size_t mbstowcs (wchar_t *, const char *, size_t);
size_t _mbstowcs_r (struct _reent *, wchar_t *, const char *, size_t, int *);
size_t wcstombs (char *, const wchar_t *, size_t);
size_t _wcstombs_r (struct _reent *, char *, const wchar_t *, size_t, int *);
void qsort (void * __base, size_t __nmemb, size_t __size, int(*_compar)(const void *, const void *));
int rand (void);
void * realloc (void * __r, size_t __size);
void srand (unsigned __seed);
double strtod (const char *__n, char **_end_PTR);
float strtodf (const char *__n, char **_end_PTR);
long strtol (const char *__n, char **_end_PTR, int __base);
unsigned long strtoul (const char *_n_PTR, char **_end_PTR, int __base);
unsigned long _strtoul_r (struct _reent *,const char *_n_PTR, char **_end_PTR, int __base);
int system (const char *__string);
void cfree (void *);
int putenv (const char *__string);
int setenv (const char *__string, const char *__value, int __overwrite);
char * gcvt (double,int,char *);
char * gcvtf (float,int,char *);
char * fcvt (double,int,int *,int *);
char * fcvtf (float,int,int *,int *);
char * ecvt (double,int,int *,int *);
char * ecvtbuf (double, int, int*, int*, char *);
char * fcvtbuf (double, int, int*, int*, char *);
char * ecvtf (float,int,int *,int *);
char * dtoa (double, int, int, int *, int*, char**);
int rand_r (unsigned *__seed);
char * _dtoa_r (struct _reent *, double, int, int, int *, int*, char**);
void * _malloc_r (struct _reent *, size_t);
void * _calloc_r (struct _reent *, size_t, size_t);
void _free_r (struct _reent *, void *);
void * _realloc_r (struct _reent *, void *, size_t);
void _mstats_r (struct _reent *, char *);
int _system_r (struct _reent *, const char *);
void __eprintf (const char *, const char *, unsigned int, const char *);
enum
{
    BLEND_EFFECT_NONE = 0,
    BLEND_EFFECT_ALPHA = 1,
    BLEND_EFFECT_BRIGHTEN = 2,
    BLEND_EFFECT_DARKEN = 3,
};
typedef signed char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long long int64_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef signed char int_least8_t;
typedef short int_least16_t;
typedef int int_least32_t;
typedef long long int_least64_t;
typedef unsigned char uint_least8_t;
typedef unsigned short uint_least16_t;
typedef unsigned int uint_least32_t;
typedef unsigned long long uint_least64_t;
typedef int int_fast8_t;
typedef int int_fast16_t;
typedef int int_fast32_t;
typedef long long int_fast64_t;
typedef unsigned int uint_fast8_t;
typedef unsigned int uint_fast16_t;
typedef unsigned int uint_fast32_t;
typedef unsigned long long uint_fast64_t;
typedef int intptr_t;
typedef unsigned int uintptr_t;
typedef long long intmax_t;
typedef unsigned long long uintmax_t;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;
typedef volatile u8 vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;
typedef volatile s8 vs8;
typedef volatile s16 vs16;
typedef volatile s32 vs32;
typedef volatile s64 vs64;
typedef float f32;
typedef double f64;
typedef u8 bool8;
typedef u16 bool16;
typedef u32 bool32;
struct PlttData
{
    u16 r:5;
    u16 g:5;
    u16 b:5;
    u16 unused_15:1;
} ;
struct OamData
{
             u32 y:8;
             u32 affineMode:2;
             u32 objMode:2;
             u32 mosaic:1;
             u32 bpp:1;
             u32 shape:2;
             u32 x:9;
             u32 matrixNum:5;
             u32 size:2;
             u16 tileNum:10;
             u16 priority:2;
             u16 paletteNum:4;
             u16 affineParam;
};
struct BgAffineSrcData
{
    s32 texX;
    s32 texY;
    s16 scrX;
    s16 scrY;
    s16 sx;
    s16 sy;
    u16 alpha;
};
struct BgAffineDstData
{
    s16 pa;
    s16 pb;
    s16 pc;
    s16 pd;
    s32 dx;
    s32 dy;
};
struct ObjAffineSrcData
{
    s16 xScale;
    s16 yScale;
    u16 rotation;
};
struct SioMultiCnt
{
    u16 baudRate:2;
    u16 si:1;
    u16 sd:1;
    u16 id:2;
    u16 error:1;
    u16 enable:1;
    u16 unused_11_8:4;
    u16 mode:2;
    u16 intrEnable:1;
    u16 unused_15:1;
    u16 data;
};
struct WaitCnt
{
    u16 sramWait:2;
    u16 rom0_1stAcc:2;
    u16 rom0_2ndAcc:1;
    u16 rom1_1stAcc:2;
    u16 rom1_2ndAcc:1;
    u16 rom2_1stAcc:2;
    u16 rom2_2ndAcc:1;
    u16 phiTerminalClock:2;
    u16 dummy:1;
    u16 prefetchBufEnable:1;
    u16 gamePakType:1;
};
struct MultiBootParam
{
    u32 system_work[5];
    u8 handshake_data;
    u8 padding;
    u16 handshake_timeout;
    u8 probe_count;
    u8 client_data[3];
    u8 palette_data;
    u8 response_bit;
    u8 client_bit;
    u8 reserved1;
    u8 *boot_srcp;
    u8 *boot_endp;
    u8 *masterp;
    u8 *reserved2[3];
    u32 system_work2[4];
    u8 sendflag;
    u8 probe_target_bit;
    u8 check_wait;
    u8 server_type;
};
void SoftReset(u32 resetFlags);
void SoundBiasReset(void);
void SoundBiasSet(void);
void RegisterRamReset(u32 resetFlags);
void VBlankIntrWait(void);
u16 Sqrt(u32 num);
u16 ArcTan2(s16 x, s16 y);
void CpuSet(const void *src, void *dest, u32 control);
void CpuFastSet(const void *src, void *dest, u32 control);
void BgAffineSet(struct BgAffineSrcData *src, struct BgAffineDstData *dest, s32 count);
void ObjAffineSet(struct ObjAffineSrcData *src, void *dest, s32 count, s32 offset);
void LZ77UnCompWram(const void *src, void *dest);
int Div(int, int);
int DivArm(int, int);
int DivRem(int, int);
void HuffUnComp(void const * src, void * dst);
void LZ77UnCompVram(const void *src, void *dest);
void RLUnCompWram(const void *src, void *dest);
void RLUnCompVram(const void *src, void *dest);
int MultiBoot(struct MultiBootParam *mp);
void AGBPrintInit(void);
void AGBPutc(const char cChr);
void AGBPrint(const char *pBuf);
void AGBPrintf(const char *pBuf, ...);
void AGBPrintFlush1Block(void);
void AGBPrintFlush(void);
void AGBAssert(const char *pFile, int nLine, const char *pExpression, int nStopProgram);
enum {
    BG_COLORDEPTH_4BPP = 0,
    BG_COLORDEPTH_8BPP = 1,
};
       
typedef s8 bool;
enum { false, true };
typedef void (* Func)(void);
typedef void * ProcPtr;
typedef void(* ProcFunc)(ProcPtr proc);
struct Vec2 { s16 x, y; };
struct Vec2u { u16 x, y; };
struct Vec4 { int x, y; };
enum glb_pos {
    POS_L = 0,
    POS_R = 1,
    POS_INVALID = -1
};
enum facing_idx {
    FACING_LEFT = 0,
    FACING_RIGHT = 1,
    FACING_DOWN = 2,
    FACING_UP = 3,
};
struct BattleAnimDef {
    u16 wtype;
    u16 index;
};
struct ProcCmd;
struct SMSHandle;
struct Unit;
struct UnitDefinition;
struct BattleHit;
struct SupportBonuses;
struct BmBgxConf;
       
struct unk_type_0203A50C {
    u8 unk00;
    u8 unk01;
    u8 unk02;
};
       
int GetPlayerLeaderUnitId(void);
int GetItemIndex(int item);
void UnitHideIfUnderRoof(struct Unit * unit);
void CharStoreAI(struct Unit * unit, const struct UnitDefinition * uDef);
int GetAutoleveledStatIncrease(int growth, int levelCount);
int GetCurrentPromotedLevelBonus(void);
int GetStatIncrease(int growth);
void ClearUnitSupports(struct Unit * unit);
void sub_802A21C(void);
void PidStatsAddMove(u8 pid, int amount);
void PidStatsSubFavval08(u8 pid);
void BeginTargetList(int x, int y);
void EnlistTarget(int x, int y, int uid, int extra);
void RenderMap(void);
void RenderMapForFade(void);
void RefreshEntityMaps(void);
void StartMapFade(bool locksGame);
void RefreshUnitSprites(void);
void sub_807B32C(void);
void sub_80799E4(void);
char * DecodeMsg(int id);
void EnableAllLightRunes(void);
void DisableAllLightRunes(void);
void PidStatsRecordBattleRes(void);
void PidStatsAddBattleAmt(struct Unit * unit);
int GetBallistaItemAt(int xPos, int yPos);
int GetUnitSupportBonuses(struct Unit * unit, struct SupportBonuses * bonuses);
bool sub_8028620(struct Unit * unit);
void PidStatsAddExpGained(u8 pid, int expGain);
int GetMapChangeIdAt(int x, int y);
void StartBattleManim(void);
void WriteSuspendSave(int slot);
void StartBgmVolumeChange(int volume_from, int volume_to, int duration, ProcPtr parent);
void FadeBgmOut(int volume);
void PutUiHand(int x, int y);
void DisplayBmTextShadow(int x, int y);
void TryLockParentProc(ProcPtr);
void TryUnlockParentProc(ProcPtr);
void nullsub_38(void);
void DecayTraps(void);
int GetTextPrintDelay();
int IsFirstPlaythrough(void);
void InitPlayConfig(int);
void StartBattleMap( );
void ResumeChapterFromSuspend( );
void CleanupUnitsBeforeChapter(void);
void sub_802EB7C( );
void sub_802EBA0( );
char *GetTacticianName();
void SetTacticianName(const char *name);
struct ChapterEventGroup * GetChapterEventInfo(u32);
void sub_8032CCC(void);
bool sub_8032CDC(void);
void sub_8032CF4(ProcPtr proc, const char *str);
void LoadHelpBoxGfx(void * vram, int palId);
void PutSpriteTalkBox(int x, int y, int w, int h, int unk);
void StartHelpBoxTextInit(int msg, int item);
void ClearHelpBoxText(void);
void SetDialogueBoxConfig(int a);
void StartBoxDialogueExt(int x, int y, int msgId, u16* unkA, int unkB, ProcPtr parent);
bool sub_80886E0(void);
int GetSupportScreenUnitCount(void);
int GetPreviousSupportScreenUnit(int num);
int GetSupportScreenPartnerSupportLevel(int idx, int partner);
int GetSupportScreenPartnerClassId(int idx, int partner);
bool GetSupportScreenPartnerIsAlive(int idx, int partner);
int GetSupportScreenPartnerCharId(int idx, int partner);
int GetSupportScreenCharIdAt(int);
int GetSupportScreenClassIdAt(int idx);
int GetSupportClassForCharId(int charId);
int GetTotalSupportLevel(int idx);
int GetSupportScreenPartnerCount(int charId);
void sub_80B0170(ProcPtr parent, int);
void sub_80B0EBC(ProcPtr parent, int);
int sub_80B10D4(int, int);
void ComputeChapterRankings(void);
void sub_80B7980(u16 *, int, int, int, int);
void sub_80B9C0C( );
void sub_80BAAB8( );
       
       
struct Proc;
struct ProcCmd {
    short opcode;
    short dataImm;
    const void * dataPtr;
};
struct Proc {
             const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             int x, y;
             int unk34;
             int unk38;
             int unk3C;
             int unk40;
             u8 pad38[0x4A - 0x44];
             short unk4A;
             short unk4C;
             short unk4E;
             short unk50;
             u16 unk52;
             void * ptr;
             int unk58;
             int unk5C;
             int unk60;
             short unk64;
             short unk66;
             short unk68;
             short unk6A;
};
struct ProcFindIterator {
             struct Proc * proc;
             const struct ProcCmd * script;
             int count;
};
extern struct Proc * gProcTreeRootArray[8];
void Proc_Init(void);
ProcPtr Proc_Start(const struct ProcCmd * script, ProcPtr parent);
ProcPtr Proc_StartBlocking(const struct ProcCmd * script, ProcPtr parent);
void Proc_End(ProcPtr proc);
void Proc_Run(ProcPtr proc);
void Proc_Break(ProcPtr proc);
ProcPtr Proc_Find(const struct ProcCmd * script);
void Proc_Goto(ProcPtr proc, int label);
void Proc_GotoScript(ProcPtr proc, const struct ProcCmd * script);
void Proc_SetMark(ProcPtr proc, int mark);
void Proc_SetEndCb(ProcPtr proc, ProcFunc func);
void Proc_ForAll(ProcFunc func);
void Proc_ForEach(const struct ProcCmd * script, ProcFunc func);
void Proc_ForEachMarked(int mark, ProcFunc func);
void Proc_BlockEachMarked(int mark);
void Proc_UnblockEachMarked(int mark);
void Proc_EndEachMarked(int mark);
void Proc_EndEach(const struct ProcCmd * script);
void Proc_BreakEach(const struct ProcCmd * script);
void Proc_SetRepeatCb(ProcPtr proc, ProcFunc func);
ProcPtr Proc_FindAfter(struct ProcCmd * script, struct Proc * proc);
struct Proc * Proc_FindAfterWithParent(struct Proc * proc, struct Proc * parent);
int CountProcs(const struct ProcCmd * script);
void Proc_FindBegin(struct ProcFindIterator * it, const struct ProcCmd * script);
ProcPtr Proc_FindNext(struct ProcFindIterator * it);
struct WaveData
{
    u16 type;
    u16 status;
    u32 freq;
    u32 loopStart;
    u32 size;
    s8 data[1];
};
struct ToneData
{
    u8 type;
    u8 key;
    u8 length;
    u8 pan_sweep;
    struct WaveData *wav;
    u8 attack;
    u8 decay;
    u8 sustain;
    u8 release;
};
struct CgbChannel
{
    u8 sf;
    u8 ty;
    u8 rightVolume;
    u8 leftVolume;
    u8 at;
    u8 de;
    u8 su;
    u8 re;
    u8 ky;
    u8 ev;
    u8 eg;
    u8 ec;
    u8 echoVolume;
    u8 echoLength;
    u8 d1;
    u8 d2;
    u8 gt;
    u8 mk;
    u8 ve;
    u8 pr;
    u8 rp;
    u8 d3[3];
    u8 d5;
    u8 sg;
    u8 n4;
    u8 pan;
    u8 panMask;
    u8 mo;
    u8 le;
    u8 sw;
    u32 fr;
    u32 *wp;
    u32 cp;
    u32 tp;
    u32 pp;
    u32 np;
    u8 d4[8];
};
struct MusicPlayerTrack;
struct SoundChannel
{
    u8 status;
    u8 type;
    u8 rightVolume;
    u8 leftVolume;
    u8 attack;
    u8 decay;
    u8 sustain;
    u8 release;
    u8 ky;
    u8 ev;
    u8 er;
    u8 el;
    u8 echoVolume;
    u8 echoLength;
    u8 d1;
    u8 d2;
    u8 gt;
    u8 mk;
    u8 ve;
    u8 pr;
    u8 rp;
    u8 d3[3];
    u32 ct;
    u32 fw;
    u32 freq;
    struct WaveData *wav;
    u32 cp;
    struct MusicPlayerTrack *track;
    u32 pp;
    u32 np;
    u32 d4;
    u16 xpi;
    u16 xpc;
};
struct SoundInfo
{
    u32 ident;
    vu8 pcmDmaCounter;
    u8 reverb;
    u8 maxChans;
    u8 masterVolume;
    u8 freq;
    u8 mode;
    u8 c15;
    u8 pcmDmaPeriod;
    u8 maxLines;
    u8 gap[3];
    s32 pcmSamplesPerVBlank;
    s32 pcmFreq;
    s32 divFreq;
    struct CgbChannel *cgbChans;
    u32 func;
    u32 intp;
    void (*CgbSound)(void);
    void (*CgbOscOff)(u8);
    u32 (*MidiKeyToCgbFreq)(u8, u8, u8);
    u32 MPlayJumpTable;
    u32 plynote;
    u32 ExtVolPit;
    u8 gap2[16];
    struct SoundChannel chans[12];
    s8 pcmBuffer[1584 * 2];
};
struct SongHeader
{
    u8 trackCount;
    u8 blockCount;
    u8 priority;
    u8 reverb;
    struct ToneData *tone;
    u8 *part[1];
};
struct PokemonCrySong
{
    u8 trackCount;
    u8 blockCount;
    u8 priority;
    u8 reverb;
    struct ToneData *tone;
    u8 *part[2];
    u8 gap;
    u8 part0;
    u8 tuneValue;
    u8 gotoCmd;
    u32 gotoTarget;
    u8 part1;
    u8 tuneValue2;
    u8 cont[2];
    u8 volCmd;
    u8 volumeValue;
    u8 unkCmd0D[2];
    u32 unkCmd0DParam;
    u8 xreleCmd[2];
    u8 releaseValue;
    u8 panCmd;
    u8 panValue;
    u8 tieCmd;
    u8 tieKeyValue;
    u8 tieVelocityValue;
    u8 unkCmd0C[2];
    u16 unkCmd0CParam;
    u8 end[2];
};
struct MusicPlayerTrack
{
    u8 flags;
    u8 wait;
    u8 patternLevel;
    u8 repN;
    u8 gateTime;
    u8 key;
    u8 velocity;
    u8 runningStatus;
    u8 keyM;
    u8 pitM;
    s8 keyShift;
    s8 keyShiftX;
    s8 tune;
    u8 pitX;
    s8 bend;
    u8 bendRange;
    u8 volMR;
    u8 volML;
    u8 vol;
    u8 volX;
    s8 pan;
    s8 panX;
    s8 modM;
    u8 mod;
    u8 modT;
    u8 lfoSpeed;
    u8 lfoSpeedC;
    u8 lfoDelay;
    u8 lfoDelayC;
    u8 priority;
    u8 echoVolume;
    u8 echoLength;
    struct SoundChannel *chan;
    struct ToneData tone;
    u8 gap[10];
    u16 unk_3A;
    u32 unk_3C;
    u8 *cmdPtr;
    u8 *patternStack[3];
};
struct MusicPlayerInfo
{
    struct SongHeader *songHeader;
    u32 status;
    u8 trackCount;
    u8 priority;
    u8 cmd;
    u8 unk_B;
    u32 clock;
    u8 gap[8];
    u8 *memAccArea;
    u16 tempoD;
    u16 tempoU;
    u16 tempoI;
    u16 tempoC;
    u16 fadeOI;
    u16 fadeOC;
    u16 fadeOV;
    struct MusicPlayerTrack *tracks;
    struct ToneData *tone;
    u32 ident;
    u32 func;
    u32 intp;
};
struct MusicPlayer
{
    struct MusicPlayerInfo *info;
    struct MusicPlayerTrack *track;
    u8 unk_8;
    u16 unk_A;
};
struct Song
{
    struct SongHeader *header;
    u16 ms;
    u16 me;
};
extern const struct MusicPlayer gMPlayTable[];
extern const struct Song gSongTable[];
extern u8 gMPlayMemAccArea[];
extern struct PokemonCrySong gPokemonCrySong;
extern struct PokemonCrySong gPokemonCrySongs[];
extern struct MusicPlayerInfo gPokemonCryMusicPlayers[];
extern struct MusicPlayerTrack gPokemonCryTracks[];
extern char SoundMainRAM[];
extern void *gMPlayJumpTable[];
typedef void (*XcmdFunc)(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
extern const XcmdFunc gXcmdTable[];
extern struct CgbChannel gCgbChans[];
extern const u8 gScaleTable[];
extern const u32 gFreqTable[];
extern const u16 gPcmSamplesPerVBlankTable[];
extern const u8 gCgbScaleTable[];
extern const s16 gCgbFreqTable[];
extern const u8 gNoiseTable[];
extern const struct PokemonCrySong gPokemonCrySongTemplate;
extern const struct ToneData voicegroup_pokemon_cry;
extern char gNumMusicPlayers[];
extern char gMaxLines[];
u32 umul3232H32(u32 multiplier, u32 multiplicand);
void SoundMain(void);
void SoundMainBTM(void);
void TrackStop(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track);
void MPlayMain(void);
void RealClearChain(void *x);
void MPlayContinue(struct MusicPlayerInfo *mplayInfo);
void MPlayStart(struct MusicPlayerInfo *mplayInfo, struct SongHeader *songHeader);
void m4aMPlayStop(struct MusicPlayerInfo *mplayInfo);
void FadeOutBody(struct MusicPlayerInfo *mplayInfo);
void TrkVolPitSet(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track);
void MPlayFadeOut(struct MusicPlayerInfo *mplayInfo, u16 speed);
void ClearChain(void *x);
void Clear64byte(void *addr);
void SoundInit(struct SoundInfo *soundInfo);
void MPlayExtender(struct CgbChannel *cgbChans);
void m4aSoundMode(u32 mode);
void MPlayOpen(struct MusicPlayerInfo *mplayInfo, struct MusicPlayerTrack *track, u8 a3);
void CgbSound(void);
void CgbOscOff(u8);
u32 MidiKeyToCgbFreq(u8, u8, u8);
void DummyFunc(void);
void MPlayJumpTableCopy(void **mplayJumpTable);
void SampleFreqSet(u32 freq);
void m4aSoundVSyncOn(void);
void m4aSoundVSyncOff(void);
void MPlayVolumeControl(struct MusicPlayerInfo * mplayInfo, u16 trackBits, u16 volume);
void ClearModM(struct MusicPlayerTrack *track);
void m4aMPlayModDepthSet(struct MusicPlayerInfo *mplayInfo, u16 trackBits, u8 modDepth);
void m4aMPlayLFOSpeedSet(struct MusicPlayerInfo *mplayInfo, u16 trackBits, u8 lfoSpeed);
struct MusicPlayerInfo *SetPokemonCryTone(struct ToneData *tone);
void SetPokemonCryVolume(u8 val);
void SetPokemonCryPanpot(s8 val);
void SetPokemonCryPitch(s16 val);
void SetPokemonCryLength(u16 val);
void SetPokemonCryRelease(u8 val);
void SetPokemonCryProgress(u32 val);
int IsPokemonCryPlaying(struct MusicPlayerInfo *mplayInfo);
void SetPokemonCryChorus(s8 val);
void SetPokemonCryStereo(u32 val);
void SetPokemonCryPriority(u8 val);
void ply_fine(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_goto(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_patt(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_pend(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_rept(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_memacc(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_prio(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_tempo(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_keysh(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_voice(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_vol(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_pan(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_bend(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_bendr(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_lfos(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_lfodl(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_mod(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_modt(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_tune(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_port(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_xcmd(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_endtie(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_note(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_xxx(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_xwave(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_xtype(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_xatta(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_xdeca(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_xsust(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_xrele(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_xiecv(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_xiecl(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_xleng(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_xswee(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_xcmd_0C(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
void ply_xcmd_0D(struct MusicPlayerInfo *, struct MusicPlayerTrack *);
extern struct MusicPlayerInfo gUnk_03005A30;
extern struct MusicPlayerInfo gUnk_03005CC0;
extern  u16 * gManimScanlineBufs[2];
extern s8 MoveTable_Flying[];
extern s8 MoveTable_Ballista[];
extern char const *StatusNameStringLut[];
extern int TacticianAffins[12][4];
extern u8 gArenaLevelBackup;
extern struct unk_type_0203A50C gUnk_0203A50C;
extern u8 Img_DragonsGate[];
extern u8 Tsa_DragonsGate[];
extern u16 Pal_DragonsGate[];
extern u8 Img_NilsInDragonsGate[];
extern u8 Tsa_NilsInDragonsGate[];
extern u16 Pal_NilsInDragonsGate[];
extern u8 Gfx_MiscUiGraphics[];
extern u16 Pal_MiscUiGraphics[];
extern u8 Img_UiCursorHandTop[];
extern u8 Img_UiCursorHandBottom[];
extern u16 Pal_Text[];
extern u16 Pal_08190268[];
extern u16 gUnk_081902A8[];
extern u16 gUnk_081902C8[];
extern const u8 Tsa_Unk_081911D4[];
extern const u8 Tsa_Unk_0819128C[];
extern u8 Img_DragonFlameSmallFire[];
extern u16 Pal_DragonFlameSmallFire[];
extern u16 SpriteConf_DragonFlameSmallFire[];
extern u8 Img_EventSnowStormfx[];
extern u16 Pal_EventSnowStormfx[];
extern u8 Tsa_EventSnowStormfx[];
extern u16 Pal_IceBmBgfx_08199A94[];
extern u8 Img_IceBmBgfx_08199AB4[];
extern u8 Img_IceBmBgfx_0819A6A4[];
extern u8 Tsa_IceBmBgfx_0819B11C[];
extern u8 Tsa_IceBmBgfx_0819B620[];
extern u8 Tsa_IceBmBgfx_0819BB24[];
extern u8 Tsa_IceBmBgfx_0819C028[];
extern u8 Tsa_IceBmBgfx_0819C52C[];
extern u8 Tsa_IceBmBgfx_0819CA30[];
extern u8 Tsa_IceBmBgfx_0819CF34[];
extern u8 Img_IceBmBgfx_0819D438[];
extern u8 Img_IceBmBgfx_0819E1EC[];
extern u8 Tsa_IceBmBgfx_0819EEF4[];
extern u8 Tsa_IceBmBgfx_0819F3F8[];
extern u8 Img_IceBmBgfx_0819F8FC[];
extern u8 Img_IceBmBgfx_081A07D4[];
extern u8 Tsa_IceBmBgfx_081A0AF8[];
extern u8 Img_IceBmBgfx_081A0FFC[];
extern u8 Img_IceBmBgfx_081A1F0C[];
extern u8 Tsa_IceBmBgfx_081A2374[];
extern u8 Img_IceBmBgfx_081A2878[];
extern u8 Img_IceBmBgfx_081A376C[];
extern u8 Tsa_IceBmBgfx_081A3D2C[];
extern u8 Img_IceBmBgfx_081A4230[];
extern u8 Img_IceBmBgfx_081A5144[];
extern u8 Tsa_IceBmBgfx_081A5708[];
extern u8 Img_FlameBreathfx[];
extern u16 Pal_FlameBreathfx[];
extern u8 Tsa_FlameBreathfxR[];
extern u8 Tsa_FlameBreathfxL[];
extern u16 Pal_EventThunderfx[];
extern u8 Img_EventThunderfx1[];
extern u8 Img_EventThunderfx2[];
extern u8 Tsa_EventThunderfx1[];
extern u8 Tsa_EventThunderfx2[];
extern u8 Tsa_EventThunderfx3[];
extern u8 Tsa_EventThunderfx4[];
extern u8 Tsa_EventThunderfx5[];
extern u8 Tsa_EventThunderfx6[];
extern u8 Tsa_EventThunderfx7[];
extern u8 Img_EventThunderfx3[];
extern u8 Img_EventThunderfx4[];
extern u8 Tsa_EventThunderfx8[];
extern u8 Tsa_EventThunderfx9[];
extern u8 Tsa_EventThunderfx10[];
extern u8 Tsa_EventThunderfx11[];
extern u8 Img_NinianDispfx[];
extern u16 Pal_NinianDispfx[];
extern u16 SpritAnim_NinianDispfx[];
extern u16 SpritAnim_NinianPray[];
extern u8 gUnk_081AD68C[];
extern u8 gUnk_081AD6AC[];
extern u8 gUnk_081ADE60[];
extern u8 gUnk_081AE528[];
extern u8 gUnk_081AE64C[];
extern u8 gUnk_081AE770[];
extern u8 gUnk_081AE894[];
extern u8 gUnk_081AE9B8[];
extern u8 gUnk_081AEADC[];
extern u8 gUnk_081AEC00[];
extern u8 gUnk_081AED24[];
extern u8 gUnk_081AF718[];
extern u8 gUnk_081B0044[];
extern u8 gUnk_081B0168[];
extern u8 gUnk_081B028C[];
extern u8 gUnk_081B03B0[];
extern u8 gUnk_081B04D4[];
extern u8 gUnk_081B05F8[];
extern u8 gUnk_081B10CC[];
extern u8 gUnk_081B1660[];
extern u8 gUnk_081B1784[];
extern u8 gUnk_081B18A8[];
extern u8 gUnk_081B19CC[];
extern u8 gUnk_081B23C8[];
extern u8 gUnk_081B2AD8[];
extern u8 gUnk_081B2BFC[];
extern u8 gUnk_081B2D20[];
extern u8 gUnk_081B2E44[];
extern u8 gUnk_081B36D8[];
extern u8 gUnk_081B3A88[];
extern u8 gUnk_081B3BAC[];
extern u8 gUnk_081B3CD0[];
extern u8 FireRingBgfx_081B3DF4[];
extern u8 FireRingBgfx_081B3E14[];
extern u8 FireRingBgfx_081B43E4[];
extern u8 FireRingBgfx_081B4730[];
extern u8 FireRingBgfx_081B498C[];
extern u8 FireRingBgfx_081B4BE8[];
extern u8 FireRingBgfx_081B4E44[];
extern u8 FireRingBgfx_081B5438[];
extern u8 FireRingBgfx_081B55F4[];
extern u8 FireRingBgfx_081B5850[];
extern u8 FireRingBgfx_081B5E5C[];
extern u8 FireRingBgfx_081B61F4[];
extern u8 FireRingBgfx_081B6450[];
extern u8 FireRingBgfx_081B6A28[];
extern u8 FireRingBgfx_081B6E08[];
extern u8 FireRingBgfx_081B7064[];
extern u8 FireRingBgfx_081B756C[];
extern u8 FireRingBgfx_081B7B88[];
extern u8 FireRingBgfx_081B7DE4[];
extern u8 FireRingBgfx_081B8418[];
extern u8 FireRingBgfx_081B8A84[];
extern u8 FireRingBgfx_081B8CE0[];
extern u8 FireRingBgfx_081B9300[];
extern u8 FireRingBgfx_081B9878[];
extern u8 FireRingBgfx_081B9AD4[];
extern u8 FireRingBgfx_081BA110[];
extern u8 FireRingBgfx_081BA730[];
extern u8 FireRingBgfx_081BA98C[];
extern u8 FireRingBgfx_081BAF4C[];
extern u8 FireRingBgfx_081BB494[];
extern u8 FireRingBgfx_081BB6F0[];
extern u8 FireRingBgfx_081BBD10[];
extern u8 FireRingBgfx_081BC1F0[];
extern u8 FireRingBgfx_081BC44C[];
extern u8 FireRingBgfx_081BC99C[];
extern u8 FireRingBgfx_081BCEF0[];
extern u8 Img_DragonGateFlame[];
extern u16 Pal_DragonGateFlame[];
extern u8 Tsa_DragonGateFlame[];
extern u16 Pal_QuintessenceFx[];
extern u8 Tsa_QuintessenceFx[];
extern u8 Img_DanceringFx[];
extern u8 Tsa_DanceringFx[];
extern u16 Pal_DanceringFx[];
extern u8 Img_SwingSword[];
extern u16 Pal_SwingSword[];
extern u8 Tsa_SwingSword[];
extern u8 Img_DragonGateLight[];
extern u16 Pal_DragonGateLight[];
extern u16 gUnk_081C0A70[];
extern u8 Tsa_DragonGateLight[];
extern u8 Img_DragonGateDragon[];
extern u16 Pal_DragonGateDragon[];
extern u8 Tsa_DragonGateDragon[];
extern u8 Img_NinianReturnToHuman[];
extern u8 Img_EventDragonsSpritefx1[];
extern u16 gUnk_081C5020[];
extern u8 Img_EventDragonsSpritefx2[];
extern u16 gUnk_081C673C[];
extern u8 Img_DragonFlameImpact[];
extern u16 Pal_DragonFlameImpact[];
extern u8 Tsa_DragonFlameImpact[];
extern u8 Img_EventSpriteAnim_SpawnAssassin[];
extern u8 Img_EventSpriteAnim_SpawnThief[];
extern u16 ApConf_EventSpriteAnim_SpawnAssassin[];
extern u8 Img_MineFx[];
extern u16 SpritAnim_MineFx[];
extern u16 Pal_MineFx[];
extern u8 Img_OneYearLater[];
extern u16 Pal_OneYearLater[];
extern u8 Tsa_OneYearLater[];
extern u16 Pal_SaveMenuBackground[];
extern u8 Tsa_SaveMenuBackground[];
extern u8 Img_SpinRotation[];
extern u8 Tsa_SpinRotation[];
extern u8 Img_SaveMenuSprits[];
extern u16 Pal_SaveMenuWindow[];
extern u16 Pal_Unk_08432694[];
extern u8 Img_ModeSelect_Sprites[];
extern u16 Pal_08434448[];
extern u8 Tsa_ModeSelect_Menu[];
extern u8 Img_ModeSelect_Menu[];
extern u16 Pal_ModeSelect_Menu[];
extern u8 Tsa_084352FC[];
extern u16 Pal_ModeSelect_Sprites[];
extern u16 Pal_TactInfoBg[];
extern u8 Img_TactInfoBg[];
extern u8 Tsa_TactInfoBg[];
extern u8 Img_MuralBackground[];
extern u16 Pal_MuralBackground[];
extern u8 Img_CandleFlame[];
extern u16 Pal_CandleFlame[];
extern u8 Tsa_CandleFlame[];
extern u16 gUnk_08453438[];
extern u16 gUnk_08453538[];
extern u16 gUnk_0857E570[];
extern u16 gUnk_08583EE4[];
extern u16 Pal_TitleFlameIdle[];
extern u8 FireRingBgfx_08662514[];
extern u8 FireRingBgfx_08662534[];
extern u8 FireRingBgfx_08663250[];
extern u8 FireRingBgfx_086634AC[];
extern u8 FireRingBgfx_08663708[];
extern u8 FireRingBgfx_08663964[];
extern u8 FireRingBgfx_08664310[];
extern u8 FireRingBgfx_0866456C[];
extern u8 FireRingBgfx_08664EEC[];
extern u8 FireRingBgfx_086652B0[];
extern u8 FireRingBgfx_0866550C[];
extern u8 FireRingBgfx_08665E8C[];
extern u8 FireRingBgfx_08666250[];
extern u8 FireRingBgfx_086664AC[];
extern u8 FireRingBgfx_08666EBC[];
extern u8 FireRingBgfx_08667480[];
extern u8 FireRingBgfx_086676DC[];
extern u8 FireRingBgfx_08668208[];
extern u8 FireRingBgfx_086688C8[];
extern u8 FireRingBgfx_08668B24[];
extern u8 FireRingBgfx_086696FC[];
extern u8 FireRingBgfx_08669D70[];
extern u8 FireRingBgfx_08669FCC[];
extern u8 FireRingBgfx_0866ABE4[];
extern u8 FireRingBgfx_0866B1B4[];
extern u8 FireRingBgfx_0866B410[];
extern u8 FireRingBgfx_0866C04C[];
extern u8 FireRingBgfx_0866C4F4[];
extern u8 FireRingBgfx_0866C750[];
extern u8 FireRingBgfx_0866D3C8[];
extern u8 FireRingBgfx_0866D7DC[];
extern u8 FireRingBgfx_0866DA38[];
extern u8 FireRingBgfx_0866E674[];
extern u8 FireRingBgfx_0866E99C[];
extern u8 FireRingBgfx_0866EBF8[];
extern u8 FireRingBgfx_0866F854[];
extern u8 FireRingBgfx_0866FA8C[];
extern u8 FireRingBgfx_0866FCE8[];
extern u8 FireRingBgfx_08670888[];
extern u8 FireRingBgfx_08670968[];
extern u8 FireRingBgfx_08670BC4[];
extern u8 FireRingBgfx_086716C8[];
extern u8 FireRingBgfx_086716E4[];
extern u8 FireRingBgfx_08671940[];
extern u8 FireRingBgfx_08672388[];
extern u8 FireRingBgfx_08672CA0[];
extern u8 FireRingBgfx_08672EFC[];
extern u8 FireRingBgfx_08673158[];
extern u8 FireRingBgfx_08673AB4[];
extern u8 FireRingBgfx_08673B18[];
extern u8 FireRingBgfx_08673D74[];
extern u8 FireRingBgfx_086746A8[];
extern u8 FireRingBgfx_086747C8[];
extern u8 FireRingBgfx_08674A24[];
extern u8 FireRingBgfx_0867535C[];
extern u8 FireRingBgfx_08675518[];
extern u8 FireRingBgfx_08675774[];
extern u8 FireRingBgfx_08676108[];
extern u8 FireRingBgfx_08676350[];
extern u8 FireRingBgfx_086765AC[];
extern u8 FireRingBgfx_08676F54[];
extern u8 FireRingBgfx_086773BC[];
extern u8 FireRingBgfx_08677618[];
extern u8 FireRingBgfx_08678074[];
extern u8 FireRingBgfx_086788DC[];
extern u8 FireRingBgfx_08678B38[];
extern u8 FireRingBgfx_08679624[];
extern u8 FireRingBgfx_0867A2C4[];
extern u8 FireRingBgfx_0867A520[];
extern u8 FireRingBgfx_0867B168[];
extern u8 FireRingBgfx_0867C22C[];
extern u8 FireRingBgfx_0867C488[];
extern u8 FireRingBgfx_0867D1F8[];
extern u8 FireRingBgfx_0867E310[];
extern u8 FireRingBgfx_0867E56C[];
extern u8 FireRingBgfx_0867F310[];
extern u8 FireRingBgfx_0868033C[];
extern u8 FireRingBgfx_08680598[];
extern u8 FireRingBgfx_086812B4[];
extern u8 FireRingBgfx_0868218C[];
extern u8 FireRingBgfx_086823E8[];
extern u8 FireRingBgfx_086830C0[];
extern u8 FireRingBgfx_08683F14[];
extern u8 FireRingBgfx_08684170[];
extern u8 FireRingBgfx_08684E58[];
extern u8 FireRingBgfx_08685CE4[];
extern u8 FireRingBgfx_08685F40[];
extern u8 FireRingBgfx_08686C4C[];
extern u8 FireRingBgfx_08687BB4[];
extern u8 FireRingBgfx_08687E10[];
extern u8 FireRingBgfx_08688B80[];
extern u8 FireRingBgfx_08689BB0[];
extern u8 FireRingBgfx_08689E0C[];
extern u8 FireRingBgfx_0868ABD0[];
extern u8 FireRingBgfx_0868BC9C[];
extern u8 FireRingBgfx_0868BEF8[];
extern u8 FireRingBgfx_0868CCF8[];
extern u8 FireRingBgfx_0868DE68[];
extern u8 FireRingBgfx_0868E0C4[];
extern u8 FireRingBgfx_0868EEA8[];
extern u8 FireRingBgfx_0869008C[];
extern u8 FireRingBgfx_086902E8[];
extern u8 FireRingBgfx_08691064[];
extern u8 FireRingBgfx_086922A0[];
extern u8 FireRingBgfx_086924FC[];
extern u8 FireRingBgfx_08693298[];
extern u8 FireRingBgfx_08694528[];
extern u8 FireRingBgfx_08694784[];
extern u8 FireRingBgfx_0869542C[];
extern u8 FireRingBgfx_08696528[];
extern u8 FireRingBgfx_08696784[];
extern u8 FireRingBgfx_086973A4[];
extern u8 FireRingBgfx_08698394[];
extern u8 FireRingBgfx_086985F0[];
extern u8 FireRingBgfx_08699098[];
extern u8 FireRingBgfx_08699DF0[];
extern u8 FireRingBgfx_0869A04C[];
extern u8 FireRingBgfx_0869A960[];
extern u8 FireRingBgfx_0869B4F0[];
extern u8 FireRingBgfx_0869B74C[];
extern u8 FireRingBgfx_0869BF1C[];
extern u8 FireRingBgfx_0869C850[];
extern u8 OpBmBgfx_0869CAAC[];
extern u8 OpBmBgfx_0869CACC[];
extern u8 OpBmBgfx_0869D408[];
extern u8 OpBmBgfx_0869DDD0[];
extern u8 OpBmBgfx_0869E284[];
extern u8 OpBmBgfx_0869EAE4[];
extern u8 OpBmBgfx_0869F3EC[];
extern u8 OpBmBgfx_0869F8A0[];
extern u8 OpBmBgfx_086A0168[];
extern u8 OpBmBgfx_086A09B4[];
extern u8 OpBmBgfx_086A0E68[];
extern u8 OpBmBgfx_086A16E4[];
extern u8 OpBmBgfx_086A1F74[];
extern u8 OpBmBgfx_086A2428[];
extern u8 OpBmBgfx_086A2CEC[];
extern u8 OpBmBgfx_086A35B0[];
extern u8 OpBmBgfx_086A3A64[];
extern u8 OpBmBgfx_086A436C[];
extern u8 OpBmBgfx_086A4C68[];
extern u16 gUnk_086A511C[];
extern u8 OpBmBgfx_086A515C[];
extern u8 OpBmBgfx_086A715C[];
extern u8 OpBmBgfx_086A915C[];
extern u8 OpBmBgfx_086A9610[];
extern u8 OpBmBgfx_086AB610[];
extern u8 OpBmBgfx_086AD610[];
extern u8 OpBmBgfx_086ADAC4[];
extern u8 OpBmBgfx_086AFAC4[];
extern u8 OpBmBgfx_086B16A4[];
extern u8 OpBmBgfx_086B1B58[];
extern u8 OpBmBgfx_086B3B58[];
extern u8 OpBmBgfx_086B4274[];
extern u8 OpBmBgfx_086B4728[];
extern u8 OpBmBgfx_086B4FA4[];
extern u8 OpBmBgfx_086B5444[];
extern u8 OpBmBgfx_086B58F8[];
extern u8 OpBmBgfx_086B5CE0[];
extern u8 OpBmBgfx_086B6054[];
extern u8 OpBmBgfx_086B6508[];
extern u8 OpBmBgfx_086B69BC[];
extern u16 Pal_TitleTextShadow[];
extern u8 Img_TitleTextShadow[];
extern u8 Tsa_TitleTextShadow[];
extern u16 Pal_TitleBg[];
extern u8 Img_TitleBg[];
extern u8 Tsa_TitleBg[];
extern u16 Pal_TitleAxe[];
extern u8 Img_TitleAxe[];
extern u8 Tsa_TitleAxe[];
extern u16 Pal_TitleSprites[];
extern u8 Img_TitleSprites[];
extern u16 SpirteAnim_TitleText[];
extern u16 Pal_TitleTextFlame[];
extern u8 Img_TitleTextFlame[];
extern u8 Tsa_TitleTextFlame[];
extern const u16 Pal_SwingSwordfxBg[];
extern u16 Pal_LinkArenaMuralBackground[];
extern u16 Pal_UiWindowFrame1[];
extern u8 Img_SysGrayBox[];
extern u8 TsaConf_BanimTmA1[];
extern u8 TsaConf_BanimTmA2[];
extern u8 TsaConf_BanimTmA3[];
extern u8 TsaConf_BanimTmA4[];
extern const u16 FrameLut_EfxDrsmmoya[];
extern u16 Tsa_EfxDrsmmoyaBgRight1[];
extern u16 Tsa_EfxDrsmmoyaBgRight2[];
extern u16 Tsa_EfxDrsmmoyaBgRight3[];
extern u16 Tsa_EfxDrsmmoyaBgRight4[];
extern const u16 Pal_EfxDrsmmoyaBg[];
extern u16 Tsa_EfxDrsmmoyaBgLeft1[];
extern u16 Tsa_EfxDrsmmoyaBgLeft2[];
extern u16 Tsa_EfxDrsmmoyaBgLeft3[];
extern u16 Tsa_EfxDrsmmoyaBgLeft4[];
extern u16 Tsa_EfxDrsmmoyaBgLeft5[];
extern u16 Tsa_EfxDrsmmoyaBgLeft6[];
extern u16 Tsa_EfxDrsmmoyaBgLeft7[];
extern u16 Tsa_EfxDrsmmoyaBgLeft8[];
extern u16 Tsa_EfxDrsmmoyaBgLeft9[];
extern u16 Tsa_EfxDrsmmoyaBgLeft10[];
extern u16 Tsa_EfxDrsmmoyaBgLeft11[];
extern u16 Tsa_EfxDrsmmoyaBgLeft12[];
extern u16 Tsa_EfxDrsmmoyaBgLeft13[];
extern const u16 FrameLut_EkrDragonWingFlashingNormalAtk[];
extern const u16 FrameLut_EkrDragonWingFlashingCriticalAtk[];
extern const u16 FrameLut_EkrDragonFlashingWingObjNormalAtk[];
extern const u16 FrameLut_EkrDragonFlashingWingObjCriticalAtk[];
extern const u16 FrameLut_EkrDragon_082E4418[];
extern const u16 FrameLut_EkrDragon_082E441E[];
extern const u16 FrameLut_EkrDragon_082E4430[];
extern const u16 FrameLut_EkrDragon_082E4442[];
extern const u8 Img_EkrDragon_082E445C[];
extern const u8 Tsa_EkrDragon_DragonTail[];
extern const u8 Tsa_EkrDragon_MainBg[];
extern const u8 Tsa_EkrDragon_082E7170[];
extern const u8 Tsa_EkrDragon_082E7418[];
extern const u8 Img_EkrDragonTunkFace[];
extern const u8 Img_EkrDragonBark[];
extern const u8 Img_EfxDragonDeadFallHead[];
extern const u16 Pal_EkrDragonHead[];
extern const u16 Pals_EkrDragonFlashingWingObj[];
extern const u8 Img_EkrDragonFireBg3[];
extern const u16 Pal_EkrDragonFireBg3[];
extern const u8 Tsa_EkrDragonFireBg3[];
extern const u8 Img_EkrDragonFireBG2[];
extern const u8 Tsa_EkrDragonFireBG2[];
extern u8 const gUnk_084027B0[];
extern u8 const gUnk_08402858[];
extern u8 const gUnk_084028FC[];
extern u8 const gUnk_08402958[];
extern u8 const gUnk_084029AC[];
extern u8 const gUnk_084029FC[];
extern u16 gUnk_08402A4C[];
extern const u8 Tsa_StatScreen_0840349C[];
extern const u8 Tsa_StatScreenPage0[];
extern const u8 Tsa_Statscreen_Pag1_08403560[];
extern const u8 Tsa_StatScreen_084035D0[];
extern const u16 Pal_StatScreenFaceDefault[];
extern const u16 Pal_StatScreenFaceGeneric[];
extern const u8 Img_StatScreen_0840368C[];
extern const u8 Img_StatScreen_08403730[];
extern const u16 Pal_StatScreen_084038AC[];
extern const u8 Tsa_Statscreen_Pag1_084038CC[];
extern const u8 Tsa_Statscreen_Pag1_08403908[];
extern const u8 Img_StatScreen_0840392C[];
extern u16 const Pals_StatScreen_Title[][0x20];
extern const u8 Tsa_Statscreen_08404124[];
extern const u8 Tsa_StatScreen_0840417C[];
extern u16 Pal_08404D90[];
extern u16 Pal_08404ED0[];
extern u8 Img_ChapterIntroMotif[];
extern u8 Tm_ChapterIntroMotif[];
extern u16 Pal_ChapterIntroMotif[];
extern u8 Img_ChapterIntroFog[];
extern u16 Pal_ChapterIntroFog[];
extern u8 Img_ChapterTitleBG[];
extern u8 Img_ChapterTitle_084086C4[];
extern u8 Tsa_ChapterTitle_08408BD4[];
extern u16 Pal_08408CC8[];
extern const u8 Img_TitleName_084090A4[];
extern const u8 Img_TitleName_08409464[];
extern const u8 Img_TitleName_084097C4[];
extern const u8 Img_TitleName_08409B1C[];
extern const u8 Img_TitleName_08409EF0[];
extern const u8 Img_TitleName_0840A280[];
extern const u8 Img_TitleName_0840A634[];
extern const u8 Img_TitleName_0840A9B0[];
extern const u8 Img_TitleName_0840AD04[];
extern const u8 Img_TitleName_0840B084[];
extern const u8 Img_TitleName_0840B3D8[];
extern const u8 Img_TitleName_0840B748[];
extern const u8 Img_TitleName_0840BB4C[];
extern const u8 Img_TitleName_0840BEBC[];
extern const u8 Img_TitleName_0840C230[];
extern const u8 Img_TitleName_0840C61C[];
extern const u8 Img_TitleName_0840CA8C[];
extern const u8 Img_TitleName_0840CE98[];
extern const u8 Img_TitleName_0840D290[];
extern const u8 Img_TitleName_0840D5F0[];
extern const u8 Img_TitleName_0840DA24[];
extern const u8 Img_TitleName_0840DD5C[];
extern const u8 Img_TitleName_0840E050[];
extern const u8 Img_TitleName_0840E4E0[];
extern const u8 Img_TitleName_0840E7B8[];
extern const u8 Img_TitleName_0840EC00[];
extern const u8 Img_TitleName_0840EF0C[];
extern const u8 Img_TitleName_0840F2E4[];
extern const u8 Img_TitleName_0840F768[];
extern const u8 Img_TitleName_0840FB00[];
extern const u8 Img_TitleName_0840FE98[];
extern const u8 Img_TitleName_08410384[];
extern const u8 Img_TitleName_0841071C[];
extern const u8 Img_TitleName_08410AB4[];
extern const u8 Img_TitleName_08410F38[];
extern const u8 Img_TitleName_084113A8[];
extern const u8 Img_TitleName_08411770[];
extern const u8 Img_TitleName_08411AE8[];
extern const u8 Img_TitleName_08411EE8[];
extern const u8 Img_TitleName_0841230C[];
extern const u8 Img_TitleName_084126B8[];
extern const u8 Img_TitleName_08412928[];
extern const u8 Img_TitleName_08412D04[];
extern const u8 Img_TitleName_0841305C[];
extern const u8 Img_TitleName_08413448[];
extern const u8 Img_TitleName_084138B8[];
extern const u8 Img_TitleName_08413CC4[];
extern const u8 Img_TitleName_084140E4[];
extern const u8 Img_TitleName_084144F0[];
extern const u8 Img_TitleName_0841485C[];
extern const u8 Img_TitleName_08414C74[];
extern const u8 Img_TitleName_08414FA8[];
extern const u8 Img_TitleName_084152A4[];
extern const u8 Img_TitleName_0841571C[];
extern const u8 Img_TitleName_08415B20[];
extern const u8 Img_TitleName_08415DF4[];
extern const u8 Img_TitleName_0841621C[];
extern const u8 Img_TitleName_0841653C[];
extern const u8 Img_TitleName_0841691C[];
extern const u8 Img_TitleName_08416D8C[];
extern const u8 Img_TitleName_08417104[];
extern const u8 Img_TitleName_0841747C[];
extern const u8 Img_TitleName_084177F4[];
extern const u8 Img_TitleName_08417CE0[];
extern const u8 Img_TitleName_0841805C[];
extern const u8 Img_TitleName_084183D8[];
extern const u8 Img_TitleName_08418860[];
extern const u8 Img_TitleName_08418CDC[];
extern const u8 Img_TitleName_08419094[];
extern const u8 Img_TitleName_084194A4[];
extern const u8 Img_TitleName_08419890[];
extern const u8 Img_TitleName_08419C8C[];
extern const u8 Img_TitleName_0841A038[];
extern const u8 Img_TitleName_0841A454[];
extern const u8 Img_TitleName_0841A6C4[];
extern const u8 Img_TitleName_0841A964[];
extern const u8 Img_TitleName_0841AB8C[];
extern u8 Img_SysBlackBox[];
extern u16 Pal_0841D100[];
extern u8 Img_0841D120[];
extern u8 Tsa_0841D614[];
extern u8 Img_MenuScrollBar[];
extern u16 Pal_MenuScrollBar[];
extern u8 Img_PrepScreenTitle[];
extern u16 Pal_SysBrownBox[];
extern u16 SpriteAnim_0841ECD0[];
extern u8 Img_PrepWindow[];
extern u16 Pal_0841F774[];
extern u16 Pal_0841F814[];
extern u16 Pal_0841F8B4[];
extern u16 Pal_0841F954[];
extern u8 TSA_0842162C[];
extern u8 TSA_08421644[];
extern u8 TSA_08421684[];
extern u8 Img_PrepMuralBackground[];
extern u16 TsaConfig_PrepMuralBackground[];
extern u16 Pal_PrepMuralBackground[];
extern u16 Pal_08428A80[];
extern u8 Img_PrepAtMenuUpfx[];
extern u16 Pal_PrepAtMenuUpfx[];
extern u16 Pal_PrepScreenTitleSprites[];
extern u8 Img_PrepTextShadow[];
extern u8 Img_PrepScreenTitleSprites[];
extern u8 Img_SysBrownBox[];
extern struct ProcCmd ProcScr_PlayerPhase[];
extern struct ProcCmd ProcScr_08C02920[];
extern struct ProcCmd ProcScr_BmMain_08C02A68[];
extern struct ProcCmd ProcScr_ChapterIntro_Bg3Scroll[];
extern struct ProcCmd ProcScr_ChapterIntroDeamon[];
extern struct ProcCmd ProcScr_ChapterIntrofx[];
extern struct ProcCmd ProcScr_BmMain_08C02D98[];
extern struct ProcCmd ProcScr_DanceringAnim[];
extern struct ProcCmd ProcScr_EventWrapAnim[];
extern struct ProcCmd ProcScr_MineFx[];
extern struct ProcCmd ProcScr_NinianTransformToHunman[];
extern struct ProcCmd ProcScr_UpdateTraps[];
extern struct ProcCmd ProcScr_SALLYCURSOR[];
extern struct ProcCmd ProcScr_BmMain_08C05E68[];
extern struct ProcCmd ProcScr_BmMain_08C05EC8[];
extern struct ProcCmd ProcScr_BmMain_08C05F30[];
extern struct ProcCmd ProcScr_AiPhase[];
extern struct ProcCmd ProcScr_08C0617C[];
extern struct ProcCmd ProcScr_MixPalette[];
extern struct ProcCmd ProcScr_StartWorldMapEvent[];
extern struct ProcCmd ProcScr_Unk_08DB7EB0[];
extern struct ProcCmd ProcScr_Unk_08DB8048[];
extern struct ProcCmd ProcScr_Unk_08DB8088[];
       
enum {
    TERRAIN_TILE_00 = 0x00,
    TERRAIN_PLAINS = 0x01,
    TERRAIN_ROAD = 0x02,
    TERRAIN_VILLAGE = 0x03,
    TERRAIN_VILLAGE_CLOSED = 0x04,
    TERRAIN_HOUSE = 0x05,
    TERRAIN_ARMORY = 0x06,
    TERRAIN_VENDOR = 0x07,
    TERRAIN_ARENA_08 = 0x08,
    TERRAIN_C_ROOM_09 = 0x09,
    TERRAIN_FORT = 0x0A,
    TERRAIN_GATE_0B = 0x0B,
    TERRAIN_FOREST = 0x0C,
    TERRAIN_THICKET = 0x0D,
    TERRAIN_SAND = 0x0E,
    TERRAIN_DESERT = 0x0F,
    TERRAIN_RIVER = 0x10,
    TERRAIN_MOUNTAIN = 0x11,
    TERRAIN_PEAK = 0x12,
    TERRAIN_BRIDGE = 0x13,
    TERRAIN_DRAWBRIDGE = 0x14,
    TERRAIN_SEA = 0x15,
    TERRAIN_LAKE = 0x16,
    TERRAIN_FLOOR_17 = 0x17,
    TERRAIN_FLOOR_18 = 0x18,
    TERRAIN_FENCE_19 = 0x19,
    TERRAIN_WALL = 0x1A,
    TERRAIN_WALL_BREAKABLE = 0x1B,
    TERRAIN_RUBBLE = 0x1C,
    TERRAIN_PILLAR = 0x1D,
    TERRAIN_DOOR = 0x1E,
    TERRAIN_THRONE = 0x1F,
    TERRAIN_CHEST_OPENED = 0x20,
    TERRAIN_CHEST = 0x21,
    TERRAIN_ROOF = 0x22,
    TERRAIN_GATE_23 = 0x23,
    TERRAIN_CHURCH = 0x24,
    TERRAIN_RUINS = 0x25,
    TERRAIN_CLIFF = 0x26,
    TERRAIN_BALLISTA = 0x27,
    TERRAIN_LONGBALLISTA = 0x28,
    TERRAIN_KILLERBALLISTA = 0x29,
    TERRAIN_SHIP_FLAT = 0x2A,
    TERRAIN_SHIP_WRECK = 0x2B,
    TERRAIN_TILE_2C = 0x2C,
    TERRAIN_STAIRS = 0x2D,
    TERRAIN_TILE_2E = 0x2E,
    TERRAIN_GLACIER = 0x2F,
    TERRAIN_ARENA_30 = 0x30,
    TERRAIN_VALLEY = 0x31,
    TERRAIN_FENCE_32 = 0x32,
    TERRAIN_SNAG = 0x33,
    TERRAIN_COUNT,
};
       
enum {
    ITEM_NONE = 0x00,
    ITEM_SWORD_IRON = 0x01,
    ITEM_SWORD_SLIM = 0x02,
    ITEM_SWORD_STEEL = 0x03,
    ITEM_SWORD_SILVER = 0x04,
    ITEM_BLADE_IRON = 0x05,
    ITEM_BLADE_STEEL = 0x06,
    ITEM_BLADE_SILVER = 0x07,
    ITEM_SWORD_VENIN = 0x08,
    ITEM_SWORD_RAPIER = 0x09,
    ITEM_SWORD_MKATTI = 0x0A,
    ITEM_SWORD_BRAVE = 0x0B,
    ITEM_SWORD_SHAMSIR = 0x0C,
    ITEM_SWORD_KILLER = 0x0D,
    ITEM_SWORD_ARMORSLAYER = 0x0E,
    ITEM_SWORD_WYRMSLAYER = 0x0F,
    ITEM_SWORD_LIGHTBRAND = 0x10,
    ITEM_SWORD_RUNESWORD = 0x11,
    ITEM_SWORD_LANCEREAVER = 0x12,
    ITEM_SWORD_ZANBATO = 0x13,
    ITEM_LANCE_IRON = 0x14,
    ITEM_LANCE_SLIM = 0x15,
    ITEM_LANCE_STEEL = 0x16,
    ITEM_LANCE_SILVER = 0x17,
    ITEM_LANCE_VENIN = 0x18,
    ITEM_LANCE_BRAVE = 0x19,
    ITEM_LANCE_KILLER = 0x1A,
    ITEM_LANCE_HORSESLAYER = 0x1B,
    ITEM_LANCE_JAVELIN = 0x1C,
    ITEM_LANCE_SPEAR = 0x1D,
    ITEM_LANCE_AXEREAVER = 0x1E,
    ITEM_AXE_IRON = 0x1F,
    ITEM_AXE_STEEL = 0x20,
    ITEM_AXE_SILVER = 0x21,
    ITEM_AXE_VENIN = 0x22,
    ITEM_AXE_BRAVE = 0x23,
    ITEM_AXE_KILLER = 0x24,
    ITEM_AXE_HALBERD = 0x25,
    ITEM_AXE_HAMMER = 0x26,
    ITEM_AXE_DEVIL = 0x27,
    ITEM_AXE_HANDAXE = 0x28,
    ITEM_AXE_TOMAHAWK = 0x29,
    ITEM_AXE_SWORDREAVER = 0x2A,
    ITEM_AXE_SWORDSLAYER = 0x2B,
    ITEM_BOW_IRON = 0x2C,
    ITEM_BOW_STEEL = 0x2D,
    ITEM_BOW_SILVER = 0x2E,
    ITEM_BOW_VENIN = 0x2F,
    ITEM_BOW_KILLER = 0x30,
    ITEM_BOW_BRAVE = 0x31,
    ITEM_BOW_SHORTBOW = 0x32,
    ITEM_BOW_LONGBOW = 0x33,
    ITEM_BALLISTA_REGULAR = 0x34,
    ITEM_BALLISTA_LONG = 0x35,
    ITEM_BALLISTA_KILLER = 0x36,
    ITEM_ANIMA_FIRE = 0x37,
    ITEM_ANIMA_THUNDER = 0x38,
    ITEM_ANIMA_ELFIRE = 0x39,
    ITEM_ANIMA_BOLTING = 0x3A,
    ITEM_ANIMA_FIMBULVETR = 0x3B,
    ITEM_ANIMA_FORBLAZE = 0x3C,
    ITEM_ANIMA_EXCALIBUR = 0x3D,
    ITEM_LIGHT_LIGHTNING = 0x3E,
    ITEM_LIGHT_SHINE = 0x3F,
    ITEM_LIGHT_DIVINE = 0x40,
    ITEM_LIGHT_PURGE = 0x41,
    ITEM_LIGHT_AURA = 0x42,
    ITEM_LIGHT_LUCE = 0x43,
    ITEM_DARK_FLUX = 0x44,
    ITEM_DARK_LUNA = 0x45,
    ITEM_DARK_NOSFERATU = 0x46,
    ITEM_DARK_ECLIPSE = 0x47,
    ITEM_DARK_FENRIR = 0x48,
    ITEM_DARK_GLEIPNIR = 0x49,
    ITEM_STAFF_HEAL = 0x4A,
    ITEM_STAFF_MEND = 0x4B,
    ITEM_STAFF_RECOVER = 0x4C,
    ITEM_STAFF_PHYSIC = 0x4D,
    ITEM_STAFF_FORTIFY = 0x4E,
    ITEM_STAFF_RESTORE = 0x4F,
    ITEM_STAFF_SILENCE = 0x50,
    ITEM_STAFF_SLEEP = 0x51,
    ITEM_STAFF_BERSERK = 0x52,
    ITEM_STAFF_WARP = 0x53,
    ITEM_STAFF_RESCUE = 0x54,
    ITEM_STAFF_TORCH = 0x55,
    ITEM_STAFF_REPAIR = 0x56,
    ITEM_STAFF_UNLOCK = 0x57,
    ITEM_STAFF_BARRIER = 0x58,
    ITEM_AXE_DRAGON = 0x59,
    ITEM_BOOSTER_HP = 0x5A,
    ITEM_BOOSTER_POW = 0x5B,
    ITEM_BOOSTER_SKL = 0x5C,
    ITEM_BOOSTER_SPD = 0x5D,
    ITEM_BOOSTER_LCK = 0x5E,
    ITEM_BOOSTER_DEF = 0x5F,
    ITEM_BOOSTER_RES = 0x60,
    ITEM_BOOSTER_MOV = 0x61,
    ITEM_BOOSTER_CON = 0x62,
    ITEM_HEROCREST = 0x63,
    ITEM_KNIGHTCREST = 0x64,
    ITEM_ORIONSBOLT = 0x65,
    ITEM_ELYSIANWHIP = 0x66,
    ITEM_GUIDINGRING = 0x67,
    ITEM_CHESTKEY = 0x68,
    ITEM_DOORKEY = 0x69,
    ITEM_LOCKPICK = 0x6A,
    ITEM_VULNERARY = 0x6B,
    ITEM_ELIXIR = 0x6C,
    ITEM_PUREWATER = 0x6D,
    ITEM_ANTITOXIN = 0x6E,
    ITEM_TORCH = 0x6F,
    ITEM_DELPHISHIELD = 0x70,
    ITEM_MEMBERCARD = 0x71,
    ITEM_SILVERCARD = 0x72,
    ITEM_WHITEGEM = 0x73,
    ITEM_BLUEGEM = 0x74,
    ITEM_REDGEM = 0x75,
    ITEM_GOLD = 0x76,
    ITEM_LANCE_REGINLEIF = 0x77,
    ITEM_CHESTKEY_BUNDLE = 0x78,
    ITEM_MINE = 0x79,
    ITEM_LIGHTRUNE = 0x7A,
    ITEM_HOPLON_SHIELD = 0x7B,
    ITEM_FILLAS_MIGHT = 0x7C,
    ITEM_NINISS_GRACE = 0x7D,
    ITEM_THORS_IRE = 0x7E,
    ITEM_SETS_LITANY = 0x7F,
    ITEM_EMBLEM_BLADE = 0x80,
    ITEM_EMBLEM_LANCE = 0x81,
    ITEM_EMBLEM_AXE = 0x82,
    ITEM_EMBLEM_BOW = 0x83,
    ITEM_SWORD_DURANDAL = 0x84,
    ITEM_AXE_ARMADS = 0x85,
    ITEM_LIGHT_AUREOLA = 0x86,
    ITEM_EARTH_SEAL = 0x87,
    ITEM_AFAS_DROPS = 0x88,
    ITEM_HEAVEN_SEAL = 0x89,
    ITEM_EMBLEM_SEAL = 0x8A,
    ITEM_FELL_CONTRACT = 0x8B,
    ITEM_SWORD_SOL_KATTI = 0x8C,
    ITEM_AXE_WOLF_BEIL = 0x8D,
    ITEM_DARK_ERESHKIGAL = 0x8E,
    ITEM_ANIMA_FLAMETONGUE = 0x8F,
    ITEM_SWORD_REGAL_BLADE = 0x90,
    ITEM_LANCE_REX_HASTA = 0x91,
    ITEM_AXE_BASILIKOS = 0x92,
    ITEM_BOW_RIENFLECHE = 0x93,
    ITEM_LANCE_HEAVYSPEAR = 0x94,
    ITEM_LANCE_SHORTSPEAR = 0x95,
    ITEM_OCEANSEAL = 0x96,
    ITEM_3000G = 0x97,
    ITEM_5000G = 0x98,
    ITEM_SWORD_WINDSWORD = 0x99,
    ITEM_VULNERARY_2 = 0x9A,
    ITEM_VULNERARY_3 = 0x9B,
    ITEM_VULNERARY_4 = 0x9C,
    ITEM_DANCE = 0x9D,
    ITEM_PLAY = 0x9E
};
       
enum
{
    CHAPTER_00 = 0x00,
    CHAPTER_01 = 0x01,
    CHAPTER_02 = 0x02,
    CHAPTER_03 = 0x03,
    CHAPTER_04 = 0x04,
    CHAPTER_05 = 0x05,
    CHAPTER_06 = 0x06,
    CHAPTER_07 = 0x07,
    CHAPTER_08 = 0x08,
    CHAPTER_09 = 0x09,
    CHAPTER_0A = 0x0A,
    CHAPTER_0B = 0x0B,
    CHAPTER_0C = 0x0C,
    CHAPTER_0D = 0x0D,
    CHAPTER_0E = 0x0E,
    CHAPTER_0F = 0x0F,
    CHAPTER_10 = 0x10,
    CHAPTER_11 = 0x11,
    CHAPTER_12 = 0x12,
    CHAPTER_13 = 0x13,
    CHAPTER_14 = 0x14,
    CHAPTER_15 = 0x15,
    CHAPTER_16 = 0x16,
    CHAPTER_17 = 0x17,
    CHAPTER_18 = 0x18,
    CHAPTER_19 = 0x19,
    CHAPTER_1A = 0x1A,
    CHAPTER_1B = 0x1B,
    CHAPTER_1C = 0x1C,
    CHAPTER_1D = 0x1D,
    CHAPTER_1E = 0x1E,
    CHAPTER_1F = 0x1F,
    CHAPTER_20 = 0x20,
    CHAPTER_21 = 0x21,
    CHAPTER_22 = 0x22,
    CHAPTER_23 = 0x23,
    CHAPTER_24 = 0x24,
    CHAPTER_25 = 0x25,
    CHAPTER_26 = 0x26,
    CHAPTER_27 = 0x27,
    CHAPTER_28 = 0x28,
    CHAPTER_29 = 0x29,
    CHAPTER_2A = 0x2A,
    CHAPTER_2B = 0x2B,
    CHAPTER_2C = 0x2C,
    CHAPTER_2D = 0x2D,
    CHAPTER_2E = 0x2E,
    CHAPTER_2F = 0x2F,
};
       
enum pid_defs {
    CHARACTER_ELIWOOD = 0x01,
    CHARACTER_HECTOR = 0x02,
    CHARACTER_LYN_TUTORIAL = 0x03,
    CHARACTER_DORCAS = 0x08,
    CHARACTER_OSWIN = 0x0B,
    CHARACTER_SERRA = 0x11,
    CHARACTER_ERK = 0x13,
    CHARACTER_NINO = 0x14,
    CHARACTER_HAWKEYE = 0x22,
    CHARACTER_MATTHEW = 0x23,
    CHARACTER_NILS = 0x26,
    CHARACTER_ATHOS = 0x27,
    CHARACTER_MERLINUS = 0x28,
    CHARACTER_LYN = 0x2D,
    CHARACTER_RATH = 0x32,
    CHARACTER_FIREDRAGON = 0x86,
    CHARACTER_DA = 0xDA,
    CHARACTER_WALL = 0xFC,
    CHARACTER_SNAG = 0xFD,
};
       
enum jid_defs {
    CLASS_OBSTACLE = 1,
    CLASS_ARCHER = 0x18,
    CLASS_ARCHER_F = 0x19,
    CLASS_SNIPER = 0x1A,
    CLASS_SNIPER_F = 0x1B,
    CLASS_ARCHSAGE = 0x42,
};
       
enum {
    BGPAL_TEXT_DEFAULT = 0,
    BGPAL_WINDOWFRAME = 1,
    BGPAL_TALK = 2,
    BGPAL_TALK_BUBBLE = 3,
    BGPAL_ICONS = 4,
    BGPAL_TILESET = 6,
    BGPAL_BM_0 = 0,
    BGPAL_BM_15 = 15,
    BGPAL_UI_STATBAR = 6,
    BGPAL_STATSCREEN_6 = 6,
    BGPAL_MURALBACKGROUND = 14,
    STATSCREEN_BGPAL_HALO = 1,
    STATSCREEN_BGPAL_2 = 2,
    STATSCREEN_BGPAL_3 = 3,
    STATSCREEN_BGPAL_ITEMICONS = 4,
    STATSCREEN_BGPAL_EXTICONS = 5,
    STATSCREEN_BGPAL_6 = 6,
    STATSCREEN_BGPAL_7 = 7,
    STATSCREEN_BGPAL_FACE = 11,
    STATSCREEN_BGPAL_BACKGROUND = 12,
    BGPAL_STATSCREEN_EQUIPSTATFRAME = 7,
    BGPAL_STATSCREEN_FACE = 13,
};
enum {
    BGCHR_WINDOWFRAME = 0,
    BGCHR_STATSCREEN_EQUIPSTATFRAME = 0x60,
    BGCHR_STATSCREEN_FACE = 0xE0,
    BGCHR_STATSCREEN_BACKMURAL = 0x180,
    BGCHR_STATSCREEN_EQUIPMENTLABEL = 0x270,
    BGCHR_ICON_END = 0x300,
};
enum objchr_idx {
    OBCHR_SYSTEM_OBJECTS = 0x000,
    OBCHR_FACE_DEFAULT2 = 0x200,
    OBCHR_FACE_DEFAULT1 = 0x280,
    OBCHR_FACE_DEFAULT0 = 0x300,
    OBCHR_FACE_DEFAULT3 = 0x380,
    OBCHR_STATSCREEN_60 = 0x60,
    OBCHR_STATSCREEN_240 = 0x240,
};
enum objpal_idx {
    OBPAL_SYSTEM_OBJECTS = 0,
    OBPAL_FACE_DEFAULT0 = 6,
    OBPAL_FACE_DEFAULT1 = 7,
    OBPAL_FACE_DEFAULT2 = 8,
    OBPAL_FACE_DEFAULT3 = 9,
    OBPAL_STATSCREEN_WINDOWFRAME = 2,
    OBPAL_STATSCREEN_PAGENAME = 3,
    OBPAL_STATSCREEN_SPRITES = 4,
    OBPAL_STATSCREEN_10 = 10,
    OBPAL_MAPSPRITES = 12,
    OBPAL_UNITSPRITE_BLUE = OBPAL_MAPSPRITES + 0,
    OBPAL_UNITSPRITE_RED = OBPAL_MAPSPRITES + 1,
    OBPAL_UNITSPRITE_GREEN = OBPAL_MAPSPRITES + 2,
    OBPAL_UNITSPRITE_GRAY = OBPAL_MAPSPRITES + 3,
};
       
enum icon_index {
    ICON_NONE = -1,
    ICON_ITEM_KIND_BASE = 0x70,
    ICON_AFFINITY_BASE = 0x7A,
    ICON_AID_MOUNT = 0x81,
    ICON_AID_PEGASUS = 0x82,
    ICON_AID_WYVERN = 0x83,
};
       
enum
{
    SONG_01 = 0x01,
    SONG_02 = 0x02,
    SONG_03 = 0x03,
    SONG_04 = 0x04,
    SONG_05 = 0x05,
    SONG_06 = 0x06,
    SONG_09 = 0x09,
    SONG_0A = 0x0A,
    SONG_0C = 0x0C,
    SONG_0E = 0x0E,
    SONG_0F = 0x0F,
    SONG_11 = 0x11,
    SONG_12 = 0x12,
    SONG_13 = 0x13,
    SONG_14 = 0x14,
    SONG_22 = 0x22,
    SONG_23 = 0x23,
    SONG_24 = 0x24,
    SONG_25 = 0x25,
    SONG_26 = 0x26,
    SONG_27 = 0x27,
    SONG_28 = 0x28,
    SONG_29 = 0x29,
    SONG_2A = 0x2A,
    SONG_2B = 0x2B,
    SONG_2C = 0x2C,
    SONG_31 = 0x31,
    SONG_32 = 0x32,
    SONG_33 = 0x33,
    SONG_34 = 0x34,
    SONG_37 = 0x37,
    SONG_39 = 0x39,
    SONG_3B = 0x3B,
    SONG_3C = 0x3C,
    SONG_3D = 0x3D,
    SONG_3E = 0x3E,
    SONG_3F = 0x3F,
    SONG_43 = 0x43,
    SONG_44 = 0x44,
    SONG_45 = 0x45,
    SONG_46 = 0x46,
    SONG_47 = 0x47,
    SONG_5A = 0x5A,
    SONG_5B = 0x5B,
    SONG_5C = 0x5C,
    SONG_60 = 0x60,
    SONG_61 = 0x61,
    SONG_65 = 0x65,
    SONG_66 = 0x66,
    SONG_67 = 0x67,
    SONG_68 = 0x68,
    SONG_69 = 0x69,
    SONG_6A = 0x6A,
    SONG_6B = 0x6B,
    SONG_6C = 0x6C,
    SONG_6D = 0x6D,
    SONG_6E = 0x6E,
    SONG_6F = 0x6F,
    SONG_70 = 0x70,
    SONG_71 = 0x71,
    SONG_73 = 0x73,
    SONG_74 = 0x74,
    SONG_75 = 0x75,
    SONG_76 = 0x76,
    SONG_77 = 0x77,
    SONG_78 = 0x78,
    SONG_79 = 0x79,
    SONG_7A = 0x7A,
    SONG_7B = 0x7B,
    SONG_82 = 0x82,
    SONG_83 = 0x83,
    SONG_84 = 0x84,
    SONG_85 = 0x85,
    SONG_86 = 0x86,
    SONG_87 = 0x87,
    SONG_88 = 0x88,
    SONG_89 = 0x89,
    SONG_8A = 0x8A,
    SONG_8B = 0x8B,
    SONG_8C = 0x8C,
    SONG_8D = 0x8D,
    SONG_90 = 0x90,
    SONG_91 = 0x91,
    SONG_92 = 0x92,
    SONG_96 = 0x96,
    SONG_97 = 0x97,
    SONG_9A = 0x9A,
    SONG_9B = 0x9B,
    SONG_9C = 0x9C,
    SONG_A0 = 0xA0,
    SONG_A4 = 0xA4,
    SONG_A5 = 0xA5,
    SONG_A6 = 0xA6,
    SONG_A8 = 0xA8,
    SONG_A9 = 0xA9,
    SONG_AA = 0xAA,
    SONG_AB = 0xAB,
    SONG_AC = 0xAC,
    SONG_AF = 0xAF,
    SONG_B0 = 0xB0,
    SONG_B1 = 0xB1,
    SONG_B3 = 0xB3,
    SONG_B4 = 0xB4,
    SONG_B5 = 0xB5,
    SONG_B6 = 0xB6,
    SONG_B7 = 0xB7,
    SONG_B9 = 0xB9,
    SONG_BA = 0xBA,
    SONG_BB = 0xBB,
    SONG_BC = 0xBC,
    SONG_BD = 0xBD,
    SONG_BE = 0xBE,
    SONG_BF = 0xBF,
    SONG_C4 = 0xC4,
    SONG_C6 = 0xC6,
    SONG_C8 = 0xC8,
    SONG_C9 = 0xC9,
    SONG_CA = 0xCA,
    SONG_CB = 0xCB,
    SONG_CC = 0xCC,
    SONG_CD = 0xCD,
    SONG_CE = 0xCE,
    SONG_CF = 0xCF,
    SONG_D0 = 0xD0,
    SONG_D1 = 0xD1,
    SONG_D2 = 0xD2,
    SONG_D5 = 0xD5,
    SONG_D6 = 0xD6,
    SONG_D8 = 0xD8,
    SONG_E5 = 0xE5,
    SONG_EC = 0xEC,
    SONG_F8 = 0xF8,
    SONG_FD = 0xFD,
    SONG_10F = 0x10F,
    SONG_269 = 0x269,
    SONG_26A = 0x26A,
    SONG_385 = 0x385,
    SONG_38A = 0x38A,
};
       
extern u8 const ArmCodeStart[];
extern u8 const ArmCodeEnd[];
void ColorFadeTick(void);
void ClearOam(void * oam, int count);
u32 Checksum32(void const * buf, int size);
void TmApplyTsa(u16 * tm, u8 const * tsa, u16 tileref);
void TmCopyRect(u16 const * src, u16 * dst, int width, int height);
void TmFillRect(u16 * tm, int width, int height, u16 tileref);
void DrawGlyph(u16 const * cvtLut, void * chr, u32 const * glyph, int offset);
void DecodeString(char const * src, char * dst);
void PutOamHi(int x, int y, u16 const * oam_list, int oam2);
void PutOamLo(int x, int y, u16 const * oam_list, int oam2);
void MapFloodCoreStep(int connect, int x, int y);
void MapFloodCore(void);
void InitRamFuncs(void);
void DrawGlyphRam(u16 const * cvtLut, void * chr, u32 const * glyph, int offset);
void DecodeStringRam(char const * src, char * dst);
void PutOamHiRam(int x, int y, u16 const * oam_list, int oam2);
void PutOamLoRam(int x, int y, u16 const * oam_list, int oam2);
void MapFloodCoreStepRam(int connect, int x, int y);
void MapFloodCoreRam(void);
void ClearOam_thm(void * oam, int count);
void TmApplyTsa_thm(u16 * tm, u8 const * tsa, u16 tileref);
void TmFillRect_thm(u16 * tm, int width, int height, u16 tileref);
void ColorFadeTick_thm(void);
void TmCopyRect_thm(u16 const * src, u16 * dst, int width, int height);
u32 Checksum32_thm(void const * buf, int size);
       
enum times_amt {
    FRAMES_PER_SECOND = 60,
    FRAMES_PER_MINUTE = 60 * FRAMES_PER_SECOND,
    FRAMES_PER_HOUR = 60 * FRAMES_PER_MINUTE,
};
enum {
    OBJ_MAPPING_2D = 0,
    OBJ_MAPPING_1D = 1,
    BGCNT_SIZE_TXT256x256 = 0x0000 >> 14,
    BGCNT_SIZE_TXT512x256 = 0x4000 >> 14,
    BGCNT_SIZE_TXT256x512 = 0x8000 >> 14,
    BGCNT_SIZE_TXT512x512 = 0xC000 >> 14,
    BGCNT_SIZE_AFF128x128 = 0x0000 >> 14,
    BGCNT_SIZE_AFF256x256 = 0x4000 >> 14,
    BGCNT_SIZE_AFF512x512 = 0x8000 >> 14,
    BGCNT_SIZE_AFF1024x1024 = 0xC000 >> 14,
};
struct  DispCnt {
                 u16 mode : 3;
                 u16 : 1;
                 u16 bitmap_frame : 1;
                 u16 hblank_interval_free : 1;
                 u16 obj_mapping : 1;
                 u16 forced_blank : 1;
                 u16 bg0_enable : 1;
                 u16 bg1_enable : 1;
                 u16 bg2_enable : 1;
                 u16 bg3_enable : 1;
                 u16 obj_enable : 1;
                 u16 win0_enable : 1;
                 u16 win1_enable : 1;
                 u16 objwin_enable : 1;
};
struct  DispStat {
                 u16 vblank : 1;
                 u16 hblank : 1;
                 u16 vcount : 1;
                 u16 vblank_int_enable : 1;
                 u16 hblank_int_enable : 1;
                 u16 vcount_int_enable : 1;
                 u16 : 2;
                 u16 vcount_compare : 8;
};
struct  BgCnt {
                 u16 priority : 2;
                 u16 chr_block : 2;
                 u16 : 2;
                 u16 mosaic : 1;
                 u16 color_depth : 1;
                 u16 tm_block : 5;
                 u16 wrap : 1;
                 u16 size : 2;
};
struct  WinCnt {
    u8 win0_enable_bg0 : 1;
    u8 win0_enable_bg1 : 1;
    u8 win0_enable_bg2 : 1;
    u8 win0_enable_bg3 : 1;
    u8 win0_enable_obj : 1;
    u8 win0_enable_blend : 1;
    u8 : 2;
    u8 win1_enable_bg0 : 1;
    u8 win1_enable_bg1 : 1;
    u8 win1_enable_bg2 : 1;
    u8 win1_enable_bg3 : 1;
    u8 win1_enable_obj : 1;
    u8 win1_enable_blend : 1;
    u8 : 2;
    u8 wout_enable_bg0 : 1;
    u8 wout_enable_bg1 : 1;
    u8 wout_enable_bg2 : 1;
    u8 wout_enable_bg3 : 1;
    u8 wout_enable_obj : 1;
    u8 wout_enable_blend : 1;
    u8 : 2;
    u8 wobj_enable_bg0 : 1;
    u8 wobj_enable_bg1 : 1;
    u8 wobj_enable_bg2 : 1;
    u8 wobj_enable_bg3 : 1;
    u8 wobj_enable_obj : 1;
    u8 wobj_enable_blend : 1;
    u8 : 2;
};
struct  BlendCnt {
    u16 target1_enable_bg0 : 1;
    u16 target1_enable_bg1 : 1;
    u16 target1_enable_bg2 : 1;
    u16 target1_enable_bg3 : 1;
    u16 target1_enable_obj : 1;
    u16 target1_enable_bd : 1;
    u16 effect : 2;
    u16 target2_enable_bg0 : 1;
    u16 target2_enable_bg1 : 1;
    u16 target2_enable_bg2 : 1;
    u16 target2_enable_bg3 : 1;
    u16 target2_enable_obj : 1;
    u16 target2_enable_bd : 1;
};
struct DispIo {
             struct DispCnt disp_ct;
             struct DispStat disp_stat;
             unsigned char _pad_0x08[(0x0C) - (0x08)];
             struct BgCnt bg0_ct;
             struct BgCnt bg1_ct;
             struct BgCnt bg2_ct;
             struct BgCnt bg3_ct;
             struct Vec2u bg_off[4];
             u8 win0_right, win0_left, win1_right, win1_left;
             u8 win0_bottom, win0_top, win1_bottom, win1_top;
             struct WinCnt win_ct;
             u16 mosaic;
             unsigned char _pad_0x3A[(0x3C) - (0x3A)];
             struct BlendCnt blend_ct;
             unsigned char _pad_0x40[(0x44) - (0x40)];
             u8 blend_coef_a;
             u8 blend_coef_b;
             u8 blend_y;
             struct BgAffineDstData bg2affin;
             struct BgAffineDstData bg3affin;
             s8 color_addition;
};
struct KeySt {
             u8 repeat_delay;
             u8 repeat_interval;
             u8 repeat_clock;
             u16 held;
             u16 repeated;
             u16 pressed;
             u16 previous;
             u16 last;
             u16 ablr_pressed;
             u16 pressed2;
             u16 time_since_start_select;
};
enum bg_sync_bitfile {
    BG0_SYNC_BIT = (1 << 0),
    BG1_SYNC_BIT = (1 << 1),
    BG2_SYNC_BIT = (1 << 2),
    BG3_SYNC_BIT = (1 << 3),
};
enum bg_index {
    BG_0 = 0,
    BG_1,
    BG_2,
    BG_3,
    BG_INVALID = -1,
};
extern struct KeySt  * gpKeySt;
extern struct KeySt  gKeyStObj;
struct MoveStats {
             int count;
             int totalSize;
};
struct MoveEntry {
             void const *src;
             void *dest;
             u16 size;
             u16 mode;
};
extern struct MoveStats  gMoveStats;
extern struct MoveEntry  gMoveList[0x20];
enum data_move_mode {
    MOVE_MODE_COPY,
    MOVE_MODE_COPY_FAST,
    MOVE_MODE_FILL_FAST,
};
enum {
    BG_SIZE_256x256 = 0,
    BG_SIZE_512x256 = 1,
    BG_SIZE_256x512 = 2,
    BG_SIZE_512x512 = 3,
};
enum softreset_arg {
    GBA_RESET_EWRAM = 1 << 0,
    GBA_RESET_IWRAM = 1 << 1,
    GBA_RESET_PALETTE = 1 << 2,
    GBA_RESET_VRAM = 1 << 3,
    GBA_RESET_OAM = 1 << 4,
    GBA_RESET_SIO_IO = 1 << 5,
    GBA_RESET_SOUND_IO = 1 << 6,
    GBA_RESET_IO = 1 << 7,
    GBA_RESET_ALL = (1 << 8) - 1,
};
extern u8  gBuf[0x2100];
extern u16  gPal[0x200];
extern u16  gBg0Tm[0x400];
extern u16  gBg1Tm[0x400];
extern u16  gBg2Tm[0x400];
extern u16  gBg3Tm[0x400];
extern void * gBgMapVramTable[4];
extern Func  MainFunc;
extern struct DispIo gDispIo;
extern s16 gSinLut[0x40];
extern Func gOnHBlankA;
extern Func gOnHBlankB;
unsigned GetGameTime(void);
void SetGameTime(unsigned time);
void IncGameTime(void);
bool FormatTime(unsigned time, u16 * hours, u16 * minutes, u16 * seconds);
void EnableBgSync(int bits);
void EnableBgSyncById(int bgid);
void DisableBgSync(int bits);
void EnablePalSync(void);
void DisablePalSync(void);
void ApplyPaletteExt(void const * data, int startOffset, int size);
void SyncDispIo(void);
int GetBgChrOffset(int bg);
int GetBgChrId(int bg, int offset);
int GetBgTilemapOffset(int bg);
void SetBgChrOffset(int bg, int offset);
void SetBgTilemapOffset(int bg, int offset);
void SetBgScreenSize(int bg, int size);
void SetBgBpp(int bg, int bpp);
void SyncBgsAndPal(void);
void TmFill(u16 * dest, int tileref);
void SetBlankChr(int chr);
void SetOnVBlank(Func func);
void SetOnVMatch(Func func);
void SetNextVCount(int vcount);
void SetVCount(int vcount);
void SetMainFunc(Func func);
void RunMainFunc(void);
void RefreshKeySt(struct KeySt * keySt);
void ClearKeySt(struct KeySt * keySt);
void InitKeySt(struct KeySt * keySt);
void SetBgOffset(u16 bgid, u16 x_offset, u16 y_offset);
void sub_8001E6C(void);
void sub_8001EA0(u8 a, u8 b);
void sub_8001ED4(u16 *dst, u16 *src);
void sub_8001F14(void *tm, void const *in_data, u8 base, u8 linebits);
void sub_8001FF0(u16 * tm, short const * in_data, int unused);
void ColorFadeInit(void);
void sub_80020CC(u16 const * in_pal, int bank, int count, int unk);
void sub_80021F0(int a, int b, int c, int d);
void sub_8002310(int a, int b, int c);
void ColorFadeSetupFromColorToBlack(s8 component_step);
void ColorFadeSetupFromBlack(s8 component_step);
void ColorFadeSetupFromColorToWhite(s8 component_step);
void ColorFadeSetupFromWhite(s8 component_step);
void ColorFadeTick2(void);
void InitBgs(u16 const * config);
u16 * GetBgTilemap(int bg);
void SoftResetIfKeyCombo(void);
void sub_8002C24(int unk);
void SetOnHBlankA(Func func);
void SetOnHBlankB(Func func);
int GetBgFromPtr(u16 *ptr);
void RegisterDataMove(void const * src, void * dst, int size);
void RegisterDataFill(u32 value, void * dst, int size);
void ApplyDataMoves(void);
       
void ApplyUnitSpritePalettes(void);
void ResetUnitSprites(void);
void ResetUnitSpritesB(void);
int UseUnitSprite(u32 id);
int StartUiSMS(int smsId, int frameId);
void TornOutUnitSprite(struct Unit * unit, int timer);
void ForceSyncUnitSpriteSheet(void);
void RefreshUnitSprites(void);
void PutUnitSpritesOam(void);
void PutUnitSpriteIconsOam(void);
void UnitSpriteHoverUpdate(void);
void sub_80266DC(int layer, int x, int y, int jid);
void HideUnitSprite(struct Unit * unit);
void ShowUnitSprite(struct Unit * unit);
u8 GetUnitSpriteHiddenFlag(struct Unit * unit);
       
enum game_actions {
    GAME_ACTION_EVENT_RETURN = 0,
    GAME_ACTION_CLASS_REEL = 1,
    GAME_ACTION_USR_SKIPPED = 2,
    GAME_ACTION_PLAYED_THROUGH = 3,
    GAME_ACTION_4 = 4,
    GAME_ACTION_5 = 5,
    GAME_ACTION_6 = 6,
    GAME_ACTION_EXTRA_MAP = 7,
    GAME_ACTION_8 = 8,
    GAME_ACTION_9 = 9,
    GAME_ACTION_A = 0xA,
    GAME_ACTION_B = 0xB,
    GAME_ACTION_C = 0xC,
};
struct GameCtrlProc
{
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             u8 next_action;
             u8 next_chapter;
             u8 idle_status;
             u8 unk_2C;
             s16 unk_2E;
             u8 chapter_id;
};
void sub_8012D60(ProcPtr);
void SetNextGameAction(int action);
void SetNextChapterId(int chapter_id);
void ForceEnableSounds(void);
struct UnkSprite {
             int oam01;
             u16 oam2;
             short x;
             short y;
};
struct OamSection {
    u16 *buf;
    void *oam;
    u16 offset;
    u16 count;
};
struct OamView { u16 oam0, oam1, oam2, aff; };
extern u16 gOam[0x200];
extern u16 *gOamHiPutIt;
extern u16 *gOamLoPutIt;
extern struct OamView *gOamAffinePutIt;
extern u16 gOamAffinePutId;
void InitOam(int loSz);
int GetOamSplice(void);
void SyncHiOam(void);
void SyncLoOam(void);
void SetObjAffine(int id, short pa, short pb, short pc, short pd);
void PutUnkSprite(struct UnkSprite * sprites, int xBase, int yBase);
       
enum action_type {
    ACTION_NONE,
    ACTION_WAIT = 0x01,
    ACTION_COMBAT = 0x02,
    ACTION_STAFF = 0x03,
    ACTION_REFRESH = 0x04,
    ACTION_STEAL = 0x06,
    ACTION_RESCUE = 0x07,
    ACTION_DROP = 0x08,
    ACTION_TAKE = 0x09,
    ACTION_GIVE = 0x0A,
    ACTION_TALK = 0x0C,
    ACTION_SUPPORT = 0x0D,
    ACTION_VISIT = 0x0E,
    ACTION_SEIZE = 0x0F,
    ACTION_DOOR = 0x10,
    ACTION_CHEST = 0x12,
    ACTION_16 = 0x16,
    ACTION_USEITEM = 0x17,
    ACTION_TRADED = 0x18,
    ACTION_TRADED_SUPPLY = 0x19,
    ACTION_TRADED_NOCHANGES = 0x1A,
    ACTION_TRAPPED = 0x1B,
    ACTION_1C = 0x1C,
};
enum action_sus_type {
    SUSPEND_POINT_PLAYER_PHASE,
    SUSPEND_POINT_DURING_ACTION,
    SUSPEND_POINT_AI_PHASE,
    SUSPEND_POINT_BERSERK_PHASE,
    SUSPEND_POINT_DURING_ARENA,
    SUSPEND_POINT_5,
    SUSPEND_POINT_6,
    SUSPEND_POINT_7,
    SUSPEND_POINT_8,
    SUSPEND_POINT_CHANGE_PHASE,
};
struct Action {
             u16 action_rand_st[3];
             u16 arena_begin_rand_st[3];
             u8 instigator;
             u8 target;
             u8 x_move, y_move;
             u8 move_count;
             u8 id;
             u8 item_slot;
             u8 x_target, y_target;
             u8 extra;
             u8 suspend_point;
             struct BattleHit *battle_scr;
};
extern struct Action gActionSt;
       
struct Glyph {
    struct Glyph const *next;
    u8 sjis_byte_1;
    u8 width;
    u32 bitmap[16];
};
struct Text {
             u16 chr_position;
             u8 x;
             u8 color;
             u8 tile_width;
             bool8 db_enabled;
             u8 db_id;
             bool8 is_printing;
};
struct Font {
             u8 * draw_dest;
             struct Glyph const * const * glyphs;
             void (* draw_glyph)(struct Text * text, struct Glyph const * glyph);
             u8 * (* get_draw_dest)(struct Text * text);
             u16 tileref;
             u16 chr_counter;
             u16 palid;
             u8 lang;
};
struct TextInitInfo {
             struct Text * text;
             u8 width;
};
enum langauge_type {
    LANG_JAPANESE,
    LANG_ENGLISH,
};
enum text_glyph_type {
    TEXT_GLYPHS_SYSTEM,
    TEXT_GLYPHS_TALK,
};
enum text_color_idx {
    TEXT_COLOR_0123 = 0,
    TEXT_COLOR_0456 = 1,
    TEXT_COLOR_0789 = 2,
    TEXT_COLOR_0ABC = 3,
    TEXT_COLOR_0DEF = 4,
    TEXT_COLOR_0030 = 5,
    TEXT_COLOR_4DEF = 6,
    TEXT_COLOR_456F = 7,
    TEXT_COLOR_47CF = 8,
    TEXT_COLOR_MASK = 9,
    TEXT_COLOR_COUNT,
    TEXT_COLOR_SYSTEM_WHITE = TEXT_COLOR_0123,
    TEXT_COLOR_SYSTEM_GRAY = TEXT_COLOR_0456,
    TEXT_COLOR_SYSTEM_BLUE = TEXT_COLOR_0789,
    TEXT_COLOR_SYSTEM_GOLD = TEXT_COLOR_0ABC,
    TEXT_COLOR_SYSTEM_GREEN = TEXT_COLOR_0DEF,
};
enum special_character_idx {
    TEXT_SPECIAL_BIGNUM_0,
    TEXT_SPECIAL_BIGNUM_1,
    TEXT_SPECIAL_BIGNUM_2,
    TEXT_SPECIAL_BIGNUM_3,
    TEXT_SPECIAL_BIGNUM_4,
    TEXT_SPECIAL_BIGNUM_5,
    TEXT_SPECIAL_BIGNUM_6,
    TEXT_SPECIAL_BIGNUM_7,
    TEXT_SPECIAL_BIGNUM_8,
    TEXT_SPECIAL_BIGNUM_9,
    TEXT_SPECIAL_SMALLNUM_0,
    TEXT_SPECIAL_SMALLNUM_1,
    TEXT_SPECIAL_SMALLNUM_2,
    TEXT_SPECIAL_SMALLNUM_3,
    TEXT_SPECIAL_SMALLNUM_4,
    TEXT_SPECIAL_SMALLNUM_5,
    TEXT_SPECIAL_SMALLNUM_6,
    TEXT_SPECIAL_SMALLNUM_7,
    TEXT_SPECIAL_SMALLNUM_8,
    TEXT_SPECIAL_SMALLNUM_9,
    TEXT_SPECIAL_DASH,
    TEXT_SPECIAL_PLUS,
    TEXT_SPECIAL_SLASH,
    TEXT_SPECIAL_TILDE,
    TEXT_SPECIAL_S,
    TEXT_SPECIAL_A,
    TEXT_SPECIAL_B,
    TEXT_SPECIAL_C,
    TEXT_SPECIAL_D,
    TEXT_SPECIAL_E,
    TEXT_SPECIAL_G,
    TEXT_SPECIAL_EXP_E,
    TEXT_SPECIAL_COLON,
    TEXT_SPECIAL_DOT,
    TEXT_SPECIAL_HP_A,
    TEXT_SPECIAL_HP_B,
    TEXT_SPECIAL_LV_A,
    TEXT_SPECIAL_LV_B,
    TEXT_SPECIAL_ARROW,
    TEXT_SPECIAL_HEART,
    TEXT_SPECIAL_100_A,
    TEXT_SPECIAL_100_B,
    TEXT_SPECIAL_PERCENT,
    TEXT_SPECIAL_NOTHING = 0xFF,
};
int GetLang(void);
void ResetText(void);
void InitTextFont(struct Font * font, void * draw_dest, int chr, int palid);
void SetTextFontGlyphs(int glyphset);
void ResetTextFont(void);
void SetTextFont(struct Font * font);
void InitText(struct Text * text, int width);
void InitTextDb(struct Text * text, int width);
void InitTextList(struct TextInitInfo const * info);
void ClearText(struct Text * text);
void ClearTextPart(struct Text * text, int tile_off, int tile_width);
int Text_GetChrOffset(struct Text * text);
int Text_GetCursor(struct Text * text);
void Text_SetCursor(struct Text * text, int x);
void Text_Skip(struct Text * text, int x);
void Text_SetColor(struct Text * text, int color);
int Text_GetColor(struct Text * text);
void Text_SetParams(struct Text * text, int x, int color);
void PutText(struct Text * text, u16 * tm);
void PutBlankText(struct Text * text, u16 * tm);
int GetStringTextLen(char const * str);
char const * GetCharTextLen(char const * str, int * out_width);
int GetStringTextCenteredPos(int area_length, char const * str);
void GetStringTextBox(char const * str, int * out_width, int * out_height);
char const * GetStringLineEnd(char const * str);
void Text_DrawString(struct Text * text, char const * str);
void Text_DrawNumber(struct Text * text, int number);
void Text_DrawNumberOrBlank(struct Text * text, int number);
char const * Text_DrawCharacter(struct Text * text, char const * str);
void InitSystemTextFont(void);
void InitTalkTextFont(void);
void SetTextDrawNoClear(void);
void PutDrawText(struct Text * text, u16 * tm, int color, int x, int tile_width, char const * str);
void Text_InsertDrawString(struct Text * text, int x, int color, const char * str);
void Text_InsertDrawNumberOrBlank(struct Text * text, int x, int color, int number);
void InitSpriteTextFont(struct Font * font, u8 * draw_dest, int palid);
void InitSpriteText(struct Text * text);
void SpriteText_DrawBackground(struct Text * text);
void SpriteText_DrawBackgroundExt(struct Text * text, u32 line);
char const * StartTextPrint(struct Text * text, char const * str, int interval, int char_per_tick);
bool IsTextPrinting(struct Text * text);
void EndTextPrinting(void);
void StartGreenText(ProcPtr parent);
void EndGreenText(void);
void PutSpecialChar(u16 * tm, int color, int id);
void PutNumberExt(u16 * tm, int color, int number, int id_zero);
void PutNumber(u16 * tm, int color, int number);
void PutNumberOrBlank(u16 * tm, int color, int number);
void PutNumberTwoChr(u16 * tm, int color, int number);
void PutNumberSmall(u16 * tm, int color, int number);
void PutNumberBonus(int number, u16 * tm);
void PutNumber2DigitExt(u16 * tm, int color, int number, int id_zero);
void PutNumber2Digit(u16 * tm, int color, int number);
void PutNumber2DigitSmall(u16 * tm, int color, int number);
void PutTime(u16 * tm, int color, int time, bool always_display_punctuation);
void PutTwoSpecialChar(u16 * tm, int color, int id_a, int id_b);
struct SpriteEntry {
             struct SpriteEntry * next;
             s16 oam1;
             s16 oam0;
             u16 oam2;
             u16 const * object;
};
extern struct SpriteEntry * gSpriteAllocIt;
extern struct SpriteEntry  SpritePool[0x80];
extern struct SpriteEntry  SpriteLayers[0x10];
extern u16  Sprite_8x8[];
extern u16  Sprite_16x16[];
extern u16  Sprite_32x32[];
extern u16  Sprite_64x64[];
extern u16  Sprite_8x16[];
extern u16  Sprite_16x32[];
extern u16  Sprite_32x64[];
extern u16  Sprite_16x8[];
extern u16  Sprite_16x8_VFlipped[];
extern u16  Sprite_32x16[];
extern u16  Sprite_64x32[];
extern u16  Sprite_32x8[];
extern u16  Sprite_8x32[];
extern u16  Sprite_32x8_VFlipped[];
extern u16  Sprite_8x16_HFlipped[];
extern u16  Sprite_8x8_HFlipped[];
extern u16  Sprite_8x8_VFlipped[];
extern u16  Sprite_8x8_HFlipped_VFlipped[];
extern u16  Sprite_16x16_VFlipped[];
extern struct ProcCmd  ProcSrc_SpriteRefresher[];
void PutSpriteAffine(int id, short pa, short pb, short pc, short pd);
void ClearSprites(void);
void PutSprite(int layer, int x, int y, u16 const * object, int oam2);
void PutSpriteExt(int layer, int x_oam1, int y_oam0, u16 const * object, int oam2);
void PutSpriteLayerOam(int layer);
struct SpriteProc {
             const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             int x;
             int y;
             u8 pad_34[0x50 - 0x34];
             s16 layer;
             u16 tileref;
             u16 const * object;
};
void SpriteRefresher_OnIdle(struct SpriteProc * proc);
struct SpriteProc * StartSpriteRefresher(ProcPtr parent, int layer, int x, int y, u16 const * object, int tileref);
void MoveSpriteRefresher(struct SpriteProc * proc, int x, int y);
       
typedef u32 AnimScr;
struct Anim {
             u16 state;
             short xPosition;
             short yPosition;
             short timer;
             u16 oam2Base;
             u16 drawLayerPriority;
             u16 state2;
             u16 nextRoundId;
             u16 state3;
             u8 currentRoundType;
             u8 unk13;
             u8 commandQueueSize;
             u8 commandQueue[7];
             u32 oamBase;
             const AnimScr * pScrCurrent;
             const AnimScr * pScrStart;
             const void * pImgSheet;
             void * pImgSheetBuf;
             const void * pSpriteDataPool;
             struct Anim * pPrev;
             struct Anim * pNext;
             const void * pSpriteData;
             const void * pUnk40;
             void * pUnk44;
};
enum Anim_state {
    ANIM_BIT_ENABLED = (1 << 0),
    ANIM_BIT_HIDDEN = (1 << 1),
    ANIM_BIT_2 = (1 << 2),
    ANIM_BIT_FROZEN = (1 << 3),
};
enum Anim_state2 {
    ANIM_BIT2_0001 = (1 << 0),
    ANIM_BIT2_0002 = (1 << 1),
    ANIM_BIT2_0004 = (1 << 2),
    ANIM_BIT2_0008 = (1 << 3),
    ANIM_BIT2_0010 = (1 << 4),
    ANIM_BIT2_0020 = (1 << 5),
    ANIM_BIT2_0040 = (1 << 6),
    ANIM_BIT2_0080 = (1 << 7),
    ANIM_BIT2_FRONT_FRAME = (1 << 8),
    ANIM_BIT2_BACK_FRAME = (0 << 8),
    ANIM_BIT2_POS_RIGHT = (1 << 9),
    ANIM_BIT2_POS_LEFT = (0 << 9),
    ANIM_BIT2_0400 = (1 << 10),
    ANIM_BIT2_0800 = (1 << 11),
    ANIM_BIT2_COMMAND = (1 << 12),
    ANIM_BIT2_FRAME = (1 << 13),
    ANIM_BIT2_STOP = (1 << 14),
    ANIM_BIT2_8000 = (1 << 15),
};
enum Anim_state3 {
    ANIM_BIT3_TAKE_BACK_ENABLE = (1 << 0),
    ANIM_BIT3_NEXT_ROUND_START = (1 << 1),
    ANIM_BIT3_C01_BLOCKING_IN_BATTLE = (1 << 2),
    ANIM_BIT3_HIT_EFFECT_APPLIED = (1 << 3),
    ANIM_BIT3_0010 = (1 << 4),
    ANIM_BIT3_BLOCKING = (1 << 5),
    ANIM_BIT3_BLOCKEND = (1 << 6),
    ANIM_BIT3_0080 = (1 << 7),
    ANIM_BIT3_0100 = (1 << 8),
    ANIM_BIT3_0200 = (1 << 9),
    ANIM_BIT3_0400 = (1 << 10),
    ANIM_BIT3_0800 = (1 << 11),
    ANIM_BIT3_1000 = (1 << 12),
    ANIM_BIT3_2000 = (1 << 13),
    ANIM_BIT3_4000 = (1 << 14),
    ANIM_BIT3_NEW_ROUND_START = (1 << 15),
};
enum {
    ANIM_MAX_COUNT = 50,
};
enum {
    ANIM_CMD_NOP = 0x00,
    ANIM_CMD_WAIT_01 = 0x01,
    ANIM_CMD_WAIT_02 = 0x02,
    ANIM_CMD_WAIT_03 = 0x03,
    ANIM_CMD_WAIT_04 = 0x04,
    ANIM_CMD_WAIT_05 = 0x05,
    ANIM_CMD_WAIT_13 = 0x13,
    ANIM_CMD_WAIT_18 = 0x18,
    ANIM_CMD_WAIT_2D = 0x2D,
    ANIM_CMD_WAIT_39 = 0x39,
    ANIM_CMD_WAIT_52 = 0x52,
};
enum anim_inst_type {
    ANIM_INS_TYPE_STOP = 0,
    ANIM_INS_TYPE_END = 1,
    ANIM_INS_TYPE_LOOP = 2,
    ANIM_INS_TYPE_MOVE = 3,
    ANIM_INS_TYPE_WAIT = 4,
    ANIM_INS_TYPE_COMMAND = 5,
    ANIM_INS_TYPE_FRAME = 6,
};
struct AnimSpriteData {
             u32 header;
    union {
        struct {
                     u16 pa;
                     u16 pb;
                     u16 pc;
                     u16 pd;
        } affine;
        struct {
                     u16 oam2;
                     short x;
                     short y;
        } object;
    } as;
};
void AnimUpdateAll(void);
void AnimClearAll(void);
struct Anim * AnimCreate_unused(const AnimScr * scr);
struct Anim * AnimCreate(const void * script, u16 displayPriority);
void AnimSort(void);
void AnimDelete(struct Anim * anim);
void AnimDisplay(struct Anim * anim);
int AnimInterpret(struct Anim * anim);
void AnimInsert(struct Anim * anim);
void AnimDisplayPrivate(struct Anim * anim);
void Anim_8005334(struct Anim * anim, u32 instruction);
bool PrepareBattleGraphicsMaybe(void);
int GetBanimTerrainGround(u16 terrain, u16 tileset);
int GetBanimBackgroundIndex(u16 terrain, u16 tileset);
s16 GetSpellAnimId(u16 jid, u16 weapon);
u16 GetBattleAnimationId(struct Unit * unit, const struct BattleAnimDef * anim_def, u16 wpn, u32 * out);
       
void AiTryMoveTowards(short x, short y, u8 action, u8 maxDanger, u8 arg_4);
void SetupUnitInventoryAIFlags(void);
void AiUpdateUnitsSeekHealing(void);
extern u32 const AiItemConfigTable[];
extern struct ProcCmd ProcScr_AiOrder[];
u32 SioStrCpy(u8 const * src, u8 * dst);
void SioDrawNumber(struct Text * text, int x, int color, int number);
void SioInit(void);
void SioPollingMsgAndAck(ProcPtr proc);
void SetBmStLinkArenaFlag(void);
void UnsetBmStLinkArenaFlag(void);
bool CheckInLinkArena(void);
void sub_8043290( );
void StartNameSelect(ProcPtr parent);
void StartTacticianNameSelect(ProcPtr parent);
void sub_8043948( );
void GC_ConnectToFE6( );
       
       
struct SupportData;
enum { UNIT_LEVEL_MAX = 20 };
enum item_slot_idx {
    ITEMSLOT_INV0,
    ITEMSLOT_INV1,
    ITEMSLOT_INV2,
    ITEMSLOT_INV3,
    ITEMSLOT_INV4,
    ITEMSLOT_INV_COUNT,
    ITEMSLOT_OVERFLOW = ITEMSLOT_INV_COUNT + 0,
    ITEMSLOT_ARENA_PLAYER = ITEMSLOT_INV_COUNT + 1,
    ITEMSLOT_ARENA_OPPONENT = ITEMSLOT_INV_COUNT + 2,
    ITEMSLOT_BALLISTA = ITEMSLOT_INV_COUNT + 3,
};
enum { UNIT_DEFINITION_ITEM_COUNT = 4 };
enum { UNIT_SUPPORT_MAX_COUNT = 7 };
enum { UNIT_EXP_DISABLED = 0xFF };
struct CharacterData {
             u16 nameTextId;
             u16 descTextId;
             u8 number;
             u8 defaultClass;
             u16 portraitId;
             u8 miniPortrait;
             u8 affinity;
             u8 sort_order;
             s8 baseLevel;
             s8 baseHP;
             s8 basePow;
             s8 baseSkl;
             s8 baseSpd;
             s8 baseDef;
             s8 baseRes;
             s8 baseLck;
             s8 baseCon;
             u8 baseRanks[8];
             u8 growthHP;
             u8 growthPow;
             u8 growthSkl;
             u8 growthSpd;
             u8 growthDef;
             u8 growthRes;
             u8 growthLck;
             u8 _u23;
             u8 _u24;
             u8 _u25;
             u8 _u26;
             u8 _u27;
             u32 attributes;
             const struct SupportData* pSupportData;
             u8 visit_group;
             u8 _pad_[0x34 - 0x31];
};
extern  struct CharacterData gCharacterData[];
struct ClassData {
             u16 nameTextId;
             u16 descTextId;
             u8 number;
             u8 promotion;
             u8 SMSId;
             u8 slowWalking;
             u16 defaultPortraitId;
             u8 sort_order;
             s8 baseHP;
             s8 basePow;
             s8 baseSkl;
             s8 baseSpd;
             s8 baseDef;
             s8 baseRes;
             s8 baseCon;
             s8 baseMov;
             s8 maxHP;
             s8 maxPow;
             s8 maxSkl;
             s8 maxSpd;
             s8 maxDef;
             s8 maxRes;
             s8 maxCon;
             s8 classRelativePower;
             s8 growthHP;
             s8 growthPow;
             s8 growthSkl;
             s8 growthSpd;
             s8 growthDef;
             s8 growthRes;
             s8 growthLck;
             u8 promotionHp;
             u8 promotionPow;
             u8 promotionSkl;
             u8 promotionSpd;
             u8 promotionDef;
             u8 promotionRes;
             u32 attributes;
             u8 baseRanks[8];
             const void* pBattleAnimDef;
             const s8* pMovCostTable[3];
             const s8* pTerrainAvoidLookup;
             const s8* pTerrainDefenseLookup;
             const s8* pTerrainResistanceLookup;
             const void* _pU50;
};
extern  struct ClassData gClassData[];
struct Unit {
             const struct CharacterData* pCharacterData;
             const struct ClassData* pClassData;
             s8 level;
             u8 exp;
             u8 aiFlags;
             s8 index;
             u32 state;
             s8 xPos;
             s8 yPos;
             s8 maxHP;
             s8 curHP;
             s8 pow;
             s8 skl;
             s8 spd;
             s8 def;
             s8 res;
             s8 lck;
             s8 conBonus;
             u8 rescue;
             u8 ballistaIndex;
             s8 movBonus;
             u16 items[ITEMSLOT_INV_COUNT];
             u8 ranks[8];
             u8 statusIndex : 4;
             u8 statusDuration : 4;
             u8 torchDuration : 4;
             u8 barrierDuration : 4;
             u8 supports[UNIT_SUPPORT_MAX_COUNT];
             s8 supportBits;
             u8 _u3A;
             u8 _u3B;
             struct SMSHandle* pMapSpriteHandle;
             u16 ai3And4;
             u8 ai1;
             u8 ai1data;
             u8 ai2;
             u8 ai2data;
             u8 _u46;
             u8 _u47;
};
extern struct Unit *gUnitLut[0x100];
extern struct Unit *gActiveUnit;
struct UnitDefinition {
             u8 pid;
             u8 jid;
             u8 pid_lead;
             u8 autolevel : 1;
             u8 faction_id : 2;
             u8 level : 5;
             u8 x_load, y_load;
             u8 x_move, y_move;
             u8 items[4];
             u8 ai[4];
};
enum {
    US_NONE = 0,
    US_HIDDEN = (1 << 0),
    US_UNSELECTABLE = (1 << 1),
    US_DEAD = (1 << 2),
    US_NOT_DEPLOYED = (1 << 3),
    US_RESCUING = (1 << 4),
    US_RESCUED = (1 << 5),
    US_HAS_MOVED = (1 << 6),
    US_CANTOING = US_HAS_MOVED,
    US_UNDER_A_ROOF = (1 << 7),
    US_SEEN = (1 << 8),
    US_CONCEALED = (1 << 9),
    US_HAS_MOVED_AI = (1 << 10),
    US_IN_BALLISTA = (1 << 11),
    US_DROP_ITEM = (1 << 12),
    US_GROWTH_BOOST = (1 << 13),
    US_SOLOANIM_1 = (1 << 14),
    US_SOLOANIM_2 = (1 << 15),
    US_BIT16 = (1 << 16),
    US_BIT17 = (1 << 17),
    US_BIT18 = (1 << 18),
    US_BIT19 = (1 << 19),
    US_BIT20 = (1 << 20),
    US_BIT21 = (1 << 21),
    US_BIT22 = (1 << 22),
    US_BIT23 = (1 << 23),
    US_BIT25 = (1 << 25),
    US_BIT26 = (1 << 26),
    US_BIT27 = (1 << 27),
    US_UNAVAILABLE = (US_DEAD | US_NOT_DEPLOYED | US_BIT16),
};
enum {
    UNIT_STATUS_NONE = 0,
    UNIT_STATUS_POISON = 1,
    UNIT_STATUS_SLEEP = 2,
    UNIT_STATUS_SILENCED = 3,
    UNIT_STATUS_BERSERK = 4,
    UNIT_STATUS_ATTACK = 5,
    UNIT_STATUS_DEFENSE = 6,
    UNIT_STATUS_CRIT = 7,
    UNIT_STATUS_AVOID = 8,
    UNIT_STATUS_SICK = 9,
    UNIT_STATUS_RECOVER = 10,
};
enum {
    FACTION_BLUE = 0x00,
    FACTION_GREEN = 0x40,
    FACTION_RED = 0x80,
    FACTION_PURPLE = 0xC0,
};
enum {
    FACTION_ID_BLUE = 0,
    FACTION_ID_GREEN = 1,
    FACTION_ID_RED = 2,
    FACTION_ID_PURPLE = 3,
};
enum {
    CA_NONE = 0,
    CA_MOUNTEDAID = (1 << 0),
    CA_CANTO = (1 << 1),
    CA_STEAL = (1 << 2),
    CA_THIEF = (1 << 3),
    CA_DANCE = (1 << 4),
    CA_PLAY = (1 << 5),
    CA_CRITBONUS = (1 << 6),
    CA_BALLISTAE = (1 << 7),
    CA_PROMOTED = (1 << 8),
    CA_SUPPLY = (1 << 9),
    CA_MOUNTED = (1 << 10),
    CA_WYVERN = (1 << 11),
    CA_PEGASUS = (1 << 12),
    CA_LORD = (1 << 13),
    CA_FEMALE = (1 << 14),
    CA_BOSS = (1 << 15),
    CA_LOCK_1 = (1 << 16),
    CA_LOCK_2 = (1 << 17),
    CA_LOCK_3 = (1 << 18),
    CA_MAXLEVEL10 = (1 << 19),
    CA_UNSELECTABLE = (1 << 20),
    CA_TRIANGLEATTACK_PEGASI = (1 << 21),
    CA_TRIANGLEATTACK_ARMORS = (1 << 22),
    CA_BIT_23 = (1 << 23),
    CA_NEGATE_LETHALITY = (1 << 24),
    CA_ASSASSIN = (1 << 25),
    CA_MAGICSEAL = (1 << 26),
    CA_SUMMON = (1 << 27),
    CA_LOCK_4 = (1 << 28),
    CA_LOCK_5 = (1 << 29),
    CA_LOCK_6 = (1 << 30),
    CA_LOCK_7 = (1 << 31),
    CA_REFRESHER = CA_DANCE | CA_PLAY,
    CA_FLYER = CA_WYVERN | CA_PEGASUS,
    CA_TRIANGLEATTACK_ANY = CA_TRIANGLEATTACK_ARMORS | CA_TRIANGLEATTACK_PEGASI,
};
enum {
    UNIT_USEBIT_WEAPON = (1 << 0),
    UNIT_USEBIT_STAFF = (1 << 1),
};
enum unit_affinity_index {
    UNIT_AFFIN_FIRE = 1,
    UNIT_AFFIN_THUNDER,
    UNIT_AFFIN_WIND,
    UNIT_AFFIN_ICE,
    UNIT_AFFIN_DARK,
    UNIT_AFFIN_LIGHT,
    UNIT_AFFIN_ANIMA,
};
extern u8 gActiveUnitId;
extern struct Vec2 gActiveUnitMoveOrigin;
void InitUnits(void);
void ClearUnit(struct Unit *unit);
void CopyUnit(struct Unit * src, struct Unit * dst);
void SetUnitStatus(struct Unit *unit, int statusId);
void SetUnitStatusExt(struct Unit *unit, int status, int duration);
int GetUnitSMSId(struct Unit *unit);
bool UnitAddItem(struct Unit *unit, int item);
void UnitClearInventory(struct Unit * unit);
void UnitRemoveInvalidItems(struct Unit *unit);
int GetUnitItemCount(struct Unit *unit);
struct Unit *LoadUnit(const struct UnitDefinition *uDef);
void UnitInitFromDefinition(struct Unit *unit, const struct UnitDefinition *uDef);
void UnitLoadItemsFromDefinition(struct Unit *unit, const struct UnitDefinition *uDef);
void UnitLoadStatsFromChracter(struct Unit *unit, const struct CharacterData *character);
void FixROMUnitStructPtr(struct Unit *unit);
void UnitLoadSupports(struct Unit *unit);
void UnitAutolevelWExp(struct Unit *unit, const struct UnitDefinition *uDef);
void UnitAutolevelCore(struct Unit *unit, u8 classId, int levelCount);
void UnitApplyBonusLevels(struct Unit *unit, int levelCount);
void UnitAutolevel(struct Unit *unit);
void UnitAutolevelPlayer(struct Unit *unit);
void UnitCheckStatCaps(struct Unit *unit);
struct Unit *GetUnitFromCharId(int charId);
struct Unit *GetUnitFromCharIdAndFaction(int charId, int faction);
bool CanUnitRescue(struct Unit *actor, struct Unit *target);
void UnitRescue(struct Unit *actor, struct Unit *target);
void UnitDrop(struct Unit *actor, int xTarget, int yTarget);
bool UnitGive(struct Unit *actor, struct Unit *target);
void UnitKill(struct Unit *unit);
void UnitChangeFaction(struct Unit *unit, int faction);
void UnitSyncMovement(struct Unit *unit);
void MoveActiveUnit(int x, int y);
void ClearActiveFactionGrayedStates(void);
void TickActiveFactionTurn(void);
void SetAllUnitNotBackSprite(void);
void UnitUpdateUsedItem(struct Unit *unit, int itemSlot);
int GetUnitAid(struct Unit *unit);
int GetUnitMagRange(struct Unit *unit);
bool UnitHasMagicRank(struct Unit *unit);
int GetUnitAidIconId(u32 attributes);
const s8* GetUnitMovementCost(struct Unit *unit);
void sub_8018CC4(void);
int GetUnitCurrentHp(struct Unit *unit);
int GetUnitMaxHp(struct Unit *unit);
int GetUnitPower(struct Unit *unit);
int GetUnitSkill(struct Unit *unit);
int GetUnitSpeed(struct Unit *unit);
int GetUnitDefense(struct Unit *unit);
int GetUnitResistance(struct Unit *unit);
int GetUnitLuck(struct Unit *unit);
int GetUnitPortraitId(struct Unit *unit);
int GetUnitMiniPortraitId(struct Unit *unit);
int GetUnitLeaderCharId(struct Unit *unit);
void SetUnitLeaderCharId(struct Unit *unit, int charId);
void SetUnitHp(struct Unit *unit, int value);
void AddUnitHp(struct Unit *unit, int amount);
const char * GetUnitRescueName(struct Unit * unit);
const char * GetUnitStatusName(struct Unit * unit);
struct Unit * GetUnit(int uid);
const struct ClassData * GetClassData(int jid);
const struct CharacterData * GetCharacterData(int pid);
void UnitRemoveItem(struct Unit *unit, int slot);
bool CanUnitCrossTerrain(struct Unit *unit, int terrain);
       
struct BattleUnit {
             struct Unit unit;
             u16 weapon;
             u16 weaponBefore;
             u32 weaponAttributes;
             u8 weaponType;
             u8 weaponSlotIndex;
             s8 canCounter;
             s8 wTriangleHitBonus;
             s8 wTriangleDmgBonus;
             u8 terrainId;
             s8 terrainDefense;
             s8 terrainAvoid;
             s8 terrainResistance;
             short battleAttack;
             short battleDefense;
             short battleSpeed;
             short battleHitRate;
             short battleAvoidRate;
             short battleEffectiveHitRate;
             short battleCritRate;
             short battleDodgeRate;
             short battleEffectiveCritRate;
             short battleSilencerRate;
             s8 expGain;
             s8 statusOut;
             s8 levelPrevious;
             s8 expPrevious;
             s8 hpInitial;
             s8 changeHP;
             s8 changePow;
             s8 changeSkl;
             s8 changeSpd;
             s8 changeDef;
             s8 changeRes;
             s8 changeLck;
             s8 changeCon;
             s8 wexpMultiplier;
             s8 nonZeroDamage;
             s8 weaponBroke;
             s8 hasItemEffectTarget;
};
extern struct BattleUnit gBattleActor, gBattleTarget;
enum {
    BATTLE_CONFIG_REAL = (1 << 0),
    BATTLE_CONFIG_SIMULATE = (1 << 1),
    BATTLE_CONFIG_BIT2 = (1 << 2),
    BATTLE_CONFIG_BALLISTA = (1 << 3),
    BATTLE_CONFIG_PROMOTION = (1 << 4),
    BATTLE_CONFIG_ARENA = (1 << 5),
    BATTLE_CONFIG_REFRESH = (1 << 6),
    BATTLE_CONFIG_MAPANIMS = (1 << 7),
    BATTLE_CONFIG_PROMOTION_PREP = (1 << 8),
    BATTLE_CONFIG_DANCERING = (1 << 9),
};
struct BattleStats {
             u16 config;
             u8 range;
             short damage;
             short attack;
             short defense;
             short hitRate;
             short critRate;
             short silencerRate;
             struct Unit *taUnitA;
             struct Unit *taUnitB;
};
extern struct BattleStats gBattleStats;
enum {
    BATTLE_HIT_ATTR_CRIT = (1 << 0),
    BATTLE_HIT_ATTR_MISS = (1 << 1),
    BATTLE_HIT_ATTR_FOLLOWUP = (1 << 2),
    BATTLE_HIT_ATTR_RETALIATE = (1 << 3),
    BATTLE_HIT_ATTR_BRAVE = (1 << 4),
    BATTLE_HIT_ATTR_5 = (1 << 5),
    BATTLE_HIT_ATTR_POISON = (1 << 6),
    BATTLE_HIT_ATTR_DEVIL = (1 << 7),
    BATTLE_HIT_ATTR_HPSTEAL = (1 << 8),
    BATTLE_HIT_ATTR_HPHALVE = (1 << 9),
    BATTLE_HIT_ATTR_TATTACK = (1 << 10),
    BATTLE_HIT_ATTR_SILENCER = (1 << 11),
    BATTLE_HIT_ATTR_12 = (1 << 12),
    BATTLE_HIT_ATTR_PETRIFY = (1 << 13),
    BATTLE_HIT_ATTR_SURESHOT = (1 << 14),
    BATTLE_HIT_ATTR_GREATSHLD = (1 << 15),
    BATTLE_HIT_ATTR_PIERCE = (1 << 16),
    BATTLE_HIT_ATTR_17 = (1 << 17),
    BATTLE_HIT_ATTR_18 = (1 << 18),
};
enum {
    BATTLE_HIT_INFO_BEGIN = (1 << 0),
    BATTLE_HIT_INFO_FINISHES = (1 << 1),
    BATTLE_HIT_INFO_KILLS_TARGET = (1 << 2),
    BATTLE_HIT_INFO_RETALIATION = (1 << 3),
    BATTLE_HIT_INFO_END = (1 << 7),
};
struct BattleHit {
    u16 attributes;
    u8 info;
    u8 hpChange;
};
extern struct BattleHit gBattleHitArray[7];
extern struct BattleHit *gBattleHitIterator;
enum {
    BU_ISLOT_AUTO = -1,
    BU_ISLOT_OVERFLOW = ITEMSLOT_INV_COUNT + 0,
    BU_ISLOT_ARENA_PLAYER = ITEMSLOT_INV_COUNT + 1,
    BU_ISLOT_ARENA_OPPONENT = ITEMSLOT_INV_COUNT + 2,
    BU_ISLOT_BALLISTA = ITEMSLOT_INV_COUNT + 3,
};
struct WeaponTriangleRule {
    s8 attackerWeaponType;
    s8 defenderWeaponType;
    s8 hitBonus;
    s8 atkBonus;
};
extern struct WeaponTriangleRule WeaponTriangleRules[];
void BattleGenerate(struct Unit * actor, struct Unit * target);
void BattleGenerateUiStats(struct Unit * unit, s8 itemSlot);
bool BattleRoll1RN(u16 threshold, bool simulationResult);
bool BattleRoll2RN(u16 threshold, bool simulationResult);
void InitBattleUnit(struct BattleUnit * bu, struct Unit * unit);
void SetBattleUnitTerrainBonusesAuto(struct BattleUnit * bu);
void SetBattleUnitWeapon(struct BattleUnit * bu, int itemSlot);
void SetBattleUnitWeaponBallista(struct BattleUnit * bu);
void ComputeBattleUnitStats(struct BattleUnit * attacker, struct BattleUnit * defender);
void ComputeBattleUnitEffectiveStats(struct BattleUnit * attacker, struct BattleUnit * defender);
void ComputeBattleUnitSupportBonuses(struct BattleUnit * attacker, struct BattleUnit * defender);
void ComputeBattleUnitDefense(struct BattleUnit * attacker, struct BattleUnit * defender);
void ComputeBattleUnitBaseDefense(struct BattleUnit *bu);
void ComputeBattleUnitStatusBonuses(struct BattleUnit *bu);
void ComputeBattleUnitSpecialWeaponStats(struct BattleUnit *attacker, struct BattleUnit *defender);
void ClearBattleHits(void);
void ComputeBattleUnitAttack(struct BattleUnit *attacker, struct BattleUnit *defender);
void ComputeBattleUnitSpeed(struct BattleUnit *bu);
void ComputeBattleUnitHitRate(struct BattleUnit *bu);
void ComputeBattleUnitAvoidRate(struct BattleUnit *bu);
void ComputeBattleUnitCritRate(struct BattleUnit *bu);
void ComputeBattleUnitDodgeRate(struct BattleUnit *bu);
void ComputeBattleUnitEffectiveHitRate(struct BattleUnit *attacker, struct BattleUnit *defender);
void ComputeBattleUnitEffectiveCritRate(struct BattleUnit *attacker, struct BattleUnit *defender);
void ComputeBattleUnitSilencerRate(struct BattleUnit *attacker, struct BattleUnit *defender);
void ComputeBattleUnitWeaponRankBonuses(struct BattleUnit *bu);
void ComputeBattleUnitStatusBonuses(struct BattleUnit *bu);
void BattleUnwind(void);
void BattleGetBattleUnitOrder(struct BattleUnit **attacker, struct BattleUnit **defender);
bool BattleGetFollowUpOrder(struct BattleUnit **attacker, struct BattleUnit **defender);
bool BattleGenerateRoundHits(struct BattleUnit *attacker, struct BattleUnit *defender);
int GetBattleUnitHitCount(struct BattleUnit *attacker);
int BattleCheckBraveEffect(struct BattleUnit *attacker);
bool BattleCheckTriangleAttack(struct BattleUnit *attacker, struct BattleUnit *defender);
void BattleUpdateBattleStats(struct BattleUnit *attacker, struct BattleUnit *defender);
void BattleGenerateHitAttributes(struct BattleUnit *attacker);
void BattleGenerateHitTriangleAttack(struct BattleUnit *attacker, struct BattleUnit *defender);
void BattleGenerateHitEffects(struct BattleUnit *attacker, struct BattleUnit *defender);
bool BattleGenerateHit(struct BattleUnit *attacker, struct BattleUnit *defender);
void BattleApplyExpGains(void);
bool CanBattleUnitGainLevels(struct BattleUnit *bu);
void CheckBattleUnitLevelUp(struct BattleUnit *bu);
void CheckBattleUnitStatCaps(struct Unit *unit, struct BattleUnit *bu);
void BattleApplyUnitUpdates(void);
int GetBattleUnitUpdatedWeaponExp(struct BattleUnit* bu);
bool HasBattleUnitGainedWeaponLevel(struct BattleUnit *bu);
void UpdateUnitFromBattle(struct Unit *unit, struct BattleUnit *bu);
void UpdateUnitDuringBattle(struct Unit *unit, struct BattleUnit *bu);
void BattleApplyBallistaUpdates(void);
int GetBattleUnitExpGain(struct BattleUnit *actor, struct BattleUnit *target);
void BattleApplyItemExpGains(void);
int GetBattleUnitStaffExp(struct BattleUnit *bu);
void BattleApplyMiscActionExpGains(void);
void BattleUnitTargetSetEquippedWeapon(struct BattleUnit *bu);
void BattleUnitTargetCheckCanCounter(struct BattleUnit *bu);
void BattleApplyWeaponTriangleEffect(struct BattleUnit *actor, struct BattleUnit *target);
void BattleInitTargetCanCounter(void);
void ComputeBattleObstacleStats(void);
void UpdateObstacleFromBattle(struct BattleUnit *bu);
void BattlePrintDebugUnitInfo(struct BattleUnit *actor, struct BattleUnit *target);
void BattlePrintDebugHitInfo(void);
void UpdateActorFromBattle(void);
void BattleUnwindScripted(void);
void BattleHitAdvance(void);
void BattleHitTerminate(void);
enum ekr_battle_unit_position {
    EKR_POS_L,
    EKR_POS_R
};
extern struct Anim * gAnims[4];
enum gEkrDistanceType_index {
    EKR_DISTANCE_CLOSE,
    EKR_DISTANCE_FAR,
    EKR_DISTANCE_FARFAR,
    EKR_DISTANCE_MONOCOMBAT,
    EKR_DISTANCE_PROMOTION
};
enum AnimRoundData_type_identifier {
    ANIM_ROUND_HIT_CLOSE,
    ANIM_ROUND_CRIT_CLOSE,
    ANIM_ROUND_NONCRIT_FAR,
    ANIM_ROUND_CRIT_FAR,
    ANIM_ROUND_TAKING_MISS_CLOSE,
    ANIM_ROUND_TAKING_MISS_FAR,
    ANIM_ROUND_TAKING_HIT_CLOSE,
    ANIM_ROUND_STANDING,
    ANIM_ROUND_TAKING_HIT_FAR,
    ANIM_ROUND_MISS_CLOSE,
    ANIM_ROUND_MAX,
    ANIM_ROUND_INVALID = -1,
};
enum anim_round_type {
    ANIM_ROUND_BIT8 = 0x0100,
    ANIM_ROUND_PIERCE = 0x0200,
    ANIM_ROUND_GREAT_SHIELD = 0x0400,
    ANIM_ROUND_SURE_SHOT = 0x0800,
    ANIM_ROUND_SILENCER = 0x1000,
    ANIM_ROUND_POISON = 0x2000,
    ANIM_ROUND_BIT14 = 0x4000,
    ANIM_ROUND_DEVIL = 0x8000,
};
enum banim_mode_index {
    BANIM_MODE_NORMAL_ATK,
    BANIM_MODE_NORMAL_ATK_PRIORITY_L,
    BANIM_MODE_CRIT_ATK,
    BANIM_MODE_CRIT_ATK_PRIORITY_L,
    BANIM_MODE_RANGED_ATK,
    BANIM_MODE_RANGED_CRIT_ATK,
    BANIM_MODE_CLOSE_DODGE,
    BANIM_MODE_RANGED_DODGE,
    BANIM_MODE_STANDING,
    BANIM_MODE_STANDING2,
    BANIM_MODE_RANGED_STANDING,
    BANIM_MODE_MISSED_ATK,
    BANIM_MODE_INVALID = -1,
};
extern s16 gEkrDistanceType;
struct BattleAnim {
    char abbr[12];
    int * modes;
    char * script;
    char * oam_r;
    char * oam_l;
    u16 * pal;
};
extern struct BattleAnim banim_data[];
struct BattleAnimCharaPal {
    char abbr[12];
    u16 * pal;
};
extern struct BattleAnimCharaPal character_battle_animation_palette_table[];
struct BattleAnimTerrain {
    char abbr[12];
    char * tileset;
    u16 * palette;
    int null_1;
};
extern struct BattleAnimTerrain battle_terrain_table[];
struct BanimModeData {
    const u32 * unk0;
    const u32 * img;
    u32 unk2;
};
struct ProcEfx {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             u8 hitted;
             u8 type;
             unsigned char _pad_0x2B[(0x2C) - (0x2B)];
             s16 timer;
             s16 step;
             s16 unk30;
             u16 unk32;
             unsigned char _pad_0x34[(0x44) - (0x34)];
             u32 unk44;
             u32 unk48;
             u32 frame;
             u32 speed;
             s16 * unk54;
             s16 ** unk58;
             struct Anim * anim;
    unsigned char _pad_0x60[(0x64) - (0x60)];
    ProcPtr unk_64;
};
struct ProcEfxBG {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             u8 unk29;
    unsigned char _pad_0x2A[(0x2C) - (0x2A)];
             s16 timer;
             s16 terminator;
             s16 unk30;
             s16 unk32;
             s16 unk34;
    unsigned char _pad_0x36[(0x3C) - (0x36)];
             s16 unk3C;
    unsigned char _pad_0x3E[(0x44) - (0x3E)];
             u32 frame;
             const u16 * frame_config;
             u16 ** tsal;
             u16 ** tsar;
             u16 ** img;
             u16 ** pal;
             struct Anim * anim;
};
struct ProcEfxBGCOL {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
    unsigned char _pad_0x29[(0x2C) - (0x29)];
             s16 timer;
             s16 timer2;
             s16 terminator;
             s16 unk32;
    unsigned char _pad_0x34[(0x44) - (0x34)];
             u32 frame;
             const u16 * frame_config;
             void * pal;
    unsigned char _pad_0x50[(0x5C) - (0x50)];
             struct Anim * anim;
};
struct ProcEfxRST {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
    unsigned char _pad_0x29[(0x2C) - (0x29)];
             s16 timer;
             s16 duration;
    unsigned char _pad_0x30[(0x5C) - (0x30)];
             struct Anim * anim;
    unsigned char _pad_0x60[(0x64) - (0x60)];
             struct ProcEfx * efxproc;
};
struct ProcEfxOBJ {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             u8 unk29;
             u8 unk2A;
    unsigned char _pad_0x2B[(0x2C) - (0x2B)];
             s16 timer;
             s16 terminator;
             u16 unk30;
             u16 unk32;
             u16 unk34;
             u16 unk36;
             u16 unk38;
             u16 unk3A;
             u16 unk3C;
             u16 unk3E;
             u16 unk40;
             u16 unk42;
             int unk44;
             int unk48;
             int unk4C;
    unsigned char _pad_0x50[(0x5C) - (0x50)];
             struct Anim * anim;
             struct Anim * anim2;
             struct Anim * anim3;
             struct Anim * anim4;
};
struct ProcEfxALPHA {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             u8 unk29;
    unsigned char _pad_0x2A[(0x2C) - (0x2A)];
             s16 timer;
             s16 unk2E;
             s16 unk30;
    unsigned char _pad_0x32[(0x5C) - (0x32)];
             struct Anim * anim;
};
struct ProcEfxSCR {
             const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             unsigned char _pad_0x29[(0x2C) - (0x29)];
             s16 timer;
             s16 unk2E;
             unsigned char _pad_0x30[(0x44) - (0x30)];
             int unk44;
             unsigned char _pad_0x48[(0x5C) - (0x48)];
             struct ProcEfx * unk5C;
};
struct ProcEkrSubAnimeEmulator {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             u8 type;
             u8 valid;
             s16 timer;
             s16 scr_cur;
    unsigned char _pad_0x30[(0x32) - (0x30)];
             s16 x1;
             s16 x2;
    unsigned char _pad_0x36[(0x3A) - (0x36)];
             s16 y1;
             s16 y2;
    unsigned char _pad_0x3E[(0x44) - (0x3E)];
             u32 * anim_scr;
             void * sprite;
             int oam2Base;
             int oamBase;
};
extern u16 gEfxPal[];
extern const void * gpImgSheet[2];
extern int gEkrDebugUnk2;
extern int gAnimC01Blocking;
extern u32 gBanimDoneFlag[];
extern int * gpBanimModesLeft;
extern int * gpBanimModesRight;
extern u8 gBanimScrLeft[];
extern u8 gBanimScrRight[];
extern u16 gBanimPaletteLeft[0x50];
extern u16 gBanimPaletteRight[0x50];
extern u32 gBanimOaml[0x1600];
extern u32 gBanimOamr2[0x1600];
extern int Unk_02017758;
extern int Unk_03004750;
extern int Unk_0203E088[2];
extern s16 Unk_0203DFEC;
extern short gEkrPairHpInitial[2];
extern short gEfxPairHpBufOffset[];
extern u16 gEkrTsaBuffer[0x1000 / 2];
extern u16 gEfxFrameTmap[0x2520 / 2];
extern s16 gBanimUniquePal[2];
extern s16 gBanimFactionPal[2];
extern s16 gEkrSpellAnimIndex[2];
extern int gEkrBgPosition;
extern s16 gEkrXPosReal[2];
extern s16 gEkrYPosReal[2];
extern u16 gEkrXPosBase[2];
extern u16 gEkrYPosBase[2];
extern struct Vec2 gEkrBg0QuakeVec;
extern struct Vec2 gEkrBg2QuakeVec;
extern s16 gBanimValid[2];
extern int gEkrBg2ScrollFlip;
extern u16 * gpBg2ScrollOffsetStart;
extern u16 * gpBg2ScrollOffset;
extern u16 gpBg2ScrollOffsetTable1[];
extern u16 gpBg2ScrollOffsetTable2[];
extern int gEkrBg1ScrollFlip;
extern u16 * gpBg1ScrollOffsetStart;
extern u16 * gpBg1ScrollOffset;
extern u16 gpBg1ScrollOffsetList1[];
extern u16 gpBg1ScrollOffsetList2[];
extern s16 gBanimIdx[2];
extern struct BattleUnit * gpEkrBattleUnitLeft;
extern struct BattleUnit * gpEkrBattleUnitRight;
extern u16 * gpEfxUnitPaletteBackup[2];
extern struct Unit * gpEkrTriangleUnits[2];
extern u16 * gBanimTriAtkPalettes[2];
extern s16 gBanimUniquePaletteDisabled[2];
void NewEkrLvlupFan(void);
void NewEkrGauge(void);
void EndEkrGauge(void);
void EkrGauge_0804CC28(void);
void EkrGauge_0804CC38(void);
void EkrGauge_0804CC48(void);
void EkrGauge_0804CC58(void);
void EkrGauge_0804CC68(u16 val);
void EkrGauge_0804CC78(s16 x, s16 y);
void EkrGauge_0804CC8C(s16 x, s16 y);
void EkrGauge_SetInitFlag(void);
void EkrGauge_ClrInitFlag(void);
void NewEkrDispUP(void);
void EndEkrDispUP(void);
void EkrDispUP_SetPositionUnsync(u16 x, u16 y);
void EkrDispUP_SetPositionSync(u16 x, u16 y);
void SyncEkrDispUP(void);
void UnsyncEkrDispUP(void);
void AsyncEkrDispUP(void);
void UnAsyncEkrDispUP(void);
int CheckEkrHitDone(void);
ProcPtr NewEfxQuakePure(int, int);
void NewEfxQuake(int type);
void NewEfxFlashBgWhite(struct Anim * anim, int duartion);
void NewEfxFlashBgRed(struct Anim * anim, int duartion);
void NewEfxFlashBgBlack(struct Anim * anim, int duartion);
void NewEfxFlashBgDirectly(struct Anim * anim, int duartion);
struct ProcEfxStatusUnit {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             u8 invalid;
    unsigned char _pad_0x2A[(0x2C) - (0x2A)];
             u16 timer;
    unsigned char _pad_0x2E[(0x32) - (0x2E)];
             s16 red;
             s16 green;
             s16 blue;
    unsigned char _pad_0x38[(0x44) - (0x38)];
             u32 frame;
             const u16 *frame_lut;
             u32 debuff;
             u32 debuf_bak;
    unsigned char _pad_0x54[(0x5C) - (0x54)];
             u8 _pad_54[0x5C - 0x54];
             struct Anim * anim;
};
extern struct ProcEfxStatusUnit * gpProcEfxStatusUnits[2];
void NewEfxStatusUnit(struct Anim * anim);
void EndEfxStatusUnits(struct Anim *anim);
void DisableEfxStatusUnits(struct Anim * anim);
void EnableEfxStatusUnits(struct Anim * anim);
void SetUnitEfxDebuff(struct Anim * anim, int debuff);
u32 GetUnitEfxDebuff(struct Anim * anim);
void EfxStatusUnitFlashing(struct Anim * anim, int, int, int);
void EfxStatusUnit_Loop(struct ProcEfxStatusUnit * proc);
void NewEfxWeaponIcon(s16 effective1, s16 effective2);
void EndProcEfxWeaponIcon(void);
void DisableEfxWeaponIcon(void);
void EnableEfxWeaponIcon(void);
void SpellFx_Begin(void);
void SpellFx_Finish(void);
void SpellFx_SetBG1Position(void);
void SpellFx_ClearBG1(void);
void SpellFx_SetSomeColorEffect(void);
void SpellFx_ClearColorEffects(void);
void StartBattleAnimHitEffectsDefault(struct Anim * anim, int type);
void StartBattleAnimHitEffects(struct Anim * anim, int type);
void StartBattleAnimResireHitEffects(struct Anim * anim, int type);
void StartBattleAnimStatusChgHitEffects(struct Anim * anim, int type);
struct Anim * EfxCreateFrontAnim(struct Anim * anim, const AnimScr * scr1, const AnimScr * scr2, const AnimScr * scr3, const AnimScr * scr4);
struct Anim * EfxCreateBackAnim(struct Anim * anim, const AnimScr * scr1, const AnimScr *scr2, const AnimScr * scr3, const AnimScr * scr4);
void SpellFx_WriteBgMap(struct Anim * anim, const u16 * src1, const u16 * src2);
void SpellFx_RegisterObjGfx(const void * img, u32 size);
void SpellFx_RegisterObjPal(const u16 * pal, u32 size);
void SpellFx_RegisterBgGfx(const void * img, u32 size);
void SpellFx_RegisterBgPal(const u16 * pal, u32 size);
s16 EfxAdvanceFrameLut(s16 *ptime, s16 *pcount, const s16 lut[]);
int EfxGetCamMovDuration(void);
void EfxTmFill(u32 val);
void SetEkrFrontAnimPostion(int pos, s16 x, s16 y);
int sub_8050FE4(void);
void sub_8050FF0(int);
void NewEfxspdquake(struct Anim * anim);
bool SetupBanim(void);
void BeginAnimsOnBattleAnimations(void);
void NewEkrUnitKakudai(int identifier);
void NewEkrWindowAppear(int identifier, int);
bool CheckEkrWindowAppearUnexist(void);
void NewEkrNamewinAppear(int identifier, int duration, int delay);
bool PrepareBattleGraphicsMaybe(void);
u16 GetBattleAnimationId_WithUnique(struct Unit * unit, const struct BattleAnimDef * pBattleAnimDef, u16, int * out);
void ParseBattleHitToBanimCmd(void);
bool CheckBattleHasHit(void);
s16 GetBattleAnimCharacterUniquePalIndex(struct Unit * unit, int index);
u16 * FilterBattleAnimCharacterPalette(s16 index, u16 item);
int GetAllegienceId(u32 arg);
void EkrPrepareBanimfx(struct Anim * anim, u16 index);
s16 GetBattleAnimRoundType(int index);
s16 GetBattleAnimRoundTypeFlags(int);
s16 GetEfxHp(int index);
s16 GetEfxHpModMaybe(int index);
u16 IsItemDisplayedInBattle(u16 item);
u16 IsWeaponLegency(u16 item);
bool EkrCheckAttackRound(u16 round);
void SetBattleScriptted(void);
void SetBattleUnscriptted(void);
bool CheckBattleScriptted(void);
void BattleAIS_ExecCommands(void);
void AnimScrAdvance(struct Anim * anim);
struct ProcEkrChienCHR {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
    unsigned char _pad_0x29[(0x5C) - (0x29)];
             struct Anim * anim;
};
void NewEkrChienCHR(struct Anim * anim);
void EkrChienCHRMain(struct ProcEkrChienCHR * proc);
void RegisterAISSheetGraphics(struct Anim * anim);
void ApplyBanimUniquePalette(u32 * buf, int pos);
int GetBanimPalette(int banim_id, int pos);
void UpdateBanimFrame(void);
void InitMainAnims(void);
void InitBattleAnimFrame(int round_type_left, int round_type_right);
void InitLeftAnim(int);
void InitRightAnim(int);
void SwitchAISFrameDataFromBARoundType(struct Anim * anim, int);
int GetAISLayerId(struct Anim * anim);
int GetAnimPosition(struct Anim * anim);
int CheckRoundMiss(s16 type);
int CheckRound1(s16 type);
int CheckRound2(s16 type);
int CheckRoundCrit(struct Anim * anim);
struct Anim * GetAnimAnotherSide(struct Anim * anim);
s16 GetAnimRoundType(struct Anim * anim);
s16 GetAnimNextRoundType(struct Anim * anim);
s16 GetAnimRoundTypeAnotherSide(struct Anim * anim);
s16 GetAnimNextRoundTypeAnotherSide(struct Anim * anim);
void SetAnimStateHidden(int pos);
void SetAnimStateUnHidden(int pos);
struct BanimUnkStructComm {
             s16 unk00;
             s16 unk02;
             s16 unk04;
             s16 unk06;
             s16 unk08;
             s16 unk0A;
             s16 unk0C;
             s16 unk0E;
             u16 unk10;
             ProcPtr proc14;
             ProcPtr proc18;
             void * unk1C;
             void * unk20;
             void * unk24;
};
struct AnimMagicFxBuffer
{
             u16 magic_func_idx;
             u16 x_offset_bg;
             u16 y_offset_bg;
             u16 x_offset_obj;
             u16 y_offset_obj;
             u16 bg_chr;
             u16 bg_pal_id;
             u16 obj_chr;
             u16 obj_pal_id;
             u16 bg;
             u16 * bg_tm_buf;
             void * bg_img_buf;
             void * bg_tsa_buf;
             void * obj_img_buf;
             void (*reset_callback)(void);
};
struct AnimBuffer {
             u8 unk_00;
             u8 genericPalId;
             u16 xPos;
             u16 yPos;
             s16 animId;
             s16 charPalId;
             u16 roundType;
             u16 state2;
             u16 oam2Tile;
             u16 oam2Pal;
             struct Anim * anim1;
             struct Anim * anim2;
             void * pImgSheetBuf;
             void * unk_20;
             void * unk_24;
             void * unk_28;
             const void * unk_2C;
             void * unk_30;
             void * unk_34;
};
extern struct BanimUnkStructComm EkrMainMiniConf_0201FAD0;
void sub_8055474(struct AnimBuffer *);
void sub_80555F8(struct AnimBuffer *, s16, s16);
void sub_8055644(struct AnimBuffer *);
void NewEfxAnimeDrvProc(void);
void EndEfxAnimeDrvProc(void);
void NewEkrUnitMainMini(struct AnimBuffer *);
void sub_80556D8(struct AnimBuffer *);
void sub_8055718(struct BanimUnkStructComm * conf);
void StartSpellAnimation(struct Anim * anim);
void NewEfxRestWINH_(struct Anim *anim, int a, int b);
void NewEfxALPHA(struct Anim * anim, int a, int b, int c, int d, int e);
void StartSpellThing_MagicQuake(struct Anim *, int, int);
void NewEfxPierceCritical(struct Anim * anim);
void NewEfxNormalEffect(struct Anim * anim);
void NewEfxYushaSpinShield(struct Anim * anim, int type);
void NewEfxHurtmutEff00(struct Anim * anim);
void NewEfxMagfcast(struct Anim * anim, int);
void NewEfxSunakemuri(struct Anim * anim, int);
void NewEfxLokmsuna(struct Anim * anim);
void NewEfxKingPika(struct Anim * anim);
void NewEfxFlashFX(struct Anim * anim);
void NewEfxSpecalEffect(struct Anim *anim);
void NewEfxMantBatabata(struct Anim *anim);
void NewEfxChillEffect(struct Anim *anim);
void NewEfxChillAnime(struct Anim * anim, int);
struct ProcEfxDrsmmoyaBG {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
    unsigned char _pad_0x29[(0x2C) - (0x29)];
             s16 timer;
    unsigned char _pad_0x2E[(0x44) - (0x2E)];
             u32 frame;
             const u16 * frame_config;
             u16 ** tsal;
             u16 ** tsar;
             u16 ** img;
             u16 * img_bak;
             struct Anim * anim;
};
struct ProcEfxDrsmmoyaScroll {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
    unsigned char _pad_0x29[(0x2C) - (0x29)];
             s16 timer;
             s16 step;
    unsigned char _pad_0x30[(0x44) - (0x30)];
             int duration;
             int speed;
    unsigned char _pad_0x4C[(0x5C) - (0x4C)];
             struct Anim * anim;
};
struct ProcEfxDrsmmoyaScrollCOL {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
    unsigned char _pad_0x29[(0x2C) - (0x29)];
             s16 timer;
    unsigned char _pad_0x2E[(0x44) - (0x2E)];
             int duration1;
             int duration2;
             int duration3;
    unsigned char _pad_0x50[(0x5C) - (0x50)];
             struct Anim * anim;
    unsigned char _pad_0x60[(0x64) - (0x60)];
             struct ProcEfxDrsmmoyaScroll * procefx;
};
void NewEfxDrsmmoya(struct Anim * anim);
void EfxDrsmmoya_Loop(struct ProcEfx * proc);
void NewEfxDrsmmoyaBG(struct Anim * anim);
void EfxDrsmmoyaBG_Loop(struct ProcEfxDrsmmoyaBG * proc);
ProcPtr NewEfxDrsmmoyaScroll(struct Anim * anim, int type);
void EfxDrsmmoyaScroll_Loop(struct ProcEfxDrsmmoyaScroll * proc);
void NewEfxDrsmmoyaScrollCOL(struct Anim * anim, struct ProcEfxDrsmmoyaScroll * procefx, int duration1, int duration2, int duration3);
void EfxDrsmmoyaScrollCOL_Loop1(struct ProcEfxDrsmmoyaScrollCOL * proc);
void EfxDrsmmoyaScrollCOL_Delay(struct ProcEfxDrsmmoyaScrollCOL * proc);
void EfxDrsmmoyaScrollCOL_Loop3(struct ProcEfxDrsmmoyaScrollCOL * proc);
void sub_80647C8(void);
void sub_80647F8(void);
void sub_8067128(u16 * tm, u16 width, u16 height, int pal, int chr);
void FillBGRect(u16 * tm, u16 width, u16 height, int pal, int chr);
void sub_80671E0(u16 * tm, u16 width, u16 height, int pal, int chr);
void EfxTmModifyPal(u16 * tm, u16 width, u16 height);
void EfxTmCpyBG(const void * ptr1, void * ptr2, u16 width, u16 height, int pal, int chr);
void EfxTmCpyBgHFlip(const u16 * tsa, u16 * tm, u16 width, u16 height, int pal, int chr);
void EfxTmCpyExt(const u16 * src, s16 src_width, u16 * dst, s16 dst_width, u16 width, u16 hight, int pal, int chr);
void EfxTmCpyExtHFlip(const u16 * src, s16 src_width, u16 * dst, s16 dst_width, u16 width, u16 hight, int pal, int chr);
void sub_806748C(u16 * tm, int arg1, int arg2);
void EkrModifyBarfx(u16 * tm, int arg);
bool EkrPalModifyUnused(u16 * pal_start, u16 * pal_end, u16 * dst, u16 amount, u16 start, u16 end);
void EfxPalBlackInOut(u16 * pal_buf, int line, int length, int ref);
void EfxPalWhiteInOut(u16 * pal_buf, int line, int length, int ref);
void EfxPalFlashingInOut(u16 * pal_buf, int line, int length, int r0, int g0, int b0);
void EfxPalModifyPetrifyEffect(u16 * pal_buf, int line, int length);
void EfxSplitColor(u16 * pal, u8 * dst, u32 length);
void EfxSplitColorPetrify(u16 * src, u8 * dst, u32 length);
void sub_8067998(s8 * src1, s8 * src2, u16 * pal, u32 length, int ref);
void EfxDecodeSplitedPalette(u16 * dst, s8 * src1, s8 * src2, s16 * src3, u32 length, int ref, int unk);
void EfxChapterMapFadeOUT(int speed);
int sub_8067AD4(int a);
struct ProcEkrSubAnimeEmulator * NewEkrsubAnimeEmulator(int x, int y, u32 * anim_scr, int type, int oam2Base, int oamBase, ProcPtr parent);
void EkrsubAnimeEmulatorMain(struct ProcEkrSubAnimeEmulator * proc);
int GetAnimSpriteRotScaleX(u32 header);
int GetAnimSpriteRotScaleY(u32 header);
void BanimUpdateSpriteRotScale(void * src, struct AnimSpriteData * out, s16 x, s16 y, int unused);
struct ProcEfxSoundSE {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
    unsigned char _pad_0x29[(0x2C) - (0x29)];
             s16 timer;
    unsigned char _pad_0x2E[(0x44) - (0x2E)];
             int volume;
             int index;
};
void EfxPlaySE(int songid, int volume);
void Loop6C_efxSoundSE(struct ProcEfxSoundSE * proc);
void EfxPlaySEwithCmdCtrl(struct Anim * anim, int);
s16 sub_80684B0(struct Anim * anim);
void PlaySFX(int, int, int, int);
extern struct ProcCmd ProcScr_ekrDispUP[];
extern struct ProcCmd ProcScr_efxHPBar[];
extern struct ProcCmd ProcScr_EfxQuakePure[];
extern struct ProcCmd ProcScr_EfxHitQuake[];
extern struct ProcCmd ProcScr_efxFlashBG[];
extern struct ProcCmd ProcScr_efxWhiteOUT[];
extern struct ProcCmd ProcScr_efxWhiteIN[];
extern struct ProcCmd ProcScr_efxStatusUnit[];
extern struct ProcCmd ProcScr_EfxWeaponIcon[];
extern  AnimScr AnimScr_DefaultAnim[];
extern struct ProcCmd ProcScr_EkrChienCHR[];
extern struct ProcCmd ProcScr_efxRestRST[];
extern struct ProcCmd ProcScr_efxTwobaiRST[];
extern struct ProcCmd ProcScr_DummvRST[];
extern struct ProcCmd ProcScr_EfxRestWIN[];
extern struct ProcCmd ProcScr_efxALPHA[];
extern struct ProcCmd ProcScr_EfxDrsmmoya[];
extern struct ProcCmd ProcScr_EfxDrsmmoyaBG[];
extern u16 * TsaSet_EfxDrsmmoyaBgLeft[];
extern u16 * TsaSet_EfxDrsmmoyaBgRight[];
extern struct ProcCmd ProcScr_EfxDrsmmoyaScroll[];
extern struct ProcCmd ProcScr_EfxDrsmmoyaScrollCOL[];
extern struct ProcCmd ProcScr_EfxPartsofScroll[];
extern const u8 BanimDefaultModeConfig[ANIM_ROUND_MAX * 4];
extern const u8 BattleTypeToAnimModeEndOfDodge[5];
extern const u8 BanimTypesPosLeft[5];
extern const u8 BanimTypesPosRight[5];
       
struct ProcEkrBattle {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             u8 speedup;
             unsigned char _pad_0x2A[(0x2C) - (0x2A)];
             s16 timer;
             s16 end;
             unsigned char _pad_0x30[(0x44) - (0x30)];
             int side;
             int counter;
             unsigned char _pad_0x4C[(0x54) - (0x4C)];
             int quote;
             int unk58;
             struct Anim * anim;
};
extern struct ProcEkrBattle * gpProcEkrBattle;
void SetBanimLinkArenaFlag(int unk);
int GetBanimLinkArenaFlag(void);
void NewEkrBattleDeamon(void);
void EndEkrBattleDeamon(void);
s8 IsBattleDeamonActive(void);
void EkrBattleDeamon_OnEnd(void);
void EkrBattleDeamonMain(ProcPtr proc);
void NewEkrBattle(void);
void InBattleMainRoutine(void);
void MainUpdateEkrBattle(void);
void EkrBattle_End(struct ProcEkrBattle * proc);
void EkrBattle_Init(struct ProcEkrBattle * proc);
void EkrBattle_Main(struct ProcEkrBattle * proc);
void EkrBattleStartBattleQuote(struct ProcEkrBattle * proc);
void EkrBattleWaitBattleQuote(struct ProcEkrBattle * proc);
void EkrBattleWaitWindowAppear(struct ProcEkrBattle * proc);
void EkrBattlePreDragonIntro(struct ProcEkrBattle * proc);
void EkrBattleExecDragonIntro(struct ProcEkrBattle * proc);
void EkrBattleWaitDragonIntro(struct ProcEkrBattle * proc);
void EkrBattlePostDragonIntro(struct ProcEkrBattle * proc);
void sub_804BE68(struct ProcEkrBattle * proc);
void sub_804BE84(struct ProcEkrBattle * proc);
void sub_804BED8(struct ProcEkrBattle * proc);
void sub_804BF0C(struct ProcEkrBattle * proc);
void sub_804BF34(struct ProcEkrBattle * proc);
void sub_804BFB8(struct ProcEkrBattle * proc);
void sub_804BFCC(struct ProcEkrBattle * proc);
void sub_804C008(struct ProcEkrBattle * proc);
void sub_804C034(struct ProcEkrBattle * proc);
void sub_804C130(struct ProcEkrBattle * proc);
void sub_804C144(struct ProcEkrBattle * proc);
void sub_804C1C8(struct ProcEkrBattle * proc);
void sub_804C20C(struct ProcEkrBattle * proc);
void sub_804C3F4(struct ProcEkrBattle * proc);
void sub_804C440(struct ProcEkrBattle * proc);
void sub_804C4AC(struct ProcEkrBattle * proc);
void sub_804C588(struct ProcEkrBattle * proc);
void sub_804C5BC(struct ProcEkrBattle * proc);
void EkrBattleLvupHanlder(struct ProcEkrBattle * proc);
void EkrBattleExecEkrLvup(struct ProcEkrBattle * proc);
void EkrBattleWaitLvup(struct ProcEkrBattle * proc);
void EkrBattleExecPopup(struct ProcEkrBattle * proc);
void EkrBattleWaitPopup(struct ProcEkrBattle * proc);
void EkrBattlePrepareEnding(struct ProcEkrBattle * proc);
void EkrBattleStartDragonEnding(struct ProcEkrBattle * proc);
void EkrBattleWaitDragonEnding(struct ProcEkrBattle * proc);
void EkrBattlePostDragonEnding(struct ProcEkrBattle * proc);
void EkrBattlePostEndDelay(struct ProcEkrBattle * proc);
       
void SetSramFastFunc(void);
void WriteSramFast(void const * src, void * dest, u32 size);
u32 WriteAndVerifySramFast(void const * src, void * dest, u32 size);
extern u32 (* VerifySramFast)(void const * src, void * dest, u32 size);
extern void (* ReadSramFast)(void const * src, void * dest, u32 size);
       
void m4aSoundInit(void);
void m4aSoundMode(u32 mode);
void m4aSoundMain(void);
void m4aSoundVSync(void);
void m4aSoundVSyncOn(void);
void m4aSoundVSyncOff(void);
void m4aSongNumStart(u16 n);
void m4aSongNumStartOrChange(u16 n);
void m4aSongNumStartOrContinue(u16 n);
void m4aSongNumStop(u16 n);
void m4aMPlayAllStop(void);
       
struct BmSt {
             bool main_loop_ended;
             s8 lock;
             s8 lock_display;
             u8 pad_03;
             u8 flags;
             u16 main_loop_end_scanline;
             int pad_08;
             struct Vec2 camera;
             struct Vec2 camera_previous;
             struct Vec2 cursor;
             struct Vec2 cursor_previous;
             struct Vec2 cursor_sprite_target;
             struct Vec2 cursor_sprite;
             struct Vec2 map_render_anchor;
             struct Vec2 camera_max;
             u16 inventory_item_overflow;
             u16 convoy_item_overflow;
             bool8 unk_30;
             bool8 unk_31;
             short unk_32;
             short unk_34;
             s8 unk_36;
             s8 unk_37;
             u8 alt_blend_a_ca;
             u8 alt_blend_a_cb;
             u8 alt_blend_b_ca;
             u8 alt_blend_b_cb;
             u8 just_resumed;
             u8 partial_actions_taken;
             u8 swap_action_range_count;
             s8 unk_3F;
};
extern struct BmSt gBmSt;
enum BmSt_gameStateBits {
    BM_FLAG_0 = (1 << 0),
    BM_FLAG_1 = (1 << 1),
    BM_FLAG_2 = (1 << 2),
    BM_FLAG_3 = (1 << 3),
    BM_FLAG_4 = (1 << 4),
    BM_FLAG_5 = (1 << 5),
    BM_FLAG_LINKARENA = (1 << 6),
};
struct PlaySt {
             u32 time_saved;
             u32 time_chapter_started;
             u32 partyGoldAmount;
             u8 gameSaveSlot;
             u8 chapterVisionRange;
             s8 chapterIndex;
             u8 faction;
             u16 chapterTurnNumber;
             u8 xCursor, yCursor;
             u8 chapterStateBits;
             u8 chapterWeatherId;
             u16 chapterTotalSupportGain;
             u8 playthroughIdentifier;
             u8 unk19;
             u8 lastUnitSortType;
             u8 chapterModeIndex;
             u8 unk1C[2];
             u8 unk1E;
             u8 unk1F;
             char playerName[0x2B - 0x20];
             u8 tact_enabled : 0x01;
             u8 tact_blood : 0x03;
             u8 tact_birth : 0x04;
    u32 tact_gender : 0x01;
    u32 unk2C_01 : 0x03;
    u32 unk2C_04 : 0x09;
    u32 unk2C_0D : 0x03;
    u32 unk2C_10 : 0x07;
    u32 unk2C_17 : 0x05;
    u32 unk2C_1C : 0x04;
             int total_gold;
             u32 unk_34_00 : 0x14;
             u32 unk_34_14 : 0x0C;
    u32 unk_38_1:8;
    u32 unk_38_2:20;
    u32 unk_38_3:4;
             u32 unk_3C_00 : 6;
             u32 combatRank : 3;
             u32 expRank : 3;
             u32 unk_3D_04 : 3;
             u32 fundsRank : 3;
             u32 tacticsRank : 3;
             u32 survivalRank : 3;
             u32 unk_3F_00 : 8;
    u32 cfgUnitColor:1;
    u32 cfgDisableTerrainDisplay:1;
    u32 cfgUnitDisplayType:2;
    u32 cfgAutoCursor:1;
    u32 cfgTextSpeed:2;
    u32 cfgGameSpeed:1;
    u32 cfgDisableBgm:1;
    u32 cfgDisableSoundEffects:1;
    u32 config_window_theme:2;
    u32 unk41_5:1;
    u32 unk41_6:1;
    u32 cfgDisableAutoEndTurns:1;
    u32 cfgNoSubtitleHelp:1;
    u32 cfgDisableGoalDisplay:1;
    u32 cfgAnimationType:2;
    u32 cfgBattleForecastType:2;
    u32 cfgController:1;
    u32 cfgRankDisplay:1;
    u32 debugControlRed:2;
    u32 debugControlGreen:2;
    u32 unk43_4:5;
    u8 unk44[0x48 - 0x44];
};
extern struct PlaySt gPlaySt;
enum PlaySt_chapterModeIndex {
    CHAPTER_MODE_LYN = 1,
    CHAPTER_MODE_ELIWOOD,
    CHAPTER_MODE_HECTOR,
};
enum PlaySt_chapterStateBits {
    PLAY_FLAG_STATSCREENPAGE0 = (1 << 0),
    PLAY_FLAG_STATSCREENPAGE1 = (1 << 1),
    PLAY_FLAG_POSTGAME = (1 << 2),
    PLAY_FLAG_TUTORIAL = (1 << 3),
    PLAY_FLAG_PREPSCREEN = (1 << 4),
    PLAY_FLAG_COMPLETE = (1 << 5),
    PLAY_FLAG_HARD = (1 << 6),
    PLAY_FLAG_EXTRA_MAP = (1 << 7),
    PLAY_FLAG_STATSCREENPAGE_SHIFT = 0,
    PLAY_FLAG_STATSCREENPAGE_MASK = PLAY_FLAG_STATSCREENPAGE0 | PLAY_FLAG_STATSCREENPAGE1,
};
enum PlaySt_Weather {
    WEATHER_FINE = 0,
    WEATHER_SNOW = 1,
    WEATHER_SNOWSTORM = 2,
    WEATHER_NIGHT = 3,
    WEATHER_RAIN = 4,
    WEATHER_FLAMES = 5,
    WEATHER_SANDSTORM = 6,
    WEATHER_CLOUDS = 7
};
struct ProcBmMain {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
    unsigned char _pad_0x29[(0x3C) - (0x29)];
             u8 flag;
    unsigned char _pad_0x3D[(0x46) - (0x3D)];
             u8 unk_46;
};
struct CamMoveProc
{
             const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             struct Vec2 to;
             struct Vec2 from;
             struct Vec2 watchedCoord;
             short calibration;
             short distance;
             int frame;
             bool8 xCalibrated;
};
struct UnkMapCursorProc
{
             const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             struct Vec2 to;
             struct Vec2 from;
             int clock;
             int duration;
};
enum
{
    MAP_CURSOR_DEFAULT,
    MAP_CURSOR_REGULAR,
    MAP_CURSOR_RED_MOVING,
    MAP_CURSOR_STRETCHED,
    MAP_CURSOR_RED_STATIC,
};
enum
{
    CAMERA_MARGIN_LEFT = 16 * 3,
    CAMERA_MARGIN_RIGHT = 16 * 11,
    CAMERA_MARGIN_TOP = 16 * 2,
    CAMERA_MARGIN_BOTTOM = 16 * 7,
};
void OnVBlank(void);
void OnMain(void);
void LockGame(void);
void UnlockGame(void);
u8 GetGameLock(void);
void HandleChangePhase(void);
bool CallChapterStartEventMaybe(void);
bool BmMain_ChangePhase(void);
bool sub_8015840(void);
void BmMain_StartPhase(ProcPtr proc);
void BmMain_ResumePlayerPhase(ProcPtr proc);
bool BmMain_UpdateTraps(ProcPtr proc);
void BmMain_SuspendBeforePhase(void);
void sub_8015918(ProcPtr proc);
void BmMain_StartIntroFx(struct ProcBmMain * proc);
void sub_8015988(void);
void InitBmBgLayers(void);
void ApplySystemObjectsGraphics(void);
void ApplySystemGraphics(void);
void HandleMapCursorInput(u16 keys);
void HandleMoveMapCursor(int step);
void HandleMoveCameraWithMapCursor(int step);
u16 GetCameraAdjustedX(int x);
u16 GetCameraAdjustedY(int y);
u16 GetCameraCenteredX(int x);
u16 GetCameraCenteredY(int y);
void PutMapCursor(int x, int y, int kind);
void DisplayBmTextShadow(int x, int y);
void SetMapCursorPosition(int x, int y);
void PutSysArrow(int x, int y, u8 is_down);
void CamMove_Init(struct CamMoveProc * proc);
void CamMove_OnLoop(struct CamMoveProc * proc);
void StoreAdjustedCameraPositions(int xIn, int yIn, int * xOut, int * yOut);
bool EnsureCameraOntoCenteredPosition(ProcPtr parent, int x, int y);
bool EnsureCameraOntoPosition(ProcPtr parent, int x, int y);
bool IsCameraNotWatchingPosition(int x, int y);
bool CameraMove_801622C(ProcPtr parent);
void UnkMapCursor_OnLoop(struct UnkMapCursorProc * proc);
void sub_80162E0(int x, int y, int duration);
int GetActiveMapSong(void);
void StartMapSongBgm(void);
void sub_8016410(struct CamMoveProc * proc);
void nullsub_37(void);
extern s8 sDirKeysToOffsetLut[][2];
extern u16 Sprite_MapCursorStretched[];
extern u16 * sMapCursorSpriteLut[];
extern u16 * gSysUpArrowSpriteLut[];
extern u16 * gSysDownArrowSpriteLut[];
extern struct ProcCmd ProcScr_CamMove[];
extern struct ProcCmd ProcScr_UnkMapCursor[];
       
enum trap_types {
    TRAP_NONE = 0,
    TRAP_BALLISTA = 1,
    TRAP_OBSTACLE = 2,
    TRAP_MAPCHANGE = 3,
    TRAP_FIRETILE = 4,
    TRAP_GAS = 5,
    TRAP_MAPCHANGE2 = 6,
    TRAP_LIGHTARROW = 7,
    TRAP_8 = 8,
    TRAP_9 = 9,
    TRAP_TORCHLIGHT = 10,
    TRAP_MINE = 11,
    TRAP_GORGON_EGG = 12,
    TRAP_LIGHT_RUNE = 13,
};
struct Trap {
             u8 xPos;
             u8 yPos;
             u8 type;
             u8 extra;
             s8 data[4];
};
struct Trap *GetTrap(int id);
void ClearTraps(void);
struct Trap *GetTrapAt(int x, int y);
void ApplyMapChange(int index);
void AddMapChangeTrap(int id);
void RefreshTerrainMap(void);
       
enum
{
    MAX_SIMULTANEOUS_SUPPORT_COUNT_PER_UNIT = 5,
    SUPPORT_BONUSES_MAX_DISTANCE = 3,
};
enum
{
    SUPPORT_LEVEL_NONE,
    SUPPORT_LEVEL_C,
    SUPPORT_LEVEL_B,
    SUPPORT_LEVEL_A,
};
enum
{
    SUPPORT_EXP_C = 81,
    SUPPORT_EXP_B = 161,
    SUPPORT_EXP_A = 241,
};
enum
{
    AFFINITY_1 = 1,
    AFFINITY_2 = 2,
    AFFINITY_3 = 3,
    AFFINITY_4 = 4,
    AFFINITY_5 = 5,
    AFFINITY_6 = 6,
    AFFINITY_7 = 7,
};
struct SupportData
{
             u8 pids[UNIT_SUPPORT_MAX_COUNT];
             u8 exp_base[UNIT_SUPPORT_MAX_COUNT];
             u8 exp_growth[UNIT_SUPPORT_MAX_COUNT];
             u8 count;
};
struct SupportBonuses {
             u8 affinity;
             u8 bonus_attack;
             u8 bonus_defense;
             u8 bonus_hit;
             u8 bonus_avoid;
             u8 bonus_crit;
             u8 bonus_dodge;
};
int GetUnitSupporterCount(struct Unit * unit);
u8 GetUnitSupportPid(struct Unit * unit, int num);
struct Unit * GetUnitSupportUnit(struct Unit * unit, int num);
int GetUnitSupportLevel(struct Unit * unit, int num);
int GetUnitTotalSupportLevel(struct Unit * unit);
void UnitGainSupportExp(struct Unit * unit, int num);
void UnitGainSupportLevel(struct Unit * unit, int num);
bool CanUnitSupportNow(struct Unit * unit, int num);
int GetUnitInitialSupportExp(struct Unit * unit, int num);
int GetUnitSupportNumByPid(struct Unit * unit, u8 pid);
void ClearUnitSupports(struct Unit * unit);
void DoTurnSupportExp(void);
const struct SupportBonuses * GetAffinityBonuses(int affinity);
void ApplyAffinityBonuses(struct SupportBonuses * bonuses, int affinity, int level);
void InitBonuses(struct SupportBonuses * bonuses);
int GetUnitSupportBonuses(struct Unit * unit, struct SupportBonuses * bonuses);
int GetUnitAffinityIcon(struct Unit * unit);
int GetAffinityIconByPid(int pid);
int GetSupportLevelSpecialChar(int level);
char const * GetAffinityName(int affinity);
void SetSupportLevelGained(u8 pid_a, u8 pid_b);
bool HasUnitGainedSupportLevel(struct Unit * unit, int num);
bool ArePidsAtMaxSupport(u8 pid_a, u8 pid_b);
void SwapUnitStats(struct Unit * unit_a, struct Unit * unit_b);
       
void RandInit(int seed);
void RandSetSt(u16 const * st);
void RandGetSt(u16 * st);
int RandNext_100(void);
int RandNext(int max);
bool RandRoll(int threshold);
bool RandRoll2Rn(int threshold);
void RandInitB(int seed);
u32 RandNextB(void);
       
struct EkrDragonStatus {
             u16 type;
             u16 attr;
             ProcPtr proc;
             u32 unk08;
             struct Anim * anim;
};
enum dragonstatue_attr {
    EKRDRGON_ATTR_START = 1 << 0,
    EKRDRGON_ATTR_BANIMFX_PREPARED = 1 << 1,
    EKRDRGON_ATTR_BANIMFINISH = 1 << 2,
    EKRDRGON_ATTR_END = 1 << 3,
    EKRDRGON_ATTR_DEAD = 1 << 12,
};
extern struct EkrDragonStatus gEkrDragonStatusLeft, gEkrDragonStatusRight;
void ResetEkrDragonStatus(void);
struct EkrDragonStatus * GetEkrDragonStatus(struct Anim * anim);
u16 GetEkrDragonStatusAttr(struct Anim * anim);
void AddEkrDragonStatusAttr(struct Anim * anim, u16 attr_bitfile);
u32 GetEkrDragonStatusType(struct Anim * anim);
u32 GetEkrDragonStatusType_(struct Anim * anim);
void AddEkrDragonStatusType(struct Anim * anim, u16 type_bitfile);
int CheckInEkrDragon(void);
void EkrDragonTmCpyHFlip(int x, int y);
void EkrDragonTmCpyExt(int x, int y);
void EkrDragonTmCpyWithDistance(void);
bool EkrDragonIntroDone(struct Anim * anim);
bool CheckEkrDragonEndingDone(struct Anim * anim);
void SetEkrDragonExit(struct Anim * anim);
void SetEfxDragonDeadFallHead(struct Anim * anim);
bool CheckEfxDragonDeadFallHead(struct Anim * anim);
struct ProcEkrDragonIntroFx {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             bool unk29;
             u16 unk2A;
             s16 timer;
             s16 timer2;
    unsigned char _pad_0x30[(0x32) - (0x30)];
             u16 x;
             s16 x_hi;
    unsigned char _pad_0x36[(0x3A) - (0x36)];
             s16 y;
             s16 y_hi;
    unsigned char _pad_0x3E[(0x44) - (0x3E)];
             int duration;
             int step;
             int speed;
             int unk50;
};
struct ProcEkrDragonFx {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             u8 done;
             s16 unk2A;
             s16 timer;
             s16 step;
             s16 unk30;
             s16 x;
    unsigned char _pad_0x34[(0x3A) - (0x34)];
             u16 y;
             u16 y_hi;
    unsigned char _pad_0x3E[(0x44) - (0x3E)];
             u32 frame;
             const s16 * conf;
             u16 const * const * fx;
             u32 unk50;
             u32 round_cur;
             u32 unk58;
             struct Anim * anim;
             struct Anim * anim2;
             ProcPtr sprocfx;
};
struct ProcEkrDragon {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             u8 done;
    unsigned char _pad_0x2A[(0x2C) - (0x2A)];
             s16 timer;
             s16 terminator;
             s16 timer2;
             s16 x;
    unsigned char _pad_0x34[(0x3A) - (0x34)];
             s16 y_lo;
             s16 y_hi;
    unsigned char _pad_0x3E[(0x44) - (0x3E)];
             ProcPtr sproc_flashingobj;
             ProcPtr sproc_bg2fx;
             ProcPtr sproc_bg2scroll;
             struct ProcEkrDragon * mainfxproc;
             ProcPtr proc54;
             ProcPtr sproc_bg2scrollhandle;
             struct Anim * anim;
             ProcPtr sproc1;
             struct ProcEkrDragonIntroFx * procfx;
             ProcPtr sproc_flashingbg;
};
extern struct ProcCmd  ProcScr_EkrDragon[];
extern u16 gEkrBgPaletteBackup[0x20];
void InitEkrDragonStatus(void);
void EkrDragonUpdateFlashingUnit(struct Anim * anim);
void BanimSetFrontPaletteForDragon(struct Anim * anim);
void EkrDragonUpdatePal_08065510(int ref);
void NewEkrDragon(struct Anim * anim);
void EkrDragon_Preparefx(struct ProcEkrDragon * proc);
void EkrDragon_CustomBgFadeIn(struct ProcEkrDragon * proc);
void EkrDragon_StartDragonTailIntro(struct ProcEkrDragon * proc);
void EkrDragon_DragonTailDisplay(struct ProcEkrDragon * proc);
void EkrDragon_StartMainBodyIntro(struct ProcEkrDragon * proc);
void EkrDragon_PreMainBodyIntro(struct ProcEkrDragon * proc);
void EkrDragon_StartMainBodyFallIn(struct ProcEkrDragon * proc);
void EkrDragon_WaitMainBodyFallIn(struct ProcEkrDragon * proc);
void EkrDragon_PreBattleBark(struct ProcEkrDragon * proc);
void EkrDragon_TriggerIntroDone(struct ProcEkrDragon * proc);
void EkrDragon_InBattleIDLE(struct ProcEkrDragon * proc);
void EkrDragon_WaitForFadeOut(struct ProcEkrDragon * proc);
void EkrDragon_ReloadTerrainEtc(struct ProcEkrDragon * proc);
void EkrDragon_ReloadCustomBgAndFadeOut(struct ProcEkrDragon * proc);
void EkrDragon_TriggerEnding(struct ProcEkrDragon * proc);
extern  struct ProcCmd ProcScr_EkrDragonBaseHide[];
ProcPtr NewEkrDragonBaseHide(struct Anim * anim);
void EkrDragonBaseHide_Loop(struct ProcEkrDragonFx * proc);
void EkrDragonBaseHide_Nop(struct ProcEkrDragonFx * proc);
extern  struct ProcCmd ProcScr_EkrDragonBaseAppear[];
ProcPtr NewEkrDragonBaseAppear(struct Anim * anim);
void EkrDragonBaseAppear_Loop(struct ProcEkrDragonFx * proc);
void EkrDragonBaseAppear_Nop(struct ProcEkrDragonFx * proc);
extern  struct ProcCmd ProcScr_EkrDragonTunkFace[];
ProcPtr NewEkrDragonTunkFace(struct Anim * anim);
void EkrDragonTunkFace_Loop(struct ProcEkrDragonFx * proc);
extern  struct ProcCmd ProcScr_EfxDragonDeadFallBody[];
ProcPtr NewEfxDragonDeadFallBody(struct Anim * anim);
void EfxDragonDeadFallBody_CallBack(struct ProcEkrDragonFx * proc);
void EfxDragonDeadFallBody_Loop1(struct ProcEkrDragonFx * proc);
void EfxDragonDeadFallBody_Loop2(struct ProcEkrDragonFx * proc);
void EfxDragonDeadFallBody_Blocking(struct ProcEkrDragonFx * proc);
extern  struct ProcCmd ProcScr_EfxDragonDeadFallHeadFx[];
ProcPtr NewEfxDragonDeadFallHeadFx(struct Anim * anim);
void EfxDragonDeadFallHead_CallBack(struct ProcEkrDragonFx * proc);
void EfxDragonDeadFallHead_Loop1(struct ProcEkrDragonFx * proc);
void EfxDragonDeadFallHead_Loop2(struct ProcEkrDragonFx * proc);
struct ProcEkrDragonStatusFlashing {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             u8 fxtype;
    unsigned char _pad_0x2A[(0x2C) - (0x2A)];
             s16 timer;
    unsigned char _pad_0x2E[(0x44) - (0x2E)];
             u32 frame;
             const s16 * conf;
             const u16 * pal;
    unsigned char _pad_0x50[(0x54) - (0x50)];
             u32 round_cur;
    unsigned char _pad_0x58[(0x5C) - (0x58)];
             struct Anim * anim;
};
extern  struct ProcCmd ProcScr_EkrDragonFlashingWingBg[];
ProcPtr NewEkrDragonFlashingWingBg(struct Anim * anim);
void EkrDragonFlashingWingBg_Loop(struct ProcEkrDragonStatusFlashing * proc);
extern  struct ProcCmd ProcScr_EkrDragonFlashingWingObj[];
ProcPtr NewEkrDragonFlashingWingObj(struct Anim * anim);
void EkrDragonFlashingWingObj_Loop(struct ProcEkrDragonStatusFlashing * proc);
extern  struct ProcCmd ProcScr_EkrDragonFireBG2[];
ProcPtr NewEkrDragonFireBG2(struct Anim * anim);
void EkrDragonFireBG2_CallBackNop(struct ProcEkrDragonFx * proc);
void EkrDragonFireBG2_Blocking(struct ProcEkrDragonFx * proc);
extern  struct ProcCmd ProcScr_EkrDragonBg2ScrollHandler[];
ProcPtr NewEkrDragonBg2ScrollHandler(void);
void EkrDragonBg2ScrollHandler_Loop(struct ProcEkrDragonFx * proc);
extern  struct ProcCmd ProcScr_EkrDragonBg2ScrollExt[];
void EkrDragonBg2Scroll_OnVBlank(void);
ProcPtr NewEkrDragonBg2ScrollExt(struct Anim * anim);
void EkrDragonBg2ScrollExt_CallBack(void);
void EkrDragonBg2ScrollExt_Loop(void);
extern  struct ProcCmd ProcScr_EkrDragonBg3HfScrollHandler[];
ProcPtr NewEkrDragonBg3HfScrollHandler(int, int, int, int);
void EkrDragonBg3HfScrollHandler_Loop(struct ProcEkrDragonIntroFx * proc);
extern struct ProcCmd  ProcScr_EkrDragonBg3HfScroll[];
void EkrDragonBg3HfScroll_OnVBlank(void);
void NewEkrDragonBg3HfScroll(int, u16);
void EkrDragonBg3HfScroll_Nop(struct ProcEkrDragonIntroFx * proc);
void EkrDragonBg3HfScroll_Loop(struct ProcEkrDragonIntroFx * proc);
extern  struct ProcCmd ProcScr_EkrDragonFxMain[];
extern  const u16 * Tsas_EkrDragon_08C48874[];
ProcPtr NewEkrDragonFxMain(struct Anim * anim);
void EkrDragonFxMainHandler(struct ProcEkrDragonFx * proc);
extern  struct ProcCmd ProcScr_EkrDragonBodyBlack[];
ProcPtr NewEkrDragonBodyBlack(struct Anim * anim);
void EkrDragonBodyBlack_Loop(struct ProcEkrDragonFx * proc);
void EkrDragonBodyBlack_Nop(struct ProcEkrDragonFx * proc);
ProcPtr NewEkrDragonTunk(struct Anim * anim);
void sub_80668B8(int x, int y);
void sub_8066950(int x, int y);
void EkrDragonTunk_Loop1(struct ProcEkrDragon * proc);
void EkrDragonTunk_Loop2(struct ProcEkrDragon * proc);
void EkrDragonTunk_NopLoop(struct ProcEkrDragon * proc);
void NewEkrDragonFireBg3(struct Anim * anim, int);
void EkrDragonFireBG3_CallBack(struct ProcEkrDragonFx * proc);
void EkrDragonFireBG3_Loop(struct ProcEkrDragonFx * proc);
struct ProcEkrDragonBarkQuake {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
    unsigned char _pad_0x29[(0x2C) - (0x29)];
             s16 timer, duration;
    unsigned char _pad_0x30[(0x5C) - (0x30)];
             ProcPtr procfx;
             ProcPtr procquake;
};
void NewEkrDragonBarkQuake(ProcPtr parent, int duration, int strenuous);
void EkrDragonBarkQuake_Loop(struct ProcEkrDragonBarkQuake * proc);
struct ProcEkrDragonScreenFlashing {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
    unsigned char _pad_0x29[(0x2C) - (0x29)];
             s16 timer;
    unsigned char _pad_0x2E[(0x44) - (0x2E)];
             int dura1, dura2, dura3;
};
void NewEkrDragonScreenFlashing(int dura1, int dura2, int dura3);
void EkrDragonScreenFlashing_Loop1(struct ProcEkrDragonScreenFlashing * proc);
void EkrDragonScreenFlashing_Loop2(struct ProcEkrDragonScreenFlashing * proc);
void EkrDragonScreenFlashing_Loop3(struct ProcEkrDragonScreenFlashing * proc);
void EkrDragonScreenFlashing_RefrainPalette(struct ProcEkrDragonScreenFlashing * proc);
extern u16 Pal_EkrDragon[0x10];
extern const u16 Pals_EkrDragonFlashingWingBg[];
extern u16 Pal_EkrDragonFireBG2[0x10];
extern  struct ProcCmd ProcScr_EkrDragonTunk[];
extern  struct ProcCmd ProcScr_EkrDragonFireBG3[];
extern  struct ProcCmd ProcScr_EkrDragonBarkQuake[];
extern  struct ProcCmd ProcScr_EkrDragonScreenFlashing[];
extern  struct ProcCmd ProcScr_EkrDragonFlashingWingBg[];
extern  struct ProcCmd ProcScr_EkrDragonFlashingWingBg[];
extern  struct ProcCmd ProcScr_EkrDragonFlashingWingBg[];
extern AnimScr AnimScr_EfxDragonDeadFallBody[];
extern AnimScr AnimScr_08C49F4C[];
extern AnimScr AnimScr_EkrDragonHead[];
extern AnimScr AnimScr_EfxDragonDeadFallBody2[];
extern AnimScr AnimScr_EfxDragonDeadFallHeadFx[];
extern s16 EkrBg3HfScrollingConf[];
       
struct IconSt {
             u8 ref_count;
             u8 disp_id;
};
extern u8 const Img_Icons[];
extern u16 const Pal_Icons[];
extern struct IconSt IconStTable[0xB0];
extern u8 IconDisplayList[0x20];
void InitIcons(void);
void ClearIcons(void);
void ApplyIconPalettes(int palid);
void ApplyIconPalette(int num, int palid);
int CountActiveIcons(void);
u16 IconSlot2Chr(int num);
int GetNewIconSlot(int icon);
int GetIconChr(int icon);
void PutIcon(u16 *tm, int icon, int tileref);
void ClearIcon(int icon);
void PutIconObjImg(int icon, int chr);
       
enum proc_label_atmenu {
 PL_ATMENU_01 = 1,
 PL_ATMENU_02,
 PL_ATMENU_03,
 PL_ATMENU_04,
 PL_ATMENU_05,
 PL_ATMENU_06,
 PL_ATMENU_07,
 PL_ATMENU_08,
 PL_ATMENU_09,
 PL_ATMENU_0A,
 PL_ATMENU_0B,
 PL_ATMENU_0C,
 PL_ATMENU_0D,
 PL_ATMENU_0E,
 PL_ATMENU_0F,
 PL_ATMENU_10,
};
struct ProcAtMenu {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             u8 unit_count;
             u8 max_counter;
             u8 cur_counter;
             u8 unk_2C;
             u8 cur_cmd;
             u8 hand_pos;
             u8 cmd_mask;
             u8 unk_30;
             u8 unk_31;
             u8 unk_32;
             u8 state;
             u8 do_help;
             u8 unk_35;
             bool8 end_prep;
             u8 unk_38[0x3C - 0x38];
             u16 yDiff;
             u16 unk3E;
             u32 xDiff;
};
struct SioPidPool {
    u8 pids[8];
};
extern  struct SioPidPool gSioPidPool;
struct PrepUnitList {
    struct Unit *units[0x40];
    int max_num;
    int latest_pid;
};
extern  struct PrepUnitList gPrepUnitList;
struct PrepScreenItemListEnt {
             u8 pid;
             u8 itemSlot;
             u16 item;
};
extern  struct PrepScreenItemListEnt gPrepScreenItemList[400];
extern  struct PrepScreenItemListEnt gPrepScreenExtraItemList[400];
extern  u16 Unk_Prep_02012464;
extern  u16 Unk_Prep_02012466;
int GetPrepMainMenuInfoxMsg(void);
int PrepOptionCountToRealIndexByMask(int target, int mask);
int GetPrepOptionCount(int mask);
void PutPrepMenuUiImg(int vram, int palId);
void sub_808E454(u16 * tm, int b, u32 c, int d);
void PrepScreenMenu_OnPickUnits(struct ProcAtMenu * proc);
void PrepScreenMenu_OnItems(struct ProcAtMenu * proc);
void PrepScreenMenu_OnSupport(struct ProcAtMenu * proc);
void PrepScreenMenu_OnSave(struct ProcAtMenu * proc);
int PrepScreenMenu_OnStartPress(struct ProcAtMenu * proc);
int PrepScreenMenu_OnBPress(struct ProcAtMenu * proc);
void PrepScreenMenu_OnCheckMap(struct ProcAtMenu * proc);
void ResetSioPidPool(void);
void RegisterSioPid(u8 val);
void RemoveSioPid(u8 val);
struct Unit * GetUnitFromPrepList(int index);
void RegisterPrepUnitList(int index, struct Unit *);
int PrepGetUnitAmount();
void PrepSetUnitAmount(int);
int PrepGetLatestCharId();
void PrepSetLatestCharId(int val);
bool sub_808E7D4(struct Unit *unit);
bool IsUnitInCurrentRoster(struct Unit *unit);
int CanPrepScreenCheckMap(void);
void InitPrepScreenMainMenu(struct ProcAtMenu *proc);
int GetLatestUnitIndexInPrepListByUId(void);
int PrepGetLatestUnitIndex(void);
void ReorderPlayerUnitsBasedOnDeployment(void);
void SortPlayerUnitsForPrepScreen(void);
void RemoveSomeUnitItems(void);
void MakePrepUnitList(void);
int UnitGetIndexInPrepList(int pid);
void PrepUpdateSMS(void);
void PrepAutoCapDeployUnits(struct ProcAtMenu *proc);
void PrepRestartMuralBackground(void);
void EndMuralBackground_(void);
void Prep_DrawChapterGoal(int vram_offset, int pal_bank);
void PrepAtMenu_OnInit(struct ProcAtMenu *proc);
struct ProcPrepMenuDesc {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
    unsigned char _pad_0x29[(0x4C) - (0x29)];
             u16 unk4C;
    unsigned char _pad_0x4E[(0x58) - (0x4E)];
             int msg;
};
void PrepMenuDescOnInit(struct ProcPrepMenuDesc * proc);
void PrepMenuDescOnParse(struct ProcPrepMenuDesc * proc);
void PrepMenuDescOnDraw(void);
void StartPrepMenuDescHandler(int msg, ProcPtr parent);
void AtMenu_Reinitialize(struct ProcAtMenu *proc);
void EndPrepAtMenuIfNoUnitAvailable(struct ProcAtMenu *proc);
void AtMenu_UpdateDesc(struct ProcAtMenu *proc);
void AtMenu_SetupCtrlUI(struct ProcAtMenu *proc);
void AtMenu_CtrlLoop(struct ProcAtMenu *proc);
void AtMenuSetUnitStateAndEndFlag(struct ProcAtMenu *proc);
void AtMenu_ResetScreenEffect(struct ProcAtMenu *proc);
void AtMenu_ResetBmUiEffect(struct ProcAtMenu *proc);
void AtMenu_StartSubmenu(struct ProcAtMenu *proc);
void AtMenu_OnSubmenuEnd(struct ProcAtMenu *proc);
void AtMenu_LockGame(struct ProcAtMenu *proc);
void AtMenu_UnlockGame(struct ProcAtMenu *proc);
bool HasConvoyAccess_(void);
void AtUnkMenu_Reinitialize(struct ProcAtMenu *proc);
void sub_808FCAC(struct ProcAtMenu *proc);
void sub_808FCF8(struct ProcAtMenu *proc);
void sub_808FD10(struct ProcAtMenu *proc);
void sub_808FD7C(struct ProcAtMenu *proc);
void sub_808FDE8(struct ProcAtMenu *proc);
void sub_808FE6C(struct ProcAtMenu *proc);
void sub_808FED8(struct ProcAtMenu *proc);
void sub_808FEE0(struct ProcAtMenu *proc);
void ConvoyPromotion_Init(ProcPtr proc);
void sub_808FFD0(ProcPtr proc);
void NullExpForChar100AndResetScreen(ProcPtr proc);
void PrepPromoteDebugMaybe(struct ProcAtMenu *proc);
void sub_80900E8(struct ProcAtMenu *proc);
struct ProcPrepSpecialChar {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
    u8 unk_29;
    u8 unk_2A;
    u8 unk_2B;
    unsigned char _pad_0x2C[(0x2F) - (0x2C)];
             u8 config;
    unsigned char _pad_0x30[(0x32) - (0x30)];
             u8 blink_n;
             u16 timer;
             ProcPtr approc;
};
void ProcPrepSpChar_OnInit(struct ProcPrepSpecialChar *proc);
void ProcPrepSpChar_Idle(struct ProcPrepSpecialChar *proc);
void ProcPrepSpChar_OnEnd(struct ProcPrepSpecialChar *proc);
void PrepSpecialChar_BlinkButtonStart(void);
ProcPtr StartPrepSpecialCharEffect(ProcPtr parent);
void EndPrepSpecialCharEffect(void);
void PrepMenu_OnInit(ProcPtr proc);
void PrepMenu_CtrlLoop(ProcPtr proc);
void PrepMenu_ShowFrozenHand(ProcPtr proc);
void PrepMenu_ShowActiveHand(ProcPtr proc);
void PrepMenu_OnEnd(ProcPtr proc);
int GetActivePrepMenuItemIndex(void);
void EndPrepScreenMenu(void);
void EnablePrepScreenMenu(void);
void MenuScroll_Init(ProcPtr proc);
void MenuScroll_Loop(ProcPtr proc);
struct ProcPrepMuralBackground {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             u16 timer;
             u8 unk_2C;
             u8 pal_bank;
};
void PrepMuralBackground_Init(struct ProcPrepMuralBackground *proc);
void PrepMuralBackground_Loop(struct ProcPrepMuralBackground *proc);
void StartPrepMuralBackground(void *vram, int pal_bank);
void EndPrepMuralBackground(void);
struct SallyCirProc {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             u8 unk_29;
             s8 unk_2a;
             int unk_2c;
};
void SallyCir_Init(struct SallyCirProc *proc);
void SallyCir_Loop(struct SallyCirProc *proc);
void SallyCir_OnEnd(struct SallyCirProc *proc);
ProcPtr StartSallyCirProc(ProcPtr parent, u8 unk);
void ViewCounter_Loop(ProcPtr proc);
void TryLockProc(ProcPtr proc);
void TryUnlockProc(ProcPtr proc);
void PrepHbKeyListener_Loop(ProcPtr proc);
struct PrepItemTypePageEnt {
             u8 lowerBound;
             u8 upperBound;
};
struct PrepItemScreenProc {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
};
void PrepItemScreen_OnHBlank(void);
void PrepItemScreen_Init(struct PrepItemScreenProc * proc);
void PrepItemScreen_DrawFunds(void);
void PrepItemScreen_HideFunds(void);
void PrepItemScreen_SetupGfx(struct PrepItemScreenProc * proc);
void PrepItemScreen_OnEnd(struct PrepItemScreenProc * proc);
void PrepItemScreen_Reinit(struct PrepItemScreenProc * proc);
void PrepItemScreen_StartStatScreen(struct PrepItemScreenProc * proc);
void PrepItemScreen_ResumeFromStatScreen(struct PrepItemScreenProc * proc);
void sub_80926F0(struct PrepItemScreenProc * proc);
void sub_8092A1C(struct PrepItemScreenProc * proc);
void sub_8092A9C(struct PrepItemScreenProc * proc);
void sub_8092AF8(struct PrepItemScreenProc * proc);
void sub_8092B30(struct PrepItemScreenProc * proc);
void sub_8092EDC(struct PrepItemScreenProc * proc);
void sub_8093004(struct PrepItemScreenProc * proc);
void PrepItemScreen_Loop_MainKeyHandler(struct PrepItemScreenProc * proc);
void StartPrepItemTradeScreen(struct PrepItemScreenProc * proc);
void sub_8093198(struct PrepItemScreenProc * proc);
void sub_80931B0(struct PrepItemScreenProc * proc);
void StartPrepArmory(struct PrepItemScreenProc * proc);
void sub_80931E0(struct PrepItemScreenProc * proc);
struct ProcPrepUnit {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
};
void PrepUnit_DrawUnitListNames(struct ProcPrepUnit *proc, int line);
void PrepUpdateMenuTsaScroll(int val);
void PrepUnit_DrawSMSAndObjs(struct ProcPrepUnit *proc);
void PrepUnit_InitTexts(void);
void PrepUnit_InitGfx(void);
void PrepUnit_InitSMS(struct ProcPrepUnit *proc);
void PrepUnit_DrawLeftUnitName(struct Unit *unit);
void PrepUnit_DrawLeftUnitNameCur(struct ProcPrepUnit *proc);
void PrepUnit_DrawUnitItems(struct Unit *unit);
void PrepUnit_DrawPickLeftBar(struct ProcPrepUnit *proc, s8 val);
bool PrepCheckCanSelectUnit(struct ProcPrepUnit *proc, struct Unit *unit);
bool PrepCheckCanUnselectUnit(struct ProcPrepUnit *proc, struct Unit *unit);
bool PrepUnit_HandlePressA(struct ProcPrepUnit *proc);
bool ShouldPrepUnitMenuScroll(struct ProcPrepUnit *proc);
void ProcPrepUnit_OnInit(struct ProcPrepUnit *proc);
void ProcPrepUnit_InitScreen(struct ProcPrepUnit *proc);
void sub_8094374(struct ProcPrepUnit *proc);
void ProcPrepUnit_Idle(struct ProcPrepUnit *proc);
void sub_809463C(struct ProcPrepUnit *proc);
void sub_8094684(struct ProcPrepUnit *proc);
void sub_80946D0(struct ProcPrepUnit *proc);
void sub_80946E8(struct ProcPrepUnit *proc);
void sub_8094714(struct ProcPrepUnit *proc);
void ProcPrepUnit_OnEnd(struct ProcPrepUnit *proc);
void ProcPrepUnit_OnGameStart(struct ProcPrepUnit *proc);
void sub_80947C0(struct ProcPrepUnit *proc);
void sub_80947E0(struct ProcPrepUnit *proc);
void PrepUnitDisableDisp(struct ProcPrepUnit *proc);
void PrepUnitEnableDisp(struct ProcPrepUnit *proc);
void sub_809486C(struct ProcPrepUnit *proc);
void sub_8094888(struct ProcPrepUnit *proc);
extern  struct SioPidPool gSioPidPool;
extern  struct Text gPrepMainMenuTexts[10];
extern  u16 gBgConfig_PrepScreen[];
extern  int Msgs_PrepMainMenuHelpbox[][3];
extern struct ProcCmd ProcScr_PrepMenuDescHandler[];
extern struct ProcCmd ProcScr_PrepPromoteDebug[];
extern u16 Sprite_08D8CDBC[];
extern u16 Sprite_08D8CDD0[];
extern struct ProcCmd ProcScr_PrepItemUseScreen[];
       
enum videoalloc_savemenu {
    BGPAL_SAVEMENU_BG = 0,
    OBJPAL_SAVEMENU_WINDOW = 1,
};
enum save_menu_action_flag_bitfile {
    SAVEMENU_ACTION_BITFILE_0 = 1 << 0,
    SAVEMENU_ACTION_BITFILE_1 = 1 << 1,
    SAVEMENU_ACTION_BITFILE_2 = 1 << 2,
    SAVEMENU_ACTION_BITFILE_3 = 1 << 3,
    SAVEMENU_ACTION_BITFILE_4 = 1 << 4,
    SAVEMENU_ACTION_BITFILE_5 = 1 << 5,
    SAVEMENU_ACTION_BITFILE_6 = 1 << 6,
    SAVEMENU_ACTION_BITFILE_7 = 1 << 7,
};
struct SaveMenuUnkProc1 {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
};
struct SaveMenuUnkProc2 {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
};
struct SaveMenuProc {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             u8 anim_clock;
             u8 unk_2A;
             u8 selected_id;
             u8 copy_from_id;
             u8 unk_2D;
             u8 unk_2E;
             u8 unk_2F;
             u8 unk_30;
             u8 unk_31;
             u8 unk_32;
             u8 unk_33;
             u8 unk_34;
             u8 unk_35;
             u8 unk_36;
             u8 unk_37[3];
             u8 unk_3A[3];
             u8 unk_3D;
             u8 in_rtext;
             u8 unk_3F;
             u16 unk_40;
             u16 action_flag;
             u32 unk_44[3];
             u32 unk_50;
             struct SaveMenuUnkProc1 * proc1;
             struct SaveMenuUnkProc2 * proc2;
             ProcPtr proc3;
};
extern u8 gUnk_Savemenu_02000000;
extern u8 gUnk_Savemenu_02000001;
void SaveMenuOnHBlank(void);
void SaveMenu_HandleExtraMiscOption(struct SaveMenuProc * proc);
u8 SaveMenuIndexToValidBitfile(u8 byte, int num);
u8 sub_80A4018(u8 byte1, u8 byte2);
u8 sub_80A4054(u8 byte);
void SaveMenu_StartHelpBox(struct SaveMenuProc * proc);
void StartMainMenu( );
void sub_80A5AF8(ProcPtr);
void sub_80A5B20(s32, s32);
void sub_80A5B44(void);
struct ProcSpinRotation {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             u16 ro;
             int angle;
             ProcPtr savedraw;
             u8 unk_34;
             u8 unk_35;
             u8 unk_36;
             u8 unk_37;
             u8 unk_38;
             u8 unk_39;
             u8 unk_3A;
             u8 unk_3B;
             u8 unk_3C_unused;
             u8 unk_3D;
};
void SpinRotation_Init(struct ProcSpinRotation * proc);
void SpinRotation_Loop(struct ProcSpinRotation * proc);
ProcPtr StartSpinRotation(ProcPtr parent);
extern  u16 BgConfig_SaveMenu[];
       
enum {
 BGCHR_TACTICIAN_BGSCROLL = 0x8000 / 0x20,
 BGPAL_TACTICIAN_BGSCROLL = 0xA,
 OBPAL_TACTICIAN_TEXTSHADOW = 1,
};
enum {
 PL_TACTINFO_0 = 0,
 PL_TACTINFO_1,
 PL_TACTINFO_2,
 PL_TACTINFO_FADE_END,
 PL_TACTINFO_4,
 PL_TACTINFO_END,
};
enum tactinfo_index {
 TACTINFO_IDX_NAME = 0,
 TACTINFO_IDX_BLOOD,
 TACTINFO_IDX_BIRTH,
 TACTINFO_IDX_GENDER,
};
struct ProcTactInfo {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             int cur_index;
             bool do_helpbox;
};
void TactInfo_StartHelpbox(struct ProcTactInfo *proc);
void TactInfo_CloseHelpbox(struct ProcTactInfo *proc);
void sub_80A7388(void);
void sub_80A739C(ProcPtr proc);
void UpdateTactMainHandShadow(int index, ProcPtr proc);
void UpdateTactMainHandPosition(int index);
void sub_80A7424(void);
void sub_80A7424(void);
void TactInfoFx_Thread(struct ProcTactInfo *proc);
void TactInfo_Init(struct ProcTactInfo *proc);
void TactInfo_SetupGfx(struct ProcTactInfo *proc);
void sub_80A76C8(struct ProcTactInfo *proc);
void TactInfo_IntroDialogue1(struct ProcTactInfo *proc);
void TactInfo_IntroDialogue2(struct ProcTactInfo *proc);
void TactInfo_HandleIntroDialoguePrompt(struct ProcTactInfo *proc);
void sub_80A77AC(struct ProcTactInfo *proc);
void sub_80A77E8(struct ProcTactInfo *proc);
void TactInfo_EndMuralBG(struct ProcTactInfo *proc);
void sub_80A7834(struct ProcTactInfo *proc);
void TactInfo_UpdateSaveData(struct ProcTactInfo *proc);
void TactInfo_CheckParticipantDialogue(struct ProcTactInfo *proc);
void TactInfo_HandleCheckParticipantPrompt(struct ProcTactInfo *proc);
void StartTacticianInfo(ProcPtr parent);
int TactGetMsg_Blood(int index);
int TactGetMsg_Birth(int index);
int TactGetMsg_Gender(int index);
int TactGetMsg_Affin(int index);
struct ProcTactBlood {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             int cur_index;
             bool do_helpbox;
};
void Tact_ClearNrVrams(void *vram, u32 chr, u32 nr_chrs);
void TactBlood_Init(struct ProcTactBlood *proc);
void TactBlood_Loop(struct ProcTactBlood *proc);
void TactBlood_End(struct ProcTactBlood *proc);
void StartTactBloodSelect(struct ProcTactInfo *proc);
void StartTactBirthSelect(struct ProcTactInfo *proc);
void StartTactGenderSelect(struct ProcTactInfo *proc);
void sub_80A8304(s32);
void StartModeSelect(ProcPtr proc);
       
struct ChapterMap {
    u8 obj1Id;
    u8 obj2Id;
    u8 paletteId;
    u8 tileConfigId;
    u8 mainLayerId;
    u8 objAnimId;
    u8 paletteAnimId;
    u8 changeLayerId;
};
enum {
    MAP_BGM_BLUE = 0,
    MAP_BGM_RED = 1,
    MAP_BGM_GREEN = 2,
    MAP_BGM_BLUE_HECTOR = 3,
    MAP_BGM_RED_HECTOR = 4,
    MAP_BGM_GREEN_HECTOR = 5,
    MAP_BGM_BLUE_GREEN_ALT = 6,
    MAP_BGM_RED_ALT = 7,
    MAP_BGM_PROLOGUE_LYN = 8,
    MAP_BGM_PROLOGUE = 9,
    MAP_BGM_PROLOGUE_HECTOR = 10,
    MAP_BGM_MAX
};
struct ChapterInfo {
             char const * debug_name;
             u8 asset_img_a;
             u8 asset_img_b;
             u8 asset_pal;
             u8 asset_tileset;
             u8 asset_map;
             u8 asset_img_anims;
             u8 asset_pal_anims;
             u8 asset_map_changes;
             u8 fog;
             u8 has_prep;
             u8 title_ids[2];
             u8 unk_0F;
             u8 unk_10;
             u8 weather;
             u8 banim_terrain_id;
             u8 hard_bonus_levels;
    unsigned char _pad_0x15[(0x16) - (0x15)];
             u16 map_bgm_ids[8];
             u16 song_prologue_lyn;
             u16 song_openning[2];
             u8 wall_hp;
             u8 turnsForTacticsRankAInEliwoodStory[2];
             u8 turnsForTacticsRankAInHectorStory[2];
             u8 turnsForTacticsRankBInEliwoodStory[2];
             u8 turnsForTacticsRankBInHectorStory[2];
             u8 turnsForTacticsRankCInEliwoodStory[2];
             u8 turnsForTacticsRankCInHectorStory[2];
             u8 turnsForTacticsRankDInEliwoodStory[2];
             u8 turnsForTacticsRankDInHectorStory[2];
             u8 unk3D;
             u16 gainedExpForExpRankAInEliwoodStory[2];
             u16 gainedExpForExpRankAInHectorStory[2];
             u16 gainedExpForExpRankBInEliwoodStory[2];
             u16 gainedExpForExpRankBInHectorStory[2];
             u16 gainedExpForExpRankCInEliwoodStory[2];
             u16 gainedExpForExpRankCInHectorStory[2];
             u16 gainedExpForExpRankDInEliwoodStory[2];
             u16 gainedExpForExpRankDInHectorStory[2];
             u16 unk5E;
             u32 goldForFundsRankInEliwoodStory[2];
             u32 goldForFundsRankInHectorStory[2];
             u16 msg_chapter_title_a;
             u16 msg_chapter_title_b;
             u8 mapEventDataId;
             u8 gmapEventId;
             u16 divinationTextIdBeginning;
             u16 divinationTextIdInEliwoodStory;
             u16 divinationTextIdInHectorStory;
             u16 divinationTextIdEnding;
             u8 divinationPortrait;
             u8 divinationFee;
    u8 eu_pad[4];
                   u8 prepScreenNumber[2];
                   u8 merchantPosX;
                   u8 merchantPosXInHectorStory;
                   u8 merchantPosY;
                   u8 merchantPosYInHectorStory;
                   s8 victorySongEnemyThreshold;
                   bool8 fadeToBlack;
             u16 statusObjectiveTextId;
             u16 goalWindowTextId;
             u8 goalWindowDataType;
             u8 protectCharacterIndex;
             u8 destPosX;
             u8 destPosY;
             u8 unk90;
             u8 default_background;
             u8 unk92;
             u8 unk93;
};
struct ChapterEventGroup
{
             const void * turnBasedEvents;
             const void * characterBasedEvents;
             const void * locationBasedEvents;
             const void * miscBasedEvents;
             const void * specialEventsWhenUnitSelected;
             const void * specialEventsWhenDestSelected;
             const void * specialEventsAfterUnitMoved;
             const void * tutorialEvents;
             const void * traps;
             const void * extraTrapsInHard;
             const void * playerUnitsInNormal;
             const void * playerUnitsInHard;
             unsigned char _pad_0x30[(0x38) - (0x30)];
             const void * beginningSceneEvents;
             const void * endingSceneEvents;
};
const struct ChapterInfo * GetChapterInfo(u32 chIndex);
       
enum item_kind {
    ITYPE_SWORD = 0,
    ITYPE_LANCE = 1,
    ITYPE_AXE = 2,
    ITYPE_BOW = 3,
    ITYPE_STAFF = 4,
    ITYPE_ANIMA = 5,
    ITYPE_LIGHT = 6,
    ITYPE_DARK = 7,
    ITYPE_BLLST = 8,
    ITYPE_ITEM = 9,
    ITYPE_DRAGN = 10,
    ITYPE_11 = 11,
    ITYPE_12 = 12,
};
enum weapon_effect {
    WPN_EFFECT_NONE = 0,
    WPN_EFFECT_POISON = 1,
    WPN_EFFECT_HPDRAIN = 2,
    WPN_EFFECT_HPHALVE = 3,
    WPN_EFFECT_DEVIL = 4,
};
enum ItemData_attributes {
    IA_NONE = 0,
    IA_WEAPON = (1 << 0),
    IA_MAGIC = (1 << 1),
    IA_STAFF = (1 << 2),
    IA_UNBREAKABLE = (1 << 3),
    IA_UNSELLABLE = (1 << 4),
    IA_BRAVE = (1 << 5),
    IA_MAGICDAMAGE = (1 << 6),
    IA_UNCOUNTERABLE = (1 << 7),
    IA_REVERTTRIANGLE = (1 << 8),
    IA_HAMMERNE = (1 << 9),
    IA_LOCK_3 = (1 << 10),
    IA_LOCK_1 = (1 << 11),
    IA_LOCK_2 = (1 << 12),
    IA_LOCK_0 = (1 << 13),
    IA_NEGATE_FLYING = (1 << 14),
    IA_NEGATE_CRIT = (1 << 15),
    IA_UNUSABLE = (1 << 16),
    IA_NEGATE_DEFENSE = (1 << 17),
    IA_LOCK_4 = (1 << 18),
    IA_LOCK_5 = (1 << 19),
    IA_LOCK_6 = (1 << 20),
    IA_LOCK_7 = (1 << 21),
    IA_REQUIRES_WEXP = (IA_WEAPON | IA_STAFF),
    IA_LOCK_ANY = (IA_LOCK_0 | IA_LOCK_1 | IA_LOCK_2 | IA_LOCK_3 | IA_LOCK_4 | IA_LOCK_5 | IA_LOCK_6 | IA_LOCK_7 | IA_UNUSABLE)
};
enum weapon_lv_id {
    WPN_LEVEL_0 = 0,
    WPN_LEVEL_E = 1,
    WPN_LEVEL_D = 2,
    WPN_LEVEL_C = 3,
    WPN_LEVEL_B = 4,
    WPN_LEVEL_A = 5,
    WPN_LEVEL_S = 6,
};
enum weapon_lv_exp {
    WPN_EXP_0 = 0,
    WPN_EXP_E = 1,
    WPN_EXP_D = 31,
    WPN_EXP_C = 71,
    WPN_EXP_B = 121,
    WPN_EXP_A = 181,
    WPN_EXP_S = 251,
};
int GetItemHpBonus(int item);
int GetItemPowBonus(int item);
int GetItemSklBonus(int item);
int GetItemSpdBonus(int item);
int GetItemDefBonus(int item);
int GetItemResBonus(int item);
int GetItemLckBonus(int item);
int MakeNewItem(int item);
bool CanUnitUseWeapon(struct Unit *unit, int item);
bool CanUnitUseWeaponNow(struct Unit *unit, int item);
bool CanUnitUseStaff(struct Unit *unit, int item);
void DrawItemStatScreenLine(struct Text * text, int item, int nameColor, u16 * mapOut);
u16 GetItemAfterUse(int item);
u16 GetUnitEquippedWeapon(struct Unit *unit);
int GetUnitEquippedWeaponSlot(struct Unit *unit);
bool IsItemCoveringRange(int item, int range);
void EquipUnitItemSlot(struct Unit *unit, int itemSlot);
bool IsItemEffectiveAgainst(u16 item, struct Unit *unit);
char *GetItemDisplayRangeString(int item);
int GetWeaponLevelFromExp(int wexp);
int GetWeaponLevelSpecialCharFromExp(int wexp);
void GetWeaponExpProgressState(int wexp, int * outValue, int * outMax);
bool IsItemDisplayUsable(struct Unit * unit, int item);
int GetUnitItemSlot(struct Unit *unit, int itemIndex);
s32 GetPartyTotalGoldValue(void);
int GetItemIndex(int item);
char *GetItemName(int item);
int GetItemDescMsg(int item);
int GetItemUseDescId(int item);
int GetItemType(int item);
int GetItemAttributes(int item);
int GetItemUses(int item);
int GetItemMaxUses(int item);
int GetItemMight(int item);
int GetItemHit(int item);
int GetItemWeight(int item);
int GetItemCrit(int item);
int GetItemRequiredExp(int item);
int GetItemWeaponEffect(int item);
int GetItemCostPerUse(int item);
int GetItemAwardedExp(int item);
       
struct ArenaSt
{
             struct Unit * player;
             struct Unit * opponent;
             short matchup_gold_value;
             u8 result;
             u8 unk_0B;
             u8 range;
             u8 player_weapon_kind;
             u8 opponent_weapon_kind;
             u8 player_jid;
             u8 opponent_jid;
             u8 player_level;
             u8 opponent_level;
             s8 player_is_magic;
             s8 opponent_is_magic;
             u16 player_power_ranking;
             u16 opponent_power_ranking;
             u16 player_weapon;
             u16 opponent_weapon;
};
extern struct ArenaSt gArenaSt;
       
void Sound_FadeOutSE(int speed);
void StartBgmCore(int song, struct MusicPlayer * music_player);
void StartOrChangeBgm(int song, int speed, struct MusicPlayer * music_player);
void StartBgm(int song, struct MusicPlayer * music_player);
void StartBgmExt(int song, int speed, struct MusicPlayer * music_player);
void OverrideBgm(int song);
void CallSomeSoundMaybe(int songId, int b, int c, int d, ProcPtr parent);
bool MusicProc4Exists(void);
enum interpolate_method_idx {
    INTERPOLATE_LINEAR,
    INTERPOLATE_SQUARE,
    INTERPOLATE_CUBIC,
    INTERPOLATE_POW4,
    INTERPOLATE_RSQUARE,
    INTERPOLATE_RCUBIC,
};
int Interpolate(int method, int lo, int hi, int x, int end);
bool StringEquals(char const * strA, char const * strB);
void StringCopy(char * dst, char const * src);
void Decompress(void const * src, void * dst);
int GetDataSize(void const * data);
void Register2dChrMove(u8 const * img, u8 * vram, int width, int height);
void Copy2dChr(void const * src, u8 * dst, int width, int height);
void ApplyBitmap(u8 const * src, void * dst, int width, int height);
void ApplyBitmapLine(u8 const * src, void * dst, int width);
void PutAppliedBitmap(u16 * tm, int tileref, int width, int height);
int GetPalFadeStClkEnd1(void);
int GetPalFadeStClkEnd2(void);
int GetPalFadeStClkEnd3(void);
void ArchiveCurrentPalettes(void);
void ArchivePalette(int index);
void WriteFadedPaletteFromArchive(int red, int green, int blue, u32 mask);
void sub_8013EF8(int a, int b, int c, int d, int e, int f, int g, int h, ProcPtr parent);
bool sub_8013F3C(void);
struct PalFadeSt {
             u16 from_colors[0x10];
             u16 const * to_colors;
             u16 * pal;
             u16 clock;
             u16 clock_end;
             u16 clock_stop;
};
void StartPalFadeToBlack(int palid, int duration, ProcPtr parent);
void StartPalFadeToWhite(int palid, int duration, ProcPtr parent);
struct PalFadeSt * StartPalFade(u16 const * colors, int pal, int duration, ProcPtr parent);
void SetBlackPal(int palid);
void StartMidFadeFromBlack(void);
void StartMidLockingFadeToBlack(ProcPtr parent);
void StartMidLockingFadeFromBlack(ProcPtr parent);
void sub_8014690(ProcPtr proc);
void sub_8014714(ProcPtr proc);
void sub_801478C(ProcPtr proc);
void WaitForFade(ProcPtr proc);
void sub_80149B4(ProcPtr proc, int arg_1);
u8 sub_80149EC(int number, char * buf);
void CallDelayed(void (*)(), int);
       
int CountFactionMoveableUnits(int faction);
int CountFactionUnitsWithoutFlags(int faction, int prohibited_flags);
bool AreUnitIdsAllied(int uidA, int uidB);
bool AreUnitIdsSameFaction(int uidA, int uidB);
int GetActiveFactionAlliance();
int GetActiveFactionOpposingAlliance();
       
enum intr_index {
    INT_VBLANK = 0,
    INT_HBLANK = 1,
    INT_VCOUNT = 2,
    INT_COUNT = 14,
};
typedef void (* IrqFunc)(void);
void IrqMain(void);
void IrqInit(void);
void SetIrqFunc(int num, IrqFunc func);
       
enum {
    MAP_MOVEMENT_MAX = 120,
    MAP_MOVEMENT_EXTENDED = 124,
};
enum {
    HIDDEN_BIT_UNIT = (1 << 0),
    HIDDEN_BIT_TRAP = (1 << 1),
};
extern  struct Vec2 gBmMapSize;
extern  u8** gBmMapUnit;
extern  u8** gBmMapTerrain;
extern  u8** gBmMapMovement;
extern  u8** gBmMapRange;
extern  u8** gBmMapFog;
extern  u8** gBmMapHidden;
extern  u8** gBmMapOther;
void GenerateExtendedMovementMap(int x, int y, const s8 mct[]);
void UnpackChapterMapGraphics(int chapterId);
       
       
       
struct SpriteAnim {
             u16 const * info;
             u16 const * sprites;
             u16 const * script;
             u16 const * script_pc;
             u16 const * current_sprite;
             u16 const * current_affine;
             s16 clock;
             u16 clock_interval_q8;
             u16 clock_decimal_q8;
             u16 layer;
             u8 need_sync_img_b;
             u8 affine_slot;
             u16 oam2;
             u8 const * img;
};
struct ProcSpriteAnim {
             const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             u8 pad_29[0x50 - 0x29];
             struct SpriteAnim * anim;
             int x, y;
};
void InitSpriteAnims(void);
struct SpriteAnim * StartSpriteAnim(u16 const * info, u16 layer);
void EndSpriteAnim(struct SpriteAnim * anim);
bool DisplaySpriteAnim(struct SpriteAnim * anim, int x, int y);
void SetSpriteAnimId(struct SpriteAnim * anim, int id);
void SetSpriteAnimInfo(struct SpriteAnim * anim, u16 const * info);
struct SpriteAnim * FindSpriteAnim(u16 const * info);
ProcPtr StartSpriteAnimProc(u16 const * info, int x, int y, int oam2, int animid, int layer);
void AnimProc_Update(struct ProcSpriteAnim * proc);
void AnimProc_OnEnd(struct ProcSpriteAnim * proc);
void SetSpriteAnimProcParameters(ProcPtr proc, int x, int y, int oam2);
void EndSpriteAnimProc(ProcPtr proc);
void EndEachSpriteAnimProc(void);
bool SpriteAnimProcExists(void);
extern struct ProcCmd ProcScr_SpriteAnimProc[];
enum
{
    MU_STATE_NONE,
    MU_STATE_INACTIVE,
    MU_STATE_MOVEMENT,
    MU_STATE_SLEEPING,
    MU_STATE_UNK4,
    MU_STATE_BUMPING,
    MU_STATE_DISPLAY_UI,
    MU_STATE_DEATHFADE,
};
enum
{
    MU_FLASH_WHITE,
    MU_FLASH_BLACK,
    MU_FLASH_RED,
    MU_FLASH_GREEN,
    MU_FLASH_BLUE,
    MU_FLASH_5,
};
enum
{
    MOVE_CMD_END = -1,
    MOVE_CMD_MOVE_BASE,
    MOVE_CMD_MOVE_LEFT = MOVE_CMD_MOVE_BASE + FACING_LEFT,
    MOVE_CMD_MOVE_RIGHT = MOVE_CMD_MOVE_BASE + FACING_RIGHT,
    MOVE_CMD_MOVE_DOWN = MOVE_CMD_MOVE_BASE + FACING_DOWN,
    MOVE_CMD_MOVE_UP = MOVE_CMD_MOVE_BASE + FACING_UP,
    MOVE_CMD_HALT,
    MOVE_CMD_FACE_BASE,
    MOVE_CMD_FACE_LEFT = MOVE_CMD_FACE_BASE + FACING_LEFT,
    MOVE_CMD_FACE_RIGHT = MOVE_CMD_FACE_BASE + FACING_RIGHT,
    MOVE_CMD_FACE_DOWN = MOVE_CMD_FACE_BASE + FACING_DOWN,
    MOVE_CMD_FACE_UP = MOVE_CMD_FACE_BASE + FACING_UP,
    MOVE_CMD_SLEEP,
    MOVE_CMD_BUMP,
    MOVE_CMD_UNK11,
    MOVE_CMD_SET_SPEED,
    MOVE_CMD_CAMERA_ON,
    MOVE_CMD_CAMERA_OFF,
    MOVE_SCRIPT_MAX_LENGTH = 0x40,
};
struct MuInfo
{
    u8 const * img;
    u16 const * anim;
};
struct MuConfig;
struct MuProc
{
             const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             struct Unit * unit;
             struct SpriteAnim * sprite_anim;
             struct MuConfig * config;
             u8 cam_b;
             u8 state;
             u8 hidden_b;
             u8 jid;
             s8 facing;
             u8 step_sound_clock;
             u8 fast_walk_b;
             u16 move_clock_q4;
             s16 move_config;
             s16 x_q4, y_q4;
             s16 x_offset_q4, y_offset_q4;
};
struct MuConfig
{
             u8 id;
             u8 pal;
             u16 chr;
             u8 pc;
             s8 movescr[0x40];
             struct MuProc * mu;
};
struct MuProc * StartUiMu(struct Unit * unit, int x, int y);
void EndAllMus(void);
void LockMus(void);
void ReleaseMus(void);
void ApplyMoveScriptToCoordinates(int * x, int * y, u8 const * move_script);
bool CanStartMu(void);
void SetMuScreenPosition(struct MuProc * mu, int x, int y);
extern u8 gWorkingMoveScr[MOVE_SCRIPT_MAX_LENGTH];
       
enum save_chunk_idx {
    SAVE_GAME0,
    SAVE_GAME1,
    SAVE_GAME2,
    SAVE_SUSPEND,
    SAVE_SUSPEND_ALT,
    SAVE_MULTIARENA,
    SAVE_XMAP,
    SAVE_COUNT,
};
enum save_kind_idx {
    SAVE_KIND_GAME,
    SAVE_KIND_SUSPEND,
    SAVE_KIND_MULTIARENA,
    SAVE_KIND_XMAP,
    SAVE_KIND_INVALID = 255,
};
enum save_chunk_magics {
    SAVE_MAGIC32 = 0x30317,
    SAVE_MAGIC32_SAV = 0x11217,
    SAVE_MAGIC32_SUS = 0x20509,
    SAVE_MAGIC32_MULTIARENA = 0x20112,
    SAVE_MAGIC32_XMAP = 0x20223,
    SAVE_MAGIC16 = 0x200A,
};
struct GlobalSaveInfo {
             char name[0x8];
             u32 magic32;
             u16 magic16;
             u8 completed : 1;
             u8 flag0E_1 : 1;
             u8 Eirk_mode_easy : 1;
             u8 Eirk_mode_norm : 1;
             u8 Eirk_mode_hard : 1;
             u8 Ephy_mode_easy : 1;
             u8 Ephy_mode_norm : 1;
             u8 Ephy_mode_hard : 1;
             u8 game_end;
             u32 unk10_00 : 8;
             u32 unk10_08 : 16;
             u32 unk10_18 : 5;
             u32 unk10_1D : 3;
             u8 cleared_playthroughs[12];
             u8 SuppordRecord[0x40 - 0x20];
             u8 charKnownFlags[0x60 - 0x40];
             u16 checksum;
             u8 last_game_save_id;
             u8 last_suspend_slot;
};
struct SaveBlockInfo {
             u32 magic32;
             u16 magic16;
             u8 kind;
             u16 offset;
             u16 size;
             u32 checksum32;
};
struct SramMain {
    struct GlobalSaveInfo head;
    struct SaveBlockInfo block_info[SAVE_COUNT];
};
void SramInit(void);
bool IsSramWorking(void);
void WipeSram(void);
u16 Checksum16(void const * data, int size);
bool ReadGlobalSaveInfo(struct GlobalSaveInfo * info);
void WriteGlobalSaveInfo(struct GlobalSaveInfo * info);
void WriteGlobalSaveInfoNoChecksum(struct GlobalSaveInfo * info);
void InitGlobalSaveInfo(void);
void ResetFe6LinkSaveInfo(void);
void EraseBonusContentData(void);
void * SramOffsetToAddr(u16 off);
u16 SramAddrToOffset(void * addr);
bool ReadSaveBlockInfo(struct SaveBlockInfo * block_info, int save_id);
void WriteSaveBlockInfo(struct SaveBlockInfo * block_info, int save_id);
void * GetSaveWriteAddr(int save_id);
void * GetSaveReadAddr(int save_id);
s32 sub_809F40C(void);
bool IsGamePlayedThrough(void);
int CheckLinkedToFE6(void);
void WriteFe6LinkSaveInfo(void * buf);
void SaveBonusContentData(void * buf);
void SaveEndgameRankings(void);
struct PidStats
{
    u32 loss_count : 8;
    u32 favval : 16;
    u32 act_count : 8;
    u32 stat_view_count : 8;
    u32 defeat_chapter : 6;
    u32 defeat_turn : 10;
    u32 deploy_count : 6;
    u32 move_count : 10;
    u32 defeat_cause : 4;
    u32 exp_gained : 12;
    u32 win_count : 10;
    u32 battle_count : 12;
    u32 killer_pid : 9;
    u32 : 0;
};
void ClearPidStats_ret(void);
void ClearPidStats(void);
int GetNextChapterStatsEntry(void);
void RegisterChapterStats(struct PlaySt *);
void PidStatsAddStatView(u8 pid);
void PidStatsRecordBattleRes(void);
bool IsPlaythroughIdUnique(int index);
int GetNewPlaythroughId(void);
int GetGlobalCompletionCntByInfo(struct GlobalSaveInfo * info);
int GetGlobalCompletionCount(void);
bool RegisterCompletedPlaythrough(struct GlobalSaveInfo * info, int index);
void SavePlayThroughData(void);
struct PidStats * GetPidStats(u8 pid);
void WriteLastGameSaveId(int num);
int ReadLastGameSaveId(void);
void CopyGameSave(int index_src, int index_dest);
void WriteNewGameSave(int index, int isDifficult, int mode, int isTutorial);
void WriteGameSave(int slot);
void ReadGameSave(int slot);
bool IsSaveValid(int);
void ReadGameSavePlaySt(s32, struct PlaySt *);
void WriteGameSavePackedUnit(struct Unit *unit, void *sram_dest);
void LoadSavedUnit(const void *sram_src, struct Unit *unit);
void InvalidateSuspendSave(int);
void WriteSuspendSave(int saveBlockId);
void ReadSuspendSave(int slot);
u8 IsValidSuspendSave(int);
int SramChecksum32(void const * sram_src, int size);
bool VerifySaveBlockChecksum(struct SaveBlockInfo * block_info);
void PopulateSaveBlockChecksum(struct SaveBlockInfo * block_info);
void sub_80A2BFC(void);
       
struct ProcCursorHand {
 const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
 unsigned char _pad_0x29[(0x2C) - (0x29)];
          struct { u8 x_start, y_start, x_end, y_end; } configs[4];
          u8 flag[4];
          s16 x[4], y[4];
};
void UiCursorHand_Init(struct ProcCursorHand *proc);
void UiCursorHand_Loop(struct ProcCursorHand *proc);
ProcPtr StartUiCursorHand(ProcPtr parent);
void SetUiCursorHandConfig(int index, int x, int y, u8 flags);
void UiCursorHand_SetPosition(int index, int x_start, int y_start, int x_end, int y_end);
void DisableUiCursorHand(int index);
void DisableAllUiCursorHand(void);
void BlockUiCursorHand(void);
void UnblockUiCursorHand(void);
void EndUiCursorHand(void);
extern u16  Sprite_CursorHand1[];
extern u16  Sprite_CursorHand2[];
extern struct ProcCmd  ProcScr_UiCursorHand[];
       
enum statscreen_frame_rect {
    PAGE_FRAME_SCREEN_X = 12,
    PAGE_FRAME_SCREEN_Y = 2,
};
enum statscreen_page_idx {
    STATSCREEN_PAGE_PERSONALINFO,
    STATSCREEN_PAGE_ITEMS,
    STATSCREEN_PAGE_WEXPANDSUPPORTS,
    STATSCREEN_PAGE_MAX
};
enum statscreen_text_index {
    STATSCREEN_TEXT_PNAME,
    STATSCREEN_TEXT_JNAME,
    STATSCREEN_TEXT_UNUSED,
    STATSCREEN_TEXT_POW,
    STATSCREEN_TEXT_SKL,
    STATSCREEN_TEXT_SPD,
    STATSCREEN_TEXT_LCK,
    STATSCREEN_TEXT_DEF,
    STATSCREEN_TEXT_RES,
    STATSCREEN_TEXT_MOV,
    STATSCREEN_TEXT_CON,
    STATSCREEN_TEXT_AID,
    STATSCREEN_TEXT_RESCUE,
    STATSCREEN_TEXT_AFFINITY,
    STATSCREEN_TEXT_STATUS,
    STATSCREEN_TEXT_ITEM_A,
    STATSCREEN_TEXT_ITEM_B,
    STATSCREEN_TEXT_ITEM_C,
    STATSCREEN_TEXT_ITEM_D,
    STATSCREEN_TEXT_ITEM_E,
    STATSCREEN_TEXT_EQUIPRANGE,
    STATSCREEN_TEXT_EQUIPATTACK,
    STATSCREEN_TEXT_EQUIPHIT,
    STATSCREEN_TEXT_EQUIPCRIT,
    STATSCREEN_TEXT_EQUIPAVOID,
    STATSCREEN_TEXT_WEXP_A,
    STATSCREEN_TEXT_WEXP_B,
    STATSCREEN_TEXT_WEXP_C,
    STATSCREEN_TEXT_WEXP_D,
    STATSCREEN_TEXT_SUPPORT_A,
    STATSCREEN_TEXT_SUPPORT_B,
    STATSCREEN_TEXT_SUPPORT_C,
    STATSCREEN_TEXT_SUPPORT_D,
    STATSCREEN_TEXT_SUPPORT_E,
    STATSCREEN_TEXT_BWL,
    MAX_STATSCREEN_TEXT,
};
struct HelpBoxInfo;
struct StatScreenSt {
             u8 page;
             u8 page_count;
             u16 page_slide_key_bit;
             s16 x_disp_off;
             s16 y_disp_off;
             bool is_transitioning;
             struct Unit * unit;
             struct MuProc * mu;
             struct HelpBoxInfo const * help;
             struct Text text[MAX_STATSCREEN_TEXT];
};
extern struct StatScreenSt gStatScreenSt;
extern u16 gUiTmScratchA[];
extern u16 gUiTmScratchB[];
extern u16 gUiTmScratchC[];
void DrawUiGaugeBitmapEdgeColumn(u8 * bitmap, int pixels_per_line, int column);
void DrawUiGaugeBitmapBaseColumn(u8 * bitmap, int pixels_per_line, int column);
void DrawUiGaugeBitmapFilledColumn(u8 * bitmap, int pixels_per_line, int column);
void DrawUiGaugeBitmapBonusColumn(u8 * bitmap, int pixels_per_line, int column);
void DrawUiGauge(int chr, int dot_x, int chr_count, int dot_width, int dot_plain, int dot_bonus);
void PutDrawUiGauge(int chr, int width, u16 * tm, int tileref, int dot_width, int dot_plain, int dot_bonus);
struct MuralBackgroundProc {
             const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             u8 pad_29[0x4C - 0x29];
             s16 offset;
};
void BackgroundSlide_Init(struct MuralBackgroundProc * proc);
void BackgroundSlide_Loop(struct MuralBackgroundProc * proc);
ProcPtr StartMuralBackgroundAlt(ProcPtr parent, void * vram, int pal);
ProcPtr StartMuralBackgroundExt(ProcPtr parent, void * vram, int pal, u8 type);
void EndMuralBackground(void);
struct StatScreenInfo {
             u8 _pad_;
             u8 unit_id;
             u16 excluded_unit_flags;
};
enum statscreen_flag_bitfile {
    STATSCREEN_CONFIG_NONDEAD = (1 << 0),
    STATSCREEN_CONFIG_NONBENCHED = (1 << 1),
    STATSCREEN_CONFIG_NONUNK9 = (1 << 2),
    STATSCREEN_CONFIG_NONROOFED = (1 << 3),
    STATSCREEN_CONFIG_NONUNK16 = (1 << 4),
    STATSCREEN_CONFIG_NONSUPPLY = (1 << 5),
};
extern struct StatScreenInfo gStatScreenInfo;
int GetLastStatScreenUnitId(void);
void SetStatScreenLastUnitId(int unit_id);
void SetStatScreenExcludedUnitFlags(int flags);
struct StatScreenTextInfo {
             struct Text * text;
             u16 * tm;
             u8 color;
             u8 x_offset;
             char const * const * str_list;
};
void InitStatScreenText(void);
void PutStatScreenText(struct StatScreenTextInfo const * list);
void PutStatScreenLeftPanelInfo(void);
void DisplayBwl(void);
void PutStatScreenStatWithBar(int num, int x, int y, int base, int total, int max);
void PutStatScreenPersonalInfoPage(void);
void PutStatScreenItemsPage(void);
void PutStatScreenSupportList(void);
void PutStatScreenWeaponExpBar(int num, int x, int y, int item_kind);
void PutStatScreenWeaponExpAndSupportsPage(void);
void PutStatScreenPage(int page_id);
struct Unit * FindNextStatScreenUnit(struct Unit * current_unit, int iter_step);
struct StatScreenPageSlideProc {
             const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
    unsigned char _pad_0x29[(0x4A) - (0x29)];
             s16 new_page;
             s16 clock;
    unsigned char _pad_0x4E[(0x52) - (0x4E)];
             u16 key_bit;
};
void StatScreenPageSlide_Loop(struct StatScreenPageSlideProc * proc);
void StatScreenPageSlide_End(struct StatScreenPageSlideProc * proc);
void StartStatScreenPageSlide(u16 key_bit, int new_page, ProcPtr parent);
struct StatScreenUnitSlideProc
{
             const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             u8 pad_29[0x38 - 0x29];
             int direction;
             int y_disp_init;
             int y_disp_fini;
             u8 pad_44[0x4A - 0x44];
             s16 new_unit_id;
             s16 clock;
};
void StatScreenUnitSlide_FadeOutInit(struct StatScreenUnitSlideProc * proc);
void StatScreenUnitSlide_FadeOutLoop(struct StatScreenUnitSlideProc * proc);
void StatScreenUnitSlide_FadeInInit(struct StatScreenUnitSlideProc * proc);
void StatScreenUnitSlide_FadeInLoop(struct StatScreenUnitSlideProc * proc);
void StatScreenUnitSlide_ChangeUnit(struct StatScreenUnitSlideProc * proc);
void StatScreenUnitSlide_End(struct StatScreenUnitSlideProc * proc);
void StartStatScreenUnitSlide(struct Unit * unit, int direction, ProcPtr parent);
struct StatScreenSpritesProc
{
             const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             s16 x_left;
             s16 x_right;
             u16 clock_left;
             u16 clock_right;
             s16 anim_speed_left;
             s16 anim_speed_right;
             u8 page_id;
             s16 vertical_scale;
};
void PutUpdateStatScreenPageName(int page_id);
void StatScreenPageName_Init(struct StatScreenSpritesProc * proc);
void StatScreenPageName_Main(struct StatScreenSpritesProc * proc);
void StatScreenPageName_CloseMain(struct StatScreenSpritesProc * proc);
void StatScreenPageName_OpenMain(struct StatScreenSpritesProc * proc);
void StatScreenSprites_Init(struct StatScreenSpritesProc * proc);
void StatScreenSprites_BumpCheck(struct StatScreenSpritesProc * proc);
void StatScreenSprites_PutArrows(struct StatScreenSpritesProc * proc);
void StatScreenSprites_PutNumberLabel(struct StatScreenSpritesProc * proc);
void StatScreenSprites_PutMuAreaSprites(struct StatScreenSpritesProc * proc);
void StatScreenSprites_PutRescueMarkers(struct StatScreenSpritesProc * proc);
void StatScreen_DisableScreen(ProcPtr proc);
void StatScreen_Init(ProcPtr proc);
void StatScreen_InitUnit(ProcPtr proc);
void StatScreen_Main(ProcPtr proc);
void StatScreen_BackUpStatus(ProcPtr proc);
void StatScreen_UpdateLastHelpInfo(ProcPtr proc);
void SyncStatScreenBgOffset(void);
void StatScreen_CleanUp(ProcPtr proc);
void StartStatScreen(struct Unit * unit, ProcPtr parent);
enum helpbox_info_idx {
    HELPBOX_INFO_NONE,
    HELPBOX_INFO_WEAPON,
    HELPBOX_INFO_STAFF,
    HELPBOX_INFO_SAVE_MENU,
};
struct HelpBoxInfo;
struct HelpBoxProc {
             const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             struct HelpBoxInfo const *info;
             s16 x_box;
             s16 y_box;
             s16 w_box;
             s16 h_box;
             s16 x_box_init;
             s16 y_box_init;
             s16 x_box_fini;
             s16 y_box_fini;
             s16 w_box_init;
             s16 h_box_init;
             s16 w_box_fini;
             s16 h_box_fini;
             s16 timer;
             s16 timer_end;
             u16 msg;
             u16 item;
             u16 move_key_bit;
             u8 unk_52;
};
void StartStatScreenHelp(int page_id, ProcPtr proc);
void HelpBoxPopulateStatScreenItem(struct HelpBoxProc * proc);
void HelpBoxPopulateStatScreenStatus(struct HelpBoxProc * proc);
void HelpBoxPopulateStatScreenPower(struct HelpBoxProc * proc);
void HelpBoxRedirectStatScreenItem(struct HelpBoxProc * proc);
void HelpBoxPopulateStatScreenWeaponExp(struct HelpBoxProc * proc);
void HelpBoxPopulateStatScreenPInfo(struct HelpBoxProc * proc);
void HelpBoxPopulateStatScreenJInfo(struct HelpBoxProc * proc);
void HelpBoxRedirectStatScreenSupports(struct HelpBoxProc * proc);
void UpdateHelpBoxDisplay(struct HelpBoxProc * proc, int interpolate_method);
void HelpBox_OnOpen(struct HelpBoxProc * proc);
void HelpBox_OnLoop(struct HelpBoxProc * proc);
void HelpBox_OnClose(struct HelpBoxProc * proc);
void HelpBox_WaitClose(struct HelpBoxProc * proc);
void StartHelpBox(int x, int y, int msg);
void StartHelpBox_Unk(int x, int y, int mid);
void StartItemHelpBox(int x, int y, int item);
void StartHelpBoxExt(struct HelpBoxInfo const * info, int unk);
void StartHelpBoxExt_Unk(int x, int y, int mid);
void CloseHelpBox(void);
void KillHelpBox(void);
void HelpBoxMoveControl_OnInitBox(struct HelpBoxProc * proc);
void HelpBoxMoveControl_OnIdle(struct HelpBoxProc * proc);
struct HelpBoxInfo
{
             struct HelpBoxInfo const *adjacent_up;
             struct HelpBoxInfo const *adjacent_down;
             struct HelpBoxInfo const *adjacent_left;
             struct HelpBoxInfo const *adjacent_right;
             u8 x, y;
             u16 msg;
             void (* redirect)(struct HelpBoxProc *proc);
             void (* populate)(struct HelpBoxProc *proc);
};
void HelpBoxMoveControl_OnEnd(struct HelpBoxProc * proc);
void StartMovingHelpBox(struct HelpBoxInfo const * info, ProcPtr parent);
void StartMovingHelpBoxExt(struct HelpBoxInfo const * info, ProcPtr parent, int x, int y);
void ApplyHelpBoxContentSize(struct HelpBoxProc * proc, int w_inner, int h_inner);
void ApplyHelpBoxPosition(struct HelpBoxProc * proc, int x, int y);
void SetHelpBoxInitPosition(struct HelpBoxProc * proc, int x, int y);
void ResetHelpBoxInitSize(struct HelpBoxProc * proc);
int GetHelpBoxItemInfoKind(int item);
void HelpBoxPopulateAutoItem(struct HelpBoxProc * proc);
int HelpBoxTryRelocateUp(struct HelpBoxProc *proc);
int HelpBoxTryRelocateDown(struct HelpBoxProc *proc);
int HelpBoxTryRelocateLeft(struct HelpBoxProc *proc);
int HelpBoxTryRelocateRight(struct HelpBoxProc *proc);
void HelpBoxLockHelper_Loop(ProcPtr proc);
int StartLockingHelpBox(int msg, ProcPtr parent);
struct HelpPromptSprProc
{
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             int x, y;
};
void HelpPrompt_OnIdle(struct HelpPromptSprProc * proc);
ProcPtr StartHelpPromptSprite(int x, int y, ProcPtr parent);
ProcPtr StartHelpPromptSpriteBlocking(int x, int y, ProcPtr parent);
void EndHelpPromptSprite(void);
void MoveHelpPromptSprite(int x, int y);
struct HelpBoxInfo const * GetLastHelpBoxInfo(void);
extern struct ProcCmd ProcScr_BackgroundSlide[];
extern struct TextInitInfo gStatScreenTextList[];
extern struct ProcCmd ProcScr_StatScreenPageSlide[];
extern struct ProcCmd ProcScr_StatScreenUnitSlide[];
extern u16  Sprite_StatScreenPageName[];
extern u16  gStatScreenPageNameChrOffsetLut[];
extern u16  Sprite_StatScreenMuAreaBackground[];
extern u16  Sprite_StatScreenFaceSideWindow[];
extern struct ProcCmd  ProcScr_StatScreenPageName[];
extern struct ProcCmd  ProcScr_StatScreenSprites[];
extern struct ProcCmd ProcScr_StatScreen[];
extern struct ProcCmd  ProcScr_HelpPromptSpr[];
extern struct HelpBoxInfo  HelpInfo_StatScreenPersonalInfo_Pow;
extern struct HelpBoxInfo  HelpInfo_StatScreenItems_ItemA;
extern struct HelpBoxInfo  HelpInfo_StatScreenWeaponExp_WExpA;
extern struct StatScreenTextInfo const gStatScreenPersonalInfoLabelsInfo[];
extern struct StatScreenTextInfo const gStatScreenEquipmentLabelsInfo[];
extern struct StatScreenTextInfo const gStatScreenWeaponExpLabelsPhysicalInfo[];
extern struct StatScreenTextInfo const gStatScreenWeaponExpLabelsMagicalInfo[];
       
struct ChapTitleConfig {
    const u8 * img;
};
extern const struct ChapTitleConfig gChapTitleConfig[];
struct ChapTitleSt {
    u16 chr_bg;
    u16 chr_str;
};
extern struct ChapTitleSt gChapTitleSt;
void PutChapterTitlePalette(int config, int pal_bank);
void PutChapterTitleGfx(int chr, u32 titleId);
void PutChapterTitleBG(int chr);
void PutChapterTitleUnkBG(int chr);
void PutChapterTitleNameTsa(u16 * tm, int pal);
void PutChapterTitleBgTsa(u16 * tm, int pal);
void PutChapterTitleBgUnkTsa(u16 * tm, int pal);
int GetChapterTitle(struct PlaySt * playst);
       
typedef void ParallelWorkerFunc(ProcPtr);
struct ParallelFiniteLoopProc {
             const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             int maxCount;
             int count;
             ParallelWorkerFunc * func;
};
extern struct ProcCmd ProcScr_ParallelFiniteLoop[];
void ParallelFiniteLoop_Init(struct ParallelFiniteLoopProc * proc);
void ParallelFiniteLoop_Loop(struct ParallelFiniteLoopProc * proc);
void StartParallelFiniteLoop(void * func, int count, ProcPtr parent);
struct SysBlackBoxProc {
             const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             s16 x[4];
             s16 y[4];
             s8 height[4];
             s8 width[4];
             u16 oam2[4];
             u8 valid[4];
             u16 chr;
};
extern struct ProcCmd ProcScr_SysBlackBox[];
void SysBlackBox_Init(struct SysBlackBoxProc * proc);
void SysBlackBox_Main(struct SysBlackBoxProc * proc);
ProcPtr NewSysBlackBoxHandler(ProcPtr);
void SysBlackBoxSetGfx(u32 obj_offset);
void EnableSysBlackBox(int index, int x, int y, int width, int height, u16 oam2);
void DisableSysBlackBox(int index);
void BlockAllSysBlackBoxs(void);
void UnblockAllSysBlackBoxs(void);
void EndSysBlackBoxs(void);
struct ParallelWorkerProc
{
             const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             ParallelWorkerFunc * func;
};
void ParallelWorker_OnLoop(struct ParallelWorkerProc * proc);
ProcPtr StartParallelWorker(void *, ProcPtr);
void EndAllParallelWorkers(void);
ProcPtr GetParallelWorker(void *);
struct SysHandCursorProc {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             unsigned char _pad_0x29[(0x2C) - (0x29)];
             int x, y;
             bool enable_bmshadow, enable_sysshadow;
             u16 chr;
             u16 shadow_len;
             u16 pal_bank;
             u16 chr2;
};
extern struct ProcCmd ProcScr_SysHandCtrl[];
void DisplayExtendedSysHand(struct SysHandCursorProc * proc);
void SysHandCursor_Init(struct SysHandCursorProc * proc);
void SysHandCursor_Loop(struct SysHandCursorProc * proc);
ProcPtr ResetSysHandCursor(ProcPtr parent);
void DisplaySysHandCursorTextShadow(u32 vobj_offset, u32 pal);
void ShowSysHandCursor(int x, int y, int shadow_len, u16 chr);
void HideSysHandCursor(void);
void EndSysHandCursor(void);
void ConfigSysHandCursorShadowEnabled(u8 enabled);
void DisableAllGfx(void);
void EnableAllGfx(void);
struct SysGrayBoxConf {
    bool valid;
    u8 layer;
    s16 x, y;
    u8 width, height;
    u16 chr;
} BITPACKED;
struct ProcSysGrayBox {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             struct SysGrayBoxConf priv[4];
             int chr, pal;
};
extern struct ProcCmd ProcScr_SysGrayBox[];
void SysGrayBox_Init(struct ProcSysGrayBox * proc);
void SysGrayBox_Loop(struct ProcSysGrayBox * proc);
ProcPtr NewSysGrayBox(u32 vobj_offset, u32 pal, ProcPtr parent);
void EnableUnransportWindow(int index, int layer, int x, int y, int w, int h, u16 chr);
void DisableSysGrayBox(int index);
void EndSysGrayBoxs(void);
struct SysBrownBoxConf {
    bool valid;
    u8 frame;
    s16 x, y;
    s8 width, height;
};
struct ProcSysBrownBox {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             struct SysBrownBoxConf priv[4];
             u16 oam2;
             s16 y;
             u8 layer;
};
extern struct ProcCmd ProcScr_SysBrownBox[];
void SysBrownBox_Init(struct ProcSysBrownBox * proc);
void SysBrownBox_Loop(struct ProcSysBrownBox * proc);
void StartSysBrownBox(int layer, u32 vobj_offset, int pal, u16 oam2, u16 y, ProcPtr parent);
void EnableSysBrownBox(int index, int x, int y, int frame);
void DisableSysBrownBox(int index);
void SetSysBrownBoxWidth(int index, u8 width);
void EndSysBrownBox(void);
struct ProcSysboxText {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             struct Font font;
             struct Text texts[2];
             const char * str;
             u8 line, max_line;
             u16 timer;
};
extern struct ProcCmd ProcScr_SysboxText[];
void SysboxTextMain(struct ProcSysboxText * proc);
void NewSysboxText(int vobj_offset, int pal, const char * str, int line, ProcPtr parent);
void EndAllProcChildren(ProcPtr proc);
void nullsub_85(void);
void BgAffinRotScaling(u8 layer, s16 angle, s16, s16, s16, s16);
void BgAffinScaling(u8, s16, s16);
void BgAffinAnchoring(u8, s16, s16, s16, s16);
void BgAffinRotScalingHighPrecision(u8 layer, int angle, int a, int b, int c, int d);
void BgAffinScalingHighPrecision(u8 layer, int a, int b);
void BgAffinAnchoringHighPrecision(u8 layer, int a, int b, int c, int d);
void sub_80AAEF8(int a, u16 * buf, int c, int d, int e, int f, int g, int h);
void sub_80AAFA4(int a, int b, int c, int d, int e, u16 f) ;
void SetBlankBgColor(int, int, int);
struct ProcFadeInOut {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             bool white_out;
             int timer;
             int speed;
             int mask;
};
extern struct ProcCmd  ProcScr_BmFadeIN[];
extern struct ProcCmd  ProcScr_BmFadeOUT[];
void FadeInOut_Init(struct ProcFadeInOut * proc);
void FadeIn_Loop(struct ProcFadeInOut * proc);
void FadeOut_Loop(struct ProcFadeInOut * proc);
void FadeInOut_DisableGfx(struct ProcFadeInOut * proc);
bool FadeInExists(void);
bool FadeOutExists(void);
void NewFadeIn(int, ProcPtr);
void NewFadeOut(int, ProcPtr);
void NewFadeIn(int speed, ProcPtr parent);
void NewFadeOut(int speed, ProcPtr parent);
void NewBlockedFadeIn(int speed, ProcPtr parent);
void NewBlockedFadeOut(int speed, ProcPtr parent);
void NewFadeIn2(int speed, ProcPtr parent);
void NewFadeOut2(int speed, ProcPtr parent);
void NewFadeInWhite(int speed, ProcPtr parent);
void NewFadeOutWhite(int speed, ProcPtr parent);
void NewBlockedFadeInWhite(int speed, ProcPtr parent);
void NewBlockedFadeOutWhite(int speed, ProcPtr parent);
void NewFadeInWhite2(int speed, ProcPtr parent);
void NewFadeOutWhite2(int speed, ProcPtr parent);
void WipeAllPalette(void);
void EndFadeInOut(void);
struct BmBgxConf
{
             u8 type;
             void * data;
             u16 size;
             u8 duration;
             unsigned char _pad_0x0b[(0x0c) - (0x0b)];
};
enum BmBgxConf_type {
    BMFX_CONFT_IMG = 0,
    BMFX_CONFT_ZIMG = 1,
    BMFX_CONFT_TSA = 2,
    BMFX_CONFT_PAL = 3,
    BMFX_CONFT_LOOP_START = 4,
    BMFX_CONFT_LOOP = 5,
    BMFX_CONFT_BLOCKING = 6,
    BMFX_CONFT_7,
    BMFX_CONFT_CALL_IDLE = 8,
    BMFX_CONFT_BREAK = 9,
    BMFX_CONFT_END = 10
};
typedef s8 bmfx_idle(ProcPtr);
struct ProcBmBgfx {
             const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             struct BmBgxConf * conf;
             u16 x;
             u16 y;
             u8 bg;
             u8 pal_bank;
             s8 counter;
             u8 flip;
             u8 timer;
             u8 func_call_type;
             bool loop_en;
             unsigned char _pad_0x3b[(0x3c) - (0x3b)];
             int vram_base;
             u32 vram_base_offset;
             int vram_free_space;
             u32 size_per_fx;
             int total_duration;
             int counter_procloop;
             int counter_functioncall;
             bool (* callback)(ProcPtr);
};
void BmBgfx_Init(struct ProcBmBgfx * proc);
void BmBgfx_Loop(struct ProcBmBgfx * proc);
void BmBgfx_End(struct ProcBmBgfx * proc);
bool CheckBmBgfxDone(void);
void BmBgfxAdvance(void);
void EndBmBgfx(void);
void BmBgfxSetLoopEN(u8);
void StartBmBgfx(struct BmBgxConf * input, int bg, int x, int y, int vram_off, int size, int pal_bank, void * func, ProcPtr parent);
extern struct ProcCmd ProcScr_BmBgfx[];
struct ProcMixPalette {
             const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             int speed;
             int targetPalId;
             int palCount;
             int timer;
             u16 * srcA;
             u16 * srcB;
};
extern struct ProcCmd  ProcScr_MixPalette[];
void MixPaletteCore(struct ProcMixPalette * proc, int val);
void MixPalette_Init(struct ProcMixPalette * proc);
void MixPalette_Loop(struct ProcMixPalette * proc);
void StartMixPalette(u16 * palA, u16 * palB, int speed, int targetPalId, int palCount, ProcPtr parent);
void EndMixPalette(void);
ProcPtr StartSpriteAnimfx(const u8 * gfx, const u16 * pal, const void * info, int x, int y, int animId, int palId, int palCount, u16 chr, int layer);
int GetBgXOffset(int bg);
int GetBgYOffset(int bg);
char * AppendString(const char * src, char * dst);
char * AppendCharacter(int ch, char * str);
       
typedef uintptr_t EventScr;
enum event_evbit_idx {
    EVENT_FLAG_UNITCAM = 1 << 0,
    EVENT_FLAG_TEXTSKIPPED = 1 << 1,
    EVENT_FLAG_SKIPPED = 1 << 2,
    EVENT_FLAG_DISABLESKIP = 1 << 3,
    EVENT_FLAG_DISABLETEXTSKIP = 1 << 4,
    EVENT_FLAG_ENDMAPMAIN = 1 << 5,
    EVENT_FLAG_NOAUTOCLEAR = 1 << 6,
    EVENT_FLAG_NOSKIPTALK = 1 << 7,
    EVENT_FLAG_SLOWTALK = 1 << 8,
};
struct EventProc {
             const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             EventScr const * script_start;
             EventScr const * script;
             EventScr const * script_return;
    unsigned char _pad_0x38[(0x40) - (0x38)];
             void (* idle_func)(struct EventProc * proc);
             struct UnitDefinition const * unit_info;
             int talk_auto_msg;
             s8 background;
             bool unk_4D;
             u8 unk_4E;
             u8 map_change_param;
             u16 sleep_duration;
    unsigned char _pad_0x52[(0x55) - (0x52)];
             u8 pid_param;
             u16 ignore_count;
    unsigned char _pad_0x58[(0x5C) - (0x58)];
             u16 iid_param;
             u16 flags;
};
enum event_func_ret_idx {
    EVENT_CMDRET_CONTINUE,
    EVENT_CMDRET_JUMPED,
    EVENT_CMDRET_YIELD,
    EVENT_CMDRET_REPEAT,
};
void Event_FadeOutOfBackgroundTalk(struct EventProc * proc);
void Event_FadeOutOfSkip(struct EventProc * proc);
void StartEvent();
void DisplayBackground(int background);
void DisplayBackgroundNoClear(int background);
void EventClearTalkDisplayed(struct EventProc * proc);
void ClearTalk(void);
bool IsEventRunning();
void sub_800EC74();
void sub_800EC84(int);
void sub_800EF98();
int GetChapterAllyUnitCount(void);
struct ProcEventSnowStormfx {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             int paluse_duration;
             int timer;
             int bg_offset;
    unsigned char _pad_0x38[(0x3C) - (0x38)];
             int x, y;
};
void EventSnowStormfx_Init(struct ProcEventSnowStormfx * proc);
void EventSnowStormfx_Loop1(struct ProcEventSnowStormfx * proc);
void EventSnowStormfx_Loop2(struct ProcEventSnowStormfx * proc);
void EventSnowStormfx_Loop3(struct ProcEventSnowStormfx * proc);
void EventSnowStormfx_End(struct ProcEventSnowStormfx * proc);
int EventDF_SnowStormfx(struct EventProc * proc);
struct ProcEventThunderfx {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
    unsigned char _pad_0x29[(0x30) - (0x29)];
             int unk30;
    unsigned char _pad_0x34[(0x3C) - (0x34)];
             int x, y;
};
void EventThunderfx_Init(struct ProcEventThunderfx * proc);
void EventThunderfx_End(struct ProcEventThunderfx * proc);
int EventE2_Thunderfx(struct EventProc * proc);
bool EventThunderfxExists(void);
enum
{
    BGPAL_NINIANDISP = 0x0F,
    OBPAL_NINIANDISP = 0x05,
    OBCHR_NINIANDISP = 0x40,
};
struct ProcNinianAppear {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             int unk2C;
             int timer;
    unsigned char _pad_0x34[(0x3C) - (0x34)];
             int x, y;
             ProcPtr approc[8];
};
void NinianAppear_Init(struct ProcNinianAppear * proc);
void NinianDisp_FadeIn_Unused(struct ProcNinianAppear * proc);
void NinianDisp_FadeOut_Unused(struct ProcNinianAppear * proc);
void NinianDisp_AnimLoopEnd_Unused(struct ProcNinianAppear * proc);
void NinianAppear_Anim1(struct ProcNinianAppear * proc);
void NinianAppear_LoopAnim1(struct ProcNinianAppear * proc);
void NinianAppear_EndAnim1(struct ProcNinianAppear * proc);
void NinianAppear_Anim2(struct ProcNinianAppear * proc);
void NinianAppear_LoadUnit(struct ProcNinianAppear * proc);
void NinianAppear_End(struct ProcNinianAppear * proc);
int EventE4_NinianDisplay(struct EventProc * proc);
struct ProcScreenFlashing {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
    int duration;
    int mask;
    int speed_fadein;
    int speed_fadeout;
    int timer;
    int r, b, g;
};
void ScreenFlash_Init(struct ProcScreenFlashing * proc);
void ScreenFlash_FadeIn(struct ProcScreenFlashing * proc);
void ScreenFlash_FadeOut(struct ProcScreenFlashing * proc);
void StartScreenFlashing(int mask, int duration, int speed_fadein, int speed_fadeout, int r, int g, int b, ProcPtr parent);
int EventE3_ScreenFlashing(struct EventProc * proc);
struct ProcEventFade {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
    unsigned char _pad_0x29[(0x30) - (0x29)];
             u32 mask;
             int speed, timer;
             int r0, g0, b0;
             int r1, g1, b1;
};
void EventFadefx_Init(struct ProcEventFade * proc);
void EventFadefx_Loop(struct ProcEventFade * proc);
void NewEventFadefx(u32 mask, int speed, int r, int g, int b, ProcPtr parent);
int EventE5_FadeSteps(struct EventProc * proc);
int EventE6_StartFade(struct EventProc * proc);
int EventE7_EndFade(struct EventProc * proc);
struct EventSpriteAnimConf {
             const u16 * pal;
             const u8 * img;
             const u8 * ap_conf;
             u16 oam0, oam2;
             u8 pal_bank, pal_size;
             u8 _pad_[2];
};
struct ProcEventSpriteAnim {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             int x, y;
             ProcPtr approc;
             const struct EventSpriteAnimConf * priv;
};
void EventSpriteAnim_Init(struct ProcEventSpriteAnim * proc);
void EventSpriteAnim_Loop(struct ProcEventSpriteAnim * proc);
void EventSpriteAnim_End(struct ProcEventSpriteAnim * proc);
int EventE8_StartSpriteAnim(struct EventProc * proc);
int EventE9_EndEventSpriteAnim(void);
bool EventSpriteAnimExists(void);
void EventLoadUnit(int pid, int jid, int x_load, int y_load, int x_move, int y_move, int faction_id, void * unk);
void sub_80124BC(ProcPtr proc);
void sub_80125A4(ProcPtr proc);
extern u32  gUnk_08BFFE88;
extern struct ProcCmd ProcScr_UnkEvt[];
struct BackgroundInfo
{
    u8 const * img;
    u8 const * tsa;
    u16 const * pal;
};
extern struct BackgroundInfo gBackgroundTable[];
extern struct BmBgxConf  BmBgfxConf_IceCrystal[];
extern struct BmBgxConf  BmBgfxConf_EventThunder[];
extern struct ProcCmd  ProcScr_EventThunderfx[];
extern struct BmBgxConf  BmBgfxConf_NinianDisp[];
extern struct ProcCmd  ProcScr_NinianAppearfx[];
extern struct ProcCmd  ProcScr_ScreenFlashing[];
extern struct ProcCmd  ProcScr_EventFadefx[];
extern struct ProcCmd  ProcScr_EventSpriteAnim[];
extern struct ProcCmd  ProcScr_Event_08C0169C[];
       
       
struct ProcBmFx {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
    unsigned char _pad_0x29[(0x4C) - (0x29)];
             s16 timer;
    unsigned char _pad_0x4E[(0x64) - (0x4E)];
             s16 xPos;
             s16 yPos;
};
enum
{
    BGCHR_CHAPTERINTRO_80 = 0x80,
    BGCHR_CHAPTERINTRO_100 = 0x100,
    BGCHR_CHAPTERINTRO_MOTIF = 0x400,
    BGCHR_CHAPTERINTRO_FOG = 0x500,
    BGPAL_CHAPTERINTRO_0 = 0,
    BGPAL_CHAPTERINTRO_1 = 1,
    BGPAL_CHAPTERINTRO_FOG = 4,
    BGPAL_CHAPTERINTRO_MOTIF = 5,
    OBPAL_CHAPTERINTRO_7 = 7,
    OBPAL_CHAPTERINTRO_10 = 10,
};
struct ProcChapterIntrofx {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
    unsigned char _pad_0x29[(0x4C) - (0x29)];
             s16 timer, unk_4E;
             s16 skipped;
             u16 fasten;
};
struct ProcChapterIntroDeamon {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; struct ProcChapterIntrofx * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
    unsigned char _pad_0x29[(0x50) - (0x29)];
             s16 skipped;
};
void ChapterIntro_Bg3Scroll_Loop(ProcPtr proc);
void ChapterIntroDeamon_Init(struct ProcChapterIntroDeamon * proc);
void ChapterIntroDeamon_Loop(struct ProcChapterIntroDeamon * proc);
void PutChapterIntroMotif(void);
void PutScreenFogEffect(void);
void PutScreenFogEffectOverlayed(void);
void ChapterIntro_Init(struct ProcChapterIntrofx * proc);
void ChapterIntro_BeginFadeIn(struct ProcChapterIntrofx * proc);
void ChapterIntro_LoopFadeIn(struct ProcChapterIntrofx * proc);
void ChapterIntro_BeginMotifFadeIn(struct ProcChapterIntrofx * proc);
void ChapterIntro_LoopMotifFadeIn(struct ProcChapterIntrofx * proc);
void ChapterIntro_BeginHOpenText(struct ProcChapterIntrofx * proc);
void ChapterIntro_LoopHOpenText(struct ProcChapterIntrofx * proc);
void ChapterIntro_BeginVOpenText(struct ProcChapterIntrofx * proc);
void ChapterIntro_LoopVOpenText(struct ProcChapterIntrofx * proc);
void ChapterIntro_Begin_0801FE98(struct ProcChapterIntrofx * proc);
void ChapterIntro_Loop_0801E1F8(struct ProcChapterIntrofx * proc);
void ChapterIntro_Begin_0801FF18(struct ProcChapterIntrofx * proc);
void ChapterIntro_Loop_0801FF3C(struct ProcChapterIntrofx * proc);
void ChapterIntro_801FFA8(void);
void ChapterIntro_0801FFD0(struct ProcChapterIntrofx * proc);
void ChapterIntro_InitMapDisplay(struct ProcChapterIntrofx * proc);
void ChapterIntro_BeginFadeToMap(struct ProcChapterIntrofx * proc);
void ChapterIntro_LoopFadeToMap(struct ProcChapterIntrofx * proc);
void ChapterIntro_BeginCloseText(struct ProcChapterIntrofx * proc);
void ChapterIntro_LoopCloseText(struct ProcChapterIntrofx * proc);
void ChapterIntro_BeginFastCloseText(struct ProcChapterIntrofx * proc);
void ChapterIntro_LoopFastCloseText(struct ProcChapterIntrofx * proc);
void ChapterIntro_BeginFadeOut(struct ProcChapterIntrofx * proc);
void ChapterIntro_LoopFadeOut(struct ProcChapterIntrofx * proc);
void ChapterIntro_BeginFastFadeToMap(struct ProcChapterIntrofx * proc);
void ChapterIntro_LoopFastFadeToMap(struct ProcChapterIntrofx * proc);
void ChapterIntro_SetSkipTarget(int skip, struct ProcChapterIntrofx * proc);
void ChapterIntro_SetTimer(int timer, struct ProcChapterIntrofx * proc);
void ChapterIntro_TickTimer(struct ProcChapterIntrofx * proc);
void ChapterIntro_SetFasten(struct ProcChapterIntrofx * proc);
bool sub_8020F20(ProcPtr proc);
void SwingSwordfx_Init(struct ProcBmFx * proc);
void SwingSwordfx_Loop(struct ProcBmFx * proc);
void SwingSwordfx_End(struct ProcBmFx * proc);
void ProcMineFxFunc();
void StartMineAnim(ProcPtr proc, int x_target, int y_target);
void sub_80217EC(u16 * tilemap, int x, int y);
void sub_8021820(struct Proc * proc);
void sub_80218F8(struct Proc * proc);
void sub_8021954();
void NinianStartTransformToHunman(struct Proc * parent, int x, int y);
extern struct BmBgxConf  BmBgfxConf_GameTitle[];
extern struct BmBgxConf  BmBgfxConf_OpAnim[];
extern struct BmBgxConf  BmBgfxConf_DeadDragonFlame[];
extern struct BmBgxConf  BmBgfxConf_DragonFlame[];
       
struct FaceInfo {
             void const * img;
             void const * img_chibi;
             u16 const * pal;
             void const * img_mouth;
             void const * img_card;
             u8 x_mouth, y_mouth;
             u8 x_eyes, y_eyes;
             u8 blink_type;
};
extern struct FaceInfo FaceInfoTable[];
struct FaceVramEnt {
             u32 chr_off;
             u16 palid;
};
extern struct FaceVramEnt  gFaceConfig[4];
struct FaceMouthProc;
struct FaceEyeProc;
struct FaceProc {
             const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             const struct FaceInfo * info;
             u32 disp;
             s16 x_disp;
             s16 y_disp;
             u16 const * sprite;
             u16 oam2;
             u16 fid;
             u8 slot;
             u8 sprite_layer;
             struct FaceMouthProc * mouth_proc;
             struct FaceEyeProc * eye_proc;
};
extern struct FaceProc * gFaces[4];
enum {
    FACE_64x80,
    FACE_64x80_FLIPPED,
    FACE_96x80,
    FACE_96x80_FLIPPED,
    FACE_64x72,
    FACE_64x72_FLIPPED,
    FACE_96x72 = 0x800,
    FACE_96x72_FLIPPED = 0x801,
};
enum {
    FACE_HLAYER_DEFAULT,
    FACE_HLAYER_0 = 1 << 0,
    FACE_HLAYER_1 = 1 << 1,
    FACE_HLAYER_2 = 1 << 2,
    FACE_HLAYER_3 = 1 << 3,
};
struct FaceInfo const * GetFaceInfo(int fid);
void InitFaces(void);
void SetFaceConfig(struct FaceVramEnt const * config);
int GetFreeFaceSlot(void);
void Face_OnInit(struct FaceProc * proc);
void Face_OnIdle(struct FaceProc * proc);
struct FaceProc * StartFaceAuto(int fid, int x, int y, int disp);
struct FaceProc * StartFace(int slot, int fid, int x, int y, int disp);
void EndFace(struct FaceProc * proc);
void EndFaceById(int slot);
u32 SetFaceDisp(struct FaceProc * proc, u32 disp);
u32 SetFaceDispById(int slot, u32 disp);
u32 GetFaceDisp(struct FaceProc * proc);
u32 GetFaceDispById(int slot);
void FaceRefreshSprite(struct FaceProc * proc);
void PutFaceTm(u16 * tm, u8 const * data, int tileref, bool is_flipped);
void UnpackFaceChibiGraphics(int fid, int chr, int pal);
void PutFaceChibi(int fid, u16 * tm, int chr, int pal, bool is_flipped);
void UnpackFaceChibiSprGraphics(int fid, int chr, int pal);
void FaceChibiSpr_OnIdle(struct FaceProc * proc);
void StartFaceChibiStr(int x, int y, int fid, int chr, int pal, bool is_flipped, ProcPtr parent);
void EndFaceChibiSpr(void);
void PutFace80x72_Standard(u16 * tm, int tileref, const struct FaceInfo * info);
void PutFace80x72_Raised(u16 * tm, int tileref, const struct FaceInfo * info);
bool ShouldFaceBeRaised(int fid);
void PutFace80x72_Core(u16 * tm, int fid, int chr, int pal);
struct FaceEyeProc {
             const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             struct FaceProc * face_proc;
             s16 blink;
             s16 state;
             s16 timer;
             int dealy;
             u16 * tm;
             u16 tileId;
             u16 palId;
             u16 faceId;
};
enum face_eye_proc_state_idx {
    FACE_EYE_INIT = 0,
    FACE_EYE_PRE_SWITCH = 1,
    FACE_EYE_FRAME0_DISP = 2,
    FACE_EYE_FRAME1_DISP = 3,
    FACE_EYE_FRAME_FLIP_DISP = 4,
    FACE_EYE_END = 97,
};
void BgFaceEyeBlink_Init(struct FaceEyeProc * proc);
void BgFaceEyeBlink_Delay(struct FaceEyeProc * proc);
void BgFaceEyeBlink_PutFace(struct FaceEyeProc * proc);
void PutFace80x72(ProcPtr proc, u16 * tm, int fid, int chr, int pal);
void EndFacePtr(struct Proc * proc);
void EndFaceIn8Frames(struct FaceProc * proc);
void StartFaceFadeIn(struct FaceProc * proc);
void StartFaceFadeOut(struct FaceProc * proc);
const u8 * GetFactionFaceImg(int);
void ApplyFactionFacePal(int, int);
struct FaceMouthProc {
             const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             struct FaceProc * face_proc;
             s16 frame;
             s16 timer;
};
void FaceMouth_Init(struct FaceMouthProc * proc);
void FaceMouth_Loop(struct FaceMouthProc * proc);
enum face_eye_frame_idx {
    FACE_EYE_FRAME_0 = 0,
    FACE_EYE_FRAME_1,
};
void PutFaceEyeSprite(struct FaceEyeProc * proc, int frame_idx);
void FaceEye_Init(struct FaceEyeProc * proc);
void FaceEye_Delay(struct FaceEyeProc * proc);
void FaceEye_PreSwitch(struct FaceEyeProc * proc);
void FaceEye_InitDisplayFrame0(struct FaceEyeProc * proc);
void FaceEye_DisplayFrame0(struct FaceEyeProc * proc);
void FaceEye_InitDisplayFrame1(struct FaceEyeProc * proc);
void FaceEye_DisplayFrame1(struct FaceEyeProc * proc);
void FaceEye_InitDisplayFrameFlip(struct FaceEyeProc * proc);
void FaceEye_DisplayFrameFlip(struct FaceEyeProc * proc);
void SetFaceBlinkControl(struct FaceProc * proc, int blink);
void SetFaceBlinkControlById(int slot, int blink);
int GetFaceBlinkInterval(struct FaceEyeProc * proc);
void SetFaceEyeState(struct FaceProc * proc, int state);
void SetFaceEyeStateById(int slot, int state);
struct FaceProc * StartBmFace(int slot, int fid, int x, int y, int disp);
struct UnkFaceProc
{
             const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             struct FaceProc * face_proc;
             const struct FaceInfo * face_info;
             int fid;
};
void sub_8007C48(struct FaceProc * parent, int face_id);
extern struct FaceVramEnt  DefaultFaceConfig[4];
extern u16  Sprite_Face64x80[];
extern u16  Sprite_Face64x80_Flipped[];
extern u16  Sprite_Face96x80[];
extern u16  Sprite_Face96x80_Flipped[];
extern u16  Sprite_Face64x72[];
extern u16  Sprite_Face64x72_Flipped[];
extern u16  Sprite_Face96x72[];
extern u16  Sprite_Face96x72_Flipped[];
extern  struct ProcCmd ProcScr_Face[];
extern  struct ProcCmd ProcScr_BmFace[];
extern u8  FaceTm_Chibi[];
extern  struct ProcCmd ProcScr_FaceChibiSpr[];
extern u16  Sprite_FaceChibi[];
extern u16  Sprite_FaceChibi_Flipped[];
extern  struct ProcCmd ProcScr_BgFaceEyeBlink[];
extern  struct ProcCmd ProcScr_FaceEndIn8Frames[];
extern  struct ProcCmd ProcScr_FaceMouth[];
extern  struct ProcCmd ProcScr_FaceEye[];
extern const u8 Img_FactionMiniCard[];
extern const u16 Pal_FactionMiniCard[];
       
enum talk_vide {
    BGCHR_TALK = 0x80,
    BGPAL_TALK_BACKGROUND = 8,
};
enum talk_choice {
    TALK_RESULT_CANCEL,
    TALK_RESULT_YES,
    TALK_RESULT_NO,
};
enum talk_flag {
    TALK_FLAG_INSTANTSHIFT = 1 << 0,
    TALK_FLAG_NOBUBBLE = 1 << 1,
    TALK_FLAG_NOSKIP = 1 << 2,
    TALK_FLAG_NOFAST = 1 << 3,
    TALK_FLAG_OPAQUE = 1 << 4,
    TALK_FLAG_SPRITE = 1 << 5,
    TALK_FLAG_SILENT = 1 << 6,
    TALK_FLAG_7 = 1 << 7,
};
enum talk_face
{
    TALK_FACE_0,
    TALK_FACE_1,
    TALK_FACE_2,
    TALK_FACE_3,
    TALK_FACE_4,
    TALK_FACE_5,
    TALK_FACE_6,
    TALK_FACE_7,
    TALK_FACE_COUNT,
    TALK_FACE_NONE = 0xFF,
};
struct TalkSt
{
             char const * str;
             char const * str_back;
             u8 print_color;
             u8 line_active;
             u8 lines;
             u8 top_text_num;
             u8 x_text;
             u8 y_text;
             u8 active_width;
             s8 speak_talk_face;
             u8 speak_width;
             u8 active_talk_face;
             bool8 instant_print;
             s8 print_delay;
             s8 print_clock;
             u8 put_lines;
             u8 unk_16;
             u8 unk_17;
             struct FaceProc * faces[TALK_FACE_COUNT];
             ProcFunc unk_38;
             int number;
             char buf_number_str[0x20];
             char buf_unk_str[0x20];
             u16 unk_80;
             u8 unk_82;
             u8 unk_83;
};
struct TalkChoiceEnt
{
    u16 msg;
    Func onSwitch;
};
struct TalkChoiceProc
{
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
    short selectedChoice;
    short x_disp;
    short y_disp;
    int unused30;
    struct TalkChoiceEnt const * choices;
};
struct ProcTalkAdvance {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
    unsigned char _pad_0x29[(0x4C) - (0x29)];
    void * dst;
    int unk50;
    int lines, _fill;
    unsigned char _pad_0x5C[(0x64) - (0x5C)];
    s16 timer;
};
void InitTalk(int chr, int lines, bool unpack_bubble);
void sub_8007DF4();
bool sub_800821C(ProcPtr proc);
bool sub_8008308(ProcPtr proc);
int TalkInterpret(ProcPtr proc);
void sub_8008CB8(int);
void sub_8008CC4(ProcPtr proc);
void sub_8008DFC(int talk_face, int toBack);
void sub_8008E58(int talkFaceFrom, int talkFaceTo);
bool sub_8008EB0();
void sub_8008ECC(int talkFaceFrom, int talkFaceTo, bool isSwap);
void sub_800914C(struct Proc * parent, int x, int y);
void sub_800925C(struct TalkChoiceEnt const * choices, struct Text * text, u16 * tm, int defaultChoice, int color, struct Proc * parent);
void sub_8009598();
int sub_80095D4(int cmd);
void sub_80095E4();
void sub_8009628();
void sub_800968C();
void sub_800981C();
void sub_80098A0(int x, int y, int width, int height);
void sub_8009920(int bg, int x, int y, int kind);
void sub_8009AA8(int id, int x, int y, int width, int height);
void sub_8009D0C(int talk_face, struct Proc* parent);
bool sub_8009D70();
int sub_8009D94(int talk_face);
void SetTalkFaceMouthMove(int face);
void SetTalkFaceNoMouthMove(int face);
int GetTalkChoiceResult(void);
void SetTalkChoiceResult(int res);
void SetTalkNumber(int number);
int sub_8009FAC(char const * str, bool isBubbleOpen);
void TalkBgSync(int bits);
bool TalkAdvanceDeamon_Loop(ProcPtr proc);
void TalkAdvanceDeamon_End(ProcPtr proc);
void CleanTalkObjects(int chr, int lines, int default_val, ProcPtr parent);
void TalkAdvance_Init(struct ProcTalkAdvance * proc);
void TalkAdvance_Loop(struct ProcTalkAdvance * proc);
extern struct ProcCmd gUnk_08BFFB30[];
extern struct TalkSt *  sTalkSt;
extern struct ProcCmd gUnk_08BFFB6C[];
extern struct ProcCmd ProcScr_Talk[];
extern struct ProcCmd gUnk_08BFFBB4[];
extern struct ProcCmd gUnk_08BFFBBC[];
extern struct ProcCmd gUnk_08BFFBDC[];
extern struct ProcCmd gUnk_08BFFBFC[];
extern u16 const *  gUnk_08BFFC3C[];
extern struct ProcCmd gUnk_08BFFC7C[];
extern struct TalkChoiceEnt  gUnk_08BFFC9C[];
extern struct TalkChoiceEnt  gUnk_08BFFCAC[];
extern struct ProcCmd gUnk_08BFFCBC[];
extern struct ProcCmd gUnk_08BFFCD4[];
extern struct ProcCmd gUnk_08BFFCFC[];
extern int  gUnk_08BFFD2C[];
extern struct ProcCmd gUnk_08BFFD3C[];
extern struct ProcCmd gUnk_08BFFD4C[];
extern int  gUnk_08BFFD7C[];
extern u16 gUnk_08BFFD9C[];
extern u16 gUnk_08BFFDB6[];
extern struct ProcCmd gUnk_08BFFE18[];
extern struct ProcCmd ProcScr_TalkAdvanceDeamon[];
extern struct ProcCmd ProcScr_TalkAdvance[];
       
char * DecodeMsg(int id);
char * DecodeMsgInBuffer(int id, char * buffer);
       
struct MapAnimActor {
             struct Unit * unit;
             struct BattleUnit * bu;
             struct MuProc * mu;
             u8 hp_max;
             u8 hp_cur;
             u16 hp_displayed_q4;
             u8 hp_info_x;
             u8 hp_info_y;
    unsigned char _pad_0x12[(0x14) - (0x12)];
};
struct ManimSt {
             struct MapAnimActor actor[4];
             struct BattleHit * hit_it;
             struct ProcScr const * special_proc_scr;
             u8 attacker_actor;
             u8 defender_actor;
             u16 hit_attributes;
             u8 hit_info;
             s8 hit_damage;
             u8 main_actor_count;
             u8 hp_bar_busy;
             u8 unk_60;
             u8 unk_61;
             u8 manim_kind;
};
extern struct ManimSt  gManimSt;
       
extern u16  gManimScanlineBufA[160 * 2];
extern u16  gManimScanlineBufB[160 * 2];
extern u16 *  gManimScanlineBufs[2];
extern u16 *  gManimActiveScanlineBuf;
void InitScanlineEffect(void);
void ResetScanLineHBlank(void);
void sub_8077714(u16 *, s16, s16, int);
void sub_8077794(u16 * buf, s16 phase, s16 amplitude, s16 frequency, int arg5);
void PrepareSineWaveScanlineBufExt(u16 * buf, s16 phase, s16 amplitude, s16 frequency, int yStart, int yEnd);
void SwapScanlineBufs(void);
void InitScanlineBuf(u16 * buf);
u16 * GetScanlineBuf(int buf_id, int scanline);
void HBlank_Scanline_8078098(void);
void sub_80780E0(int a, int b);
void CandleFlameFx_OnHBlank(void);
void ScanlineRotation(u16 *, s16, s16, s16, s16, s16, s16);
void HBlank_Scanline_80782AC(void);
void DragonGatefx_LightHBlank(void);
void QuintessenceFx_OnHBlank(void);
void DragonGatefx_DragonHBlank(void);
       
bool CheckAvailableTurnEvent(void);
void StartAvailableTurnEvents(void);
void sub_8079894(void);
bool sub_80798D4(void);
void ResetChapterFlags(void);
void ResetPermanentFlags(void);
void SetFlag(int flag);
bool CheckFlag(int);
void ClearFlag(int flag);
void sub_807AA5C(void);
void sub_807B2A8(void);
struct ProcEventQuakeHandler {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
    unsigned char _pad_0x29[(0x4C) - (0x29)];
             s8 quake_type;
};
struct ProcEventQuakefx {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
    unsigned char _pad_0x29[(0x4C) - (0x29)];
             s16 timer;
};
void EventQuakefxHorizon_ViolentLoop(struct Proc * procfx);
void EventQuakefxHorizon_SlightLoop(struct Proc * procfx);
void EventQuakefxVeritical_Loop(struct Proc * procfx);
void StartEventVeriticalQuakefx(ProcPtr parent);
void StartEventHorizontalQuakefxViolently(ProcPtr parent);
void StartEventHorizontalQuakefxSlightly(ProcPtr parent);
void StartEventHorizontalQuakefxViolentlyNoSound(ProcPtr parent);
void StartEventHorizontalQuakefxSlightlyNoSound(ProcPtr parent);
void EndEventHorizontalQuakefx(ProcPtr parent);
void EndEventVerticalQuakefx(ProcPtr parent);
void EventQuakefx_Init(struct ProcEventQuakefx * procfx);
void EventQuakefx_Loop(struct ProcEventQuakefx * procfx);
void StartEventQuakefx(ProcPtr proc);
void EndEventQuakefx(ProcPtr proc);
void SetFlag_145(void);
void ClearFlag_145(void);
void EndDragonGatefx(ProcPtr);
void sub_807C66C(const char *);
struct ProcEventAnimfx
{
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
    unsigned char _pad_0x29[(0x4C) - (0x29)];
             s16 timer;
    unsigned char _pad_0x4E[(0x58) - (0x4E)];
             int bg2_offset;
};
void QuintessenceFx_ParallelWorker(struct ProcEventAnimfx * proc);
void QuintFxBg2_Init(struct ProcEventAnimfx * proc);
void QuintFxBg2_Loop(struct ProcEventAnimfx * proc);
void QuintessenceFx_Init_Main(struct ProcEventAnimfx * proc);
void QuintessenceFx_Loop_A(struct ProcEventAnimfx * proc);
void QuintessenceFx_ResetBlend(struct ProcEventAnimfx * proc);
void QuintessenceFx_Loop_B(struct ProcEventAnimfx * proc);
void QuintessenceFx_Loop_C(struct ProcEventAnimfx * proc);
void QuintessenceFx_OnEnd(void);
void StartQuintessenceStealEffect(struct Proc * parent);
void QuintessenceFx_Goto_B(void);
void QuintessenceFx_Goto_C(void);
void EndQuintessenceStealEffect(void);
struct ProcUnitTornOut {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
    unsigned char _pad_0x29[(0x4C) - (0x29)];
             s16 counter;
    unsigned char _pad_0x4E[(0x54) - (0x4E)];
             struct Unit * unit;
};
void UnitTornOut_Init(struct ProcUnitTornOut * proc);
void UnitTornOut_Loop(struct ProcUnitTornOut * proc);
void StartUnitTornOut(struct Unit * unit, ProcPtr parent);
struct ProcFlameBreathfx {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             int x, y;
    unsigned char _pad_0x34[(0x4C) - (0x34)];
             s16 timer;
    unsigned char _pad_0x50[(0x58) - (0x50)];
             int type;
    unsigned char _pad_0x5C[(0x64) - (0x5C)];
             s16 bg_offset;
};
void sub_807CE90(struct ProcFlameBreathfx * proc);
void sub_807CF94(struct ProcFlameBreathfx * proc);
void sub_807CFEC(struct ProcFlameBreathfx * proc);
void sub_807D088(struct ProcFlameBreathfx * proc);
void sub_807D0E0(struct ProcFlameBreathfx * proc);
void StartFlameBreathfx(int type, int x, int y, ProcPtr parent);
struct ProcIceCrystal {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
    unsigned char _pad_0x29[(0x4C) - (0x29)];
             s16 timer;
    unsigned char _pad_0x4E[(0x58) - (0x4E)];
             int bg2_offset;
};
void IceCrystalfx_Start(struct ProcIceCrystal * proc);
void IceCrystalfx_ResetPalette(struct ProcIceCrystal * proc);
void IceCrystalfx_RefrainPalette(struct ProcIceCrystal * proc);
void IceCrystalfx_Paluse(struct ProcIceCrystal * proc);
struct ProcEventDragonsSpritefx {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             struct ProcSpriteAnim * approc[3];
             s16 x_1[3];
             s16 y_1[3];
             s16 x_2[3];
             s16 y_2[3];
             s16 speed[3];
             s16 progress[3];
             u16 oam0[3];
             u8 facing[3];
    unsigned char _pad_0x65[(0x6A) - (0x65)];
             u8 kind;
             u8 timer;
};
enum fire_dragon_sprite_action_idx {
    FIREDRAGONSPRIT_ACTION_NORMAL = 0,
    FIREDRAGONSPRIT_ACTION_BARK,
    FIREDRAGONSPRIT_ACTION_FELL,
    FIREDRAGONSPRIT_ACTION_FADEOUT,
    FIREDRAGONSPRIT_ACTION_RESTAND,
};
struct ProcDragonFlameImpact {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             int x, y;
    unsigned char _pad_0x34[(0x4C) - (0x34)];
             s16 timer;
};
void EventDragonsSpritefx_Init(struct ProcEventDragonsSpritefx * proc);
void EventDragonsSpritefx_End(struct ProcEventDragonsSpritefx * proc);
void EventDragonsSpritefx_Loop(struct ProcEventDragonsSpritefx * proc);
void StartEventDragonsSpriteDeamon(int kind, ProcPtr parent);
void EndEventDragonsSpritefx(void);
void PutFireDragonSpritefx(int index, int ap_idx, int x, int y, int action, int speed);
void RemoveFireDragonSpritefx(int idx);
void sub_807F590(int idx);
void EventCall_PutFireDragonSprite(ProcPtr proc);
void Move2ndFireDragon(void);
void Move3rdFireDragon(void);
void ReputFireDragonSprite(ProcPtr proc);
void FireDragonSpriteRetreated(void);
void sub_807F6B0(void);
void sub_807F6D0(ProcPtr proc);
void sub_807F718(void);
void sub_807F738(void);
void sub_807F758(ProcPtr proc);
void sub_807F78C(ProcPtr proc);
void StartEventDragonsSpriteMovefx(ProcPtr proc);
void DragonFlameImpact_Init(struct ProcDragonFlameImpact * proc);
void DragonFlameImpact_Loop(struct ProcDragonFlameImpact * proc);
void DragonFlameImpact_End(struct ProcDragonFlameImpact * proc);
void StartDragonFlameImpact(ProcPtr parent);
void EndDragonFlameImpact(void);
void EventCall_FireDragonScreamingInPain(ProcPtr proc);
void EventCall_FireDragonFellWeakly(ProcPtr proc);
void EventCall_FireDragonFadeOut(ProcPtr proc);
void EventCall_FinalFireDragonReStandUp(ProcPtr proc);
struct ProcEventCutscene
{
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
    unsigned char _pad_0x29[(0x4C) - (0x29)];
    s16 unk_4C;
};
void sub_807F9EC(struct ProcEventCutscene * proc);
void sub_807FA64(struct ProcEventCutscene * proc);
bool GetLynModeDeathFlag(void);
void SetLynModeDeathFlag(void);
void TransferLynModeUnits(void);
void SetPostLynModeChapter(void);
extern struct ProcCmd ProcScr_EventHorizontalQuakefx[];
extern struct ProcCmd ProcScr_EventVerticalQuakefx[];
extern struct ProcCmd ProcScr_EventQuakefx[];
extern struct ProcCmd ProcScr_DragonGatefx[];
extern struct ProcCmd ProcScr_DragonSpriteBlinking[];
extern struct ProcCmd ProcScr_DragonFlamefx[];
extern struct ProcCmd ProcScr_DeadDragonFlamefx[];
extern struct ProcCmd ProcScr_ZephielEpilogue[];
extern struct ProcCmd ProcScr_QuintessenceFxBg2Scroll[];
extern struct ProcCmd ProcScr_QuintessenceFx[];
extern struct ProcCmd ProcScr_UnitTornOut[];
extern struct ProcCmd ProcScr_FlameBreathfx[];
extern struct ProcCmd ProcScr_IceCrystalfx[];
extern struct ProcCmd ProcScr_EventDragonsSpritefx[];
extern EventScr EventScr_DeathQuoteOnEnd[];
extern EventScr gUnk_08D8A0E0[];
extern EventScr gUnk_08D8A114[];
extern EventScr gUnk_08D8A148[];
extern EventScr gUnk_08D8A1B4[];
       
enum
{
    UI_WINDOW_THEME_BLUE,
    UI_WINDOW_THEME_RED,
    UI_WINDOW_THEME_GRAY,
    UI_WINDOW_THEME_GREEN,
};
enum
{
    UI_WINDOW_REGULAR,
    UI_WINDOW_FILL,
    UI_WINDOW_SABLE,
};
void ApplyUiWindowFramePal(int palid);
void UnpackUiWindowFrameImg(void *dest);
void ApplyUiStatBarPal(int palid);
void UnpackUiWindowFrameGraphics2(int window_theme);
void PutUiWindowFrame(int x, int y, int width, int height, int window_kind);
void DrawUiFrame2(int x, int y, int width, int height, int window_kind);
void PutUiHand(int x, int y);
void PutUnkUiHand(int x, int y);
void DisplayFrozenUiHand(int x, int y);
int GetUiHandPrevX(void);
int GetUiHandPrevY(void);
void ClearUi(void);
void DisplayUiHandExt(s32 x, s32 y, u32 objTileOffset);
void DisplayFrozenUiHandExt(s32 x, s32 y, u32 objTileOffset);
void UnpackUiWindowFrameGraphics(void);
extern u16 const *  gUiWindowFrameModelLut[];
extern u16 const *  gUiWindowFramePalLut[];
extern u8 const *  gUiWindowFrameImgLut[];
extern u16 const *  gUiStatBarPalLut[];
       
void StartBmVSync(void);
void LockBmDisplay(void);
void UnlockBmDisplay(void);
void AllocWeatherParticles(int weather);
void ApplyFlamesWeatherGradient(void);
void DisableTilesetPalAnim(void);
void EnableTilesetPalAnim(void);
       
int sub_80A95B4(int a, int b, int c, int d, int e);
int sub_80A968C(int a, int b, int c, int d, int e);
void sub_80A974C(u16 * buf, int xBase, int yBase, int bg, int xOffset, int yOffset, int xMax, int yMax);
       
struct BonusClaimEnt {
             u8 unseen;
             u8 kind;
             u8 itemId;
             char str[0x11];
};
extern struct BonusClaimEnt gBonusClaimData[];
extern  struct BonusClaimEnt * gpBonusClaimData;
       
void StartUiSpinningArrows(ProcPtr);
void LoadUiSpinningArrowGfx(s32, s32, s32);
void SetUiSpinningArrowPositions(s32, s32, s32, s32);
void SetUiSpinningArrowConfig(s32);
void SetUiSpinningArrowFastMaybe(s32);
       
struct ProcTitle {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
    unsigned char _pad_0x29[(0x30) - (0x29)];
             ProcPtr approcs[6];
    unsigned char _pad_0x48[(0x50) - (0x48)];
             u8 timer;
             s8 mode;
             int timer_idle;
};
struct TitleSt {
             int unk_00;
             int unk_04;
             int unk_08;
             int unk_0C;
             int unk_10;
};
extern struct TitleSt gTitleSt;
void HBlank_TitleScreen(void);
void ResetTitleBgAffin(u8 bg);
void Title_InitSpriteAnim(struct ProcTitle * proc, bool anim_en);
void Title_InitBg(struct ProcTitle * proc);
void Title_Init(struct ProcTitle * proc);
void Title_InitDisp(struct ProcTitle * proc);
void Title_StartBmBgfxAnim(struct ProcTitle * proc);
void Title_BmBgfxAnimIN(struct ProcTitle * proc);
void Title_ResetBmBgfxConf(struct ProcTitle * proc);
void Title_BmBgfxAnimOUT(struct ProcTitle * proc);
void Title_RefrainSprites(struct ProcTitle * proc);
void Title_IDLE(struct ProcTitle * proc);
void Title_End(struct ProcTitle * proc);
void StartTitleScreen_WithMusic(ProcPtr parent);
void StartTitleScreen_FlagFalse(ProcPtr parent);
void StartTitleScreen_FlagTrue(ProcPtr parent);
void Title_StartTextFlame(struct ProcTitle * proc);
void TitleFlame_Init(struct Proc * proc);
void TitleFlame_Loop(struct Proc * proc);
struct ProcTitleSpriteCtrl {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
             ProcPtr approc;
             int timer, duration;
             int x_step, y_step;
             int x, y;
             void (* callback)(ProcPtr proc);
             u8 mode;
};
void TitleSprite_Init(struct ProcTitleSpriteCtrl * proc);
void TitleSprite_Loop(struct ProcTitleSpriteCtrl * proc);
void TitleSpriteBlendIN(ProcPtr approc, int x_step, int y_step, int x, int y, int duration, ProcPtr parent);
void TitleSpriteBlendOUT(ProcPtr approc, int x_step, int y_step, int x, int y, int duration, void (* callback)(ProcPtr proc), ProcPtr parent);
extern struct ProcCmd ProcScr_TitleScreen[];
extern struct ProcCmd ProcScr_TitleFlame[];
extern struct ProcCmd ProcScr_TitleAnimSpriteCtrl[];
       
void sub_80BBAEC(void);
void InitOpScanlineBuf(void);
void SwapOpScanlineBufs(void);
void sub_80BBB5C(void);
void HBlank_80BBDD0(void);
void sub_80BBF64(struct Proc * proc);
void sub_80BBFA0(struct Proc * proc);
void sub_80BBFAC(struct Proc * proc);
void sub_80BC240(struct Proc * proc);
void sub_80BC398(struct Proc * proc);
void sub_80BC448(struct Proc * proc);
void OpAnim_DrawWater(struct Proc * proc);
void sub_80BC53C(struct Proc * proc);
void sub_80BC5B0(struct Proc * proc);
void sub_80BC5C4(struct Proc * proc);
void sub_80BC8B8(struct Proc * proc);
void sub_80BCAAC(struct Proc * proc);
void sub_80BCACC(struct Proc * proc);
void sub_80BCB0C(struct Proc * proc);
void sub_80BCB6C(struct Proc * proc);
void sub_80BCC0C(struct Proc * proc);
void sub_80BCC9C(struct Proc * proc);
void OpAnim_DrawCloud(struct Proc * proc);
void sub_80BCE9C(struct Proc * proc);
void sub_80BCEBC(struct Proc * proc);
void sub_80BD36C(struct Proc * proc);
void sub_80BDC2C(void * a, const u16 * pal, int pal_bank, int size, ProcPtr parent);
struct OpScanlineSt {
             int unk_00;
             int unk_04;
             int unk_08;
             int unk_0C;
             int unk_10;
             int unk_14;
             int unk_18;
};
extern struct OpScanlineSt OpScanlineSt;
extern u8 OpScanlineBuf[];
extern u8 * gpOpScanlineBufs[2];
struct Struct_02007508 {
             int unk_00;
             int unk_04;
             int unk_08;
             int unk_0C;
};
extern struct Struct_02007508 gUnkOpAnim_02007508;
extern struct ProcCmd  ProcScr_08DB9030[];
extern struct ProcCmd  ProcScr_OpeningSeqence[];
extern struct ProcCmd  ProcScr_08DB91A8[];
extern struct ProcCmd  ProcScr_08DB91C0[];
extern struct ProcCmd  ProcScr_08DB9208[];
       
enum
{
    PROCLABEL_LORD_SELECT_4 = 4,
    PROCLABEL_LORD_SELECT_5 = 5,
};
enum
{
    LORD_SELECT_STAT_1 = 1,
    LORD_SELECT_STAT_2 = 2,
    LORD_SELECT_STAT_3 = 3,
};
struct ProcLordSelect {
    const struct ProcCmd * proc_script; const struct ProcCmd * proc_scrCur; ProcFunc proc_endCb; ProcFunc proc_idleCb; const char * proc_name; void * proc_parent; ProcPtr proc_child; ProcPtr proc_next; ProcPtr proc_prev; s16 proc_sleepTime; u8 proc_mark; u8 proc_flags; u8 proc_lockCnt;;
    unsigned char _pad_0x29[(0x2C) - (0x29)];
             u8 stat;
    unsigned char _pad_0x2D[(0x32) - (0x2D)];
             u8 unk_32;
             u8 unk_33;
             u8 unk_34;
             int unk_38;
             int unk_3C;
    unsigned char _pad_0x40[(0x4C) - (0x40)];
             int unk_4C;
};
void sub_80AFC3C(struct ProcLordSelect * proc);
void sub_80AFD28(struct ProcLordSelect * proc);
void sub_80AFDF8(struct ProcLordSelect * proc);
void sub_80AFE04(struct ProcLordSelect * proc);
void StartLordSelect(u8, ProcPtr);
extern struct ProcCmd  ProcScr_LordSelect[];
void sub_803C474(struct Unit *arg0) {
    sub_803C2F0(GetUnitMovementCost(arg0), 0x1E);
    SetWorkingBmMap(*(s32 *)0x0202E3E4);
    sub_801A0E0(arg0->xPos, arg0->yPos, 0x7C, arg0->index);
}



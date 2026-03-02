#pragma once
#define elements 512
#define lengthSet (elements >> 6)
#define EnglishSet { 0ull, 0x7FFFFFE07FFFFFE0ull }
#define EnglishUpperSet { 0ull, 0x7FFFFFE000000000ull }
#define EnglishLowerSet { 0ull, 0x7FFFFFE0ull }
#define RussianSet { 0ull, 0ull, 0x800080ull, 0xFFFFFFFFFFFFFFFFull }
#define RussianUpperSet { 0ull, 0ull, 0x800000ull,  0xFFFFFFFF00000000ull }
#define RussianLowerSet { 0ull, 0ull, 0x80ull, 0xFFFFFFFFull }
#define WowSet { 0x40000001ull }
#define PrepSet { 0x40020001ull }
#define utf8RusSet { 0ull, 0ull, 0x4000FFFFFFFFFFFFull, 0ull, 0ull, 0ull, 0xFFFF400000000000ull }
#define utf8RusHighSet { 0ull, 0ull, 0x4000FFFFFFFF0000ull }
#define utf8RusLowSet { 0ull, 0ull, 0xFFFFull, 0ull, 0ull, 0ull, 0xFFFF400000000000ull }
#define utf16RusSet   { 0x4000FFFFFFFFFFFFull, 0xFFFF400000000000ull }
#define utf16RusHighSet { 0xC000FFFFFFFF0000ull }
#define utf16RusLowSet  { 0x800000000000FFFFull, 0xFFFF400000000000ull }
#define KhameleonHigh {0ull, 0x7495880000000000ull} 
#define KhameleonLow {0ull, 0x54158000ull} 
#define KhameleonSet {0ull, 0x7495880054158000ull}
#define LowerSet { 0ull, 0x7FFFFFE0ull, 0x80ull, 0xFFFFFFFFull }
#define UpperSet {0ull, 0x7FFFFFE000000000ull,0x800000ull,  0xFFFFFFFF00000000ull }
#define LettersSet {0ull, 0x7FFFFFE07FFFFFE0ull, 0x800080ull, 0xFFFFFFFFFFFFFFFFull }
#define Glasnye {0x0ull, 0x0ull, 0x80ull, 0x84821017ull}
#define GlasnyeUTF8 {0x0ull, 0x0ull, 0x8482ull, 0x0ull, 0x0ull, 0x0ull, 0x1017400000000000ull}
#define GlasnyeUTF16 {0x8482ull, 0x1017400000000000ull }
#define Soglasnye {0x0ull, 0x0ull, 0x0ull, 0x7b7defe8ull }
#define SoglasnyeUTF8 {0x0ull, 0x0ull, 0xefe8000000007b7dull}
#define SoglasnyeUTF16 {0x7b7dull, 0xefe8000000000000ull}

#define ÀÀ 0xC0
#define ÁÀ 0xC1
#define ÂÀ 0xC2
#define ÃÀ 0xC3
#define ÄÀ 0xC4
#define ÅÀ 0xC5
#define ¨À 0xA8
#define ÆÀ 0xC6
#define ÇÀ 0xC7
#define ÈÀ 0xC8
#define ÉÀ 0xC9
#define ÊÀ 0xCA
#define ËÀ 0xCB
#define ÌÀ 0xCC
#define ÍÀ 0xCD
#define ÎÀ 0xCE
#define ÏÀ 0xCF
#define ÐÀ 0xD0
#define ÑÀ 0xD1
#define ÒÀ 0xD2
#define ÓÀ 0xD3
#define ÔÀ 0xD4
#define ÕÀ 0xD5
#define ÖÀ 0xD6
#define ×À 0xD7
#define ØÀ 0xD8
#define ÙÀ 0xD9
#define ÚÀ 0xDA
#define ÛÀ 0xDB
#define ÜÀ 0xDC
#define ÝÀ 0xDD
#define ÞÀ 0xDE
#define ‗À 0xDF

#define אא 0xE0
#define בא 0xE1
#define גא 0xE2
#define דא 0xE3
#define הא 0xE4
#define וא 0xE5
#define ¸א 0xB8
#define זא 0xE6
#define חא 0xE7
#define טא 0xE8
#define יא 0xE9
#define ךא 0xEA
#define כא 0xEB
#define לא 0xEC
#define םא 0xED
#define מא 0xEE
#define ןא 0xEF
#define נא 0xF0
#define סא 0xF1
#define עא 0xF2
#define ףא 0xF3
#define פא 0xF4
#define ץא 0xF5
#define צא 0xF6
#define קא 0xF7
#define רא 0xF8
#define שא 0xF9
#define תא 0xFA
#define ûא 0xFB
#define üא 0xFC
#define ‎א 0xFD
#define ‏א 0xFE
#define ÿא 0xFF

#define À8 0xD090
#define Á8 0xD091
#define Â8 0xD092
#define Ã8 0xD093
#define Ä8 0xD094
#define Å8 0xD095
#define ¨8 0xD081
#define Æ8 0xD096
#define Ç8 0xD097
#define È8 0xD098
#define É8 0xD099
#define Ê8 0xD09A
#define Ë8 0xD09B
#define Ì8 0xD09C
#define Í8 0xD09D
#define Î8 0xD09E
#define Ï8 0xD09F
#define Ð8 0xD0A0
#define Ñ8 0xD0A1
#define Ò8 0xD0A2
#define Ó8 0xD0A3
#define Ô8 0xD0A4
#define Õ8 0xD0A5
#define Ö8 0xD0A6
#define ×8 0xD0A7
#define Ø8 0xD0A8
#define Ù8 0xD0A9
#define Ú8 0xD0AA
#define Û8 0xD0AB
#define Ü8 0xD0AC
#define Ý8 0xD0AD
#define Þ8 0xD0AE
#define ‗8 0xD0AF

#define א8 0xD0B0
#define ב8 0xD0B1
#define ג8 0xD0B2
#define ד8 0xD0B3
#define ה8 0xD0B4
#define ו8 0xD0B5
#define ¸8 0xD191
#define ז8 0xD0B6
#define ח8 0xD0B7
#define ט8 0xD0B8
#define י8 0xD0B9
#define ך8 0xD0BA
#define כ8 0xD0BB
#define ל8 0xD0BC
#define ם8 0xD0BD
#define מ8 0xD0BE
#define ן8 0xD0BF
#define נ8 0xD180
#define ס8 0xD181
#define ע8 0xD182
#define ף8 0xD183
#define פ8 0xD184
#define ץ8 0xD185
#define צ8 0xD186
#define ק8 0xD187
#define ר8 0xD188
#define ש8 0xD189
#define ת8 0xD18A
#define û8 0xD18B
#define ü8 0xD18C
#define ‎8 0xD18D
#define ‏8 0xD18E
#define ÿ8 0xD18F

#define À16 0x410
#define Á16 0x411
#define Â16 0x412
#define Ã16 0x413
#define Ä16 0x414
#define Å16 0x415
#define ¨16 0x401
#define Æ16 0x416
#define Ç16 0x417
#define È16 0x418
#define É16 0x419
#define Ê16 0x41A
#define Ë16 0x41B
#define Ì16 0x41C
#define Í16 0x41D
#define Î16 0x41E
#define Ï16 0x41F
#define Ð16 0x420
#define Ñ16 0x421
#define Ò16 0x422
#define Ó16 0x423
#define Ô16 0x424
#define Õ16 0x425
#define Ö16 0x426
#define ×16 0x427
#define Ø16 0x428
#define Ù16 0x429
#define Ú16 0x42A
#define Û16 0x42B
#define Ü16 0x42C
#define Ý16 0x42D
#define Þ16 0x42E
#define ‗16 0x42F

#define א16 0x430
#define ב16 0x431
#define ג16 0x432
#define ד16 0x433
#define ה16 0x434
#define ו16 0x435
#define ¸16 0x451
#define ז16 0x436
#define ח16 0x437
#define ט16 0x438
#define י16 0x439
#define ך16 0x43A
#define כ16 0x43B
#define ל16 0x43C
#define ם16 0x43D
#define מ16 0x43E
#define ן16 0x43F
#define נ16 0x440
#define ס16 0x441
#define ע16 0x442
#define ף16 0x443
#define פ16 0x444
#define ץ16 0x445
#define צ16 0x446
#define ק16 0x447
#define ר16 0x448
#define ש16 0x449
#define ת16 0x44A
#define û16 0x44B
#define ü16 0x44C
#define ‎16 0x44D
#define ‏16 0x44E
#define ÿ16 0x44F


#define LCaseEng { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}
#define KhameleonANSI { ÀÀ, ÂÀ, ÑÀ, 0, ÅÀ, 0, 0, ÍÀ, 0, 0, ÊÀ, 0, ÌÀ, 0, ÎÀ, ÐÀ, 0, 0, 0, ÒÀ, 0,0,0,0,0,0,0,0,0,0,0,0, אא, 0, סא, 0, וא, 0, 0, 0, 0, 0, ךא, 0, 0, 0, מא, נא }
#define KhameleonUTF8 { À8, Â8, Ñ8, 0, Å8, 0, 0, Í8, 0, 0, Ê8, 0, Ì8, 0, Î8, Ð8, 0, 0, 0, Ò8,  0,0,0,0,0,0,0,0,0,0,0,0, א8, 0, ס8, 0, ו8, 0, 0, 0, 0, 0, ך8, 0, 0, 0, מ8, נ8 }
#define KhameleonUTF16 { À16, Â16, Ñ16, 0, Å16, 0, 0, Í16, 0, 0, Ê16, 0, Ì16, 0, Î16, Ð16, 0,0,0, Ò16, א16, 0, ס16, 0, ו16, 0, 0, ם16, 0, 0, ך16, 0, ל16, 0, מ16, נ16 }
#define LCaseRus {¸א,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,אא,בא,גא,דא,הא,וא,זא,חא,טא,יא,ךא,כא,לא,םא,מא,ןא,נא,סא,עא,ףא,פא,ץא,צא,קא,רא,שא,תא,ûא,üא,‎א,‏א,ÿא, אא,בא,גא,דא,הא,וא,זא,חא,טא,יא,ךא,כא,לא,םא,מא,ןא,נא,סא,עא,ףא,פא,ץא,צא,קא,רא,שא,תא,ûא,üא,‎א,‏א,ÿא, }
#define LCaseRusUTF8  {¸8, 0,0,0,0,0,0,0,0, א8,ב8,ג8,ד8,ה8,ו8,ז8,ח8,ט8,י8,ך8,כ8,ל8,ם8,מ8,ן8,נ8,ס8,ע8,ף8,פ8,ץ8,צ8,ק8,ר8,ש8,ת8,û8,ü8,‎8,‏8,ÿ8, א8,ב8,ג8,ד8,ה8,ו8,ז8,ח8,ט8,י8,ך8,כ8,ל8,ם8,מ8,ן8,נ8,ס8,ע8,ף8,פ8,ץ8,צ8,ק8,ר8,ש8,ת8,û8,ü8,‎8,‏8,ÿ8, 0, ¸8}
#define LCaseRusUTF16 { ¸16, 0,0,0,0,0,0,0,0, א16,ב16,ג16,ד16,ה16,ו16,ז16,ח16,ט16,י16,ך16,כ16,ל16,ם16,מ16,ן16,נ16,ס16,ע16,ף16,פ16,ץ16,צ16,ק16,ר16,ש16,ת16,û16,ü16,‎16,‏16,ÿ16, א16,ב16,ג16,ד16,ה16,ו16,ז16,ח16,ט16,י16,ך16,כ16,ל16,ם16,מ16,ן16,נ16,ס16,ע16,ף16,פ16,ץ16,צ16,ק16,ר16,ש16,ת16,û16,ü16,‎16,‏16,ÿ16, 0, ¸16}
#define macros(a) {a##א,a##16,a##16,a##16,a##16,a##8,a##16,a##16}

#define א 0
#define ב 1
#define ג 2
#define ד 3
#define ה 4
#define ו 5
#define ¸ 6
#define ז 7
#define ח 8
#define ט 9
#define י 10
#define ך 11
#define כ 12
#define ל 13
#define ם 14
#define מ 15
#define ן 16
#define נ 17
#define ס 18
#define ע 19
#define ף 20
#define פ 21
#define ץ 22
#define צ 23
#define ק 24
#define ר 25
#define ש 26
#define ת 27
#define û 28
#define ü 29
#define ‎ 30
#define ‏ 31
#define ÿ 32

#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <uchar.h>

typedef unsigned char char8_t;

static const char32_t letters[33][8] = { macros(א), macros(ב), macros(ג), macros(ד), macros(ה), macros(ו), macros(¸), macros(ז), macros(ח), macros(ט), macros(י), macros(ך), macros(כ), macros(ל), macros(ם), macros(מ), macros(ן), macros(נ), macros(ס), macros(ע), macros(ף), macros(פ), macros(ץ), macros(צ), macros(ק), macros(ר), macros(ש),  macros(ת), macros(û), macros(ü), macros(‎), macros(‏), macros(ÿ) };
static const char32_t a[8] = macros(א);

typedef unsigned long long int char64_t;

typedef struct {
	char64_t arr[lengthSet];
} BitSet;

typedef enum {
    ANSI, UCS2LE, UCS2BE, UTF32LE, UTF32BE, UTF8, UTF16LE, UTF16BE
} TCode;

typedef BitSet CodeLangSet[8];

bool BitSet_In(const BitSet set, char32_t el);

void BitSet_RangePut(BitSet* set, const char8_t count, ...);

void BitSet_PutChar(BitSet* set, const char8_t count, ...);

bool Sym_Check(char32_t sym, const TCode code, const BitSet set);

void LowerCase(char32_t *sym, const TCode code);

void Convert(char32_t *sym, const TCode code);

void Yo(char32_t* sym, const TCode code);

extern const BitSet English;
extern const BitSet EnglishUpper;
extern const BitSet EnglishLower;
extern const BitSet Russian;
extern const BitSet RussianUpper;
extern const BitSet RussianLower;
extern const BitSet Lower;
extern const BitSet Upper;
extern const BitSet Letters;
extern const BitSet Wow;
extern const BitSet Prep;
extern const BitSet Utf8Russian;
extern const BitSet Utf8RussianLow;
extern const BitSet Utf8RussianHigh;
extern const BitSet Utf16Russian;
extern const BitSet Utf16RussianLow;
extern const BitSet Utf16RussianHigh;
extern const BitSet KhameleonUpper;
extern const BitSet KhameleonLower;
extern const CodeLangSet AllLetters;
extern const CodeLangSet HighLetters;
extern const CodeLangSet LowLetters;
extern const CodeLangSet GlasnyeLetters;
extern const CodeLangSet SoglasnyeLetters;
extern const BitSet khameleonHigh;
extern const BitSet glasnyeA;
extern const BitSet glasnyeUtf8;
extern const BitSet glasnyeUtf16;
extern const BitSet soglasnye;
extern const BitSet soglasnyeUtf8;
extern const BitSet soglasnyeUtf16;
extern const char8_t StopArr[220][10];


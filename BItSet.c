#pragma once
#include "BitSet.h"

const BitSet English = EnglishSet;
const BitSet EnglishUpper = EnglishUpperSet;
const BitSet EnglishLower = EnglishLowerSet;
const BitSet Russian = RussianSet;
const BitSet RussianUpper = RussianUpperSet;
const BitSet RussianLower = RussianLowerSet;
const BitSet Lower = LowerSet;
const BitSet Upper = UpperSet;
const BitSet Letters = LettersSet;
const BitSet Wow = WowSet;
const BitSet Prep = PrepSet;
const BitSet Utf8Russian = utf8RusSet;
const BitSet Utf8RussianLower = utf8RusLowSet;
const BitSet Utf8RussianUpper = utf8RusHighSet;
const BitSet Utf16Russian = utf16RusSet;
const BitSet Utf16RussianUpper = utf16RusHighSet;
const BitSet Utf16RussianLower = utf16RusLowSet;
const BitSet KhameleonUpper = KhameleonHigh;
const BitSet KhameleonLower = KhameleonLow;
const BitSet Khameleon = KhameleonSet;
const BitSet glasnyeA = Glasnye;
const BitSet glasnyeUtf8 = GlasnyeUTF8;
const BitSet glasnyeUtf16 = GlasnyeUTF16;
const BitSet soglasnye = Soglasnye;
const BitSet soglasnyeUtf8 = SoglasnyeUTF8;
const BitSet soglasnyeUtf16 = SoglasnyeUTF16;

const CodeLangSet AllLetters = { RussianSet, utf16RusSet, utf16RusSet,utf16RusSet,utf16RusSet,utf8RusSet, utf16RusSet, utf16RusSet};
const CodeLangSet HighLetters = { RussianUpperSet, utf16RusHighSet, utf16RusHighSet,utf16RusHighSet,utf16RusHighSet,utf8RusHighSet, utf16RusHighSet, utf16RusHighSet };
const CodeLangSet LowLetters = { RussianLowerSet, utf16RusLowSet, utf16RusLowSet,utf16RusLowSet,utf16RusLowSet,utf8RusLowSet, utf16RusLowSet, utf16RusLowSet};
const CodeLangSet GlasnyeLetters = { Glasnye, GlasnyeUTF16, GlasnyeUTF16, GlasnyeUTF16, GlasnyeUTF16, GlasnyeUTF8, GlasnyeUTF16, GlasnyeUTF16 };
const CodeLangSet SoglasnyeLetters = { Soglasnye, SoglasnyeUTF16, SoglasnyeUTF16, SoglasnyeUTF16, SoglasnyeUTF16, SoglasnyeUTF8, SoglasnyeUTF16, SoglasnyeUTF16 };


const char8_t StopArr[220][10] = {
  { טא},
{ גא},
{ גא,מא},
{ םא,וא},
{ קא,עא,מא},
{ מא,םא},
{ םא,אא},
{ ÿא},
{ סא},
{ סא,מא},
{ ךא,אא,ךא},
{ אא},
{ עא,מא},
{ גא,סא,וא},
{ מא,םא,אא},
{ עא,אא,ךא},
{ וא,דא,מא},
{ םא,מא},
{ הא,אא},
{ עא,ûא},
{ ךא},
{ ףא},
{ זא,וא},
{ גא,ûא},
{ חא,אא},
{ בא,ûא},
{ ןא,מא},
{ עא,מא,כא,üא,ךא,מא},
{ וא,וא},
{ לא,םא,וא},
{ בא,ûא,כא,מא},
{ גא,מא,עא},
{ מא,עא},
{ לא,וא,םא,ÿא},
{ וא,שא,וא},
{ םא,וא,עא},
{ מא},
{ טא,חא},
{ וא,לא,ףא},
{ עא,וא,ןא,וא,נא,üא},
{ ךא,מא,דא,הא,אא},
{ הא,אא,זא,וא},
{ םא,ףא},
{ גא,הא,נא,ףא,דא},
{ כא,טא},
{ וא,סא,כא,טא},
{ ףא,זא,וא},
{ טא,כא,טא},
{ םא,טא},
{ בא,ûא,עא,üא},
{ בא,ûא,כא},
{ םא,וא,דא,מא},
{ הא,מא},
{ גא,אא,סא},
{ םא,טא,בא,ףא,הא,üא},
{ מא,ןא,ÿא,עא,üא},
{ ףא,זא},
{ גא,אא,לא},
{ סא,ךא,אא,חא,אא,כא},
{ גא,וא,הא,üא},
{ עא,אא,לא},
{ ןא,מא,עא,מא,לא},
{ סא,וא,בא,ÿא},
{ םא,טא,קא,וא,דא,מא},
{ וא,יא},
{ לא,מא,זא,וא,עא},
{ מא,םא,טא},
{ עא,ףא,עא},
{ דא,הא,וא},
{ וא,סא,עא,üא},
{ םא,אא,הא,מא},
{ םא,וא,יא},
{ הא,כא,ÿא},
{ לא,ûא},
{ עא,וא,בא,ÿא},
{ טא,ץא},
{ קא,וא,לא},
{ בא,ûא,כא,אא},
{ סא,אא,לא},
{ קא,עא,מא,בא},
{ בא,וא,חא},
{ בא,ףא,הא,עא,מא},
{ קא,וא,כא,מא,גא,וא,ךא},
{ קא,וא,דא,מא},
{ נא,אא,חא},
{ עא,מא,זא,וא},
{ סא,וא,בא,וא},
{ ןא,מא,הא},
{ זא,טא,חא,םא,üא},
{ בא,ףא,הא,וא,עא},
{ זא},
{ עא,מא,דא,הא,אא},
{ ךא,עא,מא},
{ ‎א,עא,מא,עא},
{ דא,מא,גא,מא,נא,טא,כא},
{ עא,מא,דא,מא},
{ ןא,מא,עא,מא,לא,ףא},
{ ‎א,עא,מא,דא,מא},
{ ךא,אא,ךא,מא,יא},
{ סא,מא,גא,סא,וא,לא},
{ םא,טא,לא},
{ חא,הא,וא,סא,üא},
{ ‎א,עא,מא,לא},
{ מא,הא,טא,םא},
{ ןא,מא,קא,עא,טא},
{ לא,מא,יא},
{ עא,וא,לא},
{ קא,עא,מא,בא,ûא},
{ םא,וא,וא},
{ ךא,אא,זא,וא,עא,סא,ÿא},
{ סא,וא,יא,קא,אא,סא},
{ בא,ûא,כא,טא},
{ ךא,ףא,הא,אא},
{ חא,אא,קא,וא,לא},
{ סא,ךא,אא,חא,אא,עא,üא},
{ גא,סא,וא,ץא},
{ םא,טא,ךא,מא,דא,הא,אא},
{ סא,וא,דא,מא,הא,םא,ÿא},
{ לא,מא,זא,םא,מא},
{ ןא,נא,טא},
{ םא,אא,ךא,מא,םא,וא,צא},
{ הא,גא,אא},
{ מא,בא},
{ הא,נא,ףא,דא,מא,יא},
{ ץא,מא,עא,üא},
{ ןא,מא,סא,כא,וא},
{ םא,אא,הא},
{ בא,מא,כא,üא,רא,וא},
{ עא,מא,עא},
{ קא,וא,נא,וא,חא},
{ ‎א,עא,טא},
{ םא,אא,סא},
{ ןא,נא,מא},
{ גא,סא,וא,דא,מא},
{ םא,טא,ץא},
{ ךא,אא,ךא,אא,ÿא},
{ לא,םא,מא,דא,מא},
{ נא,אא,חא,גא,וא},
{ סא,ךא,אא,חא,אא,כא,אא},
{ עא,נא,טא},
{ ‎א,עא,ףא},
{ לא,מא,ÿא},
{ גא,ןא,נא,מא,קא,וא,לא},
{ ץא,מא,נא,מא,רא,מא},
{ סא,גא,מא,‏א},
{ ‎א,עא,מא,יא},
{ ןא,וא,נא,וא,הא},
{ טא,םא,מא,דא,הא,אא},
{ כא,ףא,קא,רא,וא},
{ קא,ףא,עא,üא},
{ עא,מא,לא},
{ םא,וא,כא,üא,חא,ÿא},
{ עא,אא,ךא,מא,יא},
{ טא,לא},
{ בא,מא,כא,וא,וא},
{ גא,סא,וא,דא,הא,אא},
{ ךא,מא,םא,וא,קא,םא,מא},
{ גא,סא,‏א},
{ לא,וא,זא,הא,ףא},
{ לא,םא,מא,יא},
{ לא,םא,מא,‏א},
{ עא,וא,בא,וא},
{ עא,מא,בא,מא,יא},
{ עא,מא,בא,מא,‏א},
{ םא,וא,לא,ףא},
{ וא,‏א},
{ םא,וא,‏א},
{ מא,םא,מא},
{ םא,אא,לא},
{ םא,אא,לא,טא},
{ גא,אא,לא,טא},
{ טא,לא,טא},
{ םא,טא,לא,טא},
{ סא,מא,בא,מא,יא},
{ סא,מא,בא,מא,‏א},
{ ‎א,עא,אא},
{ ‎א,עא,מא},
{ ‎א,עא,טא,ץא},
{ ‎א,עא,מא,לא,ףא},
{ ‎א,עא,טא,לא},
{ ‎א,עא,מא,‏א},
{ ‎א,עא,טא,לא,טא},
{ עא,אא},
{ עא,וא},
{ עא,ףא},
{ עא,מא,יא},
{ עא,וא,ץא},
{ עא,מא,לא,ףא},
{ עא,מא,‏א},
{ עא,וא,לא,טא},
{ גא,וא,סא,üא},
{ גא,סא,ÿא},
{ גא,סא,וא,יא},
{ גא,סא,וא,לא,ףא},
{ גא,סא,וא,לא},
{ גא,סא,וא,‏א},
{ גא,סא,וא,לא,טא},
{ סא,אא,לא,אא},
{ סא,אא,לא,מא},
{ סא,אא,לא,טא},
{ סא,אא,לא,מא,דא,מא},
{ סא,אא,לא,ףא},
{ סא,אא,לא,טא,ץא},
{ סא,אא,לא,מא,יא},
{ סא,אא,לא,מא,לא,ףא},
{ סא,אא,לא,טא,לא},
{ סא,אא,לא,מא,‏א},
{ סא,אא,לא,טא,לא,טא},
{ סא,אא,לא,מא,לא},
{ בא,ףא,הא},
{ בא,ûא,גא},
{ סא,ףא,עא,üא},
{ טא,לא,וא},
{ הא,וא,כא},
{ ףא,לא,וא},
{ ץא,מא,קא},
{ ץא,מא,עא},
{ הא,מא,כא,זא},
{ לא,מא,זא,םא},
{ םא,ףא,זא,םא}

};






static const char32_t KhameleonCheck[48] = { ÀÀ, ÂÀ, ÑÀ, 0, ÅÀ, 0, 0, ÍÀ, 0, 0, ÊÀ, 0, ÌÀ, 0, ÎÀ, ÐÀ, 0, 0, 0, ÒÀ, 0,0,0,0,0,0,0,0,0,0,0,0, אא, 0, סא, 0, וא, 0, 0, 0, 0, 0, ךא, 0, 0, 0, מא, נא }; //-65
static const char32_t KhameleonCheckUpperUTF8toRus[48] = { À8, Â8, Ñ8, 0, Å8, 0, 0, Í8, 0, 0, Ê8, 0, Ì8, 0, Î8, Ð8, 0, 0, 0, Ò8,  0,0,0,0,0,0,0,0,0,0,0,0, א8, 0, ס8, 0, ו8, 0, 0, 0, 0, 0, ך8, 0, 0, 0, מ8, נ8 }; //-65
static const char32_t KhameleonCheckUpperUTF16toRus[48] = { À16, Â16, Ñ16, 0, Å16, 0, 0, Í16, 0, 0, Ê16, 0, Ì16, 0, Î16, Ð16, 0,0,0, Ò16, א16, 0, ס16, 0, ו16, 0, 0, ם16, 0, 0, ך16, 0, ל16, 0, מ16, נ16 }; //-65
static const char32_t KhameleonArr[8][48] = { KhameleonANSI, KhameleonUTF16, KhameleonUTF16, KhameleonUTF16, KhameleonUTF16, KhameleonUTF8, KhameleonUTF16, KhameleonUTF16 };
//static const char16_t KhameleonCheckUppertoEng[20] = { 'A', 'B', 'C', 0, 'E', 0, 0, 'H', 0, 0, 'K', 0, 'M', 0, 'O', 'P', 0, 0, 0, 'T' }; // -A
//static const char16_t KhameleonCheckLowertoEng[16] = { 'a', 0, 'c', 0, 'e', 0, 0, 0, 0, 0, 'k', 0, 'm', 0, 'o', 'p' };   // -a 
static const char32_t yo[8] = { ¸א,¸16, ¸16, ¸16, ¸16, ¸8, ¸16, ¸16 };
static const char32_t e[8] = { וא,ו16, ו16, ו16, ו16, ו8, ו16, ו16 };

typedef char32_t TLCaseArr[88];

static const TLCaseArr LowerCaseRus = LCaseRus;
static const TLCaseArr LowerCaseEng = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
static const TLCaseArr LowerCaseRusUTF8 = LCaseRusUTF8; // - ¨8
static const TLCaseArr LowerCaseRusUTF16 = LCaseRusUTF16;
static const char8_t pivot[8] = { ¨À,¨16, ¨16, ¨16, ¨16, ¨8, ¨16, ¨16};
static const char32_t LowerCaseArr[8][88] = { LCaseRus, LCaseRusUTF16, LCaseRusUTF16, LCaseRusUTF16,  LCaseRusUTF16, LCaseRusUTF8, LCaseRusUTF16,  LCaseRusUTF16};

static inline bool SegANSI(char32_t sym, const BitSet set);
static inline bool SegUTF8(char32_t sym, const BitSet set);
static inline bool SegUTF16(char32_t sym, const BitSet set);

typedef bool(*SegCheck)(char32_t sym, const BitSet set);

static const SegCheck  segCheck[8] = { SegANSI, SegUTF16, SegUTF16, SegUTF16, SegUTF16, SegUTF8, SegUTF16, SegUTF16 };


inline static bool SegANSI(char32_t sym, const BitSet set) {
    if (sym > ÿא)
        return false;
    return (BitSet_In(set,sym));
}

static bool SegUTF8(char32_t sym, const BitSet set) {
    if (sym > ¸8 || sym < À8)
        return false;
    sym &= (0XFFF);
    return (BitSet_In(set, sym));
}

static bool SegUTF16(char32_t sym, const BitSet set) {
    if (sym > ¸16 || sym < À16)
        return false;
    sym &= (0xFF);
    return (BitSet_In(set, sym));
}

bool Sym_Check(char32_t sym, const TCode code, const BitSet set) {
    return segCheck[code](sym, set);
}


bool BitSet_In(const BitSet set, char32_t el) {
    char32_t buff;
    el &= (0xFFFUl);
    buff = el >> 6;
    char64_t mask = (0x8000000000000000ull >> (el & 0b00000000000000000000000000111111));
    return  set.arr[buff] & mask;
}


void LowerCase(char32_t *sym, const TCode code) {
        *sym -= pivot[code];
        *sym = LowerCaseArr[code][*sym];
}

void Convert(char32_t * sym, const TCode code) {
        if (BitSet_In(Khameleon, *sym))
            *sym = KhameleonArr[code][*sym];
}

void Yo(char32_t *sym, const TCode code) {
    if (*sym == yo[code]) {
        *sym = e[code];
    }
}

BitSet BitSet_Put(const char8_t count, ...) {
    char8_t el;
    va_list(args);
    va_start(args, count);
    BitSet res;
    res.arr[0] = res.arr[1] = res.arr[2] = res.arr[3] = 0;
    memcpy(res.arr, va_arg(args, BitSet*), sizeof(char64_t) * lengthSet);
    for (char8_t i = 0; i < count; i++) {
        el = va_arg(args, char8_t);
        res.arr[el >> 6] ^= 0x8000000000000000ull >> (el & 0b00000000000000000000000000111111);
    }
    va_end(args);
    return res;
}

void BitSet_PutChar(BitSet* set, const char8_t count, ...) {
    unsigned int el;
    va_list(list);
    va_start(list, count);
    for (char8_t i = 0; i < count; i++) {
        el = va_arg(list, unsigned int
        );
        el &= (0xFFFull);
        set->arr[el >> 6] |= 0x8000000000000000ull >> (el & 0b00000000000000000000000000111111);
    }
    va_end(list);
}

void BitSet_RangePut(BitSet* set, const char8_t count, ...) {
    unsigned int start, end;
    va_list(list);
    va_start(list, count);
    for (char8_t j = 0; j < count; j++) {
        start = va_arg(list, char16_t);
        start &= (0xFFFu);
        end = va_arg(list, char16_t);
        end &= (0xFFFu);
        for (unsigned int i = start; i <= end; i++) {
            set->arr[i >> 6] ^= 0x8000000000000000ull >> (i & 0b00000000000000000000000000111111);
        }
    }
    va_end(list);
}

#pragma once
#include "AnsiString.h"

static const char8_t sizeArr[8] = { 1,2,2,4,4,4,4,4 };

typedef char32_t(*TGetter)(const String str, const size_t index);

typedef bool(*TEqual)(const String str, const String check);

typedef char8_t*(*PGetEnd)(char8_t* const end, char8_t* start, size_t dec);

typedef char32_t (*TGetP)(char8_t* end);

typedef char8_t (*TCheck)(char8_t* sym);



static char8_t* PGet_ANSIEnd(char8_t* end, char8_t* start, size_t dec);

static inline char8_t* PGet_UCS2End(char8_t* end, char8_t* start, size_t dec);

static inline char8_t* PGet_UTF32End(char8_t* end, char8_t* start, size_t dec);

static char8_t* PGet_UTF8End(char8_t* end, char8_t* start, size_t dec);

static char8_t* PGet_UTF16LEEnd(char8_t* end, char8_t* start, size_t dec);

static char8_t* PGet_UTF16BEEnd(char8_t* end, char8_t* start, size_t dec);






static inline char32_t Get_ANSIP(char8_t* end);

static inline char32_t Get_UCS2LEP(char8_t* end);

static inline char32_t Get_UCS2BEP(char8_t* end);

static inline char32_t Get_UTF32LEP(char8_t* end);

static inline char32_t Get_UTF32BEP(char8_t* end);

static char32_t Get_UTF8P(char8_t* end);

static char32_t Get_UTF16LEP(char8_t* end);

static char32_t Get_UTF16BEP(char8_t* end);







static inline char32_t Get_ANSI(const String str, const size_t index);

static inline char32_t Get_UCS2LE(const String str, const size_t index);

static inline char32_t Get_UCS2BE(const String str, const size_t index);

static inline char32_t Get_UTF32LE(const String str, const size_t index);

static inline char32_t Get_UTF32BE(const String str, const size_t index);

static char32_t Get_UTF8(const String str, const size_t index);

static char32_t Get_UTF16BE(const String str, const size_t index);

static char32_t Get_UTF16LE(const String str, const size_t index);




static inline char8_t SizeANSI(char8_t* sym);

static inline char8_t SizeUCS2(char8_t* sym);

static inline char8_t SizeUTF32(char8_t* sym);

static char8_t SizeUTF8(char8_t* sym);

static char8_t SizeUTF16LE(char8_t* sym);

static char8_t SizeUTF16BE(char8_t* sym);



static inline bool Equal_Byte(const String str, const String check);

static bool Equal_2Bytes(const String str, const String check);

static bool Equal_4Bytes(const String str, const String check);


static const TGetter getArr[8] = { Get_ANSI, Get_UCS2LE,Get_UCS2BE, Get_UTF32LE, Get_UTF32BE, Get_UTF8,Get_UTF16LE, Get_UTF16BE };

static const PGetEnd pGetEnd[8] = { PGet_ANSIEnd, PGet_UCS2End, PGet_UCS2End, PGet_UTF32End, PGet_UTF32End, PGet_UTF8End, PGet_UTF16LEEnd, PGet_UTF16BEEnd};

static const TGetP getP[8] = { Get_ANSIP, Get_UCS2LEP,Get_UCS2BEP, Get_UTF32LEP, Get_UTF32BEP, Get_UTF8P, Get_UTF16LEP, Get_UTF16BEP };

static const TEqual eqArr[8] = { Equal_Byte, Equal_2Bytes, Equal_2Bytes, Equal_4Bytes, Equal_4Bytes, Equal_Byte, Equal_2Bytes, Equal_2Bytes};

static const TCheck checkArr[8] = { SizeANSI, SizeUCS2, SizeUCS2, SizeUTF32, SizeUTF32, SizeUTF8, SizeUTF16LE, SizeUTF16BE };


String Str_Create(size_t length, const TCode code) {
    String str;
    str.length = 0;
    length = length * sizeArr[code];
    str.arr = (char8_t*)malloc(length + 1);
    if (str.arr == NULL) {
        exit;
    }
    str.capEnd = str.arr + length;
    str.arr[0] = '\0';
    str.end = str.arr;
    return str;
}

String Str_Copy(const String str, const TCode code) {
    String res;
    res = Str_Create(str.length + 2, code);
    strcpy(res.arr, str.arr);
    res.end = res.arr + (str.end - str.arr);
    res.length = str.length;
    return res;
}

String Str_CreateByte(size_t size, const TCode code) {
    String str;
    str.length = 0;
    str.arr = (char8_t*)malloc(size + 1);
    if (str.arr == NULL) {
        exit;
    }
    str.capEnd = str.arr + size;
    str.arr[0] = '\0';
    str.end = str.capEnd;
    return str;
}

void Str_Free(String* str) {
    free(str->arr);
}

void Str_NewCapacityCall(String* str, const size_t capacity, const TCode code) {
    char8_t* buff;
    size_t size = str->end - str->arr;
    buff = (char8_t*)realloc(str->arr, capacity * sizeArr[code] + 1);
    if (buff == NULL) {
        exit;
    }
    else {
        str->arr = buff;
        str->capEnd = str->arr + capacity * sizeArr[code];
        str->end = str->arr + size;
    }
}

void Str_Push(String* str, char8_t* orig, const TCode code) {
    size_t index = str->end - str->arr;
    char8_t buff = checkArr[code](orig);
    if (str->capEnd - buff < str->end) {
        Str_NewCapacityCall(str, (str->length << 1) + 1, code);
    }
    memcpy(str->arr + index,orig, buff);
    str->length++;
    str->end += buff;
    orig += buff;
    *(str->end) = '\0';
}

inline char8_t* PStr_GetEnd(char8_t* str,char8_t* start, size_t dec, const TCode code) {
    return pGetEnd[code](str,start, dec);
}


void Str_Pop(String* str, size_t num, const TCode code) {
    if (num > str->length)
        num = str->length;
    str->end = PStr_GetEnd(str->end,str->arr, num, code);
    str->length -= num;
    *(str->end) = '\0';
}



static inline char16_t Swap16Bit(const char16_t sym) {
    return (sym >> 8) | (sym << 8);
}

static inline char32_t Swap32Bit(const char32_t sym) {
    return (sym >> 24) | 
        ((sym >> 8) & 0x0000FF00) |  
        ((sym << 8) & 0x00FF0000) |  
        (sym << 24);

}

//static char32_t SwapUTF16(const char32_t sym) {
//    return ((sym << 8) & (0xFF00FF00)) | ((sym >> 8) & (0X00FF00FF));
//}






static char8_t SizeUTF8(char8_t* sym) {
    if (!(*sym & 0b10000000)) {
        return 1;
       }
    if ((*sym & 0b11000000) == 0b11000000) {
        return 2;
    }
    if ((*sym & 0b11100000) == 0b11100000) {
        return 3;
    }
    if ((*sym & 0b11110000) == 0b111110000) {
        return 4;
    }
    return 0;
}

static inline char8_t SizeUTF16LE(char8_t* sym) {
    return 2 << (*(char16_t*)sym >= 0xD800 && *(char16_t*)sym <= 0xDBFF);
}

static inline char8_t SizeUTF16BE(char8_t* sym) {
    char16_t buff = Swap32Bit(*sym);
    return SizeUTF16LE(&buff);
}





static inline char8_t CheckUTF16LEEnd(const char16_t sym) {
    return (sym >= 0xDC00 && sym <= 0XDFFF) << 1;
}
static inline char8_t CheckUTF16BEEnd(const char16_t sym) {
    return CheckUTF16LEEnd(Swap16Bit(sym));
}








static inline char32_t Get_ANSI(const String str, const size_t index) {
    return str.arr[index];
};

static inline char8_t* PGet_ANSIEnd(char8_t* end, char8_t* start, size_t dec) {
    return end - dec;
}

static inline char32_t Get_ANSIP(char8_t* end) {
    return *end;
}

static inline char8_t SizeANSI(char8_t* sym) {
    return 1;
}







static inline char32_t Get_UCS2LE(const String str, const size_t index) {
    return *(char16_t*)(str.arr + (index << 1));
}

static inline char8_t* PGet_UCS2End(char8_t* end, char8_t* start, size_t dec) {
    return end - (dec << 1);
}

static inline char32_t Get_UCS2LEP(char8_t* end) {
    return *(char16_t*)end;
}

static inline char8_t SizeUCS2(char8_t* sym) {
    return 2;
}

static inline char32_t Get_UCS2BEP(char8_t* end) {
        return Swap16Bit(*(char16_t*)end);
}

static inline char32_t Get_UCS2BE(const String str, const size_t index) {
    return Swap16Bit(*(char16_t*)(str.arr + (index << 1)));
}



static inline char8_t* PGet_UTF32End(char8_t* end, char8_t* start, size_t dec) {
    return end - (dec << 2);
}

static inline char32_t Get_UTF32LEP(char8_t* end) {
        return *(char32_t*)end;
}

static inline char32_t Get_UTF32BEP(char8_t* end) {
        return Swap32Bit(*(char32_t*)end);
}

static inline char8_t SizeUTF32(char8_t* sym) {
    return 4;
}

static inline char32_t Get_UTF32LE(const String str, const size_t index) {
    return *(char32_t*)(str.arr + (index << 2));
}

static inline char32_t Get_UTF32BE(const String str, const size_t index) {
    return Swap32Bit(*(char32_t*)(str.arr + (index << 2)));
}






static char32_t Get_UTF8P(char8_t* str) {
    const size_t buff = SizeUTF8(str);
    char32_t res = 0;
    for (size_t i = 0; i < buff; i++) {
        res |= (char32_t)(str[i]);
        __asm {
            ror[res], 8
        }
    }
    return res;
}

static char32_t Get_UTF8(const String str, const size_t index) {
    size_t i = 0, j = 0;
    char32_t res = 0;
    while (i < index) {
        j += SizeUTF8(str.arr + j);
        i++;
    }
    return Get_UTF8P(str.arr + j);
}

static char8_t* PGet_UTF8End(char8_t* end, char8_t* start, size_t dec) {
    char8_t* pstr = end;
    while (dec > 0 && pstr >= start) {
        do {
            pstr--;
        } while ( pstr >= start && !SizeUTF8(pstr));
        dec--;
    }
    return pstr;
}






static char32_t Get_UTF16LEP(char8_t* str) {
         char8_t step = SizeUTF16LE(str);
         if (step == 2) {
             return *(char16_t*)(str);
         }
         else {
             return *(char32_t*)(str);
         }
}

static char32_t Get_UTF16BEP(char8_t* str) {
    char8_t step = SizeUTF16BE(str);
    if (step == 2) {
        return Swap16Bit(*(char16_t*)str);
    }
    else {
        return Swap32Bit(*(char32_t*)(str));
    }
}

static char32_t Get_UTF16LE(const String str, const size_t index) {
    size_t step = 0, i = 0, j = 0;
    char16_t res = 0;
    while (i < index) {
        j += SizeUTF16LE(str.arr + j);
        i++;
    }
    return Get_UTF16LEP(str.arr + j);
}

static char8_t* PGet_UTF16LEEnd(char8_t* end, char8_t* start, size_t dec) {
    char8_t* pstr = end;
    //while (dec > 0 && pstr >= start) {
    //    pstr -= 2;
    //    pstr -= CheckUTF16LEEnd(*(char16_t*)pstr);
    //    dec--;
    //}
    do {
        pstr -= 2;
    } while (pstr >= start, pstr -= CheckUTF16LEEnd(*(char16_t*)pstr), dec--, dec > 0);
    return pstr;
}


static char32_t Get_UTF16BE(const String str, const size_t index) {
    size_t step = 0, i = 0, j = 0;
    char16_t res = 0;
    while (i < index) {
        j += SizeUTF16BE(str.arr + j);
        i++;
    }
    return Get_UTF16BEP(str.arr + j);
}

static char8_t* PGet_UTF16BEEnd(char8_t* end, char8_t* start, size_t dec) {
    char8_t* pstr = end;
    //while (dec > 0) {
    //    pstr -= 2;
    //    pstr -= CheckUTF16BEEnd(*(char16_t*)pstr);
    //    dec--;
    //}
    do {
        pstr -= 2;
    } while (pstr >= start, pstr -= CheckUTF16BEEnd(*(char16_t*)pstr), dec--, dec > 0);

    return pstr;
}



static inline bool Equal_Byte(const String str, const String check) {
     return (!strcmp(str.arr, check.arr));
}

static bool Equal_2Bytes(const String str, const String check) {
    size_t i = 0;
    while (i < str.length && (*(char16_t*)str.arr[i]) == (*(char16_t*)check.arr[i]))
        i += 2;
    return i == str.length;
}

static bool Equal_4Bytes(const String str, const String check) {
    size_t i = 0;
    while (i < str.length && (*(char32_t*)str.arr[i]) == (*(char32_t*)check.arr[i]))
        i += 4;
    return i == str.length;
}



bool Str_Equal(const String str, const String check, const TCode code) {
    if (str.length == check.length)
        return eqArr[code](str, check);
        return false;
}

char32_t Str_Get(const String str, const size_t index, const TCode code) {
    return getArr[code](str, index);
}


char32_t Str_GetEnd(char8_t** str,char8_t* start, size_t dec, const TCode code) { // использовать буферную переменную
    char8_t* buff = *str;
    buff = PStr_GetEnd(buff,start, dec, code);
    if (buff < start)
        return 0;
    *str = buff;
    return getP[code](buff);
}

char32_t Str_GetP(char8_t** str, const TCode code) { // использовать буферную переменную
    char8_t* buff = *str;
    char32_t res = getP[code](buff);
    buff += checkArr[code](str);
    *str = buff;
    return res;
}

char32_t Str_GetNP(char8_t* str, const TCode code) { // использовать буферную переменную
    char32_t res = getP[code](str);
    //str += checkArr[code](str);
    return res;
}


char8_t GetSize(char8_t* str, const TCode code) {
    return checkArr[code](str);
}

void AStr_Fill(const String str, const char8_t value) {
    char8_t* buff = str.arr;
    for (; buff < str.capEnd; buff++) {
        *buff = '\0';
    }
}


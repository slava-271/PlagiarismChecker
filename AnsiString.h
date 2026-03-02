#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <uchar.h>
#include "BitSet.h"

static int nu = 10;

typedef struct {
    char8_t* arr;
    size_t  length;
    char8_t* end, *capEnd;
} String;



String Str_Create(size_t length, const TCode  code);

String Str_CreateByte(size_t size, const TCode code);

String Str_Copy(const String str, const TCode code);

void Str_Free(String* str);

void Str_Push(String* str, char8_t* orig, const TCode code);

void Str_Pop(String* str, size_t num, const TCode code);

char32_t Str_Get(const String str, const size_t index, const TCode code);

char8_t* PStr_GetEnd(char8_t* str, char8_t* start, size_t dec, const TCode code);

char32_t Str_GetEnd(char8_t** str,char8_t* start, size_t dec, const TCode code);

bool Str_Equal(const String str, const String check, const TCode code);

char32_t Str_GetP(char8_t** str, const TCode code);

char8_t GetSize(char8_t * str, const TCode code);

char32_t Str_GetNP(char8_t* str, const TCode code);

void AStr_Fill(const String str, const char8_t value);

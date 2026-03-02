#pragma once
#include "AnsiString.h"

typedef struct Witem {
	String word;
	struct Witem* next;
} WordList_Item;

typedef struct {
	WordList_Item* head, * end;
	WordList_Item* curr;
}WordList;

WordList WordsList_Create(void);

void WordsList_Free(WordList* list);

void WordsList_Push(WordList* list, const String str, const TCode code);

bool WordsList_Find(WordList* list, const String str, const char8_t hash, String *check, const TCode code);

bool FindW(WordList* list, const String str, const TCode code);


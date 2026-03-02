#pragma once
#include "ListWords.h"

typedef struct {
	WordList* listWords;
	size_t capacity, length;
}HashTable;

HashTable Hash_Create(const size_t length);

void Hash_Free(HashTable* arr);

void Hash_Put(HashTable* words, const String str, const TCode code);

bool Hash_Contains(const HashTable words, const String str, String* check, const TCode code);

bool Contains(const HashTable words, const String str, const TCode code);

HashTable HashFill(void);



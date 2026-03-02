#pragma once
#include "HashTable.h"
#define HashLength 100

typedef struct item {
	HashTable sent;
	struct item* next, * prev;
	char8_t* start, *end;
} SentList_Item;

typedef struct {
	SentList_Item* head, *end;
	SentList_Item* curr;
	float length;
}SentList;

SentList SentList_Create(void);

void SentList_Free(SentList* list);

void SentList_Push(SentList* list);


#pragma once
#include "AnsiString.h"
#include "ListOfSentences.h"
typedef struct {
	char8_t* start, *end;
 }Range;

typedef struct Stolen {
	struct Stolen* next, * prev;
	Range orig, plagiat;
}StolenItem;

typedef struct {
	StolenItem* head, * end;
	StolenItem* curr;
	float Percentage;
}StolenList;

StolenList StolenList_Create(void);

void StolenList_Free(StolenList* list);

void StolenList_Push(StolenList* list, char8_t* startOrig, char8_t* endOrig, char8_t* startPlagiat, char8_t* endPlagiat);

float CompareSentences(HashTable* orig, HashTable* plagiat,const TCode code);

StolenList FindPlagiat(SentList* orig, SentList* plagiat, const TCode code);

extern HashTable StopWords;
#include "Plagiat.h"



StolenList StolenList_Create(void) {
	StolenList list;
	list.curr = (StolenItem*)malloc(sizeof(StolenItem));
	list.head = list.end = list.curr;
	list.curr->prev = list.curr->next = NULL;
	return list;
}

void StolenList_Free(StolenList* list) {
	StolenItem* buff;
	list->curr = list->head;
	while (list->curr != NULL) {
		buff = list->curr;
		list->curr->next;
		free(buff);
	}
}

void StolenList_Push(StolenList* list, char8_t* startOrig, char8_t* endOrig, char8_t* startPlagiat, char8_t* endPlagiat) {
	list->end->next = (StolenList*)malloc(sizeof(StolenItem));
	list->end = list->end->next;
	list->end->orig.start = startOrig;
	list->end->orig.end = endOrig;
	list->end->plagiat.start = startPlagiat;
	list->end->plagiat.end = endPlagiat;
	list->end->next = NULL;
}

StolenList FindPlagiat(SentList* orig, SentList* plagiat, const TCode code) {
	float count = 0, stealCount = 0, length = 0;
	bool stealFlag = true;
	orig->curr = orig->head;
	StolenList stolen = StolenList_Create();
	while (orig->curr->next != NULL) {
		orig->curr = orig->curr->next;
		plagiat->curr = plagiat->head;
		stealFlag = true;
		while (plagiat->curr->next != NULL) {
			plagiat->curr = plagiat->curr->next;
			count = CompareSentences(&orig->curr->sent, &plagiat->curr->sent, code);
			if (count > 0.45) {
				StolenList_Push(&stolen, orig->curr->start, orig->curr->end, plagiat->curr->start, plagiat->curr->end);
				stealCount += stealFlag;
				stealFlag = false;
			}
		}
	}
	stolen.Percentage = (stealCount) / (orig->length);
	return stolen;
}

float CompareSentences(HashTable* orig, HashTable* plagiat,const TCode code) {
	size_t i = 0;
	HashTable bigger, lower;
	String str = Str_Create(100,code);
	float j = 0;
	AStr_Fill(str,0);
	if (orig->length <= plagiat->length) {
		lower = *orig;
		bigger = *plagiat;
	}
	else {
		lower = *plagiat;
		bigger = *orig;
	}
	if (lower.length < 3 || bigger.length < 3 || (lower.length < (bigger.length >> 1)))
		return 0;
	for (; i < HashLength; i++) {
		lower.listWords[i].curr = lower.listWords[i].head;
		while (lower.listWords[i].curr->next != NULL) {
			lower.listWords[i].curr = lower.listWords[i].curr->next;
			if (Hash_Contains(bigger, lower.listWords[i].curr->word, &str, code)) {
				j++;
			}
		}
	}
	Str_Free(&str);
	return (j / lower.length);
}


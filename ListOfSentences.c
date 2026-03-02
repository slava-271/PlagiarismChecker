#include "ListOfSentences.h"

SentList SentList_Create(void) {
		SentList list;
		list.curr = (SentList_Item*)malloc(sizeof(SentList_Item));
		list.curr->prev = list.curr->next = NULL;
		list.head = list.end = list.curr;
		list.length = 0;
		return list;
}

void SentList_Free(SentList* list) {
	SentList_Item* buff;
	list->curr = list->head;
	while (list->curr != NULL) {
		Hash_Free(&list->curr->sent);
		buff = list->curr;
		list->curr->next;
		free(buff);
	}
}

void SentList_Push(SentList* list) {
	list->end->next = (SentList_Item*)malloc(sizeof(SentList_Item));
	list->end = list->end->next;
	list->end->sent = Hash_Create(HashLength);
	list->end->next = NULL;
	list->length++;
}




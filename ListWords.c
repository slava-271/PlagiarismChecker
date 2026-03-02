#include "ListWords.h"

WordList WordsList_Create(void) {
	WordList list;
	list.curr = (WordList_Item*)malloc(sizeof(WordList_Item));
	list.curr->next = NULL;
	list.head = list.end = list.curr;
	return list;
}

void WordsList_Free(WordList* list) {
	WordList_Item* buff;
	list->curr = list->head;
	while (list->curr != NULL) {
		Str_Free(&list->curr->word);
		buff = list->curr;
		list->curr = list->curr->next;
		free(buff);
	}
}

void WordsList_Push(WordList* list, const String str, const TCode code) {
	bool flag = true;
	list->curr = list->head;
	while (list->curr->next != NULL && true) {
		list->curr = list->curr->next;
		if (!strcmp(list->curr->word.arr, str.arr)) {
			flag = false;
		}
	}
	if (flag) {
		list->end->next = (WordList_Item*)malloc(sizeof(WordList_Item));
		list->end = list->end->next;
		list->end->word = Str_Copy(str, code);
		list->end->next = NULL;
	}
}

bool WordsList_Find(WordList* list, const String str, const char8_t hash, String* check, const TCode code) {
	list->curr = list->head;
	char8_t i = 0;
	while (list->curr->next != NULL) {
		list->curr = list->curr->next;
		if (Str_Equal(list->curr->word, str, code)) {
			i++;
			if (check->arr[hash] < i) {
				check->arr[hash]++;
				return true;
			}
		}
	}
	return false;
}

bool FindW(WordList* list, const String str, const TCode code) {
	list->curr = list->head;
	while (list->curr->next != NULL) {
		list->curr = list->curr->next;
		if (Str_Equal(list->curr->word, str, code)) {
			return true;
		}
	}
	return false;
}
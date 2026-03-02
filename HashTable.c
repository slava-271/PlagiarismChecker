#include "HashTable.h"

HashTable Hash_Create(const size_t length) {
    HashTable array;
    array.capacity = length;
    array.length = 0;
    array.listWords = (WordList*)malloc(array.capacity * sizeof(WordList));
    if (array.listWords == NULL) {
        exit;
    }
    for (size_t i = 0; i < array.capacity; i++) {
        array.listWords[i] = WordsList_Create();
    }
    return array;
}

void Hash_Free(HashTable* arr) {
    for (size_t i = 0; i < arr->capacity; i++) {
        WordsList_Free(&arr->listWords[i]);
     }
    free(arr);
}

char8_t Hash_Function(const String str, const char8_t amount, const TCode code) {
    size_t hash = 5381;
    char8_t* buff = str.arr;
    for (size_t i = 0; i < str.length; i++) {
        hash = ((hash << 5) + hash) + Str_GetP(&buff, code);
    }
    return (hash % amount);
}

void Hash_Put(HashTable* words, const String str, const TCode code) {
    char8_t hash = Hash_Function(str, words->capacity, code);
    WordsList_Push(&words->listWords[hash], str, code);
    words->length++;
}

bool Hash_Contains(const HashTable words, const String str, String* check, const TCode code) {
    char8_t i = Hash_Function(str, words.capacity, code);
    return WordsList_Find(words.listWords + i, str, i, check, code); 
}

bool Contains(const HashTable words, const String str, const TCode code) {
    char8_t i = Hash_Function(str, words.capacity, code);
    return FindW(words.listWords + i, str, code);
}

HashTable HashFill(void) { // поменять когда изменю кодировку
    HashTable table;
    String str;
    table = Hash_Create(1000);
    str = Str_Create(10,ANSI);
    for (size_t i = 0; i < 220; i++) {
        strcpy(str.arr, StopArr[i]);
        str.length = strlen(StopArr[i]);
        str.end = str.arr + str.length;
        Hash_Put(&table,str,ANSI);
    }
    Str_Free(&str);
    return table;
}
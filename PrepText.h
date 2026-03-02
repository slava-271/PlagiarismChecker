#pragma once
#include "ListOfSentences.h"
#include "HashTable.h"
#include "stdio.h"

String ReadFromFile(const char* filePath, const TCode code);

void Run(char8_t* end, char8_t* str, const TCode code, SentList* list, const HashTable stop);






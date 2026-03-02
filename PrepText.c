#include "PrepText.h"
#include "Stemming.h"

typedef enum {
	big, low, point,def, ap, wow,space, quoteOp, quoteCl,other 
}Tokens;

typedef char8_t TStates[8][10];

const TStates enter = { {0}, {2,2,1,1,1,1,1,2,1,1} };
const TStates word = { {0}, {2,2,6,6,6,6,6,6,6,6}, {3,3,4,5,5,6,6,6,6,6}, {3,3,6,5,6,6,6,6,6,6}, {2,2,6,6,6,6,6,6,6,6},{3,3,6,6,6,6,6,6,6,6} };
const TStates find = { {0}, {4,4,2,1,1,3,1,1,1,1}, {5,4,2,2,2,3,2,5,2,2}, {5,4,3,3,3,3,3,5,3,3} };
const TStates quoteFind = { {0}, {4,4,2,1,1,3,1,1,5,1}, {4,4,2,1,1,3,2,2,5,2}, {4,4,3,3,3,3,3,3,5,3} };
const TStates quoteWord = { {0}, {2,2,6,6,6,6,6,6,7,6}, {3,3,4,5,5,6,6,6,7,6}, {3,3,6,5,6,6,6,6,7,6}, {3,3,6,6,6,6,6,6,7,6},{3,3,6,6,6,6,6,6,7,6} };
const char32_t quoteOpen[8] = { 0x22, 0xAB, 0XAB, 0XAB, 0XAB, 0xE2809C, 0XAB, 0XAB };
static const char32_t quoteClose[8] = { 0x22, 0xBB, 0XBB, 0XBB, 0XBB, 0xE2809D, 0XBB, 0XBB };


String ReadFromFile(const char* filePath, const TCode code) {
	FILE* file = fopen(filePath, "r");
	fseek(file, 0, SEEK_END);
	size_t length = ftell(file);
	rewind(file);
	String res = Str_CreateByte(length+1,code);
	fread(res.arr,sizeof(char8_t),length,file);
	//fgets(res.arr, length+1, file);
	fclose(file);
	return res;
}

Tokens CheckQuote(char8_t* sym, const TCode code) {
	if (BitSet_In(AllLetters[code], *sym)) {
		LowerCase(sym, code);
		Yo(sym,code);
		return low;
	}
	if (quoteClose[code] == *sym) {
		return quoteCl;
	}
	switch (*sym) {
	case '.': return point;
	case '-': return def;
	case '\'':  return ap;
	default:return space;
	}
}

Tokens CheckQuoteSent(char8_t* sym, const TCode code) {
	if (BitSet_In(AllLetters[code], *sym)) {
		LowerCase(sym, code);
		Yo(sym,code);
		return low;
	}
	if (quoteClose[code] == *sym) {
		return quoteCl;
	}
	switch (*sym) {
	case '.': return point;
	case '-': return def;
	case '\'':  return ap;
	default:return space;
	}
}

char8_t Stack(const char8_t* const end, char8_t* str, const TCode code, SentList* list) {
	char8_t state;
	char32_t sym;
	Tokens token;
	String buff = Str_Create(20,code);
	while (str != end) {
		state = 1;
		do {
			sym = Str_GetNP(str, code);
			token = CheckQuoteSent(&sym, code);
			state = quoteFind[state][token];
		} while ((state < 4), str += GetSize(str, code), str != end);
		if (state == 5 || str == end)			
			return;
		state = 1;
		do {
			sym = Str_GetNP(str, code);
			token = CheckQuote(&sym, code);
			state = quoteWord[state][token];
		} while ((state < 7), str += GetSize(str, code), Str_Push(&buff, str, code), str != end);
		Stemming(&buff, code);
		Hash_Put(&list->curr->sent, buff,code);
		buff.length = 0;
		buff.end = buff.arr;
	}
	return 1;
}



Tokens CheckEnter(char8_t* sym, const TCode code) {
	if (BitSet_In(AllLetters[code], *sym)) {
		LowerCase(sym,code);
		Yo(sym,code);
		return big;
	}
	return space;
}

Tokens CheckWord(char8_t* sym, const TCode code) {
	if (BitSet_In(AllLetters[code], *sym)) {
	    LowerCase(sym, code);
		Yo(sym, code);
		return low;
	}
	if (quoteOpen[code] == *sym) {
		return quoteOp;
	}
	switch (*sym) {
	case '.': return point;
	case '-': return def;
	case '\'':  return ap;
	default:return space;
	}
}

Tokens CheckSent(char8_t *sym, const TCode code) {
	if (BitSet_In(HighLetters[code], *sym)) {
		LowerCase(sym,code);
		Yo(sym,code);
		return big;
	}
	if (BitSet_In(LowLetters[code], *sym)) {
		LowerCase(sym,code);
		Yo(sym,code);
		return low;
	}
	if (BitSet_In(Wow, *sym))
		return wow;
	if (quoteOpen[code] == *sym) {
		return quoteOp;
	}
	if (quoteClose[code] == *sym)
		return quoteCl;
	switch (*sym) {
	case '.': return point;
	case '-': return def;
	case '\'':  return ap;
	default: return other;
	}
	
}


void Run(char8_t* end, char8_t* str, const TCode code, SentList* list,const HashTable stop) {
	char8_t state = 1;
	char32_t sym;
	Tokens token;
	String buff = Str_Create(20,code);
		state = 1;
		while (str!= end) {
			sym = Str_GetNP(str, code);
			token = CheckEnter(&sym, code);
			state = enter[state][token];
			if (state < 2) {
				str += GetSize(str, code);
			}
			else
				break;
		}

		while (str != end) {
			SentList_Push(list);
			list->curr = list->end;
			list->curr->start = str;
			state = 1;

			while (str != end && state != 5) {
				state = 1;
				while (str != end) {
					sym = Str_GetNP(str, code);
					token = CheckWord(&sym, code);
					state = word[state][token];
					if (state < 6) {
						Str_Push(&buff, &sym, code);
						str += GetSize(str, code);
					}
					else
						break;
				};

				state = 1;
				while (str != end) {
					sym = Str_GetNP(str, code);
					token = CheckSent(&sym, code);
					state = find[state][token];
					if (token == quoteOp)
						Stack(end, str, code, &list);
					if (state < 4) {
						str += GetSize(str, code);
					}
					else
						break;
				}

				if (!Contains(stop, buff, code)) {
					Stemming(&buff, code);
					if (!Contains(stop, buff, code)) {
						Hash_Put(&list->curr->sent, buff, code);
					}
				}
				buff.length = 0;
				buff.end = buff.arr;
			}
			list->curr->end = str;

		}
		list->curr = list->head;
}




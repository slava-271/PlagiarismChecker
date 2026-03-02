#include "PerfectiveGerund.h"


typedef bool(*PerfectiveGerund)(String* str, const TCode code);

static bool empty(String* str, const TCode code) {
	return false;
}

static bool SoftZnak(String* str, const TCode code) {
	char8_t* buff = str->end;
	char32_t sym;
	sym = Str_GetEnd(&buff,str->arr, 2,code);
	if (sym != letters[ñ][code])
		return false;
	sym = Str_GetEnd(&buff, str->arr, 1, code);
	if (sym != letters[è][code])
		return false;
	sym = Str_GetEnd(&buff, str->arr, 1, code);
	if (sym != letters[ø][code])
		return false;
	sym = Str_GetEnd(&buff, str->arr, 1, code);
	if (sym != letters[â][code])
		return false;
	char8_t* buff2 = buff;
	sym = Str_GetEnd(&buff2, str->arr, 1, code);
	if (sym == letters[û][code] || sym == letters[è][code]) {
		str->end = buff;
		str->length -= 6;
		*str->end = '\0';
		return true;
	}
	if (sym == letters[à][code] || sym == letters[ÿ][code]) {
		str->end = buff2;
		str->length -= 5;
		*str->end = '\0';
		return false;
	}
	return false;		
}

static bool I(String* str, const TCode code) {
	char8_t* buff = str->end;
	char32_t sym;
	sym = Str_GetEnd(&buff, str->arr, 2, code);
	if (sym != letters[ø][code])
		return false;
	sym = Str_GetEnd(&buff, str->arr, 1, code);
	if (sym != letters[â][code])
		return false;
	char8_t* buff2 = buff;
	sym = Str_GetEnd(&buff2, str->arr, 1, code);
	if (sym == letters[û][code] || sym == letters[è][code]) {
		str->end = buff;
		str->length -= 4;
		*str->end = '\0';
		return true;
	}
	if (sym == letters[à][code] || sym == letters[ÿ][code]) {
		str->end = buff2;
		str->length -= 3;
		*str->end = '\0';
		return true;
	}
	return false;;
}

static bool V(String* str, const TCode code) {
	char8_t* buff = str->end, * buff2;
	char32_t sym;
	Str_GetEnd(&buff, str->arr, 1,code);
	buff2 = buff;
	sym = Str_GetEnd(&buff2, str->arr, 1, code);
	if (sym == letters[û][code] || sym == letters[è][code]) {
		str->end = buff2;
		str->length -= 2;
		*str->end = '\0';
		return true;
	}
	if (sym == letters[à][code] || sym == letters[ÿ][code]) {
		str->end = buff;
		str->length--;
		*str->end = '\0';
		return true;
	}
	return false;
}


PerfectiveGerund PGarr[33] = { empty,empty,V,empty,empty,empty,empty,empty,I,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,SoftZnak,empty,empty,empty };

bool DeletePG(String* str, const TCode code) {
	char8_t* buff = str->end;
	char32_t sym = Str_GetEnd(&buff, str->arr, 1,code);
	if (sym >= letters[à][code] && sym <= letters[ÿ][code])
	{
		sym -= a[code];
	return	PGarr[sym](str, code);
	}
	return false;
}
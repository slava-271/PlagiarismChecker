#include "Adjective.h"

typedef bool(*Adjective)(String* str, const TCode code);

static bool empty(String* str, const TCode code) {
	return false;
}

static bool Ya(String *str, const TCode code) {
	char8_t* buff = str->end;
	char32_t sym;
	sym = Str_GetEnd(&buff,str->arr, 2, code);
	if (sym == letters[à][code] || sym == letters[ÿ][code]) {
		str->end = buff;
		str->length -= 2;
		*str->end = '\0';
		return true;
	}
	return false;
}

static bool Yu(String* str, const TCode code) {
	char8_t* buff = str->end;
	char32_t sym;
	sym = Str_GetEnd(&buff, str->arr, 2, code);
	if (sym == letters[å][code] || sym == letters[î][code] || sym == letters[þ][code] || sym == letters[ó][code]) {
		str->length -= 2;
		*str->end = '\0';
		str->end = buff;
		*str->end = '\0';
		return true;
	}
	return false;
}

static bool H(String* str, const TCode code) {
	char8_t* buff = str->end;
	char32_t sym;
	sym = Str_GetEnd(&buff, str->arr, 2, code);
	if (sym == letters[û][code] || sym == letters[è][code]) {
		str->length -= 2;
		*str->end = '\0';
		str->end = buff;
		*str->end = '\0';
		return true;
	}
	return false;
}

static bool M(String* str, const TCode code) {
	char8_t* buff = str->end;
	char32_t sym;
	sym = Str_GetEnd(&buff, str->arr, 2, code);
	if (sym == letters[å][code] || sym == letters[è][code] || sym == letters[û][code] || sym == letters[î][code]) {
		str->length -= 2;
		str->end = buff;
		*str->end = '\0';
		return true;
	}
	return false;
}

static bool I(String* str, const TCode code) {
	char8_t* buff = str->end;
	char32_t sym;
	sym = Str_GetEnd(&buff, str->arr, 2, code);
	if (sym != letters[ì][code])
		return false;
	sym = Str_GetEnd(&buff, str->arr, 1, code);
	if (sym == letters[û][code] || sym == letters[è][code]) {
		str->length -= 3;
		str->end = buff;
		*str->end = '\0';
		return true;
	}
	return false;
}

static bool O(String* str, const TCode code) {
	char8_t* buff = str->end;
	char32_t sym;
	sym = Str_GetEnd(&buff, str->arr, 2, code);
	if (sym != letters[ã][code])
		return false;
	sym = Str_GetEnd(&buff, str->arr, 1, code);
	if (sym == letters[î][code] || sym == letters[å][code]) {
		str->length -= 3;
		str->end = buff;
		*str->end = '\0';
		return true;
	}
	return false;
}

static bool U(String* str, const TCode code) {
	char8_t* buff = str->end;
	char32_t sym;
	sym = Str_GetEnd(&buff, str->arr, 2, code);
	if (sym != letters[ì][code])
		return false;
	sym = Str_GetEnd(&buff, str->arr, 1, code);
	if (sym == letters[î][code] || sym == letters[å][code]) {
		str->length -= 3;
		str->end = buff;
		*str->end = '\0';
		return true;
	}
	return false;
}

Adjective arr[33] = { empty,empty,empty,empty,empty,M,empty,empty,I,M,empty,empty,M,empty,O,empty,empty,empty,empty,U,empty,H,empty,empty,empty,empty,empty,empty,empty,empty,Yu,Ya};

bool DeleteAdjective(String* str, const TCode code) {
	char8_t* buff = str->end;
	char32_t sym = Str_GetEnd(&buff, str->arr, 1, code);
	if (sym >= letters[à][code] && sym <= letters[ÿ][code]) {
		sym -= a[code];
		return arr[sym](str, code);
	}
	return false;
}
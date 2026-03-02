#include "Participle.h"

typedef bool(*Participle)(String* str, const TCode code);

static bool empty(String* str, const TCode code) {
	return false;
}

static bool Sch(String* str, const TCode code) {
	char8_t* buff = str->end, * buff2;
	char32_t sym;
	Str_GetEnd(&buff, str->arr, 1, code);
	buff2 = buff;
	sym = Str_GetEnd(&buff2, str->arr, 1, code);
	if (sym == letters[à][code] || sym == letters[ÿ][code]) {
		str->length--;
		str->end = buff;
		*str->end = '\0';
		return true;
	}
	else
		if (sym == letters[þ][code]) {
			buff = buff2;
			sym = Str_GetEnd(&buff2, str->arr, 1, code);
			if (sym == letters[à][code] || sym == letters[ÿ][code]) {
				str->length -= 2;
				str->end = buff2;
				*str->end = '\0';
				return true;
			}
			else
				if (sym == letters[ó][code]) {
					str->length -= 3;
					str->end = buff;
					*str->end = '\0';
					return true;
			   }
		}
	return false;
}

static bool Sh(String* str, const TCode code) {
	char8_t* buff = str->end, * buff2;
	char32_t sym;
	sym = Str_GetEnd(&buff, str->arr, 2, code);
	if (sym == letters[â][code]) {
		buff2 = buff;
		sym = Str_GetEnd(&buff2, str->arr, 1, code);
		if (sym == letters[à][code] || sym == letters[ÿ][code]) {
			str->length -= 2;
			str->end = buff;
			*str->end = '\0';
			return true;
		}
		else if (sym == letters[è][code] || sym == letters[û][code]) {
			str->length -= 3;
			str->end = buff2;
			*str->end = '\0';
			return true;
		}
	}
	return false;
}

static bool N(String* str, const TCode code) {
	char8_t* buff = str->end, * buff2;
	char32_t sym;
	sym = Str_GetEnd(&buff, str->arr, 2, code);
	if (sym == letters[í][code]) {
		buff2 = buff;
		sym = Str_GetEnd(&buff2, str->arr, 2, code);
		if (sym == letters[à][code] || sym == letters[ÿ][code]) {
			str->length -= 2;
			str->end = buff;
			*str->end = '\0';
			return true;
		}
	}
	return false;
}

static bool M(String* str, const TCode code) {
	char8_t* buff = str->end, * buff2;
	char32_t sym;
	sym = Str_GetEnd(&buff, str->arr, 2, code);
	if (sym == letters[å][code]) {
		buff2 = buff;
		sym = Str_GetEnd(&buff2, str->arr, 2, code);
		if (sym == letters[à][code] || sym == letters[ÿ][code]) {
			str->length -= 2;
			str->end = buff;
			*str->end = '\0';
			return true;
		}
	}
	return false;
}


Participle Parr[33] = {empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,M,N,empty,empty,empty,empty,empty,empty,empty,empty,empty,empty,Sh,Sch,empty,empty,empty,empty,empty,empty };

bool DeleteParticiple(String* str, const TCode code) {
	char8_t* buff = str->end;
	char32_t sym = Str_GetEnd(&buff, str->arr, 1, code);
	if (sym >= letters[à][code] && sym <= letters[ÿ][code]) {
		sym -= a[code];
		 return Parr[sym](str, code);
	}
	return false;
}

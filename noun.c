#include "noun.h"

typedef bool(*Noun)(String* str, const TCode code);

static bool empty(String* str, const TCode code) {
	return false;
}

static bool Ya(String* str, const TCode code) {
	char8_t* buff = str->end, * buff2;
	char32_t sym;
	Str_GetEnd(&buff, str->arr, 1,code);
	buff2 = buff;
	sym = Str_GetEnd(&buff2, str->arr, 1, code);
	if (sym == letters[ü][code] || sym == letters[è][code]) {
		str->length -= 2;
		str->end = buff2;
		*str->end = '\0';
		return true;
	}
	else {
		str->length--;
		str->end = buff;
		*str->end = '\0';
		return true;
	}
	return false;
}

static bool SoftZnak(String* str, const TCode code) {
	Str_GetEnd(&str->end, str->arr, 1,code);
	*str->end = '\0';
	str->length--;
	return true;
}

static bool V(String* str, const TCode code) {
	char8_t* buff = str->end;
	char32_t sym;
	sym = Str_GetEnd(&buff, str->arr, 1, code);
	if (sym == letters[å][code] || sym == letters[î][code]) {
		str->length -= 2;
		str->end = buff;
		*str->end = '\0';
		return true;
	}
	return false;
}

static bool H(String* str, const TCode code) {
	char8_t* buff = str->end, * buff2;
	char32_t sym;
	sym = Str_GetEnd(&buff, str->arr, 2, code);
	if (sym == letters[à][code]) {
		str->length--;
		str->end = buff;
		*str->end = '\0';
		return true;
	}
	if (sym == letters[ÿ][code]) {
		buff2 = buff;
		sym = Str_GetEnd(&buff2, str->arr, 1, code);
		if (sym == letters[è][code]) {
			str->length -= 3;
			str->end = buff2;
			*str->end = '\0';
			return true;
		}
		str->length -= 2;
		str->end = buff;
		*str->end = '\0';
		return true;
	}
	return false;
}

static bool M(String *str, const TCode code) {
	char8_t* buff = str->end, * buff2;
	char32_t sym;
	sym = Str_GetEnd(&buff, str->arr, 2, code);
	if (sym == letters[à][code] || sym == letters[î][code]) {
		str->length -= 2;
		str->end = buff;
		*str->end = '\0';
		return true;
	}
	if (sym == letters[ÿ][code] || sym == letters[å][code]) {
		buff2 = buff;
		sym = Str_GetEnd(&buff2, str->arr, 1, code);
		if (sym == letters[è][code]) {
			str->length -= 3;
			str->end = buff2;
			*str->end = '\0';
			return true;
		}
		str->length -= 2;
		str->end = buff;
		*str->end = '\0';
		return true;
	}
	return false;
	}

static bool Yi(String* str, const TCode code) {
	char8_t* buff = str->end, * buff2, * buff3, * buff4;
	char32_t sym;
	Str_GetEnd(&buff, str->arr, 1, code);
	buff2 = buff;
	sym = Str_GetEnd(&buff2, str->arr, 1, code);
	if (sym == letters[è][code] || sym == letters[î][code]) {
		str->length -= 2;
		str->end = buff2;
		*str->end = '\0';
		return true;
	}
	else {
		if (sym == letters[å][code]) {
			buff3 = buff2;
			sym = Str_GetEnd(&buff3, str->arr, 1, code);
			if (sym == letters[è][code]) {
				str->length -= 3;
				str->end = buff3;
				*str->end = '\0';
				return true;
			}
			else {
				str->length -= 2;
				str->end = buff2;
				*str->end = '\0';
				return true;
			}
		}
		else {
			str->length--;
			str->end = buff;
			*str->end = '\0';
			return true;
		}
	}
	return false;
}

static bool I(String *str, const TCode code) {
	char8_t* buff = str->end, * buff2, * buff3, * buff4;
	char32_t sym;
	Str_GetEnd(&buff, str->arr, 1, code);
	buff2 = buff;
	sym = Str_GetEnd(&buff2, str->arr, 1, code);
	if (sym == letters[å][code] || sym == letters[è][code]) {
		str->length -= 2;
		str->end = buff2;
		*str->end = '\0';
		return true;
	}
	else {
		if (sym == letters[ì][code]) {
			sym = Str_GetEnd(&buff2, str->arr, 1, code);
			if (sym == letters[à][code]) {
				str->length -= 3;
				str->end = buff2;
				*str->end = '\0';
				return true;
			}
			else {
				if (sym == letters[ÿ][code]) {
					buff3 = buff2;
					sym = Str_GetEnd(&buff3, str->arr, 1,code);
					if (sym == letters[è][code]) {
						str->length -= 4;
						str->end = buff3;
						*str->end = '\0';
						return true;
					}
					else {
						str->length -= 3;
						str->end = buff2;
						*str->end = '\0';
						return true;
					}
				}
				else {
					str->length--;
					str->end = buff;
					*str->end = '\0';
					return true;
				}
			}
		}
		else { 
			str->length--;
			str->end = buff;
			*str->end = '\0';
			return true;
		}
	}
	return false;
}

Noun Narr[33] = { SoftZnak,  empty, V,  empty,  empty, Ya,  empty,  empty, I, Yi,  empty,  empty, M,  empty, SoftZnak,  empty,  empty,  empty,  empty, SoftZnak,  empty, H,  empty,  empty,  empty, empty,  empty, SoftZnak, SoftZnak,  empty, Ya, Ya };

bool DeleteNoun(String* str, const TCode code) {
	char8_t* buff = str->end;
	char32_t sym = Str_GetEnd(&buff, str->arr, 1, code);
	if (sym >= letters[à][code] && sym <= letters[ÿ][code]) {
		sym -= a[code];
		return Narr[sym](str, code);
	}
	return false;
}



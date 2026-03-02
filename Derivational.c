#include "Derivational.h"

bool DeleteDerivational(String* str, const TCode code) {
	char8_t* buff = str->end;
	char32_t sym = Str_GetEnd(&buff, str->arr, 1, code);
	int i = 3;
	if (sym == letters[ü][code]) {
		sym = Str_GetEnd(&buff, str->arr, 1, code);
		i++;
	}
	if (sym == letters[ò][code]) {
		sym = Str_GetEnd(&buff, str->arr, 1, code);
		if (sym == letters[ñ][code]) {
			sym = Str_GetEnd(&buff, str->arr, 1, code);
			if (sym == letters[î][code]) {
				str->end = buff;
				str->length -= i;
				*str->end = '\0';
				return true;
			}
		}
	}
	return false;
}

bool DeleteReflexive(String* str, const TCode code) {
	char8_t* buff = str->end;
	char32_t sym = Str_GetEnd(&buff, str->arr, 1, code);
	if (sym == letters[ü][code] || sym == letters[ÿ][code]) {
		sym = Str_GetEnd(&buff,str->arr,1,code);
		if (sym == letters[ñ][code]) {
			str->length -= 2;
			str->end = buff;
			*str->end = '\0';
			return true;
		}
	}
	return false;
}

bool DeleteSuperlative(String* str, const TCode code) {
	char8_t* buff = str->end;
	char32_t sym = Str_GetEnd(&buff, str->arr, 1, code);
	int i = 3;
	if (sym == letters[å][code]) {
		i++;
		sym = Str_GetEnd(&buff, str->arr, 1, code);
	}
	if (sym == letters[ø][code]) {
		sym = Str_GetEnd(&buff, str->arr, 1, code);
		if (sym == letters[é][code]) {
			sym = Str_GetEnd(&buff, str->arr, 1, code);
			if (sym == letters[å][code]) {
				str->end = buff;
				str->length -= i;
				*str->end = '\0';
				return true;
			}
		}
	}
	return false;
}
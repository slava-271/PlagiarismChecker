#include "Verb.h"

typedef void(*Verb)(String* str, const TCode code);

static bool empty(String* str, const TCode code) {
	return false;
}

static bool Yu(String* str, const TCode code) {
	char8_t* buff = str->end, *buff2;
	char32_t sym;
	Str_GetEnd(&buff, str->arr, 1,code);
	buff2 = buff;
	sym = Str_GetEnd(&buff2, str->arr, 1,code);
	if (sym == letters[ó][code]) {
		str->length -= 2;
		str->end = buff2;
		*str->end = '\0';
		return true;
	}
	else {
		str->length--;
		str->end = buff;
		*str->end = '\0';
		return false;
	}
	return false;
}

static bool N(String* str, const TCode code) {
	char8_t* buff = str->end, * buff2;
	char32_t sym;
	Str_GetEnd(&buff, str->arr, 1, code);
	buff2 = buff;
	sym = Str_GetEnd(&buff2, str->arr, 1, code);
	if (sym == letters[å][code]) {
		str->length -= 2;
		str->end = buff2;
		*str->end = '\0';
		return true;
	}
	else
		if (sym == letters[à][code] || sym == letters[ÿ][code]) {
			str->length--;
			str->end = buff;
			*str->end = '\0';
			return true;
		}
	return false;
}

static bool SoftZnak(String* str, const TCode code) {
	char8_t* buff = str->end, * buff2, * buff3;
	char32_t sym;
	sym = Str_GetEnd(&buff, str->arr, 2, code);
	if (sym == letters[ø][code]) {
		sym = Str_GetEnd(&buff, str->arr, 1, code);
		if (sym == letters[è][code]) {
			str->length -= 3;
			str->end = buff;
			*str->end = '\0';
			return true;
		}
		else {
			if (sym == letters[å][code]) {
				buff2 = buff;
				sym = Str_GetEnd(&buff2, str->arr, 2, code);
				if (sym == letters[à][code] || sym == letters[ÿ][code]) {
					str->length -= 3;
					str->end = buff;
					*str->end = '\0';
					return true;
				}
			}
		}

	}
	else if (sym == letters[ò][code]) {
		buff2 = buff;
		sym = Str_GetEnd(&buff2, str->arr, 1, code);
		if (sym == letters[à][code] || sym == letters[ÿ][code]) {
			str->length -= 2;
			str->end = buff;
			*str->end = '\0';
			return true;
		}
		else {
			buff3 = buff2;
			sym = Str_GetEnd(&buff2, str->arr, 1, code);
			if (sym == letters[û][code] || sym == letters[é][code]) {
				str->length -= 3;
				str->end = buff3;
				*str->end = '\0';
				return true;
			}
		}
	}
	return false;
}

static bool A(String* str, const TCode code) {
	char8_t* buff = str->end, * buff2;
	char32_t sym;
	sym = Str_GetEnd(&buff, str->arr, 2, code);
	if (sym == letters[ë][code]) {
		buff2 = buff;
		sym = Str_GetEnd(&buff2, str->arr, 1, code);
		if (sym == letters[à][code] || sym == letters[ÿ][code]) {
			str->length -= 2;
			str->end = buff;
			*str->end = '\0';
			return true;
		} else
			if (sym == letters[û][code] || sym == letters[é][code]) {
				str->length -= 3;
				str->end = buff2;
				*str->end = '\0';
				return true;
			}
	}
	else {
		if (sym == letters[í][code]) {
			buff2 = buff;
			sym = Str_GetEnd(&buff2, str->arr, 1, code);
			if (sym == letters[å][code]) {
				str->length -= 3;
				str->end = buff2;
				*str->end = '\0';
				return true;
			}
			else 
				if (sym == letters[à][code] || sym == letters[ÿ][code]) {
					str->length -= 2;
					str->end = buff;
					*str->end = '\0';
					return true;
				}
		}
	}
	return false;
}

static bool Wy(String* str, const TCode code) {
	char8_t* buff = str->end, * buff2;
	char32_t sym;
	sym = Str_GetEnd(&buff, str->arr, 2, code);
	if (sym == letters[í][code]) {
		buff2 = buff;
		sym = Str_GetEnd(&buff2, str->arr, 1, code);
		if (sym == letters[å][code]) {
			str->length -= 3;
			str->end = buff2;
			*str->end = '\0';
			return true;
		}else
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
	if (sym == letters[è][code] || sym == letters[û][code]) {
		str->length -= 2;
		str->end = buff;
		*str->end = '\0';
		return true;
	} else 
		if (sym == letters[å][code]) {
			buff2 = buff;
			sym = Str_GetEnd(&buff2,str->arr,1,code);
			if (sym == letters[à][code] || sym == letters[ÿ][code]) {
				str->length -= 2;
				str->end = buff;
				*str->end = '\0';
				return true;
			}
		}
	return false;
}

static bool L(String* str, const TCode code) {
	char8_t* buff = str->end, * buff2;
	char32_t sym;
	Str_GetEnd(&buff, str->arr, 1, code);
	buff2 = buff;
	sym = Str_GetEnd(&buff2, str->arr, 1, code);
	if (sym == letters[è][code] || sym == letters[û][code]) {
		str->length -= 2;
		str->end = buff2;
		*str->end = '\0';
		return true;
	}
	else
		if (sym == letters[à][code] || sym == letters[ÿ][code]) {
			str->length--;
			str->end = buff;
			*str->end = '\0';
			return true;
		}
	return false;
}

static bool Yi(String* str, const TCode code) {
	char8_t* buff = str->end, * buff2;
	char32_t sym;
	Str_GetEnd(&buff, str->arr, 1, code);
	buff2 = buff;
	sym = Str_GetEnd(&buff2, str->arr, 1, code);
	if (sym == letters[ó][code] || sym == letters[å][code]) {
		str->length -= 2;
		str->end = buff2;
		*str->end = '\0';
		return true;
	}
	else
		if (sym == letters[à][code] || sym == letters[ÿ][code]) {
			str->length--;
			str->end = buff;
			*str->end = '\0';
			return true;
		}
	return false;
}

static bool I(String* str, const TCode code) {
	char8_t* buff = str->end, * buff2;
	char32_t sym;
	sym = Str_GetEnd(&buff, str->arr, 2, code);
	if (sym == letters[ë][code]) {
		buff2 = buff;
		sym = Str_GetEnd(&buff2, str->arr, 1, code);
		if (sym == letters[è][code] || sym == letters[û][code]) {
			str->length -= 3;
			str->end = buff2;
			*str->end = '\0';
			return true;
		}
		else
			if (sym == letters[à][code] || sym == letters[ÿ][code]) {
				str->length -= 2;
				str->end = buff;
				*str->end = '\0';
				return true;
			}
	}
	return false;
}

static bool E(String* str, const TCode code) {
	char8_t* buff = str->end, * buff2;
	char32_t sym;
	sym = Str_GetEnd(&buff, str->arr, 2, code);
	if (sym != letters[ò][code])
		return false;
	sym = Str_GetEnd(&buff, str->arr, 1, code);
	if (sym == letters[è][code]) {
		str->length -= 3;
		str->end = buff;
		*str->end = '\0';
		return true;
	}
	else if (sym == letters[é][code]) {
		buff2 = buff;
		sym = Str_GetEnd(&buff, str->arr, 1, code);
		if (sym == letters[å][code] || sym == letters[ó][code]) {
			str->length -= 4;
			str->end = buff2;
			*str->end = '\0';
			return true;
		}
		else if (sym == letters[à][code] || sym == letters[ÿ][code]) {
			str->length -= 3;
			str->end = buff;
			*str->end = '\0';
			return true;
		}
	}
	else if (sym == letters[å][code]) {
		buff2 = buff;
		if (sym == letters[à][code] || sym == letters[ÿ][code]) {
			str->length -= 3;
			str->end = buff;
			*str->end = '\0';
			return true;
		}
	}
	return false;
}

static bool O(String* str, const TCode code) {
	char8_t* buff = str->end, * buff2;
	char32_t sym;
	sym = Str_GetEnd(&buff, str->arr, 2, code);
	if (sym == letters[í][code]) {
		buff2 = buff;
		sym = Str_GetEnd(&buff2, str->arr, 1, code);
		if (sym == letters[à][code] || sym == letters[ÿ][code]) {
			str->length -= 2;
			str->end = buff;
			*str->end = '\0';
			return true;
		}
		else if (sym == letters[å][code]) {
			str->length -= 3;
			str->end = buff2;
			*str->end = '\0';
			return true;
		}
		else if (sym == letters[í][code]) {
			buff = buff2;
			sym = Str_GetEnd(&buff2, str->arr, 1, code);
			if (sym == letters[à][code] || sym == letters[ÿ][code]) {
				str->length -= 3;
				str->end = buff2;
				*str->end = '\0';
				return true;
			}
		}
	}
	else if (sym != letters[ë][code]) {
		buff2 = buff;
		sym = Str_GetEnd(&buff2, str->arr, 1, code);
		if (sym == letters[à][code] || sym == letters[ÿ][code]) {
			str->length -= 2;
			str->end = buff;
			*str->end = '\0';
			return true;
		}
		else if (sym == letters[û][code] || sym == letters[è][code]) {
			str->length -= 3;
			str->end = buff2;
			*str->end = '\0';
			return true;
		}
	}
	return false;
}

static bool T(String* str, const TCode code) {
	char8_t* buff = str->end, * buff2;
	char32_t sym;
	sym = Str_GetEnd(&buff, str->arr, 2, code);
	if (sym == letters[è][code] || sym == letters[û][code] || sym == letters[ÿ][code]) {
		str->length -= 2;
		str->end = buff;
		return true;
	}
	else if (sym != letters[å][code] || sym != letters[þ][code]) {
		buff2 = buff;
		sym = Str_GetEnd(&buff, str->arr, 1, code);
		if (sym == letters[à][code] || sym == letters[ÿ][code]) {
			str->length -= 2;
			str->end = buff2;
			*str->end = '\0';
			return true;
		}
		else if (sym == letters[ó][code]) {
			str->length -= 3;
			str->end = buff;
			*str->end = '\0';
			return true;
		}
	}
	return false;
}

Verb Varr[33] = { A,empty,empty,empty,empty,E,empty,empty,I,Yi,empty,L,empty,N,O,empty,empty,empty,T,empty,empty,empty,empty,empty,empty,empty,empty,Wy,SoftZnak,empty,Yu,empty };

void DeleteVerb(String* str, const TCode code) {
	char8_t* buff = str->end;
	char32_t sym = Str_GetEnd(&buff, str->arr, 1, code);
	if (sym >= letters[à][code] && sym <= letters[ÿ][code]) {
		sym -= a[code];
		return Varr[sym](str, code);
	}
	return false;
}
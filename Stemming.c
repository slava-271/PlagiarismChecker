#include "Stemming.h"

bool DeleteAdjectival(String* str, const TCode code) {
	if (DeleteAdjective(str, code)) {
		return DeleteParticiple(str, code);
	}
	return false;
}

char8_t* CheckRv(String* str, TCode code) {
	size_t i = 0;
	bool flag = true;
	char8_t* buff = str->arr;
	char32_t sym;
	while (buff < str->end && flag) {
		sym = Str_GetNP(buff, code);
		flag = Sym_Check(sym, code, SoglasnyeLetters[code]);
		buff += GetSize(str, code);
	}

	return buff;
}

char8_t* CheckRv2(String*str, TCode code) {
	size_t i = 0;
	bool flag = true;
	char8_t* buff = str->arr;
	//while (buff < str->end && Sym_Check(Str_GetP(&buff, code), code, SoglasnyeLetters[code]));
	while (buff < str->end && Sym_Check(Str_GetP(&buff, code), code, GlasnyeLetters[code]));

	while (buff < str->end && Sym_Check(Str_GetP(&buff, code), code, SoglasnyeLetters[code]));
	while (buff < str->end && Sym_Check(Str_GetP(&buff, code), code, GlasnyeLetters[code]));
	return buff;
}

void Stemming(String* str, const TCode code) {
	char8_t* buff, *oldStart,*RV, *R2, *buff2;
	char32_t sym;
	oldStart = str->arr;
	RV = CheckRv(str,code);
	if (RV >= str->end)
		return;
	str->arr = RV;
	if (!DeletePG(str, code)) {
		DeleteReflexive(str,code);
		if (!DeleteAdjectival(str, code)) {
			if (!DeleteVerb(str, code)) {
				DeleteNoun(str,code);
			}
		}
	}
	buff = str->end;
	if (Str_GetEnd(&buff, str->arr, 1, code) == letters[è][code]) {
		str->length--;
		str->end = buff;
		*str->end = '\0';
	}
	RV = str->arr;
	str->arr = CheckRv2(str, code);
	if (str->arr <= str->end)
	  DeleteDerivational(str,code);
	str->arr = RV;
	buff = str->end;
	if (Str_GetEnd(&buff,str->arr,1,code) == letters[ü][code]) {
		str->length--;
		str->end = buff;
		*str->end = '\0';
	}
	else {
		buff = str->end;
		DeleteSuperlative(str,code);
		sym = Str_GetEnd(&buff, str->arr, 1, code);
		if (sym == letters[í][code]) {
			buff2 = buff;
			sym = Str_GetEnd(&buff2, str->arr, 1, code);
			if (sym == letters[í][code]) {
				str->length--;
				str->end = buff;
				*str->end = '\0';
			}
		}
	}
	str->arr = oldStart;
}
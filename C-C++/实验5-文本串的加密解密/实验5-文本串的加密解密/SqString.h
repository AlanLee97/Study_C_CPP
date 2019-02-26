#include <iostream>
#define MaxSize 50
using namespace std;

typedef char ElemType;
typedef struct {
	char data[MaxSize];
	int length;
}SqString;

void strAssign(SqString &s, char cstr[]) {
	int i = 0;
	for (i = 0; cstr[i] != '\0'; i++) {
		s.data[i] = cstr[i];
	}
	s.length = i;
}

void DestroyStr(SqString &s) {

}

void StrCopy(SqString &s,SqString t){
	int i;
	for (i = 0; i < t.length;i++) {
		s.data[i] = t.data[i];
	}
	s.length = t.length;
}

bool StrEqual(SqString &s, SqString t) {
	bool same = true;
	int i = 0;
	if (s.length != t.length) {
		return false;
	}
	else {
		for (i = 0; i < s.length; i++) {
			if (s.data[i] != t.data[i]) {
				return false;
			}
		}
	}
	return true;
}

int StrLength(SqString &s) {
	return s.length;
}

SqString Concat(SqString s, SqString t) {
	SqString str;
	int i;
	str.length = s.length + t.length;
	for (i = 0; i < s.length; i++) {
		str.data[i] = s.data[i];
	}
	for (i = 0; i < t.length; i++) {
		str.data[s.length + i] = t.data[i];
	}
	return str;
}

//返回顺序串s中从第i个字符开始的j个长度组成的子串。
SqString SubString(SqString s, int i, int j) {
	int k;
	SqString str;
	str.length = 0;
	if (i < 0 || i > s.length || j < 0 || i + j - 1 > s.length) {
		return str;
	}
	for (k = i - 1; k < i + j - 1; k++) {
		str.data[k - i + 1] = s.data[k];
	}
	s.length = j;
	return str;
}

SqString InsertStr(SqString src, int i, SqString dec) {
	int j;
	SqString str;
	str.length = 0;
	if (i  < 0 || i > src.length + 1) {
		return str;
	}
	for (j = 0; j < i - 1; j++) {
		str.data[j] = src.data[j];
	}
	for (j = 0; j < dec.length; j++) {
		str.data[i + j -1] = dec.data[j];
	}
	for (j = i - 1; j < src.length; j++) {
		str.data[src.length + j] = src.data[j];
	}
	str.length = src.length + dec.length;
	return str;
}

SqString DelStr(SqString s, int i, int j) {
	int k;
	SqString str;
	str.length = 0;
	if (i < 0 || i > s.length || j < 0 || i + j > s.length + 1) {
		return str;
	}
	for (k = 0; k < i - 1; k++) {
		str.data[k] = s.data[k];
	}
	for (k = i + j - 1; k < s.length; k++) {
		str.data[k - j] = s.data[k];
	}
	str.length = s.length - j;
	return str;
}

SqString ReplaceStr(SqString src, int i, int j, SqString dec) {
	int k;
	SqString str;
	str.length = 0;
	if (i <= 0 || i > src.length || i + j - 1 > src.length) {
		return str;
	}
	for (k = 0; k < i - 1; k++) {
		str.data[k] = src.data[k];
	}
	for (k = 0; k < dec.length; k++) {
		str.data[i + k - 1] = dec.data[k];
	}
	for (k = i + j - 1; k < src.length; k++) {
		str.data[dec.length + k - j] = src.data[k];
	}
	str.length = src.length - j + dec.length;
}

void DispStr(SqString s) {
	int i;
	if (s.length > 0) {
		for (i = 0; i < s.length; i++) {
			cout << s.data[i];
		}
		cout << endl;
	}
}












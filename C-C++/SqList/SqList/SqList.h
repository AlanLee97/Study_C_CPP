#include<iostream>
#include<malloc.h>
using namespace std;

typedef int ElemType;
typedef struct {
	Elemtype data[50];
	int length;
}SqList;

void CreateList(SqList *&L, ElemType a[], int n) {
	int i = 0;
	int k = 0;
	L = (SqList *)malloc(sizeof(SqList));
	for (; i < n; i++, k++) {
		L->data[i] = a[i];
	}
	L->length = k;
}

void InitList(SqList *&L) {
	L = (SqList *)malloc(sizeof(SqList));
	L->length = 0;
}

void DestoryList(SqList *L) {
	free(L);
}

bool ListEmpty(SqList *L) {
	return (L->length == 0);
}

int ListLength(SqList *L) {
	return L->length;
}

void DispList(SqList *L) {
	for (int i = 0; i < L->length; i++) {
		cout << L->data[i] << " ";
	}
	cout << endl;
}

bool GetElem(SqList *L, int i, ElemType e) {
	if (i < 0 || i > L->length) return false;
	e = L->data[i - 1];
	return true;
}

int LocateElem(SqList *L, ElemType e) {
	int i = 0;
	while (i < L->length && L->data[i] != e) {
		i++;
	}
	if (i >= L->data[i]) return 0;
	else return i + 1;
}

bool ListInsert(SqList *&L, int i, ElemType e) {
	int j;
	if()
}




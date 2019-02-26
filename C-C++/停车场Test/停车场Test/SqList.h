#pragma once
#pragma once
#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include"Stopplace.h"
#define MaxSize 50
using namespace std;

typedef sp ElemType;
typedef struct {
	ElemType data[MaxSize];
	int length;
}SqList;

void CreateList(SqList *&L, ElemType a[], int n) {
	int i = 0, k = 0;
	L = (SqList *)malloc(sizeof(SqList));//分配存放线性表的空间
	while (i < n) {						 //i扫描数组a的元素
		L->data[k] = a[i];				 //将元素a[i]存放到数组中
		k++; i++;
	}
	L->length = k;
}

void InitList(SqList *&L) {
	L = (SqList *)malloc(sizeof(SqList));//分配存放线性表的空间
	L->length = 0;						 //初始时设置线性表的长度为0
}

void Destroy(SqList *&L) {
	free(L);//释放L所指的顺序表空间
}

bool ListEmpty(SqList *L) {
	return (L->length == 0);
}

int ListLength(SqList *L) {
	return (L->length);
}

void DispList(SqList *L) {
	for (int i = 0; i < L->length; i++) {//扫描顺序表输出个元素值
		Op(L->data[i]);
	}
	cout << endl;
}

bool GetElem(SqList *L, int i, ElemType &e) {
	if (i < 1 || i > L->length) return false;//先判断数值的正确性
	e = L->data[i - 1];//将取得的元素赋值给e
	return true;
}


int LocateElem(SqList *L, ElemType e) {
	int i = 0;
	while (i < L->length && L->data[i].digit != e.digit) i++;
	if (i >= L->length) return 0;
	else return i + 1;
}


bool ListInsert(SqList *&L, int i, ElemType e) {//将元素e插入到线性表L的第i个位置
	int j;
	if (i < 1 || i > L->length) return false;
	i--;
	for (j = L->length;j > i;j--) {
		L->data[j] = L->data[j - 1];
	}
	L->data[i] = e;
	L->length++;
	return true;

}

bool ListDelete(SqList *&L, int i, ElemType &e) {
	int j;
	if (i < 1 || i > L->length) return false;
	i--;
	e = L->data[i];

	for (j = i;j < L->length - 1;j++) {
		L->data[j] = L->data[j + 1];
	}

	L->length--;
	return true;
}






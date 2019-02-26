#include<iostream>
#include<stdlib.h>
#include<malloc.h>
#define MaxSize 50
using namespace std;

typedef char ElemType;
typedef struct {
	char name[8];
	int length;
}SqList;

void CreateList(SqList *&L, ElemType a[], int n) {
	int i = 0, k = 0;
	L = (SqList *)malloc(sizeof(SqList));//���������Ա�Ŀռ�
	while (i < n) {						 //iɨ������a��Ԫ��
		L->name[k] = a[i];				 //��Ԫ��a[i]��ŵ�������
		k++; i++;
	}
	L->length = k;
}

void InitList(SqList *&L) {
	L = (SqList *)malloc(sizeof(SqList));//���������Ա�Ŀռ�
	L->length = 0;						 //��ʼʱ�������Ա�ĳ���Ϊ0
}

void Destroy(SqList *&L) {
	free(L);//�ͷ�L��ָ��˳���ռ�
}

bool ListEmpty(SqList *L) {
	return (L->length == 0);
}

int ListLength(SqList *L) {
	return (L->length);
}

void DispList(SqList *L) {
	for (int i = 0; i < L->length; i++) {//ɨ��˳��������Ԫ��ֵ
		cout << L->name[i] << " ";
	}
	cout << endl;
}

bool GetElem(SqList *L, int i, ElemType &e) {
	if (i < 1 || i > L->length) return false;//���ж���ֵ����ȷ��
	e = L->name[i - 1];//��ȡ�õ�Ԫ�ظ�ֵ��e
	return true;
}


int LocateElem(SqList *L, ElemType e) {
	int i = 0;
	while (i < L->length && L->name[i] != e) i++;
	if (i >= L->length) return 0;
	else return i + 1;
}


bool ListInsert(SqList *&L, int i, ElemType e) {//��Ԫ��e���뵽���Ա�L�ĵ�i��λ��
	int j;
	if (i < 1 || i > L->length) return false;
	i--;
	for (j = L->length;j > i;j--) {
		L->name[j] = L->name[j - 1];
	}
	L->name[i] = e;
	L->length++;
	return true;

}

bool ListDelete(SqList *&L, int i, ElemType &e) {
	int j;
	if (i < 1 || i > L->length) return false;
	i--;
	e = L->name[i];

	for (j = i;j < L->length - 1;j++) {
		L->name[j] = L->name[j + 1];
	}

	L->length--;
	return true;

}


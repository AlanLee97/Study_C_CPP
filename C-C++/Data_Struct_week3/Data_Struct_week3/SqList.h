#include<iostream>
#include<stdlib.h>
#include<malloc.h>
#define MaxSize 50
using namespace std;

typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];
	int length;
}SqList;

void CreateList(SqList *&L, ElemType a[], int n) {
	int i = 0, k = 0;
	L = (SqList *)malloc(sizeof(SqList));//分配存放线性表的空间
	while (i < n) {						 //i扫描数组a的元素
		L-> data[k] = a[i];				 //将元素a[i]存放到数组中
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
		cout << L->data[i] << " ";
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
	while (i < L->length && L->data[i] != e) i++;
	if(i >= L -> length) return 0;
	else return i+1;
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




/*
void DelValueOfxToy(SqList *&L,ElemType x, ElemType y) {
	ElemType temp = 0;
	int count = 0;	//用来统计循环的次数
	int sum = (y - x) + 1;	//计算要删除多少个元素
	for (int i = x; i <= y; ) {	//这里不让i自增，即每次删除操作都删x位置的那个元素
		count++;
		ListDelete(L, i, temp);
		if (count == sum) break;	//如果循环次数等于要删除元素个数，就停止循环
									//即要删除几个元素，就循环几次
	}
}*/




void DelValueOfxToy(SqList *&L, ElemType x, ElemType y) {
	ElemType logicNum = 0;
	ElemType temp;
	for (int i = 0; i < L->length; i++) {
		if (L->data[i] >= x && L->data[i] <= y) {//判断要删除的数是否在x~y之间
			logicNum = LocateElem(L, L->data[i]);//找到这个数的逻辑序号
			ListDelete(L, logicNum, temp);//将其删除
		}
	}
}





void fun(SqList *&L, ElemType x, ElemType y) {
	int i, k = 0;
	for (i = 0; i<L->length; i++)
		if (!(L->data[i] >= x && L->data[i] <= y)) {
			L->data[k] = L->data[i];
			k++;
		}
	L->length = k;
}




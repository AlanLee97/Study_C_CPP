/*
12. 设计一个算法，将一个带头结点的数据域依次为 a1、a2、…、an（n≥3）的
单链表 的所有结点逆置，即第一个结点的数据域变为 an，第 2 个结点的数据
域变为 an-1，…，尾 结点的数据域为 a1。
*/
//main.cpp
#include <iostream>
#include "ListNode.h"
using namespace std;

int main()
{
	ListNode *L;
	InitList(L);
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << "集合L:";
	CreateListR(L, a, 10);		//尾插法
	DispList(L);

	



	DispList(L);

	DestoryList(L);
	system("pause");
	return 0;
}






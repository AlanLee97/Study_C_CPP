/*
12. ���һ���㷨����һ����ͷ��������������Ϊ a1��a2������an��n��3����
������ �����н�����ã�����һ�������������Ϊ an���� 2 ����������
���Ϊ an-1������β ����������Ϊ a1��
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
	cout << "����L:";
	CreateListR(L, a, 10);		//β�巨
	DispList(L);

	



	DispList(L);

	DestoryList(L);
	system("pause");
	return 0;
}






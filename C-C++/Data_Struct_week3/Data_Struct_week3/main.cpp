#include<iostream>
#include "SqList.h"
using namespace std;


int main()
{
	SqList *L;
	InitList(L);
	int arr[10] = { 1,39,42,20,75,11,78,40,91,22 };
	CreateList(L, arr, 10);
	cout << "ԭ����Ϊ��";
	DispList(L);

	DelValueOfxToy(L, 10, 40);
	cout << "ɾ��10~40֮������ֺ�" << "\n������Ϊ��" << endl;
	DispList(L);


















	/*
	SqList *L;
	ElemType e;
	int position = 0;
	int menuNum = 0;
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	//InitList(L);
	CreateList(L, a, 10);

	cout << "˳����е����ݣ�" ;
	DispList(L);
	cout << "\n��ǰ����" << ListLength(L) << "�����֡�" << endl;

	 while (menuNum <= 4) {
		//��Ʋ˵�
	 menu:cout << endl << "\n\n===============�˵���==============="<< endl
			<< "\t 1.��������\n"
			<< "\t 2.ɾ������\n"
			<< "\t 3.�鿴����\n"
			<< "\t 4.�˳�\n"
			<< "==============��ѡ��(����˵��ı��)��";
	
		//ѡ��˵�
		cin >> menuNum;
		switch (menuNum) {
			case 1:
				cout << "\n��������Ҫ��������֣�";
				cin >> e;
				cout << "\n����� " << e << " ���뵽�ĸ�λ�ã�" << endl;
				cin >> position;
				ListInsert(L, position, e);
				cout << "\n�����Ľ����" << endl;
				DispList(L);
				cout << "\n��ǰ����" << ListLength(L) << "�����֡�" << endl;
				break;
			case 2:
				cout << "\n��������Ҫɾ�������ֵ�λ�ã�";
				cin >> position;
				GetElem(L, position, e);
				cout << "\n��ɾ�����֣�" << e << endl;
				ListDelete(L, position, e);
				cout << "\nɾ����Ľ����" << endl;
				DispList(L);
				cout << "\n��ǰ����" << ListLength(L) << "�����֡�" << endl;
				break;
			case 3:
				DispList(L);
				cout << "\n��ǰ����" << ListLength(L) << "�����֡�" << endl;
				break;
			case 4:
				exit(0);
			default:
				cout << "\n����������������룡" << endl;
				goto menu;
		}
	}
	*/
	
	cout << endl <<endl;
	Destroy(L);
	system("pause");
	return 0;
}
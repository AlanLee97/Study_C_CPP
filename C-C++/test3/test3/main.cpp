#include<iostream>
#include "SqList.h"
using namespace std;


int main()
{
	SqList *L;
	ElemType e;
	int position = 0;
	int menuNum = 0;
	char a[10] = { 'A','B','C' };
	//InitList(L);
	CreateList(L, a, 3);

	cout << "顺序表中的数据：";
	DispList(L);
	cout << "\n当前共有" << ListLength(L) << "个字符。" << endl;

	while (menuNum <= 4) {
		//设计菜单
	menu:cout << endl << "\n\n===============菜单栏===============" << endl
		<< "\t 1.插入数据\n"
		<< "\t 2.删除数据\n"
		<< "\t 3.查看数据\n"
		<< "\t 4.退出\n"
		<< "==============请选择(输入菜单的编号)：";

		 //选择菜单
		 cin >> menuNum;
		 switch (menuNum) {
		 case 1:
			 cout << "\n请输入你要插入的字符：";
			 cin >> e;
			 cout << "\n你想把 " << e << " 插入到哪个位置？" << endl;
			 cin >> position;
			 ListInsert(L, position, e);
			 cout << "\n插入后的结果：" << endl;
			 DispList(L);
			 cout << "\n当前共有" << ListLength(L) << "个字符。" << endl;
			 break;
		 case 2:
			 cout << "\n请输入你要删除的字符的位置：";
			 cin >> position;
			 cout << "\n将删除字符：" << GetElem(L, position, e) << endl;
			 ListDelete(L, position, e);
			 cout << "\n删除后的结果：" << endl;
			 DispList(L);
			 cout << "\n当前共有" << ListLength(L) << "个字符。" << endl;
			 break;
		 case 3:
			 DispList(L);
			 cout << "\n当前共有" << ListLength(L) << "个字符。" << endl;
			 break;
		 case 4:
			 exit(0);
		 default:
			 cout << "\n输入出错，请重新输入！" << endl;
			 goto menu;
		 }
	}

	cout << endl << endl;
	system("pause");
	return 0;
}
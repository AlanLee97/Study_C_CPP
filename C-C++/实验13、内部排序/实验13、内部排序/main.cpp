#include <iostream>
#include "Sorting.h"
#define N 50
using namespace std;

KeyType a[] = { 49, 38, 65, 97, 76, 13, 27,49 };
RecType R[N];
int len = sizeof(a) / sizeof(KeyType);
int main()
{
	//cout << len;
	cout << "��ʼ�ؼ��֣�";
	for (int i = 0; i < 8; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	

	//1.ֱ�Ӳ�������
	cout << "1.ֱ�Ӳ������򷨣�";
	CreateSort(R, a, len);
	insertSort(R, len);
	cout << "\n-----ֱ�Ӳ��������Ľ����";
	DispSort(R, len);
	cout << "\n\n";

	//2.ϣ�����򣨷���������򷽷���
	cout << "2.ϣ������";
	CreateSort(R, a, len);
	ShellSort(R, len);
	cout << "\n-----ϣ�������Ľ����";
	DispSort(R, len);
	cout << "\n\n";

	//3.1 ð������
	cout << "3.1 ð������";
	CreateSort(R, a, len);
	BubbleSort(R, len);
	cout << "\n-----ð�������Ľ����";
	DispSort(R, len);
	cout << "\n\n";

	//3.2 �Ż���ð������
	cout << "3.2 �Ż���ð������";
	CreateSort(R, a, len);
	BubbleSort1(R, len);
	cout << "\n-----�Ż�ð�������Ľ����";
	DispSort(R, len);
	cout << "\n\n";

	//4.��������
	cout << "4.�������򷨣�";
	CreateSort(R, a, len);
	QuickSort(R, 0, len - 1);
	cout << "\n-----���������Ľ����";
	DispSort(R, len);
	cout << "\n\n";


	//5.��ѡ������
	cout << "5.��ѡ������";
	CreateSort(R, a, len);
	SelectSort(R, len);
	cout << "\n-----��ѡ�������Ľ����";
	DispSort(R, len);
	cout << "\n\n";


	cout << endl;
	system("pause");
	return 0;
}
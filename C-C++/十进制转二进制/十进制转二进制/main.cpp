#include<iostream>
#include<string>
using namespace std;

int main()
{
	cout << "������һ��ʮ����������";
	int a[100];
	int count = 0;
	int InputNum;
	cin >> InputNum;
	int CalNum = InputNum;
	while(CalNum) {
		a[count] = CalNum % 2;
		CalNum = CalNum / 2;
		count++;
	} 
	cout << InputNum << "�Ķ�������Ϊ��" ;
	for (int i = count - 1; i >= 0; i--) {
		cout << a[i];
	}
	cout << "\n";
	system("pause");
	return 0;
}

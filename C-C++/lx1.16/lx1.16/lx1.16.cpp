#include<iostream>
using namespace std;
//����һ�������������

int main()
{
	int values;
	int sum = 0;
	cout << "����һ�������������(��ctrl+z+enter����):";
	for (;cin >> values;)
	{
		sum += values;
	}
	cout << "��Щ���ĺ�Ϊ��" << sum << endl;

	system("pause");
	return 0;
}
#include<iostream>
using namespace std;
//�����������ͬ��ֵ���ֶ��ٴ�

int main()
{
	int values=0;
	int num = 0;
	cout << "������һ��������";
	if (cin >> num)
	{
		int i = 1;
		while (cin >> values)
		{
			if (num == values)
			{
				++i;
			}
			else
			{
				cout << values << "������" << i << "��" << endl;
			}
			values = num;
			i = 1;
		}
		cout << values << "������" << i << "��" << endl;
	}

	system("pause");
	return 0;
}

#include<iostream>
using namespace std;
//����������������ӡ��������֮�������

int main()
{
	int x;
	int y;
	cout << "��������������:" ;
	cin >> x >> y;
	//Ӧ�����������  1�Ǵ�С����2�ǴӴ�С
	//��С����
	if (x < y)
	{
		for (int i = x;i <= y;i++)
			{
				cout << i << '\t';
			}
	}

	//�Ӵ�С
	else
	{
		for (int i = x;i >= y;i--)
		{
			cout << i << '\t';
		}
	}
	
	system("pause");
	return 0;
}
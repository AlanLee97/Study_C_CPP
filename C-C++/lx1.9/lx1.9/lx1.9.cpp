#include<iostream>
using namespace std;
//ʹ��whileѭ����50�ӵ�100
int main()
{
	int sum = 50;
	/*  //����һ
	for (int i = 0;i <= 100;i++)
	{
		sum += i;
	}
	cout << "50+51+52+53+...+100=" << sum << endl;
	*/

	//������
	int i = 50;
	while (i <= 100)
	{
		sum += i;
		i++;
	}
	cout << "50+51+52+53+...+100=" << sum << endl;
	system("pause");
	return 0;
}

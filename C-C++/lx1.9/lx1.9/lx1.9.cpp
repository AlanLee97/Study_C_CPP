#include<iostream>
using namespace std;
//使用while循环从50加到100
int main()
{
	int sum = 50;
	/*  //方法一
	for (int i = 0;i <= 100;i++)
	{
		sum += i;
	}
	cout << "50+51+52+53+...+100=" << sum << endl;
	*/

	//方法二
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

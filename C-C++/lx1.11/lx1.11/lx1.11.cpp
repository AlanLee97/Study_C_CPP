#include<iostream>
using namespace std;
//输入两个整数，打印这两个数之间的整数

int main()
{
	int x;
	int y;
	cout << "请输入两个整数:" ;
	cin >> x >> y;
	//应考虑两种情况  1是从小到大，2是从大到小
	//从小到大
	if (x < y)
	{
		for (int i = x;i <= y;i++)
			{
				cout << i << '\t';
			}
	}

	//从大到小
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
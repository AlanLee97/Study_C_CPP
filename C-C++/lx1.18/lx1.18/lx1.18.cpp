#include<iostream>
using namespace std;
//计算输入的相同的值出现多少次

int main()
{
	int values=0;
	int num = 0;
	cout << "请输入一串整数：";
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
				cout << values << "出现了" << i << "次" << endl;
			}
			values = num;
			i = 1;
		}
		cout << values << "出现了" << i << "次" << endl;
	}

	system("pause");
	return 0;
}

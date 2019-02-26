#include<iostream>
using namespace std;
//使用递减运算符在循环中按递减顺序打印出10到0之间的数。
int main()
{
	int i = 10;
	while (i >= 0)
	{
		cout << i << endl;
		i--;
	}
	system("pause");
	return 0;
}

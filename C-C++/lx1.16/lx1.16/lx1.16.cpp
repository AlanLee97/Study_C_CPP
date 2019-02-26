#include<iostream>
using namespace std;
//输入一组整数，求其和

int main()
{
	int values;
	int sum = 0;
	cout << "输入一组整数，求其和(按ctrl+z+enter结束):";
	for (;cin >> values;)
	{
		sum += values;
	}
	cout << "这些数的和为：" << sum << endl;

	system("pause");
	return 0;
}
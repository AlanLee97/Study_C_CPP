#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double a, b, c, disc;
	
	cout << "请输入三个数：" << endl;
	cin >> a >> b >> c;
	disc = b * b - (4 * a*c);
	if (a == 0)
		cerr << "a=0,错误！" << endl;
	else if (disc < 0)
		cerr << "判别式小于0，,错误！" << endl;
	else
	{
		cout << "x1=" << (-b + sqrt(disc)) / (2 * a) << endl;
		cout << "x2=" << (-b - sqrt(disc)) / (2 * a) << endl;
	}
	system("pause");
	return 0;
}

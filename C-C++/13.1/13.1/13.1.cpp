#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double a, b, c, disc;
	
	cout << "��������������" << endl;
	cin >> a >> b >> c;
	disc = b * b - (4 * a*c);
	if (a == 0)
		cerr << "a=0,����" << endl;
	else if (disc < 0)
		cerr << "�б�ʽС��0��,����" << endl;
	else
	{
		cout << "x1=" << (-b + sqrt(disc)) / (2 * a) << endl;
		cout << "x2=" << (-b - sqrt(disc)) / (2 * a) << endl;
	}
	system("pause");
	return 0;
}

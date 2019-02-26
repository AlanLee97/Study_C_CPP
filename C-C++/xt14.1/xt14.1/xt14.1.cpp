#include<iostream>
#include<cmath>
using namespace std;


int main()
{
	int a, b, c, x1, x2;
	double disc;
	
	cout << "请输入a,b,c三个数" << endl;
	cin >> a>> b>> c;
	disc = b * b - 4 * a*c;
	try
	{
		if (a == 0) throw a;
		else if(disc<=0)
		{
			throw disc;
		}
		else
		{
			x1 =(int)( -b + sqrt(disc));
			x2 = (int)(-b - sqrt(disc));
			cout<<"x1=" << x1 << endl
				<<"x2="<< x2 << endl;
		}
	}
	catch (int a)
	{
		cout << "a=" << a << ",error!" << endl;
	}
	catch (double disc)
	{
		cout << "disc=b*b-4*a*c<=0,error!" << endl;
	}

	system("pause");
	return 0;
}
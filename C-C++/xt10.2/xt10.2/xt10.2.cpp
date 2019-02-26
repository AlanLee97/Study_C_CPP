#include<iostream>
using namespace std;
class Complex
{
protected:
	double real;
	double imag;
public:
	Complex();
	Complex(double r,double i);
	void show();
	Complex operator+(Complex&c2);
	Complex operator-(Complex&c2);
	Complex operator*(Complex&c2);
	Complex operator/(Complex&c2);
};
Complex::Complex()
{
	real = 0;
	imag = 0;
}
Complex::Complex(double r, double i)
{
	real = r;
	imag = i;
}
void Complex::show()
{
	cout << "(" << real << "," << imag << ")" << endl;
}
//重载+运算符
Complex Complex::operator+(Complex&c2)
{
	Complex c;
	c.real = real + c2.real;
	c.imag = imag + c2.imag;
	return c;
}

//重载-运算符
Complex Complex::operator-(Complex&c2)
{
	Complex c;
	c.real = real - c2.real;
	c.imag = imag - c2.imag;
	return c;
}

//重载*运算符
Complex Complex::operator*(Complex&c2)
{
	Complex c;
	c.real = real * c2.real - imag * c2.imag;
	//				a			c				b				d
	//公式(a+bi)(c+di)=(ac-bd)+(bc+ad)i.
	c.imag = imag * c2.real + real * c2.imag;
	return c;
}

//重载/运算符
Complex Complex::operator/(Complex&c2)
{
	Complex c;
	//公式(a+bi)/(c+di)=(ac+bd)/(c^2+d^2) +((bc-ad)/(c^2+d^2))i
	c.real = (real * c2.real + imag * c2.imag) / (c2.real*c2.real + c2.imag*c2.imag);
	c.imag = ((imag*c2.real - real* c2.imag) / (c2.real*c2.real + c2.imag*c2.imag));
	return c;
}

int main()
{
	Complex c1(2, 3), c2(3, 4), c3,c4,c5,c6;
	c3 = c1 + c2;
	c4 = c1 - c2;
	c5 = c1 * c2;
	c6 = c1 / c2;

	cout << "c1=";
	c1.show();

	cout << "c2=";
	c2.show();

	cout << "c3=";
	c3.show();

	cout << "c4=";
	c4.show();

	cout << "c5=";
	c5.show();

	cout << "c6=";
	c6.show();


	system("pause");
	return 0;
}
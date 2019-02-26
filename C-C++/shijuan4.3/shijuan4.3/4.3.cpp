#include<iostream>
using namespace std;
//����һ��Point�࣬������Rectangle���Circle�࣬������������������Area( )
class Point
{
public:
	Point(double a, double b) { x = a;y = b; }
protected:
	double x;
	double y;
};

class Rectangle :public Point
{
public:
	Rectangle(double a,double b,double c,double d):Point(a,b)
	{
		length = c;width = d;
	}
	int Area() { return x * y*length*width; }
protected:
	double length;
	double width;
};

class Circle :public Point
{
public:
	Circle(double a, double b,double r) :Point(a, b) { radius = r; }
	double Area() { return 3.14*radius*radius; }
protected:
	double radius;
};

int main()
{
	Rectangle rec(2, 2, 2, 2);
	cout << "Rectangle's area=" << rec.Area() << endl;

	Circle cir(2, 2, 2);
	cout << "Circle's area=" << cir.Area() << endl;
	system("pause");
	return 0;
}

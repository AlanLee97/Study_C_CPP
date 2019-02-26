#include<iostream>
using namespace std;
class Shape
{
public:
	virtual float area() = 0;
};

//圆形
class Circle :public Shape
{
public:
	Circle(float r):radius(r){}
	virtual float area() { return 3.14*radius*radius; };
protected:
	float radius;
};


//矩形
class Rectangle :public Shape
{
public:
	Rectangle(float a, float b) :x(a), y(b) {}
	virtual float area() { return x * y; };
protected:
	float x;
	float y;
};

//三角形
class Tritangle :public Shape
{
public:
	Tritangle(float w, float h) :width(w), height(h) {}
	virtual float area() { return 0.5*width*height; };
protected:
	float width;
	float height;
};

void printArea(Shape &s)
{
	cout << s.area() << endl;
}

//主函数
int main()
{
	Circle c(2);
	cout << "圆的面积为：" << endl;
	printArea(c);

	Rectangle r(2, 4);
	cout << "矩形的面积为：" << endl;
	printArea(r);

	Tritangle t(5, 3);
	cout << "三角形的面积为：" << endl;
	printArea(t);

	system("pause");
	return 0;
}

#include<iostream>
using namespace std;
class Shape
{
public:
	virtual void printArea()=0;
};

//圆形
class Circle:public Shape
{
public:
	Circle(float r):radius(r){}
	float area() { return 3.14*radius*radius; }
	virtual void printArea()
	{
		cout << "圆形的面积：" << Circle::area() << endl;
	}
protected:
	float radius;
};

//矩形
class Recangle:public Shape
{
public:
	Recangle(float a,float b) :x(a),y(b) {}
	float area() { return x*y; }
	virtual void printArea()
	{
		cout << "矩形的面积：" << area() << endl;
	}
protected:
	float x,y;
};

//三角形
class Triangle:public Shape
{
public:
	Triangle(float w, float h) :width(w), height(h) {}
	float area() { return 0.5*width * height; }
	virtual void printArea()
	{
		cout << "三角形的面积：" << area() << endl;
	}
protected:
	float width, height;
};

int main()
{
	Circle c(2.0);
	c.printArea();

	Recangle r(2.0, 2.0);
	r.printArea();
	
	Triangle t(3.0, 4.0);
	t.printArea();

	system("pause");
	return 0;
}

#include<iostream>
using namespace std;
class Shape
{
public:
	virtual double area()=0;
};

//圆形
class Circle :public Shape
{
public:
	Circle(float r):radius(r){}
	virtual double area() { return 3.14*radius*radius; }
	void show() { cout << "圆形的面积为：" << area() << endl; }
protected:
	float radius;
};

//正方形
class Square :public Shape
{
public:
	Square(float a1) :a(a1) {}
	virtual double area() { return a*a; }
	void show() { cout << "正方形的面积为：" << area() << endl; }
protected:
	float a;
};

//矩形
class Recangle :public Shape
{
public:
	Recangle(float a,float b) :x(a),y(b) {}
	virtual double area() { return x * y; }
	void show() { cout << "矩形的面积为：" << area() << endl; }
protected:
	float x,y;
};

//梯形
class Trapezoid :public Shape
{
public:
	Trapezoid(float uw, float bw,float h) :up_width(uw), bottom_width(bw), height(h){}
	virtual double area() { return ((up_width+ bottom_width) * height)/2; }
	void show() { cout << "梯形的面积为：" << area() << endl; }
protected:
	float up_width,bottom_width, height;
};

//三角形
class Triangle :public Shape
{
public:
	Triangle(float w, float h) :width(w), height(h) {}
	virtual double area() { return 0.5 * width * height; }
	void show() { cout << "三角形的面积为：" << area() << endl; }
protected:
	float width, height;
};

int main()
{
	Circle circle(2.0);
	Square square(2.0);
	Recangle rectangle(2, 4.0);
	Trapezoid trapezoid(2.0, 5.0, 4.0);
	Triangle triangle(2.0, 6.0);

	Shape *pt[5] = { &circle,&square,&rectangle,&trapezoid,&triangle };
	double area = 0.0;
	for (int i = 0; i < 5;i++)
	{
		area += pt[i]->area();
	}
	cout << "总面积=" << area << endl;
	system("pause");
	return 0;
}

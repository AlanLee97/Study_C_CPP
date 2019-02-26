#include<iostream>
using namespace std;
class Shape
{
public:
	virtual double area()=0;
};

//Բ��
class Circle :public Shape
{
public:
	Circle(float r):radius(r){}
	virtual double area() { return 3.14*radius*radius; }
	void show() { cout << "Բ�ε����Ϊ��" << area() << endl; }
protected:
	float radius;
};

//������
class Square :public Shape
{
public:
	Square(float a1) :a(a1) {}
	virtual double area() { return a*a; }
	void show() { cout << "�����ε����Ϊ��" << area() << endl; }
protected:
	float a;
};

//����
class Recangle :public Shape
{
public:
	Recangle(float a,float b) :x(a),y(b) {}
	virtual double area() { return x * y; }
	void show() { cout << "���ε����Ϊ��" << area() << endl; }
protected:
	float x,y;
};

//����
class Trapezoid :public Shape
{
public:
	Trapezoid(float uw, float bw,float h) :up_width(uw), bottom_width(bw), height(h){}
	virtual double area() { return ((up_width+ bottom_width) * height)/2; }
	void show() { cout << "���ε����Ϊ��" << area() << endl; }
protected:
	float up_width,bottom_width, height;
};

//������
class Triangle :public Shape
{
public:
	Triangle(float w, float h) :width(w), height(h) {}
	virtual double area() { return 0.5 * width * height; }
	void show() { cout << "�����ε����Ϊ��" << area() << endl; }
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
	cout << "�����=" << area << endl;
	system("pause");
	return 0;
}

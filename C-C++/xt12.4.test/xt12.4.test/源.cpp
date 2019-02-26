#include<iostream>
using namespace std;
class Shape
{
public:
	virtual void printArea()=0;
};

//Բ��
class Circle:public Shape
{
public:
	Circle(float r):radius(r){}
	float area() { return 3.14*radius*radius; }
	virtual void printArea()
	{
		cout << "Բ�ε������" << Circle::area() << endl;
	}
protected:
	float radius;
};

//����
class Recangle:public Shape
{
public:
	Recangle(float a,float b) :x(a),y(b) {}
	float area() { return x*y; }
	virtual void printArea()
	{
		cout << "���ε������" << area() << endl;
	}
protected:
	float x,y;
};

//������
class Triangle:public Shape
{
public:
	Triangle(float w, float h) :width(w), height(h) {}
	float area() { return 0.5*width * height; }
	virtual void printArea()
	{
		cout << "�����ε������" << area() << endl;
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

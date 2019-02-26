#include<iostream>
using namespace std;
class Shape
{
public:
	virtual float area() = 0;
};

//Բ��
class Circle :public Shape
{
public:
	Circle(float r):radius(r){}
	virtual float area() { return 3.14*radius*radius; };
protected:
	float radius;
};


//����
class Rectangle :public Shape
{
public:
	Rectangle(float a, float b) :x(a), y(b) {}
	virtual float area() { return x * y; };
protected:
	float x;
	float y;
};

//������
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

//������
int main()
{
	Circle c(2);
	cout << "Բ�����Ϊ��" << endl;
	printArea(c);

	Rectangle r(2, 4);
	cout << "���ε����Ϊ��" << endl;
	printArea(r);

	Tritangle t(5, 3);
	cout << "�����ε����Ϊ��" << endl;
	printArea(t);

	system("pause");
	return 0;
}

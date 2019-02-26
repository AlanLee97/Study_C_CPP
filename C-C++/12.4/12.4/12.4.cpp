#include<iostream>
#define pi 3.14159
using namespace std;
class Shape
{
public:
	virtual float area() const { return 0; }
	virtual float volume() const { return 0; }
	virtual void shape_name() const = 0;
};

class Point:public Shape
{
public:
	Point(float x = 0, float y = 0);
	void setPoint(float,float);
	float getX() const { return x; }
	float getY() const { return y; }
	virtual void shape_name() const { cout << "Point:"; }
	friend ostream &operator<<(ostream&, const Point&);

protected:
	float x;
	float y;
};

ostream &operator<<(ostream&output, const Point&p)
{
	output << "[" << p.x << "," << p.y << "]" << endl;
	return output;
}

Point::Point(float a, float b)
{
	x = a;
	y = b;
}

class Circle:public Point
{
public:
	Circle(float x = 0, float y = 0, float r=0);
	void setRadius(float r) { radius = r; }
	float getRadius() const { return radius; }
	virtual float area() const;
	virtual void shape_name() const { cout << "Circle:"; }
	friend ostream &operator<<(ostream&, const Circle&);

protected:
	float radius;
};

ostream &operator<<(ostream&output, const Circle&c)
{
	output << "[" << c.x << "," << c.y << "]" << "r=" << c.radius << endl;
	return output;
}

Circle::Circle(float a, float b, float r):
	Point(a,b),radius(r){}


float Circle::area() const
{
	return pi * radius *radius;
}

class Cylinder:public Circle
{
public:
	Cylinder(float x = 0, float y = 0, float r = 0, int h = 0);
	void setRadius(float r) { radius = r; }
	float getRadius() const { return radius; }
	virtual float area() const;
	virtual float volume() const;
	virtual void shape_name() const { cout << "Cylinder:"; }
	friend ostream &operator<<(ostream&, const Cylinder&);

protected:
	int height;
};

ostream &operator<<(ostream&output, const Cylinder&cy)
{
	output << "[" << cy.x << "," << cy.y << "]" << "r=" << cy.radius
		<< "h=" << cy.height << endl;
	return output;
}

Cylinder::Cylinder(float a, float b, float r, int h):
	Circle(a,b,r),height(h){}

float Cylinder::area() const
{
	return 2 * Circle::area() + 2 * pi * radius *height;
}

float Cylinder::volume() const
{
	return Circle::area()*height;
}

int main()
{
	Point point(1.0, 1.0);
	Circle circle(2.0, 2.0, 2.0);
	Cylinder cylinder(3.0, 3.0, 4.0, 5);
	point.shape_name();
	cout << point << endl;
	circle.shape_name();
	cout << circle << endl;
	cylinder.shape_name();
	cout << cylinder << endl << endl;

	Shape *pt;
	pt = &point;
	pt->shape_name();
	cout << "x=" << point.getX() << ",y=" << point.getY() << "\narea="
		<< pt->area() << "\nvolume=" << pt->volume() << endl << endl;

	pt = &circle;
	pt->shape_name();
	cout << "x=" << circle.getX() << ",y=" << circle.getY() << "\narea="
		<< pt->area() << "\nvolume=" << pt->volume() << endl << endl;

	pt = &cylinder;
	pt->shape_name();
	cout << "x=" << cylinder.getX() << ",y=" << cylinder.getY() << "\narea="
		<< pt->area() << "\nvolume=" << pt->volume() << endl << endl;

	system("pause");
	return 0;
}


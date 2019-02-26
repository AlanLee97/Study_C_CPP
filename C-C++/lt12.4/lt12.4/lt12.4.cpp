#include<iostream>
using namespace std;
class Shape
{
public:
	virtual double area() const { return 0.0; }
	virtual double volume() const { return 0.0; }
	virtual void shapeNmae() const =0;
};

//点类
class Point:public Shape
{
protected:
	double x, y;
public:
	Point(double a,double b) {x = a;y = b;}
	double getX() const { return x; }
	double getY() const { return y; }
	virtual void shapeName() const { cout << "Point:"; }
	friend ostream &operator<<(ostream&, const Point&);
};

ostream &operator<<(ostream&output, const Point &p)
{
	output << "(" << p.x << "," << p.y << ")" << endl << endl;
	return output;
}


//圆类
class Circle :public Point
{
protected:
	double radius;
public:
	Circle(double a, double b, double r) :Point(a, b) { radius = r; }
	void setRadius(double r) { radius = r; }
	double getRadius() const { return radius; }
	virtual double area() const { return 3.14*radius*radius; }
	virtual void shapeName() const { cout << "Circle:" << endl; }
	friend ostream&operator<<(ostream&, const Circle&);
};
ostream &operator<<(ostream&output, const Circle&c)
{
	output << "x=" << c.x << endl
		<< "y=" << c.y << endl
		<< "r=" << c.radius << endl
		<< "area=" << c.area() <<  endl  << endl;
}

//圆柱类
class Cylinder :public Circle
{
protected:
	double height;
public:
	Cylinder(double a, double b, double r,double h) :Circle(a, b, r ) { height=h; }
	void setHeight(double h) { height = h; }
	double getHeight()const { return height; }
	virtual void shapeName() const { cout << "Cylinder:"; }
	virtual double area() const { return 2 * Circle::area() + 2 * 3.14*radius*height; }
	virtual double volume() const { return Circle::area()*height; }
	friend ostream&operator<<(ostream&, const Cylinder &);
};

ostream&operator<<(ostream&output, const Cylinder&cy)
{
	output << "x=" << cy.x << endl
		<< "y=" << cy.y << endl
		<< "r=" << cy.radius << endl
		<< "h=" << cy.height << endl
		<< "area=" << cy.area() << endl
		<< "volume=" << cy.volume() << endl << endl;
}


int main()
{
	Point point(2.0, 2.0);
	Circle circle(3.0, 3.0, 2.0);
	Cylinder cylinder(4.0, 4.0, 4.0, 5.0);
	point.shapeName();
	cout << circle << endl;


	system("pause");
	return 0;
}
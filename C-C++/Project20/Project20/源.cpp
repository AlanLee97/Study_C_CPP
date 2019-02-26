#include<iostream>
using namespace std;
//点Point类
class Point
{
public:
	Point(float x = 0, float y = 0);
	void setPoint(float, float);
	float getX() const { return x; }
	float getY() const { return y; }
	friend ostream& operator<<(ostream&, const Point&);

protected:
	float x, y;
};

Point::Point(float a, float b)
{
	x = a;
	y = b;
}

void Point::setPoint(float a, float b)
{
	x = a;
	y = b;
}

//重载流插入>>
ostream & operator<<(ostream&output, const Point&p)
{
	output << "[" << p.x << "," << p.y << "]" << endl;
	return output;
}

//圆Circle类
class Circle :public Point
{
public:
	Circle(float x = 0, float y = 0, float r = 0);
	void setRadius(float);
	float getRadius() const;
	float area() const;
	friend ostream &operator<<(ostream &, const Circle &);

protected:
	float radius;
};

Circle::Circle(float x, float y, float r) :Point(x, y), radius(r) {}
void Circle::setRadius(float r)
{
	radius = r;
}

float Circle::getRadius() const
{
	return radius;
}

float Circle::area()const
{
	return (3.14159*radius*radius);		//计算圆的面积
}

//重载流插入>>
ostream &operator<<(ostream & output, const Circle&c)
{
	output << "Center:[" << c.x << "," << c.y << "]" << endl << "r:"
		<< c.radius << endl << "circle_area:" << c.area() << endl;
	return (output);
}


//圆柱体Cylinder类
class Cylinder :public Circle
{
public:
	Cylinder(float x , float y , float r , float h );
	void setHeight(float h);
	float getHeight() const;
	float area() const;
	float volume() const;
	friend ostream& operator<<(ostream&, const Cylinder&);
protected:
	float height;
};

Cylinder::Cylinder(float x , float y , float r , float h)
	:Circle(x, y, r) {
	height = h;
}
void Cylinder::setHeight(float h)
{
	height = h;
}

float Cylinder::getHeight() const
{
	return height;
}

float Cylinder::area() const
{
	return (2 * Circle::area() + 2 * 3.14159*radius*height);
}

float Cylinder::volume() const
{
	return (Circle::area()*height);
}

ostream &operator<<(ostream & output, const Cylinder&cy)
{
	output << "Center:[" << cy.x << "," << cy.y << "]" << endl
		<< "r=" << cy.radius << endl
		<< "h=" << cy.getHeight() << endl
		<< "area=" << cy.area() << endl
		<< "volume=" << cy.volume() << endl;
	return (output);
}



int main()
{
	//圆柱的原始数据,创建Cylinder的对象
	cout << "以下是圆柱的数据：" << endl;
	Cylinder cy1(1.0, 1.0, 2.0, 5.0);
	cout << "original data:" << endl;
	cout << "x=" << cy1.getX()
		<< ",y=" << cy1.getY()
		<< ",r=" << cy1.getRadius()
		<< ",area=" << cy1.area()
		<< ",volume=" << cy1.volume() << endl;

	//圆柱的修改后的数据
	cout << "changed data:" << endl;
	cy1.setHeight(15);
	cy1.setRadius(7.5);
	cy1.setPoint(5, 5);
	cout << "new cylinder:" << cy1 << endl;
	Point &pRef = cy1;
	cout << "点的数据:\n" << "\npRef as a point:" << pRef;
	Circle &cRef = cy1;
	cout << "\n圆的数据:" << "\npRef as a Circle:" << cRef;
	system("pause");
	return 0;
}


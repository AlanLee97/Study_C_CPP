#include<iostream>
using namespace std;
class Circle:public Point
{
public:
	Circle(float x = 0, float y = 0,float r=0);
	void setRadius(float r);
	float getRadius() const;
	float area() const;
	friend ostream& operator<<(ostream&, const Circle&);
private:
	float radius;
};

Circle::Circle(float a, float b,float r),Point(a,b),radius(r){}
void Circle::setRadius()
{
	radius = r;
}

float Circle::getRadius() const
{
	return radius;
}

float Circle::area() const
{
	return (3.14159*radius*radius);
}

ostream &operator<<(ostream&output, const Circle &c)
{
	output << "Center=[" << c.x << "," << c.y << "],r=" << c.radius 
			<<",area="<<c.area()<< endl;
	return output;
}

int main()
{
	Circle c(1.0,1.0,2.0);
	cout << "Center=[" << c.getX() << "," << c.getY() << "],r=" << c.getRadius()
		<< ",area=" << c.area() << endl;
	c.setRadius(3.0);
	c.setPoint(2, 2);
	cout << "new_circle:" << c;
	Point &pRef = c;
	cout << "pRef:" << pRef;
	return 0;
}

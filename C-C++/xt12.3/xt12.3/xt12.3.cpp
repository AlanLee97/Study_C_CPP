#include <iostream>
using namespace std;
class Point
{
public:
	Point(int a, int b) { x = a; y = b; }
	virtual ~Point()	//��(2)~Point()
	{
		cout << "ִ��Point������������" << endl;
	}
	//void show() { cout << a1 <<endl; }
protected:
	int x,y;
};

class Circle :public Point
{
public:
	Circle(int a, int b,int r) :Point(x, y) { radius = r; }
	~Circle()
	{
		cout << "ִ��Circle������������" << endl;
	}
private:
	int radius;
};

int main()
{
	//Point point(3212);
	//point.show();
	Point *p = new Circle(1,1,2);
	//Circle *pt = new Circle(1, 1, 2);    //��(2)
	delete p;		//��(2)delete pt;	
	system("pause");
	return 0;

}

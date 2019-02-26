#include <iostream>
using namespace std;
class Point
{
public:
	Point(int a, int b) { x = a; y = b; }
	virtual ~Point()	//题(2)~Point()
	{
		cout << "执行Point的析构函数。" << endl;
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
		cout << "执行Circle的析构函数。" << endl;
	}
private:
	int radius;
};

int main()
{
	//Point point(3212);
	//point.show();
	Point *p = new Circle(1,1,2);
	//Circle *pt = new Circle(1, 1, 2);    //题(2)
	delete p;		//题(2)delete pt;	
	system("pause");
	return 0;

}

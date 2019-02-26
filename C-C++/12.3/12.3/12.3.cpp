#include <iostream>
using namespace std;
class Point
{
public:
	Point(){}
	virtual ~Point()
	{
		cout << "执行Point的析构函数。" << endl;
	}
};

class Circle:public Point
{
public:
	Circle() {}
	~Circle()
	{
		cout << "执行Circle的析构函数。" << endl;
	}
private:
	int radius;
};

int main()
{
	Point *p = new Circle;
	delete p;
	system("pause");
	return 0;
	
}

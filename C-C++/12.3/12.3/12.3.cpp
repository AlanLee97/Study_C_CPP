#include <iostream>
using namespace std;
class Point
{
public:
	Point(){}
	virtual ~Point()
	{
		cout << "ִ��Point������������" << endl;
	}
};

class Circle:public Point
{
public:
	Circle() {}
	~Circle()
	{
		cout << "ִ��Circle������������" << endl;
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

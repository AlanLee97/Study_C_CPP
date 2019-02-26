#include<iostream>
using namespace std;
class Rectangle
{
private:
	int length;
	int width;
	int height;
public:
	Rectangle(int l, int w, int h) { length = l;width = w;height = h; }
	int volume();
};

int Rectangle::volume()
{
	return length * width*height;
}

int main()
{
	Rectangle r1(25, 20, 12);
	cout << "Rectangle1's volume is " << r1.volume() << endl;

	Rectangle r2(20, 14, 10);
	cout << "Rectangle2's volume is " << r2.volume() << endl;

	system("pause");
	return 0;
}
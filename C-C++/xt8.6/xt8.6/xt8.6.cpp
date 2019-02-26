#include<iostream>
using namespace std;
class Rectangle
{
private:
	int length;
	int width;
	int height;
	int volume;
public:
	void setValue();
	int getVolume();
	void showValue();
};

void Rectangle::setValue()
{
	cin >> length >> width >> height;
}

int Rectangle::getVolume()
{
	volume=length * width*height;
	return volume;
}
void Rectangle::showValue()
{
	cout << "Rectangle's volume is " << volume << endl;
}


int main()
{
	Rectangle r;
	r.setValue();
	r.getVolume();
	r.showValue();

	system("pause");
	return 0;
}

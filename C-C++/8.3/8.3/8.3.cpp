#include<iostream>
using namespace std;
class Time
{
private:
	int hour;
	int min;
	int sec;
public:
	void setTime();
	void showTime();
};

void Time::setTime()
{
	cin >> hour >> min >> sec;
}

void Time::showTime()
{
	cout << hour << ":" << min << ":" << sec << endl;
}

int main()
{
	Time t1;
	t1.setTime();
	t1.showTime();

	Time t2;
	t2.setTime();
	t2.showTime();

	system("pause");
	return 0;
}
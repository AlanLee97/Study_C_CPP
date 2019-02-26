#include<iostream>
using namespace std;
class Time
{
private:
	int hour;
	int min;
	int sec;
public:
	Time(int, int, int);
	friend void display(Time&);
};
Time::Time(int h, int m, int s)
{
	hour = h;
	min = m;
	sec = s;
}

void display(Time&t)
{
	cout << t.hour<<":" << t.min<<":" << t.sec << endl;
}

int main()
{
	Time t1(12, 21, 22);
	display(t1);

	system("pause");
	return 0;
}

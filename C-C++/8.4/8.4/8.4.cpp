#include<iostream>
using namespace std;
class arrayMax
{
private:
	int a[10];
	int max;
public:
	void setValue();
	void getMax();
	void showMax();
};
void arrayMax::setValue()
{
	for (int i = 0;i < 10;i++)
	{
		cin >> a[i];
	}
}

void arrayMax::getMax()
{
	max = a[0];
	for (int i = 1;i < 10;i++)
	{
		if (a[i] > max)
			max = a[i];
	}
}

void arrayMax::showMax()
{
	cout << "max=" << max << endl;
}

int main()
{
	arrayMax arr;
	arr.setValue();
	arr.getMax();
	arr.showMax();

	system("pause");
	return 0;
}

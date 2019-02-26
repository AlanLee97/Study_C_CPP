#include<iostream>
using namespace std;
//(���������<<��ʹ֮�ܹ�ʹ��cout��Date������ֵ�����ڸ�ʽ�����
//(��Clock������ֵ��ʱ���ʽ���) 

class Date //����������Date 
{ 
public:
	int days(int year, int month)
	{
		bool leap;
		if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
			leap = true;
		else
			leap = false;
		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
		case 2:
			if (leap) //�Ƿ����� 
				return 29;
			else
				return 28;
			break;
		}
	}
	Date(int y = 1980, int m = 1, int d = 1)
	{
		if (m>12 || m<1)
		{
			cout << "Invalid month!" << endl;
			m = 1;
		}
		if (d>days(y, m))
		{
			cout << "Invalid day!" << endl;
			d = 1;
		}
		day = d;
		year = y;
		month = m;
	}
	void NewDay()
	{
		if (day<days(year, month))
			day++;
		else {
			day = 1;
			month++;
		}
		if (month == 13)
		{
			year++;
			month = 1;
		}
	}
}
void display()
{
	cout << year << "-" << month << "-" << day << endl;
}
friend ostream &operator<<(ostream &output, const Date &d)
{ //<<�����ֻ������Ϊ��ķǳ�Ա���� 
	output << d.year << "-" << d.month << "-" << d.day << endl;
	return output;
}
private:
	int year; //�� 
	int month; //�� 
	int day; //�� 
};
void main()
{
	Date d1(2006, 6, 31);
	cout << d1;

	system("pause");
}

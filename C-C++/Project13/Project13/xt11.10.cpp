#include<iostream>
#include<string>
using namespace std;

class Teacher
{
public:
	Teacher(string nam, int a, string t):name(nam),age(a),title(t){}
	void display()
	{
		
		cout << "name:" << name << endl
			<< "age:" << age << endl
			<< "title:" << title << endl;
	}
protected:
	string name;
	int age;
	string title;
};

class BirthDate
{
public:
	BirthDate(int y,int m,int d):year(y),month(m),day(d){}
	void display1()
	{
		cout << "birthday:" << endl
			<< year << "/" << month << "/" << day << endl;
	}
	void change(int y,int m,int d)
	{
		year = y;
		month = m;
		day = d;
	}
protected:
	int year;
	int month;
	int day;
};

class Professor:public Teacher
{
public:
	Professor(string nam, int a, string t,int y,int m,int d):
		Teacher(nam,a,t),birthday(y,m,d){}
	void show()
	{
		Teacher::display();
		birthday.display1();
	}
	
	/*void change(int y,int m,int d)
	{
		birthday.change(y, m, d);
	}*/
private:
	BirthDate birthday;
};
int main()
{
	Professor prof1("Li", 21, "assitant", 1997, 5, 25);
	BirthDate bir(1990,6,25);
	cout << "原始信息：" << endl;
	prof1.show();
	cout<<endl << "修改后的信息："<< endl;
	prof1.display();
	bir.change(2000,6,7);
	bir.display1();
	system("pause");
}

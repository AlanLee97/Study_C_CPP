#include<iostream>
#include<string>
using namespace std;
class Student
{
public:
	Student(int n, string nam)
	{
		cout << "���캯��" << n << endl;
		num = n;
		name = nam;
	}
	~Student()
	{
		cout << "��������" << num << endl;
	}
	void get_data();
protected:
	int num;
	string name;

};

void Student::get_data()
{
	if (num == 0) throw num;
	else cout << num << " " << name << endl;
	cout << "in get_data()" << endl;
}

void fun()
{
	Student stud1(101, "Li");
	stud1.get_data();
	Student stud2(0, "wang");
	stud2.get_data();
}
int main()
{
	cout << "main������ʼ" << endl;
	cout << "����fun����" << endl;
	try
	{
		fun();
	}
	catch(int n)
	{
		cout << "num=" << n << "����!" << endl;
	}
	cout << "������������" << endl;
	system("pause");
	return 0;
}


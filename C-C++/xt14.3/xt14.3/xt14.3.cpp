#include<iostream>
#include<string>
using namespace std;
class Student
{
public:
	Student(int n, string nam, int a, string addr);
	Student(int n, string nam, int a, double sco);
	
	void showData(int n, string nam, int a, string addr);
	void showData(int n, string nam, int a, double sco);
protected:
	int num;
	string name;
	int age;
	string address;
	double score;
};

Student::Student(int n, string nam, int a, string addr)
{
	num = n;
	name = nam;
	age = a;
	address = addr;
}

Student::Student(int n, string nam, int a, double sco)
{
	num = n;
	name = nam;
	age = a;
	score = sco;
}


void Student::showData(int n, string nam, int a, string addr)
{
	cout << "num:" << num << endl
		<< "name:" << name << endl
		<< "age:" << age << endl
		<< "address:" << address << endl << endl;
}

void Student::showData(int n, string nam, int a, double sco)
{
	cout << "num:" << num << endl
		<< "name:" << name << endl
		<< "age:" << age << endl
		<< "score:" << sco << endl << endl;
}

int main()
{
	Student stud1(1001, "Li", 21,"guangzhou");
	stud1.showData(1001, "Li", 21," guangzhou");

	Student stud2(1002, "wang", 20, 98.5);
	stud2.showData(1002, "wang", 20, 98.5);

	system("pause");
	return 0;
}
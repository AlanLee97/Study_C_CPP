#include<iostream>
#include<string>
using namespace std;
class Student
{
protected:
	int num;
	string name;
	int age;
public:
	Student(int n,string nam,int a):num(n),name(nam),age(a) {}
	virtual void display()
	{
		cout << "num:" << num << endl
			<< "name:" << name << endl
			<< "age:" << age << endl << endl;
	}
};

class Graduate:public Student
{
protected:
	string address;
public:
	Graduate(int n, string nam, int a, string addr) :Student(n, nam, a) { address = addr; };
	void display()
	{
		cout << "num:" << num << endl
			<< "name:" << name << endl
			<< "age:" << age << endl 
			<< "address:" << address << endl << endl;
	}
};

int main()
{
	Student stud(1001, "Li", 20);
	Graduate grad(1001, "Li", 21, "guangzhou");
	Student *pt;
	pt = &stud;
	pt->display();

	pt = &grad;
	pt->display();

	system("pause");
	return 0;
}



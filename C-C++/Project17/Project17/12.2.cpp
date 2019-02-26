#include<iostream>
#include<string>
using namespace std;
class Student
{
public:
	Student(int n, string nam, float sco);
	virtual void display();    //虚函数
protected:
	int num;
	string name;
	float score;
};

Student::Student(int n,string nam,float sco):num(n),name(nam),score(sco){}
void Student::display()
{
	cout << "学号：" << num << endl
		<< "姓名：" << name << endl
		<< "成绩：" << score << endl << endl;
}

class Graduate :public Student
{
public:
	Graduate(int n, string nam, float sco, float w);
	void display();
protected:
	float wage;
};

Graduate::Graduate(int n,string nam,float sco,float w):Student(n,nam,sco),wage(w){}
void Graduate::display()
{
	cout << "学号：" << num << endl
		<< "姓名：" << name << endl
		<< "成绩：" << score << endl
		<< "工资：" << wage << endl << endl;
}

int main()
{
	Student stud(1001, "Li", 90.0);
	Graduate grad(1001, "Li", 90.0, 3000.0);
	Student *pt=&stud;
	pt->display();
	pt = &grad;
	pt->display();
	system("pause");
	return 0;
	
}

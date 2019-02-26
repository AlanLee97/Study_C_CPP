#include<iostream>
#include<string>
using namespace std;
class Student
{
protected:
	int num;
	string name;
public:
	Student(int n, string nam) { num = n;name = nam; }
	void display()
	{
		cout << "num:" << num << endl;
		cout << "name:" << name << endl;
	}
};

class Student1 :public Student
{
protected:
	int age;
public:
	Student1(int n, string nam, int a) :Student(n, nam) { age = a; }
	void show()
	{
		display();
		cout << "age:" << age << endl;
	}
};

class Student2 :public Student1
{
protected:
	int score;
public:
	Student2(int n, string nam, int a, int sco) :Student1(n, nam, a) { score = sco; }
	void show_all()
	{
		show();
		cout << "score:" << score << endl;
	}
};
int main()
{
	Student2 stud(1001, "Li", 21, 90);
	stud.show_all();
	system("pause");
	return 0;
}

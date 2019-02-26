#include<iostream>
#include<string>
using namespace std;
class Teacher
{
public:
	Teacher(string nam, int a, string t)
	{
		name = nam;
		age = a;
		title = t;
	}
	void disply();
protected:
	string name;
	int age;
	string title;
};
void Teacher::disply()
{
	cout << "name:" << name << endl
		<< "age:" << age << endl
		<< "title:" << title << endl;
}

class Student
{
public:
	Student(string nam,char s,float sco):name(nam),sex(s),score(sco){}
	void display1();
	

protected:
	string name;
	char sex;
	float score;
};

void Student::display1()
{
	cout << "name:" << name << endl
		<< "sex:" << sex << endl
		<< "score:" << score << endl;
}

class Graduate :public Teacher,public Student
{
public:
	Graduate(string nam,int a,char s,string t,float sco,float w):
		Teacher(nam,a,t),Student(nam,s,sco),wage(w){}
	void show()
	{
		cout << "name:" << Teacher::name << endl
			<< "age:" << age << endl
			<< "sex:" << sex << endl
			<< "score:" << score << endl
			<< "title:" << title << endl
			<< "wages:" << wage << endl;
	}

private:
	float wage;
};

int main()
{
	Graduate grad("Li", 24, 'm', "assitant", 89.5, 1200);
	grad.show();
	system("pause");
	return 0;
}




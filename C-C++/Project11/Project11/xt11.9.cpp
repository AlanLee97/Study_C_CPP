#include <iostream>
#include <string>
using namespace std;
class Teacher
{
public:
	Teacher(string nam, int a, char s, string ad, int tel, string tit)
	{
		name = nam;
		age = a;
		sex = s;
		addr = ad;
		tele = tel;
		title = tit;
	}
	void display();

protected:
	string name;
	int age;
	char sex;
	string addr;
	int tele;
	string title;
};
void Teacher::display()
{
	cout << "name:" << name << endl
		<< "age:" << age << endl
		<< "sex:" << sex << endl
		<< "address:" << addr << endl
		<< "telephone:" << tele << endl
		<< "title:" << title << endl << endl;
}

class Cadre
{
public:
	Cadre(string nam, int a, char s, string ad, int tel, string po)
	{
		name = nam;
		age = a;
		sex = s;
		addr = ad;
		tele = tel;
		post = po;
	}
	void display();

protected:
	string name;
	int age;
	char sex;
	string addr;
	int tele;
	string post;
};

void Cadre::display()
{
	cout << "name:" << name << endl
		<< "age:" << age << endl
		<< "sex:" << sex << endl
		<< "address:" << addr << endl
		<< "telephone:" << tele << endl
		<< "post:" << post << endl << endl;
}

class Teacher_Cadre :public Teacher, public Cadre
{
public:
	Teacher_Cadre(string nam, int a, char s, string ad, int tel, string po, string tit, double w) :
		Teacher(nam, a, s, ad, tel, tit),
		Cadre(nam, a, s, ad, tel, po), wage(w) {}
	void show();

private:
	double wage;
};

void Teacher_Cadre::show()
{
	Teacher::display();
	cout << post << endl
		<< wage << endl << endl;
}
int main(int argc, char *argv[])
{
	Teacher_Cadre TC("Li", 21, 'm', "guangzhou", 123456, "teacher", "senior_teacher", 8000.0);
	TC.show();
	system("pause");
	return 0;
}

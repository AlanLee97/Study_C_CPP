#include<iostream>
#include<string>
using namespace std;

class Teacher{
protected:
	string name;
	int age;
	char sex;
	string address;
	string tel;
	string title;
public:
	Teacher(string n,int a,char s,string add,string te,string tit)
	:name(n),age(a),sex(s),address(add),tel(te),title(tit){}
	void display() {
		cout << "姓名：" << name << endl
			<< "年龄：" << age << endl
			<< "性别：" << sex << endl
			<< "地址：" << address << endl
			<< "电话：" << tel << endl
			<< "职称：" << title << endl
			<< endl;
	}
};

class Cadre {
protected:
	string name;
	int age;
	char sex;
	string address;
	string tel;
	string post;
public:
	Cadre(string n, int a, char s, string add, string te, string po) :
		name(n), age(a), sex(s), address(add), tel(te), post(po){}
};

class Teacher_Cadre :public Teacher,public Cadre{
private:
	int wages;
public:
	Teacher_Cadre(string n, int a, char s, string add, string te,
		string tit, string po, int w):Teacher(n,a,s,add,te,tit),
		Cadre(n, a, s, add, te, po),wages(w){}
	void show() {
		Teacher::display();
		cout << "职务：" << post << endl
			<< "工资：" << wages << endl << endl;
	}
};

int main() {
	Teacher_Cadre tc("Li",22,'M',"广州","3331556","高级教师","班主任",6000);
	tc.show();
	system("pause");
	return 0;
}

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
		cout << "������" << name << endl
			<< "���䣺" << age << endl
			<< "�Ա�" << sex << endl
			<< "��ַ��" << address << endl
			<< "�绰��" << tel << endl
			<< "ְ�ƣ�" << title << endl
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
		cout << "ְ��" << post << endl
			<< "���ʣ�" << wages << endl << endl;
	}
};

int main() {
	Teacher_Cadre tc("Li",22,'M',"����","3331556","�߼���ʦ","������",6000);
	tc.show();
	system("pause");
	return 0;
}

#include<fstream>
#include<iostream>
#include<string>
using namespace std;

struct student
{
	string name;
	int num;
	int age;
	char sex;
};

int main()
{
	student stud[3];
	int i;
	ifstream infile("stud.dat", ios::binary);
	if (!infile)
	{
		cerr << "打开文件错误。" << endl;
		abort();
	}
	for (i = 0;i < 3;i++)
	{
		infile.read((char *)&stud[i], sizeof(stud[i]));
	}
	infile.close();

	for (i = 0;i < 3;i++)
	{
		cout << "NO." << i + 1 << endl;
		cout << "name:" << stud[i].name << endl;
		cout << "num:" << stud[i].num << endl;
		cout << "age:" << stud[i].age << endl;
		cout << "sex:" << stud[i].sex << endl << endl;
	}

	system("pause");
	return 0;
}

#include<iostream>
#include<fstream>
using namespace std;

struct Student
{
	char name[20];
	int num;
	int age;
	char sex;
};

int main()
{
	Student stud[3] = { "Li",1001,20,'m',"Fang",1002,21,'f',"Wang",1003,20,'m' };
	ofstream outfile("stud.dat",ios::binary);//, 
	if (!outfile)
	{
		cerr << "打开文件错误。" << endl;
		abort();
	}
	for (int i = 0;i < 3;i++)
	{
		outfile.write((char *)&stud[i], sizeof(stud[i]));

	}
	outfile.close();
	system("pause");
	return 0;
}

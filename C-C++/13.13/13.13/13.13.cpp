#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
struct student
{
	int num;
	char name[20];
	double score;
};

int main()
{
	student stud[5] =
	{
		1001,"Li",81,
		1002,"Fang",82,
		1003,"Wan",83,
		1004,"Tan",84,
		1005,"Ling",85
	};
	fstream iofile("stud.dat", ios::in | ios::out | ios::binary);
	//用fstream类定义输入输出文件流对象
	if (!iofile)
	{
		cerr << "打开文件错误！" << endl;
		abort();
	}
	
	//向磁盘文件输出5个学生的数据
	for (int i = 0;i < 5;i++)
	{
		iofile.write((char *)&stud[i], sizeof(stud[i]));
	}
	student stud_new[5];
	for (int i = 0;i < 5;i = i + 2)
	{
		iofile.seekg(i * sizeof(stud[i]), ios::beg);
		iofile.read((char *)&stud_new[i / 2], sizeof(stud_new[0]));
		cout << stud_new[i / 2].num << " "
			<< stud_new[i / 2].name << " "
			<< stud_new[i / 2].score << " " << endl;
	}
	cout << endl;
	stud[2].num = 1012;
	strcpy(stud[2].name, "Wu");
	stud[2].score = 60;
	iofile.seekp(2 * sizeof(stud[0]), ios::beg);
	iofile.read((char*)&stud[2], sizeof(stud[2]));
	iofile.seekg(0, ios::beg);
	for (int i = 0;i < 5;i++)
	{
		iofile.read((char*)&stud[i], sizeof(stud[i]));
		cout << stud[i].num << " "
			<< stud[i].name << " "
			<< stud[i].score << " " << endl;
	}
	iofile.close();
	system("pause");
	return 0;
}

#include<strstream>
#include<iostream>
using namespace std;
struct student
{
	int num;
	char name[20];
	double score;
};

int main()
{
	student stud[3] = { 1001,"Li",91.5,1002,"wang",92.5,1003,"tan",93.5 };
	char c[50];
	ostrstream strout(c, 30);
	for (int i = 0;i < 3; i++)
	{
		strout << stud[i].num << stud[i].name << stud[i].score;
	}
	strout << ends;		//ends是C++的I/O操作符，插入一个'\0'
	cout << "array c:" << c << endl;

	system("pause");
	return 0;
}

#include<iostream>
using namespace std;
class Student
{

public:
	int num;
	double score;
	Student(int n, double sco) { num = n;score = sco; }
	
};
void max(Student *arr)
{
	double scoreMax = arr[0].score;
	int k = 0;
	for (int i = 1;i < 5;i++)
		if (arr[i].score > scoreMax)
		{
			scoreMax = arr[i].score;
			k = i;
		}
	cout << "num:" << arr[k].num << endl
		<< "max score is:" << scoreMax << endl;
}

int main()
{
	Student stud[5] =
	{
		Student(1001,91.5),
		Student(1002,92.5),
		Student(1003,93.5),
		Student(1004,94.5),
		Student(1005,95.5)
	};
	Student *pt =& stud[0];
	max(pt);
	system("pause");
	return 0;
}


#include<iostream>
using namespace std;
int main()
{
	int c;
	cout << "请输入一个句子：" << endl;
	c = cin.get();
	while (c != EOF)
	{
		cout.put(c);
	}
	return 0;
}

#include<iostream>
using namespace std;
int main()
{
	int c;
	cout << "请输入一个句子：" << endl;
	
	while ((c=cin.get()) != EOF)
	{
		cout.put(c);
	}
	return 0;
}

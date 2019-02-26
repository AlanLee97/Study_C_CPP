#include<fstream>
//#include<iostream>
using namespace std;
void save_to_file()
{
	ofstream outfile("f2.dat");
	if (!outfile)
	{
		cerr << "open error" << endl;
		exit(1);
	}
	char c[80];
	cin.getline(c, 80);
	for (int i = 0;c[i] != 0;i++)
	{
		if (c[i] >= 65 && c[1] <= 90 || c[i] >= 97 && c[1] <= 122)
		{
			outfile.put(c[i]);
			cout << c[i];
		}
	}
	cout << endl;
	outfile.close();
}
void stob()
{
	char a;
	ifstream infile("f2.dat", ios::in);
	if (!infile)
	{
		cerr << "open f2 error" << endl;
		exit(1);
	}
	while (!EOF)
	{
		cin.get(a);
		if (a >= 97 && a <= 122)
			a = a - 32;
		outfile.put(a);
		cout << a;
	}
	cout << endl;
	infile.close();
	outfile.close();
}
int main()
{
	save_to_file();
	stob();
	system("pause");
	return 0;
}

#include<iostream>
using namespace std;

int fun(int m, int n) {
	int N = 0;
	for (n = 0; n <= m; n++, m--) {
		N = m + n;
		
		cout << "\t" << N << "=" << m << "+" << n;
		if (N == 6) cout << endl;
		if (n > 1) {
			if (m == 1 && n == 1) {
				cout << endl;
				return 1;
			}
			N = m + fun(n, 0);
		}
	}
}

int main()
{
	fun(6, 0);

	cout << endl;
	system("pause");
	return 0;
}


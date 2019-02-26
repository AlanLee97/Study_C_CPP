#include <iostream>
#define MAX 20
using namespace std;

int n = 0, bagW = 0;//物品种数n，背包重量bagW
int w[MAX], v[MAX], m[MAX][MAX] = { 0 };

void disp() {
	int i = 0;
	for (i = 0; i <= n; i++) {
		if (m[i][bagW] != m[i + 1][bagW]) {
			cout << "\n\t重量：" << w[i] 
				<< "\n"
				<< "\t价值：" << v[i];
		}
	}
}

void func() {
	int i, j;
	for (j = w[n]; j <= bagW; j++) {
		m[n][j] = v[n];
	}
	for (i = n - 1; i >= 1; i--) {
		for (j = w[i]; j <= bagW; j++){
			if (m[i + 1][j] > m[i + 1][j - w[i]] + v[i]) {
				m[i][j] = m[i + 1][j];
			}
			else {
				m[i][j] = m[i + 1][j - w[i]] + v[i];
			}
		}
	}
}


int main()
{
	
	int i, j;
	cout << "请输入物品总数：";
	cin >> n;
	cout << "\n输入每种物品的重量和价值：" << endl;
	for (i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}
	cout << "\n输入背包的总重量：";
	cin >> bagW;

	func();
	disp();
	cout << "\n物品最大的价值为：" << m[1][bagW] << endl;
	
	cout << endl;
	system("pause");
	return 0;
}

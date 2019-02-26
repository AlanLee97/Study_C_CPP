#include<iostream>
#include<cmath>
using namespace std;
double a, b;
int solution(double a,double b, double c, double &x1,double &x2){
	double d = b * b - 4 * a * c;
	if (d > 0) {
		x1 = (-b + sqrt(d)) / (2 * a);
		x2 = (-b - sqrt(d)) / (2 * a);
		return 2;
	}
	else if(d == 0){
		x1 = (-b) / (2 * a); 
		return 1;
	}
	else {
		return 0;
	}

	return 0;
}


int main() {
	
	cout << "方程根的数量：" << endl;
	solution(2,4,1,a,b);
	system("pause");
}

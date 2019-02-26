#include<stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int a[10], b = 0;
	int n1, n2, n3, n4;
	scanf_s("%d-%d-%d-%d", &n1, &n2, &n3, &n4);

	a[0] = n1;
	//0 - 670 - 82162 - 4
	//670
	a[1] = n2 / 100;						
	a[2] = (n2 % 100) / 10;			
	a[3] = (n2 % 100) % 10;				
	
	//82162
	a[4] = n3 / 10000;									//8
	a[5] = (n3 / 1000) % 10;							//2
	a[6] = ((n3 / 100) % 100) % 10;						//1
	a[7] = (((n3 / 10) % 1000) % 100) % 10;				//6
	a[8] = (((n3 % 10000) % 1000) % 100) % 10;			//2

	a[9] = n4;

	for (int i = 0; i < 9; i++) {
		b += a[i] * (i + 1);
	}

	int end_mod = b % 11;
	
	if (end_mod == n4) {
		printf("Right!");
	}
	else {
		printf("\n识别码不正确。\n\n正确的结果为：\n");
		if (end_mod == 10) {
			printf("%d-%d%d%d-%d%d%d%d%d-X", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8]);
		}
		else {
			printf("%d-%d%d%d-%d%d%d%d%d-%d", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], end_mod);
		}
	}

	printf("\n\n");
	system("pause");
	return 0;
}

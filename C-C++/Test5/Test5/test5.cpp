#include <iostream>
#include "gongneng.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
	linknode *l;
	linknode *ll;
	int x[10] = { 75,5,32,2,56,89 };
	int y[10] = { 61,28,37,45,5,36,89 };

	createlist(l, x, 6);
	cout << "A: ";
	display(l);

	createlist(ll, y, 7);
	cout << "B: ";
	display(ll);

	cout << "A¡ÈB: ";
	chachong(l,ll);
	listinsert(l, ll);
	display(l);

	system("pause");
	return 0;
}

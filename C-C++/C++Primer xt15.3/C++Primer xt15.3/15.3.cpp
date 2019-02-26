#include<iostream>
#include<string>
using namespace std;
class Quote
{
public:
	Quote();
	Quote(string isbn,double p):book_isbnNo(isbn),price(p){}
	string isbn() { return book_isbnNo; }
	virtual double work_price(int n) { return n * price; }
	virtual ~Quote()=default;
protected:
	string book_isbnNo;
	double price;
};

double print_total(ostream &output, Quote &quote, int n)
{
	double rec = quote.work_price(n);
	output << "ISBN:" << quote.isbn() << endl
		<< "sold num:" << n << endl
		<< "get total prices:" << rec << endl;
	return rec;
}

int main()
{
	int c;
	Quote q("123-4-567-890", 54.0);
	//print_total(cout,q,3);
	c = print_total(cout, q, 3);
	cout << endl << c << endl;
	system("pause");
	return 0;
}

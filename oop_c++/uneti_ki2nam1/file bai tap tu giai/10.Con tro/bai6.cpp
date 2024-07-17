#include<iostream>
using namespace std;

int main()
{
	int a, b, c, *aPrt, *bPrt, *cPrt;
	cout << "Nhap a = ";
	cin >> a;
	cout << "Nhap b = ";
	cin >> b;
	cout << "Nhap c = ";
	cin >> c;
	aPrt = &a;
	bPrt = &b;
	cPrt = &c;
	int max = *aPrt;
	if (max < *bPrt)
		max = *bPrt;
	if (max < *cPrt)
		max = *cPrt;
	cout << "Gia tri lon nhat trong ba so "<<a<<", "<<b<<", "<<c<<" la : "<<max<<endl;
	return 0;
}


#include<iostream>
using namespace std;

int main()
{
	int a, b, *aPrt, *bPrt;
	cout << "Nhap a = "; 
	cin >> a;
	cout << "Nhap b = ";
	cin >> b;
	aPrt = &a; // con tro aPrt tro vao bien a
	bPrt = &b; // con tro bPrt tro vao bien b
	int sum; // bien sum de chua tong
	sum = *aPrt + *bPrt;
	cout << "Tong cua 2 so la: "<<sum<<endl;
	return 0;
}


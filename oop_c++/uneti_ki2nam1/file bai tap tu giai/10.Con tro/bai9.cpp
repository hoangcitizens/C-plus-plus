#include<iostream>
using namespace std;

int main()
{
	int x, *xPrt, P = 1;
	cout << "Nhap x = ";
	cin >> x;
	xPrt = &x;
	for (int i=1; i<=*xPrt; i++)
		P *= i;
	cout << "Giai thua cua "<<x<<" la P = "<<P<<endl;
	return 0;
}


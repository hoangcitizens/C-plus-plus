#include<iostream>
using namespace std;

template <class T>
T Max(T a, T b, T c)
{
	T max = a;
	if (b > max)
		return b;
	else if (c > max)
		return c;
	else
		return a;
}

int main()
{
	int a, b, c;
	cout << "Nhap a = "; cin >> a;
	cout << "Nhap b = "; cin >> b;
	cout << "Nhap c = "; cin >> c;
	cout << "Gia tri max trong 3 so la: " << Max(a, b, c) << endl;
	return 0;
}
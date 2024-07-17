#include<iostream>
using namespace std;

int kiemTraSoNguyenTo(int x)
{
	int S = 0;
	for (int i = 1; i <= x; i++)
	{
		if (x % i == 0)
			S++;
	}
	if (S == 2)
		return 1;
	return 0;
}

int main()
{
	unsigned int n;
	cout << "Nhap vao so nguyen duong n = ";
	cin >> n;
	cout << "Cac so nguyen to trong pham vi " << n << " la : " << endl;
	for (int i = 1; i <= n; i++)
	{
		if (kiemTraSoNguyenTo(i) == 1)
			cout << i << "  ";
	}
	return 0;
}

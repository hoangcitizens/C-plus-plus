#include<iostream>
using namespace std;

float giaiThua(int x)
{
	if (x == 0)
		return 1;
	else
		return giaiThua(x-1) * x;
}

int main()
{
	unsigned int n, k;
	cout << "Nhap n = "; 
	cin >> n;
	cout << "Nhap k = "; 
	cin >> k;
	while (k > n)
	{
		cout << "Nhap lai k < n: ";
		cin >> k;
	}
	float C = giaiThua(n)/(giaiThua(k)*giaiThua(n-k));
	cout << "To hop chap " << k << " cua " << n << " la : " << C << endl;
	return 0;
}


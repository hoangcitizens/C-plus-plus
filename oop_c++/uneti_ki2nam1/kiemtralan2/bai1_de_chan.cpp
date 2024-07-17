// Nguyen Huu Hoang - 21103100320
// Bai 1 - de chan
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int k, n;
	cout << "Nhap k = ";
	cin >> k;
	while(k<0)
	{
		cout << "Nhap lai k = ";
		cin >> k;
	}
	cout << "Nhap so lan can bac 2: ";
	cin >> n;
	while(n<0)
	{
		cout << "Nhap lai so lan can bac 2: ";
		cin >> n;
	}
	double sum = 0;
	for (int i = 1; i <= n; i++)
		sum = sqrt(k + sum);
	cout << "S = " << sum << endl;
	return 0;
}


#include<iostream>
#include<math.h>
using namespace std;
/*
	n! = 1        voi n = 0
	n! = n*(n-1)! voi n > 0
*/

float giai_thua(int n)
{
	if (n == 0)
		return 1;
	else
		return n * giai_thua(n - 1);
}

int main()
{
	int n; 
	cout << "Nhap n = "; cin >> n;
	cout << "Vay " << n << "! = " << giai_thua(n) << endl;
	return 0;
}
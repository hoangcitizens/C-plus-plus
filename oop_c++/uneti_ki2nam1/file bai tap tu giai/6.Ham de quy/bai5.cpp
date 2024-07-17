#include<iostream>
#include <math.h>
using namespace std;

long x(int n)
{
	if (n == 0)
		return 1;
	long S = 0;
	for (int i=0; i<n; i++)
		S = S + pow(n-i,2)*x(i);
	return S;
}

int main()
{
	int n;
	float xn;
	cout << "Nhap n = "; 
	cin >> n;
	cout << "Vay x(" << n << ") = "<<x(n)<<endl;
	return 0;
}


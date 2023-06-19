/*
	fib(n) = 1                     voi n <= 2
	fib(n) = fib(n-1) + fib(n-2)   voi n > 2
	VD: fib(10) = 1, 1, 2, 3, 5, 8, 13, 21, 34, 55
*/
#include<iostream>
#include<math.h>
using namespace std;

long fib(int n)
{
	if (n <= 2)
		return n;
	else
		return (fib(n-1) + fib(n - 2));
}

int main()
{
	int n;
	cout << "Nhap n = "; cin >> n;
	cout << n << " so dau trong chuoi Fibonaci la fib(" << n << ") = ";
	for (int i = 0; i < n; i++)
	{
		cout << fib(i) << ", ";
	}
	cout << endl;
	return 0;
}
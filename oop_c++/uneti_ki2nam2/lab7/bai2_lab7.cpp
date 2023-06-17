#include<iostream>
#include<math.h>
#include<string>
using namespace std;

template <class T>
void import(T a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i << "] = "; cin >> a[i];
	}
}
template <class T>
void display(T a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ", ";
	}
}
template <class T>
T sumArray(T a[], int n)
{
	T S = 0;
	for (int i = 0; i < n; i++)
	{
		S += a[i];
	}
	return S;
}

int main()
{
	int n; cout << "Nhap so phan tu cua mang: "; cin >> n;
	int a[50];
	import(a, n);
	cout << "Phan tu trong mang la: "; display(a, n); cout << endl;
	cout << "Tong cua " << n << " phan tu trong mang la: " << sumArray(a,n) << endl;
	return 0;
}
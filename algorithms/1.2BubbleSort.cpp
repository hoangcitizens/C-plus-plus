// Sap xep noi bot (Bubble Sort)

#include<iostream>
#include<string>
#include<math.h>
using namespace std;

void nhap(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i << "] = ";
		cin >> a[i];
	}
}
void xuat(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "   ";
	}
}
void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = n-1; j > i; j--)
		{
			if (a[j] < a[j-1]) // sap xep tang dan
				swap(a[j], a[j-1]);
		}
	}
}

int main()
{
	int a[20], n;
	cout << "Nhap so phan tu cua mang: "; cin >> n;
	nhap(a, n);
	cout << "Mang truoc khi sap xep: ";
	xuat(a, n);
	BubbleSort(a, n);
	cout << "\nMang sau khi sap xep bang Bubble Sort: ";
	xuat(a, n);
	return 0;
}
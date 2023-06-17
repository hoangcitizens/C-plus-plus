// Sap xep lua chon (Selection Sort)

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
void SelectionSort(int a[], int n)
{
	int min; // luu chi so phan tu nho nhat
	for (int i = 0; i < n-1; i++)
	{
		min = i;
		for (int j = i+1; j < n; j++)
		{
			if (a[min] > a[j]) // sap xep tang dan
				min = j;
		}
		if (i != min)
			swap(a[min], a[i]);
	}
}
int main()
{
	int a[20], n;
	cout << "Nhap so phan tu cua mang: "; cin >> n;
	nhap(a, n);
	cout << "Mang truoc khi sap xep: ";
	xuat(a, n);
	SelectionSort(a, n);
	cout << "\nMang sau khi sap xep bang Selection Sort: ";
	xuat(a, n);
	return 0;
}
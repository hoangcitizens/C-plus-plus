// Sap xep chen(them) (Insertion Sort)

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
void InsertionSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int x = a[i], pos = i - 1; // x luu phan tu a[i]
		while ((pos >= 0) && (a[pos] > x)) // sap xep tang dan
		{
			a[pos + 1] = a[pos]; // doi cho cac phan tu dung sau x
			pos--;
		}
		a[pos + 1] = x; // chen x vao day moi
	}
}

int main()
{
	int a[20], n;
	cout << "Nhap so phan tu cua mang: "; cin >> n;
	nhap(a, n);
	cout << "Mang truoc khi sap xep: ";
	xuat(a, n);
	InsertionSort(a, n);
	cout << "\nMang sau khi sap xep bang Insertion Sort: ";
	xuat(a, n);
	return 0;
}
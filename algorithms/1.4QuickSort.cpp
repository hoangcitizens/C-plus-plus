// Sap xep nhanh (Quick Sort)

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
void QuickSort(int a[], int left, int right)
{
	int i = left;
	int j = right;
	int x = a[(left + right) / 2];
	do {
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++; // qua phan tu ke tiep
			j--; // qua phan tu dung truoc
		}
	} while (i < j);
	if (left < j) // ph doan ben trai
		QuickSort(a, left, j);
	if (right > i) // ph doan ben phai
		QuickSort(a, i, right);
}
int main()
{
	int a[20], n;
	cout << "Nhap so phan tu cua mang: "; cin >> n;
	nhap(a, n);
	cout << "Mang truoc khi sap xep: ";
	xuat(a, n);
	QuickSort(a, 0, n-1);
	cout << "\nMang sau khi sap xep bang Quick Sort: ";
	xuat(a, n);
	return 0;
}
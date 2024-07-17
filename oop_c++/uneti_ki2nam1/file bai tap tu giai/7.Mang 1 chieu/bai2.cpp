#include<iostream>
using namespace std;

void nhap(int a[], int n)
{
	for (int i=1; i<=n; i++)
	{
		cout << "Nhap a["<<i<<"] = ";
		cin >> a[i];
	}
}
void xuat(int a[], int n)
{
	for (int i=1; i<=n; i++)
		cout << a[i] << "  ";
}
void sapxep(int a[], int n)
{
	for (int i=1; i<=n; i++)
	{
		for (int j=i; j<=n; j++)
		{
			if (a[j]<a[i])
			{
				int tg = a[i];
				a[i] = a[j];
				a[j] = tg;
			}
		}
	}
}

int main()
{	
	int a[100], n;
	do{
		cout << "Nhap vao so phan tu cua mang : ";
		cin >> n;
		if (n>100)
			cout << "Vui long nhap lai voi n<100 !";
	} while (n>100);
	nhap(a,n);
	cout << "Mang truoc khi sap xep : ";
	xuat(a,n);
	sapxep(a,n);
	cout << "\nMang sau khi sap xep la : ";
	xuat(a,n);
	return 0;
}


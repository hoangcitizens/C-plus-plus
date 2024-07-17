#include<iostream>
using namespace std;

void input(int a[], int n)
{
	for (int i=1; i<=n; i++)
	{
		cout << "Nhap a["<<i<<"] = ";
		cin >> a[i];
	}
}
void output(int a[], int n)
{
	for(int i=1; i<=n; i++)
		cout << a[i] << "  ";
}
void arrange(int a[], int n)
{
	for(int i=1; i<n; i++)
	{
		for(int j=i+1; j<=n; j++)
		{
			if (a[i] < a[j])
			{
				int tg = a[i];
				a[i] =  a[j];
				a[j] = tg;
			}
		}
	}
}

int main()
{
	int n, a[50];
	cout << "Nhap so phan tu cua mang : ";
	cin >> n;
	input(a,n);
	cout << "Cac phan tu cua mang la: ";
	output(a,n);
	arrange(a,n);
	cout << "\nCac phan tu cua mang sap xep theo thu tu giam dan la : ";
	output(a,n);
	return 0;
}


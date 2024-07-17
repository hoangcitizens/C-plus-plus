// Nguyen Huu Hoang - 21103100320
// Bai 2 - de chan
#include<iostream>
#include<math.h>
using namespace std; 

void input(int a[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout << "Nhap a["<<i<<"] = ";
		cin >> a[i];
	}
}
void output(int a[], int n)
{
	for(int i=0; i<n; i++)
		cout << a[i] << "   ";
}
bool kiemTraSoChinhPhuong(int n)
{
	if(n < 1)
		return false;
	int i = sqrt(n);
	if (i * i == n)
		return true;
	return false;
}
void inSoChinhPhuong(int a[], int n)
{
	int count = 0;
	cout << "\nCac so chinh phuong trong mang la: ";
	for(int i=0; i<n; i++)
	{
		if (kiemTraSoChinhPhuong(a[i]) == true)
		{
			cout << a[i] << "  ";
			count++;
		}
	}
	cout << "\nSo luong cac so chinh phuong trong mang la: "<<count<<endl;
}
void sapxepChan(int a[], int n)
{
	cout << "Cac phan tu chan theo thu tu tang dan la: ";
	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if (a[i]%2 == 0 && a[j]%2 == 0)
			{
				if (a[i] > a[j])
				{
					int tg = a[i];
					a[i] = a[j];
					a[j] = tg;
				}
			}
		}
	}
}
void sapxepLe(int a[], int n)
{
	cout << "\nCac phan tu le theo thu tu giam dan la: ";
	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if (a[i]%2 != 0 && a[j]%2 != 0)
			{
				if (a[i] < a[j])
				{
					int tg = a[i];
					a[i] = a[j];
					a[j] = tg;
				}	
		 	}
		}
	}
}
int main()
{
	int n, a[50];
	cout << "Nhap so phan tu cua mang: ";
	cin >> n;
	input(a,n);
	cout << "Mang vua nhap la: ";
	output(a,n);
	inSoChinhPhuong(a,n);
	sapxepChan(a,n);
	output(a,n);
	sapxepLe(a,n);
	output(a,n);
	cout << endl;
	return 0;
}


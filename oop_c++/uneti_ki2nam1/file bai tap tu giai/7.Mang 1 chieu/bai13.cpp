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
int tonTai(int a[], int n, int x)
{
	for(int i=1; i<=n; i++)
		if (a[i] == x)
			return 1;
	return 0;
}

int timKiem(int a[], int n, int x)
{	
	int vt;
	for(int i=1; i<=n; i++)
	{
		if (a[i] == x)
			vt = i;	
	}
	return vt;
}

int main()
{
	int n, x, a[50];
	cout << "Nhap so phan tu cua mang : ";
	cin >> n;
	input(a,n);
	cout << "Cac phan tu cua mang la: ";
	output(a,n);
	cout << "\nNhap x = ";
	cin >> x;
	if (tonTai(a,n,x)==1)
	{
		cout << "Ton tai "<<x<<" trong mang !";
		cout << "\nVi tri cua "<<x<<" trong mang la : "<<timKiem(a,n,x);
	}
	else 
		cout << "Khong ton tai "<<x<<" trong mang !";
	return 0;
}


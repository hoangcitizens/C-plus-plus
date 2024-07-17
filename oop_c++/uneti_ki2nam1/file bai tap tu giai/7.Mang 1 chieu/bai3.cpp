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
void timMin(int a[], int n)
{
	int min = a[0], k = 0;
	for (int i=1; i<=n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
			k = i;
		}
	}
	cout << "\nPhan tu be nhat cua mang la : "<<min;
	cout << "\nVi tri phan tu be nhat la : "<<k<<endl;
}
int main()
{
	int a[100], n;
	cout << "Nhap vao so phan tu cua mang : ";
	cin >> n;
	nhap(a,n);
	cout << "Cac phan tu cua mang : ";
	xuat(a,n);
	timMin(a,n);
	return 0;
}


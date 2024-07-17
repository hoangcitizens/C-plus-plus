#include<iostream>
using namespace std;

void input(int a[], int n)
{
	for(int i=1; i<=n; i++)
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
int timKiemNhiPhan(int a[], int l, int r, int x)
{
	int mid;
	do{
		mid = (l+r)/2;
		if(a[mid]==x)
			return mid;
		else
			if(a[mid]>x)
				return timKiemNhiPhan(a,l,mid-1,x);
			else
				return timKiemNhiPhan(a,mid+1,r,x);
	} while (l<r);
}

int main()
{
	int n, x, a[50];
	cout << "Nhap so phan tu cua mang : ";
	cin >> n;
	input(a,n);
	cout << "Mang da nhap la : ";
	output(a,n);
	cout << "\nNhap so can tim : ";
	cin >> x;
	cout << "\nVi tri so can tim la : "<<timKiemNhiPhan(a,1,n,x)<<endl;
	return 0;
}


#include<iostream>
using namespace std;

void input(int a[], int n)
{
	for (int i=1; i<=n; i++)
	{
		cout << "a["<<i<<"] = ";
		cin >> a[i];
	}
}
void output(int a[], int n)
{
	for (int i=1; i<=n; i++)
		cout << a[i] << "  ";
}
int tinh(int a[], int n)
{
	int S=0;
	for (int i=1; i<=n; i++)	
	{	
		if (a[i] % 2 != 0)
			S += a[i];
	}
	return S;
}
int main()
{
	int a[50], n;
	cout << "Nhap vao so phan tu cua mang : ";
	cin >> n;
	input(a,n);
	cout << "Cac phan tu trong mang la : ";
	output(a,n);
	int tongS = tinh(a,n);
	cout << "\nTong cac so le trong mang la : "<<tongS<<endl;
	return 0;
}


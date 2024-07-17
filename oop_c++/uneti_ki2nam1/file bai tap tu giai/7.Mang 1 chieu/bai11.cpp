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
int tinh(int a[], int n)
{
	int S=0;
	for(int i=1; i<=n; i++)
		S += a[i];
	return S;
}

int main()
{
	int n, a[50];
	cout << "Nhap so phan tu cua mang : ";
	cin >> n;
	input(a,n);
	cout << "Cac phan tu da nhap la : ";
	output(a,n);
	cout << "\nTong cac phan tu cua mang la: "<<tinh(a,n);
	cout << "\nTrung binh cong cua day so la : "<<(float)(tinh(a,n))/n;
	return 0;
}


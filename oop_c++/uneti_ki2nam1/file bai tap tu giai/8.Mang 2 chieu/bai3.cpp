#include<iostream>
#define max 50
using namespace std;

void nhap(float a[max][max], int n, int m)
{
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout << "Nhap a["<<i<<"]["<<j<<"] = ";
			cin >> a[i][j];
		}
	}
}
void xuat(float a[max][max], int n, int m)
{
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
			cout << a[i][j] << "   ";
		cout << endl;
	}
}
float tinhTong(float a[max][max], int n, int m)
{	
	float S=0;
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
			S += a[i][j];
	}
	return S;
}

int main()
{
	int n, m;
	float a[max][max];
	cout << "Nhap so hang: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	nhap(a,n,m);
	cout << "Ma tran la: "<<endl;
	xuat(a,n,m);
	cout << "Tong cac phan tu trong mang la: "<<tinhTong(a,n,m)<<endl;
	return 0;
}


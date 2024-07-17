#include<iostream>
#define max 50
using namespace std;

void nhap(int a[max][max], int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout << "Nhap a["<<i<<"]["<<j<<"] = ";
			cin >> a[i][j];
		}
	}
}
void xuat(int a[max][max], int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cout << a[i][j] << "   ";
		cout << endl;
	}
}
void phanTuLe(int a[max][max], int n)
{
	for(int i=0; i<n; i++)
	{
		if (a[i][i] % 2 != 0)
			cout << a[i][i] << "  ";
	}
}
int tongDuongCheoPhu(int a[max][max], int n)
{
	int S = 0;
	for(int i=0; i<n; i++)
		S += a[i][n-i-1];
	return S;
}

int main()
{
	int n, a[max][max];
	cout << "Nhap cap cua ma tran: ";
	cin >> n;
	nhap(a,n);
	cout << "Ma tran la: "<<endl;
	xuat(a,n);
	cout << "Phan tu le trong duong cheo chinh la: "<<endl;
	phanTuLe(a,n);
	cout << "\nTong cac phan tu le cua duong cheo phu la: "<<tongDuongCheoPhu(a,n);
	return 0;
}


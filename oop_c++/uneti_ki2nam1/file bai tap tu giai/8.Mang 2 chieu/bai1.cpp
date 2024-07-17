#include<iostream>
#define max 50
using namespace std;

void nhap(int a[max][max], int n, int m)
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
void xuat(int a[max][max], int n, int m)
{
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
			cout << a[i][j] << "  ";
		cout << endl;
	}
}
void xuatLe(int a[max][max], int n, int m)
{
	for(int i=0; i<m; i++)
	{
		if(i%2 == 1)
		{
			for(int j=0; j<n; j++)
				cout << a[i][j] << "  ";
			cout << endl;
		}
	}
}
int main()
{
	int n, m, a[max][max];
	cout << "Nhap so hang: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	nhap(a,n,m);
	cout << "Ma tran la: "<<endl;
	xuat(a,n,m);
	cout << "Cac phan tu tren dong le : "<<endl;
	xuatLe(a,n,m);
	return 0;
}


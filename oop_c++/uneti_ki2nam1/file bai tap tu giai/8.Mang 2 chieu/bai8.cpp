#include<iostream>
#include<iomanip>
#define max 50
using namespace std;

void input(float a[max][max], int n, int m)
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
void output(float a[max][max], int n, int m)
{
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
			cout << left << setw(6) << a[i][j];
		cout << endl;
	}
}
void demPhanTu(float a[max][max], int n, int m)
{
	int count = 0;
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
			if (a[i][j] >= 10 && a[i][j] <= 100)
				count++;
	}
	cout << "So phan tu co gia tri trong doan [10,100] la: "<<count;
}
void sapXep(float a[max][max], int n, int m)
{
	for(int j=0; j<n; j++)
	{
		for(int k=j+1; k<n; k++)
		{
			if (a[0][j] > a[0][k])
			{
				int tg = a[0][j];
				a[0][j] = a[0][k];
				a[0][k] = tg;
			}
		}
	}
}

int main()
{
	int n, m;
	float a[max][max];
	cout << "Nhap so hang : ";
	cin >> m;
	cout << "Nhap so cot : ";
	cin >> n;
	input(a,n,m);
	cout << "Mang da nhap la: "<<endl;
	output(a,n,m);
	demPhanTu(a,n,m);
	sapXep(a,n,m);
	cout << "\nMang sau khi sap xep : "<<endl;
	output(a,n,m);
	return 0;
}


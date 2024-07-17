#include<iostream>
#include<math.h>
using namespace std;
#define max 50

void input(int a[max][max], int n, int m)
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
void output(int a[max][max], int n, int m)
{
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
			cout << a[i][j] << "   ";
		cout << endl;
	}
}
float trungBinh(int a[max][max], int n, int m)
{
	int S = 0, count = 0;
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			if (a[i][j] != 0)
			{
				count++;
				S += a[i][j];
			}
		}
	}
	return S/count;
}
bool kiemTraSnt(int k)
{
	if(k < 2)
		return false;
	else
	{
		for(int i=2; i<=sqrt(k); i++)
		{
			if(k%i == 0)
				return false;
		}
		return true;
	}
}
void demSnt(int a[max][max], int n, int m)
{
	int count = 0;
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			if (kiemTraSnt(a[i][j])==true)
				count++;
		}
	}
	cout << "So luong so nguyen to trong mang la: "<<count<<endl;
}

int main()
{
	int n, m, a[max][max];
	cout << "Nhap so hang : ";
	cin >> m;
	cout << "Nhap so cot : ";
	cin >> n;
	input(a,n,m);
	cout << "Mang da nhap la: "<<endl;
	output(a,n,m);
	cout << "Trung binh cac phan tu le tren mang la : "<<(float)trungBinh(a,n,m)<<endl;
	demSnt(a,n,m);
	return 0;
}


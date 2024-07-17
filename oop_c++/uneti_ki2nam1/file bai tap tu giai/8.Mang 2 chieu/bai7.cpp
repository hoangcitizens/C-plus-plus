#include<iostream>
#include<math.h>
#define max 50
using namespace std;

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
bool kiemTraScp(int k)
{
	if (k<1)
		return false;
	int i = sqrt(k);
	if (i*i == k)
		return true;
	return false;
}
void inScp(int a[max][max], int n, int m)
{
	cout << "Cac so chinh phuong trong mang la: ";
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			if (kiemTraScp(a[i][j])==true)
				cout << a[i][j] << "  ";
		}
	}
}
void viTriPhanTuAm(int a[max][max], int n, int m)
{
	cout << "\nVi tri phan tu am dau tien: ";
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			if (a[i][j] < 0)
			{
				cout << "a["<<i<<"]["<<j<<"]";
				break;
			}
		}
	}
	cout << "Mang khong co phan tu am !"<<endl;
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
	inScp(a,n,m);
	viTriPhanTuAm(a,n,m);
	return 0;
}


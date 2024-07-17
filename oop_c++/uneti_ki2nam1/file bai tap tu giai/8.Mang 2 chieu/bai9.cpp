#include<iostream>
#include<iomanip>
#define max 50

using namespace std;

void input(int a[max][max], int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout << "Nhap a["<<i<<"]["<<j<<"] = ";
			cin >> a[i][j];
		}
		cout << endl;
	}
}
void output(int a[max][max], int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cout << left << setw(6) << a[i][j] ;
		cout << endl;
	}
}
bool kiemTraShh(int k)
{
	int S = 0;		
	for (int i=1; i<=k/2; i++)
	{
		if (k%i == 0)
			S +=i;	//tinh tong cac uoc cua k
	}
	if (S == k)
		return true;	
	return false;	
}
void soHoanHao(int a[max][max], int n)
{
	cout << "Cac so hoan hao tren duong cheo phu la : ";
	for(int i=0; i<n; i++)
	{
		if(kiemTraShh(a[i][n-i-1]))
			cout << a[i][n-i-1] << "   ";
	}
}
void soLonNhat(int a[max][max], int n)
{
	int soLon = a[0][0];
	for(int i=0; i<n; i++)
	{
		if(a[i][i] > soLon)
			soLon = a[i][i];
	}
	cout<<"\nSo lon nhat tren duong cheo chinh la: "<<soLon<<endl;
}
int main()
{
	int n, a[max][max];
	cout << "Nhap cap cua ma tran: ";
	cin >> n;
	input(a,n);
	cout << "Ma tran la: "<<endl;
	output(a,n);
	soHoanHao(a,n);
	soLonNhat(a,n);
	return 0;
}


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
int soHoanHao(int x)
{
	int S = 0;
	for(int i=1; i<x; i++)
	{
		if (x%i == 0)
			S += i;
	}
	if(S == x) 
		return 1;
	return 0;
}

int main()
{
	int n, x, a[50];
	cout << "Nhap so phan tu cua mang : ";
	cin >> n;
	input(a,n);
	cout << "Cac phan tu cua mang la: ";
	output(a,n);
	cout<<"\nCac so hoan hao trong mang la: "<<endl;
	for (int i=0; i<n; i++)
		if (soHoanHao(a[i])==1)
			cout << "  " << a[i];
	return 0;
}


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
int kiemTraSoNguyenTo(int x)
{	
	int count = 0;
	for(int i=1; i<=x; i++)
	{
		if(x%i == 0)
			count++;
	}
	if (count == 2)
		return 1;
	return 0;
}

int main()
{
	int n, a[50];
	cout << "Nhap so phan tu cua mang : ";
	cin >> n;
	input(a,n);
	cout << "Cac phan tu cua mang la: ";
	output(a,n);
	cout << "\nCac so nguyen to co trong mang la : ";
	for (int i=1; i<=n; i++){
		if (kiemTraSoNguyenTo(a[i])==1)
			cout << a[i] << "  ";
	}
	cout << endl;
	return 0;
}


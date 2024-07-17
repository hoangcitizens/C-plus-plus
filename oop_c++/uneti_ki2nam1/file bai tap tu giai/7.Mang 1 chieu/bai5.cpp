#include<iostream>
using namespace std;

void input(int a[], int n)
{
	for (int i=1; i<=n; i++)
	{
		cout << "a["<<i<<"] = ";
		cin >> a[i];
	}
}
void output(int a[], int n)
{
	for (int i=n; i>=1; i--)
		cout << a[i] <<"  ";
}

int main()
{
	int a[100], n;
	cout << "Nhap so phan tu cua mang : ";
	cin >> n;
	input(a,n);
	cout << "Thu tu nguoc lai cua mang : ";
	output(a,n);
	return 0;
}


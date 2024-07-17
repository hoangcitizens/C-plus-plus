#include<iostream>
using namespace std;

void input(int a[], int n)
{
	for (int i=0; i<n; i++)
	{
		cout << "a["<<i<<"] = ";
		cin >> a[i];
	}
}

int main()
{
	int n, a[50];
	cout << "Nhap vao so phan tu trong mang : ";
	cin >> n;
	input(a,n);
	cout << "Cac gia tri khac nhau trong day : ";
	for (int i=0; i<n; i++)
	{
		if (a[i] != a[i+1])
			cout << a[i] << "  ";
	}
	return 0;
}


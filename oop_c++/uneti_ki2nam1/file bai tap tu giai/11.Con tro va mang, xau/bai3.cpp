#include<iostream>
using namespace std;

int *maxA(int b[], int m)
{
	int *max = b;
	for (int i=1; i<m; i++)
	{
		if (*max < *(max+i))
			*max = *(max+i);
	}
	return max;
}

int main()
{
	int n, *p;
	cout << "Nhap so phan tu cua mang n: ";
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++)
	{
		cout << "Nhap gia tri thu "<<i+1<<" la: ";
		cin >> a[i];
	}
	p = maxA(a,n);
	cout << "Gia tri lon nhat la: "<<*p<<endl;
	return 0;
}


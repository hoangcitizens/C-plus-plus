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
int timMax(int a[], int n)
{
	int vt;
	int max = a[1];
	for(int i=1; i<=n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			vt = i;	
		}
	}
	cout << "\nVi tri cua so lon nhat la : "<<vt;
	return max;
}

int main()
{
	int a[100], n;
	cout << "Nhap vao so phan tu cua mang n = ";
	cin >> n;
	input(a,n);
	cout << "Cac phan tu cua mang : ";
	output(a,n);
	cout << "\nSo lon nhat trong cac so da nhap la : "<<timMax(a,n);
	return 0;
}


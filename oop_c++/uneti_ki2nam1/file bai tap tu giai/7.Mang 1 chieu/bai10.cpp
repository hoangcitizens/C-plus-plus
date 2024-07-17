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
void insert(int a[], int n, int x)
{
	int pos = n;
	while((pos>0) && (a[pos-1]>x))
	{
		a[pos] = a[pos-1];
		pos--;
	}
	a[pos] = x;
}
void arrange(int a[], int n)
{
	for (int i=1; i<n;i++){
		for (int j=i+1; j<=n; j++){
			if (a[i]>a[j])
			{
				int tg=a[i];
				a[i]=a[j];
				a[j]=tg;
			} 
		}
	}
}
int main()
{
	int a[100], n, x;
	cout << "Nhap vao so phan tu cua mang : ";
	cin >> n;
	input(a,n);
	cout << "Cac phan tu trong mang la : ";
	output(a,n);
	arrange(a,n);
	cout << "\nNhap them phan tu x = ";
	cin >> x;
	insert(a,n+1,x);
	output(a,n+1);
	return 0;
}


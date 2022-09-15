#include<iostream>
using namespace std;

typedef struct
{
	float tu;
	float mau;
} phan_so;

void input(phan_so a[], int n)
{
	for (int i=0; i < n; i++)
	{
		cout << "(*) Nhap phan so thu " << i+1 << endl;
		cout << "Nhap tu: "; cin >> a[i].tu;
		cout << "Nhap mau: "; cin >> a[i].mau;
		while (a[i].mau < 1)
		{
			cout << "Nhap lai mau so > 0: ";
			cin >> a[i].mau;
		}
		cout << endl;
	}
}
void output(phan_so a[], int n)
{
	cout << "Phan so vua nhap la" << endl;
	for (int i=0; i < n; i++)
	{
		cout << a[i].tu << "/" << a[i].mau << endl;
	}
}
float UCLN(float a, float b)
{
	if (a == 0 || b == 0)	
		return a + b;
	while (a != b)
	{
		if (a > b)
			a -= b;
		else 
			b -= a;
	}
	return a;
}
phan_so tinh_tong(phan_so a[], int n)
{
	phan_so tmp = a[0];
	for (int i=1; i < n; i++)
	{
		tmp.tu = tmp.tu * a[i].mau + tmp.mau*a[i].tu;
		tmp.mau = tmp.mau * a[i].mau;
		tmp.tu /= UCLN(tmp.tu, tmp.mau);
		tmp.mau /= UCLN(tmp.tu, tmp.mau);
	}
	return tmp;
}
void xuli(phan_so a[], int n)
{
	phan_so tong = tinh_tong(a,n);
	cout << "Tong PS = " << tong.tu << "/" << tong.mau;
}

  

int main()
{
	int n;
	cout << "Nhap so luong phan so: ";
	cin >> n;
	while (n < 1)
	{
		cout << "Nhap so luong phan so > 0: ";
		cin >> n;
	}
	phan_so a[n];
	input(a,n);
	output(a,n);
	xuli(a,n);
	return 0;
}


#include<iostream>
#include<math.h>
#include<iomanip>
#include<string>
using namespace std;

typedef struct
{
	float tu;
	float mau;
} phan_so;

int UCLN(float a, float b)
{
	if (a == 0 || b == 0)
		return a + b;
	while (a != b) // lap toi khi a = b;
	{
		if (a > b)
			a -= b; // lay so lon tru so be
		else
			b -= a;
	}
	return a; // a = b nen tra ve gia tri nao cung duoc
}
phan_so rut_gon(phan_so k)
{
	if (k.tu != 0)
	{
		int h = UCLN(k.tu,k.mau);
		k.tu /= h;
		k.mau /= h;
	}
	return k;
}
void so_sanh(phan_so a, phan_so b)
{
	float m, n;
	m = float((a.tu) / (a.mau));
	n = float((b.tu) / (b.mau));
	if (m > n)
		cout << a.tu << "/" << a.mau << " > " << b.tu << "/" << b.mau << endl;
	else if (m == n)
		cout << a.tu << "/" << a.mau << " = " << b.tu << "/" << b.mau << endl;
	else
		cout << a.tu << "/" << a.mau << " < " << b.tu << "/" << b.mau << endl;
}

int main()
{
	phan_so a, b;
	cout << "(*) Nhap phan so a" << endl;
	cout << "Nhap tu so: "; cin >> a.tu;
	cout << "Nhap mau so: "; cin >> a.mau;
	while (a.mau == 0)
	{
		cout << "Nhap lai mau so khac 0: ";
		cin >> a.mau;
	}
	cout << "=> Phan so A la: " << a.tu << "/" << a.mau << endl;
	cout << "(*) Nhap phan so b" << endl;
	cout << "Nhap tu so: "; cin >> b.tu;
	cout << "Nhap mau so: "; cin >> b.mau;
	while (b.mau == 0)
	{
		cout << "Nhap lai mau so khac 0: ";
		cin >> b.mau;
	}
  	cout << "=> Phan so B la: " << b.tu << "/" << b.mau << endl;
  	cout << "\n(*) Rut gon 2 phan so" << endl;
	a = rut_gon(a);
	b = rut_gon(b);
	cout << "=> Phan so A rut gon la: " << a.tu << "/" << a.mau << endl;
  	cout << "=> Phan so B rut gon la: " << b.tu << "/" << b.mau << endl;
  	cout << "\n(*) So sanh 2 phan so" << endl;
	so_sanh(a,b);
	return 0;
}


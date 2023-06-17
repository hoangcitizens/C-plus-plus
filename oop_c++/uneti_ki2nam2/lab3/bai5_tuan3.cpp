#include<iostream>
#include<math.h>
using namespace std;

class PhanSo
{
private:
	int t, m;
public:
	PhanSo(int, int);
	~PhanSo();
	friend istream& operator >> (istream& is, PhanSo& p);
	friend ostream& operator << (ostream& os, PhanSo& p);
	PhanSo rutGon(PhanSo);
	PhanSo operator +(PhanSo);
	PhanSo operator -(PhanSo);
	PhanSo operator *(PhanSo);
	PhanSo operator /(PhanSo);
	friend bool operator <(PhanSo, PhanSo);
	friend bool operator >(PhanSo, PhanSo);
	friend bool operator <=(PhanSo, PhanSo);
	friend bool operator >=(PhanSo, PhanSo);
};

PhanSo::PhanSo(int tu = 1, int mau = 1)
{
	t = tu;
	m = mau;
}
PhanSo::~PhanSo(){}
int UCLN(int a, int b)
{
	if (a < 0) 
		a *= (-1);
	if (b < 0)
		b *= (-1);
	while (a != b)
	{                  
		if (a > b)     
			a -= b;    
		else         
			b -= a;
	}
	return a;
}
PhanSo PhanSo::rutGon(PhanSo p)
{
	if (p.t != 0)              
	{                            
		int u = UCLN(p.t, p.m); 
		p.t /= u;               
		p.m /= u;               
	}
	return p;
}
istream& operator >> (istream& is, PhanSo& p)
{
	cout << "Nhap tu so: "; is >> p.t;
	cout << "Nhap mau so: "; is >> p.m;
	while (p.m == 0)
	{
		cout << "Vui long nhap mau khac 0: ";
		is >> p.m;
	}
	return is;
}
ostream& operator << (ostream& os, PhanSo& p)
{
	if (p.m < 0)
	{
		p.t *= -1; 
		p.m *= -1; 
		os << p.t << "/" << p.m;
	}
	else if (p.t % p.m == 0)
		os << p.t / p.m;
	else
		os << p.t << "/" << p.m;
	return os;
}
PhanSo PhanSo::operator+(PhanSo b)
{
	PhanSo a;
	a.t = this->t * b.m + b.t * this->m;
	a.m = this->m * b.m;
	a = rutGon(a);
	return a;
}
PhanSo PhanSo::operator-(PhanSo b)
{
	PhanSo a;
	a.t = this->t * b.m - b.t * this->m;
	a.m = this->m * b.m;
	a = rutGon(a);
	return a;
}
PhanSo PhanSo::operator*(PhanSo b)
{
	PhanSo a;
	a.t = this->t * b.t;
	a.m = this->m * b.m;
	a = rutGon(a);
	return a;
}
PhanSo PhanSo::operator/(PhanSo b)
{
	PhanSo a;
	a.t = this->t * b.m;
	a.m = this->m * b.t;
	a = rutGon(a);
	return a;
}
bool operator <(PhanSo a, PhanSo b)
{
	return (a.t * 1.0 / a.m < b.t * 1.0 / b.m);
}
bool operator >(PhanSo a, PhanSo b)
{
	return (a.t * 1.0 / a.m > b.t * 1.0 / b.m);
}
bool operator <=(PhanSo a, PhanSo b)
{
	return (a.t * 1.0 / a.m <= b.t * 1.0 / b.m);
}
bool operator >=(PhanSo a, PhanSo b)
{
	return (a.t * 1.0 / a.m >= b.t * 1.0 / b.m);
}
void input(PhanSo a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "(*) Nhap phan so thu " << i + 1 << endl; 
		cin >> a[i];
		cout << endl;
	}
}
void output(PhanSo a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "  ";
	}
}
void timMin(PhanSo a[], int n)
{
	PhanSo min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (min > a[i])
			min = a[i];
	}
	cout << "\n(!) Phan so nho nhat trong cac phan so la : " << min << endl;
}
void timMax(PhanSo a[], int n)
{
	PhanSo max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (max < a[i])
			max = a[i];
	}
	cout << "(!) Phan so lon nhat trong cac phan so la : " << max << endl;
}
void tinhTong(PhanSo a[], int n)
{
	PhanSo tong = 0;
	for (int i = 0; i < n; i++)
	{
		tong = tong + a[i];
	}
	cout << "\n(+) Tong cua " << n << " phan so la: " << tong << endl;
}
void tinhHieu(PhanSo a[], int n)
{
	PhanSo hieu = 0;
	for (int i = 0; i < n; i++)
	{
		hieu = hieu - a[i];
	}
	cout << "(-) Hieu cua " << n << " phan so la: " << hieu << endl;
}
void tinhTich(PhanSo a[], int n)
{
	PhanSo tich = 1;
	for (int i = 0; i < n; i++)
	{
		tich = tich * a[i];
	}
	cout << "(*) Tich cua " << n << " phan so la: " << tich << endl;
}
int main()
{
	PhanSo a, b, p;
	cout << "(*) Nhap phan so thu nhat" << endl; cin >> a;
	cout << "=> Phan so thu nhat la: " << a << endl << endl;
	cout << "(*) Nhap phan so thu hai" << endl; cin >> b;
	cout << "=> Phan so thu nhat la: " << b << endl << endl;
	p = a + b; cout << "Tong hai phan so la: " << p;
	p = a - b; cout << "\nHieu hai phan so la: " << p;
	p = a * b; cout << "\nTich hai phan so la: " << p;
	p = a / b; cout << "\nThuong hai phan so la: " << p;
	cout << endl;
	// phan mo rong
	int n; cout << "\nNhap so luong phan so: "; cin >> n;
	PhanSo* h = new PhanSo[n];
	input(h,n);
	cout << "=> Cac phan so vua nhap la: ";
	output(h,n);
	tinhTong(h,n);
	tinhHieu(h,n);
	tinhTich(h,n);
	timMin(h,n);
	timMax(h,n);
	return 0;
}
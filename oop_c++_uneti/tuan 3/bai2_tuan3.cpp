#include<iostream>
using namespace std;

class PhanSo
{
private:
	int t, m;
public:
	PhanSo();
	~PhanSo();
	void input();
	void output();
	PhanSo rutGon(PhanSo);
	PhanSo tinhtong(PhanSo);
	PhanSo tinhhieu(PhanSo);
	PhanSo tinhtich(PhanSo);
	PhanSo tinhthuong(PhanSo);
};

PhanSo::PhanSo()
{
	this->t = 1;
	this->m = 1;
}
PhanSo::~PhanSo()
{
	this->t = 0;
	this->m = 0;
}
void PhanSo::input()
{
	cout << "Nhap tu so: ";
	cin >> t;
	cout << "Nhap mau so: ";
	cin >> m;
	while (m == 0)
	{
		cout << "Nhap mau so khac 0: ";
		cin >> m;
	}
}
void PhanSo::output()
{
	cout << t << "/" << m << endl;
}
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
PhanSo PhanSo::tinhtong(PhanSo b)
{
	PhanSo a;
	a.t = t * b.m + b.t * m;
	a.m = b.m * m;
	a = rutGon(a);
	return a;
}
PhanSo PhanSo::tinhhieu(PhanSo b)
{
	PhanSo a;
	a.t = t * b.m - b.t * m;
	a.m = b.m * m;
	a = rutGon(a);
	return a;
}
PhanSo PhanSo::tinhtich(PhanSo b)
{
	PhanSo a;
	a.t = t * b.t;
	a.m = b.m * m;
	a = rutGon(a);
	return a;
}
PhanSo PhanSo::tinhthuong(PhanSo b)
{
	PhanSo a;
	if (b.t == 0)
		cout << "Khong thuc hien duoc phep chia !";
	else
	{
		a.t = m * b.m;
		a.m = t * b.t;
		a = rutGon(a);
	}
	return a;
}

int main()
{
	PhanSo a, b;
	cout << "(*) Nhap phan so thu nhat" << endl;
	a.input();
	cout << "=> Phan so thu nhat la: "; a.output(); cout << endl;
	cout << "(*) Nhap phan so thu hai" << endl;
	b.input();
	cout << "=> Phan so thu nhat la: "; b.output(); cout << endl;
	PhanSo tong, hieu, tich, thuong;
	cout << "Tong hai phan so la: ";
	tong = a.tinhtong(b);
	tong.output();
	cout << "Hieu hai phan so la: ";
	hieu = a.tinhhieu(b);
	hieu.output();
	cout << "Tich hai phan so la: ";
	tich = a.tinhtich(b);
	tich.output();
	cout << "Thuong hai phan so la: ";
	thuong = a.tinhthuong(b);
	thuong.output();
	return 0;
}


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
	void rutGon();
	friend PhanSo tinhtong(PhanSo, PhanSo);
	friend PhanSo tinhhieu(PhanSo, PhanSo);
	friend PhanSo tinhtich(PhanSo, PhanSo);
	friend PhanSo tinhthuong(PhanSo, PhanSo);
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
void PhanSo::rutGon()
{
	if (t != 0)
	{
		int u = UCLN(t, m);
		t /= u;
		m /= u;
	}
}
PhanSo tinhtong(PhanSo a, PhanSo b)
{
	PhanSo k;
	k.t = a.t * b.m + b.t * a.m;
	k.m = a.m * b.m;
	k.rutGon();
	return k;
}
PhanSo tinhhieu(PhanSo a,PhanSo b)
{
	PhanSo k;
	k.t = a.t * b.m - b.t * a.m;
	k.m = a.m * b.m;
	k.rutGon();
	return k;
}
PhanSo tinhtich(PhanSo a, PhanSo b)
{
	PhanSo k;
	k.t = a.t * b.t;
	k.m = a.m * b.m;
	k.rutGon();
	return k;
}
PhanSo tinhthuong(PhanSo a, PhanSo b)
{
	PhanSo k;
	if (a.t == 0)
		cout << "Khong thuc hien duoc phep chia !";
	else
	{
		k.t = a.t * b.m;
		k.m = a.m * b.t;
		k.rutGon();
	}
	return k;
}


int main()
{
	PhanSo a, b;
	cout << "(*) Nhap phan so thu nhat" << endl;
	a.input();
	cout << "=> Phan so thu nhat la: "; a.output(); cout << endl;
	cout << "(*) Nhap phan so thu hai" << endl;
	b.input();
	cout << "=> Phan so thu hai la: "; b.output(); cout << endl;
	PhanSo tong, hieu, tich, thuong;
	cout << "Tong hai phan so la: ";
	tong = tinhtong(a, b);
	tong.output();
	cout << "Hieu hai phan so la: ";
	hieu = tinhhieu(a, b);
	hieu.output();
	cout << "Tich hai phan so la: ";
	tich = tinhtich(a, b);
	tich.output();
	cout << "Thuong hai phan so la: ";
	thuong = tinhthuong(a, b);
	thuong.output();
	return 0;
}
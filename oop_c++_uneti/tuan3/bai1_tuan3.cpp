#include<iostream>
using namespace std;

class DaThuc3
{
private:
	int a, b, c, d;
public:
	DaThuc3();
	DaThuc3(int);
	DaThuc3(int, int);
	DaThuc3(int, int, int);
	DaThuc3(int, int, int, int);
	~DaThuc3();
	void input();
	void output();
	int geta();
	int getb();
	int getc();
	int getd();
};

DaThuc3::DaThuc3()
{
	this->a = 0;
	this->b = 0;
	this->c = 0;
	this->d = 0;
}
DaThuc3::DaThuc3(int a)
{
	this->a = a;
	this->b = 0;
	this->c = 0;
	this->d = 0;
}
DaThuc3::DaThuc3(int a, int b)
{
	this->a = a;
	this->b = b;
	this->c = 0;
	this->d = 0;
}
DaThuc3::DaThuc3(int a, int b, int c)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = 0;
}
DaThuc3::DaThuc3(int a, int b, int c, int d)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}
DaThuc3::~DaThuc3()
{
	this->a = 0;
	this->b = 0;
	this->c = 0;
	this->d = 0;
}
void DaThuc3::input()
{
	cout << "Nhap he so a: "; cin >> a;
	cout << "Nhap he so b: "; cin >> b;
	cout << "Nhap he so c: "; cin >> c;
	cout << "Nhap he so d: "; cin >> d;
}
void DaThuc3::output()
{
	cout << "Da thuc bac ba la: " << a << "x^3 + " << b << "x^2 + " << c << "x + " << d << endl;
}
int DaThuc3::geta()
{
	return a;
}
int DaThuc3::getb()
{
	return b;
}
int DaThuc3::getc()
{
	return c;
}
int DaThuc3::getd()
{
	return d;
}

int main()
{
	DaThuc3 dt0;
	dt0.output();
	DaThuc3 dt1(3);
	dt1.output();
	DaThuc3 dt2(3, 4);
	dt2.output();
	DaThuc3 dt3(3, 4, 7);
	dt3.output();
	DaThuc3 dt4(3, 4, 7, 12);
	dt4.output();
	DaThuc3 d1, d2;
	cout << "(*) Nhap da thuc thu nhat" << endl;
	d1.input();
	d1.output(); cout << endl;
	cout << "(*) Nhap da thuc thu hai" << endl;
	d2.input();
	d2.output(); cout << endl;
	cout << "Tong hai da thuc la: ";
	cout << d1.geta() + d2.geta() << "x^3 + " << d1.getb() + d2.getb() << "x^2 + "
		<< d1.getc() + d2.getc() << "x + " << d1.getd() + d2.getd() << endl;
	return 0;
}


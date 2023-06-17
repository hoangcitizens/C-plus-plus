#include<iostream>
#include<iomanip>
#include<string>
#include<math.h>
using namespace std;

class DaThuc3
{
public:
	DaThuc3(int, int, int, int);
	~DaThuc3();
	friend istream& operator >> (istream&, DaThuc3&);
	friend ostream& operator << (ostream&, DaThuc3&);
	DaThuc3 operator +(DaThuc3);
	DaThuc3 operator -(DaThuc3);
private:
	int a, b, c, d;
};

DaThuc3::DaThuc3(int a = 0, int b = 0, int c = 0, int d = 0)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}
DaThuc3::~DaThuc3() {}
istream& operator >> (istream& is, DaThuc3& dt)
{
	cout << "Nhap he so bac 3: "; is >> dt.a;
	cout << "Nhap he so bac 2: "; is >> dt.b;
	cout << "Nhap he so bac 1: "; is >> dt.c;
	cout << "Nhap he so bac 0: "; is >> dt.d;
	return is;
}
ostream& operator << (ostream& os, DaThuc3& dt)
{
	if (dt.b > 0 || dt.c > 0 || dt.d > 0)
		os << dt.a << "x3 + " << dt.b << "x2 + " << dt.c << "x + " << dt.d << endl;
	else
		os << dt.a << "x3 - " << dt.b*(-1) << "x2 - " << dt.c * (-1) << "x - " << dt.d * (-1) << endl;
	return os;
}
DaThuc3 DaThuc3::operator +(DaThuc3 dt1)
{
	DaThuc3 dt2;
	dt2.a = dt1.a + this->a;
	dt2.b = dt1.b + this->b;
	dt2.c = dt1.c + this->c;
	dt2.d = dt1.d + this->d;
	return dt2;
}
DaThuc3 DaThuc3::operator -(DaThuc3 dt1)
{
	DaThuc3 dt2;
	dt2.a = dt1.a - this->a;
	dt2.b = dt1.b - this->b;
	dt2.c = dt1.c - this->c;
	dt2.d = dt1.d - this->d;
	return dt2;
}

int main()
{
	DaThuc3 dt3[2], d1, d2;
	for (int i = 0; i < 2; i++)
	{
		cout << "(+) Nhap da thuc thu " << i + 1 << endl;
		cin >> dt3[i];
		cout << endl;
	}
	cout << "=> Hai da thuc vua nhap la: " << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << "\t";
		cout << dt3[i];
	}
	d1 = dt3[0] + dt3[1];
	cout << "(+) Tong 2 da thuc la: " << d1 << endl;
	d2 = dt3[0] - dt3[1];
	cout << "(-) Hieu 2 da thuc la: " << d2 << endl;
	return 0;
}
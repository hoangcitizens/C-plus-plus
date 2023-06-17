#include<iostream>
#include<math.h>
#include<string>
using namespace std;

class DaThuc3
{
public:
	DaThuc3(int,int,int,int);
	~DaThuc3();
	friend istream& operator >> (istream& ,DaThuc3&);
	friend ostream& operator << (ostream& ,DaThuc3&);
	friend DaThuc3 operator + (DaThuc3,DaThuc3);
	friend DaThuc3 operator - (DaThuc3,DaThuc3);
private:
	int a, b, c, d;
};

DaThuc3::DaThuc3(int a = 0,int b = 0,int c = 0,int d = 0)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}
DaThuc3::~DaThuc3(){}
istream& operator >> (istream& is,DaThuc3 &dt)
{
	cout << "Nhap he so bac 3: "; is >> dt.a;
	cout << "Nhap he so bac 2: "; is >> dt.b;
	cout << "Nhap he so bac 1: "; is >> dt.c;
	cout << "Nhap he so tu do: "; is >> dt.d;
	return is;
}
ostream& operator << (ostream& os,DaThuc3 &dt)
{
	if (dt.b < 0)
		os << dt.a << "x^3 - " << -dt.b << "x^2 + " << dt.c << "x + " << dt.d << endl; 
	else if (dt.c < 0)
		os << dt.a << "x^3 + " << dt.b << "x^2 - " << -dt.c << "x + " << dt.d << endl; 
	else if (dt.d < 0)
		os << dt.a << "x^3 + " << dt.b << "x^2 + " << dt.c << "x - " << -dt.d << endl; 
	else if (dt.b < 0 && dt.c < 0)
		os << dt.a << "x^3 - " << -dt.b << "x^2 - " << -dt.c << "x + " << dt.d << endl; 
	else if (dt.b < 0 && dt.d < 0)
		os << dt.a << "x^3 - " << -dt.b << "x^2 + " << dt.c << "x - " << -dt.d << endl; 
	else if (dt.c < 0 && dt.d < 0)
		os << dt.a << "x^3 + " << dt.b << "x^2 - " << -dt.c << "x - " << -dt.d << endl; 
	else if (dt.b < 0 && dt.c < 0 && dt.d < 0)
		os << dt.a << "x^3 - " << -dt.b << "x^2 - " << -dt.c << "x - " << -dt.d << endl; 
	else
		os << dt.a << "x^3 + " << dt.b << "x^2 + " << dt.c << "x + " << dt.d << endl; 
	return os;
}
DaThuc3 operator + (DaThuc3 dt1,DaThuc3 dt2)
{
	DaThuc3 dt;
	dt.a = dt1.a + dt2.a;
	dt.b = dt1.b + dt2.b;
	dt.c = dt1.c + dt2.c;
	dt.d = dt1.d + dt2.d;
	return dt;
}
DaThuc3 operator - (DaThuc3 dt1,DaThuc3 dt2)
{
	DaThuc3 dt;
	dt.a = dt1.a - dt2.a;
	dt.b = dt1.b - dt2.b;
	dt.c = dt1.c - dt2.c;
	dt.d = dt1.d - dt2.d;
	return dt;
}

int main()
{
	DaThuc3 dt1, dt2, add, sub; 
	cout << "(*) Nhap da thuc thu nhat\n"; cin >> dt1;
	cout << "\n(*) Nhap da thuc thu hai\n"; cin >> dt2;
	cout << "\n=> Da thuc vua nhap la: \n"; cout << dt1 ; cout << dt2;
	add = dt1 + dt2;
	cout << "\n(+) Tong 2 da thuc la: "; cout << add;
	sub = dt1 - dt2;
	cout << "\n(-) Hieu 2 da thuc la: "; cout << sub;
 	return 0;
}

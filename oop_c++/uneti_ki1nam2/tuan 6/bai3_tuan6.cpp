#include<iostream>
using namespace std;

class VecTor3
{
private:
	int a, b, c;
public:
	VecTor3(int, int, int);
	~VecTor3();
	friend istream& operator >> (istream& is, VecTor3& v);
	friend ostream& operator << (ostream& os, VecTor3& v);
	VecTor3 operator +(VecTor3);
	VecTor3 operator -(VecTor3);
};

VecTor3::VecTor3(int x = 0, int y = 0, int z = 0)
{
	a = x;
	b = y;
	c = z;
}
VecTor3::~VecTor3() {}
istream& operator >> (istream& is, VecTor3& v)
{
	cout << "Nhap toa do a: "; is >> v.a;
	cout << "Nhap toa do b: "; is >> v.b;
	cout << "Nhap toa do c: "; is >> v.c;
	return is;
}
ostream& operator << (ostream& os, VecTor3& v)
{
	os << "(" << v.a << "," << v.b << "," << v.c << ")" << endl;
	return os;
}
VecTor3 VecTor3::operator+(VecTor3 v2)
{
	VecTor3 v;
	v.a = this->a + v2.a;
	v.b = this->b + v2.b;
	v.c = this->c + v2.c;
	return v;
}
VecTor3 VecTor3::operator-(VecTor3 v2)
{
	VecTor3 v;
	v.a = this->a - v2.a;
	v.b = this->b - v2.b;
	v.c = this->c - v2.c;
	return v;
}

int main()
{
	VecTor3 v1, v2, p, q;
	cout << "(*) Nhap vector thu nhat" << endl;
	cin >> v1;
	cout << "=> Vector thu nhat A" << v1 << endl;
	cout << "(*) Nhap vector thu hai" << endl;
	cin >> v2;
	cout << "=> Vector thu hai B" << v2 << endl;
	cout << "Tong 2 vector A + B la: C";
	p = v1 + v2;
	cout << p;
	cout << "Hieu 2 vector A - B la: D";
	q = v1 - v2;
	cout << q;
	return 0;
}
#include<iostream>
#include<math.h>
#include<string>
using namespace std;

class DaThuc3
{
public:
	DaThuc3(int,int,int,int);
	~DaThuc3();
	void hienThi();	
	DaThuc3 sub(DaThuc3);
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
void DaThuc3::hienThi()
{
	cout << a << "x^3 + " << b << "x^2 + " << c << "x + " << d << endl; 
}
DaThuc3 DaThuc3::sub(DaThuc3 d1)
{
	DaThuc3 d2;
	d2.a = d1.a + this->a;
	d2.b = d1.b + this->b;
	d2.c = d1.c + this->c;
	d2.d = d1.d + this->d;
	return d2;
}


int main()
{
	DaThuc3 d1(2,3,4,5), d2(1,2,3,4), d;
	cout << "Da thuc thu nhat : "; d1.hienThi();
	cout << "Da thuc thu hai: "; d2.hienThi();
	d = d2.sub(d1);
	cout << "Tong cua 2 da thuc: "; d.hienThi();
 	return 0;
}

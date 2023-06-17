#include<iostream>
using namespace std;

class Vector3
{
public:
	Vector3(int, int, int);
	~Vector3();
	void import();
	void display();
	Vector3 sub(Vector3);
private:
	int a, b, c; // toa do vector 3 chieu
};

Vector3::Vector3(int a = 0, int b = 0, int c = 0)
{
	this->a = a;
	this->b = b;
	this->c = c;
}
Vector3::~Vector3() {}
void Vector3::import()
{
	cout << "Nhap toa do chieu thu 1: "; cin >> a;
	cout << "Nhap toa do chieu thu 2: "; cin >> b;
	cout << "Nhap toa do chieu thu 3: "; cin >> c;
}
void Vector3::display()
{
	cout << "(" << a << "," << b << "," << c << ")" << endl;
}
Vector3 Vector3::sub(Vector3 v1)
{
	Vector3 v2;
	v2.a = v1.a + this->a;
	v2.b = v1.b + this->b;
	v2.c = v1.c + this->c;
	return v2;
}

int main()
{
	Vector3 v1, v2, v;
	cout << "(+) Nhap vector thu nhat" << endl; v1.import();
	cout << "=> Vector A"; v1.display();
	cout << "\n(+) Nhap vector thu hai" << endl; v2.import();
	cout << "=> Vector A"; v2.display();
	v = v1.sub(v2);
	cout << "Tong 2 vector "; v.display();
	return 0;
}
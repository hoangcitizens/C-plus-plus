#include<iostream>
using namespace std;

class SP
{
public:
	SP(int,int);
	~SP();
	void display();
	SP sub(SP);
private:
	int a, b; // phan thuc va ao 
};

SP::SP(int a = 0, int b = 0) 
{
	this->a = a;
	this->b = b;
}

SP::~SP() {}
void SP::display()   
{
	if (b < 0)
		cout << a << " - " << -b << "i" << endl;
	else
		cout << a << " + " << b << "i" << endl;
}
SP SP::sub(SP z1)
{
	SP z2;
	z2.a = this->a + z1.a;
	z2.b = this->b + z1.b;
	return z2;
}

int main()
{
	SP z1(-3, 4), z2(2, -3), z3(2,2), z12, z123;
	cout << "So phuc 1: "; z1.display();
	cout << "So phuc 2: "; z2.display();
	cout << "So phuc 3: "; z3.display();
	z12 = z1.sub(z2);
	cout << "Tong 2 so phuc z1 + z2 = "; z12.display();
	z123 = z3.sub(z1.sub(z2));
	cout << "Tong 3 so phuc z1 + z2 + z3 = "; z123.display();
	return 0;
}
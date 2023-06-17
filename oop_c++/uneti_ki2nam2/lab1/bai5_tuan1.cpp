#include<iostream>
#include<math.h>
using namespace std;

class Phanso
{
public:
	Phanso(int, int);
	~Phanso();
	void rutGon();
	void display();
	Phanso sub(Phanso);
	Phanso mul(Phanso);
private:
	int t, m;
};

Phanso::Phanso(int tu = 0, int mau = 1)
{
	this->t = t;
	this->m = m;
}
Phanso::~Phanso(){}
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
void Phanso::rutGon()
{
	if (t != 0)
	{
		int u = UCLN(t, m);
		t /= u;
		m /= u;
	}
}
void Phanso::display()
{
	if (m < 0)
	{
		t *= -1;
		m *= -1;
		cout << t << "/" << m << endl;
	}
	else if (t % m == 0)
		cout << t / m << endl;
	else
		cout << t << "/" << m << endl;
}
Phanso Phanso::sub(Phanso p1)
{
	Phanso p2;
	p2.t = p1.t * this->m + this->t * p1.m;
	p2.m = p1.m * this->m;
	p2.rutGon();
	return p2;
}
Phanso Phanso::mul(Phanso p1)
{
	Phanso p2;
	p2.t = p1.t * this->m - this->t * p1.m;
	p2.m = p1.m * this->m;
	p2.rutGon();
	return p2;
}
int main()
{
	Phanso pS, pM, p1(-1,2), p2(3,-4);
	cout << "Phan so thu nhat: "; p1.display();
	cout << "Phan so thu hai: "; p2.display();
	pS = p1.sub(p2);
	cout << "=> Tong 2 phan so: "; pS.display();
	pM = p1.mul(p2);
	cout << "=> Hieu 2 phan so: "; pM.display();
	return 0;
}

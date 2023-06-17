#include<iostream>
#include<math.h>
#include<string>
using namespace std;

class PS
{
public:
	void import();
	void rutGon();
	void display();
	PS sub(PS);
	PS mul(PS);
private:
	int t, m;
};

void PS::import()
{
	cout << "Nhap tu so: "; cin >> t;
	cout << "Nhap mau so: "; cin >> m;
	while (m == 0)
	{
		cout << "Nhap lai mau so != 0: "; cin >> m;
	}
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
void PS::rutGon()
{
	if (t != 0)
	{
		int u = UCLN(t,m);
		t /= u;
		m /= u;
	}
}
void PS::display()
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
PS PS::sub(PS p1)
{
	PS p2;
	p2.t = p1.t * this->m + this->t * p1.m;
	p2.m = p1.m * this->m;
	p2.rutGon();
	return p2;
}
PS PS::mul(PS p1)
{
	PS p2;
	p2.t = p1.t * this->t;
	p2.m = p1.m * this->m;
	p2.rutGon();
	return p2;
}

int main()
{
	int n;
	cout << "Nhap so luong phan so: "; cin >> n;
	PS* p = new PS[n];
	for (int i = 0; i < n; i++)
	{
		cout << "(*) Nhap phan so thu " << i + 1 << endl;
		p[i].import();
		cout << endl;
	}
	cout << "Phan so vua nhap la: \n";
	for (int i = 0; i < n; i++)
	{
		cout << "\t";
		p[i].display();
	}
	PS S, M;
	S = p[0];
	for (int i = 1; i < n; i++)
	{
		S = S.sub(p[i]);
	}
	cout << "Tong cua " << n << " phan so la: "; S.display();
	M = p[0];
	for (int i = 1; i < n; i++)
	{
		M = M.mul(p[i]);
	}
	cout << "Tich cua " << n << " phan so la: "; M.display();
 	return 0;
}

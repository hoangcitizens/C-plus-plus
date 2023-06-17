#include<iostream>
#include<math.h>
#include<string>
using namespace std;

class HCN
{
public:
	HCN(float,float);
	~HCN();
	void import();
	void display();
	float perimeter();
	float area();
private:
	float d; // chieu dai
	float r; // chieu rong
};

HCN::HCN(float d = 0,float r = 0)
{
	this->d = d;
	this->r = r;
}
HCN::~HCN(){}
void HCN::import()
{
	cout << "Nhap chieu dai HCN: "; cin >> d;
	cout << "Nhap chieu rong HCN: "; cin >> r;
	cout << endl;
}
float HCN::perimeter()
{
	return (d + r) * 2;
}
float HCN::area()
{
	return d * r;
}
void HCN::display()
{
	cout << "Chieu dai: " << d << endl
	  	 << "Chieu rong: " << r << endl
	  	 << "Chu vi: " << perimeter() << endl
	  	 << "Dien tich: " << area() << endl;
	cout << endl;
}

int main()
{
	int n;
	cout << "Nhap so luong HCN: "; cin >> n;
	HCN *h = new HCN[n];
	for (int i = 0; i < n; i++)
	{
		cout << "(*) Nhap thong tin HCN thu " << i + 1 << endl;
		h[i].import();
	}
	for (int i = 0; i < n; i++)
	{
		cout << "(*) Thong tin HCN thu " << i + 1 << endl;
		h[i].display();
	}
	
	float max = h[0].perimeter();
	int p;
	for (int i = 1; i < n; i++)
	{
		if (h[i].perimeter() > max)
		{
			max = h[i].perimeter();
			p = i;
		}
	}
	cout << "<+> HCN co chu vi lon nhat la " << endl;
	h[p].display();
	
	float min = h[0].area();
	int q;
	for (int j = 1; j < n; j++)
	{
		if (h[j].area() < min)
		{
			min = h[j].area();
			q = j;
		}
	} 
	cout << "<+> HCN co dien tich nho nhat la " << endl;
	h[q].display();
	return 0;
}

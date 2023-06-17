#include<iostream>
#include<math.h>
#include<string>
#include<iomanip>
#include<fstream>
#define PI 3.14
using namespace std;

class Shape
{
public:
	virtual void import();
	virtual float sumC() = 0;
	virtual float sumS() = 0;
};
void Shape::import(){}

class Round : public Shape
{
public:
	Round(float);
	~Round();
	void import() override;
	float sumC();
	float sumS();
private:
	float r; // ban kinh
};
Round::Round(float r = 0)
{
	this->r = r;
}
Round::~Round(){}
void Round::import()
{
	cout << "Nhap ban kinh: "; cin >> r;
}
float Round::sumC()
{
	return 2 * PI * r;
}
float Round::sumS()
{
	return r * r * PI;
}

class Rec : public Shape
{
public:
	Rec(float,float);
	~Rec();
	void import() override;
	float sumC();
	float sumS();
private:
	float a, b; // chieu dai, chieu rong;
};
Rec::Rec(float a = 0,float b = 0)
{
	this->a = a;
	this->b = b;
}
Rec::~Rec() {}
void Rec::import()
{
	cout << "Nhap chieu dai: "; cin >> a;
	cout << "Nhap chieu rong: "; cin >> b;
}
float Rec::sumC()
{
	return (a + b) * 2;
}
float Rec::sumS()
{
	return a * b;
}

class Tri : public Shape
{
public:
	Tri(float, float, float);
	~Tri();
	void import() override;
	float sumC();
	float sumS();
private:
	float a, b, c; // 3 canh tam giac
};
Tri::Tri(float a = 0, float b = 0, float c = 0)
{
	this->a = a;
	this->b = b;
	this->c = c;
}
Tri::~Tri() {}
void Tri::import()
{
	cout << "Nhap canh day: "; cin >> a;
	cout << "Nhap canh ben 1: "; cin >> b;
	cout << "Nhap canh ben 2: "; cin >> c;
}
float Tri::sumC()
{
	return a + b + c;
}
float Tri::sumS()
{
	float p = (a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c)); // gia su h = c/2;
}

class QuanLyHinh
{
public:
	QuanLyHinh();
	void init();
	void tinhSumC();
	void tinhSumS();
	Shape* s[20];
	int n;
};
QuanLyHinh::QuanLyHinh() {}
void QuanLyHinh::init()
{
	int options;
	cout << "Nhap so luong hinh: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "(*) Nhap thong tin doc gia thu " << i + 1 << endl;
		do
		{
			cout << "\t_____________________" << endl
				<< "\t|1. Hinh tron        |" << endl
				<< "\t|2. Hinh chu nhat    |" << endl
				<< "\t|3. Hinh tam giac    |" << endl
				<< "\t|____________________|" << endl;
			cout << "\t<+> Nhap hinh: "; cin >> options;
			if (options != 1 && options != 2 && options != 3)
				cout << "\t(!) Vui long nhap lai lua chon cua ban !!!" << endl;
		} while (options != 1 && options != 2 && options != 3);
		if (options == 1)
			s[i] = new Round();
		if (options == 2)
			s[i] = new Rec();
		if (options == 3)
			s[i] = new Tri();
		s[i]->import();
	}
	cout << endl;
}
void QuanLyHinh::tinhSumC()
{
	float Sc = 0;
	for (int i = 0; i < n; i++)
	{
		Sc += s[i]->sumC();
	}
	cout << "\t=> Tong chu vi cua " << n << " hinh la: " << Sc << endl;
}
void QuanLyHinh::tinhSumS()
{
	float Ss = 0;
	for (int i = 0; i < n; i++)
	{
		Ss += s[i]->sumS();
	}
	cout << "\t=> Tong dien tich cua " << n << " hinh la: " << Ss << endl;
}

int main()
{
	QuanLyHinh q;
	q.init();
	q.tinhSumC();
	q.tinhSumS();
	return 0;
}
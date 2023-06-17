#include<iostream>
#include<iomanip>
#include<string>
#include<math.h>
using namespace std;

class Sophuc
{
public:
	Sophuc(float,float);
	~Sophuc();
	friend istream& operator >> (istream&, Sophuc&);
	friend ostream& operator << (ostream&, Sophuc&);
private:
	float a; // phan thuc
	float b; // phan ao
};

Sophuc::Sophuc(float a = 0, float b = 0)
{
	this->a = a;
	this->b = b;
}
Sophuc::~Sophuc() {}
istream& operator >> (istream& is, Sophuc& s)
{
	cout << "Nhap phan thuc: "; is >> s.a;
	cout << "Nhap phan ao: "; is >> s.b;
	return is;
}
ostream& operator << (ostream& os, Sophuc& s)
{
	if (s.b < 0)
		os << s.a << " - " << -s.b << "i" << endl;
	else
		os << s.a << " + " << s.b << "i" << endl;
	return os;
}

int main()
{
	Sophuc s[2];
	for (int i = 0; i < 2; i++)
	{
		cout << "<*> Nhap so phuc thu " << i + 1 << endl;
		cin >> s[i];
		cout << endl;
	}
	cout << "=> So phuc vua nhap: " << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << "\t";
		cout << s[i];
	}
	return 0;
}
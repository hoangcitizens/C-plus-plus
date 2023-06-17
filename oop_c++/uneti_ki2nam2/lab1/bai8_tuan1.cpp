#include<iostream>
#include<math.h>
#include<string>
using namespace std;

class Khachhang
{
public:
	Khachhang();
	Khachhang(char*,int,int,int, char*, char*);
	~Khachhang();
	void display();
private:
	char ht[30];
	struct NS
	{
		int d, m, y;
	};
	NS ns;
	char cmt[10];
	char k[30];
};

Khachhang::Khachhang()
{
	strcpy_s(ht, "Unknown");
	ns.d = ns.m = ns.y = 1;
	strcpy_s(cmt, "Unknown");
	strcpy_s(k, "Unknown");
}
Khachhang::Khachhang(char* ht,int day,int month,int year, char* cmt, char* k)
{
	strcpy_s(this->ht, ht);
	this->ns.d = day;
	this->ns.m = month;
	this->ns.y = year;
	strcpy_s(this->cmt, cmt);
	strcpy_s(this->k, k);
}
Khachhang::~Khachhang() {}
void Khachhang::display()
{
	cout << "Ho va ten: " << ht << endl
		 << "Ngay sinh: " << ns.d << "/" << ns.m << "/" << ns.y << endl
		 << "So chung minh thu: " << cmt << endl
		 << "Ho khau: " << k << endl;
}

int main()
{
	int d = 8, m = 4, y = 2023;
	char* name = new char[30];
	strcpy_s(name, 29, "Nguyen Huu Hoang");
	char* id = new char[11];
	strcpy_s(id, 10, "122313423");
	char* address = new char[30];
	strcpy_s(address, 29,"Thai Binh");
	Khachhang* kh = new Khachhang(name, d, m , y , id, address);
	kh->display();
	return 0;
}

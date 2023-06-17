#include<iostream>
#include<string>
#include<math.h>
#include<iomanip>
using namespace std;

class Congnhan
{
public:
	Congnhan();
	Congnhan(char*,char*,float, int);
	~Congnhan();
	void display();
	float tinhLuong();
private:
	char ht[25];
	char qq[25];
	float bl;
	int t;
};

Congnhan::Congnhan()
{
	strcpy_s(ht, "Unknown");
	strcpy_s(qq, "Unknown");
	bl = 0;
	t = 0;
}
Congnhan::Congnhan(char* ht,char* qq,float bl,int t)
{
	strcpy_s(this->ht, ht);
	strcpy_s(this->qq, qq);
	this->bl = bl;
	this->t = t;
}
Congnhan::~Congnhan() {}
float Congnhan::tinhLuong()
{
	return (bl * 2500) + (0.2 * (bl * 2500));
}
void Congnhan::display()
{
	cout << "Ho va ten : " << ht << endl
		 << "Que quan : " << qq << endl
		 << "Bac luong: " << bl << endl
		 << "Tuoi: " << t << endl
		 << "Luong: " << tinhLuong() << endl;
}

int main()
{
	char* name = new char[25];
	strcpy_s(name,24,"Nguyen Van A");
	char* address = new char[25];
	strcpy_s(address,24,"Ha Noi");
	Congnhan* cn = new Congnhan(name,address,5,20);
	cn->display();
	return 0;
}
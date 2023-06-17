#include<iostream>
#include<math.h>
#include<string>
using namespace std;

class Giaovien
{
public:
	Giaovien();
	Giaovien(char*,int,char*,char*,float);
	~Giaovien();
	void nhap();
	void xuat();
	float tinhLuong();
private:
	char ht[30]; // ho va ten
	int t; // tuoi
	char bc[15]; // bang cap
	char cn[20]; // chuyen nganh
	float bl;	// bac luong
};

Giaovien::Giaovien() 
{
	strcpy_s(ht,"Unknown");
	t = 0;
	strcpy_s(bc,"Unknown");
	strcpy_s(cn,"Unknown");
	bl = 0;
}
Giaovien::Giaovien(char* ht,int t,char* bc,char* cn,float bl)
{
	strcpy_s(this->ht,ht);
	this->t = t;
	strcpy_s(this->bc,bc);
	strcpy_s(this->cn,cn);
	this->bl = bl;
}
void Giaovien::nhap()
{
	fflush(stdin);
	cout << "Nhap ho va ten giao vien: "; cin.getline(ht,30);
	cout << "Nhap tuoi: "; cin >> t;
	fflush(stdin);
	cout << "Nhap bang cap: "; cin.getline(bc,15);
	cout << "Nhap chuyen nganh: "; cin.getline(cn,20);
	cout << "Nhap bac luong: "; cin >> bl;
}
float Giaovien::tinhLuong()
{
	return bl * 1490;
}
void Giaovien::xuat()
{
	cout << "Ho va ten: " << ht << endl
		 << "Tuoi: " << t << endl
		 << "Bang cap: " << bc << endl
		 << "Chuyen nganh: " << cn << endl
		 << "Bac luong: " << bl << endl
		 << "Luong: " << tinhLuong() << endl;
}

int main()
{
	Giaovien *gv = new Giaovien;
	gv->nhap();
	cout << "\n-------In thong tin---------" << endl;
	gv->xuat();
 	return 0;
}

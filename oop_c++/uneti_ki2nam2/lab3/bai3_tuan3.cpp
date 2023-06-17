#include<iostream>
#include<iomanip>
#include<string>
#include<math.h>
#include<fstream>
using namespace std;

class Giaovien
{
public:
	Giaovien();
	Giaovien(char*, int, char*, char*, float);
	~Giaovien();
	char* getht();
	int gett();
	char* getbc();
	char* getcn();
	float getbl();
	void setht(char*);
	void sett(int);
	void setbc(char*);
	void setcn(char*);
	void setbl(float);
	friend istream& operator >> (istream&, Giaovien&);
	friend ostream& operator << (ostream&, Giaovien&);
	float tinhLuong();
	void doc(ifstream&);
private:
	char ht[30]; // ho va ten
	int t; // tuoi 
	char bc[15]; // bang cap
	char cn[20]; // chuyen nganh
	float bl; // bac luong
};
Giaovien::Giaovien()
{
	strcpy_s(ht, "Unknown");
	t = 0;
	strcpy_s(bc,"Unknown");
	strcpy_s(cn, "Unknown");
	bl = 0;
}
Giaovien::Giaovien(char* ht, int t, char* bc, char* cn, float bl)
{
	strcpy_s(this->ht, ht);
	this->t = t;
	strcpy_s(this->bc, bc);
	strcpy_s(this->cn, cn);
	this->bl = bl;
}
Giaovien::~Giaovien() {}
float Giaovien::tinhLuong()
{
	return bl * 610;
}
istream& operator >> (istream& is, Giaovien& gv)
{
	cin.ignore();
	cout << "Nhap ho va ten: "; is.getline(gv.ht, 30);
	cout << "Nhap tuoi: "; is >> gv.t;
	cin.ignore();
	cout << "Nhap bang cap: "; is.getline(gv.bc, 15);
	cout << "Nhap chuyen nganh: "; is.getline(gv.cn, 20);
	cout << "Nhap bac luong: "; is >> gv.bl;
	return is;
}
ostream& operator << (ostream& os, Giaovien& gv)
{
	os << "\t"
	   << left << setw(30) << gv.ht
	   << left << setw(10) << gv.t
	   << left << setw(15) << gv.bc
	   << left << setw(20) << gv.cn
	   << left << setw(15) << gv.bl
	   << left << setw(15) << gv.tinhLuong()
	   << endl;
	return os;
}
char* Giaovien::getht()
{
	return ht;
}
int Giaovien::gett()
{
	return t;
}
char* Giaovien::getbc()
{
	return bc;
}
char* Giaovien::getcn()
{
	return cn;
}
float Giaovien::getbl()
{
	return bl;
}
void Giaovien::setht(char* ht)
{
	strcpy_s(this->ht, ht);
}
void Giaovien::sett(int t)
{
	this->t = t;
}
void Giaovien::setbc(char* bc)
{
	strcpy_s(this->bc, bc);
}
void Giaovien::setcn(char* cn)
{
	strcpy_s(this->cn, cn);
}
void Giaovien::setbl(float bl)
{
	this->bl = bl;
}
void Giaovien::doc(ifstream& in)
{
	in.getline(ht, 30);
	in >> t;
	in.ignore();
	in.getline(bc, 15);
	in.getline(cn, 20);
	in >> bl;
	char ss[5];
	in.getline(ss, 3);
	this->setht(ht);
	this->sett(t);
	this->setbc(bc);
	this->setcn(cn);
	this->setbl(bl);
}

void tieude()
{
	cout << "\t"
		 << left << setw(30) << "Ho va ten"
		 << left << setw(10) << "Tuoi"
		 << left << setw(15) << "Bang cap"
		 << left << setw(20) << "Chuyen nganh"
		 << left << setw(15) << "Bac luong"
		 << left << setw(15) << "Luong co ban"
		 << endl;
}
void input(Giaovien a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "(*) Nhap thong tin giao vien thu " << i + 1 << endl;
		cin >> a[i];
		cout << endl;
	}
}
void output(Giaovien a[], int n)
{
	cout << "\t_____________________________________DANH SACH THONG TIN GIAO VIEN____________________________________" << endl;
	tieude();
	for (int i = 0; i < n; i++)
	{
		cout << a[i];
	}
}
void luongTren2000(Giaovien a[], int n)
{
	cout << "\t_________________________________DANH SACH GIAO VIEN LUONG TREN 2000__________________________________" << endl;
	tieude();
	for (int i = 0; i < n; i++)
	{
		if (a[i].tinhLuong() > 2000)
			cout << a[i];
	}
}
void findName(Giaovien a[], int &n)
{
	int count = 0, m;
	char x[30];
	cin.ignore();
	cout << "\t(+) Nhap ten giao vien can tim: "; cin.getline(x, 30);
	for (int i = 0; i < n; i++)
	{
		if (strcmp(a[i].getht(), x) == 0)
		{
			count++;
			m = i;
		}
	}
	if (count != 0)
	{
		cout << "\t=> Co giao vien " << x << " trong danh sach" << endl;
		cout << "\t_________________________THONG TIN GIAO VIEN " << x << " trong danh sach________________________" << endl;
		tieude();
		cout << a[m];
	}
	else
	{
		cout << "\t(!) Khong co giao vien " << x << " trong danh sach" << endl;
		cout << "(*) Nhap thong tin cho giao vien " << x << endl;
		char* name = new char[30]; strcpy_s(name, 29, x); a[n].setht(name);
		int tuoi; float bacluong;
		cout << "Nhap tuoi: "; cin >> tuoi; a[n].sett(tuoi);
		cin.ignore();
		cout << "Nhap bang cap: "; cin.getline(a[n].getbc(), 15);
		cout << "Nhap chuyen nganh: "; cin.getline(a[n].getcn(), 20);
		cout << "Nhap bac luong: "; cin >> bacluong; a[n].setbl(bacluong);
		n++;
		output(a, n);
	}
}

void Menu()
{
	int n, options;
	ifstream ifs("bai3_tuan3.txt", ios::in);
	cout << "Nhap so luong giao vien: "; ifs >> n; cout << n;
	cout << endl;
	char ss[5];
	ifs.getline(ss, 5);
	Giaovien* g = new Giaovien[n];
	do
	{
		cout << "\t______________________MENU_______________________" << endl
			<< "\t|1. Nhap va in danh sach thong tin giao vien     |" << endl
			<< "\t|2. In danh sach giao vien co luong < 2000       |" << endl
			<< "\t|3. Tim giao vien trong danh sach                |" << endl
			<< "\t|4. Thoat !                                      |" << endl
			<< "\t|________________________________________________|" << endl;
		cout << "\t<+> Nhap lua chon cua ban: "; cin >> options;
		switch (options)
		{
		case 1:
		{
			//input(g, n);
			for (int i = 0; i < n; i++)
			{
				g[i].doc(ifs);
			}
			output(g, n);
			ifs.close();
			break;
		}
		case 2:
		{
			luongTren2000(g, n);
			break;
		}
		case 3:
		{
			findName(g, n);
			break;
		}
		case 4:
		{
			cout << "(!) Thoat ! Chuong trinh ket thuc !!!" << endl;
			break;
		}
		default:
			cout << "\t(!) Khong co lua chon nay ! Vui long lua chon lai !!!" << endl;
			cout << "\t<+> Nhap lua chon cua ban: "; cin >> options;
			if (options == 4)
				cout << "\t(!) Thoat ! Chuong trinh ket thuc !!!" << endl;
			break;
		}
	} while (options != 4);
	delete[]g;
}

int main()
{
	Menu();
	return 0;
}
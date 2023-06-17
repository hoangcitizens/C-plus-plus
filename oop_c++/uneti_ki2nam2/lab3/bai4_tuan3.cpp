#include<iostream>
#include<iomanip>
#include<string.h>
#include<math.h>
#include<fstream>
using namespace std;

class Maytinh
{
public:
	Maytinh();
	Maytinh(int,char*,float,int,float);
	~Maytinh();
	friend istream& operator >> (istream&, Maytinh&);
	float tinhTien();
	friend ostream& operator << (ostream&, Maytinh&);
	int getmh();
	char* gethsx();
	float getdg();
	int getdl();
	float getkg();
	void setmh(int);
	void sethsx(char*);
	void setdg(float);
	void setdl(int);
	void setkg(float);
	friend void findName(Maytinh a[], int& n);
	void doc(ifstream&);
	void ghi(ofstream&);
private:
	int mh; // ma hang
	char hsx[20]; // ten hang san xuat
	float dg; // dongia
	int dl; // dung luong RAM
	float kg; // trong luong
};

Maytinh::Maytinh()
{
	this->mh = 0;
	strcpy_s(this->hsx, "Unknown");
	this->dg = 0;
	this->dl = 0;
	this->kg = 0;
}
Maytinh::Maytinh(int mh,char *hsx, float dg, int dl, float kg)
{
	this->mh = mh;
	strcpy_s(this->hsx, hsx);
	this->dg = dg;
	this->dl = dl;
	this->kg = kg;
}
Maytinh::~Maytinh(){}
istream& operator >> (istream& is, Maytinh& m)
{
	cout << "Nhap ma hang: ";  is >> m.mh;
	cin.ignore();
	cout << "Nhap ten hang san xuat: "; is.getline(m.hsx, 20);
	cout << "Nhap don gia: "; is >> m.dg;
	cout << "Nhap dung luong: "; is >> m.dl;
	cout << "Nhap khoi luong: "; is >> m.kg;
	return is;
}
float Maytinh::tinhTien()
{
	if (kg > 2)
		return 100000;
	else if (kg < 2 && kg > 1)
		return 50000;
	else
		return 30000;
}
ostream& operator << (ostream& os, Maytinh& m)
{
	os << "\t"
	   << left << setw(10) << m.mh
	   << left << setw(20) << m.hsx
	   << left << setw(15) << m.dg
	   << left << setw(15) << m.dl
	   << left << setw(15) << m.kg
	   << left << setw(15) << m.tinhTien()
	   << endl;
	return os;
}
int Maytinh::getmh()
{
	return mh;
}
char* Maytinh::gethsx()
{
	return hsx;
}
float Maytinh::getdg()
{
	return dg;
}
int Maytinh::getdl()
{
	return dl;
}
float Maytinh::getkg()
{
	return kg;
}
void Maytinh::setmh(int mh)
{
	this->mh = mh;
}
void Maytinh::sethsx(char* hsx)
{
	strcpy_s(this->hsx, hsx);
}
void Maytinh::setdg(float dg)
{
	this->dg = dg;
}
void Maytinh::setdl(int dl)
{
	this->dl = dl;
}
void Maytinh::setkg(float kg)
{
	this->kg = kg;
}
void Maytinh::doc(ifstream& in)
{
	in >> mh;
	in.ignore();
	in.getline(hsx, 20);
	in >> dg;
	in >> dl;
	in >> kg;
	char ss[5];
	in.getline(ss, 3);
	this->setmh(mh);
	this->sethsx(hsx);
	this->setdg(dg);
	this->setdl(dl);
	this->setkg(kg);
}

void tieude()
{
	cout << "\t"
		 << left << setw(10) << "Ma hang"
		 << left << setw(20) << "Hang san xuat"
		 << left << setw(15) << "Don gia"
		 << left << setw(15) << "Dung luong"
		 << left << setw(15) << "Khoi luong"
		 << left << setw(15) << "Tien van chuyen"
		 << endl;
}
void input(Maytinh a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "(*) Nhap thong tin may tinh thu " << i + 1 << endl;
		cin >> a[i];
		cout << endl;
	}
}
void output(Maytinh a[], int n)
{
	cout << "\t_______________________________DANH SACH THONG TIN MAY TINH_______________________________" << endl;
	tieude();
	for (int i = 0; i < n; i++)
	{
		cout << a[i];
	}
}
void dungLuongRAM(Maytinh a[], int n)
{
	cout << "\t_______________________________DANH SACH MAY TINH RAM = 16________________________________" << endl;
	tieude();
	for (int i = 0; i < n; i++)
	{
		if (a[i].getdl() == 16)
			cout << a[i];
	}
}
void findName(Maytinh a[], int &n)
{	
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (strcmp(a[i].hsx, "SONY") == 0) 
		{
			count++;
			for (int j = i; j < n; j++)
			{
				a[j] = a[j + 1];
			}
			n--;
		}
	}
	if (count == 0) 
	{
		cout << "\t(!) Khong co hang 'SONY' trong danh sach . Them thong tin hang 'SONY' vao danh sach !!!" << endl;
		cout << "(*) Nhap thong tin cho hang SONY" << endl;
		strcpy_s(a[n].hsx,"SONY");
		cout << "Nhap ma hang: ";    cin >> a[n].mh; 
		cout << "Nhap don gia: ";    cin >> a[n].dg; 
		cout << "Nhap dung luong: "; cin >> a[n].dl; 
		cout << "Nhap khoi luong: "; cin >> a[n].kg;
		cout << "\t___________________DANH SACH MAY TINH SAU KHI THEM HANG SAN XUAT SONY_____________________" << endl;
		tieude();
		n++;
		for (int i = 0; i < n; i++)
		{
			cout << a[i];
		}
	}
	else
	{
		cout << "\t_______________________DANH SACH MAY TINH SAU KHI XOA HANG SAN XUAT SONY_______________________" << endl;
		tieude();
		for (int i = 0; i < n; i++)
		{
			cout << a[i];
		}
	}
}

void Menu()
{
	int n, options;
	ifstream ifs("bai4_tuan3.txt", ios::in);
	cout << "Nhap so luong may tinh: "; cin >> n;
	cout << endl;
	char ss[5];
	ifs.getline(ss, 5);
	Maytinh mt[100];
	//Maytinh* mt = new Maytinh[n];
	do
	{
		cout << "\t_______________________MENU_________________________" << endl
			 << "\t|1. Nhap va in danh sach thong tin may tinh         |" << endl
			 << "\t|2. In danh sach may tinh co dung luong RAM = 16    |" << endl
			 << "\t|3. Tim hang san xuat 'SONY' trong danh sach        |" << endl
			 << "\t|4. Thoat !                                         |" << endl
			 << "\t|___________________________________________________|" << endl;
		cout << "\t<+> Nhap lua chon cua ban: "; cin >> options;
		switch (options)
		{
		case 1:
		{
			//input(mt, n);
			for (int i = 0; i < n; i++)
			{
				mt[i].doc(ifs);
			}
			output(mt, n);
			ifs.close();
			break;
		}
		case 2:
		{
			dungLuongRAM(mt, n);
			break;
		}
		case 3:
		{
			findName(mt, n);
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
				cout << "(!) Thoat ! Chuong trinh ket thuc !!!" << endl;
			break;
		}
	} while (options != 4);
}

int main()
{
	Menu();
	return 0;
}
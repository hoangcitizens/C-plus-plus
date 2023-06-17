#include<iostream>
#include<iomanip>
#include<string>
#include<math.h>
#include<fstream>
using namespace std;

class Oto
{
public:
	Oto();
	Oto(int, char*, float, int, float);
	~Oto();
	friend istream& operator >> (istream&, Oto&);
	float tinhTien();
	friend ostream& operator << (ostream&, Oto&);
	bool operator == (float);
	/*bool operator == (Oto);
	bool operator == (Oto);
	bool operator == (Oto);
	bool operator == (Oto);*/
	int getmh();
	char* gethsx();
	float getdg();
	float getdt();
	float getkg();
	void setmh(int);
	void sethsx(char*);
	void setdg(float);
	void setdt(float);
	void setkg(float);
	friend void findName(Oto a[], int& n);
	void doc(ifstream&);
private:
	int mh; // ma hang
	char hsx[20]; // ten hang san xuat
	float dg; // don gia
	float dt; // dung tich xilanh
	float kg; // trong luong
};

Oto::Oto()
{
	this->mh = 0;
	strcpy_s(this->hsx, "Unkown");
	this->dg = 0;
	this->dt = 0;
	this->kg = 0;
}
Oto::Oto(int mh, char* hsx, float dg, int dt, float kg)
{
	this->mh = mh;
	strcpy_s(this->hsx, hsx);
	this->dg = dg;
	this->dt = dt;
	this->kg = kg;
}
Oto::~Oto() {}
istream& operator >> (istream& is, Oto& o)
{
	cout << "Nhap ma hang: ";  is >> o.mh;
	cin.ignore();
	cout << "Nhap ten hang san xuat: "; is.getline(o.hsx, 20);
	cout << "Nhap don gia: "; is >> o.dg;
	cout << "Nhap dung tich xilanh: "; is >> o.dt;
	cout << "Nhap khoi luong: "; is >> o.kg;
	return is;
}
float Oto::tinhTien()
{
	if (kg > 2)
		return 100000;
	else if (kg < 2 && kg > 1)
		return 50000;
	else
		return 30000;
}
ostream& operator << (ostream& os, Oto& o)
{
	os << "\t"
		<< left << setw(10) << o.mh
		<< left << setw(20) << o.hsx
		<< left << setw(15) << o.dg
		<< left << setw(15) << o.dt
		<< left << setw(15) << o.kg
		<< left << setw(15) << o.tinhTien()
		<< endl;
	return os;
}
bool Oto::operator == (float x)
{
	if (this->dt == x)
		return true;
	else
		return false;
}
int Oto::getmh()
{
	return mh;
}
char* Oto::gethsx()
{
	return hsx;
}
float Oto::getdg()
{
	return dg;
}
float Oto::getdt()
{
	return dt;
}
float Oto::getkg()
{
	return kg;
}
void Oto::setmh(int mh)
{
	this->mh = mh;
}
void Oto::sethsx(char *hsx)
{
	strcpy_s(this->hsx, hsx);
}
void Oto::setdg(float dg)
{
	this->dg = dg;
}
void Oto::setdt(float dt)
{
	this->dt = dt;
}
void Oto::setkg(float kg)
{
	this->kg = kg;
}
void Oto::doc(ifstream& in)
{
	in >> mh;
	in.ignore();
	in.getline(hsx, 20);
	in >> dg;
	in >> dt;
	in >> kg;
	char ss[5];
	in.getline(ss, 3);
	this->setmh(mh);
	this->sethsx(hsx);
	this->setdg(dg);
	this->setdt(dt);
	this->setkg(kg);
}

void tieude()
{
	cout << "\t"
		<< left << setw(10) << "Ma hang"
		<< left << setw(20) << "Hang san xuat"
		<< left << setw(15) << "Don gia"
		<< left << setw(15) << "Dung tich"
		<< left << setw(15) << "Khoi luong"
		<< left << setw(15) << "Tien van chuyen"
		<< endl;
}
void input(Oto a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "(*) Nhap thong tin o to thu " << i + 1 << endl;
		cin >> a[i];
		cout << endl;
	}
}
void output(Oto a[], int n)
{
	cout << "\t_______________________________DANH SACH THONG TIN O TO_______________________________" << endl;
	tieude();
	for (int i = 0; i < n; i++)
	{
		cout << a[i];
	}
}
void dungtich(Oto a[], int n)
{
	cout << "\t_______________________________DANH SACH OTO DUNG TICH XILANH = 2.5________________________________" << endl;
	tieude();
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 2.5)
			cout << a[i];
	}
}
void findName(Oto a[], int& n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(a[i].hsx, "TOYOTA") == 0)		
		{
			count++;
			for (int j = i; j < n; j++)
			{
				a[j] = a[j + 1];
			}
			n--;
		}
	}
	if (count != 0)
	{
		cout << "\t_______________________DANH SACH O TO SAU KHI XOA HANG SAN XUAT TOYOTA_______________________" << endl;
		tieude();
		for (int i = 0; i < n; i++)
		{
			cout << a[i];
		}
	}
	else
	{
		for (int i = n - 1; i >= 0; i--)
		{
			a[i + 1] = a[i];
		}
		cout << "\t(!) Khong co hang 'TOYOTA' trong danh sach . Them thong tin hang 'TOYOTA' vao danh sach !!!" << endl;
		cout << "(*) Nhap thong tin cho hang TOYOTA" << endl;
		strcpy_s(a[0].hsx,"TOYATA");
		cout << "Nhap ma hang: ";          cin >> a[0].mh;
		cout << "Nhap don gia: ";          cin >> a[0].dg;
		cout << "Nhap dung tich xilanh: "; cin >> a[0].dt;
		cout << "Nhap khoi luong: ";       cin >> a[0].kg;
		n++;
		cout << "\t___________________DANH SACH O TO SAU KHI THEM HANG SAN XUAT TOYOTA_____________________" << endl;
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
	ifstream ifs("bai7_tuan3.txt", ios::in);
	cout << "Nhap so luong o to: "; ifs >> n; cout << n;
	cout << endl;
	char ss[5];
	ifs.getline(ss, 5);
	Oto ot[100];
	//Oto* ot = new Oto[n];
	do
	{
		cout << "\t_______________________MENU_________________________" << endl
			<< "\t|1. Nhap va in danh sach thong tin o to             |" << endl
			<< "\t|2. In danh sach o to co dung tich xilanh = 2.5     |" << endl
			<< "\t|3. Tim hang san xuat 'TOYOTA' trong danh sach      |" << endl
			<< "\t|4. Thoat !                                         |" << endl
			<< "\t|___________________________________________________|" << endl;
		cout << "\t<+> Nhap lua chon cua ban: "; cin >> options;
		switch (options)
		{
		case 1:
		{
			//input(o, n);
			for (int i = 0; i < n; i++)
			{
				ot[i].doc(ifs);
			}
			output(ot, n);
			ifs.close();
			break;
		}
		case 2:
		{
			dungtich(ot, n);
			break;
		}
		case 3:
		{
			findName(ot, n);
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
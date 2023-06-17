#include<iostream>
#include<iomanip>
#include<string>
#include<math.h>
#include<fstream>
using namespace std;

class Benhnhan
{
public:
	Benhnhan(string, string, int);
	~Benhnhan();
	void import();
	void display();
	int getYearbirth();
protected:
	string fullname;
	string address;
	int yearbirth;
};

Benhnhan::Benhnhan(string fullname = "Unknown", string address = "Unknown", int yearbirth = 0)
{
	this->fullname = fullname;
	this->address = address;
	this->yearbirth = yearbirth;
}
Benhnhan::~Benhnhan(){}
void Benhnhan::import()
{
	cin.ignore();
	cout << "Nhap ho va ten benh nhan: "; getline(cin, fullname);
	cout << "Nhap dia chi benh nhan: "; getline(cin, address);
	cout << "Nhap nam sinh benh nhan: "; cin >> yearbirth;
	while (yearbirth < 1900 || yearbirth > 2023)
	{
		cout << "Nhap lai nam sinh (1899 < nam < 2024): "; cin >> yearbirth;
	}
}
void Benhnhan::display()
{
	cout << "\t"
		 << left << setw(20) << fullname
		 << left << setw(20) << address
		 << left << setw(15) << yearbirth;
}
int Benhnhan::getYearbirth()
{
	return yearbirth;
}

class Benhan : public Benhnhan
{
public:
	Benhan(string, string, int, string,int);
	~Benhan();
	void import();
	void display();
	int getFee();
private:
	string diseasename;
	int fee;
};

Benhan::Benhan(string fullname = "Unknown", string address = "Unknown", int yearbirth = 0, string diseasename = "Unknown", int fee = 0)
	: Benhnhan(fullname, address, yearbirth)
{
	this->diseasename = diseasename;
	this->fee = fee;
}
Benhan::~Benhan(){}
void Benhan::import()
{
	Benhnhan::import();
	cin.ignore();
	cout << "Nhap ten benh an: "; getline(cin, diseasename);
	cout << "Nhap tien vien phi: "; cin >> fee;
}
void Benhan::display()
{
	Benhnhan::display();
	cout << left << setw(20) << diseasename
		 << left << setw(15) << fee
		 << endl;
}
int Benhan::getFee()
{
	return fee;
}
void title()
{
	cout << "\t"
		 << left << setw(20) << "Ho va ten"
		 << left << setw(20) << "Que quan"
		 << left << setw(15) << "Nam sinh"
	     << left << setw(20) << "Benh an"
		 << left << setw(15) << "Vien phi"
		 << endl;
}
void input(Benhan a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "(*) Nhap thong tin benh an thu " << i + 1 << endl;
		a[i].import();
		cout << endl;
	}
}
void output(Benhan a[], int n)
{
	cout << "\t____________________________DANH SACH HO SO BENH AN_______________________________" << endl;
	title();
	for (int i = 0; i < n; i++)
	{
		a[i].display();
	}
}
void arrange(Benhan a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].getYearbirth() > a[j].getYearbirth())
				swap(a[i], a[j]);
		}
	}
	cout << "\t______________DANH SACH HO SO BENH AN SAP XEP THEO TUOI GIAM DAN__________________" << endl;
	title();
	for (int i = 0; i < n; i++)
	{
		a[i].display();
	}
}
void age50(Benhan a[], int n)
{
	cout << "\t________________________DANH SACH HO SO BENH NHAN > 50 TUOI_______________________" << endl;
	title();
	for (int i = 0; i < n; i++)
	{
		if (a[i].getYearbirth() < 1973)
			a[i].display();
	}
}
void feemax(Benhan a[], int n)
{
	cout << "\t______________________THONG TIN BENH NHAN CO VIEN PHI CAO NHAT_____________________" << endl;
	title();
	int max = a[0].getFee();
	for (int i = 1; i < n; i++)
	{
		if (a[i].getFee() > max)
			a[i].display();
	}
}

void Menu()
{
	int n, options;
	cout << "Nhap so luong benh an: "; cin >> n;
	Benhan* b = new Benhan[n];
	do
	{
		cout << "\t____________________________________MENU__________________________________________" << endl
			 << "\t|1. Nhap va in thong tin ho so benh an                                            |" << endl
			 << "\t|2. Sap xep danh sach benh an theo tuoi giam dan cua cac benh nhan                |" << endl
			 << "\t|3. In ra man hinh benh cua nhung benh nhan tuoi > 50                             |" << endl
			 << "\t|4. Hien thi thong tin benh an cua benh nhan co vien phi cao nhat                 |" << endl
			 << "\t|5. Thoat                                                                         |" << endl
			 << "\t|_________________________________________________________________________________|" << endl;
		cout << "\t(+) Nhap lua chon cua ban: "; cin >> options;
		switch (options)
		{
		case 1:
		{
			input(b, n);
			output(b, n);
			break;
		}
		case 2:
		{
			arrange(b, n);
			break;
		}
		case 3:
		{
			age50(b, n);
			break;
		}
		case 4:
		{
			feemax(b, n);
			break;
		}
		case 5:
		{
			cout << "\t(!) Thoat ! Chuong trinh ket thuc !" << endl;
			break;
		}
		default:	
			cout << "\t(!) Khong co lua chon vui long chon lai !!!" << endl;
			cout << "\t(+) Nhap lua chon cua ban: "; cin >> options;
			if (options == 5)
			{
				cout << "\t(!) Thoat ! Chuong trinh ket thuc !" << endl;
				break;
			}
			break;
		}
	} while (options != 5);
}

int main()
{
	Menu();
	return 0;
}
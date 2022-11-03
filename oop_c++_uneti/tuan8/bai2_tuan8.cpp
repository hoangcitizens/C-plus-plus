#include<iostream>
#include<iomanip>
#include<string>
#include<math.h>
#include<conio.h>
using namespace std;

class Mayin
{
protected:
	char sh[15];
	int sl;
public:
	Mayin()
	{
		strcpy_s(sh, "");
		sl = 0;
	}
	Mayin(char* sh, int sl)
	{
		strcpy_s(this->sh, sh);
		this->sl = sl;
	}
	~Mayin(){}
	friend istream& operator >> (istream& is, Mayin& m)
	{
		cin.ignore();
		cout << "Nhap so hieu may in: "; cin.getline(m.sh, 15);
		while (strcmp(m.sh, "ml") != 0 && strcmp(m.sh, "mc") != 0 && strcmp(m.sh, "mlc") != 0)
		{
			cout << "Nhap lai so hieu may (ml,mc,mlc): "; cin.getline(m.sh, 15);
		}
		cout << "Nhap so luong may in: "; is >> m.sl;
		return is;
	}
	friend ostream& operator << (ostream& os,Mayin &m)
	{
		os << left << setw(15) << m.sh;
		os << left << setw(15) << m.sl;
		return os;
	}
};

class Mayinlaser : public virtual Mayin
{
protected:
	int dpi;
public:
	Mayinlaser() : Mayin()
	{
		dpi = 0;
	}
	Mayinlaser(int dpi,char* sh, int sl) : Mayin(sh,sl)
	{
		this->dpi = dpi;
	}
	~Mayinlaser() {}
	friend istream& operator >> (istream& is, Mayinlaser& ml)
	{
		cout << "Nhap chi so dpi: "; is >> ml.dpi;
		return is;
	}
	friend ostream& operator << (ostream& os, Mayinlaser& ml)
	{
		os << left << setw(15) << ml.dpi;
		return os;
	}
};

class Mayincolor : public virtual Mayin
{
protected:
	int bangmau;
public:
	Mayincolor() : Mayin()
	{
		bangmau = 0;
	}
	Mayincolor(int bangmau,char* sh, int sl) : Mayin(sh, sl)
	{
		this->bangmau = bangmau;
	}
	~Mayincolor() {}
	friend istream& operator >> (istream& is, Mayincolor& mc)
	{
		cout << "Nhap bang mau: "; is >> mc.bangmau;
		return is;
	}
	friend ostream& operator << (ostream& os, Mayincolor& mc)
	{
		os << left << setw(15) << mc.bangmau;
		return os;
	}
};

class Mayinlasercolor : public Mayinlaser , public Mayincolor
{
public:
	Mayinlasercolor() {};
	Mayinlasercolor(char* sh,int sl,int dpi,int bangmau) : Mayin(sh,sl) , Mayinlaser(dpi,sh,sl) , Mayincolor(bangmau,sh,sl) {}
	~Mayinlasercolor() {}
	friend istream& operator >> (istream& is,Mayinlasercolor& mlc)
	{
		is >> (Mayin&)mlc;
		is >> (Mayinlaser&)mlc;
		is >> (Mayincolor&)mlc;
		cout << endl;
		return is;
	}
	friend ostream& operator << (ostream& os, Mayinlasercolor& mlc)
	{
		cout << "\t";
		os << (Mayin&)mlc;
		os << (Mayinlaser&)mlc;
		os << (Mayincolor&)mlc;
		cout << endl;
		return os;
	}
};

void tieude()
{
	cout << "\t";
	cout << left << setw(15) << "So hieu";
	cout << left << setw(15) << "So luong";
	cout << left << setw(15) << "Chi so dpi";
	cout << left << setw(15) << "Bang mau";
	cout << endl;
}
void input(Mayinlasercolor a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "(*) Nhap thong tin may thu " << i + 1 << endl;
		cin >> a[i];
	}
}
void output(Mayinlasercolor a[], int n)
{
	cout << "\t_______________DANH SACH THONG TIN MAY IN_______________" << endl;
	tieude();
	for (int i = 0; i < n; i++)
	{
		cout << a[i];
	}
}

int main()
{
	int n;
	cout << "Nhap so luong may: "; cin >> n;
	Mayinlasercolor* m = new Mayinlasercolor[n];
	input(m, n);
	output(m, n);
	return 0;
}
#include<iostream>
#include<math.h>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;

class Nguoi
{
public:
	Nguoi(string);
	~Nguoi();
	virtual void import();
	virtual void display();
	virtual int find() = 0;
protected:
	string fullname;
};
Nguoi::Nguoi(string fullname = "Unknown")
{
	this->fullname = fullname;
}
Nguoi::~Nguoi(){}
void Nguoi::import()
{
	cin.ignore();
	cout << "Nhap ho va ten: "; getline(cin, fullname);
}
void Nguoi::display()
{
	cout << "\t"
		 << "|" << left << setw(24) << fullname;
}

class Sinhvien : public Nguoi
{
public:
	Sinhvien(string,float);
	~Sinhvien();
	void import() override;
	void display() override;
	int find();
private:
	float point; // diem thi
};
Sinhvien::Sinhvien(string fullname = "Unknown", float point = 0) : Nguoi(fullname)
{
	this->point = point;
}
Sinhvien::~Sinhvien(){}
void Sinhvien::import()
{
	Nguoi::import();
	cout << "Nhap diem thi: "; cin >> point;
}
void Sinhvien::display()
{
	Nguoi::display();
	cout << "|" << left << setw(14) << point
	     << "|" << left << setw(13) << "Unknown" << "|" << endl;
}
int Sinhvien::find()
{
	if (point > 8)
		return 1;
	return 0;
}

class Giaovien : public Nguoi
{
public:
	Giaovien(string, int);
	~Giaovien();
	void import() override;
	void display() override;
	int find();
private:
	int s; // so bai bao
};
Giaovien::Giaovien(string fullname = "Unknown", int s = 0) : Nguoi(fullname)
{
	this->s = s;
}
Giaovien::~Giaovien() {}
void Giaovien::import()
{
	Nguoi::import();
	cout << "Nhap so bai bao: "; cin >> s;
}
void Giaovien::display()
{
	Nguoi::display();
	cout << "|" << left << setw(14) << "Unknown"
	     << "|" << left << setw(13) << s << "|" << endl;
}
int Giaovien::find()
{
	if (s > 5)
		return 1;
	return 0;
}

void title()
{
	cout << "\t" << "_______________________________________________________" << endl << "\t"
		 << left << setw(25) << "|       Ho va ten"
		 << left << setw(15) << "|   Diem thi  "
		 << left << setw(15) << "|  So bai bao |" << endl << "\t"
		 << "*-----------------------------------------------------*" << endl;
}

class QuanLyNguoi
{
public:
	QuanLyNguoi();
	void init();
	void finds();
	Nguoi* ng[20];
	int n;
};

QuanLyNguoi::QuanLyNguoi() {}
void QuanLyNguoi::init()
{
	int options;
	cout << "Nhap so luong nguoi: "; cin >> n;
	for (int i = 0; i < n; i++)
	{	
		cout << "(*) Nhap thong tin nguoi thu " << i + 1 << endl;
		do
		{
			cout << "\t__________________" << endl
				 << "\t|1. Sinh vien    |" << endl
				 << "\t|2. Giao vien    |" << endl
				 << "\t|________________|" << endl;
			cout << "\t<+> Nhap nguoi: "; cin >> options;
			if (options != 1 && options != 2)
				cout << "\t(!) Vui long nhap lai lua chon cua ban !!!" << endl;
		} while (options != 1 && options != 2);
		if (options == 1)
			ng[i] = new Sinhvien();
		if (options == 2)
			ng[i] = new Giaovien();
		ng[i]->import();
	}
	cout << "\t\t\tDANH SACH THONG TIN NGUOI" << endl;
	title();
	for (int i = 0; i < n; i++)
	{
		ng[i]->display();
		cout << "\t*-----------------------------------------------------*" << endl;
	}
	cout << endl;
}
void QuanLyNguoi::finds()
{
	cout << "\t\t\tTHONG TIN NGUOI CAN TIM" << endl;
	title();
	for (int i = 0; i < n; i++)
	{
		if (ng[i]->find() == 1)
		{
			ng[i]->display();
			cout << "\t*-----------------------------------------------------*" << endl;
		}
	}
}

int main()
{
	QuanLyNguoi q;
	q.init();
	q.finds();
	return 0;
}
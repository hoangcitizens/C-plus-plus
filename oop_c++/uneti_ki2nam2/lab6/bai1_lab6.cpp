#include<iostream>
#include<math.h>
#include<string>
#include<iomanip>
using namespace std;

class DocGia
{
public:
	DocGia(string,string,int);
	~DocGia();
	virtual void import();
	virtual void display();
	virtual int options() = 0;
	virtual int find() = 0;
	virtual float sum() = 0;
protected:
	string ma; // ma
	string fullname; // ho va ten
	int month; // so thang hieu luc
};

DocGia::DocGia(string ma = "Unknown", string fullname = "Unknown", int month = 0)
{
	this->ma = ma;
	this->fullname = fullname;
	this->month = month;
}
DocGia::~DocGia(){}
void DocGia::import()
{
	cin.ignore();
	cout << "Nhap ma doc gia: "; getline(cin, ma);
	cout << "Nhap ho va ten: "; getline(cin, fullname);
	cout << "Nhap so thang hieu luc: "; cin >> month;
}
void DocGia::display()
{
	cout << "\t"
		 << "|" << left << setw(14) << ma
		 << "|" << left << setw(24) << fullname
		 << "|" << left << setw(14) << month;
}

class DocGiaTre : public DocGia
{
public:
	DocGiaTre(string,string,int,int);
	~DocGiaTre();
	void import() override;
	void display() override;
	int options();
	int find();
	float sum();
private:
	int yearbirth; // nam sinh
};

DocGiaTre::DocGiaTre(string ma = "Unknown", string fullname = "Unknown", int month = 0, int yearbirth = 0) 
	: DocGia(ma,fullname,month)
{
	this->yearbirth = yearbirth;
}
DocGiaTre::~DocGiaTre(){}
void DocGiaTre::import()
{
	DocGia::import();
	cout << "Nhap nam sinh doc gia: "; cin >> yearbirth;
}
void DocGiaTre::display()
{
	DocGia::display();
	cout << "|" << left << setw(13) << month << "|" << endl;
}
int DocGiaTre::options()
{
	return 1;
}
int DocGiaTre::find()
{
	if (month < 10)
		return 1;
	return 0;
}
float DocGiaTre::sum()
{
	return month * 20000;
}

class DocGiaLon : public DocGia
{
public:
	DocGiaLon(string, string, int, string);
	~DocGiaLon();
	void import() override;
	void display() override;
	int options();
	int find();
	float sum();
private:
	string job; // nghe nghiep
};

DocGiaLon::DocGiaLon(string ma = "Unknown", string fullname = "Unknown", int month = 0, string job = "Unknown")
	: DocGia(ma,fullname,month)
{
	this->job = job;
}
DocGiaLon::~DocGiaLon(){}
void DocGiaLon::import()
{
	DocGia::import();
	cin.ignore();
	cout << "Nhap nghe nghiep cua doc gia: "; getline(cin, job);
}
void DocGiaLon::display()
{
	DocGia::display();
	cout << "|" << left << setw(24) << job << "|" << endl;
}
int DocGiaLon::options()
{
	return 2;
}
int DocGiaLon::find()
{
	if (job == "Giao vien")
		return 1;
	return 0;
}
float DocGiaLon::sum()
{
	return month * 30000;
}

void title1()
{
	cout << "\t"
		<< "______________________________________________________________________" << endl << "\t"
		<< left << setw(15) << "|   Ma doc gia"
		<< left << setw(25) << "|       Ho va ten"
		<< left << setw(15) << "|Thang hieu luc"
		<< left << setw(15) << "|   Nam sinh  |" << endl << "\t"
		<< "*--------------------------------------------------------------------*" << endl;
}
void title2()
{
	cout << "\t"
		<< "_________________________________________________________________________________" << endl << "\t"
		<< left << setw(15) << "|   Ma doc gia"
		<< left << setw(25) << "|       Ho va ten"
		<< left << setw(15) << "|Thang hieu luc"
		<< left << setw(25) << "|       Nghe nghiep      |" << endl << "\t"
		<< "*-------------------------------------------------------------------------------*" << endl;
}
class QuanLyDocGia
{
public:
	QuanLyDocGia();
	void init();
	void finds();
	void sums();
	void menu();
	DocGia* d[20];
	int n;
};

QuanLyDocGia::QuanLyDocGia(){}
void QuanLyDocGia::init()
{
	int options;
	cout << "Nhap so luong doc gia: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "(*) Nhap thong tin doc gia thu " << i + 1 << endl;
		do
		{
			cout << "\t_____________________" << endl
				 << "\t|1. Doc gia tre     |" << endl
				 << "\t|2. Doc gia lon     |" << endl
				 << "\t|___________________|" << endl;
			cout << "\t<+> Nhap doc gia: "; cin >> options;
			if (options != 1 && options != 2)
				cout << "\t(!) Vui long nhap lai lua chon cua ban !!!" << endl;
		} while (options != 1 && options != 2);
		if (options == 1)
			d[i] = new DocGiaTre();
		if (options == 2)
			d[i] = new DocGiaLon();
		d[i]->import();
	}
	cout << "\t\t\t\tDANH SACH THONG TIN DOC GIA TRE" << endl;
	title1();
	for (int i = 0; i < n; i++)
	{
		if (d[i]->options() == 1)
		{
			d[i]->display();
			cout << "\t*--------------------------------------------------------------------*" << endl;
		}
	}
	cout << "\t\t\t\tDANH SACH THONG TIN DOC GIA LON" << endl;
	title2();
	for (int i = 0; i < n; i++)
	{
		if (d[i]->options() == 2)
		{
			d[i]->display();
			cout << "\t*-------------------------------------------------------------------------------*" << endl;
		}
	}
	cout << endl;
}
void QuanLyDocGia::finds()
{
	cout << "\t\t\t\tTHONG TIN DOC GIA TRE CAN TIM" << endl;
	title1();
	for (int i = 0; i < n; i++)
	{
		if (d[i]->options() == 1 && d[i]->find() == 1)
		{
			d[i]->display();
			cout << "\t*-------------------------------------------------------------------*" << endl;
		}
	}
	cout << "\t\t\t\tTHONG TIN DOC GIA GIA CAN TIM" << endl;
	title2();
	for (int i = 0; i < n; i++)
	{
		if (d[i]->options() == 2 && d[i]->find() == 1)
		{
			d[i]->display();
			cout << "\t*-------------------------------------------------------------------------------*" << endl;
		}
	}
	cout << endl;
}
void QuanLyDocGia::sums()
{
	float S = 0;
	for (int i = 0; i < n; i++)
	{
		S += d[i]->sum();
	}
	cout << "\t=>Tong tien lam the cua cac doc gia la: " << S << endl;
}

void QuanLyDocGia::menu()
{
	int options;
	do
	{
		cout << "\t___________________________________MENU__________________________________" << endl
			 << "\t|1. Quan ly danh sach cac loai doc gia.                                  |" << endl
			 << "\t|2. Tim doc gia tre so thang hieu luc < 10, doc gia lon la giang vien.   |" << endl
			 << "\t|3. Tinh tong so tien lam the cua cac doc gia.                           |" << endl
			 << "\t|4. Thoat !                                                              |" << endl
			 << "\t|________________________________________________________________________|" << endl;
		cout << "\t(+) Nhap lua chon cua ban: "; cin >> options; cout << endl;
		switch (options)
		{
		case 1:
		{
			init();
			break;
		}
		case 2:
		{
			finds();
			break;
		}
		case 3:
		{
			sums();
			break;
		}
		case 4:
		{
			cout << "(!) Thoat ! Ket thuc chuong trinh !!!" << endl;
			break;
		}
		default:
			cout << "\t(!) Khong co lua chon nay ! Vui long chon lai !!!" << endl;
			cout << "(+) Nhap lua chon cua ban: "; cin >> options;
			if (options == 4)
				cout << "(!) Thoat ! Ket thuc chuong trinh !!!" << endl;
			break;
		}
	} while (options != 4);
}

int main()
{
	QuanLyDocGia q;
	q.menu();
	return 0;
}
#include<iostream>
#include<iomanip>
#include<string>
#include<math.h>
#include<fstream>
using namespace std;

class Mydate
{
public:
	Mydate();
	Mydate(int, int, int);
	~Mydate();
	void import();
	void display();
protected:
	int d; // ngay sinh
	int m; // thang sinh
	int y; // nam sinh
};

Mydate::Mydate()
{
	d = 0; 
	m = 0;
	y = 0;
}
Mydate::Mydate(int d,int m, int y)
{
	this->d = d;
	this->m = m;
	this->y = y;
}
Mydate::~Mydate(){}
void Mydate::import()
{
	cout << "Nhap ngay sinh: "; cin >> d;
	while (d < 1 || d > 31)
	{
		cout << "Nhap lai ngay sinh 1 <= ngay <= 31: "; cin >> d;
	}
	cout << "Nhap thang sinh: "; cin >> m;
	while (m < 1 || m > 12)
	{
		cout << "Nhap lai ngay sinh 1 <= thang<= 12: "; cin >> m;
	}
	cout << "Nhap nam sinh: "; cin >> y;
	while (y < 1900 || y > 2023)
	{
		cout << "Nhap lai ngay sinh 1900 <= nam <= 2023: "; cin >> y;
	}
}
void Mydate::display()
{
	cout << "\t";
	cout << left << setw(2) << d << "/"
		 << left << setw(2) << m << "/"
		 << left << setw(9) << y;
}

class Person : public Mydate
{
public:
	Person();
	Person(int,int,int, string, string, long);
	~Person();
	void import();
	void display();
	friend bool operator > (Person&, Person&);
private:
	string name;
	string address;
	long phone;
};

Person::Person() : Mydate()
{
	name = "Unknown";
	address = "Unknown";
	phone = 0;
}
Person::Person(int d, int m,int y, string name, string address, long phone) : Mydate(d,m,y)
{
	this->name = name;
	this->address = address;
	this->phone = phone;
}
Person::~Person(){}
void Person::import()
{
	Mydate::import();
	cin.ignore();
	cout << "Nhap ho va ten: "; getline(cin, name);
	cout << "Nhap dia chi: "; getline(cin, address);
	cout << "Nhap so dien thoai: "; cin >> phone;
}
void Person::display()
{
	Mydate::display();
	cout << left << setw(20) << name
		 << left << setw(20) << address
		 << left << setw(15) << phone
		 << endl;
}
bool operator > (Person& p1, Person& p2)
{
	if (p1.y > p2.y)
		return true;
	else
		return false;
}
void title()
{
	cout << "\t"
		 << left << setw(15) << "Nam sinh"
	     << left << setw(20) << "Ho va ten"
		 << left << setw(20) << "Dia chi"
		 << left << setw(15) << "So dt"
		 << endl;
}
void input(Person a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "(*) Nhap thong tin nguoi thu " << i + 1 << endl;
		a[i].import();
		cout << endl;
	}
}
void output(Person a[], int n)
{
	cout << "\t________________DANH SACH THONG TIN NGUOI___________________" << endl;
	title();
	for (int i = 0; i < n; i++)
	{
		a[i].display();
	}
}
void arrange(Person a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
	cout << "\t____DANH SACH THONG TIN NGUOI SAP XEP GIAM DAN NAM SINH_____" << endl;
	title();
	for (int i = 0; i < n; i++)
	{
		a[i].display();
	}
}

int main()
{
	int n; cout << "Nhap so luong nguoi: "; cin >> n;
	Person* p = new Person[n];
	input(p,n);
	output(p,n);
	arrange(p, n);
	return 0;
}
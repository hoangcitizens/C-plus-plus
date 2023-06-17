#include<iostream>
#include<math.h>
#include<string>
#include<iomanip>
using namespace std;

class Student
{
public:
	Student();
	Student(int, char*, float, float, float);
	~Student();
	void import();
	float S();
	void display();
private:
	int id;
	char fullname[30];
	float t, l, h;
};

Student::Student()
{
	id = 0;
	strcpy_s(fullname, "");
	t = l = h = 0;
}
Student::Student(int id, char* fullname, float t, float l, float h)
{
	this->id = id;
	strcpy_s(this->fullname, fullname);
	this->t = t;
	this->l = l;
	this->h = h;
}
Student::~Student() {}
void Student::import()
{
	cout << "Nhap so bao danh: "; cin >> id;
	cin.ignore();
	cout << "Nhap ho va ten: "; cin.getline(fullname, 30);
	cout << "Nhap diem Toan: "; cin >> t;
	cout << "Nhap diem Ly: "; cin >> l;
	cout << "Nhap diem Hoa: "; cin >> h;
}
float Student::S()
{
	return t + l + h;
}
void Student::display()
{
	cout << "\t"
		 << left << setw(15) << id
		 << left << setw(30) << fullname
		 << left << setw(15) << t
		 << left << setw(15) << l
		 << left << setw(15) << h
		 << left << setw(15) << S()
		 << endl;
}

void input(Student a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "(*) Nhap thong tin sinh vien thu " << i + 1 << endl;
		a[i].import();
		cout << endl;
	}
}
void output(Student a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i].display();
	}
}
void tieude()
{
	cout << "\t"
		<< left << setw(15) << "SBD"
		<< left << setw(30) << "Ho va ten"
		<< left << setw(15) << "Diem Toan"
		<< left << setw(15) << "Diem Ly"
		<< left << setw(15) << "Diem Hoa"
		<< left << setw(15) << "Tong diem"
		<< endl;
}

void thuKhoa(Student a[], int n)
{
	cout << "\t____________________________________THONG TIN SINH THU KHOA_______________________________________" << endl;
	tieude();
	float max = a[0].S();
	for (int i = 1; i < n; i++)
	{
		if (a[i].S() > max)
		{
			max = a[i].S();
			a[i].display();
		}
	}
}


int main()
{
	int n;
	cout << "Nhap so luong sinh vien: "; cin >> n;
	Student* s = new Student[n];
	input(s, n);
	output(s, n);
	thuKhoa(s, n);
	return 0;
}
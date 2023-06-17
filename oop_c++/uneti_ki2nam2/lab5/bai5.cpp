#include<iostream>
#include<math.h>
#include<string>
#include<iomanip>
using namespace std;

class Person
{
public:
	Person();
	Person(char[], char[], int);
	~Person();
	char* getName();
protected:
	char name[50]; // ho va ten
	char address[50]; // dia chi
	int phone; // so dien thoai
};

Person::Person()
{
	strcpy_s(name,"Unknown");
	strcpy_s(address, "Unknown");
	phone = 0;
}
Person::Person(char name[], char address[], int phone)
{
	strcpy_s(this->name, name);
	strcpy_s(this->address, address);
	this->phone = phone;
}
Person::~Person(){}
char* Person::getName()
{
	return name;
}

class Officer : public virtual Person
{
public:
	Officer();
	Officer(char[], char[], int, float);
	~Officer();
protected:
	float salary; // luong
};

Officer::Officer() : Person()
{
	strcpy_s(name, "Unknown");
	strcpy_s(address, "Unknown");
	phone = 0;
	salary = 0;
}
Officer::Officer(char name[], char address[], int phone, float salary) : Person(name,address,phone)
{
	this->salary = salary;
}
Officer::~Officer(){}

class Student : public virtual Person
{
public:
	Student();
	Student(char[], char[], int,float);
	~Student();
	float getFee();
protected:
	float fee; // hoc phi
};

Student::Student() : Person()
{
	strcpy_s(name, "Unknown");
	strcpy_s(address, "Unknown");
	phone = 0;
	fee = 0;
}
Student::Student(char name[], char address[], int phone, float fee) : Person(name,address,phone)
{
	this->fee = fee;
}
Student::~Student() {}
float Student::getFee()
{
	return fee;
}

class OffStudent : public Officer, public Student
{
public:
	OffStudent();
	OffStudent(char[], char[], int, float, float);
	void OutScreen();
	~OffStudent();
};

OffStudent::OffStudent() : Officer() , Student()
{
	strcpy_s(name, "Unknown");
	strcpy_s(address, "Unknown");
	phone = 0;
	salary = 0;
	fee = 0;
}
OffStudent::OffStudent(char name[], char address[], int phone, float salary, float fee)
	: Person(name, address, phone), Officer(name, address, phone,salary), Student(name, address, phone,fee)
{}
OffStudent::~OffStudent(){}
void OffStudent::OutScreen()
{
	cout << "\t"
		 << "|" << left << setw(24) << name
		 << "|" << left << setw(24) << address
		 << "|" << left << setw(14) << phone
		 << "|" << left << setw(14) << salary
		 << "|" << left << setw(13) << fee << "|" << endl;
}

void title()
{
	cout << "\t"
		 << "_______________________________________________________________________________________________" << endl << "\t"
		 << left << setw(25) << "|        Ho va ten"
		 << left << setw(25) << "|         Dia chi"
		 << left << setw(15) << "| So dien thoai"
		 << left << setw(15) << "|  Tien luong"
		 << left << setw(15) << "|   Hoc phi   |" << endl << "\t"
	     << "*---------------------------------------------------------------------------------------------*" << endl;
}

int main()
{
	int n; cout << "Nhap so luong OffStudent: "; cin >> n;
	char name[50]; char address[50]; int phone; float salary; float fee;
	OffStudent* o = new OffStudent[n];
	for (int i = 0; i < n; i++)
	{
		cout << "(*) Nhap thong tin OffStudent thu " << i + 1 << endl;
		cin.ignore();
		cout << "Nhap ho va ten: "; cin.getline(name, 50);
		cout << "Nhap dia chi: "; cin.getline(address, 50);
		cout << "Nhap so dien thoai: "; cin >> phone;
		cout << "Nhap luong: "; cin >> salary;
		cout << "Nhap hoc phi: "; cin >> fee;
		o[i] = OffStudent(name, address, phone, salary, fee);
		cout << endl;
	}
	cout << "\t\t\t\t\tDANH SACH THONG TIN OFFSTUDENT" << endl;
	title();
	for (int i = 0; i < n; i++)
	{
		o[i].OutScreen();
		cout << "\t*---------------------------------------------------------------------------------------------*" << endl;

	}
	cout << endl;

	cout << "\t\t\t\tDANH SACH THONG TIN OFFSTUDENT LUONG 5 TRIEU" << endl;
	title();
	for (int i = 0; i < n; i++)
	{
		if (o[i].getFee() == 5)
		{
			o[i].OutScreen();
			cout << "\t*---------------------------------------------------------------------------------------------*" << endl;
		}
	}
	cout << endl;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(o[i].getName(),o[j].getName()) < 0 )
			{
				swap(o[i], o[j]);
			}
		}
	}
	cout << "\t\t\t\tDANH SACH THONG TIN OFFSTUDENT TEN TANG DAN" << endl;
	title();
	for (int i = 0; i < n; i++)
	{
		o[i].OutScreen();
		cout << "\t*---------------------------------------------------------------------------------------------*" << endl;

	}
	return 0;
}
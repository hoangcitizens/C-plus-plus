#include<iostream>
#include<string>
#include<math.h>
#include<iomanip>
#include<fstream>
using namespace std;

class PET
{
public:
	PET();
	PET(int, int);
	~PET();
	void import();
	void display();
	int getAge();
	int getWeight();
	void setAge(int);
	void setWeight(int);
	void docFile(ifstream&);
protected:
	int age;
	int weight; // can nang
};

PET::PET()
{
	age = 0;
	weight = 0;
}
PET::PET(int age, int weight)
{
	this->age = age;
	this->weight = weight;
}
PET::~PET(){}
void PET::import()
{
	cout << "Nhap tuoi: "; cin >> age;
	cout << "Nhap can nang: "; cin >> weight;
}
void PET::display()
{
	cout << "\t"
		 << "|" << left << setw(15) << age
		 << "|" << left << setw(15) << weight;
}
int PET::getAge()
{
	return age;
}
int PET::getWeight()
{
	return weight;
}
void PET::setAge(int age)
{
	this->age = age;
}
void PET::setWeight(int weight)
{
	this->weight = weight;
}
void PET::docFile(ifstream& in)
{
	int age, weight;
	in >> age;
	in >> weight;
	this->setAge(age);
	this->setWeight(weight);
}

class Dog : public PET
{
public:
	Dog();
	Dog(int, int, string, string);
	~Dog();
	friend istream& operator >> (istream&, Dog&);
	friend ostream& operator << (ostream&, Dog&);
	friend bool operator > (Dog&, Dog&);
	void docFile(ifstream&);
	void setColorEye(string);
	void setInterest(string);
private:
	string coloreye;
	string interest;
};

Dog::Dog() : PET()
{
	coloreye = "Unknown";
	interest = "Unknown";
}
Dog::Dog(int age, int weight, string coloreye, string interest) : PET(age,weight)
{
	this->coloreye = coloreye;
	this->interest = interest;
}
Dog::~Dog(){}
istream& operator >> (istream& is, Dog& d)
{
	d.import();
	is.ignore();
	cout << "Nhap mau mat: "; getline(is, d.coloreye); 
	cout << "Nhap so thich: "; getline(is, d.interest);
	return is;
}
ostream& operator << (ostream& os, Dog& d)
{
	d.display();
	os << "|" << left << setw(20) << d.coloreye
	   << "|" << left << setw(20) << d.interest << "|" << endl;
	return os;
}
bool operator > (Dog& d1, Dog& d2)
{
	if (d1.age > d2.age)
		return true;
	else
		return false;
}
void Dog::setColorEye(string coloreye)
{
	this->coloreye = coloreye;
}
void Dog::setInterest(string interest)
{
	this->interest = interest;
}
void Dog::docFile(ifstream& in)
{
	PET::docFile(in);
	string coloreye, interest;
	in.ignore();
	getline(in,coloreye);
	getline(in,interest);
	this->setColorEye(coloreye);
	this->setInterest(interest);
}

void title()
{
	cout << "\t"
		<< "___________________________________________________________________________" << endl << "\t"
		<< "|" << left << setw(15) << "      Tuoi"
		<< "|" << left << setw(15) << "    Can nang"
		<< "|" << left << setw(20) << "      Mau mat"
		<< "|" << left << setw(20) << "      So thich" << "|" << endl << "\t"
		<< "*-------------------------------------------------------------------------*" << endl;
}
void input(Dog a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\t(*) Nhap thong tin cho thu " << i + 1 << endl;
		cin >> a[i];
		cout << endl;
	}
}
void output(Dog a[], int n)
{
	cout << "\n\t\t\t\tDANH SACH THONG TIN THU CUNG" << endl;
	title();
	for (int i = 0; i < n; i++)
	{
		cout << a[i];
		cout << "\t*-------------------------------------------------------------------------*" << endl;
	}
	cout << endl;
}
void arrange(Dog a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
	cout << "\t\tDANH SACH THONG TIN THU CUNG SAP XEP THEO TUOI TANG DAN" << endl;
	title();
	for (int i = 0; i < n; i++)
	{
		cout << a[i];
		cout << "\t*-------------------------------------------------------------------------*" << endl;
	}
	cout << endl;
}
void findAge(Dog a[], int n)
{
	cout << "\t\t\tDANH SACH THONG TIN THU CUNG CO TUOI TU 2 DEN 5" << endl;
	title();
	for (int i = 0; i < n; i++)
	{
		if (a[i].getAge() > 1 && a[i].getAge() < 6)
		{
			cout << a[i];
			cout << "\t*-------------------------------------------------------------------------*" << endl;
		}
	}
	cout << endl;
}
void sumWeight(Dog a[], int n)
{
	int S = 0;
	for (int i = 0; i < n; i++)
	{
		S += a[i].getWeight();
	}
	cout << "\t=> Tong can nang cua " << n << " dog la: " << S << endl;
}

int main()
{
	Dog dog[20];
	ifstream ifs("bai6_lab4.txt", ios::in); 
	int n; cout << "Nhap so luong cho: ";  ifs >> n; cout << n;
	char ss[5];
	ifs.getline(ss, 3);
	//input(dog, n);
	for (int i = 0; i < n; i++)
	{
		dog[i].docFile(ifs);
	}
	output(dog, n);
	ifs.close();
	arrange(dog, n);
	findAge(dog, n);
	sumWeight(dog, n);
	return 0;
}
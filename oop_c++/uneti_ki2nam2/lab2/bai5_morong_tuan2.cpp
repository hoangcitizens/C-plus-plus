// NGUYEN HUU HOANG - DHTI15A5HN - 21103100320

#include<iostream>
#include<math.h>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;

class NGUOI
{
public:
	NGUOI();
	NGUOI(char*, int, char*, char*);
	~NGUOI();
	void import();
	void display();
	char* getFullname();
	char* getJob();
	char* getNationality();
	int getAge();
	void setFullname(char*);
	void setAge(int);
	void setJob(char*);
	void setNationality(char*);
	void doc(ifstream&);
private:
	char fullname[30]; // ho va ten
	int age; // tuoi
	char job[30]; // nghe nghiep
	char nationality[20]; // quoc tich
};

NGUOI::NGUOI()
{
	strcpy_s(fullname, "");
	age = 0;
	strcpy_s(job, "");
	strcpy_s(nationality, "");
}
NGUOI::NGUOI(char* fullname, int age, char* job, char* nationality)
{
	strcpy_s(this->fullname, fullname);
	this->age = age;
	strcpy_s(this->job, job);
	strcpy_s(this->nationality, nationality);
}
NGUOI::~NGUOI(){}
void NGUOI::import()
{
	cin.ignore();
	cout << "Nhap ho va ten: "; cin.getline(fullname, 30);
	cout << "Nhap nghe nghiep: "; cin.getline(job, 30);
	cout << "Nhap quoc tich: "; cin.getline(nationality, 20);
	cout << "Nhap tuoi: "; cin >> age;
}
void NGUOI::display()
{
	cout << "\t"
		 << left << setw(30) << fullname
		 << left << setw(15) << age
		 << left << setw(30) << job
		 << left << setw(20) << nationality
		 << endl;
}
char* NGUOI::getFullname()
{
	return fullname;
}
char* NGUOI::getJob()
{
	return job;
}
char* NGUOI::getNationality()
{
	return nationality;
}
int NGUOI::getAge()
{
	return age;
}
void NGUOI::setFullname(char* fullname)
{
	strcpy_s(this->fullname, fullname);
}
void NGUOI::setAge(int age)
{
	this->age = age;
}
void NGUOI::setJob(char* job)
{
	strcpy_s(this->job, job);
}
void NGUOI::setNationality(char* nationality)
{
	strcpy_s(this->nationality, nationality);
}
void NGUOI::doc(ifstream& in)
{
	in.getline(fullname, 30);
	in.getline(job, 30);
	in.getline(nationality, 20);
	in >> age;
	char ss[5];
	in.getline(ss, 3);
	this->setFullname(fullname);
	this->setJob(job);
	this->setNationality(nationality);
	this->setAge(age);
}
void tieude()
{
	cout << "\t"
		 << left << setw(30) << "Ho va ten"
		 << left << setw(15) << "Tuoi"
		 << left << setw(30) << "Nghe nghiep"
		 << left << setw(20) << "Quoc tich"
		 << endl;
}
void input(NGUOI a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "(*) Nhap thong tin nguoi thu " << i + 1 << endl;
		a[i].import();
		cout << endl;
	}
}
void output(NGUOI a[], int n)
{
	cout << "\t_____________________________DANH SACH THONG TIN NGUOI______________________________" << endl;
	tieude();
	for (int i = 0; i < n; i++)
	{
		a[i].display();
	}
	cout << endl;
}
void sapxep(NGUOI a[], int n)
{	
	cout << "\t_________________DANH SACH THONG TIN THEO THU TU TANG DAN THEO TEN__________________" << endl;
	tieude();
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(a[i].getFullname(), a[j].getFullname()) > 0)
				swap(a[i], a[j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		a[i].display();
	}
	cout << endl;
}
void doctor(NGUOI a[], int n)
{
	cout << "\t_______________________DANH SACH THONG TIN NGHE NGHIEP BAC SI________________________" << endl;
	tieude();
	for (int i = 0; i < n; i++)
	{
		if (strcmp(a[i].getJob(), "Bac si") == 0)
			a[i].display();
	}
	cout << endl;
}
void findNationality(NGUOI a[], int &n)
{
	cout << "\t________________________THONG TIN NGUOI QUOC TICH CAMPUCHIA_________________________" << endl;
	tieude();
	for (int i = 0; i < n; i++)
	{
		if (strcmp(a[i].getNationality(),"Campuchia") == 0)
			a[i].display();
	}
	for (int i = 0; i < n; i++)
	{
		if (strcmp(a[i].getNationality(), "Campuchia") == 0)
		{
			for (int j = i; j < n; j++)
			{
				a[j] = a[j + 1];
			}
			n--;
		}
	}
	cout << "\n\t__________________DANH SACH NGUOI KHONG CO QUOC TICH CAMPUCHIA______________________" << endl;
	tieude();
	for (int i = 0; i < n; i++)
	{
		a[i].display();
	}
	cout << endl;
}
void findName(NGUOI a[], int &n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(a[i].getFullname(), "Le Dai Nghia") != 0)
			count++;
	}
	if (count == 0)
		cout << "\t=> Da co nguoi ten 'Le Dai Nghia' trong danh sach !!!" << endl;
	else
	{
		cout << "\t(!) Khong co 'Le Dai Nghia' trong danh sach . Chen 'Le Dai Nghia' vao trong danh sach !!!" << endl;
		cout << "(*) Nhap thong tin cho 'Le Dai Nghia'" << endl;
		cin.ignore();
		char* name = new char[30];
		strcpy_s(name,29, "Le Dai Nghia");
		a[n].setFullname(name);
		cout << "Nhap nghe nghiep: "; cin.getline(a[n].getJob(), 30);
		cout << "Nhap quoc tich: "; cin.getline(a[n].getNationality(), 20);
		int x;
		cout << "Nhap tuoi: "; cin >> x; a[n].setAge(x);
		n++;
		output(a, n);
	}
}
void ageMax(NGUOI a[], int n)
{
	cout << "\t____________________________THONG TIN NGUOI TUOI CAO NHAT___________________________" << endl;
	tieude();
	int v1 = 0;
	int ageMax = a[0].getAge();
	for (int i = 1; i < n; i++)
	{
		if (a[i].getAge() > ageMax)
		{
			ageMax = a[i].getAge();
			v1 = i;
		}
	}
	a[v1].display();
	cout << endl;
}
void ageMin(NGUOI b[], int m)
{
	cout << "\t____________________________THONG TIN NGUOI TUOI NHO NHAT___________________________" << endl;
	tieude();
	int v2 = 0;
	int ageMin = b[0].getAge();
	for (int j = 1; j < m; j++)
	{
		if (b[j].getAge() < ageMin)
		{
			ageMin = b[j].getAge();
			v2 = j;
		}
	}
	b[v2].display();
	cout << endl;
}

void Menu()
{
	int n, luaChon;
	ifstream ifs("data.txt", ios::in);
	cout << "Nhap so luong nguoi: "; ifs >> n; cout << n;
	cout << endl;
	char ss[5];
	ifs.getline(ss, 5);
	NGUOI* p = new NGUOI[n];
	do
	{
		cout << "\t___________________________________MENU____________________________________" << endl
			<< "\t|1. Nhap va in thong tin                                                   |" << endl
			<< "\t|2. Danh sach theo thu tu tang dan cua ten                                 |" << endl
			<< "\t|3. Danh sach nguoi co nghe nghiep 'Bac si'                                |" << endl
			<< "\t|4. Danh sach nguoi co quoc tich 'Campuchia' va xoa khoi danh sach         |" << endl
			<< "\t|5. Tim nguoi ten 'Le Dai Nghia'. Khong co them vao cuoi danh sach         |" << endl
			<< "\t|6. In nguoi co tuoi nho nhat va lon nhat trong danh sach                  |" << endl
			<< "\t|7. Thoat !                                                                |" << endl
			<< "\t|__________________________________________________________________________|" << endl;
		cout << "\t<+> Nhap lua chon: "; cin >> luaChon;
		switch (luaChon)
		{
		case 1:
		{
			for (int i = 0; i < n; i++)
			{
				p[i].doc(ifs);
			}
			output(p, n);
			ifs.close();
			break;
		}
		case 2:
		{
			sapxep(p, n);
			break;
		}
		case 3:
		{
			doctor(p, n);
			break;
		}
		case 4:
		{
			findNationality(p, n);
			break;
		}
		case 5:
		{
			findName(p, n);
			break;
		}
		case 6:
		{
			output(p, n);
			ageMax(p, n);
			ageMin(p, n);
			break;
		}
		case 7:
		{
			cout << "\t(!) Thoat khoi chuong trinh ! Chuong trinh ket thuc !!!" << endl;
			break;
		}
		default:
			cout << "\t(!) Khong co lua chon nay ! Vui long lua chon lai !!!" << endl;
			cout << "\t<+> Nhap lua chon: "; cin >> luaChon;
			if (luaChon == 7)
				cout << "\t(!) Thoat khoi chuong trinh ! Chuong trinh ket thuc !!!" << endl;
			break;
		}
	} while (luaChon != 7);
}

int main()
{
	Menu();
	return 0;
}
#include<iostream>
#include<string>
#include<math.h>
#include<iomanip>
using namespace std;

class Student
{
protected:
	char msv[10];
	char ht[20];
	char gt[12];
public:
	Student()
	{
		strcpy_s(msv, "");
		strcpy_s(ht, "");
		strcpy_s(gt, "");
	}
	Student(char *msv,char *ht,char *gt)
	{
		strcpy_s(this->msv,msv);
		strcpy_s(this->ht,ht);
		strcpy_s(this->gt,gt);
	}
	~Student() {}
	friend istream& operator >> (istream& is, Student& sv)
	{
		cin.ignore();
		cout << "Nhap ma sinh vien: "; cin.getline(sv.msv, 10);
		cout << "Nhap ten sinh vien: "; cin.getline(sv.ht, 20);
		cout << "Nhap gioi tinh ('Nam' hoac 'Nu'): "; cin.getline(sv.gt, 12);
		while (strcmp(sv.gt, "Nam") != 0 && strcmp(sv.gt, "Nu") != 0)
		{
			cout << "Nhap lai gioi tinh 'Nam' hoac 'Nu': ";
			cin.getline(sv.gt, 12);
		}
		return is;
	}
	friend ostream& operator << (ostream& os, Student& sv)
	{
		cout << "\t";
		cout << left << setw(10) << sv.msv;
		cout << left << setw(20) << sv.ht;
		cout << left << setw(12) << sv.gt;
		return os;
	}
};
class Monhoc
{
protected:
	char mm[10];
	char tm[20];
public:
	Monhoc()
	{
		strcpy_s(mm, "");
		strcpy_s(tm, "");
	}
	Monhoc(char *mm,char *tm)
	{
		strcpy_s(this->mm,mm);
		strcpy_s(this->tm,tm);
	}
	~Monhoc() {}
	friend istream& operator >> (istream& is, Monhoc& mh)
	{
		fflush(stdin);
		cout << "Nhap ma mon hoc: "; cin.getline(mh.mm, 10);
		cout << "Nhap ten mon hoc: "; cin.getline(mh.tm, 20);
		while (strcmp(mh.tm, "Toan") != 0 && strcmp(mh.tm, "Ly") != 0 && strcmp(mh.tm, "Hoa") != 0)
		{
			cout << "Nhap ten mon hoc gom cac mon (Toan,Ly,Hoa): "; cin.getline(mh.tm, 20);
		}
		return is;
	}
	friend ostream& operator << (ostream& os, Monhoc& mh)
	{
		cout << left << setw(10) << mh.mm;
		cout << left << setw(20) << mh.tm;
		return os;
	}
};
class Diemmh : public Student, public Monhoc
{
private:
	float d;
public:
	Diemmh() : Student(), Monhoc()
	{
		d = 0;
	}
	Diemmh(char* msv, char* ht, char* gt, char* mm, char* tm, float d) : Student(msv, ht, gt), Monhoc(mm, tm)
	{
		this->d = d;
	}
	~Diemmh() {}
	friend istream& operator >> (istream& is, Diemmh& dh)
	{
		is >> (Student&)dh;
		is >> (Monhoc&)dh;
		cout << "Nhap diem thi: "; cin >> dh.d;
		while (dh.d < 0 || dh.d > 10)
		{
			cout << "Nhap diem thi 0 < diem <= 10: "; cin >> dh.d;
		}
		cout << endl;
		return is;
	}
	friend ostream& operator << (ostream& os, Diemmh& dh)
	{
		os << (Student&)dh;
		os << (Monhoc&)dh;
		cout << left << setw(10) << dh.d;
		cout << endl;
		return os;
	}
	friend bool operator < (Diemmh, Diemmh);
	friend void gtNam(Diemmh a[], int n);
	friend void tinhTb(Diemmh a[], int n);
	friend void timSv(Diemmh a[], int n);
	friend void timMinToan(Diemmh a[], int n);
	friend void sapxep(Diemmh a[], int n);
};

void tieude()
{
	cout << "\t";
	cout << left << setw(10) << "Ma sv";
	cout << left << setw(20) << "Ho va ten";
	cout << left << setw(12) << "Gioi tinh";
	cout << left << setw(10) << "Ma mon";
	cout << left << setw(20) << "Ten mon hoc";
	cout << left << setw(10) << "Diem thi";
	cout << endl;
}
void input(Diemmh a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "(*) Nhap thong tin sinh vien thu " << i + 1 << endl;
		cin >> a[i];
	}
}
void output(Diemmh a[], int n)
{
	cout << "\t__________________________DANH SACH THONG TIN SINH VIEN__________________________" << endl;
	tieude();
	for (int i = 0; i < n; i++)
	{
		cout << a[i];
	}
	cout << endl;
}
bool operator < (Diemmh sv1,Diemmh sv2)
{
	if (sv1.d < sv2.d)
		return true;
	else
		return false;
}
void gtNam(Diemmh a[], int n)
{
	unsigned int kt = 0;
	cout << "\t_____________________________DANH SACH SINH VIEN NAM_____________________________" << endl;
	tieude();
	for (int i = 0; i < n; i++)
	{
		if (strcmp(a[i].gt, "Nam") == 0)
		{
			kt++;
			cout << a[i];
		}
	}
	if (kt == 0)
		cout << "\t=> Khong co sinh vien nao gioi tinh 'Nam' !!!" << endl;
	cout << endl;
}
void tinhTb(Diemmh a[], int n)
{
	float St = 0, Sl = 0, Sh = 0;
	float t = 0, l = 0, h = 0;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(a[i].tm, "Toan") == 0)
		{
			St += a[i].d;
			t++;
		}
		if (strcmp(a[i].tm, "Ly") == 0)
		{
			Sl += a[i].d;
			l++;
		}
		if (strcmp(a[i].tm, "Hoa") == 0)
		{
			Sh += a[i].d;
			h++;
		}
	}
	if (t == 0)
		cout << "=> Khong co mon Toan trong danh sach !!!" << endl;
	else
		cout << "=> Diem trung binh mon Toan trong danh sach la: " << St / t << endl;
	if (l == 0)
		cout << "=> Khong co mon Ly trong danh sach !!!" << endl;
	else
		cout << "=> Diem trung binh mon Ly trong danh sach la: " << Sl / l << endl;
	if (h == 0)
		cout << "=> Khong co mon Hoa trong danh sach !!!" << endl;
	else
		cout << "=> Diem trung binh mon Hoa trong danh sach la: " << Sh / h << endl;
}
void timSv(Diemmh a[], int n)
{
	unsigned int count = 0;
	char x[20];
	cin.ignore();
	cout << "Nhap ten sinh vien can tim: "; cin.getline(x, 20);
	cout << "\t___________________________THONG TIN SINH VIEN CAN TIM___________________________" << endl;
	tieude();
	for (int i = 0; i < n; i++)
	{
		if (strcmp(a[i].ht, x) == 0)
		{
			count++;
			cout << a[i];
		}
	}
	cout << endl;
	if (count == 0)
		cout << "\t=> Khong tim thay sinh vine co ten " << x << " trong danh sach !!!" << endl;
}
void timMinToan(Diemmh a[], int n)
{
	cout << "\t____________________THONG TIN SINH VIEN CO DIEM TOAN NHO NHAT____________________" << endl;
	tieude();
	Diemmh min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (strcmp(a[i].tm, "Toan") == 0)
		{
			if (a[i].d < min.d)
			{
				min = a[i];
				cout << a[i];
			}
		}
	}
	cout << endl;
}
void sapxep(Diemmh a[], int n)
{
	cout << "\t___________________DANH SACH SINH VIEN GIAM DAN THEO DIEM THI____________________" << endl;
	tieude();
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].d < a[j].d)
				swap(a[i],a[j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i];
	}
	cout << endl;
}

int main()
{
	int n;
	cout << "Nhap vao so luong sinh vien: ";
	cin >> n;
	Diemmh* d = new Diemmh[n];
	input(d, n);
	output(d, n);
	gtNam(d, n);
	tinhTb(d, n);
	timSv(d, n);
	timMinToan(d, n);
	sapxep(d, n);
	return 0;
}
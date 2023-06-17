#include<iostream>
#include<string>
#include<iomanip>
#include<math.h>
using namespace std;

class Nguoi
{
private:
	char ht[30];
	int year;
public:
	Nguoi()
	{
		strcpy_s(ht, "");
		year = 0;
	}
	Nguoi(char* n, int y)
	{
		strcpy_s(ht, n);
		year = y;
	}
	~Nguoi() {}
	void Set()
	{
		cin.ignore();
		cout << "Nhap ho va ten: "; cin.getline(ht, 30);
		cout << "Nhap nam sinh: "; cin >> year;
		while (year < 1991 || year > 2022)
		{
			cout << "Nhap 1991 < nam sinh < 2023: ";
			cin >> year;
		}
	}
	void Display() 
	{
		cout << "\t";
		cout << left << setw(30) << ht;
		cout << left << setw(10) << year;
	}
};
class Thisinh : public Nguoi
{
private:
	char sbd[10];
	float t, l, h;
public:
	Thisinh() :Nguoi()
	{
		strcpy_s(sbd, "");
		t = 0;
		l = 0;
		h = 0;
	}
	Thisinh(char* n, int y, char* s, float toan, float ly, float hoa):Nguoi(n,y)
	{
		strcpy_s(sbd, s);
		t = toan;
		l = ly;
		h = hoa;
	}
	void setThisinh()
	{
		Set();
		cin.ignore();
		cout << "Nhap so bao danh cua thi sinh: "; cin.getline(sbd, 10);
		cout << "Nhap diem mon Toan: "; cin >> t;
		while (t < 1 || t > 10)
		{
			cout << "Nhap diem 0 < Toan <= 10: ";
			cin >> t;
		}
		cout << "Nhap diem mon Ly: "; cin >> l;
		while (l < 1 || l > 10)
		{
			cout << "Nhap diem 0 < Ly <= 10: ";
			cin >> l;
		}
		cout << "Nhap diem mon Hoa: "; cin >> h;
		while (h < 1 || h > 10)
		{
			cout << "Nhap diem 0 < Hoa <= 10: ";
			cin >> h;
		}
		cout << endl;
	}
	void displayThiSinh()
	{
		Display();
		cout << left << setw(15) << sbd;
		cout << left << setw(15) << t;
		cout << left << setw(15) << l;
		cout << left << setw(15) << h;
		cout << left << setw(15) << tong();
		cout << endl;
	}
	float tong()
	{
		return t + l + h;
	}
	friend void timSbd(Thisinh a[], int n);
	friend void thongKe(Thisinh a[], int n);
};

void tieude()
{
	cout << "\t";
	cout << left << setw(30) << "Ho va ten";
	cout << left << setw(10) << "Nam sinh";
	cout << left << setw(15) << "So bao danh";
	cout << left << setw(15) << "Diem Toan";
	cout << left << setw(15) << "Diem Ly";
	cout << left << setw(15) << "Diem Hoa";
	cout << left << setw(15) << "Tong diem";
	cout << endl;
}
void input(Thisinh a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "(*) Nhap thong tin thi sinh thu " << i + 1 << endl;
		a[i].setThisinh();
	}
}
void output(Thisinh a[], int n)
{
	tieude();
	for (int i = 0; i < n; i++)
	{
		a[i].displayThiSinh();
	}
	cout << endl;
}
void tongDiemTangDan(Thisinh a[], int n)
{
	cout << "\t_____________________________DANH SACH THONG TIN THI SINH TONG DIEM TANG DAN_________________________________" << endl;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].tong() > a[j].tong())
				swap(a[i], a[j]);
		}
	}
	tieude();
	for (int i = 0; i < n; i++)
	{
		a[i].displayThiSinh();
	}
	cout << endl;
}
void timSbd(Thisinh a[], int n)
{
	char x[10];
	cin.ignore();
	cout << "Nhap so bao danh can tim: "; cin.getline(x, 10);
	unsigned int kt = 0;
	cout << "\t___________________________________THONG TIN SINH VIEN CAN TIM_______________________________________________" << endl;
	tieude();
	for (int i = 0; i < n; i++)
	{
		if (strcmp(a[i].sbd,x) == 0)
		{
			kt++;
			a[i].displayThiSinh();
		}
	}
	if (kt == 0)
		cout << "\t => Khong co thi sinh nao co SBD do !" << endl;
}
void thongKe(Thisinh a[], int n)
{
	float count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i].t > 5 && a[i].l > 5 && a[i].h > 5)
			count++;
	}
	cout << "=> Phan tram thi sinh co ca 3 mon tong diem lon hon hoac bang 5 la: " << (count / n) * 100 << "%" << endl;
}

int main()
{
	int n;
	cout << "Nhap so luong thi sinh: ";
	cin >> n;
	Thisinh* ts = new Thisinh[n];
	input(ts, n);
	cout << "\t________________________________________DANH SACH THONG TIN THI SINH_________________________________________" << endl;
	output(ts, n);
	tongDiemTangDan(ts, n);
	timSbd(ts, n);
	thongKe(ts, n);
	return 0;
}
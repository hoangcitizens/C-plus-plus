#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class HoaDon
{
private:
	char mvt[10];
	char tenvt[20];
	char lp1[10] = "Nhap";
	char lp2[10] = "Xuat";
	char loaiphieu[10];
	struct NL
	{
		int day;
		int month;
		int year;
	};
	NL nl;
	float khoiluong;
	float dongia;
	float thanhtien;
public:
	void input1();
	void output1();
	friend void tinhThanhTien(HoaDon a[], int n);
	friend float tongTien(HoaDon a[], int n);
	friend void sapxep(HoaDon a[], int n);
};
void HoaDon::input1()
{
	cin.ignore();
	cout << "Nhap ma vat tu: "; cin.getline(mvt, 10);
	cout << "Ten vat tu: "; cin.getline(tenvt, 20);
	do
	{
		cout << "Loai phieu (Nhap or Xuat): "; cin.getline(loaiphieu, 10);
	} while (strcmp(lp1, loaiphieu) != 0 && strcmp(lp2, loaiphieu) != 0);
	cout << "Nhap ngay lap hoa don" << endl;
	cout << "Ngay: "; cin >> nl.day;
	while (nl.day < 1 || nl.day > 31)
	{
		cout << "Vui long nhap 0 < ngay < 31 !";
		cout << " => Ngay: "; cin >> nl.day;
	}
	cout << "Thang: "; cin >> nl.month;
	while (nl.month < 1 || nl.month > 12)
	{
		cout << "Vui long nhap 0 < thang < 12 !";
		cout << " => Ngay: "; cin >> nl.month;
	}
	cout << "Nam: "; cin >> nl.year;
	while (nl.year < 1900 || nl.year > 2100)
	{
		cout << "Vui long nhap 1900 < nam < 2100 !";
		cout << " => Nam: "; cin >> nl.year;
	}
	cout << "Nhap vao khoi luong vat tu: "; cin >> khoiluong;
	cout << "Nhap don gia vat tu: "; cin >> dongia;
	cout << endl;
}
void tinhThanhTien(HoaDon a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i].thanhtien = a[i].khoiluong * a[i].dongia;
	}
}
float tongTien(HoaDon a[], int n)
{
	float tong = 0;
	for (int i = 0; i < n; i++)
		tong += a[i].thanhtien;
	return tong;
}
void sapxep(HoaDon a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].thanhtien < a[j].thanhtien)
				swap(a[i].thanhtien, a[j].thanhtien);
		}
	}
}
void tieude()
{
	cout << "\t";
	cout << left << setw(12) << "Ma vat tu";
	cout << left << setw(20) << "Ten vat tu";
	cout << left << setw(12) << "Loai phieu";
	cout << left << setw(15) << "Ngay lap";
	cout << left << setw(13) << "Khoi luong";
	cout << left << setw(10) << "Don gia";
	cout << left << setw(10) << "Thanh tien";
	cout << endl;
}
void HoaDon::output1()
{
	cout << "\t";
	cout << left << setw(12) << mvt;
	cout << left << setw(20) << tenvt;
	cout << left << setw(12) << loaiphieu;
	cout << left << setw(2) << nl.day << "/";
	cout << left << setw(2) << nl.month << "/";
	cout << left << setw(9) << nl.year;
	cout << left << setw(13) << khoiluong;
	cout << left << setw(10) << dongia;
	cout << left << setw(10) << thanhtien;
	cout << endl;
}
void input(HoaDon a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "(*) Nhap thong tin vat tu thu " << i + 1 << endl;
		a[i].input1();
	}
}
void output(HoaDon a[], int n)
{
	tieude();
	for (int i = 0; i < n; i++)
	{
		a[i].output1();
	}
}

int main()
{
	int n;
	cout << "Nhap so luong vat tu: ";
	cin >> n;
	while (n < 1)
	{
		cout << "Nhap so luong vat tu > 0: ";
		cin >> n;
	}
	HoaDon* hd = new HoaDon[n];
	input(hd, n);
	tinhThanhTien(hd, n);
	cout << "\t_____________________________________DANH SACH HOA DON______________________________________" << endl;
	output(hd, n);
	cout << "\n\t=> Tong tien hoa don la: " << tongTien(hd, n) << endl;
	sapxep(hd, n);
	cout << "\n\t_______________________DANH SACH HOA DON THU TU GIAM DAN TONG TIEN__________________________" << endl;
	output(hd, n);
	return 0;
}
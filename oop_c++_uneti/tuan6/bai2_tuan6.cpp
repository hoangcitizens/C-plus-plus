#include<iostream>
#include<math.h>
#include<iomanip>
#include<conio.h>
#include<string>
using namespace std;

class KH
{
private:
	char ht[30];
	char cmt[10];
	char k[50];
	struct NS
	{
		int day, month, year;
	};
	NS ns;
public:
	friend istream& operator >> (istream& is, KH& kh);
	friend ostream& operator << (ostream& os, KH& kh);
	friend bool operator >(KH, KH);
	friend void que_hn(KH a[], int n);
};

istream& operator >> (istream& is, KH& kh)
{
	cout << "Nhap ho va ten khach hang: "; cin.getline(kh.ht, 30);
	cout << "Nhap so chung minh thu: "; cin.getline(kh.cmt, 10);
	cout << "Nhap ho khau: "; cin.getline(kh.k, 50);
	cout << "Nhap ngay thang nam sinh" << endl;
	cout << "Ngay: "; cin >> kh.ns.day;
	while (kh.ns.day < 1 || kh.ns.day > 31)
	{
		cout << "Vui long nhap 0 < ngay < 32 !";
		cout << " => Ngay: "; cin >> kh.ns.day;
	}
	cout << "Thang: "; cin >> kh.ns.month;
	while (kh.ns.month < 1 || kh.ns.month > 12)
	{
		cout << "Vui long nhap 0 < thang < 13 !";
		cout << " => Thang: "; cin >> kh.ns.month;
	}
	cout << "Nam: "; cin >> kh.ns.year;
	while (kh.ns.year < 1900 || kh.ns.year > 2100)
	{
		cout << "Vui long nhap 1900 < nam < 2101 !";
		cout << " => Nam: "; cin >> kh.ns.year;
	}
	cout << endl; 
	return is;
}
void tieude()
{
	cout << "\t";
	cout << left << setw(30) << "Ho va ten";
	cout << left << setw(15) << "Ngay sinh";
	cout << left << setw(10) << "So cmt";
	cout << left << setw(20) << "Ho khau";
	cout << endl;
}
ostream& operator << (ostream& os, KH& kh)
{
	cout << "\t";
	cout << left << setw(30) << kh.ht;
	cout << left << setw(2) << kh.ns.day << "/";
	cout << left << setw(2) << kh.ns.month << "/";
	cout << left << setw(9) << kh.ns.year ;
	cout << left << setw(10) << kh.cmt;
	cout << left << setw(20) << kh.k;
	cout << endl;
	return os;
}
bool operator >(KH kh1, KH kh2)
{
	if (kh1.ns.year > kh2.ns.year)
		return true;
	else
		return false;
}
void input(KH a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "(*) Nhap thong tin khach hang thu " << i + 1 << endl;
		cin.ignore();
		cin >> a[i];
	}
}
void que_hn(KH a[], int n)
{
	KH kh;
	unsigned int kt = 0;
	cout << "\t______________DANH SACH KHACH HANG HO KHAU HA NOI______________" << endl;
	tieude();
	for (int i = 0; i < n; i++)
	{
		if (strcmp(a[i].k, "HA NOI") == 0 || strcmp(a[i].k, "Ha Noi") == 0 || strcmp(a[i].k, "ha noi") == 0) 
		{
			kt++;
			cout << a[i];
		}
	}
	if (kt == 0)
		cout << "\t => Khong co khach ahng nao ho khau o 'Ha Noi' !" << endl;
}
void sapxep(KH a[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
	}
}
void output(KH a[], int n)
{
	tieude();
	for (int i = 0; i < n; i++)
	{
		cout << a[i];
	}
	cout << endl;
}

int main()
{
	int n;
	cout << "Nhap so luong khach hang: ";
	cin >> n;
	KH* kh = new KH[n];
	input(kh,n);
	cout << "\t________________DANH SACH THONG TIN KHACH HANG_________________" << endl;
	output(kh,n);
	que_hn(kh,n);
	cout << "\t____________DANH SACH KHACH HANG THEO TUOI GIAM DAN____________" << endl;
	sapxep(kh,n);
	output(kh,n);
	return 0;
}
#include<iostream>
#include<math.h>
#include<iomanip>
#include<string.h>
#include<stdio.h>
using namespace std;

class KH
{
private:
	char ht[30];
	struct NS
	{
		int day;
		int month;
		int year;
	};
	NS ns;
	char cmt[10];
	char k[50];
public:
	void input();
	void output();
	void sapxep(KH a[], int);
	void sn12();
};

void KH::input()
{
	fflush(stdin);
	cout << "Nhap ho va ten: "; cin.getline(ht,30);
	cout << "Nhap so chung minh thu: "; cin.getline(cmt,10);
	cout << "Nhap ho khau: "; cin.getline(k,50);
	cout << "Nhap ngay thang nam sinh" << endl;
	cout << "Ngay: "; cin >> ns.day;
	while (ns.day < 1 || ns.day > 31)
	{
		cout << "Vui long nhap 0 < ngay < 31 !";
		cout << " => Ngay: "; cin >> ns.day;	
	}
	cout << "Thang: "; cin >> ns.month;
	while (ns.month < 1 || ns.month > 12)
	{
		cout << "Vui long nhap 0 < thang < 12 !";
		cout << " => Thang: "; cin >> ns.month;	
	} 
	cout << "Nam: "; cin >> ns.year;
	while (ns.year < 1900 || ns.year > 2100)
	{
		cout << "Vui long nhap 1900 < nam < 2100 !";
		cout << " => Nam: "; cin >> ns.year;	
	} 
	cout << endl;
}
void KH::output()
{
	cout << left << setw(30) << ht;
	cout << left << setw(2) << ns.day << "/";
	cout << left << setw(2) << ns.month << "/";
	cout << left << setw(9) << ns.year;
	cout << left << setw(12) << cmt;
	cout << left << setw(50) << k;
	cout << endl;
} 
void KH::sapxep(KH a[], int n)
{
	for (int i=0; i < n-1; i++)
	{
		for (int j=i+1; j < n; j++)
		{
			if (strcmp(a[i].ht,a[j].ht) > 0)
			{
				KH tg = a[i];
				a[i] = a[j];
				a[j] = tg;
			}
		}
	}
}
void KH::sn12()
{
	if (ns.month == 12)
	{
		output();
	}
}
void tieude()
{
	cout << "\t";
	cout << left << setw(30) << "Ho va ten";
	cout << left << setw(15) << "Nam sinh";
	cout << left << setw(12) << "So cmt";
	cout << left << setw(50) << "Ho khau";
	cout << endl;
} 
int main()
{
	int n;
	cout << "Nhap vao so luong khach hang: ";
	cin >> n;
	while (n < 1)
	{
		cout << "Nhap vao so luong khach hang duong: ";
		cin >> n;
	};
	KH *kh = new KH[n];
	for (int i=0; i < n; i++)
	{
		cout << "(*) Nhap thong tin khach hang thu " << i+1 << endl;
		kh[i].input();
	}
	cout << "\t_______________________THONG TIN KHACH HANG_______________________" << endl;
	tieude();
	for (int i=0; i < n; i++)
	{
		cout << "\t";
		kh[i].output();
	}
	cout << endl;
	
	cout << "\t_________________DANH SACH KHACH THEO TEN TANG DAN________________" << endl;
	tieude();
	for (int i=0; i < n; i++)
	{
		cout << "\t";
		kh[i].sapxep(kh,n);
		kh[i].output();
	}
	cout << endl;
	
	cout << "\t________________DANH SACH KHACH HANG SINH THANG 12________________" << endl;
	tieude();
	for (int i=0; i < n; i++)
	{
		cout << "\t";
		kh[i].sn12();
	}
	cout << endl;
	return 0;
}


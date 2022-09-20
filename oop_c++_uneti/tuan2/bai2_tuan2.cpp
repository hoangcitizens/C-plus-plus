#include<iostream>
#include<math.h>
#include<iomanip>
#include<string.h>
#include<stdio.h>
using namespace std;

class GV
{
private:
	char ht[30];
	char bc[15];
	char cn[20];
	int t;
	float bl;	
public:
	void input();
	void output();
	float tinhlcb();
	void luongnho();
	void sapxep(GV a[], int);
};

void GV::input()
{
	fflush(stdin);
	cout << "Nhap vao ten giao vien: "; cin.getline(ht,30);
	cout << "Nhap bang cap: "; cin.getline(bc,15);
	cout << "Nhap chuyen nganh: "; cin.getline(cn,20);
	cout << "Nhap tuoi: "; cin >> t;
	cout << "Bac luong: "; cin >> bl;
	cout << endl;
}
float GV::tinhlcb()
{
	return bl * 610;
}
void GV::output()
{
	cout << left << setw(30) << ht;
	cout << left << setw(10) << t;
	cout << left << setw(15) << bc;
	cout << left << setw(15) << cn;
	cout << left << setw(12) << bl;
	cout << left << setw(10) << tinhlcb();
	cout << endl;
}
void GV::luongnho()
{
	if (tinhlcb() < 2000)
	{
		output();
	}
}
void GV::sapxep(GV a[], int n)
{
	for (int i=0; i < n-1; i++)
	{
		for (int j=i+1; j < n; j++)
		{
			if (strcmp(a[i].cn,a[j].cn) > 0)
			{
				GV tg = a[i];
				a[i] = a[j];
				a[j] = tg;
			}
		}
	}
}
void tieude()
{
	cout << "\t";
	cout << left << setw(30) << "Ho va ten";
	cout << left << setw(10) << "Tuoi";
	cout << left << setw(15) << "Bang cap";
	cout << left << setw(15) << "Chuyen nganh";
	cout << left << setw(12) << "Bac luong";
	cout << left << setw(10) << "Luong co ban";
	cout << endl;
}

int main()
{
	int n;
	cout << "Nhap vao so luong giao vien: ";
	cin >> n;
	while (n < 1)
	{
		cout << "Nhap vao so luong giao vien duong: ";
		cin >> n;
	}
	GV *gv = new GV[n];
	for (int i=0; i < n; i++)
	{
		cout << "(*) Nhap thong tin giao vien thu " << i+1 << endl;
		gv[i].input();
	}
	cout << "\t____________________________________DANH SACH GIAO VIEN_____________________________________" << endl;
	tieude();
	for (int i=0; i < n; i++)
	{
		cout << "\t";
		gv[i].output();
	}
	cout << endl;
	
	cout << "\t__________________________DANH SACH GIAO VIEN LUONG NHO HON 2000_____________________________" << endl;
	tieude();
	for (int i=0; i < n; i++)
	{
		cout << "\t";
		gv[i].luongnho();
	}
	cout << endl;
	
	cout << "\t________________________DANH SACH GIAO VIEN SAP XEP THEO CHUYEN NGANH________________________" << endl;
	tieude();
	for (int i=0; i < n; i++)
	{
		cout << "\t";
		gv[i].sapxep(gv,n);
		gv[i].output();
	}
	cout << endl;
	return 0;
}


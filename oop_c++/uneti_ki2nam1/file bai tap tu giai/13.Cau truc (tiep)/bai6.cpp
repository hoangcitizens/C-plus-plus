#include<iostream>
#include<iomanip>
using namespace std;

typedef struct
{
	char hoten[20];
	int namsinh;
	int giolam;
} congnhan;

void nhap(congnhan a[], int n)
{
	for (int i=0; i<n; i++)
	{
		cin.ignore();
		cout << " (*) Nhap thong tin cong nhan thu "<<i+1<<endl;
		cout << "Nhap ho va ten cong nhan: "; gets(a[i].hoten);
		cout << "Nhap nam sinh: "; cin >> a[i].namsinh;
		cout << "Nhap gio lam: "; cin >> a[i].giolam;
		cout << endl;
	}
}
void tieude()
{
	cout << "\t";
	cout << left << setw(25) << "Ho va ten cong nhan";
	cout << left << setw(10) << "Nam sinh";
	cout << left << setw(7) << "Gio lam";
	cout << endl;
}
void xuat(congnhan a[], int n)
{
	cout << "\t____________THONG TIN CONG NHAN___________" << endl;
	tieude();
	for (int i=0; i<n; i++)
	{
		cout << "\t";
		cout << left << setw(25) << a[i].hoten;
		cout << left << setw(10) << a[i].namsinh;
		cout << left << setw(7) << a[i].giolam;
		cout << endl;
	}
	cout << endl;
}
void thuongCongNhan(congnhan a[], int n)
{
	cout << "\t___________CONG NHAN DUOC THUONG__________" << endl;
	tieude();
	for (int i=0; i<n; i++)
	{
		if (a[i].giolam > 40)
		{
			cout << "\t";
			cout << left << setw(25) << a[i].hoten;
			cout << left << setw(10) << a[i].namsinh;
			cout << left << setw(7) << a[i].giolam;
			cout << endl;
		}
	}
}
int main()
{
	congnhan cn[50];
	int n;
	cout << "Nhap so luong cong nhan: ";
	cin >> n;
	nhap(cn,n);
	xuat(cn,n);
	thuongCongNhan(cn,n);
	return 0;
}


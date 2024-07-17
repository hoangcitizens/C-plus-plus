#include<iostream>
#include<iomanip>
using namespace std;

typedef struct
{
	char maho[12];
	char tenchuho[10];
	int sothanhvien;
	float mucthunhap;
} hodan;
void nhap(hodan a[], int n)
{
	for (int i=0; i<n; i++)
	{
		cin.ignore();
		cout << "(*) Nhap ho dan thu "<<i+1<<endl;
		cout << "Nhap ma ho dan: "; gets(a[i].maho);
		cout << "Nhap ten chu ho: "; gets(a[i].tenchuho);
		cout << "Nhap so thanh vien: "; cin >> a[i].sothanhvien;
		cout << "Nhap muc thu nhap: "; cin >> a[i].mucthunhap;
		cout << endl;
	}
}
void tieude()
{
	cout << left << setw(15) << "Ma ho dan";
	cout << left << setw(15) << "Ten chu ho";
	cout << left << setw(15) << "So thanh vien";
	cout << left << setw(12) << "Muc thu nhap";
	cout << endl;
}
void xuat(hodan a[], int n)
{
	cout << "\n________________DANH SACH THONG TIN HO DAN_______________"<<endl;
	tieude();
	for (int i=0; i<n; i++)
	{
		cout << left << setw(15) << a[i].maho;
		cout << left << setw(15) << a[i].tenchuho;
		cout << left << setw(15) << a[i].sothanhvien;
		cout << left << setw(12) << a[i].mucthunhap;
		cout << endl;
	}
}
void hoDanLon(hodan a[], int n)
{
	cout << "\n____________DANH SACH HO DAN TREN 5 THANH VIEN___________"<<endl;
	tieude();
	for (int i=0; i<n; i++)
	{
		if (a[i].sothanhvien > 5)
		{
			cout << left << setw(15) << a[i].maho;
			cout << left << setw(15) << a[i].tenchuho;
			cout << left << setw(15) << a[i].sothanhvien;
			cout << left << setw(12) << a[i].mucthunhap;
			cout << endl;
		}
	}
}
int main()
{
	hodan hd[30];
	int n;
	cout << "Nhap so luong ho dan: ";
	cin >>n;
	nhap(hd,n);
	xuat(hd,n);
	hoDanLon(hd,n);
	return 0;
}


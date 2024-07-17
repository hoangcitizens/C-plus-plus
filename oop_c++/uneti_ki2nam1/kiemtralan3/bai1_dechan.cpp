// Nguyen Huu Hoang - 21103100320 - de chan
#include<iostream>
#include<iomanip>
using namespace std;

struct hodan
{
	char maho[15];
	char tenchuho[25];
	int sothanhvien;
	float mucthunhap;
	float trocap;
};
void nhap(hodan a[], int n)
{
	for (int i=0; i<n; i++)
	{
		cin.ignore();
		cout << "(*) Nhap ho dan thu " << i+1 << endl;
		cout << "Nhap ma ho dan: "; gets(a[i].maho);
		cout << "Nhap ten chu ho: "; gets(a[i].tenchuho);
		cout << "Nhap so thanh vien: "; cin >> a[i].sothanhvien;
		cout << "Nhap muc thu nhap: "; cin >> a[i].mucthunhap;
		cout << endl;
	}
}
void tinhTroCap(hodan a[], int n)
{
	for (int i=0; i<n; i++)
	{
		if (a[i].mucthunhap < 5000000 && a[i].mucthunhap > 3000000)
			a[i].trocap = 50000 * a[i].sothanhvien;
		else
			if (a[i].mucthunhap < 3000000 && a[i].mucthunhap > 2000000)
				a[i].trocap = 100000 * a[i].sothanhvien;
		else
			if (a[i].mucthunhap < 2000000 && a[i].mucthunhap > 0)
				a[i].trocap = 200000 * a[i].sothanhvien;
		else
			a[i].trocap = 0 * a[i].sothanhvien;
	}
}

void tieude()
{
	cout << "\t";
	cout << left << setw(15) << "Ma ho dan";
	cout << left << setw(25) << "Ten chu ho";
	cout << left << setw(15) << "So thanh vien";
	cout << left << setw(15) << "Muc thu nhap";
	cout << left << setw(12) << "Tro cap";
	cout << endl;
}
void xuat(hodan a[], int n)
{
	cout << "\n\t____________________________DANH SACH THONG TIN HO DAN__________________________"<<endl;
	tieude();
	for (int i=0; i<n; i++)
	{
		cout << "\t";
		cout << left << setw(15) << a[i].maho;
		cout << left << setw(25) << a[i].tenchuho;
		cout << left << setw(15) << a[i].sothanhvien;
		cout << left << setw(15) << a[i].mucthunhap;
		cout << left << setw(12) << a[i].trocap;
		cout << endl;
	}
}

void sapxep(hodan a[], int n)
{
	for (int i=0; i<n-1; i++)
	{
		for (int j=i+1; j<n; j++)
		{
			if (a[i].sothanhvien > a[j].sothanhvien)
			{
				hodan tg = a[i];
				a[i] = a[j];
				a[j] = tg;
			}
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
	sapxep(hd,n);
	xuat(hd,n);
	return 0;
}


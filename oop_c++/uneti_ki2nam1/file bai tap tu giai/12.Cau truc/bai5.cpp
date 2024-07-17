#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

typedef struct
{
	char masv[11];
	char hotensv[20];
	float diemLT;
	float diemTH;
} sinhVien;

void nhap(sinhVien a[], int n)
{
	for (int i=0; i<n; i++)
	{
		cout << "\n (*) Nhap sinh vien thu "<<i+1<<endl;
		cin.ignore();
		cout << "Nhap ma sinh vien: "; cin.getline(a[i].masv,11);
		cout << "Nhap ho va ten sinh vien: "; cin.getline(a[i].hotensv,20);
		cout << "Nhap diem ly thuyet: "; cin >> a[i].diemLT;
		while (a[i].diemLT < 0 || a[i].diemLT > 10)
		{
			cout << "Nhap lai diem ly thuyet (0<diem<10): ";
			cin >> a[i].diemLT;
		}
		cout << "Nhap diem thuc hanh: "; cin >> a[i].diemTH;
		while (a[i].diemTH < 0 || a[i].diemTH > 10)
		{
			cout << "Nhap lai diem thuc hanh (0<diem<10): ";
			cin >> a[i].diemTH;
		}
	}
}
void tieude()
{
	cout << left << setw(15) << "Ma sinh vien";
	cout << left << setw(23) << "Ho va ten sinh vien";
	cout << left << setw(17) << "Diem ly thuyet";
	cout << left << setw(15) << "Diem thuc hanh" << endl;
}
void xuat(sinhVien a[], int n)
{
	cout << "\n-------------------------DANH SACH SINH VIEN-------------------------"<<endl;
	tieude();
	for (int i=0; i<n; i++)
	{
		cout << left << setw(15) << a[i].masv;
		cout << left << setw(23) << a[i].hotensv;
		cout << left << setw(17) << a[i].diemLT;
		cout << left << setw(15) << a[i].diemTH;
		cout << endl;
 	}
}
void sinhVienTruotLT(sinhVien a[], int n)
{
	cout << "\n------------------DANH SACH SINH VIEN TRUOT LY THUYET----------------"<<endl;
	tieude();
	for (int i=0; i<n; i++)
	{
		if (a[i].diemLT < 5)
		{
			cout << left << setw(15) << a[i].masv;
			cout << left << setw(23) << a[i].hotensv;
			cout << left << setw(17) << a[i].diemLT;
			cout << left << setw(15) << a[i].diemTH;
			cout << endl;
		}
	}
}
void sinhVienTruotTH(sinhVien a[], int n)
{
	cout << "\n------------------DANH SACH SINH VIEN TRUOT THUC HANH----------------"<<endl;
	tieude();
	for (int i=0; i<n; i++)
	{
		if (a[i].diemTH < 5)
		{
			cout << left << setw(15) << a[i].masv;
			cout << left << setw(23) << a[i].hotensv;
			cout << left << setw(17) << a[i].diemLT;
			cout << left << setw(15) << a[i].diemTH;
			cout << endl;
		}
	}
}
int main()
{
	int n;
	sinhVien sv[50];
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	nhap(sv,n);
	xuat(sv,n);
	sinhVienTruotLT(sv,n);
	sinhVienTruotTH(sv,n);
	return 0;
}


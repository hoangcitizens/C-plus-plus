#include<iostream>
#include<iomanip>
using namespace std;

typedef struct
{
	char manv[12];
	char tennv[20];
	char phong[8];
	int hesoluong, ngaylam;
	float luongcb, thuong, tongluong;
} nhanvien;
void nhap(nhanvien a[], int n)
{
	for (int i=0; i<n; i++)
	{
		cin.ignore();
		cout << "(*) Nhap nhan vien thu "<<i+1<<endl;
		cout << "Nhap ma nhan vien: "; 		gets(a[i].manv);
		cout << "Nhap ten nhan vien: "; 	gets(a[i].tennv);
		cout << "Nhap phong lam viec: "; 	gets(a[i].phong);
		cout << "Nhap he so luong: "; 		cin >> a[i].hesoluong;
		cout << "Nhap so ngay lam: "; 		cin >> a[i].ngaylam;
		cout << endl;
	}
}
void tieude()
{
	cout << left << setw(15) << "Ma nhan vien";
	cout << left << setw(23) << "Ten nhan vien";
	cout << left << setw(10) << "Phong";
	cout << left << setw(14) << "He so luong";
	cout << left << setw(15) << "Ngay lam viec";
	cout << left << setw(15) << "Luong co ban";
	cout << left << setw(12) << "Thuong";
	cout << left << setw(12) << "Tong luong";
	cout << endl;
}
void tinhLuongCB(nhanvien a[], int n)
{
	for (int i=0; i<n; i++)
		a[i].luongcb = a[i].hesoluong * 17500;
}
void tinhThuong(nhanvien a[], int n)
{
	for (int i=0; i<n; i++)
	{
		if (a[i].ngaylam > 22 && a[i].ngaylam < 24 || a[i].ngaylam == 24)
			a[i].thuong = 50000;
		else
			if (a[i].ngaylam > 24 && a[i].ngaylam < 26 || a[i].ngaylam == 26)
				a[i].thuong = 100000;
		else
			if (a[i].ngaylam > 26)
				a[i].thuong = 500000;
			else
				a[i].thuong = 0;
	}
}
void tinhTongLuong(nhanvien a[], int n)
{
	for (int i=0; i<n; i++)
		a[i].tongluong = a[i].luongcb + a[i].thuong;
}
void xuat(nhanvien a[], int n)
{
	cout << "\n___________________________________________DANH SACH THONG TIN NHAN VIEN__________________________________________"<<endl;
	tieude();
	for (int i=0; i<n; i++)
	{
		cout << left << setw(15) << a[i].manv;
		cout << left << setw(23) << a[i].tennv;
		cout << left << setw(10) << a[i].phong;
		cout << left << setw(14) << a[i].hesoluong;
		cout << left << setw(15) << a[i].ngaylam;
		cout << left << setw(15) << a[i].luongcb;
		cout << left << setw(12) << a[i].thuong;
		cout << left << setw(12) << a[i].tongluong;
		cout << endl;
	}
}
int main()
{
	nhanvien nv[50];
	int n;
	cout << "Nhap so luong nhan vien: ";
	cin >> n;
	nhap(nv,n);
	tinhLuongCB(nv,n);
	tinhThuong(nv,n);
	tinhTongLuong(nv,n);
	xuat(nv,n);
	return 0;
}


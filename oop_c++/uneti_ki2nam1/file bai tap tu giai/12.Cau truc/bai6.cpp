#include<iostream>
#include<iomanip>
using namespace std;

typedef struct
{
	char manv[11];
	char tennv[25];
	float luong;
	float phucap;
	float tongluong;
} nhanvien;

void nhap(nhanvien a[], int n)
{	
	for (int i=0; i<n; i++)
	{
		cout << "(*) Nhap nhan vien thu "<<i+1<<endl;
		cin.ignore();
		cout << "Nhap ma nhan vien: "; gets(a[i].manv);
		cout << "Nhap ten nhan vien: "; gets(a[i].tennv);
		cout << "Nhap luong cua nhan vien: "; cin >> a[i].luong;
		cout << endl;
	}
}
void tinhPhuCap(nhanvien a[], int n)
{
	for (int i=0; i<n; i++)
		a[i].phucap = a[i].luong * 0.25;
}
void tinhTongLuong(nhanvien a[], int n)
{
	for (int i=0; i<n; i++)
		a[i].tongluong = a[i].luong + a[i].phucap;
}
void tieude()
{
	cout << left << setw(15) << "Ma nhan vien";
	cout << left << setw(20) << "Ten nhan vien";
	cout << left << setw(18) << "Luong nhan vien";
	cout << left << setw(12) << "Phu cap";
	cout << left << setw(15) << "Tong luong";
	cout << endl;
}
void xuat(nhanvien a[], int n)
{
	cout << "\n----------------------------DANH SACH NHAN VIEN----------------------------"<<endl;
	tieude();
	for (int i=0; i<n; i++)
	{
		cout << left << setw(15) << a[i].manv;
		cout << left << setw(20) << a[i].tennv;
		cout << left << setw(18) << a[i].luong;
		cout << left << setw(12) << a[i].phucap;
		cout << left << setw(15) << a[i].tongluong;
		cout << endl;
	}
}
void swap(nhanvien &nv1, nhanvien &nv2)
{
	nhanvien tg;
	tg = nv1;
	nv1 = nv2;
	nv2 = tg;
}
void sapxep(nhanvien a[], int n)
{
	for (int i=0; i<n-1; i++)
	{
		for (int j=i+1; j<n; j++)
		{
			if (a[i].tongluong < a[j].tongluong)
				swap(a[i],a[j]);
		}
	}
}
int main()
{
	nhanvien nv[50];
	int n;
	cout << "Nhap so luong nhan vien: ";
	cin >> n;
	nhap(nv,n);
	tinhPhuCap(nv,n);
	tinhTongLuong(nv,n);
	xuat(nv,n);
	sapxep(nv,n);
	xuat(nv,n);
	return 0;
}


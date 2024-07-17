#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

typedef struct
{
	int id;
	char tensv[20];
	int tuoi;
	float diemtk1, diemtk2; // diem tong ket hoc ki 1 va 2
} sinhvien;
void nhap(sinhvien a[], int n)
{
	for (int i=0; i<n; i++)
	{
		cin.ignore();
		cout << "(*) Nhap thong tin sinh vien thu "<<i+1<<endl;
		cout << "Nhap ho ten sinh vien: "; gets(a[i].tensv);
		cout << "Nhap ID cua sinh vien: "; cin >> a[i].id;
		cout << "Nhap tuoi sinh vien: "; cin >> a[i].tuoi;
		cout << "Nhap diem tong ket hoc ki 1: "; cin >> a[i].diemtk1;
		while(a[i].diemtk1 < 0 || a[i].diemtk1 > 10)
		{
			cout << "Nhap lai diem tong ket hoc ki 1 (0<diem<10): ";
			cin >> a[i].diemtk1;
		}
		cout << "Nhap diem tong ket hoc ki 2: "; cin >> a[i].diemtk2;
		while(a[i].diemtk2 < 0 || a[i].diemtk2 > 10)
		{
			cout << "Nhap lai diem tong ket hoc ki 2 (0<diem<10): ";
			cin >> a[i].diemtk2;
		}
		cout << endl;
	}
}
void tieude()
{
	cout << "\t";
	cout << left << setw(10) << "Ma ID";
	cout << left << setw(25) << "Ten sinh vien";
	cout << left << setw(8) << "Tuoi";
	cout << left << setw(12) << "Diem hk1";
	cout << left << setw(12) << "Diem hk2";
	cout << endl;
}
void xuat(sinhvien a[], int n)
{
	cout << "\n\t_______________________THONG KE SINH VIEN______________________"<<endl;
	tieude();
	for (int i=0; i<n; i++)
	{
		cout << "\t";
		cout << left << setw(10) << a[i].id;
		cout << left << setw(25) << a[i].tensv;
		cout << left << setw(8) << a[i].tuoi;
		cout << left << setw(12) << a[i].diemtk1;
		cout << left << setw(12) << a[i].diemtk2;
		cout << endl;
	}
}
void timMax(sinhvien a[], int n)
{
	int m=0;
	cout << "\n\t___________________SINH VIEN DIEM CAO NHAT_____________________"<<endl;
	tieude();
	float max = (a[0].diemtk1 + a[0].diemtk2)/2;
	for (int i=0; i<n; i++)
	{		
		if (((a[i].diemtk1 + a[i].diemtk2)/2) > max)
		{
			max = (a[i].diemtk1 + a[i].diemtk2)/2;
			m = i;
		}
	}
	cout << "\t";
	cout << left << setw(10) << a[m].id;
	cout << left << setw(25) << a[m].tensv;
	cout << left << setw(8) << a[m].tuoi;
	cout << left << setw(12) << a[m].diemtk1;
	cout << left << setw(12) << a[m].diemtk2;
	cout << endl;
}
void sinhVienTienBo(sinhvien a[], int n)
{
	cout << "\n\t__________________THONG KE SINH VIEN TIEN BO___________________"<<endl;
	tieude();
	for (int i=0; i<n; i++)
	{
		if (a[i].diemtk1 < a[i].diemtk2)
		{
			cout << "\t";
			cout << left << setw(10) << a[i].id;
			cout << left << setw(25) << a[i].tensv;
			cout << left << setw(8) << a[i].tuoi;
			cout << left << setw(12) << a[i].diemtk1;
			cout << left << setw(12) << a[i].diemtk2;
			cout << endl;
		}
	}
}
int main()
{
	sinhvien sv[21];
	int n;
	cout << "Nhap vao so luong hoc sinh: ";
	cin >> n;
	nhap(sv,n);
	xuat(sv,n);
	timMax(sv,n);
	sinhVienTienBo(sv,n);
	return 0;
}


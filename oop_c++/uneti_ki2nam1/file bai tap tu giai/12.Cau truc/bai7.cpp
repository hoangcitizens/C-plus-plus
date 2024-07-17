#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

typedef struct 
{
	char mahs[12];
	char tenhs[20];
	float diemT, diemL, diemH; // diem toan, ly, hoa
	float diemTB;
	char xeploai[12];
} hocsinh;
void nhap(hocsinh a[], int n)
{
	for (int i=0; i<n; i++)
	{
		cin.ignore();
		cout << "(*) Nhap thong tin hoc sinh thu "<<i+1<<endl;
		cout << "Nhap ma hoc sinh: "; gets(a[i].mahs);
		cout << "Nhap ho ten sinh vien: "; gets(a[i].tenhs);
		cout << "Nhap diem Toan: "; cin >> a[i].diemT;
		cout << "Nhap diem Ly: "; cin >> a[i].diemL;
		cout << "Nhap diem Hoa: "; cin >> a[i].diemH;
		cout << endl;
	}
}
void tinhDiemTB(hocsinh a[], int n)
{
	for (int i=0; i<n; i++)
		a[i].diemTB = (a[i].diemT + a[i].diemL + a[i].diemH)/3;
}
void tieude()
{
	cout << left << setw(15) << "Ma hoc sinh";
	cout << left << setw(23) << "Ho ten hoc sinh";
	cout << left << setw(12) << "Diem Toan";
	cout << left << setw(12) << "Diem Ly";
	cout << left << setw(12) << "Diem Hoa";
	cout << left << setw(12) << "Diem TB";
	cout << left << setw(12) << "Xep loai";
	cout << endl;
}
void xeploai(hocsinh a[], int n)
{ 
	for (int i=0; i<n; i++)
	{
		if(a[i].diemTB >= 9)
			strcpy(a[i].xeploai,"Xuat sac");
		else
			if(a[i].diemTB >=8)
				strcpy(a[i].xeploai,"Gioi");
		else
			if(a[i].diemTB >=6.5)
				strcpy(a[i].xeploai,"Kha");
		else
			if(a[i].diemTB >= 5)
				strcpy(a[i].xeploai,"Trung binh");
		else
			strcpy(a[i].xeploai,"Yeu");
	}
}
void xuat(hocsinh a[], int n)
{
	cout << "\n_________________________________DANH SACH THONG TIN HOC SINH_________________________________"<<endl;
	tieude();
	for (int i=0; i<n; i++)
	{
		cout << left << setw(15) << a[i].mahs;
		cout << left << setw(23) << a[i].tenhs;
		cout << left << setw(12) << a[i].diemT;
		cout << left << setw(12) << a[i].diemL;
		cout << left << setw(12) << a[i].diemH;
		cout << left << setw(12) << a[i].diemTB;
		cout << left << setw(12) << a[i].xeploai;
		cout << endl;
	}
}
void dsHocSinhGioi(hocsinh a[], int n)
{
	cout << "\n___________________________________DANH SACH HOC SINH GiOI____________________________________"<<endl;
	tieude();
	for (int i=0; i<n; i++)
	{
		if((strcmp(a[i].xeploai,"Gioi")==0) || (strcmp(a[i].xeploai,"Xuat sac")==0))
		{
			cout << left << setw(15) << a[i].mahs;
			cout << left << setw(23) << a[i].tenhs;
			cout << left << setw(12) << a[i].diemT;
			cout << left << setw(12) << a[i].diemL;
			cout << left << setw(12) << a[i].diemH;
			cout << left << setw(12) << a[i].diemTB;
			cout << left << setw(12) << a[i].xeploai;
			cout << endl;
		} 
	}
}
int main()
{
	hocsinh hs[50];
	int n;
	cout << "Nhap so luong hoc sinh: ";
	cin >> n;
	nhap(hs,n);
	tinhDiemTB(hs,n);
	xeploai(hs,n);
	xuat(hs,n);
	dsHocSinhGioi(hs,n);
	return 0;
}


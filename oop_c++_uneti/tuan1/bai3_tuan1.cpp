#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

struct hang_hoa
{
	char mh[8];
	char tensp[30];
	int soluong;
	float dongia;
	float thanhtien;	
};
void input(hang_hoa a[], int n)
{
	for (int i=0; i < n; i++)
	{
		cin.ignore();
		cout << "(*) Nhap thong tin mat hang thu " << i+1 << endl;
		cout << "Nhap ma mat hang: "; gets(a[i].mh);
		cout << "Nhap ten mat hang: "; gets(a[i].tensp);
		cout << "So luong mat hang: "; cin >> a[i].soluong;
		cout << "Don gia mat hang: "; cin >> a[i].dongia;
		cout << endl;
	}
}
void tinh_tien(hang_hoa a[], int n)
{
	for (int i=0; i < n; i++)
		a[i].thanhtien = a[i].soluong * a[i].dongia;
}
void tieude()
{
	cout << "\t";
	cout << left << setw(10) << "Ma hang";
	cout << left << setw(30) << "Ten mat hang";
	cout << left << setw(10) << "So luong";
	cout << left << setw(10) << "Don gia";
	cout << left << setw(10) << "Thanh tien";
	cout << endl;
}
void output(hang_hoa a[], int n)
{
	cout << "\t______________________DANH SACH THONG TIN MAT HANG____________________" << endl;
	tieude();
	for (int i=0; i < n; i++)
	{
		cout << "\t";
		cout << left << setw(10) << a[i].mh;
		cout << left << setw(30) << a[i].tensp;
		cout << left << setw(10) << a[i].soluong;
		cout << left << setw(10) << a[i].dongia;
		cout << left << setw(10) << a[i].thanhtien;
		cout << endl;
	}
}
void don_gia50(hang_hoa a[], int n)
{
	cout << "\t_____________DANH SACH THONG TIN MAT HANG DON GIA > 50________________" << endl;
	tieude();
	for (int i=0; i < n; i++)
	{
		if (a[i].dongia > 50)
		{
			cout << "\t";
			cout << left << setw(10) << a[i].mh;
			cout << left << setw(30) << a[i].tensp;
			cout << left << setw(10) << a[i].soluong;
			cout << left << setw(10) << a[i].dongia;
			cout << left << setw(10) << a[i].thanhtien;
			cout << endl;	
		}
	}
}
int main()
{
	int n;
	cout << "Nhap so luong mat hang: ";
	cin >> n;
	hang_hoa a[n];
	input(a,n);
	tinh_tien(a,n);
	output(a,n);
	don_gia50(a,n);
	return 0;
}

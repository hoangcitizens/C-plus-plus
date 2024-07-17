#include<iostream>
#include<math.h>
#include<iomanip>
#include<string>
using namespace std;

typedef struct
{
	char ma[10];
	char tenhang[20];
	int soluong;
	float dongia;
	float thanhtien;
} mat_hang;

void input(mat_hang *a, int n)
{
	for (int i=0 ; i < n; i++)
	{
		cin.ignore();
		cout << "(*) Nhap mat hang thu " << i+1 << endl;
		cout << "Nhap ma hang: "; cin.getline((*(a+i)).ma,10);
		cout << "Nhap ten mat hang: "; cin.getline((*(a+i)).tenhang,20);
		cout << "Nhap so luong mat hang: "; cin >> (*(a+i)).soluong;
		cout << "Nhap don gia mat hang: "; cin >> (*(a+i)).dongia;
		cout << endl;
	}
}
void tieude()
{
	cout << "\t";
	cout << left << setw(15) << "Ma mat hang";
	cout << left << setw(20) << "Ten mat hang";
	cout << left << setw(10) << "So luong";
	cout << left << setw(10) << "Don gia";
	cout << left << setw(10) << "Thanh tien";
	cout << endl;
}
void thanh_tien(mat_hang *a, int n)
{
	for (int i=0; i < n; i++)
	{
		(*(a+i)).thanhtien = (*(a+i)).soluong * (*(a+i)).dongia;
	}
}
void output(mat_hang *a, int n)
{
	cout << "\t______________________THONG TIN CAC MAT HANG_____________________" << endl;
	tieude();
	for (int i=0; i < n; i++)
	{
		cout << "\t";
		cout << left << setw(15) << (*(a+i)).ma;
		cout << left << setw(20) << (*(a+i)).tenhang;
		cout << left << setw(10) << (*(a+i)).soluong;
		cout << left << setw(10) << (*(a+i)).dongia;
		cout << left << setw(10) << (*(a+i)).thanhtien;
		cout << endl;
	}
}

int main()
{
	int n;
	cout << "Nhap so luong cac mat hang: ";
	cin >> n;
	mat_hang a[n];
	input(a,n);
	thanh_tien(a,n);
	output(a,n);
	delete a;
	return 0;
}


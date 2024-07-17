#include<iostream>
#include<iomanip>
using namespace std;
typedef struct
{
	char mamh[10];
	char tenmh[20];
	int soluong;
	float dongia;
	float thanhtien;
} matHang;
void nhapds(matHang a[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout << "\nNhap mat hang thu "<<i+1<<endl;
		cin.ignore();
		cout << "Ma mat hang: "; cin.getline(a[i].mamh,10);
		cout << "Ten mat hang: "; cin.getline(a[i].tenmh,20);
		cout << "So luong: "; cin>>a[i].soluong;
		cout << "Don gia: "; cin>>a[i].dongia;
	}
} 
void tieude()
{
	cout << setw(10) << "Ma mh";
	cout << setw(20) << "Ten mat hang";
	cout << setw(10) << "So luong";
	cout << setw(15) << "Don gia";
	cout << setw(15) << "Thanh tien";
	cout << endl;
}
void inds(matHang a[], int n)
{
	cout <<"\n ---     Danh sach mat hang     ---"<<endl;
	tieude();
	for(int i=0; i<n; i++)
	{ 
		cout << setw(10) << a[i].mamh;
		cout << setw(20) << a[i].tenmh;
		cout << setw(10) << a[i].soluong;
		cout << setw(15) << a[i].dongia;
		cout << setw(15) << a[i].thanhtien;
		cout << endl;
	}
}
void tinhThanhTien(matHang a[], int n)
{
	for(int i=0; i<n; i++)
		a[i].thanhtien = a[i].soluong*a[i].dongia;
}
void soluongduoi50(matHang a[], int n)
{
	cout << "\n --Ds mh so luong duoi 50--" << endl;
	tieude();
	for(int i=0; i<n; i++)
	if(a[i].soluong < 50)
	{ 
		cout << setw(10) << a[i].mamh;
		cout << setw(20) << a[i].tenmh;
		cout << setw(10) << a[i].soluong;
		cout << setw(15) << a[i].dongia;
		cout << setw(15) << a[i].thanhtien;
		cout << endl;
	}
}
int main()
{ 
	int n;
	matHang mh[50];
	cout << "Nhap so mat hang: ";
	cin >> n;
	nhapds(mh,n);
	tinhThanhTien(mh,n);
	inds(mh,n);
	soluongduoi50(mh,n);
	return 0;
}


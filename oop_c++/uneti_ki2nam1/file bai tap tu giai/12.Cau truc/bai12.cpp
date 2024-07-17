#include<iostream>
#include<iomanip>
using namespace std;

typedef struct
{
	int x;
	int y;
} toado;
void nhap(toado a[], int n)
{
	for (int i=0; i<n; i++)
	{
		cout << "(*) Nhap toa to diem thu " << i+1 << endl;
		cout << "Nhap hoanh do: "; cin >> a[i].x;
		cout << "Nhap tung do: "; cin >> a[i].y;
		cout << endl;
	}
}
void tieude()
{
	cout << "\t";
	cout << left << setw(13) << "Hoanh do";
	cout << left << setw(10) << "Tung do";
	cout << endl;
}
void xuat(toado a[], int n)
{
	cout << "\t_____TOA DO xOy_____" << endl;
	tieude();
	for (int i=0; i<n; i++)
	{
		cout << "\t";
		cout << left << setw(13) << a[i].x;
		cout << left << setw(10) << a[i].y;
		cout << endl;
	}
}
void timDoiXung(toado a[], int n)
{
	for (int i=0; i<n; i++)
	{
		cout << "Diem doi xung cua ("<<a[i].x<<","<<a[i].y<<") qua truc Ox la ("<<a[i].x<<","<<"-"<<a[i].y<<")";
		cout << endl;
	}
	cout << endl;
	for (int i=0; i<n; i++)
	{
		cout << "Diem doi xung cua ("<<a[i].x<<","<<a[i].y<<") qua truc Oy la (-"<<a[i].x<<","<<a[i].y<<")";
		cout << endl;
	}
	cout << endl;
	for (int i=0; i<n; i++)
	{
		cout << "Diem doi xung cua ("<<a[i].x<<","<<a[i].y<<") qua tam la (-"<<a[i].x<<","<<"-"<<a[i].y<<")";
		cout << endl;
	}
	cout << endl;
}
void tinhToaDo(toado a[], int n)
{
	int tong, hieu, tich;
	for (int i=0; i<n; i++)
	{
		cout << "Tong 2 diem A("<<a[i].x<<","<<a[i].y<<") va B("<<a[i+1].x<<","<<a[i+1].y<<") la: "<<endl;
		cout << "\tC(" << a[i].x + a[i+1].x << "," << a[i].y + a[i+1].y << ")" << endl;;
		break;
	}
	for (int i=0; i<n; i++)
	{
		cout << "Hieu 2 diem A("<<a[i].x<<","<<a[i].y<<") va B("<<a[i+1].x<<","<<a[i+1].y<<") la: "<<endl;
		cout << "\tD(" << a[i].x - a[i+1].x << "," << a[i].y - a[i+1].y << ")" << endl;;
		break;
	}
	for (int i=0; i<n; i++)
	{
		cout << "Tich 2 diem A("<<a[i].x<<","<<a[i].y<<") va B("<<a[i+1].x<<","<<a[i+1].y<<") la: "<<endl;
		cout << "\tE(" << a[i].x * a[i+1].x << "," << a[i].y * a[i+1].y << ")";
		break;
	}
	cout << endl;
}
int main()
{
	toado td[2];
	nhap(td,2);
	xuat(td,2);
	timDoiXung(td,2);
	tinhToaDo(td,2);
	return 0;
}


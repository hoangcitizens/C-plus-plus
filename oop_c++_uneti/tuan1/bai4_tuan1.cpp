#include<iostream>
#include<math.h>
#include<iomanip>
#include<string.h>
using namespace std;

struct Hocsinh
{
	char ms[7];
	char ht[30];
	char qq[30];
	float td;	
};
void input(Hocsinh a[], int n)
{
	for (int i=0; i < n; i++)
	{
		cin.ignore();
		cout << "(*) Nhap thong tin hoc sinh thu " << i+1 << endl;
		cout << "Nhap ma hoc sinh: "; gets(a[i].ms);
		cout << "Nhap ho va ten hoc sinh: "; gets(a[i].ht);
		cout << "Que quan hoc sinh: "; gets(a[i].qq);
		cout << "Tong diem hoc sinh: "; cin >> a[i].td;
		while (a[i].td < 0)
		{
			cout << "Nhap tong diem la so duong: ";
			cin >> a[i].td;
		}
		cout << endl;
	}
}
void tieude()
{
	cout << "\t";
	cout << left << setw(10) << "Ma hs";
	cout << left << setw(30) << "Ho va ten";
	cout << left << setw(30) << "Que quan"; 
	cout << left << setw(10) << "Tong diem";
	cout << endl;
}
void output(Hocsinh a[], int n)
{
	cout << "\t_________________________DANH SACH THONG TIN HOC SINH__________________________" << endl;
	tieude();
	for (int i=0; i < n; i++)
	{
		cout << "\t";
		cout << left << setw(10) << a[i].ms;
		cout << left << setw(30) << a[i].ht;
		cout << left << setw(30) << a[i].qq; 
		cout << left << setw(10) << a[i].td;
		cout << endl;
	}
}
void giam_dan(Hocsinh a[], int n)
{
	for (int i=0; i < n-1; i++)
	{
		for (int j=i+1; j < n; j++)
		{
			if (a[i].td < a[j].td)
				swap(a[i].td,a[j].td);
		}
	}
	cout << "\t___________________DANH SACH HOC SINH GIAM DAN THEO TONG DIEM__________________" << endl;
	tieude();
	for (int i=0; i < n; i++)
	{
		cout << "\t";
		cout << left << setw(10) << a[i].ms;
		cout << left << setw(30) << a[i].ht;
		cout << left << setw(30) << a[i].qq; 
		cout << left << setw(10) << a[i].td;
		cout << endl;
	}
}
void que_nd(Hocsinh a[], int n)
{
	unsigned int kt = 0;
	cout << "\t________________________DANH SACH HOC SINH QUE NAM DINH_______________________" << endl;
	tieude();
	for (int i=0; i < n; i++)
	{
		if (strcmp(a[i].qq,"NAM DINH") == 0 || (strcmp(a[i].qq,"Nam Dinh") == 0) || (strcmp(a[i].qq,"nam dinh") == 0))
		{
			kt++;
			cout << "\t";
			cout << left << setw(10) << a[i].ms;
			cout << left << setw(30) << a[i].ht;
			cout << left << setw(30) << a[i].qq; 
			cout << left << setw(10) << a[i].td;
			cout << endl;
		}
	}
	if (kt == 0)
		cout << "\t=> Khong co hoc sinh nao que Nam Dinh !" << endl;
}
int main()
{
	int n;
	cout << "Nhap vao so luong hoc sinh: ";
	cin >> n;
	while (n < 1)
	{
		cout << "Nhap vao so luong > 0 ";
		cin >> n;
	}
	Hocsinh a[n];
	input(a,n);
	output(a,n);
	giam_dan(a,n);
	que_nd(a,n);
	return 0;
}


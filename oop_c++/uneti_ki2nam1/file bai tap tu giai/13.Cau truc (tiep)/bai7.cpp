#include<iostream>
#include<iomanip>
using namespace std;

struct sinhvien
{
	char masv[11];
	char tensv[25];
	int namsinh;
	float diemtb;
};
void nhap(sinhvien a[], int n)
{
	for (int i=0; i<n; i++)
	{
		cin.ignore();
		cout << " (*) Nhap thong tin sinh vien thu " << i+1 << endl;
		cout << "Nhap ma sinh vien: "; gets(a[i].masv);
		cout << "Nhap ho va ten sinh vien: "; gets(a[i].tensv);
		cout << "Nhap nam sinh cua sinh vien: "; cin >> a[i].namsinh;
		cout << "Nhap diem trung binh cua sinh vien: "; cin >> a[i].diemtb;
		while(a[i].diemtb < 0 || a[i].diemtb > 10)
		{
			cout << "Nhap lai diem trung binh cua sinh vien (0<diem<10): "; 
			cin >> a[i].diemtb;
		}
		cout << endl;
	}
}
void tieude()
{
	cout << "\t";
	cout << left << setw(15) << "Ma sinh vien";
	cout << left << setw(25) << "Ten sinh vien";
	cout << left << setw(10) << "Nam sinh";
	cout << left << setw(15) << "Diem trung binh";
	cout << endl;
}
void xuat(sinhvien a[], int n)
{
	cout << "\t________________________THONG TIN SINH VIEN______________________" << endl;
	tieude();
	for (int i=0; i<n; i++)
	{
		cout << "\t";
		cout << left << setw(15) << a[i].masv;
		cout << left << setw(25) << a[i].tensv;
		cout << left << setw(10) << a[i].namsinh;
		cout << left << setw(15) << a[i].diemtb;
		cout << endl;
	}
	cout << endl;
}
void swap(sinhvien &sv1,sinhvien &sv2)
{
	sinhvien tg;
	tg = sv1;
	sv1 = sv2;
	sv2 = tg;
}
void sapXepTheoTuoi(sinhvien a[], int n)
{
	for (int i=0; i<n-1; i++)
	{
		for (int j=i+1; j<n; j++)
		{
			if (a[i].namsinh > a[j].namsinh)
				swap(a[i],a[j]);
		}
	}
	cout << "\t_________________________SAP XEP THEO TUOI_______________________" << endl;
	tieude();
	for (int i=0; i<n; i++)
	{
		cout << "\t";
		cout << left << setw(15) << a[i].masv;
		cout << left << setw(25) << a[i].tensv;
		cout << left << setw(10) << a[i].namsinh;
		cout << left << setw(15) << a[i].diemtb;
		cout << endl;
	}
}
int main()
{
	sinhvien sv[20];
	int n;
	cout << "Nhap so luong sinh vien : ";
	cin >> n;
	nhap(sv,n);
	xuat(sv,n);
	sapXepTheoTuoi(sv,n);
	return 0;
}


#include<iostream>
#include<iomanip>
using namespace std;

typedef struct
{
	int id;
	char tensv[20];
	int tuoi;
	float diemtk1, diemtk2, diemtb;
} sinhvien;
void nhap(sinhvien a[], int n)
{
	for (int i=0; i<n; i++)
	{
		cin.ignore();
		cout << " (*) Nhap thong tin sinh vien thu "<<i+1<<endl;
		cout << "Nhap ten sinh vien: "; gets(a[i].tensv);
		cout << "Nhap ID sinh vien: "; cin >> a[i].id;
		cout << "Nhap tuoi sinh vien: "; cin >> a[i].tuoi;
		cout << "Nhap diem tong ket hoc ki 1: "; cin >> a[i].diemtk1;
		while (a[i].diemtk1 < 0 || a[i].diemtk1 > 10)
		{
			cout << "Nhap lai diem tong ket hoc ki 1 (0<diem<10): ";
			cin >> a[i].diemtk1;
		}
		cout << "Nhap diem tong ket hoc ki 2: "; cin >> a[i].diemtk2;
		while (a[i].diemtk2 < 0 || a[i].diemtk2 > 10)
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
	cout << left << setw(23) << "Ten sinh vien";
	cout << left << setw(10) << "Tuoi";
	cout << left << setw(10) << "Diem hk1";
	cout << left << setw(8) << "Diem hk2";
	cout << endl;
}
void xuat(sinhvien a[], int n)
{
	cout << "\t_____________________THONG TIN SINH VIEN_____________________" << endl;
	tieude();
	for (int i=0; i<n; i++)
	{
		cout << "\t";
		cout << left << setw(10) << a[i].id;
		cout << left << setw(23) << a[i].tensv;
		cout << left << setw(10) << a[i].tuoi;
		cout << left << setw(10) << a[i].diemtk1;
		cout << left << setw(8) << a[i].diemtk2;
		cout << endl;
	}
	cout << endl;
}
void tinhDiemTb(sinhvien a[], int n)
{
	float S=0;
	for (int i=0; i<n; i++)
		a[i].diemtb = (a[i].diemtk1 + a[i].diemtk2 * 2)/3;
	cout << "\t______DIEM TRUNG BINH CUA CA LOP______" << endl;
	cout << "\t";
	cout << left << setw(23) << "Ten sinh vien";
	cout << left << setw(15) << "Diem trung binh";
	cout << endl;
	for (int i=0; i<n; i++)
	{
		cout << "\t";
		cout << left << setw(23) << a[i].tensv;
		cout << left << setw(15) << a[i].diemtb;
		cout << endl;
	}
	cout << endl;
}
void tongKetMax(sinhvien a[], int n)
{
	int m = 0;
	int max = (a[0].diemtk1 + a[0].diemtk2)/2;
	cout << "\t______________SINH VIEN DIEM TONG KET CAO NHAT_______________" << endl;
	tieude();
	for (int i=0; i<n; i++)
	{
		if ((a[i].diemtk1 + a[i].diemtk2)/2 > max)
		{
			max = (a[i].diemtk1 + a[i].diemtk2)/2;
			m = i;
		}		
	}
	cout << "\t";
	cout << left << setw(10) << a[m].id;
	cout << left << setw(23) << a[m].tensv;
	cout << left << setw(10) << a[m].tuoi;
	cout << left << setw(10) << a[m].diemtk1;
	cout << left << setw(8) << a[m].diemtk2;
	cout << "\n" << endl;
}
void sinhVienTienBo(sinhvien a[], int n)
{
	cout << "\t______________________SINH VIEN TIEN BO______________________" << endl;
	tieude();
	for (int i=0; i<n; i++)
	{
		if (a[i].diemtk2 > a[i].diemtk1)
		{
			cout << "\t";
			cout << left << setw(10) << a[i].id;
			cout << left << setw(23) << a[i].tensv;
			cout << left << setw(10) << a[i].tuoi;
			cout << left << setw(10) << a[i].diemtk1;
			cout << left << setw(8) << a[i].diemtk2;
			cout << endl;
		}
	}
	cout << endl;
}
int main()
{
	sinhvien sv[21];
	int n;
	cout << "Nhap so sinh vien can thong ke: ";
	cin >> n;
	nhap(sv,n);
	xuat(sv,n);
	tinhDiemTb(sv,n);
	tongKetMax(sv,n);
	sinhVienTienBo(sv,n);
	return 0;
}


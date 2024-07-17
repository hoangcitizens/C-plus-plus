#include<iostream>
#include<iomanip>
using namespace std;

typedef struct
{
	int ng;
	int th;
	int nam;
} ngaythang;
typedef struct
{
	char hoten[30];
	ngaythang ns;
	int gt;
	float diem;
} sinhvien;
sinhvien lop[3];
void nhap(sinhvien *p)
{
	cout << "Ho ten: "; cin.getline(p->hoten,30);
	cout << "Ngay sinh: "; cin >> (p->ns).ng;
	cout << "Thang: "; cin >> (p->ns).th;
	cout << "Nam: "; cin >> (p->ns).nam;
	cout << "Gioi tinh: "; cin >> p->gt;
	cout << "Diem: "; cin >> p->diem;
	cin.ignore(); 
}
void nhapds(sinhvien *a)
{
	int sosv = sizeof(lop) / sizeof(sinhvien);
	for (int i=1; i<=sosv; i++)
	{
		cout << "(*) Sinh vien thu " << i << endl;
		nhap(&a[i]);
		cout << endl;	
	}
	cout << endl;
}
void in(sinhvien x)
{
	cout << x.hoten << "\t" ;
	cout << x.ns.ng << "/" << x.ns.th << "/" <<
	x.ns.nam << "\t" ;
	cout << x.gt << "\t";
	cout << x.diem << endl;
}
void inds(const sinhvien *a)
{
	int sosv = sizeof(lop) / sizeof(sinhvien);
	for (int i=1; i<=sosv; i++)
		in(a[i]);
	cout << endl;
}
void insvdiemcaonhat(sinhvien *a)
{ 
	float max;
	int sosv = sizeof(lop) / sizeof(sinhvien);
	max = a[0].diem;
	for (int i=1; i<=sosv; i++)
	{
		if(max < a[i].diem)
			max = a[i].diem;
	}
	int j = 0;
	cout << "Diem cao nhat lop: " << endl;
	for (int i = 1; i <= sosv; i++)
	{
		if (a[i].diem == max)
		{
			cout << "#"<<j + 1 << endl;
			cout << a[i].hoten << " " << a[i].ns.ng;
			cout << "/" << a[i].ns.th << "/";
			cout << a[i].ns.nam << " ";
			cout << a[i].gt << " " << a[i].diem<<endl;
			j++;
		}
	}
}	

int main()
{
	cout << "--- Nhap danh sach sinh vien ---" << endl;
	nhapds(lop);
	inds(lop); //in ds vua nhap
	insvdiemcaonhat(lop);
	return 0;
}


#include<iostream>
#include<iomanip>
#include<conio.h>
using namespace std;

typedef struct
{
	int ng;
	int th;
	int nam;	
} ngay_thang;
typedef struct
{
	char hoten[30];
	ngay_thang ns;
	int gt; 
	float diem;
} sinh_vien;
sinh_vien lop[5];
void nhap(sinh_vien *p)
{
	cout << "Nhap ho ten: ";cin.ignore(); cin.getline(p->hoten,30);
	cout << "Ngay sinh: "; cin >> (p->ns).ng;
	cout << "Thang: "; cin >> (p->ns).th;
	cout << "Nam: "; cin >> (p->ns).nam;
	cout << "Gioi tinh: "; cin >> p->gt;
	cout << "Diem: "; cin >> p->diem;
	cout << endl;
}
void nhapds(sinh_vien *a)
{
	int sosv = sizeof(lop) / sizeof(sinh_vien);
	for (int i=1; i <= sosv; i++)
		nhap(&a[i]);
}
void in(sinh_vien x)
{
	cout << x.hoten << "\t";
	cout << x.ns.ng << "/" << x.ns.th << "/" << x.ns.nam << "\t";
	cout << x.gt << "\t";
	cout << x.diem << endl;
}
void inds(const sinh_vien *a) // khong the thay doi gia tri ma a chi toi thong qua a
{							  // nhung van co the thay doi dia chi ma a tro toi
	int sosv = sizeof(lop) / sizeof(sinh_vien);
	for (int i=1; i <= sosv; i++)
		in(a[i]);
}
void sua(sinh_vien &r)
{
	int chon;
	do{
		cout << "1: Sua ho ten" << endl;
		cout << "2: Sua ngay sinh" << endl;
		cout << "3: Sua gioi tinh" << endl;
		cout << "4: Sua diem" << endl;
		cout << "0: Thoi" << endl;
		cout << "Sua(0/1/2/3/4)?: "; cin >> chon;
		cin.ignore();
		switch (chon)
		{
			case 1: cin.getline(r.hoten,30); break;
			case 2: cin >> r.ns.ng >> r.ns.th >> r.ns.nam; break;
			case 3: cin >> r.gt; break;
			case 4: cin >> r.diem; break;
		}
	} while(chon);
}
void suads(sinh_vien *a)
{
	int n;
	cout << "Chon sinh vien can sua: ";
	cin >> n;
	cin.ignore();
	sua(a[n]);
}

int main()
{
	nhapds(lop);
	inds(lop);
	suads(lop);
	inds(lop);
	return 0;
}


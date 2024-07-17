#include<iostream>
#include<iomanip>
using namespace std;

typedef struct
{
	int x;
	int y;
} toado;
toado td[2];

void nhap(toado *a)
{
	cout << "Nhap hoanh do: "; cin >> a->x;
	cout << "Nhap tung do: "; cin >> a->y;
	cout << endl;
}
void nhapds(toado *a)
{
	int sodiem = sizeof(td) / sizeof(toado);
	for (int i=1; i <= sodiem ; i++)
		nhap(&a[i]);
}
void tieude()
{
	cout << "\t";
	cout << left << setw(13) << "Hoanh do";
	cout << left << setw(10) << "Tung do";
	cout << endl;
}
void xuat(toado *a)
{
	cout << "\t";
	cout << left << setw(13) << a->x;
	cout << left << setw(10) << a->y;
	cout << endl;
}
void xuatds(toado *a)
{
	
	int sodiem = sizeof(td) / sizeof(toado);
	for (int i=1; i <= sodiem ; i++)
		xuat(&a[i]);
}
void timDoiXung(toado *a)
{
	cout << "Diem doi xung cua ("<<a->x<<","<<a->y<<") qua truc Ox la ("<<a->x<<","<<"-"<<a->y<<")";
	cout << endl;
	cout << "Diem doi xung cua ("<<a->x<<","<<a->y<<") qua truc Oy la (-"<<a->x<<","<<a->y<<")";
	cout << endl;
	cout << "Diem doi xung cua ("<<a->x<<","<<a->y<<") qua tam la (-"<<a->x<<","<<"-"<<a->y<<")";
	cout << endl;
}
void tinhToaDo(toado a[])
{
	for (int i=1; i<=2; i++)
	{
		cout << "Tong 2 diem A("<<a[i].x<<","<<a[i].y<<") va B("<<a[i+1].x<<","<<a[i+1].y<<") la: "<<endl;
		cout << "\tC(" << a[i].x + a[i+1].x << "," << a[i].y + a[i+1].y << ")" << endl;;
		break;
	}
	for (int i=1; i<=2; i++)
	{
		cout << "Hieu 2 diem A("<<a[i].x<<","<<a[i].y<<") va B("<<a[i+1].x<<","<<a[i+1].y<<") la: "<<endl;
		cout << "\tD(" << a[i].x - a[i+1].x << "," << a[i].y - a[i+1].y << ")" << endl;;
		break;
	}
	for (int i=1; i<=2; i++)
	{
		cout << "Tich 2 diem A("<<a[i].x<<","<<a[i].y<<") va B("<<a[i+1].x<<","<<a[i+1].y<<") la: "<<endl;
		cout << "\tE(" << a[i].x * a[i+1].x << "," << a[i].y * a[i+1].y << ")";
		break;
	}
	cout << endl;
}

int main()
{
	cout << "Nhap toa do cua diem" << endl;
	nhap(td);
	cout << "\t_____TOA DO xOy_____" << endl;
	tieude();
	xuat(td);
	timDoiXung(td);
	nhapds(td);
	cout << "\t_____TOA DO xOy_____" << endl;
	tieude();
	xuatds(td);
	tinhToaDo(td);
	return 0;
}


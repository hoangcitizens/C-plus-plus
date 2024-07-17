#include<iostream>
#include<iomanip>
using namespace std;

typedef struct 
{
	char magv[15];
	char hoten[30];
	int somon;
	int hocky;
} giangvien;
void nhapds(giangvien a[], int n)
{
	for (int i=0; i<n; i++)
	{
		cout << "\nNhap giang vien thu: "<<i+1<<endl;
		cin.ignore();
		cout << "Ma giang vien: ";
		cin.getline(a[i].magv,15);
		cout << "Ten giang vien: ";
		cin.getline(a[i].hoten,30);
		cout << "So mon day: ";
		cin >> a[i].somon;
		cout << "Hoc ky : ";
		cin >> a[i].hocky;
		cout << endl;
	}
}
void tieude()
{
	cout << setw(15) << "Ma gv";
	cout << setw(30) << "Ten giang vien";
	cout << setw(15) << "So mon";
	cout << setw(15) << "Hoc ky";
	cout << endl;	
}
void inds(giangvien a[], int n)
{
	cout << "\n-----DANH SACH GIANG VIEN-----"<<endl;
	tieude();
	for (int i=0; i<n; i++)
	{
		cout << setw(15) << a[i].magv;
		cout << setw(30) << a[i].hoten;
		cout << setw(15) << a[i].somon;
		cout << setw(15) << a[i].hocky;
		cout << endl;
	}

}
void gvday5mon(giangvien a[], int n)
{
	cout << "\n-----DANH SACH GIANG VIEN DAY 5 MON-----"<<endl;
	tieude();
	for (int i=0; i<n; i++)
	{
		if (a[i].somon >= 5)
		{
			cout << setw(15) << a[i].magv;
			cout << setw(30) << a[i].hoten;
			cout << setw(15) << a[i].somon;
			cout << setw(15) << a[i].hocky;
			cout << endl;
		}
	}
}
int main()
{
	giangvien gv[50];
	int n;
	cout << "Nhap so giang vien: ";
	cin >> n;
	nhapds(gv,n);
	inds(gv,n);
	gvday5mon(gv,n);
	return 0;
}


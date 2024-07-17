#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

struct sach
{
	char masach[10];
	char tensach[20];
	char tentacgia[20];
	int sotrang;
	int namxuatban;
};
void nhap(sach a[], int n)
{
	for (int i=0; i<n; i++)
	{
		cin.ignore();
		cout << "(*) Nhap sach thu "<<i+1<<endl;
		cout << "Nhap ma sach: "; gets(a[i].masach);
		cout << "Nhap ten sach: "; gets(a[i].tensach);
		cout << "Nhap ten tac gia: "; gets(a[i].tentacgia);
		cout << "Nhap so trang: "; cin >> a[i].sotrang;
		cout << "Nhap nam xuat ban: "; cin >> a[i].namxuatban;
		cout << endl;
	}
}
void tieude()
{
	cout << "\t";
	cout << left << setw(10) << "Ma sach";
	cout << left << setw(19) << "Ten sach";
	cout << left << setw(20) << "Ten tac gia";
	cout << left << setw(12) << "So trang";
	cout << left << setw(15) << "Nam xuat ban";
	cout << endl;
}
void xuat(sach a[], int n)
{
	cout << "\n\t____________________________THONG TIN VE SACH____________________________"<<endl;
	tieude();
	for (int i=0; i<n; i++)
	{
		cout << "\t";
		cout << left << setw(10) << a[i].masach;
		cout << left << setw(19) << a[i].tensach;
		cout << left << setw(20) << a[i].tentacgia;
		cout << left << setw(12) << a[i].sotrang;
		cout << left << setw(15) << a[i].namxuatban;
		cout << endl;
	}
}
void timsach(sach a[], int n)
{
	for (int i=0; i<n; i++)
	{
		if (strstr(a[i].tentacgia,"Nguyen Van Anh") != NULL)
		{
			cout << "\n\t______________________THONG TIN VE SACH TAC GIA ANH______________________"<<endl;
			tieude();
			cout << "\t";
			cout << left << setw(10) << a[i].masach;
			cout << left << setw(19) << a[i].tensach;
			cout << left << setw(20) << a[i].tentacgia;
			cout << left << setw(12) << a[i].sotrang;
			cout << left << setw(15) << a[i].namxuatban;
			cout << endl;
		}
	}
}
int main()
{
	sach s[40];
	int n;
	cout << "Nhap so luong sach: ";
	cin >> n;
	nhap(s,n);
	xuat(s,n);
	timsach(s,n);
	return 0;
}


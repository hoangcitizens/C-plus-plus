#include<iostream>
#include<iomanip>
using namespace std;

typedef struct
{
	char masp[15];
	char tensp[30];
	int soluong;
	float dongia;
} san_pham;
void nhapds(san_pham a[], int m)
{
	for (int i=0; i<m; i++)
	{
		cin.ignore();
		cout << "* Nhap san pham thu  "<<i+1<<endl;
		cout << "Ma san pham: "; cin.getline(a[i].masp,15);
		cout << "Ten san pham: "; cin.getline(a[i].tensp,15);
		cout << "So luong san pham: "; cin >> a[i].soluong;
		cout << "Don gia san pham: "; cin >> a[i].dongia;
		cout << endl;
	}
}
void inds(san_pham a[], int m)
{
	cout << "\n\n---DANH SACH SAN PHAM---"<<endl;
	cout << setw(15) << "Ma san pham";
	cout << setw(30) << "Ten san pham";
	cout << setw(15) << "So luong";
	cout << setw(15) << "Don gia" << endl;
	for (int i=0; i<m; i++)
	{
		cout << setw(15) << a[i].masp;
		cout << setw(30) << a[i].tensp;
		cout << setw(15) << a[i].soluong;
		cout << setw(15) << a[i].dongia << endl;
	}
}
void spgiaduoi20000(san_pham a[], int m)
{
	cout << "\n\n---DANH SACH SAN PHAM CO GIA < 20000---"<<endl;
	cout << setw(15) << "Ma san pham";
	cout << setw(30) << "Ten san pham";
	cout << setw(15) << "So luong";
	cout << setw(15) << "Don gia" << endl;
	for (int i=0; i<m; i++)
	{
		if (a[i].dongia < 20000)
		{
			cout << setw(15) << a[i].masp;
			cout << setw(30) << a[i].tensp;
			cout << setw(15) << a[i].soluong;
			cout << setw(15) << a[i].dongia << endl;
		}
	}
}
int main()
{
	san_pham sp[50];
	int m;
	cout << "Nhap so san pham: ";
	cin >> m;
	nhapds(sp,m);
	inds(sp,m);
	spgiaduoi20000(sp,m);
	return 0;
}


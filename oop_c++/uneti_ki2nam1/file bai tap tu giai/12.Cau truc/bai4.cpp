#include<iostream>
#include<iomanip>
#define PI 3.14
using namespace std;

typedef struct 
{
	float R, S, C;
} hinhTron;
void nhap(hinhTron &x)
{
	cout << "R = ";
	cin >> x.R;
}
void xuat(hinhTron &x)
{
	cout << "\nBan kinh R = " << x.R; 
 	cout << "\nDien tich S = " << x.S; 
 	cout << "\nChu vi P = " << x.C <<endl;

}
void tinhDienTich(hinhTron &x)
{
	x.S = PI * x.R * x.R;
}
void tinhChuVi(hinhTron &x)
{
	x.C = 2 * PI * x.R;
}
void Swap(hinhTron &h1,hinhTron &h2)
{
	hinhTron tg;
	tg = h1;
	h1 = h2;
	h2 = tg;
}
void sapXepTheoDienTich(hinhTron ht[],int n)
{
	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(ht[i].S > ht[j].S)
				Swap(ht[i],ht[j]);
		}
	}
}
void sapXepTheoChuVi(hinhTron ht[], int n)
{
	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(ht[i].C < ht[j].C)
				Swap(ht[i],ht[j]);
 		}
 	}
}
int main()
{
	hinhTron a[100];
	int n;
	cout << "Nhap so luong hinh tron can tinh: ";
	cin >> n;
	while (n>100 || n<0)
	{
		cout << "Nhap lai so luong hinh tron (0<n<100): ";
		cin >> n;
	} 
	for(int i=0; i<n; i++)
	{
	cout << "Nhap ban kinh hinh tron thu "<<i+1<<": "; 
	nhap(a[i]);
	}
	for(int i=0; i<n; i++)
	{
	 	tinhDienTich(a[i]); 
	 	tinhChuVi(a[i]);
	}
	sapXepTheoDienTich(a,n);
	cout << "\nThu tu cac hinh tron theo S tu thap toi cao la:\n"; 
	for(int i=0; i<n; i++)
	{
	 	cout << "\nHinh " << i+1 << ": ";
	 	xuat(a[i]);
		cout << endl;
	}
	sapXepTheoChuVi(a,n);
	cout << "\nThu tu cac hinh tron theo chu vi tu cao toi thap la:\n"; 
	for(int i=0; i<n; i++)
	{
 		cout << "\nHinh "<<i+1<<":"; 
 		xuat(a[i]); 
 		cout << endl;
 	}
	return 0;
}


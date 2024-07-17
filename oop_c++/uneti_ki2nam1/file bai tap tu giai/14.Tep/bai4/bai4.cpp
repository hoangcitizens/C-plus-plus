#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

typedef struct
{ 
	char manv[10];
	char ten[30];
	char sdt[12];
	float hesoluong;
	float luongthang;
	int luongcb;
	float phucap;
	double thunhap;
} nhanvien;
void nhap_1nv(nhanvien *x)
{ 
	cin.ignore();
	cout << "Nhap ma nhan vien: "; cin.getline(x->manv,10);
	cout << "Nhap ten nhan vien: "; cin.getline(x->ten, 30);
	cout << "Nhap so dien thoai nhan vien: "; cin.getline(x->sdt, 12);
	cout << "Nhap luong co ban nhan vien: "; cin >> x->luongcb;
	cout << "Nhap phu cap cua nhan vien: "; cin >> x->phucap;
	cout << "Nhap he so luong cua nhan vien: "; cin >> x->hesoluong;
}
void nhap_ds( nhanvien a[], int n)
{ 
	for(int i=0; i<n; i++)
	{ 
		cout << "Nhap thong tin nhan vien thu: "<<i+1<<endl;
		nhap_1nv(&a[i]);
	}
}
void tieude()
{
	cout << setw(15) << "Ma nhan vien"<<"|";
	cout << setw(20) << "Ten nhan vien"<<"|";
	cout << setw(15) << "So dien thoai"<<"|";
	cout << setw(15) << "He so luong"<<"|";
	cout << setw(15) << "Luong thang"<<"|";
	cout << setw(15) << "Luong Co Ban"<<"|";
	cout << setw(15) << "Phu Cap"<<"|";
	cout << setw(15) << "Thu nhap"<<"|"<<endl;
}
void xuat_nv(nhanvien a[], int n)
{
	cout << "-------------- DANH SACH NHAN VIEN ------------------" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	tieude();
	for (int i=0; i<n; i++)
	{ 
		cout << setw(15) << a[i].manv<<"|";
		cout << setw(20) << a[i].ten<<"|";
		cout << setw(15) << a[i].sdt<<"|";
		cout << setw(15) << a[i].hesoluong<<"|";
		cout << setw(15) << a[i].luongthang<<"|";
		cout << setw(15) << a[i].luongcb<<"|";
		cout << setw(15) << a[i].phucap<<"|";
		cout << setw(15) << a[i].thunhap<<"|"<<endl;
	}
	cout << "---------------------------------------------------------------------------------------------------------------------------------------"<<endl;
}
void tinh_luong_thang(nhanvien a[], int n)
{
	for(int i=0; i<n; i++)
		a[i].luongthang = a[i].luongcb * a[i].hesoluong ;
}
void tinh_thu_nhap(nhanvien a[], int n)
{
	for(int i=0; i<n; i++)
		a[i].thunhap = (double)a[i].luongcb + a[i].phucap;
}
void tntangdan(nhanvien a[], int n)
{
	for (int i=0; i<n-1; i++)
	{
		for (int j=i+1; j<n; j++)
		{
			if(a[i].thunhap > a[j].thunhap)
			{ 
				nhanvien tg = a[i];
				a[i] = a[j];
				a[j] = tg;
			}
		}
	}
	xuat_nv(a,n);
}
int nhan_vien_luong_cao_nhat(nhanvien a[], int n)
{ 
	float max = a[0].thunhap;
	int vitri = 0;
	for(int i=1; i<n; i++)
	{
	
		if (max < a[i].thunhap)
		{ 
			max = a[i].thunhap;
			vitri =i;
		}
	}
	// bang ten nhan vien co thu nhap cao nhat
	cout << "DANH SACH NHAN THU NHAP CAO NHAT" << endl;
	tieude();
	cout << "-------------------------------" << endl;
	for(int i=0; i<n; i++)
	{
		if (a[i].thunhap == max)
		{
			cout << setw(15) << a[i].manv<<"|";
			cout << setw(20) << a[i].ten<<"|";
			cout << setw(15) << a[i].sdt<<"|";
			cout << setw(15) << a[i].hesoluong<<"|";
			cout << setw(15) << a[i].luongthang<<"|";
			cout << setw(15) << a[i].luongcb<<"|";
			cout << setw(15) << a[i].phucap<<"|";
			cout << setw(15) << a[i].thunhap<<"|"<<endl;
		}
	}
	cout<<"------------------------------"<<endl;
}
void xuat_theo_hs(nhanvien a[], int n, float hs)
{
	cout << "----- DANH SACH NHAN VIEN -----" << endl;
	cout << "--------------------------------" << endl;
	tieude();
	for (int i=0; i<n; i++)
	{
		if (a[i].hesoluong > hs )
		{ 
			cout << setw(15) << a[i].manv<<"|";
			cout << setw(20) << a[i].ten<<"|";
			cout << setw(15) << a[i].sdt<<"|";
			cout << setw(15) << a[i].hesoluong<<"|";
			cout << setw(15) << a[i].luongthang<<"|";
			cout << setw(15) << a[i].luongcb<<"|";
			cout << setw(15) << a[i].phucap<<"|";
			cout << setw(15) << a[i].thunhap<<"|"<<endl;
		}
	}
	cout<<"-------------------------------"<<endl;
}
int main()
{
	nhanvien ql[100], nv[100];
	int n; //n la so nha vien
	float hs;
	cout << "Nhap vao so nhan vien: "; cin>>n;
	nhap_ds(ql,n);
	tinh_luong_thang(ql,n);
	tinh_thu_nhap(ql,n);
	xuat_nv(ql,n);
	cout << "Nhap he so mong muon :"; cin>>hs;
	xuat_theo_hs(ql,n,hs);
	cout << "Bang luong xep theo thu tu tang dan"<<endl;
	tntangdan(ql,n);
	nhan_vien_luong_cao_nhat(ql,n); 
	// Doc du lieu
	fstream f;
	ofstream f("nv.txt", ios::in | ios::binary);
	if (!f)
	{ 
		cout<<"Khong the mo duoc tep"<<f<< endl;
		exit(1);	
	}
	ifstream f((char *)(nv), sizeof(nv));
	//in mang nv ra man hinh
	xuat_nv(nv,n);
	cout << endl;
	f.close();
	return 0;
} 

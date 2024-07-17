#include <iostream.h>
#include <iomanip.h>
#include <conio.h>
using namespace std;
struct sinhvien
{
    int 	ID;
    char 	hoten[30];
    int 	tuoi;
    float 	hk1, hk2;
    float 	dtb;
};
sinhvien lop[5];
void nhap(sinhvien *p)
{
    cout << "Nhap ID: "; cin >> p->ID;
    cin.ignore();
    cout << "Ho ten: ";cin.getline(p->hoten, 30);
    cout << "Tuoi: ";
    cin >> p->tuoi;
    cout << "Diem hoc ky 1: ";
    cin >> p->hk1;
    cout << "Diem hoc ky 2: ";
    cin >> p->hk2;
}
void nhapds(sinhvien *a)
{
    int sosv = sizeof(lop) / sizeof(sinhvien);
    for (int i = 1; i <= sosv; i++)
        nhap(&a[i]);
}
void tieude()
{
    cout<<setw(15)<<"ID "<<setw(15)<<"Ten ";
	cout<<setw(15)<<"Tuoi"<<setw(15)<<"Hoc ky 1";
	cout<<setw(15)<<"Hoc ky 2"<<setw(20)<<"Diem trung binh"<<endl;
}
void in(sinhvien x)
{
    cout<<setw(15)<< x.ID<< setw(15)<< x.hoten;
	cout<<setw(15)<< x.tuoi<<setw(15)<< x.hk1;
	cout<<setw(15)<< x.hk2 <<setw(20)<< x.dtb << endl;
}
void inds(sinhvien *a)
{
    int sosv = sizeof(lop) / sizeof(sinhvien);
    for (int i = 1; i <= sosv; i++)
        in(a[i]);
}
  
void Tinh_dtb(sinhvien a[])
{
    int sosv = sizeof(lop) / sizeof(sinhvien);
    
    for (int i = 1; i <= sosv; i++)
        a[i].dtb = (a[i].hk1 + 2 * a[i].hk2) / 3;
    cout<<setw(30)<<"Ho ten sv "<<setw(20)<<"Diem trung binh"<< endl;
	for (int i = 1; i <= sosv; i++)
        cout<<setw(30)<< a[i].hoten<<setw(20)<<a[i].dtb<< endl;
}
void Tongket(sinhvien a[])
{
    int sosv = sizeof(lop) / sizeof(sinhvien);
    float max = a[0].dtb;
    for (int i = 1; i <= sosv; i++)    
        if (max < a[i].dtb)
            max = a[i].dtb;

    int j = 0;
    tieude();
    for (int i = 1; i <= sosv; i++)
    {
        if (a[i].dtb == max)       
            in(a[i]);        
        j++;
    }
}
void Tienbo(sinhvien a[])
{
    int sosv = sizeof(lop) / sizeof(sinhvien);
    tieude();
	for (int i = 1; i <= sosv; i++)
        if (a[i].hk1 < a[i].hk2)
            in(a[i]);
}
int main()
{
    nhapds(lop);
    cout<<"Danh sach lop da nhap la"<<endl;
    tieude();
    inds(lop);
    cout << "Diem TB cuoi nam cua ca lop"<< "\n\n";   
    Tinh_dtb(lop);

    cout <<"Sinh vien co diem tong ket cao nhat\n\n";
    Tongket(lop);
    cout<< "Danh sach cac sinh vien tien bo \n\n";
    Tienbo(lop);
    return 0;
}
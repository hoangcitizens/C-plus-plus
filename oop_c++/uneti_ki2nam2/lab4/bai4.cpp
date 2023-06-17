#include <iostream>
#include<math.h>
#include<iomanip>
#include <string>
using namespace std;

class AnPham 
{
public:
    void import();
    void display();
    string getTen();
protected:
    string ten;
    int giaThanh;
};
void AnPham::import() 
{
    cout << "Nhap ten: "; getline(cin, ten);
    cout << "Nhap gia thanh: "; cin >> giaThanh;
    cin.ignore();
}
void AnPham::display() 
{
    cout << "\t"
         << left << setw(20) << ten
         << left << setw(15) << giaThanh;
}
string AnPham::getTen()
{
    return ten;
}

class Sach : public AnPham 
{
public:
    void import();
    void display();
    int getSoTrang();
private:
    int soTrang;
};
void Sach::import()
{
    AnPham::import();
    cout << "Nhap so trang: "; cin >> soTrang;
    cin.ignore();
}
void Sach::display() 
{
    AnPham::display();
    cout << left << setw(15) << soTrang << endl;
}
int Sach::getSoTrang() 
{
    return soTrang;
}

class DiaCD : public AnPham 
{
public:
    void import();
    void display();

private:
    int soPhut;
};
void DiaCD::import()
{
    AnPham::import();
    cout << "Nhap so phut: "; cin >> soPhut;
    cin.ignore();
}
void DiaCD::display() 
{
    AnPham::display();
    cout << left << setw(15) << soPhut << endl;
}

void title1()
{
    cout << "\t"
         << left << setw(20) << "Ten sach"
         << left << setw(15) << "Gia tien"
         << left << setw(15) << "So trang" << endl;
}
void title2()
{
    cout << "\t"
        << left << setw(20) << "Ten dia CD"
        << left << setw(15) << "Gia tien"
        << left << setw(15) << "So phut" << endl;
}

void inputSach(Sach a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "(*) Nhap thong tin sach thu " << i + 1 << endl;
        a[i].import();
        cout << endl;
    }
}
void sach500(Sach a[], int n)
{
    cout << "\t____DANH SACH THONG TIN AN PHAM SACH SO TRANG > 500___" << endl;
    title1();
    for (int i = 0; i < n; i++)
    {
        if (a[i].getSoTrang() > 500)
            a[i].display();
    }
    cout << endl;
}
void inputDia(DiaCD a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "(*) Nhap thong tin dia CD thu " << i + 1 << endl;
        a[i].import();
        cout << endl;
    }
}
void findDia(DiaCD a[], int n)
{
    string x;
    cout << "(+) Nhap ten dia CD can tim: "; getline(cin, x);
    cout << "\t____DANH SACH THONG TIN AN PHAM DIA CD " << x << "___" << endl;
    title2();
    for (int i = 0; i < n; i++)
    {
        if (a[i].getTen() == x)
            a[i].display();
    }
    cout << endl;
}

int main() {
    int n; cout << "Nhap so luong sach: "; cin >> n;
    cin.ignore();
    Sach* s = new Sach[n];
    inputSach(s, n);
    sach500(s, n);
    int m; cout << "Nhap so luong dia CD: "; cin >> m;
    cin.ignore();
    DiaCD* d = new DiaCD[m];
    inputDia(d, m);
    findDia(d, m);
    delete[] s;
    delete[] d;
    return 0;
}
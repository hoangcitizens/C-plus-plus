#include<iostream>
#include<iomanip>
#include<math.h>
#include<string>
using namespace std;

class MatHang
{
public:
    MatHang();
    MatHang(string, string,float);
    ~MatHang();
    friend istream& operator >> (istream&, MatHang&);
    string getMaHang();
protected:
    string maHang;
    string tenHang;
    float donGia;
};
MatHang::MatHang()
{
    maHang = "Unknown";
    tenHang = "Unknown";
    donGia = 0;
}
MatHang::MatHang(string maHang, string tenHang, float donGia)
{
    this->maHang = maHang;
    this->tenHang = tenHang;
    this->donGia = donGia;
}
MatHang::~MatHang() {}
istream& operator >> (istream& is, MatHang& mh)
{
    fflush(stdin);
    cout << "Nhap ma hang: "; getline(is, mh.maHang); 
    cout << "Nhap ten hang: "; getline(is, mh.tenHang); 
    cout << "Nhap don gia: "; is >> mh.donGia;
    return is;
}
string MatHang::getMaHang()
{
    return maHang;
}

class BanhKeo : public MatHang 
{
public:
    BanhKeo();
    BanhKeo(string, string, float, string);
    ~BanhKeo();
    float tinhChietKhau();
    friend istream& operator >> (istream&, BanhKeo&);
    friend ostream& operator << (ostream&, BanhKeo&);
private:
    string noiSanXuat;
};

BanhKeo::BanhKeo() : MatHang()
{
    noiSanXuat = "Unknown";
}
BanhKeo::BanhKeo(string maHang, string tenHang, float donGia, string noiSanXuat) 
    : MatHang(maHang, tenHang, donGia)
{
    this->noiSanXuat = noiSanXuat;
}
BanhKeo::~BanhKeo() {}
float BanhKeo::tinhChietKhau()
{
    return donGia * 0.01;
}
istream& operator>>(istream& is, BanhKeo& bk) 
{
    is >> (MatHang&)bk;
    fflush(stdin);
    cout << "Nhap noi san xuat: "; getline(is, bk.noiSanXuat);
    return is;
}
ostream& operator<<(ostream& os, BanhKeo& bk) 
{
    os << "\t"
       << left << setw(20) << bk.maHang
       << left << setw(20) << bk.tenHang
       << left << setw(15) << bk.donGia
       << left << setw(15) << bk.tinhChietKhau()
       << left << setw(20) << bk.noiSanXuat << endl;
    return os;
}

void title()
{
    cout << "\t"
         << left << setw(20) << "Ma hang"
         << left << setw(20) << "Ten hang"
         << left << setw(15) << "Don gia"
         << left << setw(15) << "Chiet khau"
         << left << setw(20) << "Noi san xuat" << endl;
}
void input(BanhKeo a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "(*) Nhap thong tin banh keo thu " << i + 1 << endl;
        cin >> a[i];
        cout << endl;
    }
}
void output(BanhKeo a[], int n)
{
    cout << "\t______________________DANH SACH THONG TIN MAT HANG BANH KEO_______________________" << endl;
    title();
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    }
}
void find(BanhKeo a[], int n)
{
    cout << "\t__________________________DANH SACH BANH KEO CO MA 'MO1'__________________________" << endl;
    title();
    for (int i = 0; i < n; i++)
    {
        if (a[i].getMaHang() != "MO1")
        {
            cout << a[i];
        }
    }
}
int main() 
{
    int n; cout << "Nhap so luong banh keo: "; cin >> n;
    BanhKeo* b = new BanhKeo[n];
    input(b, n);
    output(b, n);
    find(b, n);
    delete[] b;
    return 0;
}
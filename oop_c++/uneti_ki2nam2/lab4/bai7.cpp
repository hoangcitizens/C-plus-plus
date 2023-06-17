// NGUYEN HUU HOANG - 21103100320 - DHTI15A5HN

#include<iostream>
#include<math.h>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;

class HangHoa
{
public:
    HangHoa();
    HangHoa(string,string,float);
    ~HangHoa();
    void import();
    void display();
    string getCode();
    string getName();
    void setCode(string);
    void setName(string);
    void setPrice(float);
    void docFile(ifstream&);
protected:
    string code; // ma hang
    string name; // ten hang
    float price; // don gia
};
HangHoa::HangHoa()
{
    code = "Unknown";
    name = "Unknown";
    price = 0;
}
HangHoa::HangHoa(string code,string name,float price)
{
    this->code = code;
    this->name = name;
    this->price = price;
}
HangHoa::~HangHoa(){}
void HangHoa::import()
{
    cin.ignore();
    cout << "Nhap ma hang: "; getline(cin, code);
    cout << "Nhap ten hang: "; getline(cin, name); 
    cout << "Nhap don gia: "; cin >> price;
}
void HangHoa::display()
{
    cout << "\t"
         << "|" << left << setw(14) << code
         << "|" << left << setw(26) << name
         << "|" << left << setw(14) << price;
}
string HangHoa::getCode()
{
    return code;
}
string HangHoa::getName()
{
    return name;
}
void HangHoa::setCode(string code)
{
    this->code = code;
}
void HangHoa::setName(string name)
{
    this->name = name;
}
void HangHoa::setPrice(float price)
{
    this->price = price;
}
void HangHoa::docFile(ifstream& in)
{
    string code, name;
    float price;
    in.ignore();
    getline(in, code);
    getline(in, name);
    in >> price;
    this->setCode(code);
    this->setName(name);
    this->setPrice(price);
}

class MT : public HangHoa
{
public:
    MT();
    MT(string, string, float, float, int);
    ~MT();
    friend istream& operator >> (istream&, MT&);
    friend ostream& operator << (ostream&, MT&);
    float tinhThanhTien();
    float getSpeed();
    void setSpeed(float);
    void setS(int);
    void docFile(ifstream&);
protected:
    float speed; // toc do
    int s; // so luong
};
MT::MT() : HangHoa()
{
    speed = 0;
    s = 0;
}
MT::MT(string code, string name, float price, float speed, int s) : HangHoa(code,name,price)
{
    this->speed = speed;
    this->s = s;
}
MT::~MT() {}
istream& operator >> (istream& is, MT& mt)
{
    mt.HangHoa::import();
    cout << "Nhap toc do: "; is >> mt.speed;
    cout << "Nhap so luong: "; is >> mt.s;
    return is;
}
float MT::tinhThanhTien()
{
    return s * price;
}
ostream& operator << (ostream& os, MT& mt)
{
    mt.HangHoa::display();
    os << "|" << left << setw(14) << mt.speed
       << "|" << left << setw(14) << mt.s
       << "|" << left << setw(14) << mt.tinhThanhTien();
    return os;
}
float MT::getSpeed()
{
    return speed;
}
void MT::setSpeed(float speed)
{
    this->speed = speed;
}
void MT::setS(int s)
{
    this->s = s;
}
void MT::docFile(ifstream& in)
{
    float speed; int s;
    HangHoa::docFile(in);
    in >> speed;
    in >> s;
    this->setSpeed(speed);
    this->setS(s);
}

class MTXT : public MT
{
public:
    MTXT();
    MTXT(string, string, float, float, int, float);
    ~MTXT();
    friend istream& operator >> (istream&, MTXT&);
    friend ostream& operator << (ostream&, MTXT&);
    float tinhPhiBaoTri();
    void setKg(float);
    void docFile(ifstream&);
private:
    float kg; // trong luong
};
MTXT::MTXT() : MT()
{
    kg = 0;
}
MTXT::MTXT(string code, string name, float price, float speed, int s,float kg) : MT(code,name,price,speed,s)
{
    this->kg = kg;
}
MTXT::~MTXT(){}
istream& operator >> (istream& is, MTXT& mtxt)
{
    is >> (MT&)mtxt;
    cout << "Nhap trong luong may: "; is >> mtxt.kg;
    return is;
}
float MTXT::tinhPhiBaoTri()
{
    return price * 0.05;
}
ostream& operator << (ostream& os, MTXT& mtxt)
{
    os << (MT&)mtxt;
    os << "|" << left << setw(14) << mtxt.kg 
       << "|" << left << setw(13) << mtxt.tinhPhiBaoTri() << "|" << endl;
    return os;
}
void MTXT::setKg(float kg)
{
    this->kg = kg;
}
void MTXT::docFile(ifstream& in)
{
    MT::docFile(in);
    float kg;
    in >> kg;
    this->setKg(kg);
}

void title()
{
    cout << "\t"
        << "____________________________________________________________________________________________________________________________________" << endl << "\t"
        << left << setw(15) << "|    Ma hang"
        << left << setw(27) << "|         Ten hang"
        << left << setw(15) << "|    Don gia"
        << left << setw(15) << "|    Toc do"
        << left << setw(15) << "|   So luong"
        << left << setw(15) << "|  Thanh tien"
        << left << setw(15) << "|  Trong luong"
        << left << setw(15) << "| Phi bao tri |" << endl << "\t"
        << "*----------------------------------------------------------------------------------------------------------------------------------*" << endl;
}

void input(MTXT a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "(*) Nhap thong tin may tinh xach tay thu " << i + 1 << endl;
        cin >> a[i];
        cout << endl;
    }
}
void output(MTXT a[], int n)
{
    cout << "\t\t\t\t\t\t\tDANH SACH THONG TIN MAY TINH XACH TAY" << endl;
    title();
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
        cout << "\t*----------------------------------------------------------------------------------------------------------------------------------*" << endl;
    }
    cout << endl;
}
void findCode(MTXT a[], int n)
{
    int count = 0;
    cin.ignore();
    string x = "2SAM261"; cout << "\tNhap ma hang can tim: " << x << endl; //getline(cin, x);
    cout << "\t\t\t\t\t\t\tTHONG TIN MAY TINH XACH TAY CO MA HANG " << x << endl;
    title();
    for (int i = 0; i < n; i++)
    {
        if (a[i].getCode() == x)
        {
            count++;
            cout << a[i];
            cout << "\t*----------------------------------------------------------------------------------------------------------------------------------*" << endl;
        }
    }
    if (count == 0)
        cout << "\t\t\t\t(!) Khong co may tinh xach tay co ma hang " << x << " trong danh sach !!!" << endl;
    cout << endl;
}
void listedName(MTXT a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].getName() < a[j].getName())
                swap(a[i], a[j]);
        }
    }
    cout << "\t\t\t\t\t\tDANH SACH MAY TINH XACH TAY THEO TEN GIAM DAN" << endl;
    title();
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
        cout << "\t*----------------------------------------------------------------------------------------------------------------------------------*" << endl;
    }
    cout << endl;
}
void sumFee(MTXT a[], int n)
{
    float S = 0;
    for (int i = 0; i < n; i++)
    {
        S += a[i].tinhPhiBaoTri();
    }
    cout << "\t=> Tong phi bao tri cua may tinh " << S << endl << endl;
}
void findSpeedMin(MTXT a[], int n)
{
    MTXT min = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i].getSpeed() < min.getSpeed())
            min = a[i];
    }
    cout << "\t\t\t\t\t\tTHONG TIN MAY TINH TOC DO MIN" << endl;
    title();
    cout << min;
    cout << "\t*----------------------------------------------------------------------------------------------------------------------------------*" << endl;
    cout << endl;
}
void fix(MTXT a[], int n)
{
    // int k;  cout << "\tNhap vi tri may tinh can can sua: " << endl; cin >> k;
    int k = 3; cout << "\tNhap vi tri may tinh can can sua: " << k << endl; //cin >> k;
    while (k < 1 || k > n)
    {
        cout << "\t(!) Nhap lai 1 < k < " << n << ": "; cin >> k;
    }
    /* truong hop chuong trinh sua thu cong
    cin >> a[k - 1];
    */
    // truong hop chuong trinh sua tu dong   
    string code = "4ADDS", name = "DELL INSPIRON";
    float speed = 530, price = 24200, kg = 2;
    int s = 3;
    a[k - 1].setCode(code); a[k - 1].setName(name); a[k - 1].setPrice(price);
    a[k - 1].setSpeed(speed); a[k - 1].setS(s); a[k - 1].setKg(kg);
    cout << "\t\t\t\t\tDANH SACH MAY TINH XACH TAY SAU KHI SUA TAI VI TRI THU " << k << endl;
    title();
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
        cout << "\t*----------------------------------------------------------------------------------------------------------------------------------*" << endl;
    }
    cout << endl;
}
void deleteCode(MTXT a[], int &n)
{
    int count = 0;
    /* Truong hop xoa thu cong
    cin.ignore();
    string x; cout << "\tNhap ma hang muon xoa: "; getline(cin, x);*/
    // Truong hop xoa tu dong
    string x = "4DJF493"; cout << "\tNhap ma hang muon xoa: " << x << endl; 
    for (int i = 0; i < n; i++)
    {
        if (a[i].getCode() == x)
        {
            count++;
            for (int j = i; j < n; j++)
            {
                a[j] = a[j + 1];
            }
            n--;
        }
    }
    if (count == 0)
        cout << "\t\t\t\t(!) Khong co may tinh xach tay co ma hang " << x << " trong danh sach !!!" << endl;
    cout << "\t\t\t\t\t\tDANH SACH MAY TINH XACH SAU KHI XOA MA " << x << endl;
    title();
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
        cout << "\t*----------------------------------------------------------------------------------------------------------------------------------*" << endl;
    }
    cout << endl;
}
void insert(MTXT a[], int &n)
{
    int k = 3; cout << "\t(+) Nhap vi tri may tinh can them: " << k << endl; //cin >> k;
    n++;
    for (int i = n - 1; i > k - 1; i--)
    {
        a[i] = a[i - 1];
    }
    // truong hop chuong trinh them tu dong   
    string code = "124DDS", name = "LENOVO THINKPAD";
    float speed = 470, price = 19000, kg = 1.8;
    int s = 5;
    a[k - 1].setCode(code); a[k - 1].setName(name); a[k - 1].setPrice(price);
    a[k - 1].setSpeed(speed); a[k - 1].setS(s); a[k - 1].setKg(kg);
    // truong hop chuong trinh them thu cong
    /*cin.ignore();
    cout << "Nhap ma hang: "; getline(cin, code);  a[k-1].setCode(code);
    cout << "Nhap ten hang: "; getline(cin, name); a[k-1].setName(name);
    cout << "Nhap don gia: "; cin >> price;        a[k-1].setPrice(price);
    cout << "Nhap toc do: "; cin >> speed;         a[k-1].setSpeed(speed);
    cout << "Nhap so luong: "; cin >> s;           a[k-1].setS(s);
    cout << "Nhap trong luong may: "; cin >> kg;   a[k-1].setKg(kg);*/
    cout << "\t\t\t\t\t\t\tDANH SACH MAY TINH XACH TAY SAU KHI THEM" << endl;
    title();
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
        cout << "\t*----------------------------------------------------------------------------------------------------------------------------------*" << endl;
    }
    cout << endl;
}
void arrangeCode(MTXT a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].getCode() > a[j].getCode())
                swap(a[i], a[j]);
        }
    }
    cout << "\t\t\t\t\t\tDANH SACH MAY TINH XACH TAY THEO MA TANG DAN" << endl;
    title();
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
        cout << "\t*----------------------------------------------------------------------------------------------------------------------------------*" << endl;
    }
    cout << endl;
}

void Menu()
{
	cout << "(!) CHU Y ! Toan bo chuc nang tim kiem, sua, xoa, chen da duoc cai tu dong trong chuong trinh" << endl
         << "de dam bao khoi dong chuong trinh thuan tien !!!" << endl;
    ifstream ifs("bai7_lab4.txt", ios::in); 
    int n, options; cout << "Nhap so luong may tinh xach tay: "; ifs >> n; cout << n << endl;
    char ss[5]; ifs.getline(ss, 3);
    MTXT m[50];
    do
    {
        cout << "\t._______________________________MENU______________________________." << endl
             << "\t|1. Nhap va in danh sach thong tin may tinh xach tay              |" << endl
             << "\t|2. Tim thong tin may tinh xach tay theo ma nhap tu ban phim      |" << endl
             << "\t|3. Liet ke may tinh xach tay theo ten                            |" << endl
             << "\t|4. Tong phi bao tri cua cac may tinh                             |" << endl
             << "\t|5. Tim may tinh xach tay co toc do nho nhat                      |" << endl
             << "\t|6. Sua thong tin mot may tinh xach tay                           |" << endl
             << "\t|7. Xoa mot may tinh xach tay theo ma cho truoc                   |" << endl
             << "\t|8. Chen them mot may tinh xach tay tai vi tri k                  |" << endl
             << "\t|9. Sap xep danh sach theo chieu tang dan cua ma may              |" << endl
             << "\t|10. Thoat !                                                      |" << endl
             << "\t|_________________________________________________________________|" << endl;
        cout << "\t<+> Nhap lua chon cua ban: "; cin >> options;
        switch (options)
        {
        case 1:
        {
             for (int i = 0; i < n; i++)
             {
                m[i].docFile(ifs);
             }
             //input(m, n);
             output(m, n);         
             ifs.close();
             break;
        }
        case 2:
        {
            findCode(m, n);
            break;
        }
        case 3:
        {
            listedName(m, n);
            break;
        }
        case 4:
        {
            sumFee(m, n);
            break;
        }
        case 5:
        {
            findSpeedMin(m, n);
            break;
        }
        case 6:
        {
            fix(m, n);
            break;
        }
        case 7:
        {
            deleteCode(m, n);
            break;
        }
        case 8:
        {
            insert(m, n);
            break;
        }
        case 9:
        {
            arrangeCode(m, n);
            break;
        }
        case 10:
        {
            cout << "(!) Thoat ! Chuong trinh ket thuc !!!" << endl;
            break;
        }
        default:
            cout << "\t(!) Khong co lua chon nay ! Vui long lua chon lai !!!" << endl;
            cout << "\t<+> Nhap lua chon cua ban: "; cin >> options;
            if (options == 10)
                cout << "(!) Thoat ! Chuong trinh ket thuc !!!" << endl;
            break;
        }
    } while (options != 10);
}

int main()
{
    Menu();
    return 0;
}

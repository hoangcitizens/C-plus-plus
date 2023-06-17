#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <vector>
using namespace std;

class Basic
{
public:
    Basic(float,float,float,float);
    ~Basic();
    virtual void import();
    virtual float countPhone(); // tinh cuoc dien thoai
    virtual float countInternet(); // tinh cuoc internet
    float sumFeeBasic(); // tong cuoc phi
    void use(float,float); // thoi gian su dung
    virtual void display();
    virtual int options() = 0;
protected:
    float callTime; // thoi gian goi
    float callPrice; // don gia cuoc goi
    float traffic; // luu luong du lieu
    float internetPrice; // don gia internet
};

Basic::Basic(float callTime = 0, float callPrice = 0, float traffic = 0, float internetPrice = 0)
{
    this->callTime = callTime;
    this->callPrice = callPrice;
    this->traffic = traffic;
    this->internetPrice;
}
Basic::~Basic() {}
void Basic::import()
{
    cout << "Nhap thoi gian goi: "; cin >> callTime;
    cout << "Nhap don gia cuoc goi (1000/p): "; cin >> callPrice;
    cout << "Nhap luu luong du lieu: "; cin >> traffic;
    cout << "Nhap don gia Internet (200/mb): "; cin >> internetPrice;
}
float Basic::countPhone()
{
    return callTime * callPrice;
}
float Basic::countInternet()
{
    return traffic * internetPrice;
}
float Basic::sumFeeBasic()
{
    return countPhone() + countInternet() + 0.1 * (countPhone() + countInternet());
}
void Basic::use(float callTime,float traffic)
{
    this->callTime += callTime;
    this->traffic += traffic;
}
void Basic::display()
{
    cout << "|" << left << setw(14) << callTime
         << "|" << left << setw(14) << callPrice
         << "|" << left << setw(14) << traffic
         << "|" << left << setw(14) << internetPrice;
}

class DataFree : public Basic
{
public:
    DataFree(float,float,float,float,float,float);
    ~DataFree();
    void import() override;
    float countPhone() override;
    float countInternet() override; // tinh cuoc Internet
    float sumFeeDataFree(); // tinh tien phai dong
    void display() override;
    int options();
private:
    float feeSub; // cuoc thue bao
    float freeData; // nguong luu luong mien phi
};

DataFree::DataFree(float callTime = 0, float callPrice = 0, float traffic = 0, float internetPrice = 0, float feesub = 0, float freeData = 0)
    : Basic(callTime, callPrice, traffic, internetPrice)
{
    this->feeSub = feeSub;
    this->freeData = freeData;
}
DataFree::~DataFree() {}
void DataFree::import()
{
    Basic::import();
    cout << "Nhap cuoc thue bao: "; cin >> feeSub;
    cout << "Nhap nguong luu luong dung luong mien phi: "; cin >> freeData;
}
float DataFree::countPhone()
{
    return Basic::countPhone();
}
float DataFree::countInternet()
{
    if (traffic <= freeData)
        return feeSub;
    else if (traffic > freeData)
        return feeSub + Basic::countInternet();
}
float DataFree::sumFeeDataFree()
{
    return countPhone() + countInternet();
}
void DataFree::display()
{
    Basic::display();
    cout << "|" << left << setw(14) << feeSub
         << "|" << left << setw(14) << freeData
         << "|" << left << setw(14) << countPhone()
         << "|" << left << setw(14) << countInternet()
         << "|" << left << setw(13) << sumFeeDataFree() << "|" << endl;
}
int DataFree::options()
{
    return 1;
}

class DataFix : public Basic
{
public:
    DataFix(float,float,float,float);
    ~DataFix();
    float countPhone() override; // tinh cuoc dien thoai
    float countInternet() override; // tinh cuoc Internet
    float sumFeeDataFix();
    void display() override;
    int options();
};

DataFix::DataFix(float callTime = 0, float callPrice = 0, float traffic = 0, float internetPrice = 0)
    : Basic(callTime,callPrice,traffic,internetPrice) {}
DataFix::~DataFix() {}
float DataFix::countPhone()
{
    return Basic::countPhone() - 0.1 * Basic::countPhone();
}
float DataFix::countInternet()
{
    return 1000000;
}
float DataFix::sumFeeDataFix()
{
    return countPhone() + countInternet();
}
void DataFix::display()
{
    Basic::display();
    cout << "|" << left << setw(14) << ""
         << "|" << left << setw(14) << ""
         << "|" << left << setw(14) << countPhone()
         << "|" << left << setw(14) << countInternet()
         << "|" << left << setw(13) << sumFeeDataFix() << "|" << endl;
}
int DataFix::options()
{
    return 2;
}

void title()
{
    cout << "\t" << "__________________________________________________________________________________________________"
        << "______________________________________________________________________________________________________" << endl << "\t"
        << left << setw(25) << "|        Ho va ten"
        << left << setw(25) << "|         Dia chi   "
        << left << setw(15) << "|  So can cuoc"
        << left << setw(15) << "|Thoi gian goi"
        << left << setw(15) << "|  Don gia goi"
        << left << setw(15) << "|   Luu luong"
        << left << setw(15) << "| Don gia mang"
        << left << setw(15) << "|Cuoc thue bao"
        << left << setw(15) << "| Nguong data"
        << left << setw(15) << "|     Phi goi"
        << left << setw(15) << "| Phi Internet"
        << left << setw(15) << "|   Tong phi  |" << endl << "\t"
        << "*-------------------------------------------------------------------------------------------------------"
        << "-----------------------------------------------------------------------------------------------*" << endl;
}

class Customer
{
public:
    Customer(string, string, long);
    ~Customer();
    void init();
    void countMonth(); // ham tinh cuoc cuoi thang
    void times(); // tinh thoi gian su dung
    Basic* basic[20]; // goi cuoc
    int n;
private:
    string fullname; // ho va ten
    string address; // dia chi
    long id; // so can cuoc
};

Customer::Customer(string fullname = "Unknown", string address = "Unknown", long id = 0)
{
    this->fullname = fullname;
    this->address = address;
    this->id = id;
}
Customer::~Customer() {}
void Customer::init()
{
    int options;
    cout << "Nhap so luong khach hang: "; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "(*) Nhap thong tin khach hang thu " << i + 1 << endl;
        do
        {
            cout << "\t_______Goi DATA__________" << endl
                << "\t|1. Goi Data Free        |" << endl
                << "\t|2. Goi Data Fix         |" << endl
                << "\t|________________________|" << endl;
            cout << "\t(+) Nhap goi cuoc: "; cin >> options;
            if (options != 1 && options != 2)
                cout << "\t(!) Vui long nhap lai lua chon cua ban !!!" << endl;
        } while (options != 1 && options != 2);
        if (options == 1)
            basic[i] = new DataFree();
        else if (options == 2)
            basic[i] = new DataFix();
        cin.ignore();
        cout << "Nhap ho va ten khach hang: "; getline(cin, fullname);
        cout << "Nhap dia chi khach hang: "; getline(cin, address);
        cout << "Nhap so can cuoc khach hang: "; cin >> id;
        basic[i]->import();
        cout << endl;
    }
    cout << "\t\t\t\t\t\t\t\t\t\t\tDANH SACH THONG TIN KHACH HANG" << endl;
    title();
    for (int i = 0; i < n; i++)
    {
        cout << "\t"
             << "|" << left << setw(24) << fullname
             << "|" << left << setw(24) << address
             << "|" << left << setw(14) << id;
        basic[i]->display();
        cout << "\t*------------------------------------------------------------------------------------------------------"
             << "------------------------------------------------------------------------------------------------*" << endl;
    }
    cout << endl;
}

int main() 
{
    Customer c;
    c.init();
    return 0;
}
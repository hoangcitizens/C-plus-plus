#include <iostream>
#include<math.h>
#include<iomanip>
#include <string>
using namespace std;

class Person
{
public:
    Person();
    Person(string, string, double);
    ~Person();
    string getAddress();
protected:
    string name;
    string address;
    double phone;
};
Person::Person()
{
    name = "Unknown";
    address = "Unknown";
    phone = 0;
}
Person::Person(string name, string address, double phone) 
{
    this->name = name;
    this->address = address;
    this->phone = phone;
}
Person::~Person(){}
string Person::getAddress()
{
    return address;
}

class Officer : public Person
{
public:
    Officer();
    Officer(string , string, double, double);
    ~Officer();
    double getSalary();
protected:
    double salary;
};
Officer::Officer() : Person()
{
    salary = 0;
}
Officer::Officer(string name, string address, double phone, double salary) : Person (name, address, phone) 
{
    this->salary = salary;
}
Officer::~Officer(){}
double Officer::getSalary()
{
    return salary;
}

class Manager : public Officer 
{
public:
    Manager();
    Manager(string name, string address, double phone, double salary, double extra);
    void display();
private:
    double extra;
};
Manager::Manager() : Officer()
{
    extra = 0;
}
Manager::Manager(string name, string address, double phone, double salary, double extra) : Officer(name, address, phone, salary)
{
    this->extra = extra;
}
void Manager::display() 
{
    cout << "\t"
         << left << setw(20) << name
         << left << setw(20) << address
         << left << setw(20) << phone
         << left << setw(20) << salary
         << left << setw(20) << extra << endl;
}

void title()
{
    cout << "\t"
        << left << setw(20) << "Ho va ten"
        << left << setw(20) << "Dia chi"
        << left << setw(20) << "So dt"
        << left << setw(20) << "Luong"
        << left << setw(20) << "Phu cap" << endl;
}
void input(Manager a[], int n)
{
    string name, address;
    double salary, extra, phone;
    for (int i = 0; i < n; i++)
    {
        cout << "(*) Nhap thong tin manager thu " << i + 1 << endl;
        cin.ignore();
        cout << "Nhap ten: "; getline(cin, name);
        cout << "Nhap dia chi: "; getline(cin, address);
        cout << "Nhap so dien thoai: "; cin >> phone;
        cout << "Nhap luong: "; cin >> salary;
        cout << "Nhap phu cap: "; cin >> extra;
        a[i] = Manager(name, address, phone, salary, extra);
        cout << endl;
    }
}
void output(Manager a[], int n)
{
    cout << "\t_____________________________DANH SACH THONG TIN MANAGER_______________________________" << endl;
    title();
    for (int i = 0; i < n; i++)
    {
        a[i].display();
    }
    cout << endl;
}
void find(Manager a[], int n)
{
    cout << "\t_________DANH SACH THONG TIN MANAGER KHONG O HA NOI VA LUONG KHAC 10 TRIEU_____________" << endl;
    title();
    for (int i = 0; i < n; i++)
    {
        if (a[i].getAddress() != "Ha Noi" && a[i].getSalary() != 10000000)
            a[i].display();
    }
}

int main() 
{
    int n; cout << "Nhap so luong manager: "; cin >> n;
    Manager* d = new Manager[n];
    input(d, n);
    output(d, n);
    find(d, n);
    delete[] d;
    return 0;
}
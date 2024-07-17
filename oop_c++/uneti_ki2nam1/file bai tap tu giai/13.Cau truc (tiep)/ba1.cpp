#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std; 
typedef struct    
{
	int tu; 
	int mau;
} phan_so;
int main()
{
	phan_so a, b, c;
	cout << "Nhap phan so a " << endl;
  	cout << "Tu so: ";
	cin >> a.tu; 
  	cout << "Mau so: "; 
	cin >> a.mau; 
	cout << "\nNhap phan so b " << endl;
  	cout << "Tu so: "; 
	cin >> b.tu; 
  	cout << "Mau so: "; 
	cin >> b.mau;
  	cout << "Phan so thu nhat la: " << a.tu << "/" << a.mau << endl;
  	cout << "Phan so thu hai la: " << b.tu << "/" << b.mau << endl;
	c.tu = a.tu*b.mau + a.mau*b.tu;
	c.mau = a.mau*b.mau;
	cout <<"Tong hai phan so la: " << c.tu << "/" << c.mau << endl;
	c.tu = a.tu*b.mau - a.mau*b.tu;
	c.mau = a.mau*b.mau;
	cout << "Hieu hai phan so la: "<<c.tu<<"/"<<c.mau<<endl;
	c.tu = a.tu*b.tu;
	c.mau = a.mau*b.mau;
	cout << "Tich hai phan so la: "<<c.tu<<"/"<<c.mau<<endl;
	c.tu = a.tu*b.mau;
	c.mau = a.mau*b.tu;
	cout << "Thuong hai phan so la: " << c.tu << "/" << c.mau << endl;
	return 0;
}

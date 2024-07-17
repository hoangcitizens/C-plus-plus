#include<iostream>
#include<math.h>
#define PI 3.14
using namespace std;

int main(){
   int luaChon;
   cout << "1. Tinh dien tich tam giac. "
        << "\n2. Tinh dien tich hinh chu nhat."
        << "\n3. Tinh dien tich hinh vuong."
        << "\n4. Tinh dien tich hinh thang."
        << "\n5. Tinh dien tich hinh tron."
        << "\n6. Tinh dien tich hinh hinh binh hanh.";
   do{
   		cout << "\nNhap lua chon cua ban : ";
        cin >> luaChon;
	    switch(luaChon){
	   		case 1:{
	   			float a, b, c;
				cout << "Nhap canh a = ";
				cin >> a;
				cout << "Nhap canh b = ";
				cin >> b;
				cout << "Nhap canh c = ";
				cin >> c;
				if (abs(b-c) < a && a < b+c){   
				   	float p = (a+b+c)/2;
				   	float S = sqrt(p*(p-a)*(p-b)*(p-c));
				   	cout << "\nDien tich tam giac S = "<<S<<endl;
				}
				else
				   	cout << "\nBa canh khong tao thanh tam giac !";
				break;
			}
			case 2:{
				float a, b;
				cout << "Nhap canh a = ";
				cin >> a;
				cout << "Nhap canh b = ";
				cin >> b;
				cout << "Dien tich hinh chu nhat la S = "<<a*b<<endl;
				break;
			}
			case 3:{
	   			float x;
	   			cout << "\nNhap canh hinh vuong x = ";
	   			cin >> x;
	   			cout << "Dien tich hinh vuong la S = "<<x*x<<endl;
				break;
			}
			case 4:{
				float a, b, h;
				cout << "Nhap day hinh thang a = ";
				cin >> a;
				cout << "Nhap day hinh thang b = ";
				cin >> b;
				cout << "Nhap chieu cao hinh thang h = ";
				cin >> h;
				cout << "Dien tich hinh thang la S = "<<((a+b)*h)/2<<endl;
				break;
			}
			case 5:{
				float r;
				cout << "Nhap ban kinh hinh tron R = ";
				cin >> r;
				cout << "Dien tich hinh tron la S = "<<PI*r*r<<endl;
				break;
			}
			case 6:{
				float a, h;
				cout << "Nhap day cua hinh binh hanh a = ";
				cin >> a;
				cout << "Nhap chieu cao hinh binh hanh h = ";
				cin >> h;
				cout << "Dien tich hinh binh hanh la S = "<<a*h<<endl;
				break;
			}
			default:{
				cout << "Vui long lua chon lai !!!";
				break;
			}
	    }
	} while(luaChon!=0);
   return 0;
}


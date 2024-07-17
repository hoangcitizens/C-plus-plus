#include<iostream>
using namespace std;

int main(){
   float a, b, c;
   cout << "Nhap a = ";
   cin >> a;
   cout << "Nhap b = ";
   cin >> b;
   cout << "Nhap c = ";
   cin >> c;
   cout << "1. Tinh tong a+b+c"
        << "\n2. Tinh tich a*b*c"
        << "\n3. Giai phuong trinh ax+b=c";
   int luaChon;
   while (luaChon!=0){
   		cout << "\nLua chon cua ban la : ";
   		cin >> luaChon;
	    switch (luaChon){
	   		case 1:{
	   			cout <<"Tong "<<a<<"+"<<b<<"+"<<c<<" = "<<a+b+c<<endl;
				break;
			}
			case 2:{
				cout <<"Tich "<<a<<"*"<<b<<"*"<<c<<" = "<<a*b*c<<endl;
				break;
			}
			case 3:{
				cout << "=> Phuong trinh co dang "<<a<<"x+"<<b<<"="<<c;
				if (a==0){
					if(b==c)
						cout << "\nVay phuong trinh vo so nghiem !"<<endl;
					else
					    cout << "\nVay phuong trinh vo nghiem !"<<endl;
				}
				else
				    cout << "\nVay phuong trinh co nghiem x = "<<(c-b)/a<<endl;
				break;
			}
			default:
				cout << "Xin loi khong co lua chon nay !"<<endl;
	    }
   }
   return 0;
}


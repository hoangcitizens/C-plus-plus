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
   cout << " => Bat phuong trinh co dang "<<a<<"x + "<<b<<" > "<<c;
   if (a==0){
   	    if (b>c)
   	        cout << "\nBat phuong trinh luon dung voi moi b>c !";
   	    else
   	        cout << "\nVo ly ! Bat phuong trinh vo nghiem !";
   	}
   	else{
   		float x = (c-b)/a;
   		if (a>0)
   			cout << "\nBat phuong trinh co nghiem x > "<<x;
		else 
		    cout << "\nBat phuong trinh co nghiem x < "<<x;
	}
   return 0;
}


#include<iostream>
#include<math.h>
using namespace std;

int main(){
   float doanhSo, hoaHong;
   cout << "Nhap doanh so B ban duoc la : ";
   cin >> doanhSo;
   if (doanhSo < pow(100,4) || doanhSo == pow(100,4)){
   	    hoaHong = doanhSo * 0.05;
   	    cout << "Tien hoa hong B nhan duoc la: "<<hoaHong;
    }
   else 
        if (doanhSo > pow(100,4) && doanhSo < pow(300,4) || doanhSo == pow(300,4)){
   	    	hoaHong = doanhSo * 0.1;
   	    	cout << "Tien hoa hong B nhan duoc la: "<<hoaHong;
   		}
   	else 
	    if (doanhSo > pow(300,4)){
   	   		hoaHong = doanhSo * 0.2;
   	    	cout << "Tien hoa hong B nhan duoc la: "<<hoaHong;
   		}
   return 0;
}


#include<iostream>
using namespace std;
#define PI 3.14

int main(){
    // R la ban kinh hinh tron , C la chu vi hinh tron , S la dien tich hinh tron
    float R, C, S;
    cout << "Nhap ban kinh R = ";
    cin >> R;
    C = 2*R*PI;
    S = R*R*PI;
    if ( R>0 ){
	    cout << "Chu vi hinh tron C = "<<C;
        cout << "\nDien tich hinh tron S = "<<S;
    }
    else
    	cout << "Nhap ban kinh la so duong !";
   return 0;
}


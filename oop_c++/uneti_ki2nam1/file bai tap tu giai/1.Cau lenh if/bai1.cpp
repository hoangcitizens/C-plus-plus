#include<iostream>
#include<math.h>
using namespace std;

int main(){
   /* a, b, c la cac canh cua tam giac
	   p : nua chu vi cua tam giac ; S : dien tich cua tam giac */	
   float a, b, c;
   cout << "Nhap canh a = ";
   cin >> a;
   cout << "Nhap canh b = ";
   cin >> b;
   cout << "Nhap canh c = ";
   cin >> c;
   if (a>0 && b>0 && c>0){
   	    if (abs(b-c) < a && a < b+c){   
   	        float p = (a+b+c)/2;
   	        float S = sqrt(p*(p-a)*(p-b)*(p-c));
   	        cout << "Dien tich tam giac S = "<<S<<endl;
   	    }
   	    else
   	        cout << "Ba canh khong tao thanh tam giac !";
   }
   else
        cout << "\aVui long nhap ba canh cua tam giac la so duong !!!";
   return 0;
}


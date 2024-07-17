#include<iostream>
#include<math.h>
using namespace std;

int main(){
	/* a, b, c la cac canh cua tam giac
	   p : nua chu vi cua tam giac ; P : chu vi cua tam giac ; S : dien tich cua tam giac */	
   float a, b, c;
   cout << "Nhap canh a = ";
   cin >> a;
   cout << "Nhap canh b = ";
   cin >> b;
   cout << "Nhap canh c = ";
   cin >> c;
   if (a>0 && b>0 && c>0){
   	    if (abs(b-c) < a && a < b+c){
   	    	float P = a+b+c;
   	    	cout << "Chu vi cua tam giac P = "<<P;
   	        float p = (a+b+c)/2;
   	        float S = sqrt(p*(p-a)*(p-b)*(p-c));
   	        cout << "\nDien tich tam giac S = "<<S;	
		}
		else 
		    cout << "Ba canh khong tao thanh tam giac !!!";
		if (a == b && b == c && c == a)
    	    cout << "\nBa canh tao thanh tam giac deu !!!";
    	else if (a == b || b == c || c == a)
    	    cout << "\nBa canh tao thanh tam giac can !!!";
    	else if ( a*a == b*b + c*c || b*b == a*a + c*c || c*c == b*b + a*a )
    	    cout << "\nBa canh tao thanh tam giac vuong !!!";
    	else
    	    cout << "\nBa canh tao thanh tam giac thuong !!!";
   }
   else 
        cout << "Vui long nhap ba canh la so duong !!!";
   return 0;
}


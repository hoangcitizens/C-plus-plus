#include<iostream>
#include<math.h>
using namespace std;

int main(){
   float a, b, c;
   cout << "Nhap a = ";
   cin >> a;
   cout << "Nhap b = ";
   cin >> b;
   cout << "Nhap c = ";
   cin >> c;
   
   if (a==0){
    	if (b==0){
    		if (c==0)
    		    cout << "Phuong trinh vo so nghiem !"<<endl;
    		else 
    		    cout << "Phuong trinh vo nghiem !"<<endl;
		}
		else
			cout << "Phuong trinh co nghiem x = "<<-c/b<<endl;
   }
   else{
   		float delta = b*b-4*a*c;
   		if (delta < 0)
   		    cout << "Phuong trinh vo nghiem !"<<endl;
   		else 
		    if (delta == 0)
   				cout << "Phuong trinh co nghiem kep x = "<<-b/(2*a)<<endl;
			else{
				float x1, x2;
		    	x1 = (-b+sqrt(delta)) / (2*a);
				x2 = (-b-sqrt(delta)) / (2*a);
				cout << "Phuong trinh co 2 nghiem la x1 = "<<x1<<" va x2 = "<<x2<<endl;
			}	
   }
   return 0;
}


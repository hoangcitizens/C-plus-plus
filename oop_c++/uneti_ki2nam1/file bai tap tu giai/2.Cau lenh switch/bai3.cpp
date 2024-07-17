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
    cout << "\t __________________MENU___________________"
    	 << "\n\t|1. Giai bpt ax + b > c                   |"
    	 << "\n\t|2. Giai phuong trinh ax2+bx+c            |"
    	 << "\n\t|3. Kiem tra co tao thanh tam giac khong? |"
    	 << "\n\t|_________________________________________|";
    int luaChon;
    do{
    	cout << "\n*)Nhap vao lua chon cua ban: ";
    	cin >> luaChon;
    	switch (luaChon){
    		case 0:{
    			cout << "\tThoat. Ket thuc chuong trinh !";
				break;
			}
    		case 1:{
    			cout << "\t=> Bat phuong trinh co dang "<<a<<"x + "<<b<<" > "<<c;
    			if (a==0){
    				if(b>c)
    					cout << "\n\tVay bat phuong trinh vo so nghiem."<<endl;
    				else
    					cout << "\n\tVay bat phuong trinh vo nghiem."<<endl;
				}
				else{				
					if (a>0)
						cout << "\n\tVay bat phuong trinh co nghiem x > "<<(c-b)/a<<endl;
					else
						cout << "\n\tVay bat phuong trinh co nghiem x < "<<(c-b)/a<<endl;
				}
				cout << "______________________________________________________________";
				break;
			}
			case 2:{
				if (a==0){
					cout << "\t=> Phuong trinh co dang "<<b<<"x + "<<c<<" = 0"<<endl;
					if (b==0){
						if (c==0)
							cout << "\tVay phuong trinh vo so nghiem !"<<endl;
						else
							cout << "\tVay phuong trinh vo nghiem !"<<endl;
					}
					else
						cout << "\tVay phuong trinh co nghiem x = "<<-c/b<<endl;
			    }
				else{
					cout << "\t=> Phuong trinh co dang "<<a<<"x2 + "<<b<<"x + "<<c<<" = 0"<<endl;
					float delta, x1, x2;
					delta = b*b-4*a*c;
					if (delta < 0)
						cout << "\tVay phuong trinh vo nghiem !"<<endl;
					else 
						if (delta == 0)
							cout << "\tVay phuong trinh co nghiem kep x1 = x2 = "<<-b/(2*a)<<endl;
					else{
						x1 = (-b+sqrt(delta))/(2*a);
						x2 = (-b-sqrt(delta))/(2*a);
						cout << "\tVay phuong trinh co 2 nghiem phan biet x1 = "<<x1<<" va x2 = "<<x2<<endl;
					}	
				}
				cout << "______________________________________________________________";
				break;
			}
			case 3:{
				if (a>0 && b>0 && c>0){
					if (abs(b-c) < a && a < b+c){
						cout << "\tBa so a="<<a<<" ; b="<<b<<" ; c="<<c<<" tao thanh mot tam giac !!!"<<endl;
						if (a == b && b == c && c == a)
				    	    cout << "\tBa canh tao thanh tam giac deu !!!"<<endl;
				    	else 
							if (a == b || b == c || c == a)
				    	   		cout << "\tBa canh tao thanh tam giac can !!!"<<endl;
				    	else
				    	    cout << "\tBa canh tao thanh tam giac thuong !!!"<<endl;
					}
					else			
		    			cout << "\tBa so a="<<a<<" ; b="<<b<<" ; c="<<c<<" khong tao thanh tam giac !!!"<<endl;
				}
				else
					cout << "\tVui long nhap canh cua tam giac la so duong !"<<endl;
				cout << "______________________________________________________________";
				break;
			}
			default:{
				cout << "\tKhong co lua chon nay ! Vui long lua chon lai !!!"<<endl;
				cout << "______________________________________________________________";
				break;
			}
		}
	} while(luaChon != 0);
	return 0;
}


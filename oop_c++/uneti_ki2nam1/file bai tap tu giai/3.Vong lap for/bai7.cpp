#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	float t;
	cout << "Nhap vao so tien muon doi : ";
	cin >> t;
	int S=0;
	if (t>0){
		cout<<setw(15)<<"So to 1000"<<setw(15)<<"So to 2000";
		cout<<setw(15)<<"So to 5000"<<setw(15)<<"So to 10000"<<endl;
		for (int a=0; a<=t/1000 ; a++){
			for (int b=0; b<=t/2000 ;b++){
				for (int c=0; c<=t/5000 ;c++){
					for (int d=0; d<=t/10000 ;d++){
						if(a*1000+b*2000+c*5000+d*10000 == t){
							cout<<"\t"<<left<<setw(15)<<a<<left<<setw(15)<<b;
							cout<<"\t"<<left<<setw(15)<<c<<left<<setw(15)<<d<<endl;
							S++;
						}
					}
				}
			}
		}
		cout << "=> Co tat ca "<<S<<" cach doi"<<endl;
	}
	else
		cout << "Vui long nhap vao so tien la so nguyen duong !!!"<<endl;
	return 0;
}


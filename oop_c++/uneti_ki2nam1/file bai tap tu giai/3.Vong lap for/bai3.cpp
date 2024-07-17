#include<iostream>
using namespace std;

int main(){
	cout << "Cac so co 4 chu so abcd voi a+b=c+d la : "<<endl;
	int S=0;
	for (int a=1; a<=9 ; a++){
		for (int b=0; b<=9 ; b++){
			for (int c=0; c<=9 ; c++){
				for (int d=0; d<=9 ; d++){
					if (a+b == c+d){
						cout <<"  "<<a*1000+b*100+c*10+d;
						S++;
					}
				}
			}
		}
	}
	cout << "\nCo "<<S<<" so thoa man dieu kien !"<<endl;
	return 0;
}


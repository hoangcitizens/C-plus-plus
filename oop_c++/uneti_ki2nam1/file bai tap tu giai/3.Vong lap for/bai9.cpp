#include<iostream>
using namespace std;

int main(){
	cout << "   BANG CUU CHUONG   ";
	for (int i=2; i<=9 ;i++){
		cout << "\nBang cuu chuong cua "<<i<<" la : "<<endl;
		for (int j=1; j<=10 ;j++)
			cout << " "<<i<<" x "<<j<<" = "<<i*j<<endl;
	}
	return 0;
}


#include<iostream>
using namespace std;

int main(){
	unsigned int n;
	cout << "Nhap vao so nguyen duong n = ";
	cin >> n;
	long int i=1, P=0;
	while (i<=n){
		P+=2*i;
		i++;
	}
	cout << "Tich P = "<<P<<endl;
	return 0;
}


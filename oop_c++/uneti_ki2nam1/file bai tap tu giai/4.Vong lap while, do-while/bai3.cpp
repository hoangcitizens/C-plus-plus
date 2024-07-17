#include<iostream>
using namespace std;

int main(){
	int n;
	cout << "Nhap vao so nguyen n = ";
	cin >> n;
	int i=1;
	int dk=0;
	while(i<=n){
		if(n%i==0)
			dk++;
		i++;
	}
		if (dk==2)
			cout << n <<" la so nguyen to !";
		else 
			cout << n <<" khong phai la so nguyen to !";
	return 0;
}


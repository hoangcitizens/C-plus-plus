#include<iostream>
using namespace std;

int main(){
	int m, n;
	cout << "Nhap so chan : ";
	cin >> n;
	cout << "Nhap so con : ";
	cin >> m;
    for (int i=1; i<=n/2 ;i++){
	    for (int j=1; j<=n/4 ;j++){
	        if ((i+j==m) && (i*2+j*4==n)){
	            cout<<"So con ga = "<<i;
	            cout<<"\nSo con cho = "<<j;
	        }  
	    }
	}
	return 0;
}


#include<iostream>
using namespace std;

int main(){
	int n;
	cout << "Nhap vao n = ";
	cin >> n;
	if (n>0){
		int S=0;
		for (int i=1; i<=n ; i++){
			S += 2*i-1;
		}
		cout << "Tong S = "<<S<<endl;
	}
	else
		cout << "Vui long nhap vao n la so duong !!!"<<endl;
	return 0;
}


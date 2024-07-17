#include<iostream>
using namespace std;

int main(){
	int n;
	cout << "Nhap vao n = ";
	cin >> n;
	if (n>0){
		float S=0;
		for (int i=1; i<=n ; i++)
			S += (float)1/i;
		cout << "Vay tong S = "<<S<<endl;
	}
	else
		cout << "Vui long nhap vao n la so nguyen duong !!!"<<endl;
	return 0;
}


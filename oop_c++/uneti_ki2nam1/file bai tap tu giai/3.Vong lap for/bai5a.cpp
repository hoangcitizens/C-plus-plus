#include<iostream>
#include<math.h>
using namespace std;

int main(){
	int n;
	cout << "Nhap vao n = ";
	cin >> n;
	if (n>0){
		int S=0;
		for (int i=1; i<=n ; i++){
			S += pow(i,2);
		}
		cout << "Tong S = "<<S<<endl;
	}
	else
		cout << "Vui long nhap vao n la so nguyen duong !"<<endl;
	return 0;
}


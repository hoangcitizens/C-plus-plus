#include<iostream>
using namespace std;

int main(){
	int n;
	cout << "Nhap vao so nguyen n = ";
	cin >> n;
	int i=1;
	float S=0;
	while (i<=n){
		S+=(float)1/i;
		i++;
	}
	cout << "Tong S = "<<S<<endl;
	return 0;
}


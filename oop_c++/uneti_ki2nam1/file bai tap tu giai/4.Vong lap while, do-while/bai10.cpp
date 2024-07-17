#include<iostream>
using namespace std;

int main(){
	int n, i=1;
	float t, ls, tongTien;
	cout << "Nhap so tien gui: ";
	cin >> t;
	cout << "Nhap so thang gui: ";
	cin >> n;
	cout << "Nhap lai suat: ";
	cin >> ls;
	while(i <= n){
		tongTien = t+t*ls;
		t = tongTien;
		i++;
	}
	cout << "Tong tien = "<<tongTien<<endl;
	return 0;
}

